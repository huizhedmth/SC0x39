/* quad.c
 *
 * Implementation of quad-related functions
 * 
 * The major function has the name "gen_code", which takes as input
 * the syntax tree and symboltables, and store generated quads in 
 * the global array g_array defined at line 31. This global will be 
 * refered to by assembly generator to directly generate target codes.
 *
 * by Huizhe Li, Master Student, Dartmouth College
 */

#include "quad.h"
#include "typecheck.h"
#include "ast.h"
#include "symtab.h"
#include <stdlib.h>
#include <stdio.h>

/* Constants for convenience */
#define INC_PRE_FORM 1000
#define INC_POST_FORM 1001
#define DEC_PRE_FORM 1002
#define DEC_POST_FORM 1003

extern FILE* out;

/* Debug flag */
extern int qdDebug;

/* The global quad array */
quad g_array[MAXQUADSIZE];

/* Next quad index, also the size of quad array */
int next_quad = 0;

/* Next available temp var */
static int next_free_temp = 0;

/* Current function */
static int cur_fun = -1;

/* The patch queue */
static quad g_patch_queue[MAXQUADSIZE];

/* Size of Patch queue */
static int queue_size = 0;

/* Function entrance address table */
static entrance_table f_addr_table;

/* idx_case_table */
static idx_case_table case_table;

/* Default statement flags */
static int default_index;
static int default_already = 0;

/* Switch statement flags */
static int in_switch = 0;

/* Return statement flags */
static int in_function = 0;
static int ret_statement = 0;

/* Return temp address */
static int ret_val_address;

/* Error flag */
int qd_error = 0;

char* op_str[] = {
  "ADD",
  "ADDF",
  "SUB",
  "SUBF",
  "MUL",
  "MULF",
  "DIV",
  "DIVF",
  "MOD",

  "JLT",
  "JLE",
  "JGT",
  "JGE",
  "JEQ",
  "JNE",
  "JFLT",
  "JFLE",
  "JFGT",
  "JFGE",
  "JFEQ",
  "JFNE",

  "NOT",
 
  "ASSN",
  "ASSNF",

  "GOTO",

  "FUNC_CALL",
  "PUSH",
  "PUSHA",	
  "PUSHFP",
  "POP",
  "RET",
  
  "RDI",
  "RDF",
  
  
  "PRINTI",
  "PRINTF",
  "PRINTB",

  "ITOF",
  "FTOI",

  "FUNC_BODY",
  "START",
  
  "GROW"
    };

/* Insert a quad to backpatch_queue */
void insert_patch_queue(quad qd){
  if (queue_size == MAXQUADSIZE){
    printf("--- error --- patch_queue full\n");
    return;
  }
  g_patch_queue[queue_size++] = qd;
}

/* Backpatch all quads in queue if they "belong" */
void patch_quad_in_queue(int start, int next_quad){
  int i, cur_index;
  for (i = queue_size - 1; i >= 0; i--){
    cur_index = g_patch_queue[i]->index;
    if (cur_index > start)
      patch_quad(cur_index, 1, next_quad);
    else	// quad belongs to outer scope, leave them there
      break;
    queue_size--;
  }
}

/* lookup a function by name, return its entry if found, otherwise NULL */
func_entry lookup_function(func_table function_table, char* name)
{
  int i;
  for (i = 0; i < function_table->size; i++){
    if(strcmp(name, function_table->entries[i]->id) == 0)
      return function_table->entries[i];
  }
  return NULL;
}

/* Binary operation wrapper (+,-,*,/), save a little space */
operand gen_code_biop(flat_symtab var_table, func_table function_table, ast_node root, quad_op op, quad_op fop);

/* Binary operation wrapper (>, >=, <, <=, ==, !=), save a little space */
operand gen_code_reop(flat_symtab var_table, func_table function_table, ast_node root, quad_op op, quad_op fop);

/* Self-increment/decrement operators */
operand gen_code_self(flat_symtab var_table, func_table function_table, ast_node root, int form);

/* Convert current node into an OP_ASSIGN node */
ast_node convert_to_assign(ast_node root, int form);

operand gen_code_reop(flat_symtab var_table, func_table function_table, ast_node root, quad_op op, quad_op fop);

/* Fill func entrance address for CALL quads */
void fill_call();

/* Generate quad arrays for the syntax tree 
 * return the operand if expression node, otherwise the return value if ignored
 */
operand gen_code(flat_symtab var_table, func_table function_table, ast_node root)
{
  ast_node child;
  quad qd;
  data_type dtype;
  ast_node expr_node, id_node, arg_node, list_node;
  int source_addr;
  int int_value;
  double double_value;
  symtab_entry entry;
  operand op1, op2, op3, op_ret, op_temp1, op_temp2;
  operand_type opcode;
  func_entry fEntry;
  int temp_var;
  int i;
  int flag_param;
  int test, testL, testR, jmp, this_case;

  switch(root->node_type){
  case ROOT:	// first init all globals, then "call" main, then generate codes for func_decl
    if(qdDebug == 1)
    printf("--- trace --- ROOT\n");
    for(child = root->left_child; child != NULL; child = child->right_sibling)
      if (child->node_type == VAR_DECL)
	gen_code(var_table, function_table, child);

    // call main, hardcode!
    op1 = create_operand(OP_TYPE_STR, TYPE_INT, (double)0);
    op1->value.string_value = "main";
    insert_quad(create_quad(START, op1, NULL, NULL));

    for(child = root->left_child; child != NULL; child = child->right_sibling)
      if (child->node_type == FUNC_DECL)
	gen_code(var_table, function_table, child);

    return NULL;	// no need to return something

  case VAR_DECL:	// do nothing except when decl & init, in a way similar to OP_ASSIGN 
    if(qdDebug == 1)    printf("--- trace --- VAR_DECL\n");
    expr_node =  root->left_child->right_sibling->right_sibling->right_sibling;
    id_node = root->left_child->right_sibling->right_sibling;

    if (expr_node != NULL){	// var = expr, yeah.
      // do coersion if necessary
      op1 = gen_code(var_table, function_table, id_node);
      op2 = gen_code(var_table, function_table, expr_node);

      if ((op1->dtype >= TYPE_DOUBLE) && (op2->dtype <= TYPE_INT_ARRAY)){	// promote op2
	op_temp1 = create_operand(OP_TYPE_ID, TYPE_DOUBLE, (double) get_temp_addr(next_temp()));
	insert_quad(create_quad(ITOF, op_temp1, op2, NULL));
      }else if ((op1->dtype <= TYPE_INT_ARRAY) && (op2->dtype >= TYPE_DOUBLE)){	// narrow op2
	op_temp1 = create_operand(OP_TYPE_ID, TYPE_INT, (double) get_temp_addr(next_temp()));
	insert_quad(create_quad(FTOI, op_temp1, op2, NULL));
	printf("--- Warning --- implicitly cast double to int at line %d.\n", root->lineNumber);
      }else{	// same type, yeah~
	op_temp1 = op2;	// for convenience
      }

      // now ready to do the assignment!
      if (op1->dtype <= TYPE_INT_ARRAY){
	insert_quad(create_quad(ASSN, op1, op_temp1, NULL));	
      }else{
	insert_quad(create_quad(ASSNF, op1, op_temp1, NULL));	
      }	

    }

    // generate stack ajustment quad
    if ((id_node->left_child == NULL) || (id_node->right_sibling != NULL) ){	// grow stack by 8 bytes
      insert_quad(create_quad(GROW, NULL, NULL, NULL));
    }else{	// array definition
      op1 = gen_code(var_table, function_table, id_node->left_child);	// evaluate array size
      insert_quad(create_quad(GROW, op1, NULL, NULL));			// grow stack by op1 * 8 bytes
    }      
    break;
	
  case FUNC_DECL:	// remember function entry address by creating a FUNC_BODY quad
    if(qdDebug == 1)    printf("--- trace --- FUNC_DECL\n");
    // modify flags
    in_function = 1;
    ret_statement = 0;
    cur_fun = root->left_child->left_child->right_sibling->sn;
    // retrieve info
    id_node = root->left_child->left_child->right_sibling;
    source_addr = next_quad;

    // build and insert quad. 
    opcode = FUNC_BODY;
    op1 = create_operand(OP_TYPE_INT, TYPE_INT, (double)source_addr);	// line number of this quad    
    op2 = create_operand(OP_TYPE_STR, TYPE_INT, (double)id_node->sn);	
    op2->value.string_value = id_node->value.string;	// save func name;
    insert_quad(create_quad(opcode, op1, op2, NULL));

    // insert info into entrance table
    f_addr_table.entrances[f_addr_table.size++] = 
      create_entrance(root->left_child->left_child->right_sibling->value.string, source_addr);

    // generate code for children
    for(child = root->left_child; child != NULL; child = child->right_sibling)
      gen_code(var_table, function_table, child);

    //modify flags, and check for return statement
    in_function = 0;
    if(ret_statement == 0){
      if(strcmp(root->left_child->left_child->value.string, "VOID")!=0){	// need a return value!
	qd_error = 1;
	printf("--- error --- Function must return a value at line %d.\n", root->lineNumber);
      }else{	// void type, add a ret statement silently
	insert_quad(create_quad(RET, NULL, NULL, NULL));
      }
    }

    break;
      
  case RETURN_STMT:		// with or without ret value
    if(qdDebug == 1)    printf("--- trace --- RETURN_STMT\n");
    // check and modify flags
    if (in_function == 0){
      qd_error = 1;
      printf("--- error --- return statement outside function body at line %d.\n", root->lineNumber);
      return NULL;
    }
    ret_statement ++;

    // check type
    if (root->left_child == NULL){	// no return value
      insert_quad(create_quad(RET, NULL, NULL, NULL));
      op_temp1 = NULL;
    }else{	// return value, need a temp for potential expression
      op_temp1 = gen_code(var_table, function_table, root->left_child);
      op1 = create_operand(OP_TYPE_ID, TYPE_INT, (double)ret_val_address);
      insert_quad(create_quad(RET, op1, op_temp1, NULL));
    }
   
    return op_temp1;

   case IDENTIFIER:	// array or var?
    if(qdDebug == 1)    printf("--- trace --- IDENTIFIER\n");
    // retrieve info
    entry = var_table->entries[root->sn];
    dtype = entry->dtype;
    source_addr = var_table->entries[root->sn]->addr;

    if (root->left_child != NULL){    

      // generate code for expression
      op1 = gen_code(var_table, function_table, root->left_child);
	
      // calculate address offset, and add it to source_addr   
      // create a temp to store the final address
      op_ret = create_operand(OP_TYPE_PT, dtype, get_temp_addr(next_temp()));      

      // compute offset to op_temp1
      op_temp1 = create_operand(OP_TYPE_ID, dtype, get_temp_addr(next_temp()));      
      op2 = create_operand(OP_TYPE_INT, TYPE_INT, (double)8);
      insert_quad(create_quad(MUL, op_temp1, op1, op2));

      // now op_temp1 has the right offset, add it with source_addr
      op2 = create_operand(OP_TYPE_INT, dtype, (double)source_addr); // dereference source_addr to op2

      // now compute the final address to op_temp1
      insert_quad(create_quad(ADD, op_ret, op2, op_temp1));
    
      
      
    }else{	// not an array - simple
      op_ret = create_operand(OP_TYPE_ID, dtype, (double)source_addr);
    }

    // return operand
    return op_ret;

  case CALL:
    if(qdDebug == 1)    printf("--- trace --- CALL\n");
    // a FUNC_CALL quad has two operands, the first being the sn of the function (for now),
    // and the second being the operand that is to take the return value opon returning, 
    // if the function will return a value
    //
    // there is no instruction as push/pop in TM57. (nor is ret). the opcode here will be 
    // fully expanded in assembly-generation stage. (especially for SP ajusting, which needs not 
    // to be worried within a function body.)
    //
    // first push params, fp and ret addr.
    // then make the call, receiving ret value if applicable, and pop fp, ret address and params

    // push params
    arg_node = root->left_child->right_sibling;
    id_node = root->left_child;
    if (arg_node == NULL){	// the function takes no arguments, do nothing
    }else{	// push arguments from left to right, just as the order they are stored in the ast
      opcode = PUSH;
      // find the fEntry in function_table
      fEntry = lookup_function(function_table, id_node->value.string);
      i = 0;
      for(child = arg_node->left_child; child != NULL; child = child->right_sibling){
	opcode = PUSH;
	// use a temp to hold the value of the argument(expression)
	op_temp1 = gen_code(var_table, function_table, child);
	// do coercion/widening if necessary
	// check parameter type
	dtype = fEntry->types[i++];
	if ((op_temp1->dtype == TYPE_INT) && (dtype == TYPE_DOUBLE)){	// widen argument
	  op_temp2 = create_operand(OP_TYPE_ID, TYPE_DOUBLE, get_temp_addr(next_temp()));
	  insert_quad(create_quad(ITOF, op_temp2, op_temp1, NULL));	
	  op_temp1 = op_temp2;
	}else if  ((op_temp1->dtype == TYPE_DOUBLE) && (dtype == TYPE_INT)){	// coerce argument
	  op_temp2 = create_operand(OP_TYPE_ID, TYPE_DOUBLE, get_temp_addr(next_temp()));
	  insert_quad(create_quad(FTOI, op_temp2, op_temp1, NULL));	
	  printf("--- Warning --- implicitly cast double to int at line %d.\n", root->lineNumber);
	  op_temp1 = op_temp2;
	}else{	// push address instead of value if array argument
	  //    printf("name: %s.\n", id_node->value.string);
	  //printf("dtype: %d.\n", op_temp1->dtype);

	  if ((op_temp1->dtype == TYPE_DOUBLE_ARRAY) || (op_temp1->dtype == TYPE_INT_ARRAY)){
	    opcode = PUSHA;
	  }
	}
	// push this argument, yeah~
	insert_quad(create_quad(opcode, op_temp1, NULL, NULL));
      }
    }

    // push fp
    op1 = create_operand(OP_TYPE_INT, TYPE_INT, (double)0);	// mark: figure out fp when generating assembly
    insert_quad(create_quad(PUSHFP, op1, NULL, NULL));

    // push return address, which (for now) is the index after "FUNC_CALL" quad
    op1 = create_operand(OP_TYPE_INT, TYPE_INT, (double)(next_quad+2));
    insert_quad(create_quad(PUSH, op1, NULL, NULL));
    
    // make the call. save ret value in a temp if necessary
    fEntry = lookup_function(function_table, id_node->value.string);
    op1 = create_operand(OP_TYPE_STR, TYPE_INT, (double)fEntry->sn);
    op1->value.string_value = id_node->value.string;
    dtype = fEntry->dtype;
    op_temp1 = NULL;
    if (dtype == TYPE_VOID){	// no ret value, just make the call
      insert_quad(create_quad(FUNC_CALL, op1, NULL, NULL));
    }else{	// need a temp to save ret value
      ret_val_address = get_temp_addr(next_temp());
      op_temp1 = create_operand(OP_TYPE_ID, dtype, ret_val_address);
      insert_quad(create_quad(FUNC_CALL, op1, op_temp1, NULL));
    }

    // pop arguments
    // each POP pops one argument, so we need argc POP quads
    // the extra two POPs are for fp and ret address
    for (i = 0; i < fEntry->argc + 2; i++)
      insert_quad(create_quad(POP, NULL, NULL, NULL));    
    return op_temp1;

    // ------------------------- branch statements ------------------------//
  case IF_STMT:
    if(qdDebug == 1)    printf("--- trace --- IF_STMT\n");
    op1 = gen_code(var_table, function_table, root->left_child);	// evaluate condition expression
    testL = next_quad;
    if (op1->dtype == TYPE_INT)
      insert_quad(create_quad(JEQ, op1, NULL, NULL));	// need backpatch
    else
      insert_quad(create_quad(JFEQ, op1, NULL, NULL));	// need backpatch

    gen_code(var_table, function_table, root->left_child->right_sibling);	// gen code for then part
    
    patch_quad(testL, 2, next_quad);
    return NULL;	// no one needs it

  case IF_ELSE_STMT:
    if(qdDebug == 1)    printf("--- trace --- IF_ELSE_STMT\n");
    op1 = gen_code(var_table, function_table, root->left_child);	// evaluate condition expression
    testL = next_quad;
    if (op1->dtype == TYPE_INT)
      insert_quad(create_quad(JEQ, op1, NULL, NULL));	// need backpatch
    else
      insert_quad(create_quad(JFEQ, op1, NULL, NULL));	// need backpatch
    gen_code(var_table, function_table, root->left_child->right_sibling);	// gen code for then part
    jmp = next_quad;
    insert_quad(create_quad(GOTO, NULL, NULL, NULL));	// need backpatch
    
    patch_quad(testL, 2, next_quad);
    gen_code(var_table, function_table, root->left_child->right_sibling->right_sibling);// gen code for else part
    
    patch_quad(jmp, 1, next_quad);
    return NULL;	// no one wants it
    
  case SWITCH_STMT:    	// tricky one
    // First evaluate the expression.
    // Then compare it with each case constant, and generate a series of GOTO's.
    // Of course these quads need backpatching, which is done when encountering a CASE_STMT.
    // Store (quad_index, case_constant) pairs in a global structure, so CASE could refer to 
    // it to decide where to patch
    // Remember to patch BREAK statements at the end of SWITCH, just as in other loop statements

    // modify flags
    in_switch = 1;
    default_already = 0;
    jmp = next_quad;	// the top. used to patch break statements
    op1 = gen_code(var_table, function_table, root->left_child);	// evaluate expression
    op_temp1 = create_operand(OP_TYPE_ID, TYPE_INT, get_temp_addr(next_temp()));

    // now gather how many cases are there as well as their constants

    list_node = root->left_child->right_sibling->left_child->right_sibling;	// STMT_LIST node
    for(child = list_node->left_child; child != NULL; child = child->right_sibling){
      // insert a pair upon seeing CASE
      if (child->node_type == CASE_STMT){
	this_case = child->value.int_value;	// save case constant
	// compare expression and this case
	op2 = create_operand(OP_TYPE_INT, TYPE_INT, (double)this_case);
	insert_quad(create_quad(SUB, op_temp1, op1, op2));
	// the next quad will be a JEQ, one that needs backpatching
	if (create_pair(next_quad, this_case) == NULL)
	  printf("--- error --- duplicate cases in switch block at line %d.\n", root->lineNumber);
	// new ready to generate the GOTO quad
	insert_quad(create_quad(JEQ, op_temp1, NULL, NULL));	// this will be patched in a CASE_STMT
      }
    }
    // don't forget default.
    default_index = next_quad;
    insert_quad(create_quad(GOTO, NULL, NULL, NULL));	// this will be patched in a DEFAULT_STMT
    
    // finally! gen_code for its children
    for(child = list_node->left_child; child != NULL; child = child->right_sibling){
      gen_code(var_table, function_table, child);
    }

    // patch breaks
    patch_quad_in_queue(jmp, next_quad);
     
    // modify and check flags
    in_switch = 0;
    if (default_already == 0){
      qd_error = 1;
      printf("--- error --- must provide a default statement at line %d.\n", root->lineNumber);
    }
    return NULL;
    
  case CASE_STMT:	// patch the jumps!    
    if (in_switch == 0){
      qd_error = 1;
      printf("--- error --- case statement outside switch block at line %d.\n", root->lineNumber);
      return NULL;
      }	
    patch_a_case(root->value.int_value, next_quad);
    return NULL;

  case DEFAULT_STMT:	// patch the jump! remember it's a GOTO, not JEQ
    if (in_switch == 0){
      qd_error = 1;
      printf("--- error --- default statement outside switch block at line %d.\n", root->lineNumber);
      return NULL;
    }

    if (default_already == 1){
      qd_error = 1;
      printf("--- error --- duplicate default statement at line %d.\n", root->lineNumber);
      return NULL;
    }else{
      default_already = 1;
    }
    patch_quad(default_index, 1, next_quad);
    return NULL;
    
    
    // ------------------------- loop statements ------------------------//
    // loop statements need to deal with "break" statements
    // there may be more than one break statements within a loop body, and they all
    // jump to the same position. To achieve this, break quads are placed in a
    // "queue", and when loop bodies closes, these quads can be backpatched.

    // another issue concerns the position where a break statement (or case statement ,etc)
    // could appear. Before backpatching a quad, we should assert that the index of this 
    // quad is between those of the loop body. A smaller index may imply a break statemetn from
    // an outer loop, or worse, an illegal break statement. To do this we add an "index" attribute
    // to each quad structure.
    
    // if there exists one or more break quads at the end of compilation, it can be implied that
    // these statements are illegal. The compiler should report an error then, and abort.

  case WHILE_STMT:
    if(qdDebug == 1)    printf("--- trace --- WHILE_STMT\n");
    // top of the loop body. create a operand holding this position
    jmp = next_quad;
    op2 = create_operand(OP_TYPE_INT, TYPE_INT, (double)jmp);
    op1 = gen_code(var_table, function_table, root->left_child);
    test = next_quad;
    if (op1->dtype == TYPE_INT)
      insert_quad(create_quad(JEQ, op1, NULL, NULL));	// need backpatch
    else
      insert_quad(create_quad(JFEQ, op1, NULL, NULL));	// need backpatch
    gen_code(var_table, function_table, root->left_child->right_sibling);
    insert_quad(create_quad(GOTO, op2, NULL, NULL));	// jmp to the top
    patch_quad(test, 2, next_quad);
    patch_quad_in_queue(jmp, next_quad);		// patch break quads 
    return NULL;	// nobody cares
	
  case FOR_STMT:
    gen_code(var_table, function_table, root->left_child);
    test = next_quad;
    op1 = gen_code(var_table, function_table, root->left_child->right_sibling);
    op2 = create_operand(OP_TYPE_INT, TYPE_INT, (double)test);
    testL = next_quad;
    if (op1->dtype == TYPE_INT)
      insert_quad(create_quad(JEQ, op1, NULL, NULL));	// need backpatch
    else
      insert_quad(create_quad(JFEQ, op1, NULL, NULL));	// need backpatch
    gen_code(var_table, function_table, root->left_child->right_sibling->right_sibling);
    gen_code(var_table, function_table, root->left_child->right_sibling->right_sibling->right_sibling);
    insert_quad(create_quad(GOTO, op2, NULL, NULL));	// jmp to the beginning
    patch_quad(testL, 2, next_quad);
    patch_quad_in_queue(jmp, next_quad);		// patch break quads 
    return NULL;

    break;

  case DO_WHILE_STMT:
    if(qdDebug == 1)    printf("--- trace --- DO_WHILE_STMT\n");
    // top of the loop body. create a operand holding this position
    jmp = next_quad;
    gen_code(var_table, function_table, root->left_child);
    op2 = create_operand(OP_TYPE_INT, TYPE_INT, (double)jmp);
    op1 = gen_code(var_table, function_table, root->left_child->right_sibling);
    test = next_quad;
    if (op1->dtype == TYPE_INT)
      insert_quad(create_quad(JEQ, op1, NULL, NULL));	// need backpatch
    else
      insert_quad(create_quad(JFEQ, op1, NULL, NULL));	// need backpatch
    insert_quad(create_quad(GOTO, op2, NULL, NULL));	// jmp to the top
    patch_quad(test, 2, next_quad);
    patch_quad_in_queue(jmp, next_quad);		// patch break quads 
    return NULL;	// nobody cares
    break;

  case BREAK_STMT:
    if(qdDebug == 1)    printf("--- trace --- BREAK_STMT\n");
    qd = create_quad(GOTO, NULL, NULL, NULL);	// need backpatch
    insert_quad(create_quad(GOTO, NULL, NULL, NULL));	
    insert_patch_queue(qd);			// i'm waiting to be patched!
    return NULL;	
    

    // ----------------------------- I/O ------------------------------//
  case PRINT_STMT:
     // may print int, double or string
    if (root->left_child->node_type == STR_LITERAL){	// string! yeah
      // create operand holding the string constant
      op1 = create_operand(OP_TYPE_STR, TYPE_VOID, (double)0);
      op1->value.string_value =
	root->left_child->value.string;
      insert_quad(create_quad(PRINTB, op1, NULL, NULL));
    }else{
      op2 = gen_code(var_table, function_table, root->left_child);
      if (op2->dtype <= TYPE_INT_ARRAY){
	insert_quad(create_quad(PRINTI, op2, NULL, NULL));
      }else if (op2->dtype >= TYPE_DOUBLE){
	insert_quad(create_quad(PRINTF, op2, NULL, NULL));
      }
    }
    return NULL;
      
  case READ_STMT:
    op1 = gen_code(var_table, function_table, root->left_child);	// compute var address
    if (op1->dtype <= TYPE_INT_ARRAY)
      insert_quad(create_quad(RDI, op1, NULL, NULL));
    else if (op1->dtype >= TYPE_DOUBLE)
      insert_quad(create_quad(RDF, op1, NULL, NULL));
    else printf("--- internal error --- should not happen\n");
    return NULL;

    // ------------------------- operaters ----------------------------//
    
    // these binary operators are joined for coding convenience
  case OP_PLUS:
    return gen_code_biop(var_table, function_table, root, ADD, ADDF);
  case OP_MINUS:	// binary or unary?
    if (root->left_child->right_sibling != NULL)	// binary
      return gen_code_biop(var_table, function_table, root, SUB, SUBF);
    else{						// unary
      op1 = gen_code(var_table, function_table, root->left_child);
      // get -op1 
      if (op1->dtype <= TYPE_INT_ARRAY){ 
	op_temp1 = create_operand(OP_TYPE_ID, TYPE_INT, get_temp_addr(next_temp()));
	op2 = create_operand(OP_TYPE_INT, TYPE_INT, (double)0);
	insert_quad(create_quad(SUB, op_temp1, op2, op1));
	return op_temp1;
      }else{	
	op_temp1 = create_operand(OP_TYPE_ID, TYPE_DOUBLE, get_temp_addr(next_temp()));
	op2 = create_operand(OP_TYPE_DOUBLE, TYPE_DOUBLE, (double)0);
	insert_quad(create_quad(SUBF, op_temp1, op2, op1));
	return op_temp1;
      }     
    }
  case OP_TIMES:
    return gen_code_biop(var_table, function_table, root, MUL, MULF);
  case OP_DIVIDE:
    return gen_code_biop(var_table, function_table, root, DIV, DIVF);
  case OP_MOD:
    return gen_code_biop(var_table, function_table, root, MOD, 0);	// type check guarentee int operands

    // these involve condition jumps, join them for coding convenience
  case OP_EQUALS:
    return gen_code_reop(var_table, function_table, root, JEQ, JFEQ);
  case OP_LESS:
    return gen_code_reop(var_table, function_table, root, JLT, JFLT);
  case OP_LESSEQ:
    return gen_code_reop(var_table, function_table, root, JLE, JFLE);
  case OP_GRTER:
    return gen_code_reop(var_table, function_table, root, JGT, JFGT);
  case OP_GRTEREQ:
    return gen_code_reop(var_table, function_table, root, JGE, JFGE);
  case OP_NEQ:
    return gen_code_reop(var_table, function_table, root, JNE, JFNE);

    // self-increment/decrement operators
  case OP_INC_PRE:     
    return gen_code_self(var_table, function_table, root, INC_PRE_FORM);
  case OP_INC_POST:
    return gen_code_self(var_table, function_table, root, INC_POST_FORM);
  case OP_DEC_PRE:
    return gen_code_self(var_table, function_table, root, DEC_PRE_FORM);
  case OP_DEC_POST:
    return gen_code_self(var_table, function_table, root, DEC_POST_FORM);

  case OP_ASSIGN:	// may need to do coersion
   if(qdDebug == 1)    printf("--- trace --- OP_ASSIGN\n");
    
    // do coersion if necessary
    op1 = gen_code(var_table, function_table, root->left_child);
    op2 = gen_code(var_table, function_table, root->left_child->right_sibling);
   
    if ((op1->dtype >= TYPE_DOUBLE) && (op2->dtype <= TYPE_INT_ARRAY)){	// promote op2
      op_temp1 = create_operand(OP_TYPE_ID, TYPE_DOUBLE, (double) get_temp_addr(next_temp()));
      insert_quad(create_quad(ITOF, op_temp1, op2, NULL));
    }else if ((op1->dtype <= TYPE_INT_ARRAY) && (op2->dtype >= TYPE_DOUBLE)){	// narrow op2   
      op_temp1 = create_operand(OP_TYPE_ID, TYPE_INT, (double) get_temp_addr(next_temp()));
      insert_quad(create_quad(FTOI, op_temp1, op2, NULL));
      printf("--- Warning --- implicitly cast double to int at line %d.\n", root->lineNumber);
    }else{	// same type, yeah~
      op_temp1 = op2;	// for convenience
    }

    // now ready to do the assignment!
    if (op1->dtype <= TYPE_INT_ARRAY)
      insert_quad(create_quad(ASSN, op1, op_temp1, NULL));	
    else
      insert_quad(create_quad(ASSNF, op1, op_temp1, NULL));	
 
     return op1;

    // AND, OR, NOT
  case OP_NOT:	
    if(qdDebug == 1)    printf("--- trace --- OP_NOT\n");
    op_temp1 = create_operand(OP_TYPE_ID, TYPE_INT, get_temp_addr(next_temp()));	// hold the value
    op3 = gen_code(var_table, function_table, root->left_child);

    // prepare operand holding 0 and 1
    op1 = create_operand(OP_TYPE_INT, TYPE_INT, (double)0);
    op2 = create_operand(OP_TYPE_INT, TYPE_INT, (double)1);

    // forced to be integer by type checker
    test = next_quad;
    insert_quad(create_quad(JEQ, op3, NULL, NULL));	// need backpatch
    insert_quad(create_quad(ASSN, op_temp1, op1, NULL));   
    jmp = next_quad;	
    insert_quad(create_quad(GOTO, NULL, NULL, NULL));   	// need backpatch
    patch_quad(test, 2, next_quad);
    insert_quad(create_quad(ASSN, op_temp1, op2, NULL));   	
    patch_quad(jmp, 1, next_quad);
    
    return op_temp1;

  case OP_AND:
    if(qdDebug == 1)    printf("--- trace --- OP_AND\n");
    op_temp1 = create_operand(OP_TYPE_ID, TYPE_INT, get_temp_addr(next_temp()));	// hold the value

    op1 = gen_code(var_table, function_table, root->left_child);       
    testL = next_quad;
    insert_quad(create_quad(JEQ, op1, NULL, NULL));	// need backpatch

    op2 = gen_code(var_table, function_table, root->left_child->right_sibling);
    testR = next_quad;
    insert_quad(create_quad(JEQ, op2, NULL, NULL));	// need backpatch

    // prepare operands holding 0 and 1
    op1 = create_operand(OP_TYPE_INT, TYPE_INT, (double)0);
    op2 = create_operand(OP_TYPE_INT, TYPE_INT, (double)1);

    insert_quad(create_quad(ASSN, op_temp1, op2, NULL));
    jmp = next_quad;
    insert_quad(create_quad(GOTO, NULL, NULL, NULL));	// need backpatch

    patch_quad(testL, 2, next_quad);
    patch_quad(testR, 2, next_quad);

    // if either test fails, jump to here
    insert_quad(create_quad(ASSN, op_temp1, op1, NULL));    

    // if both tests pass, jump to here
    patch_quad(jmp, 1, next_quad);

    return op_temp1;

  case OP_OR:
    if(qdDebug == 1)    printf("--- trace --- OP_OR\n");
    op_temp1 = create_operand(OP_TYPE_ID, TYPE_INT, get_temp_addr(next_temp()));	// hold the value

    op1 = gen_code(var_table, function_table, root->left_child);       
    testL = next_quad;
    insert_quad(create_quad(JNE, op1, NULL, NULL));	// need backpatch

    op2 = gen_code(var_table, function_table, root->left_child->right_sibling);
    testR = next_quad;
    insert_quad(create_quad(JNE, op2, NULL, NULL));	// need backpatch

    // prepare operands holding 0 and 1
    op1 = create_operand(OP_TYPE_INT, TYPE_INT, (double)0);
    op2 = create_operand(OP_TYPE_INT, TYPE_INT, (double)1);

    insert_quad(create_quad(ASSN, op_temp1, op1, NULL));
    jmp = next_quad;
    insert_quad(create_quad(GOTO, NULL, NULL, NULL));	// need backpatch

    patch_quad(testL, 2, next_quad);
    patch_quad(testR, 2, next_quad);

    // if either test fails, jump to here
    insert_quad(create_quad(ASSN, op_temp1, op2, NULL));    

    // if both tests pass, jump to here
    patch_quad(jmp, 1, next_quad);

    return op_temp1;

    // ------------------------------ trivial ones ---------------------------//
  case FUNC_HEADER:
  case FUNC_PARAMS:	// need to do nothing
    if(qdDebug == 1)    printf("--- trace --- TRIVIAL\n");
    break;

  case CMPD_STMT:
  case LOCAL_DECL:
  case STMT_LIST:    // recursively generate code 
    if(qdDebug == 1)    printf("--- trace --- TRIVIAL\n");
    for(child = root->left_child; child != NULL; child = child->right_sibling)
      gen_code(var_table, function_table, child);
    break;
   
  case INT_LITERAL:
    if(qdDebug == 1)    printf("--- trace --- INT_LITERAL\n");
    return create_operand(OP_TYPE_INT, TYPE_INT, (double)root->value.int_value);

  case DOUBLE_LITERAL:
    if(qdDebug == 1)    printf("--- trace --- DOUBLE_LITERAL\n");
    return create_operand(OP_TYPE_DOUBLE, TYPE_DOUBLE, root->value.double_value);

  default:
    if(qdDebug == 1)    printf("--- Not reached yet. Be patient:) ---\n");
    break;
  }
}

/* Create operand, need to cast value type */
operand create_operand(operand_type type, data_type dtype,  double value)
{
  operand new_op = (operand)malloc(sizeof(struct operand));
  new_op->value.double_value = value;
  new_op->value.id_addr = new_op->value.int_value = (int)value;
  new_op->op_type = type;
  new_op->dtype = dtype;
  
  return new_op;
}

/* Create a quad */
quad create_quad(quad_op op, operand op1, operand op2, operand op3)
{
  quad new_qd = (quad)malloc(sizeof(struct quad));
  new_qd->op = op;
  new_qd->op1 = op1;
  new_qd->op2 = op2;
  new_qd->op3 = op3;
  new_qd->index = next_quad;
  return new_qd;
}

/* Insert a quad to global quad array */
void insert_quad(quad qd)
{
  g_array[next_quad++] = qd;
}

/* Get next available temp */
int next_temp()
{
  int ret = next_free_temp;
  next_free_temp = (next_free_temp + 1) % MAXTEMP;
  return ret;
}

/* Get mem address of a given temp */
int get_temp_addr(int no_temp)
{
  return TEMP_BASE_ADDR - 8 * (no_temp+1);
}

void print_operand(operand opx)
{
  if (opx == NULL){
    fprintf(out,"N/A");
    return;
  }
  
 switch(opx->op_type){
  case OP_TYPE_INT:
      fprintf(out,"int: %d", opx->value.int_value);
    break;
  case OP_TYPE_DOUBLE:
    fprintf(out,"double: %f", opx->value.double_value);
    break;
  case OP_TYPE_ID:
    fprintf(out,"addr: %d", opx->value.id_addr);
    break;
  case OP_TYPE_STR:
    fprintf(out,"str: %s", opx->value.string_value);
    break;
 case OP_TYPE_PT:
   fprintf(out, "pointer: %d", opx->value.int_value);
    break;
  default:
    break;
  }
}	   


void print_quad(quad qd)
{
  fprintf(out,"* %d  ", qd->index);

  fprintf(out,"( %s,\t", op_str[qd->op]);
  print_operand(qd->op1);

  fprintf(out,",\t");
  print_operand(qd->op2);

  fprintf(out,",\t");
  print_operand(qd->op3);

  fprintf(out," )\n");
}

void print_code()
{
  int i;

  for (i = 0; i < next_quad; i++){
    print_quad(g_array[i]);
  }

}

/* Binary operation wrapper (+,-,*,/), save a little space */
operand gen_code_biop(flat_symtab var_table, func_table function_table, ast_node root, quad_op op, quad_op fop)
{
  operand op1, op2, op_temp1, op_ret;
  int source_addr;
  
  op1 = gen_code(var_table, function_table, root->left_child);
  op2 = gen_code(var_table, function_table, root->left_child->right_sibling);
  op_ret = create_operand(OP_TYPE_ID, TYPE_INT,  get_temp_addr(next_temp()));

  // deal with coersion by check types. four combinations in total
  if ((op1->dtype <= TYPE_INT_ARRAY) && (op2->dtype >= TYPE_DOUBLE)){	// promote op1
    // create new temp 
    op_temp1 = create_operand(OP_TYPE_ID, TYPE_DOUBLE, (double) get_temp_addr(next_temp()));
    // promote the temp: get double value from op1 and save it into temp
    insert_quad(create_quad(ITOF, op_temp1, op1, NULL));
    // ready to add: op2 + op_temp1 => op_ret
    op_ret->dtype = TYPE_DOUBLE;
    insert_quad(create_quad(fop, op_ret, op_temp1, op2));
  }else if  ((op2->dtype <= TYPE_INT_ARRAY) && (op1->dtype >= TYPE_DOUBLE)){
    op_temp1 = create_operand(OP_TYPE_ID, TYPE_DOUBLE, (double) get_temp_addr(next_temp()));
    insert_quad(create_quad(ITOF, op_temp1, op2, NULL));
    op_ret->dtype = TYPE_DOUBLE;
    insert_quad(create_quad(fop, op_ret, op_temp1, op1));
  }else {
    if (op1->dtype <= TYPE_INT_ARRAY)
      insert_quad(create_quad(op, op_ret, op1, op2));
    else{
      op_ret->dtype = TYPE_DOUBLE;
      insert_quad(create_quad(fop, op_ret, op1, op2));
    }
  }
	
  return op_ret;    
}

/* Binary operation wrapper (>, >=, <, <=, ==, !=), save a little space */
operand gen_code_reop(flat_symtab var_table, func_table function_table, ast_node root, quad_op op, quad_op fop)
{
  operand temp, temp2, op1, op2, zero, one;
  int test, jumpQ;

  // create operand to have 0 and 1, for later use
  zero = create_operand(OP_TYPE_INT, TYPE_INT, (double)0);	
  one = create_operand(OP_TYPE_INT, TYPE_INT, (double)1);

  // holds result
  temp = create_operand(OP_TYPE_ID, TYPE_INT, get_temp_addr(next_temp()));

  // evaluate left and right child
  op1 = gen_code(var_table, function_table, root->left_child);
  op2 = gen_code(var_table, function_table, root->left_child->right_sibling);
  
  // sub them!
  
  // check dtype
  if ((op1->dtype <= TYPE_INT_ARRAY) && (op2->dtype <= TYPE_INT_ARRAY)){	// easy part
    insert_quad(create_quad(SUB, temp, op1, op2));
    test = next_quad;	// save index of next quad before hand
    insert_quad(create_quad(op, temp, NULL, NULL)); 	// need backpatch
    insert_quad(create_quad(ASSN, temp, zero, NULL));
    jumpQ = next_quad;
    insert_quad(create_quad(GOTO, NULL, NULL, NULL));	// need backpatch
    // patch "test"
    patch_quad(test, 2, next_quad);
    insert_quad(create_quad(ASSN, temp, one, NULL));	
    // patch "jumpQ"
    patch_quad(jumpQ, 1, next_quad);
  } else if ((op1->dtype >= TYPE_DOUBLE) && (op2->dtype >= TYPE_DOUBLE)){	// easy part
    insert_quad(create_quad(SUBF, temp, op1, op2));
    test = next_quad;	// save index of next quad before hand
    insert_quad(create_quad(fop, temp, NULL, NULL)); 	// need backpatch
    insert_quad(create_quad(ASSN, temp, zero, NULL));
    jumpQ = next_quad;
    insert_quad(create_quad(GOTO, NULL, NULL, NULL));	// need backpatch
    // patch "test"
    patch_quad(test, 2, next_quad);
    insert_quad(create_quad(ASSN, temp, one, NULL));	
    // patch "jumpQ"
    patch_quad(jumpQ, 1, next_quad);
  } else if (op1->dtype <= TYPE_INT_ARRAY){	// need to promote op1 to double
    temp2 = create_operand(OP_TYPE_ID, TYPE_DOUBLE, get_temp_addr(next_temp()));
    insert_quad(create_quad(ITOF, temp2, op1, NULL));	// promote op1 and save to temp2

    // now everything is the same as before
    insert_quad(create_quad(SUBF, temp, temp2, op2));
    test = next_quad;	// save index of next quad before hand
    insert_quad(create_quad(fop, temp, NULL, NULL)); 	// need backpatch
    insert_quad(create_quad(ASSN, temp, zero, NULL));
    jumpQ = next_quad;
    insert_quad(create_quad(GOTO, NULL, NULL, NULL));	// need backpatch
    // patch "test"
    patch_quad(test, 2, next_quad);
    insert_quad(create_quad(ASSN, temp, one, NULL));	
    // patch "jumpQ"
    patch_quad(jumpQ, 1, next_quad);
  } else { 	// need to promote op2 to double
    temp2 = create_operand(OP_TYPE_ID, TYPE_DOUBLE, get_temp_addr(next_temp()));
    insert_quad(create_quad(ITOF, temp2, op2, NULL));	// promote op2 and save to temp2

    // now everything is the same as before
    insert_quad(create_quad(SUBF, temp, temp2, op1));
    test = next_quad;	// save index of next quad before hand
    insert_quad(create_quad(fop, temp, NULL, NULL)); 	// need backpatch
    insert_quad(create_quad(ASSN, temp, zero, NULL));
    jumpQ = next_quad;
    insert_quad(create_quad(GOTO, NULL, NULL, NULL));	// need backpatch
    // patch "test"
    patch_quad(test, 2, next_quad);
    insert_quad(create_quad(ASSN, temp, one, NULL));	
    // patch "jumpQ"
    patch_quad(jumpQ, 1, next_quad);
  }
   return temp;
}

void patch_quad(int q, int i, int next)
{
  operand op;
  quad qd = g_array[q];
  op = create_operand(OP_TYPE_INT, TYPE_INT, (double)next);

  switch(i){
  case 1:
    qd->op1 = op;
    break;
  case 2:
    qd->op2 = op;
    break;
  case 3:
    qd->op3 = op;
    break;
  default:
    printf("--- internal error --- argument 3 should be within 1~3\n");
    break;
  }
}
    
/* Helper function */
ast_node clone_node(ast_node root)
{
  ast_node ret = create_ast_node(root->node_type);
  *ret = *root;
  return ret;
}

/* Convert current node into an OP_ASSIGN node */
ast_node convert_to_assign(ast_node root, int form)
{
  ast_node ret = create_ast_node(OP_ASSIGN);
  ast_node temp;
  ret->left_child = clone_node(root->left_child);
  ret->left_child->left_child = ret->left_child->right_sibling = NULL;
  switch(form){
  case INC_POST_FORM:
  case INC_PRE_FORM:
    ret->left_child->right_sibling = create_ast_node(OP_PLUS);
    break;
  case DEC_POST_FORM:
  case DEC_PRE_FORM:
    ret->left_child->right_sibling = create_ast_node(OP_MINUS);
    break;
  default:
    printf("--- internal error --- this should not appear\n");
    break;
  }
  temp = ret->left_child->right_sibling->left_child = clone_node(root->left_child);
  temp->left_child = temp->right_sibling = NULL;
  temp = ret->left_child->right_sibling->left_child->right_sibling = create_ast_node(INT_LITERAL);
  temp->value.int_value = 1;
  temp->static_expr = 1;
  temp->expr.int_value = 1;

  return ret;
}

/* Self-increment/decrement operators */
operand gen_code_self(flat_symtab var_table, func_table function_table, ast_node root, int form)
{
  // play a trick: convert this node to OP_ASSIGN and gen_code on the resulting node
  // then return according to form PRE or POST

  operand temp1 = create_operand(OP_TYPE_ID, TYPE_INT, get_temp_addr(next_temp()));
  operand temp2 = create_operand(OP_TYPE_INT, TYPE_INT, (double)1);
  ast_node assign_node = convert_to_assign(root, form);
  // print_ast(assign_node, 0);
  operand op = gen_code(var_table, function_table, assign_node);

  // compute return value
  switch(form){
  case INC_PRE_FORM:
  case DEC_PRE_FORM:	// just return op
    return op;
  case INC_POST_FORM:
    insert_quad(create_quad(SUB, temp1, op, temp2));	// temp1 = op - 1
    return temp1;
  case DEC_POST_FORM:
    insert_quad(create_quad(ADD, temp1, op, temp2));	// temp1 = op + 1
    return temp1;
  }
}

/* Create an func_entrance */
func_entrance create_entrance(char* name, int index)
{
  func_entrance new_entry = (func_entrance)malloc(sizeof(struct func_entrance));
  new_entry->name = name;
  new_entry->index = index;
  return new_entry;
}

void fill_call()
{
  int i, j;
  
  for (i = 0; i < next_quad; i++){
    if (g_array[i]->op == FUNC_CALL || g_array[i]->op == START){
      for(j = 0; j < f_addr_table.size; j++){
	if (strcmp(g_array[i]->op1->value.string_value, f_addr_table.entrances[j]->name)==0){
	  // fill entrance
	  g_array[i]->op1->op_type = OP_TYPE_INT;
	  g_array[i]->op1->dtype = TYPE_INT;
	  g_array[i]->op1->value.int_value = f_addr_table.entrances[j]->index;
	  break;
	}
      }
    }
  }

  // secretly check break statements
  if (queue_size > 0){
    qd_error = 1;
    printf("--- error --- break statement outside loop or switch statement.\n");
  }
}

/* Create a idx_case_pair and insert it*/
idx_case_pair create_pair(int index, int case_const)
{
  int i;
  int j;
  idx_case_pair new_pair = (idx_case_pair)malloc(sizeof(struct idx_case_pair));
  new_pair->quad_index = index;
  new_pair->case_const = case_const;
  // insert
  if (case_table.size >= 100)	{// see quad.h where it's hardcoded. 
    qd_error = 1;
    printf("--- error --- no more than 100 cases!\n");
    return new_pair;
  }

  case_table.pairs[case_table.size++] = new_pair;

  // check if duplicate cases
  for (i = 0; i < case_table.size; i++){
    for (j = i+1; j < case_table.size; j++){
      if (case_table.pairs[i]->case_const == case_table.pairs[j]->case_const){
	qd_error = 1;
	case_table.size--;
	return NULL;
      }
    }
  }

  return new_pair;
}

/* Lookup the pair table and patch */
void patch_a_case(int case_const, int next_quad)
{
  int i;
  for (i = 0; i < case_table.size; i++){
    if (case_const == case_table.pairs[i]->case_const){
      patch_quad(case_table.pairs[i]->quad_index, 2, next_quad);
      return;
    }
  }
}
