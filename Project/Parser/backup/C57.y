/* C57.y
 * 
 * Bison grammar rule definition file.
 * Used as the bison input file to
 * generate a parser for the C57 language.
 * 
 * author: Huizhe Li, Master Student, Dartmouth College
 *
 */

%{
	#define YYSTYPE int
	#define YYDEBUG 1
	#include <stdio.h>
	int yylex (void);
	void yyerror (char const *);
%}

%token	ELSE		
%token	IF		
%token	INT		
%token	RETURN		
%token	VOID		
%token	WHILE		
%token	FOR		
%token	DO		
%token	DOUBLE		
%token	BREAK		
%token	CONTINUE	
%token	SIZEOF		
%token	CONST		
%token	SWITCH		
%token	STATIC		
%token	STRUCT		
%token	EXTERN		
%token 	DEFAULT		
%token 	CASE		

%token	PLUS		
%token	MINUS		
%token	STAR		
%token	DIV		
%token	LESS		
%token	LESSEQ		
%token	GRTER		
%token	GRTEREQ		
%token	EQ		
%token	NEQ		
%token	ASSIGN		
%token	SEMICOLON	
%token	COMMA		
%token	LBRKT		
%token	RBRKT		
%token	LSQRBRKT	
%token	RSQRBRKT	
%token	LCLYBRKT	
%token	RCLYBRKT	
%token	INC		
%token	DEC		
%token	MOD		
%token	AND		
%token	OR		
%token	NOT		
%token	PLUSEQ		
%token	MINUSEQ		
%token	MULEQ		
%token	DIVEQ		
%token	PRECMP		
%token	ADDR		
%token 	DOT		
%token 	COLON		

%token	ID		
%token	NUM		
%token	FNUM		
%token	STRING		
%token	ILLEGALID	

%token	OTHER	

%left PLUS MINUS
%left STAR DIV


%%	/* rule section */

C57: 	input;

input:	exp SEMICOLON 	 	{ printf("%d\n", $1); }
| input exp SEMICOLON		{ printf("%d\n", $2); }
;

exp:
	NUM 			{ $$ = $1; }
|	exp 	PLUS	exp	{ $$ = $1 + $3;}
|	exp 	MINUS 	exp	{ $$ = $1 - $3;}
|	exp 	STAR  	exp	{ $$ = $1 * $3;}
|	exp 	DIV   	exp	{ $$ = $1 / $3;}
;



%%	/* code section */
void set_debug()
{
	extern int yydebug;	
	yydebug = 1;
}
	
