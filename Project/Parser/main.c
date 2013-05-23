#include <stdio.h>
#include "ast.h"
#include <string.h>
#include <stdlib.h>

extern ast_node root;
extern void yyset(FILE*);
extern char* yytext;
extern int lineNumber;	/* in lex.yy.c */
extern void print_ast(ast_node root, int depth);
extern char* g_type;

int main(int argc, char** argv)
{
  if (argc < 2){
    printf("usage: scan filename\n");
    return -1;
  }

  FILE* in = fopen(argv[1], "r");
  if (in == NULL){
    printf("file not found\n");
    return -1;
  }

  g_type = (char*)malloc(10);
  yyset_in(in);
  int ret = yyparse();
  if (ret == 0){
    printf("succeeded parsing input.\n");
    if (strcmp(argv[2], "1")==0)
      print_ast(root, 0);
  }
  else
    printf("failed parsing input: error at line %d\n", lineNumber);
  return 0;
} 
