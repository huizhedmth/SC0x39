/* main.c
 *
 * arranged for input file being parsed by the 
 * parser generated from bison specs
 *
 * author: Huizhe Li, Master Student, Dartmouth College
 *
 */

#include<stdio.h>

extern int yyparse();
extern void yyset_in(FILE*);

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


	int ret =  yyparse ();
	if (ret == 0)
		printf("succeeded parsing input. ret val = %d\n", ret);
	else
		printf("failed parsing input. ret val = %d\n", ret);
	return ret;
}
