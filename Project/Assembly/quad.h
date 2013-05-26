/* quad.h
 *
 * Quad structure and func prototype definition.
 *
 * Details on how intermediate quads will be used to directly generate assembly 
 * (without refering to any other information) can be found at the beginning of 
 * assembly.h
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
#define GLOBAL_BASE_ADDR TEMP_BASE_ADDR - MAXTEMP*4000	/* where global vars are saved */

#define MAXFUNCNUM 100

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

  // actually no need to separate, was being stupid
  ASSNA,	// similar as LDA, direct
  ASSN,	// similar as LD, indirect (dereference)

  IF_FALSE,	// this group also needs expansion when assembling
  IF_TRUE,	// not primitive instruction!
  GOTO,

  FUNC_CALL,
  PUSH,		// push, pop, and ret are not defined in TM57
  PUSHA,	// add the value with current fp
  PUSHFP,
  POP,		// so need to expand them when assembling
  RET,

  RDIA,		// similar as ASSNA
  RDI,
  RDFA,
  RDF,
  RDBA,	       	// seems unneccessary...
  RDB,
  PRINTI,
  PRINTF,
  PRINTB,

  ITOF,
  FTOI,

  FUNC_BODY,
  START,	// main
} quad_op;

/* Define quad operand type.
 * Assembly generator uses this to determine instruction type
 */
typedef enum  {
  OP_TYPE_INT,
  OP_TYPE_DOUBLE,
  OP_TYPE_STR,
  OP_TYPE_ID
} operand_type;

/* Define operand structure */
typedef struct operand *operand;
struct operand {
  union {
    int int_value;
    double double_value;
    char* string_value;
    int id_addr;
  } value;
  operand_type op_type;
  data_type dtype;
};

/* Define quad structure */
typedef struct quad *quad;
struct quad {
  quad_op op;
  operand op1;
  operand op2;
  operand op3;

  /* only used to backpatch break statements */
  int index;
};

/* Used to patch CALL's after a whole pass of the tree */
struct func_entrance{
  char* name;	// name of function
  int index;	// index of quad, its entrance address
};

typedef struct func_entrance *func_entrance;

struct entrance_table{
  int size;
  func_entrance entrances[MAXFUNCNUM];
};
typedef struct entrance_table entrance_table;

/* (quad_index, case_constant) pairs. See "case SWITCH_STMT" in quad.c for details */
struct idx_case_pair{
  int quad_index;
  int case_const;
};
typedef struct idx_case_pair *idx_case_pair;

struct idx_case_table{
  int size;
  idx_case_pair pairs[100];	// hardcode it for now
};
typedef struct idx_case_table idx_case_table;
/************************** function declaration ******************************/

/* Create an func_entrance */
func_entrance create_entrance(char* name, int index);
/* Create operand, need to cast value type */
operand create_operand(operand_type type, data_type dtype, double value);

/* Create a quad */
quad create_quad(quad_op op, operand op1, operand op2, operand op3);

/* Backpatch a quad */
void patch_quad(int q, int i, int next);

/* Generate intermediate code recursively 
 * The returned operand may be necessary to determine
 * expression values.
 */
operand gen_code(flat_symtab var_table, func_table function_table, ast_node node);

/* Insert a quad to global quad array */
void insert_quad(quad qd);

/* Get next available temp */
int next_temp();

/* Get mem address of a given temp */
int get_temp_addr(int no_temp);	


/* Printers */
void print_code();
void print_quad(quad qd);

/* Fill func entrance address for CALL quads */
void fill_call();

/* Create a idx_case_pair and insert it*/
idx_case_pair create_pair(int index, int case_const);

/* Lookup the pair table and patch */
void patch_a_case(int case_const, int next_quad);
#endif // QUAD_H
