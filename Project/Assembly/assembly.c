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
#define MEM_REG 4	// since amount of mem wil be unknown until runtime, so keep that info in register 4
#define REG_0 0
#define REG_1 1
#define REG_2 2
#define REG_3 3

// for now REG 0 and REG 1 will be treated as the most "temporary" registers - do not make assumptions about them

const int ignored = 0;	// placed whenever an instruction ignores an operand, merely as a reminder
const int patch	  = 0;	// placed whenever an operand needs to be patched, also a reminder
extern quad g_array[];	// the quad array
extern int next_quad;	// total number of quads
extern int no_globals;	// total number of globals
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
  
  // remember memory size
  create_int_instr(OPCODE_TYPE_RM, ASM_LDA, MEM_REG, 0, REG_SP);

  // local temps are implemented as global vars (shame on me)
  // compute address of the bottom of the stack, and assign it to sp
  create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_0, 0, ignored);			// reg[0] = 0
  create_int_instr(OPCODE_TYPE_RM, ASM_LDA, REG_0, MAXTEMP+no_globals, REG_0);	// reg = number of vars
  create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_1, 8, ignored);			// all types take 8 bytes (again shame on me)
  create_int_instr(OPCODE_TYPE_RO, ASM_MUL, REG_0, REG_0, REG_1);		// reg[0] = offset
  create_int_instr(OPCODE_TYPE_RO, ASM_SUB, REG_SP, REG_SP, REG_0);		// sp -= offset, i.e. the stack bottom

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
gen_asm_from_quad(quad this_quad)
{
  int table_size = the_patch_table.size;
  char* str;
  char*	cur_char;

  // save this for patching later on
  quad_asm[this_quad->index] = next_instr;
  
  switch(this_quad->op){
    
  case START:	// call main, which receives no parameters
    create_int_instr(OPCODE_TYPE_RM, ASM_LDA, REG_FP, 0, REG_SP);	      	// fp = sp

    // register patching info
    the_patch_table.entries[table_size].asm_ln = next_instr;	// line number of the next instruction
    the_patch_table.entries[table_size].index = 1;		// the second!
    the_patch_table.entries[table_size].quad_ln = this_quad->op1->value.int_value;	// quad index
    (the_patch_table.size)++;		// register this entry

    create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_PC, patch, ignored);		// call main, need patching
    break;
    
  case PRINTB:	// print string one by one
    str = this_quad->op1->value.string_value;
    for(cur_char = str; *(cur_char)!='\0'; cur_char++){
      create_int_instr(OPCODE_TYPE_RM, ASM_LDC, REG_0, *(cur_char), ignored);	// load a character into reg[0]
      create_int_instr(OPCODE_TYPE_RO, ASM_OUTB, REG_0, ignored, ignored);	// print this character
    }
    break;
    

  default:
    break;
  }


  
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
  for (i = 0; i < next_instr; i++){
    instruction = instructions[i];
    // line number
    printf("%d:\t", instruction->asm_ln);

    // opcode
    printf("%s\t", asm_opcode_str[instruction->opcode]);

    print_operand(instruction->operands[0]);
    printf(",");

    print_operand(instruction->operands[1]);    
    if(instruction->opcode_type == OPCODE_TYPE_RM)
      printf("(");
    else
      printf(",");

    print_operand(instruction->operands[2]);    
    if(instruction->opcode_type == OPCODE_TYPE_RM)
      printf(")\n");
    else
      printf("\n");
  }

}

/* Print an operand */
static void print_operand(asm_operand op)
{
  switch(op->type){
  case ASM_OPERAND_TYPE_INT:
    printf("%d", op->value.int_value);
    break;
  case ASM_OPERAND_TYPE_DOUBLE:
    printf("%f", op->value.double_value);
    break;
  case ASM_OPERAND_TYPE_STRING:
    printf("%s", op->value.string);
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
