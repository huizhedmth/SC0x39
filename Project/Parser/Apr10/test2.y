%token INT
%token DOUBLE
%token VOID
%token ID
%token E
%token F
%%


start:	a ID
|	b 
;

a:	E
|	F
;

b:	E
|	F
|	E ID
;
