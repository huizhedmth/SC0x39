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

%expect 2	/* match dangling "else"s with the closest unmatched "then" 
		 * this is achieved by prefering "shift" rather than "reduce",
		 * which is by default the choice of bison 
		 */ 


%%	/* rule section */

	/* the following rules deal with var decl and expr stmt
	 * with no extra features 
 	 */


/* 1 */
program:	declaration_list 
;

/* 2 */
declaration_list:	declaration_list declaration
| 			declaration
;		

/* 3 */
declaration:	var_declaration
|		func_declaration
;

/* 4 */
var_declaration:	var_type_specifier var_decl_list SEMICOLON
;

/* 5 */
var_type_specifier:	INT
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
func_declaration:	var_type_specifier ID LBRKT formal_params RBRKT compound_statement
|			VOID ID LBRKT formal_params RBRKT compound_statement
;

/* 9 
func_type_specifier:	INT
|			DOUBLE
|			VOID
;
*/

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
formal_param:		var_type_specifier ID
|			var_type_specifier ID LSQRBRKT RSQRBRKT
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
|			switch_statement
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
while_statement:	WHILE LBRKT expression RBRKT loop_statement
;

/* 20 */
do_while_statement:	DO loop_statement WHILE LBRKT expression RBRKT SEMICOLON
;

/* 21 */
for_statement:		FOR LBRKT for_header_expression SEMICOLON for_header_expression SEMICOLON for_header_expression RBRKT loop_statement
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

/* EXTRA: break & continue */
loop_statement:		expression_statement
|			loop_compound_statement
|			loop_if_statement
|			while_statement
|			do_while_statement
|			for_statement
|			return_statement
|			read_statement
|			print_statement
|			break_statement
|			continue_statement
;

break_statement:	BREAK SEMICOLON
;

continue_statement:	CONTINUE SEMICOLON
;

loop_compound_statement:LCLYBRKT local_declarations loop_statement_list RCLYBRKT
;
	
loop_statement_list:	loop_statement_list loop_statement
| 			/* empty */
;

loop_if_statement:	IF LBRKT expression RBRKT loop_statement
|			IF LBRKT expression RBRKT loop_statement ELSE loop_statement
;

/* EXTRA: switch */
switch_statement:	SWITCH LBRKT expression RBRKT swt_statement
;

swt_statement:		expression_statement
|			case_compound_statement
|			case_if_statement
|			while_statement
|			do_while_statement
|			for_statement
|			return_statement
|			read_statement
|			print_statement	
|			case_statement
|			break_statement
;

case_statement:		CASE COLON swt_statement
;

case_compound_statement:LCLYBRKT local_declarations case_statement_list RCLYBRKT
;
	
case_statement_list:	case_statement_list case_statement
| 			/* empty */
;

case_if_statement:	IF LBRKT expression RBRKT case_statement
|			IF LBRKT expression RBRKT case_statement ELSE loop_statement
;



%%	/* code section */
void set_debug()
{
	extern int yydebug;	
	yydebug = 1;
}
	
