%token INT
%token DOUBLE
%token VOID
%token ID
%token E
%token F
%%


declaration:	func_decl
|		var_decl
;

func_decl:	func_spec  F
;

var_decl:	var_spec  E 
;

var_spec:	INT
|		DOUBLE
;

func_spec:	INT
|		DOUBLE
|		VOID
;


