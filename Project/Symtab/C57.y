/* C57.y
 *
 * Bison specification for the C57 grammar, that generates its parser and
 * builds the syntax tree along the way.
 *
 * 05/17/2013
 *
 * Modified based on its first version and comments by THC, Dartmouth College.
 *
 * Currently works with the CFG containing just enough features to meet the minimum requirements for graduate students.
 *
 * by Huizhe Li, Master Student, Dartmouth College
 */

%{
#define YYDEBUG 1
#define YYSTYPE ast_node

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ast.h"		/* syntax tree */

ast_node root = NULL;		/* pointer to the root node of the tree */

int yylex(void);	   	/* scanner */
void yyerror(char const *);
  
extern int lineNumber;		/* in lex.yy.c */
extern char* yytext;
extern char savedIdText[];
extern char savedLiteralText[];


int g_flag_const = 0;		/* storage type for current var_decl */
char* g_type;	   		/* data type for current var_decl. initialized in main.c */
int g_scope = 0;		/* current scope */
%}

%token ELSE		
%token IF		
%token INT		
%token RETURN		
%token VOID		
%token WHILE		
%token FOR		
%token DO		
%token DOUBLE		
%token READ		
%token PRINT		
%token BREAK		
%token CONTINUE	
%token SWITCH	       
%token CASE	
%token DEFAULT	
%token SIZEOF	
%token CONST
	
%token EQ	
%token NEQ     		
%token INC		
%token DEC		
%token AND		
%token OR		
%token LESSEQ		
%token GRTEREQ	
	
%token ID		
%token NUM		
%token FNUM		
%token STRING		
%token OTHER


%left	','
%right	'=' 
%left	OR
%left	AND
%left	EQ NEQ
%left	'<' LESSEQ '>' GRTEREQ
%left	'+' '-'
%left	'*' '/' '%'
%right	UMINUS '!' INCPRE DECPRE SIZEOF
%left	INCPOST DECPOST

%expect 1	/* dangling else */

%%	/* rule section */



program:		declaration_list{
				root = create_ast_node(ROOT);
				root->left_child = $1;
				$$ = root;
				$$->scope = g_scope;
			}
;


declaration_list:	declaration_list declaration{
				ast_node t = $1;
				if (t!=NULL){
				   while (t->right_sibling != NULL)
				   	 t = t->right_sibling;
				   t->right_sibling = $2;
				   $$ = $1;
				}else
				   $$ = $2;
			}
|			declaration {$$ = $1;}
;


declaration:		var_declaration {$$ = $1;}
|			func_declaration {$$ = $1;}
|			func_prototype {$$ = $1;}
;


var_declaration:	var_type_specifier var_decl_list ';' { 
				$$ = $2;
			}
|			CONST {g_flag_const = 1;}var_type_specifier var_decl_list ';'{ 
			      	$$ = $4;
				g_flag_const = 0;
			}
;


var_type_specifier:	INT{
				ast_node t = create_ast_node(TYPE);
				t->value.string = strdup("INT");
				strcpy(g_type, t->value.string);
				$$ = t;
				$$->scope = g_scope;
			}
|			DOUBLE{
				ast_node t = create_ast_node(TYPE);
				t->value.string = strdup("DOUBLE");
				strcpy(g_type, t->value.string);
				$$ = t;
				$$->scope = g_scope;
			}
;


var_decl_list:		var_decl_list ','  var_decl{
				ast_node t = $1;
				if (t!=NULL){
				   while (t->right_sibling != NULL)
				   	 t = t->right_sibling;
				   t->right_sibling = $3;
				   $$ = $1;
				}else
				   $$ = $3;
			}
|			var_decl{$$ = $1;}
;


var_decl:		ID{
				ast_node t = create_ast_node(VAR_DECL);
				$$ = t;
				ast_node t1 = create_ast_node(STORAGE);
				if (g_flag_const == 1)
				   t1->value.string = strdup("CONST");
				else
				   t1->value.string = strdup("NORMAL");
				ast_node t2  = create_ast_node(TYPE);
				t2->value.string = strdup(g_type);
				ast_node t3 = create_ast_node(IDENTIFIER);
				t3->value.string = strdup(savedIdText);
				t->left_child = t1;
				t1->right_sibling = t2;
				t2->right_sibling = t3;
				t3->scope = g_scope;	/* save scope */
				t3->lineNumber = lineNumber;	/* save line number */
				t->scope = g_scope;
				t1->scope = g_scope;
				t2->scope = g_scope;
			}
|			ID '=' {
				ast_node t = create_ast_node(IDENTIFIER);
				t->value.string = strdup(savedIdText);
				$$ = t;
				t->scope = g_scope;
				t->lineNumber = lineNumber;
			} expression {
				ast_node t = create_ast_node(VAR_DECL);
				$$ = t;
				ast_node t1 = create_ast_node(STORAGE);
				if (g_flag_const == 1)
				   t1->value.string = strdup("CONST");
				else
				   t1->value.string = strdup("NORMAL");
				ast_node t2  = create_ast_node(TYPE);
				t2->value.string = strdup(g_type);
				t->left_child = t1;
				t1->right_sibling = t2;
				t2->right_sibling = $3;
				$3->right_sibling = $4;
				t->scope = g_scope;
				t1->scope = g_scope;
				t2->scope = g_scope;
			}
|			ID '[' {
				ast_node t = create_ast_node(IDENTIFIER);
				t->value.string = strdup(savedIdText);
				$$ = t;
				t->scope = g_scope;
				t->lineNumber = lineNumber;
			} expression ']'{
				ast_node t = create_ast_node(VAR_DECL);
				$$ = t;
				ast_node t1 = create_ast_node(STORAGE);
				if (g_flag_const == 1)
				   t1->value.string = strdup("CONST");
				else
				   t1->value.string = strdup("NORMAL");
				ast_node t2  = create_ast_node(TYPE);
				t2->value.string = (char*)malloc(15);
				strcpy(t2->value.string, g_type);
				strcat(t2->value.string, " ARRAY");
			
				t->left_child = t1;
				t1->right_sibling = t2;
				t2->right_sibling = $3;
				$3->right_sibling = $4;
				t->scope = g_scope;
				t1->scope = g_scope;
				t2->scope = g_scope;
			}
;


func_header:		var_type_specifier ID{
				ast_node t = create_ast_node(FUNC_HEADER);
				t->left_child = $1;
				ast_node t1 = create_ast_node(IDENTIFIER);
				t1->value.string = strdup(savedIdText);
				$1->right_sibling = t1;
				$$ = t;
				t->scope = g_scope;
				t1->lineNumber = lineNumber;
			} 
|			VOID ID {
			     	ast_node t = create_ast_node(FUNC_HEADER);
				ast_node t1 = create_ast_node(TYPE);
				t1->value.string = strdup("VOID");
				t->left_child = t1;
				$$ = t;
				ast_node t2 = create_ast_node(IDENTIFIER);
				t2->value.string = strdup(savedIdText);
				t1->right_sibling = t2;
				t->scope = g_scope;
				t1->scope = g_scope;
				t2->scope = g_scope;
				t2->lineNumber = lineNumber;
			}
;


func_declaration:	func_header '(' formal_params ')' compound_statement{
				ast_node t = create_ast_node(FUNC_DECL);
				$$ = t;
				t->left_child = $1;
				$1->right_sibling = $3;
				$3->right_sibling = $5;
				t->scope = g_scope;
				t->lineNumber = lineNumber;
			}	
;


 /* params should either all come with identifiers,
  * or none comes with an identifier.
  * mixed param style will not be accepted. (eg. void f(int, int a);)
  */
func_prototype:		func_header '(' formal_params ')' ';'{
				ast_node t = create_ast_node(FUNC_PROTO);
				$$ = t;
				t->left_child = $1;
				t->left_child->right_sibling = $3;
				t->scope = g_scope;
			}	
|			func_header '(' informal_params ')' ';'{
				ast_node t = create_ast_node(FUNC_PROTO);
				$$ = t;
				t->left_child = $1;
				t->left_child->right_sibling = $3;
				t->scope = g_scope;
			}	
;


formal_params:		formal_list{
				ast_node t = create_ast_node(FUNC_PARAMS);
				$$ = t;
				t->left_child = $1;
				t->scope = g_scope;
			}	
|			VOID{
				ast_node t = create_ast_node(FUNC_PARAMS);
				$$ = t;
				ast_node t1 = create_ast_node(TYPE);
				t1->value.string = strdup("VOID");
				t->left_child = t1;
				t->scope = g_scope;
				t1->scope = g_scope;
			}
|			/* empty */{
				ast_node t = create_ast_node(FUNC_PARAMS);
				$$ = t;
				ast_node t1 = create_ast_node(TYPE);
				t1->value.string = strdup("VOID");
				t->left_child = t1;
				t->scope = g_scope;
				t1->scope = g_scope;
			}
;


formal_list:		formal_list ',' formal_param{
				ast_node t = $1;
				if (t!=NULL){
				   while (t->right_sibling != NULL)
				   	 t = t->right_sibling;
				   t->right_sibling = $3;
				   $$ = $1;
				}else
				   $$ = $3;
			}
|			formal_param{$$ = $1;}
;


formal_param:		var_type_specifier ID{
				ast_node t2 = create_ast_node(PARAM);
				ast_node t = create_ast_node(IDENTIFIER);
				t->value.string = strdup(savedIdText);
				ast_node t1 = create_ast_node(STORAGE);
				t1->value.string = strdup("NORMAL");
			
				$$ = t2;
				t2->left_child = t1;
				t1->right_sibling = $1;
				$1->right_sibling = t;
				t->scope = g_scope;
				t1->scope = g_scope;
				t2->scope = g_scope;
				t->lineNumber = lineNumber;
			}
|			CONST var_type_specifier ID{
				ast_node t2 = create_ast_node(PARAM);
				ast_node t = create_ast_node(IDENTIFIER);
				t->value.string = strdup(savedIdText);
				ast_node t1 = create_ast_node(STORAGE);	
				t1->value.string = strdup("CONST");
				
				$$ = t2;
				t2->left_child = t1;
				t1->right_sibling = $2;
				$2->right_sibling = t;
				t->scope = g_scope;
				t1->scope = g_scope;
				t2->scope = g_scope;
				t->lineNumber = lineNumber;
			}
|			var_type_specifier ID '[' ']'{
				ast_node t2 = create_ast_node(PARAM);
				$1->value.string = (char*)realloc($1->value.string, 15);
				strcat($1->value.string, " ARRAY");
				ast_node t = create_ast_node(IDENTIFIER);
				t->value.string = strdup(savedIdText);
				ast_node t1 = create_ast_node(STORAGE);
			        t1->value.string = strdup("NORMAL");
						 
				$$ = t2;
				t2->left_child = t1;
				t1->right_sibling = $1;
				$1->right_sibling = t;
				t->scope = g_scope;								
				t1->scope = g_scope;
				t2->scope = g_scope;
				t->lineNumber = lineNumber;
			}
|			CONST var_type_specifier ID '[' ']'{
				ast_node t2 = create_ast_node(PARAM);
				$2->value.string = (char*)realloc($2->value.string, 15);
				strcat($2->value.string, " ARRAY");
				ast_node t = create_ast_node(IDENTIFIER);
				t->value.string = strdup(savedIdText);
				ast_node t1 = create_ast_node(STORAGE);
			        t1->value.string = strdup("CONST");
				
				$$ = t2;
				t2->left_child = t1;
				t1->right_sibling = $2;
				$2->right_sibling = t;
				t->scope = g_scope;
				t1->scope = g_scope;
				t2->scope = g_scope;
				t->lineNumber = lineNumber;
			}
;


informal_params:	informal_list {
				ast_node t = create_ast_node(FUNC_PARAMS);
				$$ = t;
				t->left_child = $1;
				t->scope = g_scope;
 			}
;


informal_list:		informal_list ',' informal_param{
				ast_node t = $1;
				if (t!=NULL){
				   while (t->right_sibling != NULL)
				   	 t = t->right_sibling;
				   t->right_sibling = $3;
				   $$ = $1;
				}else
				   $$ = $3;
			}
|			informal_param{ $$ = $1;}
;


informal_param:		var_type_specifier{
				ast_node t2 = create_ast_node(PARAM);
				ast_node t = create_ast_node(STORAGE);
				t->value.string = strdup("NORMAL");
				$$ = t2;
				t2->left_child = t;
				t->right_sibling = $1;
				t->scope = g_scope;
				t2->scope = g_scope;
			}
|			CONST var_type_specifier {
				ast_node t2 = create_ast_node(PARAM);
				ast_node t1 = create_ast_node(STORAGE);	
				t1->value.string = strdup("CONST");
				
				$$ = t2;
				t2->left_child = t1;
				t1->right_sibling = $2;
				t1->scope = g_scope;
				t2->scope = g_scope;
			}
|			var_type_specifier '[' ']'{
				ast_node t2 = create_ast_node(PARAM);
				ast_node t1 = create_ast_node(STORAGE);	
				t1->value.string = strdup("NORMAL");
				$$ = t2;
				t2->left_child = t1;
				$1->value.string = (char*)realloc($1->value.string, 15);
				strcat($1->value.string, " ARRAY");
				t1->right_sibling = $1;
				t1->scope = g_scope;
				t2->scope = g_scope;
			}
|			CONST var_type_specifier '[' ']'{
				ast_node t2 = create_ast_node(PARAM);
				$2->value.string = (char*)realloc($2->value.string, 15);
				strcat($2->value.string, " ARRAY");
				ast_node t1 = create_ast_node(STORAGE);
			        t1->value.string = strdup("CONST");
				
				$$ = t2;
				t2->left_child = t1;
				t1->right_sibling = $2;
				t1->scope = g_scope;
				t2->scope = g_scope;
			}
;


compound_statement:	'{' {g_scope++;} local_declarations statement_list '}'{
			    	ast_node t = create_ast_node(CMPD_STMT);
				ast_node t1 = create_ast_node(LOCAL_DECL);
				ast_node t2 = create_ast_node(STMT_LIST);
				t->left_child = t1;
				t1->right_sibling = t2;
				t1->left_child = $3;
				t2->left_child = $4;
				$$ = t;
				t->scope = g_scope;
				t1->scope = g_scope;
				t2->scope = g_scope;
				g_scope--;
			}
;


local_declarations:	local_declarations var_declaration{
				ast_node t = $1;
				if (t!=NULL){
				   while (t->right_sibling != NULL)
				   	 t = t->right_sibling;
				   t->right_sibling = $2;
				   $$ = $1;
				}else
				   $$ = $2;
			}
|			/* empty */{$$ = NULL;}
;


statement_list:		statement_list statement{
				ast_node t = $1;
				if (t!=NULL){
				   while (t->right_sibling != NULL)
				   	 t = t->right_sibling;
				   t->right_sibling = $2;
				   $$ = $1;
				}else
				   $$ = $2;
			}
|			/* empty */{$$ = NULL}
;


statement:		expression_statement{$$ = $1;}
|			compound_statement{$$ = $1;}
|			if_statement{$$ = $1;}
|			while_statement{$$ = $1;}
|			do_while_statement{$$ = $1;}
|			for_statement{$$ = $1;}
|			return_statement{$$ = $1;}
|			read_statement{$$ = $1;}
|			print_statement{$$ = $1;}
|			break_statement{$$ = $1;}
|			continue_statement{$$ = $1;}
|			switch_statement{$$ = $1;}
|			case_statement{$$ = $1;}
|			default_statement{$$ = $1;}
;


if_statement:		IF '(' expression ')' statement {
			   ast_node t = create_ast_node(IF_STMT);
			   $$ = t;
			   t->left_child = $3;
			   $3->right_sibling = $5;
				t->scope = g_scope;
			}
			 
|			IF '(' expression ')' statement ELSE statement{
			   ast_node t = create_ast_node(IF_ELSE_STMT);
			   $$ = t;
			   t->left_child = $3;
			   $3->right_sibling = $5;
			   $5->right_sibling = $7;
				t->scope = g_scope;
			}
;


while_statement:	WHILE '(' expression ')' statement {
			      ast_node t = create_ast_node(WHILE_STMT);
			      $$ = t;
			      t->left_child = $3;
			      $3->right_sibling = $5;
				t->scope = g_scope;
			}
;


do_while_statement:	DO statement WHILE '(' expression ')' ';' {
			   ast_node t = create_ast_node(DO_WHILE_STMT);
			   $$ = t;
			   t->left_child = $2;
			   $2->right_sibling = $5;
				t->scope = g_scope;
			}
;


for_statement:		FOR '(' for_header_expression ';' for_header_expression ';' for_header_expression ')' statement{
			    ast_node t = create_ast_node(FOR_STMT);
			    $$ = t;
			    t->left_child = $3;
			    $3->right_sibling = $5;
			    $5->right_sibling = $9;
			    $9->right_sibling = $7;
				t->scope = g_scope;
			}
;

for_header_expression:	expression
|			/* empty */{
				ast_node t = create_ast_node(EMPTY);
				$$ = t;
				t->scope = g_scope;
			}
;


return_statement:	RETURN ';' {
			       ast_node t = create_ast_node(RETURN_STMT);
			       $$ = t;
				t->scope = g_scope;
			}
|			RETURN expression ';' {
			       ast_node t = create_ast_node(RETURN_STMT);
			       $$ = t;
			       t->left_child = $2;
				t->scope = g_scope;
			}
;


read_statement:		READ var ';'{
			     ast_node t = create_ast_node(READ_STMT);
			     $$ = t;
			     t->left_child = $2;
				t->scope = g_scope;
			}			 
;


print_statement:	PRINT expression ';'{
			      ast_node t = create_ast_node(PRINT_STMT);
			      $$ = t;
			      t->left_child = $2;
				t->scope = g_scope;
			}
|			PRINT STRING ';'{
			      ast_node t = create_ast_node(PRINT_STMT);
			      $$ = t;  
			      ast_node t1 = create_ast_node(STR_LITERAL);
			      t1->value.string = strdup(savedLiteralText);
			      t->left_child = t1;
				t->scope = g_scope;
				t1->scope = g_scope;
			}
;


break_statement:	BREAK ';'{
			      ast_node t = create_ast_node(BREAK_STMT);
			      $$ = t;
				t->scope = g_scope;
			}
;


continue_statement:	CONTINUE ';'{
			      ast_node t = create_ast_node(CONTINUE_STMT);
			      $$ = t;
				t->scope = g_scope;
			}
;


case_statement:		CASE NUM ':' statement{
			     ast_node t = create_ast_node(CASE_STMT);
			     $$ = t;
			     t->value.int_value = atoi(savedLiteralText);
			     t->right_sibling = $4;
				t->scope = g_scope;
			}    
;


default_statement:	DEFAULT ':' statement{
			     ast_node t = create_ast_node(DEFAULT_STMT);
			     $$ = t;
			     t->right_sibling = $3;
				t->scope = g_scope;
			}    
;


switch_statement:	SWITCH '(' expression ')' statement{
			     ast_node t = create_ast_node(SWITCH_STMT);
			     $$ = t;
			     t->left_child = $3;
			     $3->right_sibling = $5;
				t->scope = g_scope;
			}
;


expression_statement:	expression ';'{$$ = $1;}
|			';'{
				ast_node t = create_ast_node(EMPTY);
				$$ = t;
				t->scope = g_scope;
			}
;


expression:		var '=' expression{
			    ast_node t = create_ast_node(OP_ASSIGN);
			    $$ = t;
			    t->left_child = $1;
			    $1->right_sibling = $3;
				t->scope = g_scope;
			}
|			r_value{$$ = $1;}
;


var:			ID{
				ast_node t = create_ast_node(IDENTIFIER);
				t->value.string = strdup(savedIdText);
				$$ = t;
				t->scope = g_scope;
				t->lineNumber = lineNumber;
				t->scope = g_scope;
			}
|			ID {			
			   	ast_node t = create_ast_node(IDENTIFIER);
				t->value.string = strdup(savedIdText);
				$$ = t;
				t->scope = g_scope;
				t->lineNumber = lineNumber;
				t->scope = g_scope;
			}'[' expression ']'{
				$$ = $2;
				$$->left_child = $4;
			}
;


r_value:		expression '+' expression{
			    ast_node t = create_ast_node(OP_PLUS);
			    $$ = t;
			    t->left_child = $1;
			    $1->right_sibling = $3;
				t->scope = g_scope;
			}
|			expression '-' expression{
			    ast_node t = create_ast_node(OP_MINUS);
			    $$ = t;
			    t->left_child = $1;
			    $1->right_sibling = $3;
				t->scope = g_scope;
			}
|			expression '*' expression{
			    ast_node t = create_ast_node(OP_TIMES);
			    $$ = t;
			    t->left_child = $1;
			    $1->right_sibling = $3;
				t->scope = g_scope;
			}
|			expression '/' expression{
			    ast_node t = create_ast_node(OP_DIVIDE);
			    $$ = t;
			    t->left_child = $1;
			    $1->right_sibling = $3;
				t->scope = g_scope;
			}
|			expression '%' expression{
			    ast_node t = create_ast_node(OP_MOD);
			    $$ = t;
			    t->left_child = $1;
			    $1->right_sibling = $3;
				t->scope = g_scope;
			}
|			expression '<' expression{
			    ast_node t = create_ast_node(OP_LESS);
			    $$ = t;
			    t->left_child = $1;
			    $1->right_sibling = $3;
				t->scope = g_scope;
			}
|			expression LESSEQ expression{
			    ast_node t = create_ast_node(OP_LESSEQ);
			    $$ = t;
			    t->left_child = $1;
			    $1->right_sibling = $3;
				t->scope = g_scope;
			}
|			expression '>' expression{
			    ast_node t = create_ast_node(OP_GRTER);
			    $$ = t;
			    t->left_child = $1;
			    $1->right_sibling = $3;
				t->scope = g_scope;
			}
|			expression GRTEREQ expression{
			    ast_node t = create_ast_node(OP_GRTEREQ);
			    $$ = t;
			    t->left_child = $1;
			    $1->right_sibling = $3;
				t->scope = g_scope;
			}
|			expression EQ expression{
			    ast_node t = create_ast_node(OP_EQUALS);
			    $$ = t;
			    t->left_child = $1;
			    $1->right_sibling = $3;
				t->scope = g_scope;
			}
|			expression NEQ expression{
			    ast_node t = create_ast_node(OP_NEQ);
			    $$ = t;
			    t->left_child = $1;
			    $1->right_sibling = $3;
				t->scope = g_scope;
			}
|			expression AND expression{
			    ast_node t = create_ast_node(OP_AND);
			    $$ = t;
			    t->left_child = $1;
			    $1->right_sibling = $3;
				t->scope = g_scope;
			}
|			expression OR expression{
			    ast_node t = create_ast_node(OP_OR);
			    $$ = t;
			    t->left_child = $1;
			    $1->right_sibling = $3;
				t->scope = g_scope;
			}
|			'!' expression{
			    ast_node t = create_ast_node(OP_NOT);
			    $$ = t;
			    t->left_child = $2;
				t->scope = g_scope;
			}
|			'-' expression %prec UMINUS{
			    ast_node t = create_ast_node(OP_MINUS);
			    $$ = t;
			    t->left_child = $2;
				t->scope = g_scope;
			}
|			var{ $$ = $1;}
|			INC var %prec INCPRE{
			    ast_node t = create_ast_node(OP_INC_PRE);
			    t->left_child = $2;
			    $$ = t;
				t->scope = g_scope;
			}
|			DEC var %prec DECPRE{
			    ast_node t = create_ast_node(OP_DEC_PRE);
			    t->left_child = $2;
			    $$ = t;
				t->scope = g_scope;
			}
|			var INC %prec INCPOST{
			    ast_node t = create_ast_node(OP_INC_POST);
			    t->left_child = $1;
			    $$ = t;
				t->scope = g_scope;
			}
|			var DEC %prec DECPOST{
			    ast_node t = create_ast_node(OP_DEC_POST);
			    t->left_child = $1;
			    $$ = t;
				t->scope = g_scope;
			}
|			'(' expression ')' { $$ = $2;}
|			NUM{
				ast_node t = create_ast_node(INT_LITERAL);
				t->value.int_value = atoi(savedLiteralText);
				$$ = t;
				t->scope = g_scope;
			}
|			FNUM{
				ast_node t = create_ast_node(DOUBLE_LITERAL);
				t->value.double_value = atof(savedLiteralText);
				$$ = t;
				t->scope = g_scope;
			}
|			sizeof_expression {$$ = $1;}
|			call {$$ = $1;}
;


sizeof_expression:	SIZEOF '(' var_type_specifier ')' {
			       ast_node t = create_ast_node(SIZE_OF);
			       $$ = t;
			       t->left_child = $3;
				t->scope = g_scope;
			}
|			SIZEOF '(' expression ')' {
			       ast_node t = create_ast_node(SIZE_OF);
			       $$ = t;
			       t->left_child = $3;
				t->scope = g_scope;
			}
;


call:			ID {
			   ast_node t = create_ast_node(IDENTIFIER);
			   t->value.string = strdup(savedIdText);
			   $$ = t;
				t->scope = g_scope;
				t->lineNumber = lineNumber;
			} '(' args ')'{
			   ast_node t = create_ast_node(CALL);
			   t->left_child = $2;
			   $2->right_sibling = $4;
			   $$ = t;
				t->scope = g_scope;
			}
;


args:			arg_list{
				ast_node t = create_ast_node(ARGS);
				$$ = t;
				t->left_child = $1;
				t->scope = g_scope;
			}
|			/* empty */{$$ = NULL;}
;


arg_list:		arg_list ',' expression{
				ast_node t = $1;
				if (t!=NULL){
				   while (t->right_sibling != NULL)
				   	 t = t->right_sibling;
				   t->right_sibling = $3;
				   $$ = $1;
				}else
				   $$ = $3;
			}
|			expression{$$ = $1;}
;




%%	/* code section */
void set_debug()
{
	extern int yydebug;
	yydebug = 1;
}

void yyerror(char const* s)
{
	fprintf(stderr, "%s\n", s);
}
