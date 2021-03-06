/* assembly.c
 *
 * Generate target codes for TM57 from quads
 *
 * by Huizhe Li, Master Student, Dartmouth College
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"assembly.h"
#include"quad.h"

#define REG_PC 7
#define REG_SP 6
#define REG_FP 5
#define REG_MEM 4	// since amount of mem wil be unknown until runtime, save mem size here
#define REG_0 0
#define REG_1 1
#define REG_2 2
#define REG_3 3

#define FREG_7 7
#define FREG_6 6
#define FREG_5 5
#define FREG_4 4
#define FREG_0 0
#define FREG_1 1
#define FREG_2 2
#define FREG_3 3

// for now REG 0 and REG 1 will be treated as the most "temporary" registers - do not make assumptions about them

const int ignored = 0;	// placed whenever an instruction ignores an operand, merely as a reminder
const int patch	  = 0;	// placed whenever an operand needs to be patched, also a reminder
extern quad g_array[];	// the quad array
extern int next_quad;	// total number of quads
extern int no_globals;	// total number of globals
extern FILE* out;
extern char* filename;
extern int asm_debug;
int cur_quad = 0;	// next quad to be processed
int next_instr = 0;

asm_instr instructions[MAXINSTR];

patch_table the_patch_table;

// patching tool
int quad_asm[MAXQUADSIZE];	// indexed by quad number
				// store the line number of the first instruction produced by this quad

char* asm_opcode_str[] = {
  "HALT",
  "IN",
  "OUT",
  "ADD",
  "SUB",
  "MUL",
  "DIV",
  "LD",
  "LDA",
  "LDC",
  "ST",
  "JLT",
  "JLE",
  "JGE",
  "JGT",
  "JEQ",
  "JNE",

  "MOD",
  "ADDF",
  "SUBF",
  "MULF",
  "DIVF",
  "CVTIF",
  "CVTFI",
  "LDF",
  "STF",
  "JFLT",
  "JFLE",
  "JFGE",
  "JFGT",
  "JFEQ",
  "JFNE",
  "INF",
  "OUTF",
  "INB",
  "OUTB",
  "LDFC",
  "LDB",
  "STB",

  ".INT",
  ".STRING",
  ".FILL",
  ".FLOAT"
};

void gen_assembly()
{
  int no_quads;	// number of quads in total
  int val;
  int asm_ln, index;

  int i, j;	// loop var
  int quad_index;
  quad this_quad;	// current quad being processed
  
  no_quads = next_quad - 1;

  // initialization before generating assembly for quads

  // init patch table
  the_patch_table.size = 0;
  
   // init sp to DADDR_SIZE
  create_int_instr(OPCODE_TYPE_RM, ASM_LD, REG_SP, 0, 0);	// sp = dMem[0]
  create_int_instr(OPCODE_TYPE_RM, ASM_LDA, REG_SP, 1, REG_SP);	// sp = sp + 1

  // remember mem size
  create_int_instr(OPCODE_TYPE_RM, ASM_LDA, REG_MEM, 0, REG_SP);

  // local temps are implemented as global vars (shame on me)
  // compute address of the bottom of the stack, and assign it to sp
  create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_0, 0, ignored);			// reg[0] = 0
  create_int_instr(OPCODE_TYPE_RM, ASM_LDA, REG_0, MAXTEMP+no_globals, REG_0);	// reg = number of vars
  create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_1, 8, ignored);			// all types take 8 bytes (again shame on me)
  create_int_instr(OPCODE_TYPE_RO, ASM_MUL, REG_0, REG_0, REG_1);		// reg[0] = offset
  create_int_instr(OPCODE_TYPE_RO, ASM_SUB, REG_SP, REG_SP, REG_0);		// sp -= offset, now points to the 
                                                                                // first free address
  for (i = 0; i < no_quads; i++){	// generate codes for each quads
    this_quad = g_array[i];
    gen_asm_from_quad(this_quad);
    cur_quad++;
  }

  // back patch all function entrances
  for (i = 0; i < the_patch_table.size; i++){
    quad_index = the_patch_table.entries[i].quad_ln;

    // prepare arguments
    index =   the_patch_table.entries[i].index;
    asm_ln =  the_patch_table.entries[i].asm_ln;
    val = quad_asm[quad_index];

    patch_instruction(asm_ln, index, val);
  } 
}



/* Generate assembly code for a given quad  */
void gen_asm_from_quad(quad this_quad)
{
  char* str;
  char*	cur_char;
  int addr;
  asm_opcode opcode;
  int label1, label2, label3, label4;

  // save this for patching later on
  quad_asm[this_quad->index] = next_instr;
  
  switch(this_quad->op){
    
  case START:	// call main, which receives no parameters
    if (asm_debug) printf("--- trace --- START\n");
    create_int_instr(OPCODE_TYPE_RM, ASM_LDA, REG_FP, 0, REG_SP);	      	// fp = sp

    // push one more time for main's return address
    // just to make the maths work
    create_int_instr(OPCODE_TYPE_RM, ASM_LDA, REG_SP, -8, REG_SP);	      	// sp -= 8

    // register patching info
    reg_entry(next_instr, 1, this_quad->op1->value.int_value);

    create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_PC, patch, ignored);		// call main, need patching

    break;
    
    /* ----------------------------- ASSIGNMENT -------------------------------- */

  case ASSN:	// direct access (as opposed to dereference)
    if (asm_debug) printf("--- trace --- ASSN\n");

    // check operand type, and store value to be assigned into reg[3]
    switch(this_quad->op2->op_type){
    case OP_TYPE_INT:	// instant number
      create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_3, this_quad->op2->value.int_value, ignored);// reg[3] = value
      break;
    case OP_TYPE_ID:	// variable
      absolute_addr(this_quad->op2->value.int_value);			// store address of var into reg[2]
      create_int_instr(OPCODE_TYPE_RM, ASM_LD, REG_3, 0, REG_2);// reg[3] = value
      break;
    case OP_TYPE_PT:	// pointer
      absolute_addr_deref(this_quad->op2->value.int_value);			// store address of var into reg[2]
      create_int_instr(OPCODE_TYPE_RM, ASM_LD, REG_3, 0, REG_2);// reg[3] = value
      break;
    default:
      printf("--- internal error --- this should not happen\n");

    }

    // store address into reg[2]
    switch(this_quad->op1->op_type){
    case OP_TYPE_ID:
      absolute_addr(this_quad->op1->value.int_value);
      break;
    case OP_TYPE_PT:
      absolute_addr_deref(this_quad->op1->value.int_value);
      break;
    default:
      printf("--- internal error --- this should not happen\n");
    }

    // move! 
    create_int_instr(OPCODE_TYPE_RM, ASM_ST, REG_3, 0, REG_2);	// store reg[3] into address reg[2] + 0
    
    break;

  case ASSNF:	// direct access (as opposed to dereference)
    if (asm_debug) printf("--- trace --- ASSNF\n");

    // check operand type, and store value to be assigned into reg[3]
    switch(this_quad->op2->op_type){
    case OP_TYPE_DOUBLE:	// instant number
      create_double_instr(OPCODE_TYPE_RM, ASM_LDFC, FREG_3, this_quad->op2->value.double_value, ignored);// reg[3] = value
      break;
    case OP_TYPE_ID:	// variable
      absolute_addr(this_quad->op2->value.int_value);			// store address of var into reg[2]
      create_int_instr(OPCODE_TYPE_RM, ASM_LDF, FREG_3, 0, REG_2);// reg[3] = value
      break;
    case OP_TYPE_PT:	// pointer
      absolute_addr_deref(this_quad->op2->value.int_value);			// store address of var into reg[2]
      create_int_instr(OPCODE_TYPE_RM, ASM_LDF, FREG_3, 0, REG_2);// reg[3] = value
      break;
    default:
      printf("--- internal error --- this should not happen\n");
    }

    // store address into reg[2]
    switch(this_quad->op1->op_type){
    case OP_TYPE_ID:
      absolute_addr(this_quad->op1->value.int_value);
      break;
    case OP_TYPE_PT:
      absolute_addr_deref(this_quad->op1->value.int_value);
      break;
    default:
      printf("--- internal error --- this should not happen\n");
    }

    // move! 
    create_int_instr(OPCODE_TYPE_RM, ASM_STF, FREG_3, 0, REG_2);	// store reg[3] into address reg[2] + 0

    break;

    /* ------------------------------ I/O ---------------------------------- */

  case PRINTB:	// print characters one by one
    if (asm_debug) printf("--- trace --- PRINTB\n");
    str = this_quad->op1->value.string_value;
    for(cur_char = str; *(cur_char)!='\0'; cur_char++){
      create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_0, *(cur_char), ignored);	// load a character into reg[0]
      create_int_instr(OPCODE_TYPE_RO, ASM_OUTB, REG_0, ignored, ignored);	// print this character
    }
    break;

 case PRINTF:	// need to check quad operand type - double literal or address
    if (asm_debug) printf("--- trace --- PRINTF\n");
    switch(this_quad->op1->op_type){
    case OP_TYPE_DOUBLE:	// float literal, print it straight out
      // load the literal into reg[0]
      create_double_instr(OPCODE_TYPE_RM, ASM_LDFC, FREG_0, this_quad->op1->value.double_value, ignored);
      create_int_instr(OPCODE_TYPE_RO, ASM_OUTF, FREG_0, ignored, ignored);	// print this double
      break;
    case OP_TYPE_ID:	// double variable
      absolute_addr(this_quad->op1->value.int_value);	// get the real address of the variable in REG[2]
      create_int_instr(OPCODE_TYPE_RM, ASM_LDF, FREG_0, 0, REG_2);	// load int value into reg[0]
      create_int_instr(OPCODE_TYPE_RO, ASM_OUTF, FREG_0, ignored, ignored);	// print this double
      break;
    case OP_TYPE_PT:	// pointer to a double variable
      absolute_addr_deref(this_quad->op1->value.int_value);	// get the real address of the variable in REG[2]
      create_int_instr(OPCODE_TYPE_RM, ASM_LDF, FREG_0, 0, REG_2);	// load int value into reg[0]
      create_int_instr(OPCODE_TYPE_RO, ASM_OUTF, FREG_0, ignored, ignored);	// print this double
      break;
    default:
      printf("--- internal error --- this should not happen\n");
    }
    break;
 case PRINTI:	// need to check quad operand type - double literal or address
    if (asm_debug) printf("--- trace --- PRINTI\n");
    switch(this_quad->op1->op_type){
    case OP_TYPE_INT:	// int literal, print it straight out
      // load the literal into reg[0]
      create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_0, this_quad->op1->value.int_value, ignored);
      create_int_instr(OPCODE_TYPE_RO, ASM_OUT, REG_0, ignored, ignored);	// print this double
      break;
    case OP_TYPE_ID:	// int variable
      absolute_addr(this_quad->op1->value.int_value);	// get the real address of the variable in REG[2]
      create_int_instr(OPCODE_TYPE_RM, ASM_LD, REG_0, 0, REG_2);	// load int value into reg[0]
      create_int_instr(OPCODE_TYPE_RO, ASM_OUT, REG_0, ignored, ignored);	// print this double
      break;
    case OP_TYPE_PT:	// pointer to an int variable
      absolute_addr_deref(this_quad->op1->value.int_value);	// get the real address of the variable in REG[2]
      create_int_instr(OPCODE_TYPE_RM, ASM_LD, REG_0, 0, REG_2);	// load int value into reg[0]
      create_int_instr(OPCODE_TYPE_RO, ASM_OUT, REG_0, ignored, ignored);	// print this double
      break;
    default:
      printf("--- internal error --- this should not happen\n");
    }
    break;


    /* ----------------------------- SP and FP book-keeping ---------------------------- */
  case GROW:	// grow stack
    if (asm_debug) printf("--- trace --- GROW\n");
    // reg[1] is 0 throughout this procedure
    create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_1, 0, ignored);	// reg[1] = 0;

    // check op1, NULL or not?
    if (this_quad->op1 == NULL){	// single var, grow 8 bytes
      create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_0, 8, ignored);	// reg[0] = 8
      create_int_instr(OPCODE_TYPE_RO, ASM_SUB, REG_SP, REG_SP, REG_0);	// sp = sp - 8
    }else{				// array, grow n times, n being the array size
      // save n into reg[3], 0 into reg[2], the latter being the loop var
      // check op1, addr or literal?	
      create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_2, 0, ignored);		// reg[2] = 0
      if (this_quad->op1->op_type == OP_TYPE_INT){		// literal
	create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_3, this_quad->op1->value.int_value, ignored);	
      }else{					// var
	create_int_instr(OPCODE_TYPE_RM, ASM_LD, REG_3, this_quad->op1->value.int_value, REG_2);	// reg[3] = n
      }

      // generate loop instructions

      // compare reg[2] (loop var) with reg[3] (times of loop)
      label1 = next_instr;
      create_int_instr(OPCODE_TYPE_RO, ASM_SUB, REG_0, REG_3, REG_2);	// reg[0] = reg[3] - reg[2]
      
      // jump out 
      label2 = next_instr;
      create_int_instr(OPCODE_TYPE_RM, ASM_JEQ, REG_0, patch, REG_1);	

      // loop body
      create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_0, 8, ignored);	// reg[0] = 8
      create_int_instr(OPCODE_TYPE_RO, ASM_SUB, REG_SP, REG_SP, REG_0);	// sp = sp - 8
      create_int_instr(OPCODE_TYPE_RM, ASM_LDA, REG_2, 1, REG_2);	// reg[2]++;

      // jump back
      create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_PC, label1, ignored);	// go back to the top

      // patch time
      label3 = next_instr;
      instructions[label2]->operands[1]->value.int_value = label3;	// tell the previous instr where to jump
    }
      
    break;
      

    /***************************** binary op **********************************/

  case ADD:	
    gen_biop(this_quad, ASM_ADD);	 break;

  case ADDF:
    gen_fbiop(this_quad, ASM_ADDF);	break;

  case MUL:
    gen_biop(this_quad, ASM_MUL);	break;

  case MULF:
    gen_fbiop(this_quad, ASM_MULF);	break;

  case SUB:
    gen_biop(this_quad, ASM_SUB);	break;

  case SUBF:
    gen_fbiop(this_quad, ASM_SUBF);	break;

  case DIV:
    gen_biop(this_quad, ASM_DIV);	break;

  case DIVF:
    gen_fbiop(this_quad, ASM_DIVF);	break;

  case MOD:
    gen_biop(this_quad, ASM_MOD);	break;

    /***************************** condition jump ******************************/

  case JLT:
    gen_jmp(this_quad, ASM_JLT);	break;

  case JLE:	
    gen_jmp(this_quad, ASM_JLE);	break;

  case JGT:	
    gen_jmp(this_quad, ASM_JGT);	break;

  case JGE:	
    gen_jmp(this_quad, ASM_JGE);	break;

  case JEQ:	
    gen_jmp(this_quad, ASM_JEQ);	break;

  case JNE:
    gen_jmp(this_quad, ASM_JNE);	break;

  case JFLT:
    gen_fjmp(this_quad, ASM_JFLT);	break;

  case JFLE:	
    gen_fjmp(this_quad, ASM_JFLE);	break;

  case JFGT:	
    gen_fjmp(this_quad, ASM_JFGT);	break;

  case JFGE:	
    gen_fjmp(this_quad, ASM_JFGE);	break;

  case JFEQ:	
    gen_fjmp(this_quad, ASM_JFEQ);	break;

  case JFNE:
    gen_fjmp(this_quad, ASM_JFNE);	break;

  case GOTO:    
    if (asm_debug) printf("--- trace --- GOTO\n");

    create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_1, 0, ignored);	// reg[1] = 0

    // register patch entry
    reg_entry(next_instr, 1, this_quad->op1->value.int_value);

    // goto
    create_int_instr(OPCODE_TYPE_RM, ASM_LDA, 7, patch, REG_1);	
    
    break;

    /******************************* convertion *********************************/

  case FTOI:	// get int from op2, convert, then save into the address in op1
    // check op2 type
    if (this_quad->op2->op_type == OP_TYPE_DOUBLE){	// literal
      create_int_instr(OPCODE_TYPE_RM, ASM_LDFC, FREG_0, this_quad->op2->value.double_value, ignored); // freg[0] = double value
      create_int_instr(OPCODE_TYPE_RO, ASM_CVTFI, REG_3, FREG_0, ignored);	// reg[3] = int value
    }else{	// var
      absolute_addr( this_quad->op2->value.int_value );		       	// reg[2] = address
      create_int_instr(OPCODE_TYPE_RM, ASM_LDF, FREG_0, 0, REG_2);     	// freg[0] = double value
      create_int_instr(OPCODE_TYPE_RO, ASM_CVTFI, REG_3, FREG_0, ignored);	// reg[3] = int value
    }

    // store 
    absolute_addr( this_quad->op1->value.int_value );		       	// reg[2] = address
    create_int_instr(OPCODE_TYPE_RM, ASM_ST, REG_3, 0, REG_2); 		  
      
    break;

 case ITOF:	// similar
    // check op2 type
    if (this_quad->op2->op_type == OP_TYPE_INT){	// literal
      create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_0, this_quad->op2->value.int_value, ignored);
      create_int_instr(OPCODE_TYPE_RO, ASM_CVTIF, FREG_3, REG_0, ignored);
    }else{	// var
      absolute_addr( this_quad->op2->value.int_value );		       
      create_int_instr(OPCODE_TYPE_RM, ASM_LD, REG_0, 0, REG_2);   
      create_int_instr(OPCODE_TYPE_RO, ASM_CVTIF, FREG_3, REG_0, ignored);
    }

    absolute_addr( this_quad->op1->value.int_value );		       
    create_int_instr(OPCODE_TYPE_RM, ASM_STF, FREG_3, 0, REG_2); 		  
      
    break;
    
  default:
    break;
  }
}


/* Compute the absolute address of an address given by a quad, store it in REG_2 */
void absolute_addr(int addr)
{
  // if addr < MEM_REG then it's a local var, need to add FP
  // else it's global, no computation needed
  
  int label1, label2, label3, label4;

  //printf("mark 1\n");
  // compare addr with MEM_REG

  create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_2, addr, ignored);	// reg[2] = addr;

  create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_1, 1000, ignored);	// load 10000 to reg[1], mark: overflow problem

  create_int_instr(OPCODE_TYPE_RO, ASM_SUB, REG_0, REG_2, REG_1);	// reg[0] = addr - global_base_addr
  label3 = next_instr;
  create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_1, patch, ignored);		// load zero to reg[1]
  create_int_instr(OPCODE_TYPE_RM, ASM_JLT, REG_0, 0, REG_1);	// if reg[0] < 0 then local
  
  // instructions if global
 
  // first adjust addr (that has TEMP_BASE_ADDR as starting address, defined in quad.h)
  create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_0, TEMP_BASE_ADDR, ignored);	// reg[0] = TEMP_BASE_ADDR;
  create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_1, addr, ignored);		// REG[1] = addr 
  create_int_instr(OPCODE_TYPE_RO, ASM_SUB, REG_2, REG_1, REG_0);	// REG[2] = offset
  create_int_instr(OPCODE_TYPE_RO, ASM_ADD, REG_2, REG_2, REG_MEM);	// REG[2] = right address

  create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_1, 0, ignored);		// load zero to reg[1]
  label4 = next_instr;
  create_int_instr(OPCODE_TYPE_RM, ASM_LDA, REG_PC, patch, REG_1);	// goto end

  // instructions if local

  label1 = next_instr;
  create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_2, addr, ignored);	// reg[2] = addr;
  create_int_instr(OPCODE_TYPE_RO, ASM_ADD, REG_2, REG_2, REG_FP);	// reg[2] = addr + fp , done!
  label2 = next_instr;

  // patch
  instructions[label3]->operands[1]->value.int_value = label1;
  instructions[label4]->operands[1]->value.int_value = label2;
}

/* similar to the above, but the reference addr is the value that is in the argument
 * instead of the argument it self
 */
void absolute_addr_deref(int addr)
{
  // first figure out the real address being refered to, and we could do the same as absolute_addr
  int label1, label2, label3, label4;
  absolute_addr(addr);	// reg[2] = absolute addr for the argument

  create_int_instr(OPCODE_TYPE_RM, ASM_LD, REG_2, 0, REG_2 );    // now ready to do the same stuff
  create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_1, 0, ignored);		// load zero to reg[1]
  create_int_instr(OPCODE_TYPE_RM, ASM_ST, REG_2, 0, REG_1);
  create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_1, 1000, ignored);	// load 1000 to reg[1], mark: overflow problem

  create_int_instr(OPCODE_TYPE_RO, ASM_SUB, REG_0, REG_2, REG_1);	// reg[0] = addr - global_base_addr
  label3 = next_instr;
  create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_1, patch, ignored);		// load zero to reg[1]
  create_int_instr(OPCODE_TYPE_RM, ASM_JLT, REG_0, 0, REG_1);	// if reg[0] < 0 then local
  
  // instructions if global
 
  // first adjust addr (that has TEMP_BASE_ADDR as starting address, defined in quad.h)
  create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_0, TEMP_BASE_ADDR, ignored);	// reg[0] = TEMP_BASE_ADDR;
  create_int_instr(OPCODE_TYPE_RM, ASM_LDA, REG_1, 0, FREG_0);		// REG[1] = addr 
  create_int_instr(OPCODE_TYPE_RO, ASM_SUB, REG_2, REG_1, REG_0);	// REG[2] = offset
  create_int_instr(OPCODE_TYPE_RO, ASM_ADD, REG_2, REG_2, REG_MEM);	// REG[2] = right address

  create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_1, 0, ignored);		// load zero to reg[1]
  label4 = next_instr;
  create_int_instr(OPCODE_TYPE_RM, ASM_LDA, REG_PC, patch, REG_1);	// goto end

  // instructions if local

  label1 = next_instr;
  create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_0, 0, ignored);		// load zero to reg[0]
  create_int_instr(OPCODE_TYPE_RM, ASM_LD,  REG_1, 0, 0);	// reg[1] = addr;
  create_int_instr(OPCODE_TYPE_RO, ASM_ADD, REG_2, REG_1, REG_FP);	// reg[2] = addr + fp , done!
  label2 = next_instr;

  // patch
  instructions[label3]->operands[1]->value.int_value = label1;
  instructions[label4]->operands[1]->value.int_value = label2;
}


/* Register a patch entry */
void reg_entry(int asm_ln, int index, int quad_line)
{
  
    the_patch_table.entries[the_patch_table.size].asm_ln = next_instr;	// line number of the next instruction
    the_patch_table.entries[the_patch_table.size].index = 1;		// the second!
    the_patch_table.entries[the_patch_table.size].quad_ln = quad_line;	// quad index
    (the_patch_table.size)++;		// register this entry
}

/* Create an instrction with 3 integer operands */
asm_instr create_int_instr(int opcode_type, asm_opcode opcode, int val1, int val2, int val3)
{
  asm_operand op1, op2, op3;
  
  op1 = create_asm_operand(ASM_OPERAND_TYPE_INT);
  op1->value.int_value = val1;
  op2 = create_asm_operand(ASM_OPERAND_TYPE_INT);
  op2->value.int_value = val2;
  op3 = create_asm_operand(ASM_OPERAND_TYPE_INT);
  op3->value.int_value = val3;
  return create_asm_instr(opcode_type, opcode, op1, op2, op3);
}


asm_instr create_double_instr(int opcode_type, asm_opcode opcode, int val1, double val2, int val3)
{
  asm_operand op1, op2, op3;
  
  op1 = create_asm_operand(ASM_OPERAND_TYPE_INT);
  op1->value.int_value = val1;
  op2 = create_asm_operand(ASM_OPERAND_TYPE_DOUBLE);
  op2->value.double_value = val2;
  op3 = create_asm_operand(ASM_OPERAND_TYPE_INT);
  op3->value.int_value = val3;
  return create_asm_instr(opcode_type, opcode, op1, op2, op3);
}
  
asm_instr create_double_3_instr(int opcode_type, asm_opcode opcode, double val1, double val2, double val3)
{
  asm_operand op1, op2, op3;
  
  op1 = create_asm_operand(ASM_OPERAND_TYPE_DOUBLE);
  op1->value.double_value = val1;
  op2 = create_asm_operand(ASM_OPERAND_TYPE_DOUBLE);
  op2->value.double_value = val2;
  op3 = create_asm_operand(ASM_OPERAND_TYPE_DOUBLE);
  op3->value.double_value = val3;
  return create_asm_instr(opcode_type, opcode, op1, op2, op3);
}

/* Create an instr struct */
asm_instr create_asm_instr(int opcode_type, asm_opcode opcode, asm_operand op1, asm_operand op2, asm_operand op3)
{
  asm_instr instr = (asm_instr)malloc(sizeof(struct asm_instr));
  
  instr->asm_ln = next_instr;
  instr->opcode = opcode;
  instr->operands[0] = op1;
  instr->operands[1] = op2;
  instr->operands[2] = op3;

  instr->opcode_type = opcode_type;
  instr->qd_ln = cur_quad;
  instructions[next_instr] = instr;
  
  next_instr++;
  return instr;
}

/* Create an operand struct, need to specify value */
asm_operand create_asm_operand(asm_operand_type type)
{
  asm_operand op = (asm_operand)malloc(sizeof(struct asm_operand));
  op->type = type;
  return op;
}

/* Print all instructions */
void print_instructions()
{
  int i; 
  asm_instr instruction;
  int prev_qd = -1;
  int cur_qd;
  int print_qd = 0;


  if (out == NULL){
    printf("failed opening file. abort printing target code\n");
    return;
  }

  
  for (i = 0; i < next_instr; i++){
    instruction = instructions[i];

    // determine whether to print quad
    print_qd = 0;
    cur_qd = instruction->qd_ln;
    if (cur_qd > prev_qd)
      print_qd = 1;
    prev_qd = cur_qd;
    
    // line number
    fprintf(out, "%d:\t", instruction->asm_ln);

    // opcode
    fprintf(out, "%s\t", asm_opcode_str[instruction->opcode]);

    print_operand(instruction->operands[0]);
    fprintf(out, ",");

    print_operand(instruction->operands[1]);    
    if(instruction->opcode_type == OPCODE_TYPE_RM)
      fprintf(out, "(");
    else
      fprintf(out, ",");

    print_operand(instruction->operands[2]);    
    if(instruction->opcode_type == OPCODE_TYPE_RM)
      fprintf(out, ")");

    // if new quad print it

    
    if (print_qd){
      fprintf(out, "  \tquad");
      print_quad(g_array[cur_qd]);
    }
    else
      fprintf(out,"\n");
  }
}

/* Print an operand */
static void print_operand(asm_operand op)
{
  switch(op->type){
  case ASM_OPERAND_TYPE_INT:
    fprintf(out,"%d", op->value.int_value);
    break;
  case ASM_OPERAND_TYPE_DOUBLE:
    fprintf(out,"%f", op->value.double_value);
    break;
  case ASM_OPERAND_TYPE_STRING:
    fprintf(out,"%s", op->value.string);
    break;
  default:
    printf("--- internal error --- should not happen");
  }
}

/* Patch an instruction */
void patch_instruction(int asm_ln, int index, int val)
{
  instructions[asm_ln]->operands[index]->value.int_value = val;
}

/* Wrapper for ADD ~ MOD*/
void gen_biop(quad this_quad, int opcode)
{
  if (asm_debug) printf("--- trace --- gen_biop\n");
    // check operand 1, literal or var?
    switch(this_quad->op2->op_type){
    case OP_TYPE_INT:
      create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_3, this_quad->op2->value.int_value, ignored);
      break;
    case OP_TYPE_ID:
      absolute_addr( this_quad->op2->value.int_value );
      create_int_instr(OPCODE_TYPE_RM, ASM_LD, REG_3, 0, REG_2);
      break;
    case OP_TYPE_PT:
      absolute_addr_deref( this_quad->op2->value.int_value );
      create_int_instr(OPCODE_TYPE_RM, ASM_LD, REG_3, 0, REG_2);
      break;
    default:
      printf("--- internal error --- this should not happen\n");
    }

    // check operand 2, literal or var?
    switch(this_quad->op3->op_type){
    case OP_TYPE_INT:
      create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_2, this_quad->op3->value.int_value, ignored);
      break;
    case OP_TYPE_ID:
      absolute_addr( this_quad->op3->value.int_value );
      create_int_instr(OPCODE_TYPE_RM, ASM_LD, REG_2, 0, REG_2);
      break;
    case OP_TYPE_PT:
      absolute_addr_deref( this_quad->op3->value.int_value );
      create_int_instr(OPCODE_TYPE_RM, ASM_LD, REG_2, 0, REG_2);
      break;
    default:
      printf("--- internal error --- this should not happen\n");
    }

    // reg[3] = reg[3] + reg[2]
    create_int_instr(OPCODE_TYPE_RO, opcode, REG_3, REG_3, REG_2);

    // store
    // destination is always treated as addr
    absolute_addr( this_quad->op1->value.int_value);	// reg[2] = right address
    create_int_instr(OPCODE_TYPE_RM, ASM_ST, REG_3, 0, REG_2);
}

/* Wrapper for ADDF ~ DIVF */
void gen_fbiop(quad this_quad, int opcode)
{

  if (asm_debug) printf("--- trace --- gen_fbiop\n");
  if (this_quad->op2->op_type == OP_TYPE_DOUBLE){
    create_double_instr(OPCODE_TYPE_RM, ASM_LDFC, FREG_3, this_quad->op2->value.double_value, ignored);
  }else{	// load the value from mem
    absolute_addr( this_quad->op2->value.int_value );
    create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_0, 0, ignored);
    create_int_instr(OPCODE_TYPE_RM, ASM_LDF, FREG_3, REG_0, REG_2);
  }

  if (this_quad->op3->op_type == OP_TYPE_DOUBLE){
    // printf("value: %f\n", this_quad->op3->value.double_value);
    create_double_instr(OPCODE_TYPE_RM, ASM_LDFC, FREG_2, this_quad->op3->value.double_value, ignored);
  }else{	// load the value from mem
    absolute_addr( this_quad->op3->value.int_value );
    create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_0, 0, ignored); // reg[0] = 0
    create_int_instr(OPCODE_TYPE_RM, ASM_LDF, FREG_2, REG_0, REG_2);
  }

  create_double_3_instr(OPCODE_TYPE_RO, opcode, FREG_3, FREG_3, FREG_2);

  absolute_addr( this_quad->op1->value.int_value);	// reg[2] = right address
  create_int_instr(OPCODE_TYPE_RM, ASM_STF, FREG_3, 0, REG_2);

}

/* Wrapper for integer jumps */
void gen_jmp(quad this_quad, int opcode)
{
  if (asm_debug) printf("--- trace --- gen_jmp\n");
   // check operand 1, literal or var?
    switch(this_quad->op1->op_type){
    case OP_TYPE_INT:
      create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_3, this_quad->op1->value.int_value, ignored);
      break;
    case OP_TYPE_ID:
      absolute_addr( this_quad->op1->value.int_value );
      create_int_instr(OPCODE_TYPE_RM, ASM_LD, REG_3, 0, REG_2);
      break;
    case OP_TYPE_PT:
      absolute_addr_deref( this_quad->op1->value.int_value );
      create_int_instr(OPCODE_TYPE_RM, ASM_LD, REG_3, 0, REG_2);
      break;
    default:
      printf("--- internal error --- this should not happen\n");
    }
    
    create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_1, 0, ignored);	// reg[1] = 0
  
    // register patch entry
    reg_entry(next_instr, 1, this_quad->op2->value.int_value);
  
    create_int_instr(OPCODE_TYPE_RM, opcode, REG_3, patch, REG_1);	
}

/* Wrapper for float jumps */
void gen_fjmp(quad this_quad, int opcode)
{
  if (asm_debug) printf("--- trace --- gen_fjmp\n");
   // check operand 1, literal or var?
    switch(this_quad->op1->op_type){
    case OP_TYPE_DOUBLE:
      create_double_instr(OPCODE_TYPE_RM, ASM_LDFC, FREG_3, this_quad->op1->value.double_value, ignored);
      break;
    case OP_TYPE_ID:
      absolute_addr( this_quad->op1->value.int_value );
      create_int_instr(OPCODE_TYPE_RM, ASM_LDF, FREG_3, 0, REG_2);
      break;
    case OP_TYPE_PT:
      absolute_addr_deref( this_quad->op1->value.int_value );
      create_int_instr(OPCODE_TYPE_RM, ASM_LDF, FREG_3, 0, REG_2);
      break;
    default:
      printf("--- internal error --- this should not happen\n");
    }
    
    create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_1, 0, ignored);	// reg[1] = 0
  
    // register patch entry
    reg_entry(next_instr, 1, this_quad->op2->value.int_value);
  
    create_int_instr(OPCODE_TYPE_RM, opcode, FREG_3, patch, REG_1);	
}
