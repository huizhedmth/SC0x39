/* main.c
 *
 * The main function takes its second argument
 * as the filename of input file. 
 * Other cmd arguments are ignored.
 * The program exits if the specified file cannot be opened.
 * main() calls yylex() repeatedly and print tokens
 * until EOF is found
 *
 * author: Huizhe Li, Master Student, Dartmouth College
 */



#include <stdio.h>
#include "token.h"
extern void yyset_in(FILE*);
extern char* yytext;


int main(int argc, char** argv){
	FILE* fp = fopen(argv[1], "r");
	if (fp == NULL){
		printf("ERROR: file not found. exit.\n");
		return -1;
	}

	yyset_in(fp);

	while(yylex()!=0)
		printf("%s\n", yytext);
		
	fclose(fp);

	return 0;
}
