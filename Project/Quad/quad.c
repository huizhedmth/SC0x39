/* quad.c
 *
 * Implementation of quad-related functions
 *
 * by Huizhe Li, Master Student, Dartmouth College
 */

#include "quad.h"
#include "ast.h"
#include "symtab.h"
#include <stdlib.h>
#include <stdio.h>

/* The global quad array */
quad g_array[MAXQUADSIZE];

/* Next quad index, also the size of quad array */
static int next_quad = 0;

char* op_str[] = {
  "ADDI",
  "ADDD",
  "SUB",
  "SUBD",
  "MUL",
  "MULD",
  "DIV",
  "DIVD",
  "MOD",
  "LT",
  "LEQ",
  "GT",
  "GEQ",
  "EQ",
  "NEQ",
  "NOT",
  "PREINC",
  "INCPOST",
  "PREDEC",
  "DECPOST",
  "ASSIGN",	// args = (id, index, value), may need expansion  

  "IF_FALSE",
  "IF_TRUE",
  "GOTO",

  "FUNC_CALL",
  "RET",

  "RD",
  "PRINT",

  "ITOD",
  "DTOI",

  "FUNC_BODY",
  "START"
    };



/* Generate quad arrays for the syntax tree */
void gen_quad(flat_symtab var_table, func_table function_table, ast_node root)
{
  return;
}

/* Create oprand, need to cast value type */
oprand create_oprand(oprand_type type, double value)
{
  oprand new_op = (oprand)malloc(sizeof(struct oprand));
  new_op->value.double_value = value;
  new_op->value.id_addr = new_op->value.int_value = (int)value;
  new_op->type = type;
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


void print_oprand(oprand opx)
{
  if (opx == NULL){
    printf("N/A");
    return;
  }
  
  switch(opx->type){
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
  printf("( %s, ", op_str[qd->op]);
  print_oprand(qd->op1);
  printf(",");
  print_oprand(qd->op2);
  printf(",");
  print_oprand(qd->op3);
  printf(" )\n");
}

void print_code()
{
  int i;
  for (i = 0; i < next_quad; i++)
    print_quad(g_array[i]);
}
