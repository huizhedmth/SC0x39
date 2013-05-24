/* quad.h
 *
 * Quad structure and func prototype definition.
 *
 * by Huizhe Li, Master Student, Dartmouth College
 */

#ifndef QUAD_H
#define QUAD_H

#include "ast.h"
#include "symtab.h"

#define MAXQUADSIZE 2048


/* operation types for quad */
typedef enum {
  ADDI,
  ADDD,
  SUB,
  SUBD,
  MUL,
  MULD,
  DIV,
  DIVD,
  MOD,
  LT,
  LEQ,
  GT,
  GEQ,
  EQ,
  NEQ,
  NOT,
  PREINC,
  INCPOST,
  PREDEC,
  DECPOST,
  ASSIGN,	// args = (id, index, value), may need expansion  

  IF_FALSE,
  IF_TRUE,
  GOTO,

  FUNC_CALL,
  RET,

  RD,
  PRINT,

  ITOD,
  DTOI,

  FUNC_BODY,
  START,	// main
} quad_op;

/* Define quad oprand type */
typedef enum  {
  OP_TYPE_NA,
  OP_TYPE_INT,
  OP_TYPE_DOUBLE,
  OP_TYPE_STR,
  OP_TYPE_ID
} oprand_type;

/* Define oprand structure */
typedef struct oprand *oprand;
struct oprand {
  union {
    int int_value;
    double double_value;
    int id_addr;
  } value;
  oprand_type type;
};

/* Define quad structure */
typedef struct quad *quad;
struct quad {
  quad_op op;
  oprand op1;
  oprand op2;
  oprand op3;
};

/* Create oprand, need to cast value type */
oprand create_oprand(oprand_type type, double value);

/* Create a quad */
quad create_quad(quad_op op, oprand op1, oprand op2, oprand op3);

/* Backpatch a quad */
void patch_quad(quad q, int index, oprand opx);

/* Generate intermediate code recursively */
void gen_quad(flat_symtab var_table, func_table function_table, ast_node node);

/* Insert a quad to global quad array */
void insert_quad(quad qd);

/* Printers */
void print_code();
void print_quad(quad qd);
#endif // QUAD_H
