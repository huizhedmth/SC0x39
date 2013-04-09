/* main.c
 *
 * The main function takes its second argument
 * as the filename of input file. 
 * Other cmd arguments are ignored.
 * The program exits if the specified file cannot be opened.
 * main() calls yylex() repeatedly and writes tokens to file
 * until EOF is found
 *
 * author: Huizhe Li, Master Student, Dartmouth College
 */



#include <stdio.h>
#include <string.h>
#include "token.h"

extern void yyset_in(FILE*);
extern char* yytext;

char* typeLookup(int);

int main(int argc, char** argv){

	/* open files */
	FILE* in = fopen(argv[1], "r");
	if (in == NULL){
		printf("ERROR: file not found. exit.\n");
		return -1;
	}
	char* outfile = strcat(argv[1], ".out"); 
	FILE* out = fopen(outfile, "w");
	if (out == NULL){
		printf("ERROR: failed opening file. exit.\n");
		return -2;
	}

	/* set input file source for lexer */
	yyset_in(in);

	/* print types and tokens */
	int ret;
	char* type;
	while( (ret=yylex()) != 0)
		fprintf(out, "%-20s%-20s\n", typeLookup(ret), yytext);
		
	fclose(in);
	fclose(out);
	return 0;
}

char* typeLookup(int token) {
  typedef struct typeItem {
    int token;
    char *type;
  } typeItem;

  const int TYPECOUNT = 53;

  static typeItem types[] = {
 	{258, "ELSE"},
	{259, "IF"},
	{260, "INT"},
	{261, "RETURN"},
	{262, "VOID"},
	{263, "WHILE"},
	{264, "FOR"},
	{265, "DO"},
	{266, "DOUBLE"},
	{267, "BREAK"},
	{268, "CONTINUE"},
	{269, "SIZEOF"},
	{270, "CONST"},
	{271, "SWITCH"},
	{272, "STATIC"},
	{273, "STRUCT"},
	{274, "EXTERN"},
	{275, "DEFAULT"},
	{276, "CASE"},
 	{280, "PLUS"},
	{281, "MINUS"},
	{282, "STAR"},
	{283, "DIV"},
	{284, "LESS"},
	{285, "LESSEQ"},
	{286, "GRTER"},
	{287, "GRTEREQ"},
	{288, "EQ"},
	{289, "NEQ"},
	{290, "ASSIGN"},
	{291, "SEMICOLON"},
	{292, "COMMA"},
	{293, "LBRKT"},
	{294, "RBRKT"},
	{295, "LSQRBRKT"},
	{296, "RSQRBRKT"},
	{297, "LCLYBRKT"},
	{298, "RCLYBRKT"},
	{299, "INC"},
	{300, "DEC"},
	{301, "MOD"},
	{302, "AND"},
	{303, "OR"},
	{304, "NOT"},
	{305, "PLUSEQ"},
	{306, "MINUSEQ"},
	{307, "MULEQ"},
	{308, "DIVEQ"},
	{309, "PRECMP"},
	{310, "ADDR"},
	{311, "DOT"},
	{312, "COLON"},
	{330, "ID"},
	{331, "NUM"},
	{332, "FNUM"},
	{333, "STRING"},
	{334, "ILLEGALID"},
	{340, "OTHER"}
 };

  typeItem* tp;

  for (tp = types; tp->token != token; tp++)
    ;

  return tp->type;
}


