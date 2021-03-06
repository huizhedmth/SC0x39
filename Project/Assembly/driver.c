/* main.c
 *
 * Test drive for C57 compilation
 *
 * by Huizhe Li, Master Student, Dartmouth College
 */

#include <stdio.h>
#include "ast.h"
#include <string.h>
#include <stdlib.h>
#include "symtab.h"
#include "quad.h"
#include "assembly.h"

FILE* out;
extern ast_node root;
extern void yyset(FILE*);
extern char* yytext;
extern int lineNumber;	/* in lex.yy.c */
extern void print_ast(ast_node root, int depth);
extern int sym_error;
extern int qd_error;
extern char* g_type;
extern quad g_array[MAXQUADSIZE];
char* filename = "output.tm57";

int symDEBUG = 0;	/* debug flag */
int tcDEBUG = 0;
int qdDebug = 0;
int TRACE = 0;
int asm_debug = 1;

/* Use command line options -t, -v and -f if you would like to see
 * the syntax tree, var-symtab or func-symtab, respectively.
 */

int main(int argc, char** argv)
{

  int print_t = 0;
  int print_v = 0;
  int print_f = 0;
  int print_q = 0;
  int print_trace = 0;
  int i;
  int rc;

  g_type = (char*) malloc(10);	// stupid, but just let it be like this...
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

	out = fopen(filename, "w");
  for(i = 2; i < argc; i++){
    if(strcmp(argv[i], "-t") == 0){
      print_t = 1;
    }else if (strcmp(argv[i], "-v") == 0){
      print_v = 1;
    }else if (strcmp(argv[i], "-f") == 0){
      print_f = 1;
    }else if (strcmp(argv[i], "-q") == 0){
      print_q = 1;
    }else if (strcmp(argv[i], "-trace") == 0){
      print_trace = 1;
    }else if (strcmp(argv[i], "-o") == 0){
      if (argv[i+1] == NULL){
	printf("argument missing, using default file name\n");
      }else{
      	filename = argv[++i];
	out = fopen(filename, "w");
      }
    } else{ 
      printf("acceptable options are -t, -v and -f\n");
    }
  }

  // set input source
  yyset_in(in);

  // parse input
  rc = yyparse();

  if(rc != 0){
    printf("--- error --- failed parsing input: error at line %d, abort.\n", lineNumber);
    return -1;
  }else{
    if (print_trace)
      printf(" --- c57c  --- parsing succeeded.\n");
  }	
  
  // build symbol table
  build_symtab(tracking_table, var_table, function_table, root);
  if (sym_error != 0){
    printf("--- error --- errors found building symboltable, abort. \n");
    return -1;
  }else{
    if (print_trace)    printf(" --- c57c --- symtab built.\n");
  }

  // type check
  rc = type_check(var_table, function_table, root);
  if (rc != 0){
    printf("--- error --- errors found in type checking, abort.\n");
    return -1;
  }else{
    if (print_trace)    printf(" --- c57c --- typecheck passed.\n");
  }

  // compute address for global and local vars
  comp_addr(var_table, function_table, root);
  if (print_trace)  printf(" --- c57c --- address computed. generating code...\n");
  gen_code(var_table, function_table, root);
  fill_call();
  if (qd_error == 1){
    printf("--- error --- errors found in quads generation, abort.\n");
    return -1;
  }
  if (print_trace)  printf(" --- c57c --- intermediate code generated.\n");

  // generate target code
  gen_assembly();
  
  if (print_trace) printf(" --- c57c --- assembly generated\n");

  // print data structures
  if(print_t == 1)
    print_ast(root, 0);	
  if(print_v == 1)
    print_flat_table(var_table);
  if(print_f == 1)
    print_func_table(function_table);
  if(print_q == 1)   
    print_code();
 
  print_instructions();
 fclose(out);
  return 0;
} 
