/* main.c
 *
 * arranged for yyparse being called
 *
 * author: Huizhe Li, Master Student, Dartmouth College
 *
 */

#include<stdio.h>

extern int yyparse();
extern void yyset_in(FILE*);
extern void set_debug();

int main (int argc, char** argv)
{
	set_debug();
	FILE* in = fopen(argv[1], "r");
	if (in == NULL){
		printf("ERROR: file not found. exit.\n");
		return -1;
	}

	/* set input file source for lexer */
	yyset_in(in);

	return yyparse ();
}
