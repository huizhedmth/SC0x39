/* ast.c
 *
 * Written by THC for CS 57.  Relies on an enum and a struct for
 * various node types that appear in ast.h.  You should modify the
 * enum and struct as appropriate.
 *
 * This file contains functions to create a node and to print out an
 * abstract syntax tree, for debugging.
 *
 * Modified by Huizhe Li, Master Student, Dartmouth College
 */

#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

extern int symDEBUG;	/* declare it in test driver! */
extern int lineNumber;
extern int g_scope;

/* Define a table of token types and their associated strings.  You
   should modify this table as appropriate.  The order of entries
   should match the order of enumerated values in ast_node_type. */
struct token_lookup {
  char *token;
  ast_node_type node_type;
};
static struct token_lookup token_table[] = {
  { "ROOT", ROOT },
  { "SEQ", SEQ },
  { "=", OP_ASSIGN },
  { "+", OP_PLUS },
  { "-", OP_MINUS },
  { "-", OP_NEG },
  { "*", OP_TIMES },
  { "/", OP_DIVIDE },
  { "==", OP_EQUALS },
  { "%", OP_MOD },
  { "<", OP_LESS },
  { "<=", OP_LESSEQ },
  { ">", OP_GRTER },
  { ">=", OP_GRTEREQ },
  { "!=", OP_NEQ },
  { "&&", OP_AND },
  { "||", OP_OR},
  { "!", OP_NOT},
  { "++PRE", OP_INC_PRE},
  { "--PRE", OP_DEC_PRE},
  { "POST++", OP_INC_POST},
  { "POST--", OP_DEC_POST},
  { "IF", IF_STMT },
  { "IFELSE", IF_ELSE_STMT },
  { "WHILE" , WHILE_STMT },
  { "DO_WHILE", DO_WHILE_STMT},
  { "FOR", FOR_STMT},
  { "RETURN", RETURN_STMT},
  { "READ", READ_STMT},
  { "PRINT", PRINT_STMT},
  { "BREAK", BREAK_STMT},
  { "CONTINUE", CONTINUE_STMT},
  { "CASE", CASE_STMT},
  { "DEFAULT", DEFAULT_STMT},
  { "SWITCH", SWITCH_STMT},
  { "ID", IDENTIFIER },
  { "INTLIT", INT_LITERAL },
  { "DOUBLELIT", DOUBLE_LITERAL },
  { "STRINGLIT", STR_LITERAL },
  { "TYPE", TYPE},
  { "STORAGE", STORAGE},
  { "VAR DECL", VAR_DECL},
  { "FUNC DECL", FUNC_DECL},
  { "FUNC PROTO", FUNC_PROTO},
  { "FUNC HEADER", FUNC_HEADER},
  { "FUNC PARAMS", FUNC_PARAMS},
  { "LOCAL DECL", LOCAL_DECL},
  { "STATEMENT LIST", STMT_LIST},
  { "COMPOUND STATEMENT", CMPD_STMT},
  { "PARAMETER", PARAM},
  { "CALL", CALL},
  { "ARGUMENTS", ARGS},
  { "SIZEOF", SIZE_OF},
  { "EMPTY", EMPTY},
  { NULL, 0 }
};

/* Create a node with a given token type and return a pointer to the
   node. */
ast_node create_ast_node(ast_node_type node_type) {
  ast_node new_node = malloc(sizeof(struct ast_node_struct));
  new_node->node_type = node_type;
  new_node->left_child = new_node->right_sibling = NULL;
  // added by Huizhe Li
  new_node->flag_visited = 0;	
  new_node->lineNumber = lineNumber;
  new_node->scope = g_scope;
  new_node->static_expr = 0;
  return new_node;
}

/* Print the contents of a subtree of an abstract syntax tree, given
   the root of the subtree and the depth of the subtree root. */
void print_ast(ast_node root, int depth) {
  /* Print two spaces for every level of depth. */
  int i;
  for (i = 0; i < depth; i++)
    printf("  ");

  /* Print the node type. */
  printf("%s ", token_table[root->node_type].token);

  /* Print attributes specific to node types. */
  switch (root->node_type) {
  case IDENTIFIER:			/* print the id */
    if (symDEBUG){
      printf("line number: %d ", root->lineNumber);
      printf("scope: %d ", root->scope);
      printf("sn: %d ", root->sn);
    }
  case TYPE:
  case STORAGE:
  case STR_LITERAL:
    printf("%s", root->value.string);
    break;

  case VAR_DECL:
    if (symDEBUG)
      printf("scope: %d ", root->scope);
    break;
  case INT_LITERAL:		/* print the int literal */
  case CASE_STMT:
    printf("%d", root->value.int_value);
    break;

  case DOUBLE_LITERAL:		/* print the double literal */
    printf("%f", root->value.double_value);
    break;

  default:
    break;
  }

  printf("\n");

  /* Recurse on each child of the subtree root, with a depth one
     greater than the root's depth. */
  ast_node child;
  for (child = root->left_child; child != NULL; child = child->right_sibling)
    print_ast(child, depth + 1);
}  

