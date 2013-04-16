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
%token	READ
%token	PRINT
			
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

%expect 1	/* match dangling "else"s with the closest unmatched "then" 
		 * this is achieved by prefering "shift" rather than "reduce",
		 * which is by default the choice of bison 
		 */ 


%%	/* rule section */


/* 1 */
program:		declaration_list 
;

/* 2 */
declaration_list:	declaration_list declaration
| 			declaration
;		

/* 3 */
declaration:		var_declaration
|			func_declaration
|			func_prototype
;

/* 4 */
var_declaration:	CONST type_specifier var_decl_list SEMICOLON
|			type_specifier CONST var_decl_list SEMICOLON
|			type_specifier var_decl_list SEMICOLON
;


/* 5 */
type_specifier:		INT
|			DOUBLE
;

/* 6 */
var_decl_list:		var_decl_list COMMA var_decl
|			var_decl
;

/* 7 */
var_decl:		ID
|			ID ASSIGN expression 
|			ID LSQRBRKT expression RSQRBRKT
;

/* 8 */
func_declaration:	type_specifier ID LBRKT formal_params RBRKT compound_statement
|			VOID ID LBRKT formal_params RBRKT compound_statement
;

/* 9 */
func_prototype:		VOID ID LBRKT formal_params RBRKT SEMICOLON
|			type_specifier ID LBRKT formal_params RBRKT SEMICOLON
;

/* 10 */
formal_params:		formal_list
|			VOID
|			/* empty */
;

/* 11 */
formal_list:		formal_list COMMA formal_param
|			formal_param
;

/* 12 */
formal_param:		type_specifier ID
|			type_specifier ID LSQRBRKT RSQRBRKT
;

/* 13 */
compound_statement:	LCLYBRKT local_declarations statement_list RCLYBRKT
;

/* 14 */
local_declarations:	local_declarations var_declaration
|			/* empty */
;

/* 15 */
statement_list:		statement_list statement
| 			/* empty */
;

/* 16 */
statement:		expression_statement
|			compound_statement
|			if_statement
|			while_statement
|			do_while_statement
|			for_statement
|			return_statement
|			read_statement
|			print_statement
|			break_statement
|			continue_statement
|			switch_statement
|			case_statement
|			default_statement
;

/* 17 */
expression_statement:	expression SEMICOLON
|			SEMICOLON
;

/* 18 */
if_statement:		IF LBRKT expression RBRKT statement
|			IF LBRKT expression RBRKT statement ELSE statement
;


/* 19 */
while_statement:	WHILE LBRKT expression RBRKT statement
;

/* 20 */
do_while_statement:	DO statement WHILE LBRKT expression RBRKT SEMICOLON
;

/* 21 */
for_statement:		FOR LBRKT for_header_expression SEMICOLON for_header_expression SEMICOLON for_header_expression RBRKT statement
;

/* 22 */
for_header_expression:	expression
|			/* empty */
;

/* 23 */
return_statement:	RETURN SEMICOLON
|			RETURN expression SEMICOLON
;

/* 24 */
read_statement:		READ var SEMICOLON
;

/* 25 */
print_statement:	PRINT expression SEMICOLON
|			PRINT STRING SEMICOLON
;

/* 26 */
expression:		var ASSIGN expression
|			r_value 
;

/* 27 */
var:			ID
|			ID LSQRBRKT expression RSQRBRKT
;

/* 28 */
r_value:		expression	PLUS		expression
|			expression	MINUS		expression
|			expression	STAR		expression
|			expression	DIV		expression
|			expression	MOD		expression
|			expression	LESS		expression
|			expression	LESSEQ		expression
|			expression	GRTER		expression
|			expression	GRTEREQ		expression
|			expression	EQ		expression
|			expression	NEQ		expression
|			expression	AND		expression
|			expression	OR		expression
|			NOT	expression
|			MINUS	expression %prec UMINUS
|			var
|			INC var %prec INCPRE
|			DEC var %prec DECPRE
|			var INC %prec INCPOST
|			var DEC %prec DECPOST
|			LBRKT	expression	RBRKT
|			call
|			NUM
|			FNUM
|			sizeof_expression
;

/* 29 */
call:			ID LBRKT args RBRKT
;

/* 30 */
args:			arg_list
|			/* empty */
;

/* 31 */
arg_list:		arg_list COMMA expression
|			expression
;

/* 32 */
break_statement:	BREAK SEMICOLON 
;

/* 33 */ 
continue_statement:	CONTINUE SEMICOLON
;

/* 34 */
case_statement:		CASE NUM COLON statement
;

/* 35 */
default_statement:	DEFAULT COLON statement
;

/* 36 */
switch_statement:	SWITCH LBRKT expression RBRKT statement
;

/* 38 */
sizeof_expression:	SIZEOF LBRKT type_specifier RBRKT
|			SIZEOF LBRKT expression RBRKT
;







%%	/* code section */
void set_debug()
{
	extern int yydebug;	
	yydebug = 1;
}
	
