#include <stdio.h>
#include "ast.h"
#include <string.h>
#include <stdlib.h>
#include "symtab.h"

extern ast_node root;
extern void yyset(FILE*);
extern char* yytext;
extern int lineNumber;	/* in lex.yy.c */
extern void print_ast(ast_node root, int depth);
extern int sym_error;
extern char* g_type;

int hzDEBUG = 1;	/* debug flag */

/* Use command line options -t, -v and -f if you would like to see
 * the syntax tree, var-symtab or func-symtab, respectively.
 */

int main(int argc, char** argv)
{

  int print_t = 0;
  int print_v = 0;
  int print_f = 0;
  int i;
  int rc;

  g_type = (char*) malloc(10);
  symboltable tracking_table = create_symboltable();
  flat_symtab var_table = create_flat_symtab();
  func_table function_table = create_functable();

  
  if (argc < 2){
    printf("usage: scan filename\n");
    return -1;
  }

  FILE* in = fopen(argv[1], "r");
  if (in == NULL){
    printf("file not found\n");
    return -1;
  }

  for(i = 2; i < argc; i++){
    if(strcmp(argv[i], "-t") == 0){
      print_t = 1;
    }else if (strcmp(argv[i], "-v") == 0){
      print_v = 1;
    }else if (strcmp(argv[i], "-f") == 0){
      print_f = 1;
    }else {
      printf("acceptable options are -t, -v and -f\n");
    }
  }

  // set input source
  yyset_in(in);

  // parse input
  rc = yyparse();

  if (rc == 0){
    printf("succeeded parsing input.\n");
  }
  else{
    printf("--- error --- failed parsing input: error at line %d, abort.\n", lineNumber);
    return -1;
  }
  
  // build symbol table
  build_symtab(tracking_table, var_table, function_table, root);
  if (sym_error != 0){
    printf("--- error --- errors found building symboltable, abort. \n");
    //    return -1;
  }

  // type check
  rc = type_check(var_table, function_table, root);
  if (rc != 0){
    printf("--- error --- errors found in type checking, abort.\n");
    return -1;
  }

  // print data structures
   if(print_t == 1)
     print_ast(root, 0);	
   if(print_v == 1)
     print_flat_table(var_table);
   if(print_f == 1)
     print_func_table(function_table);
 
  return 0;
} 
