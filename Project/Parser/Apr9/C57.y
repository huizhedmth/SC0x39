/* C57.y
 * 
 * Bison grammar rule definition.
 * Used as the bison input file to
 * generate source code of a parser for the C57 language.
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
%token	NIL	

%token	PLUS		
%token	MINUS		
%token	STAR		
%token	DIV		
%token	LESS		
%token	LESSEQ		
%token	GRTER		
%token	GRTEREQ				
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
%token	NOT		
%token	PLUSEQ		
%token	MINUSEQ		
%token	MULEQ		
%token	DIVEQ		
%token	PRECMP			
%token 	COLON		

%token	ID		
%token	NUM		
%token	FNUM		
%token	STRING		
%token	ILLEGALID	

%token	OTHER	

%left OR
%left AND
%left EQ NEQ
%left LESS LESSEQ GRTER GRTEREQ
%left PLUS MINUS
%left STAR DIV ADDR DOT ARROW
%left NOT INC DEC UMINUS



%%	/* rule section */

	/* the following rules deal with var decl and expr stmt
	 * with no extra features 
 	 */

program:	declaration_list 
;

declaration_list:	declaration_list declaration
| 			declaration
;		

declaration:	var_declaration
|		statement
;

var_declaration:	var_type_specifier var_decl_list SEMICOLON
;

var_type_specifier:	INT
|			DOUBLE
;

var_decl_list:		var_decl_list COMMA var_decl
|			var_decl
;

var_decl:		ID
|			ID ASSIGN expression 
|			ID LSQRBRKT expression RSQRBRKT
;

statement_list:		statement_list statement
| 			/* empty */
;

statement:		expression_statement
;

expression_statement:	expression SEMICOLON
|			SEMICOLON
;

expression:		var ASSIGN expression
|			/* r_value */ NUM
;

var:			ID
|			ID LSQRBRKT expression RSQRBRKT
;

	/*
r_value:		expression	PLUS	expression
|			expression	MINUS	expression
|			expression	STAR	expression
|			expression	DIV	expression
|			expression	MOD	expression
|			expression	LESS	expression
|			expression	LESSEQ	expression
|			expression	GRTER	expression
|			expression	GRTEREQ	expression
|			expression	EQ	expression
|			expression	NEQ	expression
|			expression	AND	expression
|			expression	OR	expression
|			NOT	expression
|			MINUS	expression %prec UMINUS
|			var
|			INC var
|			DEC var
|			LBRKT	expression	RBRKT
|			NUM
|			FNUM
;
	*/





%%	/* code section */
void set_debug()
{
	extern int yydebug;	
	yydebug = 1;
}
	