/* C57.y
 * 
 * Bison grammar rule definition.
 * Used as the bison input file to
 * generate source code of a parser for the C57 language.
 * 
 * By Huizhe Li, Master Student, Dartmouth College
 *
 */

%{
	#define YYSTYPE ast_node
	#define YYDEBUG 1

	#include <stdio.h>
	#include "ast.h"	/* syntax tree */
	#include <string.h>
	#include <stdlib.h>
	#include "idt.h"	/* identifier table */

	int yylex (void);
	void yyerror (char const *);


	extern ast_node root;	
	extern int lineNumber;
	extern char savedIdText[];
	extern char savedLiteralText[];	
	extern char savedKwText[];	/* for type info */
	extern char savedStrText[];	/* for string literals */

	ID_table *the_id_table;

	char* retrieve_id(ID_table* table, char* id);

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


program:			declaration_list{
				ast_node t = create_ast_node(ROOT);
  				t->left_child = $1;
 				root = $$ = t; 
			}
;

declaration_list:	declaration_list declaration{		
				/* standard solution to recursive lists */	
  				ast_node t = $1;
 				if (t != NULL) {
   					while (t->right_sibling != NULL)
       						t = t->right_sibling;
     					t->right_sibling = $2;
   					$$ = $1;
  				}else
					$$ = $2;
			}
| 			declaration{$$ = $1;}
;		

declaration:		var_declaration	{ $$ = $1;}
|			func_declaration{ $$ = $1;}
|			func_prototype	{ $$ = $1;}
;

var_declaration:	CONST type_specifier var_decl_list SEMICOLON{
				ast_node t = create_ast_node(VAR_DECL);
				t->left_child = $2;
				t->left_child->right_sibling = $3;
				$$ = t;
			}	
|			type_specifier CONST var_decl_list SEMICOLON{
				ast_node t = create_ast_node(VAR_DECL);
				t->left_child = $1;
				t->left_child->right_sibling = $3;
				$$ = t;
			}
|			type_specifier var_decl_list SEMICOLON{
				ast_node t = create_ast_node(VAR_DECL);
				t->left_child = $1;
				t->left_child->right_sibling = $2;
				$$ = t;
			}		
;

type_specifier:		INT{
				ast_node t = create_ast_node(TYPE);	/* save type info */
				t->value.string = strdup(savedKwText);
				$$ = t;
			}
|			DOUBLE{
				ast_node t = create_ast_node(TYPE);
				t->value.string = strdup(savedKwText);
				$$ = t;
			}
;

var_decl_list:		var_decl_list COMMA var_decl{
  				ast_node t = $1;
 				if (t != NULL) {
   					while (t->right_sibling != NULL)
       						t = t->right_sibling;
     					t->right_sibling = $3;
   					$$ = $1;
  				}else
					$$ = $3;
			}
|			var_decl	 { $$ = $1;}
;

var_decl:		ID {
				ast_node t = create_ast_node(IDENT);
				t->value.string = retrieve_id(the_id_table, savedIdText);
				$$ = t;
			}
|			ID {
				ast_node t = create_ast_node(IDENT);
				t->value.string = retrieve_id(the_id_table, savedIdText);
				$1 = t;
			} ASSIGN expression{
				$1->left_child = $4;
				$$ = $1;
			}
|			ID {
				ast_node t = create_ast_node(IDENT);
				char* tmp = (char*)malloc(strlen(savedIdText)+3);
				strcat(tmp, savedIdText);
				strcat(tmp, "[]");
				tmp = retrieve_id(the_id_table, tmp);
				t->value.string = tmp;
				$1 = t;
			} LSQRBRKT expression RSQRBRKT{
				$1->left_child = $4;
				$$ = $1;
			} 
;

/* common part for definitions and prototypes */
func_header:		type_specifier ID {
				ast_node t = create_ast_node(FUNC_HEADER);
				t->value.string = retrieve_id(the_id_table, savedIdText);
				$$ = t;
			} LBRKT formal_params RBRKT {
				$$ = $3;
				$$->left_child = $5;
			}
|		 	VOID ID {
				ast_node t = create_ast_node(FUNC_HEADER);
				t->value.string = retrieve_id(the_id_table, savedIdText);
				$$ = t;
			}LBRKT formal_params RBRKT {
				$$ = $3;
				$$->left_child = $5;
			}
;


func_declaration:	func_header compound_statement{
				ast_node t = create_ast_node(FUNC_DECL);
				t->left_child = $1;
				t->left_child->right_sibling = $2;
				$$ = t;
			}
;

func_prototype:		func_header SEMICOLON{
				ast_node t = create_ast_node(FUNC_PROTO);
				t->left_child = $1;
				$$ = t;
			}
;

formal_params:		formal_list { $$ = $1;}
|			VOID	    { $$ = NULL;}
|			/* empty */ { $$ = NULL;}
;

/* 11 */
formal_list:		formal_list COMMA formal_param{
  				ast_node t = $1;
 				if (t != NULL) {
   					while (t->right_sibling != NULL)
       						t = t->right_sibling;
     					t->right_sibling = $3;
   					$$ = $1;
  				}else
					$$ = $3;
			}
|			formal_param { $$ = $1;}
;

/* merged with proto_params, which can havo no ID */
formal_param:		type_specifier ID {
				ast_node t1 = create_ast_node(TYPE);
				t1->value.string = strdup(savedKwText);	/* save type info */
				ast_node t2 = create_ast_node(IDENT);
				t2->value.string = retrieve_id(the_id_table, savedIdText);
				ast_node t = create_ast_node(FORMAL_PARAM);
				t->left_child = t1;
				t->left_child->right_sibling = t2;
				$$ = t;
			}
|			type_specifier {
				ast_node t = create_ast_node(FORMAL_PARAM);
				ast_node t1 = create_ast_node(TYPE);
				t1->value.string = strdup(savedKwText);
				t->left_child = t1;
				$$ = t;
			}
			/* extra '[]' for array type */
|			type_specifier ID LSQRBRKT RSQRBRKT{
				ast_node t = create_ast_node(FORMAL_PARAM);
				ast_node t1 = create_ast_node(TYPE);
				ast_node t2 = create_ast_node(IDENT);
				char* tmp = (char*)malloc(strlen(savedIdText)+3);
				strcat(tmp, savedIdText);
				strcat(tmp, "[]");
				tmp = retrieve_id(the_id_table, tmp);
				t2->value.string = tmp;
				t1->value.string = strdup(savedKwText);
				t->left_child = t1;
				t->left_child->right_sibling = t2;
				$$ = t;
			}
|			type_specifier LSQRBRKT RSQRBRKT{
				ast_node t = create_ast_node(FORMAL_PARAM);
				ast_node t1 = create_ast_node(TYPE);
				ast_node t2 = create_ast_node(IDENT);
				char* tmp = (char*)malloc(3);
				strcat(tmp, "[]");
				tmp = retrieve_id(the_id_table, tmp);
				t2->value.string = tmp;
				t1->value.string = strdup(savedKwText);
				t->left_child = t1;
				t->left_child->right_sibling = t2;
				$$ = t;
			}
;

compound_statement:	LCLYBRKT local_declarations statement_list RCLYBRKT{
				ast_node t = create_ast_node(CMPD_STMT);
				ast_node t1 = create_ast_node(LOCAL_DECL);
				if ($2 != NULL){
					t1->left_child= $2;
					t->left_child = t1;
					t->left_child->right_sibling = $3;
				}else{
					t1 = NULL;
					t->left_child = $3;
				}
				$$ = t;
			}
;

local_declarations:	local_declarations var_declaration{
  				ast_node t = $1;
 				if (t != NULL) {
   					while (t->right_sibling != NULL)
       						t = t->right_sibling;
     					t->right_sibling = $2;
   					$$ = $1;
  				}else
					$$ = $2;
			}
|			/* empty */{ $$ = NULL;}
;

statement_list:		statement_list statement{
  				ast_node t = $1;
 				if (t != NULL) {
   					while (t->right_sibling != NULL)
       						t = t->right_sibling;
     					t->right_sibling = $2;
   					$$ = $1;
  				}else
					$$ = $2;
			}
| 			/* empty */{$$ = NULL;}
;

statement:		expression_statement{ $$ = $1;}
|			compound_statement{ $$ = $1;}
|			if_statement{ $$ = $1;}
|			while_statement{ $$ = $1;}
|			do_while_statement{ $$ = $1;}
|			for_statement{ $$ = $1;}
|			return_statement{ $$ = $1;}
|			read_statement{ $$ = $1;}
|			print_statement{ $$ = $1;}
|			break_statement{ $$ = $1;}
|			continue_statement{ $$ = $1;}
|			switch_statement{ $$ = $1;}
|			case_statement{ $$ = $1;}
|			default_statement{ $$ = $1;}
;

expression_statement:	expression SEMICOLON{$$ = $1;}
|			SEMICOLON{$$ = create_ast_node(EMPTY_STMT);}	/* better not set to NULL */
;

if_statement:		IF LBRKT expression RBRKT statement {
				ast_node t = create_ast_node(IF_STMT);
				t->left_child = $3;
				t->left_child->right_sibling = $5;
				$$ = t;
			}
|			IF LBRKT expression RBRKT statement ELSE statement{
				ast_node t = create_ast_node(IF_ELSE_STMT);
				t->left_child = $3;
				t->left_child->right_sibling = $5;
				t->left_child->right_sibling->right_sibling = $7;
				$$ = t;
			}
;


while_statement:	WHILE LBRKT expression RBRKT statement{
				ast_node t = create_ast_node(WHILE_STMT);
				t->left_child = $3;
				t->left_child->right_sibling = $5;
				$$ = t;
			}
;

do_while_statement:	DO statement WHILE LBRKT expression RBRKT SEMICOLON{
				ast_node t = create_ast_node(DO_WHILE_STMT);
				t->left_child = $5;	/* set first child to be the loop condition */
				t->left_child->right_sibling = $2;
				$$ = t;
			}
;

for_statement:		FOR for_header statement	{
				ast_node t = create_ast_node(FOR_STMT);
				t->left_child = $2;
				/* this is guaranteed not to dereference a null pointer, see rule "for_header" below */
				t->left_child->right_sibling->right_sibling->right_sibling = $3;
				$$ = t;
			}
;

for_header:		LBRKT for_header_expression SEMICOLON for_header_expression SEMICOLON for_header_expression RBRKT{
				/* hold place for empty for_header_expression */
				if($2 == NULL)$2 = create_ast_node(BOZO);
				if($4 == NULL)$4 = create_ast_node(BOZO);				
				if($6 == NULL)$6 = create_ast_node(BOZO);						
				$$ = $2;
				$$->right_sibling = $4;
				$$->right_sibling->right_sibling = $6;		
			}
;

for_header_expression:	expression {$$ = $1;}
|			/* empty */{$$ = NULL;}
;

return_statement:	RETURN SEMICOLON{
				ast_node t = create_ast_node(RTN_STMT);
				$$ = t;
			}
|			RETURN expression SEMICOLON{
				ast_node t = create_ast_node(RTN_STMT);
				$$ = t;
				$$->left_child = $2;	/* return value */
			}
;

read_statement:		READ var SEMICOLON{
				ast_node t = create_ast_node(READ_STMT);
				$$ = t;
				$$->left_child = $2;
			}
;

print_statement:	PRINT expression SEMICOLON{
				ast_node t = create_ast_node(PRINT_STMT);
				$$ = t;
				$$->left_child = $2;
			}
|			PRINT STRING SEMICOLON{
				ast_node t = create_ast_node(PRINT_STMT);
				ast_node t1 = create_ast_node(STRING_LITERAL);
				t1->value.string = strdup(savedStrText);
				t->left_child = t1;
				$$ = t;
			}
;

expression:		var ASSIGN expression{
				ast_node t = create_ast_node(OP_ASSIGN);
				t->left_child = $1;
				t->left_child->right_sibling = $3;
				$$ = t;
			}
|			r_value {$$ = $1;}
;

var:			ID{
 				ast_node t = create_ast_node(IDENT);
  				t->value.string = retrieve_id(the_id_table, savedIdText);
				$$ = t;
			}
|			ID {
				ast_node t = create_ast_node(IDENT);
				char* tmp = (char*)malloc(strlen(savedIdText)+3);
				strcat(tmp, savedIdText);
				strcat(tmp, "[]");
				tmp = retrieve_id(the_id_table, tmp);
				t->value.string = tmp;
				t->value.string = tmp;
				$1 = t;
			} LSQRBRKT expression RSQRBRKT {
				$1->left_child = $4;
				$$ = $1;		
			}		
;

r_value:		expression	PLUS		expression{
 				ast_node t = create_ast_node(OP_PLUS);
  				t->left_child = $1;
  				t->left_child->right_sibling = $3;
				$$ = t;
			}
|			expression	MINUS		expression{
 				ast_node t = create_ast_node(OP_MINUS);
  				t->left_child = $1;
  				t->left_child->right_sibling = $3;
				$$ = t;
			}
|			expression	STAR		expression{
 				ast_node t = create_ast_node(OP_TIMES);
  				t->left_child = $1;
  				t->left_child->right_sibling = $3;
				$$ = t;
			}
|			expression	DIV		expression{
 				ast_node t = create_ast_node(OP_DIVIDE);
  				t->left_child = $1;
  				t->left_child->right_sibling = $3;
				$$ = t;
			}
|			expression	MOD		expression{
 				ast_node t = create_ast_node(OP_MOD);
  				t->left_child = $1;
  				t->left_child->right_sibling = $3;
				$$ = t;
			}
|			expression	LESS		expression{
 				ast_node t = create_ast_node(OP_LESS);
  				t->left_child = $1;
  				t->left_child->right_sibling = $3;
				$$ = t;
			}
|			expression	LESSEQ		expression{
 				ast_node t = create_ast_node(OP_LESSEQ);
  				t->left_child = $1;
  				t->left_child->right_sibling = $3;
				$$ = t;
			}
|			expression	GRTER		expression{
 				ast_node t = create_ast_node(OP_GRTER);
  				t->left_child = $1;
  				t->left_child->right_sibling = $3;
				$$ = t;
			}
|			expression	GRTEREQ		expression{
 				ast_node t = create_ast_node(OP_GRTEREQ);
  				t->left_child = $1;
  				t->left_child->right_sibling = $3;
				$$ = t;
			}
|			expression	EQ		expression{
 				ast_node t = create_ast_node(OP_EQUALS);
  				t->left_child = $1;
  				t->left_child->right_sibling = $3;
				$$ = t;
			}
|			expression	NEQ		expression{
 				ast_node t = create_ast_node(OP_NEQ);
  				t->left_child = $1;
  				t->left_child->right_sibling = $3;
				$$ = t;
			}
|			expression	AND		expression{
 				ast_node t = create_ast_node(OP_AND);
  				t->left_child = $1;
  				t->left_child->right_sibling = $3;
				$$ = t;
			}
|			expression	OR		expression{
 				ast_node t = create_ast_node(OP_OR);
  				t->left_child = $1;
  				t->left_child->right_sibling = $3;
				$$ = t;
			}
|			NOT	expression{
 				ast_node t = create_ast_node(OP_NOT);	
				t->left_child = $2;
				$$ = t;
			}
|			MINUS	expression %prec UMINUS{
 				ast_node t = create_ast_node(OP_UMINUS);	
				t->left_child = $2;
				$$ = t;
			}
|			var{
				$$ = $1;
			}
|			INC var %prec INCPRE{
 				ast_node t = create_ast_node(INC_PRE);	
				t->left_child = $2;
				$$ = t;
			}
|			DEC var %prec DECPRE{
 				ast_node t = create_ast_node(DEC_PRE);	
				t->left_child = $2;
				$$ = t;
			}
|			var INC %prec INCPOST{
 				ast_node t = create_ast_node(INC_POST);	
				t->left_child = $1;
				$$ = t;
			}
|			var DEC %prec DECPOST{
 				ast_node t = create_ast_node(DEC_POST);	
				t->left_child = $1;
				$$ = t;
			}
|			LBRKT	expression	RBRKT{$$ = $2;}
|			call{ $$ = $1;}
|			NUM{
  				ast_node t = create_ast_node(INT_LITERAL);
 				t->value.int_value = atoi(savedLiteralText);
 				$$ = t; 
			}
|			FNUM{
  				ast_node t = create_ast_node(DOUBLE_LITERAL);
 				t->value.double_value = atof(savedLiteralText);
 				$$ = t; 
			}
|			sizeof_expression
;

call:			ID {
				ast_node t = create_ast_node(IDENT);
				t->value.string = retrieve_id(the_id_table, savedIdText);	/* func ID */
				$1 = t;
			}LBRKT args RBRKT{
				ast_node t = create_ast_node(CALL);
				t->value.string = retrieve_id(the_id_table, savedIdText);	/* func ID */
				t->left_child = $4;
				$$ = t;
			}
;

args:			arg_list		{$$ = $1;}
|			/* empty */	{$$ = NULL;}
;

arg_list:		arg_list COMMA expression{
  				ast_node t = $1;
 				if (t != NULL) {
   					while (t->right_sibling != NULL)
       						t = t->right_sibling;
     					t->right_sibling = $3;
   					$$ = $1;
  				}else
					$$ = $3;
			}
|			expression	{$$ = $1;}
;

break_statement:	BREAK SEMICOLON{
				ast_node t = create_ast_node(BREAK_STMT);
				$$ = t;
			}
;

continue_statement:	CONTINUE SEMICOLON{
				ast_node t = create_ast_node(CONTINUE_STMT);
				$$ = t;
			}
;

case_statement:		CASE NUM COLON statement{
				ast_node t = create_ast_node(CASE_STMT);
				t->value.int_value = atoi(savedLiteralText);	/* NUM */
				t->right_sibling = $4;
				$$ = t;
			}
;

default_statement:	DEFAULT COLON statement{
				ast_node t = create_ast_node(DEFAULT_STMT);
				t->right_sibling = $3;
				$$ = t;
			}
;

switch_statement:	SWITCH LBRKT expression RBRKT statement{
				ast_node t = create_ast_node(SWITCH_STMT);
				t->left_child = $5;
				$$ = t;
			}
;

sizeof_expression:	SIZEOF LBRKT type_specifier RBRKT{
				ast_node t = create_ast_node(SIZE_OF);
				t->left_child = $3;
				$$ = t;
			}
|			SIZEOF LBRKT expression RBRKT{
				ast_node t = create_ast_node(SIZE_OF);
				t->left_child = $3;
				$$ = t;
			}
;







%%	/* code section */
void set_debug()
{
	extern int yydebug;	
	yydebug = 1;
}






	
