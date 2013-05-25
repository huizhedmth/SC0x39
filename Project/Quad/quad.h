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

#define MAXQUADSIZE 2048	/* maximum number of quads */
#define MAXTEMP 100		/* maximum number of temp vars */
#define TEMP_BASE_ADDR 4000	/* where temp vars are saved */


/* operation types for quad */
typedef enum {
  ADD,
  ADDF,
  SUB,
  SUBF,
  MUL,
  MULF,
  DIV,
  DIVF,
  MOD,

  JLT,
  JLE,
  JGT,
  JGE,
  JEQ,
  JNE,
  JFLT,
  JFLE,
  JFGT,
  JFGE,
  JFEQ,
  JFNE,

  NOT,
  PREINC,
  INCPOST,
  PREDEC,
  DECPOST,

  ASSIGNI,	// int literal
  ASSIGNF,	// float literal
  ASSIGNV,	// var

  IF_FALSE,
  IF_TRUE,
  GOTO,

  FUNC_CALL,
  PUSH,
  POP,
  RET,

  RDI,
  RDF,
  RDB,
  PRINTI,
  PRINTF,
  PRINTB,

  ITOF,
  FTOI,

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
  oprand_type op_type;
  data_type dtype;
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
oprand create_oprand(oprand_type type, data_type dtype, double value);

/* Create a quad */
quad create_quad(quad_op op, oprand op1, oprand op2, oprand op3);

/* Backpatch a quad */
void patch_quad(quad q, int index, oprand opx);

/* Generate intermediate code recursively 
 * The returned oprand may be necessary to determine
 * expression values.
 */
oprand gen_code(flat_symtab var_table, func_table function_table, ast_node node);

/* Insert a quad to global quad array */
void insert_quad(quad qd);

/* Get next available temp */
int next_temp();

/* Get mem address of a given temp */
int get_temp_addr(int no_temp);	


/* Printers */
void print_code();
void print_quad(quad qd);
#endif // QUAD_H
