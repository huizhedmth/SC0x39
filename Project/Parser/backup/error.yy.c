/* error.yy.c
 *
 * define yyerror() for yyparse 
 *
 * author: Huizhe Li, Master Student, Dartmouth College
 *
 */

#include <stdio.h>

void yyerror (char const *s)
{
	fprintf (stderr, "%s\n", s);
}
