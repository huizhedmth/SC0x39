/* definition section */
/**********************/

%{
#include<stdlib.h>
int expr_layer = 0;
%}

whitespace		[ \t\n]
letter 			[A-Za-z]
digit 			[0-9]
identifier 		({letter}|_)({letter}|{digit}|_)*
hexadecimal		0[xX][0-9a-fA-F]+
octal			0[0-7]+
decimal			{digit}+						
delimiter		[ \t\n;+*/\-#<>=!(){}\[\]]|==|!=|<<|>>|->|&&|"||"	
illegal			[^ \t\n;+*/\-#<>=!(){}\[\]&\|]+				

%x comment	

/* rule section */
/****************/
%%

		/* 3.1 strip out comments */
		/**************************/

"/*"					BEGIN(comment);
<comment>[^*]*				/* eat up characters that are not '*'s	 	*/	
<comment>"*"+[^*/]			/* eat up '*'s not followed by '/' or '*'	*/
<comment>"*"+"/"			BEGIN(INITIAL);	/* leave the "comment" env 	*/	


		/* 3.2 convert integers to hexadecimals */
		/****************************************/

{hexadecimal}				printf("0x%x", (unsigned int)strtol(yytext, 0, 16));

{octal}					printf("0x%x", (unsigned int)strtol(yytext, 0, 8));	/* must appear before 'decimal' */

{decimal}				printf("0x%x", (unsigned int)strtol(yytext, 0, 10));


		/* 3.3 convert addressing expressions */
		/**************************************/

{identifier}{whitespace}*"["{whitespace}*"]"	ECHO;						/* don't convert if no expression between */

{identifier}{whitespace}*"["		{
						expr_layer++;					/* count expression layers */
						printf("*(");
						*(yytext+yyleng-1) = '+';
						printf("%s(", yytext);
					}						

"]"					{							/* must appear before 'delimiter' */
						if (expr_layer > 0) {				/* if still in an expression, close it with '))' */
							expr_layer--;
							printf("))");
						}else						/* else do nothing */
							ECHO;
					}


{delimiter}				ECHO;

{illegal}				ECHO;
