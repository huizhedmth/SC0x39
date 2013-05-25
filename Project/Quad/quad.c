/* quad.c
 *
 * Implementation of quad-related functions
 *
 * by Huizhe Li, Master Student, Dartmouth College
 */

#include "quad.h"
#include "typecheck.h"
#include "ast.h"
#include "symtab.h"
#include <stdlib.h>
#include <stdio.h>

/* The global quad array */
quad g_array[MAXQUADSIZE];

/* Next quad index, also the size of quad array */
static int next_quad = 0;

/* Next available temp var */
static int next_free_temp = 0;

/* Current function */
static int cur_fun = -1;


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
  "JEQ",
  "JGT",
  "JGE",
  "JEQ",
  "JNQ",
  "JFLT",
  "JFEQ",
  "JFGT",
  "JFGE",
  "JFEQ",
  "JFNQ",

  "NOT",
  "PREINC",
  "INCPOST",
  "PREDEC",
  "DECPOST",

  "ASSIGNI",
  "ASSIGNF",
  "ASSIGNV",
  "IF_FALSE",
  "IF_TRUE",
  "GOTO",

  "FUNC_CALL",
  "PUSH",
  "POP",
  "RET",

  "RDI",
  "RDF",
  "RDB",
  "PRINTI",
  "PRINTF",
  "PRINTB",

  "ITOF",
  "FTOI",

  "FUNC_BODY",
  "START"
    };

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
oprand gen_code_biop(flat_symtab var_table, func_table function_table, ast_node root)
{
  oprand op1, op2, op_temp1, op_ret;
  int source_addr;
  
  op1 = gen_code(var_table, function_table, root->left_child);
  op2 = gen_code(var_table, function_table, root->left_child->right_sibling);
  source_addr = get_temp_addr(next_temp());

  // deal with coersion by check types. four combinations in total
  if (op1->dtype == TYPE_INT){
    if (op2->dtype == TYPE_INT){
      op_ret = create_oprand(OP_TYPE_ID, TYPE_INT, (double) source_addr);
      insert_quad(create_quad(ADD, op_ret, op1, op2));
    }else{	// promote op1 to double, need a new temp
      // create new temp 
      op_temp1 = create_oprand(OP_TYPE_ID, TYPE_DOUBLE, (double) get_temp_addr(next_temp()));
	
      // promote the temp: get double value from op1 and save it into temp
      insert_quad(create_quad(ITOF, op_temp1, op1, NULL));
	
      // ready to add: op2 + op_temp1 => op_ret
      op_ret = create_oprand(OP_TYPE_ID, TYPE_DOUBLE, (double)source_addr);
      insert_quad(create_quad(ADDF, op_ret, op_temp1, op2));
	
    }
  }else{
    if (op2->dtype == TYPE_INT){// promote op2 to double, similar as above
      op_temp1 = create_oprand(OP_TYPE_ID, TYPE_DOUBLE, (double) get_temp_addr(next_temp()));
      insert_quad(create_quad(ITOF, op_temp1, op2, NULL));
      op_ret = create_oprand(OP_TYPE_ID, TYPE_DOUBLE,  (double)source_addr);
      insert_quad(create_quad(ADDF, op_ret, op1, op_temp1));
    }else{	// both double, no promotion needed
      op_ret = create_oprand(OP_TYPE_ID, TYPE_DOUBLE, (double)source_addr);
      insert_quad(create_quad(ADDF, op_ret, op1, op2));
    }
  }	
	
  return op_ret;    
}
/* Generate quad arrays for the syntax tree */
oprand gen_code(flat_symtab var_table, func_table function_table, ast_node root)
{
  ast_node child;
  quad qd;
  data_type dtype;
  ast_node expr_node, id_node, arg_node;
  int source_addr;
  int int_value;
  double double_value;
  symtab_entry entry;
  oprand op1, op2, op3, op_ret, op_temp1, op_temp2;
  oprand_type opcode;
  func_entry fEntry;
  int temp_var;
  int i;
  int flag_param;

  switch(root->node_type){
  case ROOT:	// first init all globals, then "call" main, then generate codes for func_decl
    for(child = root->left_child; child != NULL; child = child->right_sibling)
      if (child->node_type == VAR_DECL)
	gen_code(var_table, function_table, child);

    // call main
    insert_quad(create_quad(START, NULL, NULL, NULL));

    for(child = root->left_child; child != NULL; child = child->right_sibling)
      if (child->node_type == FUNC_DECL)
	gen_code(var_table, function_table, child);

    return NULL;	// no need to return something

  case VAR_DECL:	// do nothing except when decl & init    
    expr_node = root->left_child->right_sibling->right_sibling->right_sibling;
    id_node = root->left_child->right_sibling->right_sibling;
    if (expr_node != NULL){	// assign init value to var
      // retrieve info
      entry = var_table->entries[id_node->sn];
      source_addr = entry->addr;
      int_value = expr_node->expr.int_value;
      double_value = expr_node->expr.double_value;

      // build and insert quad
      op1 = create_oprand(OP_TYPE_ID, entry->dtype, (double)source_addr);
      if (entry->dtype == TYPE_INT){
	opcode = ASSIGNI;
	op2 = create_oprand(OP_TYPE_INT, TYPE_INT, (double)int_value);
      }else if (entry->dtype == TYPE_DOUBLE){
	opcode = ASSIGNF;
	op2 = create_oprand(OP_TYPE_DOUBLE, TYPE_DOUBLE, (double)double_value);
      }else{
	printf("--- error --- line 96 at quad.c\n"); op2 = NULL;
      }
      insert_quad(create_quad(opcode, op1, op2, NULL));
    }	
    break;
	
  case FUNC_DECL:	// remember function entry address by creating a FUNC_BODY quad
    cur_fun = root->left_child->left_child->right_sibling->sn;
    // retrieve info
    id_node = root->left_child->left_child->right_sibling;
    source_addr = next_quad;

    // build and insert quad
    opcode = FUNC_BODY;
    op1 = create_oprand(OP_TYPE_ID, TYPE_INT, (double)source_addr);	// line number of this quad    
    op2 = create_oprand(OP_TYPE_INT, TYPE_INT, (double)id_node->sn);	// the function's sn
    insert_quad(create_quad(opcode, op1, op2, NULL));

    // generate code for children
    for(child = root->left_child; child != NULL; child = child->right_sibling)
      gen_code(var_table, function_table, child);
    break;
      
  case FUNC_HEADER:
  case FUNC_PARAMS:	// need to do nothing
    break;

  case CMPD_STMT:
  case LOCAL_DECL:
  case STMT_LIST:    // recursively generate code 
    for(child = root->left_child; child != NULL; child = child->right_sibling)
      gen_code(var_table, function_table, child);
    break;

  case OP_PLUS:	// first generate code for children, then return the result oprand
    return gen_code_biop(var_table, function_table, root);

  case OP_ASSIGN:	// may need to do coersion
    // retireve info
    source_addr = var_table->entries[id_node->sn]->addr;
    
    // do coersion if necessary
    op1 = gen_code(var_table, function_table, root->left_child);
    op2 = gen_code(var_table, function_table, root->left_child->right_sibling);
    if ((op1->dtype >= TYPE_DOUBLE) && (op2->dtype <= TYPE_INT_ARRAY)){	// promote op2
      op_temp1 = create_oprand(OP_TYPE_ID, TYPE_DOUBLE, (double) get_temp_addr(next_temp()));
      insert_quad(create_quad(ITOF, op_temp1, op2, NULL));
    }else if ((op1->dtype <= TYPE_INT_ARRAY) && (op2->dtype >= TYPE_DOUBLE)){	// narrow op2
      op_temp1 = create_oprand(OP_TYPE_ID, TYPE_INT, (double) get_temp_addr(next_temp()));
      insert_quad(create_quad(FTOI, op_temp1, op2, NULL));
    }else{	// same type, yeah~
      op_temp1 = op2;	// for convenience
    }
    
    // now ready to do the assignment!
    insert_quad(create_quad(ASSIGNV, op1, op_temp1, NULL));
    
    return op_temp1;

  case RETURN_STMT:		// with or without ret value
    if (root->left_child == NULL){	// no return value
      insert_quad(create_quad(RET, NULL, NULL, NULL));
      op_temp1 = NULL;
    }else{	// return value, need a temp for potential expression
      op_temp1 = gen_code(var_table, function_table, root->left_child);
      insert_quad(create_quad(RET, op_temp1, NULL, NULL));
    }
   
    return op_temp1;

    
  case INT_LITERAL:
    return create_oprand(OP_TYPE_INT, TYPE_INT, (double)root->value.int_value);

  case DOUBLE_LITERAL:
    return create_oprand(OP_TYPE_DOUBLE, TYPE_DOUBLE, root->value.double_value);

  case IDENTIFIER:	// array or var?
    // retrieve info
    entry = var_table->entries[root->sn];
    dtype = entry->dtype;
    source_addr = var_table->entries[root->sn]->addr;

    if (root->left_child != NULL){	// an array. type check guarentees that it's not non-integer indexed
      // if the name comes from a function param, then its value contains the actual address
      // in this case we have to dereference the value

      // check if this id is a param
      flag_param = 0;
      if(cur_fun >=0){
	fEntry = function_table->entries[cur_fun];
	for (i = 0; i < fEntry->argc; i++){
	  if (strcmp(root->value.string, fEntry->args[i])==0){
	    flag_param = 1;
	    break;
	  }
	}
      }
  	
      // generate code for expression
      op1 = gen_code(var_table, function_table, root->left_child);
	
      // calculate address offset, and add it to source_addr   
      // create a temp to store the final address
      op_temp1 = create_oprand(OP_TYPE_ID, dtype, get_temp_addr(next_temp()));      
      // compute offset to op_temp1
      op2 = create_oprand(OP_TYPE_INT, TYPE_INT, (double)8);
      insert_quad(create_quad(MUL, op_temp1, op1, op2));
      // now op_temp1 has the right offset, add it with source_addr
      if (flag_param == 0)
	op2 = create_oprand(OP_TYPE_INT, TYPE_INT, (double)source_addr); // directly store source_addr to op2
      else
	op2 = create_oprand(OP_TYPE_ID, dtype, (double)source_addr); // dereference source_addr to op2

      // now compute the final address to op_temp1
      insert_quad(create_quad(ADD, op_temp1, op2, op_temp1));
      
      // return op_temp1
      op_ret = op_temp1;
  
    }else{	// not an array - simple
      op_ret = create_oprand(OP_TYPE_ID, dtype, (double)source_addr);
    }

    // return oprand
    return op_ret;

  case CALL:
    // a FUNC_CALL quad has two oprands, the first being the sn of the function (for now),
    // and the second being the oprand that is to take the return value opon returning, 
    // if the function will return a value
    //
    // there is no instruction as push/pop in TM57. (nor is ret). the opcode here will be 
    // fully expanded in assembly-generation stage. (especially for SP ajusting, which needs not 
    // to be worried within a function body.)
    //
    // first push params, then make the call, receiving ret value if available and pop params

    // push params
    arg_node = root->left_child->right_sibling;
    id_node = root->left_child;
    if (arg_node == NULL){	// the function takes no arguments, do nothing
    }else{	// push arguments from left to right, just as the order they are stored in the ast
      for(child = arg_node->left_child; child != NULL; child = child->right_sibling){
	// use a temp to hold the value of the argument(expression)
	op_temp1 = gen_code(var_table, function_table, child);
	// do coercion/widening if necessary
	// mark: TODO
	// push this argument, yeah~
	insert_quad(create_quad(PUSH, op_temp1, NULL, NULL));
      }
    }
    // make the call. save ret value in a temp if necessary
  

    fEntry = lookup_function(function_table, id_node->value.string);
    op1 = create_oprand(OP_TYPE_INT, TYPE_INT, (double)fEntry->sn);
    dtype = fEntry->dtype;
    op_temp1 = NULL;
    if (dtype == TYPE_VOID){	// no ret value, just make the call
      insert_quad(create_quad(FUNC_CALL, op1, NULL, NULL));
    }else{	// need a temp to save ret value
      op_temp1 = create_oprand(OP_TYPE_ID, dtype, get_temp_addr(next_temp()));
      insert_quad(create_quad(FUNC_CALL, op1, op_temp1, NULL));
    }

    // pop arguments
    // each POP pops one argument, so we need argc POP quads
    for (i = 0; i < fEntry->argc; i++)
      insert_quad(create_quad(POP, NULL, NULL, NULL));
    
    return op_temp1;
  default:
    printf("--- Not reached yet. Be patient:) ---\n");
    break;
  }
}






















/* Create oprand, need to cast value type */
oprand create_oprand(oprand_type type, data_type dtype,  double value)
{
  oprand new_op = (oprand)malloc(sizeof(struct oprand));
  new_op->value.double_value = value;
  new_op->value.id_addr = new_op->value.int_value = (int)value;
  new_op->op_type = type;
  new_op->dtype = dtype;
  
  return new_op;
}

/* Create a quad */
quad create_quad(quad_op op, oprand op1, oprand op2, oprand op3)
{
  quad new_qd = (quad)malloc(sizeof(struct quad));
  new_qd->op = op;
  new_qd->op1 = op1;
  new_qd->op2 = op2;
  new_qd->op3 = op3;
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

void print_oprand(oprand opx)
{
  if (opx == NULL){
    printf("N/A");
    return;
  }
  
  switch(opx->op_type){
  case OP_TYPE_INT:
    printf("int: %d", opx->value.int_value);
    break;
  case OP_TYPE_DOUBLE:
    printf("double: %f", opx->value.double_value);
    break;
  case OP_TYPE_ID:
    printf("addr: %d", opx->value.id_addr);
    break;
  default:
    printf("OP_TYPE_NA");
    break;
  }
}	   


void print_quad(quad qd)
{
  printf("( %s,\t", op_str[qd->op]);
  print_oprand(qd->op1);
  printf(",\t");
  print_oprand(qd->op2);
  printf(",\t");
  print_oprand(qd->op3);
  printf(" )\n");
}

void print_code()
{
  int i;
  printf( "--------------------- intermediate code ----------------------\n");
  for (i = 0; i < next_quad; i++)
    print_quad(g_array[i]);
}
