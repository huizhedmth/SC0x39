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
%token	CONST		
%token	SWITCH		
%token	STATIC		
%token	STRUCT		
%token	EXTERN		
%token 	DEFAULT		
%token 	CASE	
%token	NIL	
			
%token	SEMICOLON	
%token	LBRKT		
%token	RBRKT		
%token	LSQRBRKT	
%token	RSQRBRKT	
%token	LCLYBRKT	
%token	RCLYBRKT		
%token	PRECMP			
%token 	COLON		
%token 	INC
%token	DEC

%token	ID		
%token	NUM		
%token	FNUM		
%token	STRING		
%token	ILLEGALID	

%token	OTHER	

%left	COMMA
%right	ASSIGN PLUSEQ MINUSEQ MULEQ DIVEQ
%left	OR
%left	AND
%left	EQ NEQ
%left	LESS LESSEQ GRTER GRTEREQ
%left	PLUS MINUS
%left	STAR DIV MOD
%right	ADDR DEREF UMINUS NOT INCPRE DECPRE SIZEOF
%left	ARROW DOT INCPOST DECPOST

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
|		func_declaration
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

func_declaration:	func_type_specifier ID LBRKT formal_params RBRKT compound_statement
|			VOID ID LBRKT formal_params RBRKT compound_statement
;

func_type_specifier:	INT
|			DOUBLE
|			VOID
;

formal_params:		formal_list
|			VOID
|			/* empty */
;

formal_list:		formal_list COMMA formal_param
|			formal_param
;

formal_param:		var_type_specifier ID
|			var_type_specifier ID LSQRBRKT RSQRBRKT
;

compound_statement:	LCLYBRKT local_declarations statement_list RCLYBRKT
;

local_declarations:	local_declarations var_declaration
|			/* empty */
;

statement_list:		statement_list statement
| 			/* empty */
;

statement:		expression_statement
|			compound_statement
;

expression_statement:	expression SEMICOLON
|			SEMICOLON
;

expression:		var ASSIGN expression
|			r_value 
;

var:			ID
|			ID LSQRBRKT expression RSQRBRKT
;

	
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
|			INC var %prec INCPRE
|			DEC var %prec DECPRE
|			LBRKT	expression	RBRKT
|			call
|			NUM
|			FNUM
;

call:			ID LBRKT args RBRKT
;

args:			arg_list
|			/* empty */
;

arg_list:		arg_list COMMA expression
|			expression
;





%%	/* code section */
void set_debug()
{
	extern int yydebug;	
	yydebug = 1;
}
	
