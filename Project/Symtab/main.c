/* main.c
 *
 * parse input file and build a symbol table 
 * from generated parse-tree
 *
 * By Huizhe Li, Master Student, Dartmouth College
 *
 */

#include <stdio.h>
#include "ast.h"
#include "idt.h"
#include "symtab.h"

extern int yyparse();
extern void yyset_in(FILE*);
extern ID_table *the_id_table;

extern int lineNumber;

ast_node root = NULL;
symboltable the_symtab = NULL;

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
		/* create an empty symbol table */
		the_symtab = create_symboltable();
		/* set root scope */
		root->scope = 0;
		/* traverse the parse-tree and build the table along the way */
		build_symtab(the_symtab, root, 0);
	}else
		printf("failed parsing input. error at line %d\n", lineNumber);
	return ret;
}
