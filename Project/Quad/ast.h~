/* 
 * ast.h
 *
 * File defining an enum and a struct for node types in an abstract
 * syntax tree.
 *
 * Written by THC for CS 57.  You should modify this file as
 * appropriate.
 *
 */

#ifndef AST_H_
#define AST_H_

/* You should fill in the various node types.  The following are given
   to you to start with.  You may add or remove node types as you
   wish. */
typedef enum { ROOT,
	       SEQ,
	       OP_ASSIGN, OP_PLUS, OP_MINUS, OP_NEG, OP_TIMES, OP_DIVIDE,
	       OP_EQUALS, OP_MOD, OP_LESS, OP_LESSEQ, OP_GRTER, OP_GRTEREQ,
	       OP_NEQ, OP_AND, OP_OR, OP_NOT, 
	       OP_INC_PRE, OP_DEC_PRE, OP_INC_POST, OP_DEC_POST,
	       IF_STMT, IF_ELSE_STMT,
	       WHILE_STMT, DO_WHILE_STMT, FOR_STMT, RETURN_STMT,
	       READ_STMT, PRINT_STMT, BREAK_STMT, CONTINUE_STMT,
	       CASE_STMT, DEFAULT_STMT, SWITCH_STMT,
	       IDENTIFIER, 
	       INT_LITERAL, DOUBLE_LITERAL, STR_LITERAL,
               TYPE, STORAGE,
	       VAR_DECL, FUNC_DECL, FUNC_PROTO,
	       FUNC_HEADER, FUNC_PARAMS,
	       LOCAL_DECL,
	       STMT_LIST,
	       CMPD_STMT,
	       PARAM,
	       CALL, ARGS,
	       SIZE_OF,
	       EMPTY
               } ast_node_type;

/* Expression data type */
typedef enum{
  EXPR_INT,
  EXPR_DOUBLE,
  EXPR_VOID,
} expr_type;

/* Structure for nodes of the abstract syntax tree.  Uses the
   left-child/right-sibling representation, so that each node can have
   a variable number of children.  You should add or remove fields as
   appropriate. */
typedef struct ast_node_struct *ast_node;
struct ast_node_struct {
  ast_node_type node_type;
  ast_node left_child, right_sibling;
  union {
    char * string;		/* for ID */
    int int_value;		/* for INT_LITERAL */
    double double_value;	/* for DOUBLE_LITERAL */
  } value;

  /* added by Huizhe Li */
  /* note: the following two fields do NOT apply to all node types */
  int scope;	/* filled by parser to indicate in which scope this node appears */
  int lineNumber;	/* filled by parser to indicate at which line this node appears */
  int sn;		/* "serial number" that uniquely identifies the id throughout the program */
  int flag_visited;	/* whether it's been visited in case VAR_DECL in function build_symtab */

  union{
    expr_type dtype;
    int int_value;
    double double_value;
  } expr;

  int static_expr;	/* indicate whether its value can be computed at compile time */
    
};

/* Create a node with a given token type and return a pointer to the
   node. */
ast_node create_ast_node(ast_node_type node_type);

/* Print the contents of a subtree of an abstract syntax tree, given
   the root of the subtree and the depth of the subtree root. */
void print_ast(ast_node root, int depth);

#endif
