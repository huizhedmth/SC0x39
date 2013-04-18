%token A
%token INT
%token CONST
%token SEMICOLON
%token COMMA

/*
%%


var_daclaration:	var_decl_specs var_list SEMICOLON
;

var_list:		var_list COMMA var
|			var
;

var:			A
;

var_decl_specs:		sc_modifier_list type_specifier sc_modifier_list
;

type_specifier:		INT
;

sc_modifier_list:	sc_modifier_list CONST
|			
;
*/

%% stmt:
       expr
     | if_stmt
     ;
     if_stmt:
       "if" expr "then" stmt
     | "if" expr "then" stmt "else" stmt
     ;
     expr:
       "identifier"
;
