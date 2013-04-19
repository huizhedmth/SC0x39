/* main.c
 *
 * Arranged for input file to be parsed by the 
 * parser generated from bison specs
 *
 * By Huizhe Li, Master Student, Dartmouth College
 *
 */

#include <stdio.h>
#include "ast.h"
#include "idt.h"

extern int yyparse();
extern void yyset_in(FILE*);
extern ID_table *the_id_table;
extern void init_table(ID_table **table);

extern int lineNumber;

ast_node root = NULL;


int main (int argc, char** argv)
{
	if (argc > 1){
		FILE* in = fopen(argv[1], "r");
		if (in == NULL){
			printf("ERROR: file not found. exit.\n");
			return -1;
		}
		/* set input file source for lexer */
		yyset_in(in);
	}

	init_table(&the_id_table);

	int ret =  yyparse ();
	if (ret == 0){
		printf("succeeded parsing input.\n");
		print_ast(root, 0);
	}else
		printf("failed parsing input. error at line %d\n", lineNumber);
	return ret;
}
