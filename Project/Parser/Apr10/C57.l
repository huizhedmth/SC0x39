%{
/* C57.l				
 * 
 * flex source codes that define rules for generating a lexer 
 * for the C57 language
 *
 * author: Huizhe Li, Master Student, Dartmouth College
 *
 * reference: the idea of handling string literal and performing
 * symbol-lookup are borrowed from cscan.l
 */
%}



 /* definition section */
 /**********************/
%{
#include "C57.tab.h"
%}

%x comment
%x string

	/* C- */
white		[ \t\n]+
space		[ \t\n]
_keyword	else|if|int|return|void|while|for|do|double
_symbol		"+"|"-"|"*"|"/"|"<"|"<="|">"|">="|"=="|"!="|"="|";"|","|"("|")"|"["|"]"|"{"|"}"|":"
letter		[a-zA-Z]
digit		[0-9]
id		(_|{letter})(_|{letter}|{digit})*
num		{digit}+

	/* C57 */
fnum		{num}"."{num}|"."{num}
inc		"++"
dec		"--"
mod		"%"
logical		"&&"|"||"|"!"
break		break
continue	continue
sizeof		sizeof
const		const
switch		switch
default		default
case		case

	/* extra credit */
static		static
struct		struct
extern		extern
opeq		"+="|"-="|"*="|"/="
addr		"&"
precmp		"#"
dot		"."
arrow		"->"
nil		nil	

keyword		{_keyword}|{break}|{continue}|{sizeof}|{const}|{switch}|{default}
keyword_ex	{keyword}|{static}|{struct}|{extern}|{nil}
symbol		{_symbol}|{inc}|{dec}|{mod}|{logical}
symbol_ex	{symbol}|{addr}|{opeq}|{precmp}|{dot}|{arrow}

	/* other */
illegal		({digit})(_|{letter}|{digit})+





 /* rule section */
 /****************/
%%

"/*"					BEGIN(comment);
<comment>[^*]*				/* eat up characters that are not '*'s	 	*/	
<comment>"*"+[^*/]			/* eat up '*'s not followed by '/' or '*'	*/
<comment><<EOF>>			{fprintf(stderr, "error: EOF in comment\n");return -1;}
<comment>"*"+"/"			BEGIN(INITIAL);	/* go back to normal state	*/

\"           { BEGIN(string); }
<string>\n   return OTHER;
<string>\\\" { yymore(); }
<string>\"   {
  BEGIN(INITIAL);			/* go back to normal state */
  yytext[--yyleng] = '\0';		/* remove the trailing double-quote */
  return STRING;
 }
<string>.    { yymore(); }

{white}					/* ignore white spaces */
{keyword_ex}				return KWLookup(yytext);
{id}					return ID;
{num}					return NUM;
{illegal}				return ILLEGALID;
{fnum}					return FNUM;
{symbol_ex}				return SMBLookup(yytext);
<<EOF>>					return 0;
.					return OTHER;

 /* user code section */
 /****************/
%%

int KWLookup(char *s) {
  typedef struct KWItem {
    char *keyword;
    int token;
  } KWItem;

  static KWItem keywords[] = {
 	{"else", ELSE},
	{"if", IF},
	{"int", INT},
	{"return", RETURN},
	{"void", VOID},
	{"while", WHILE},
	{"for", FOR},
	{"do", DO},
	{"double", DOUBLE},
	{"break", BREAK},
	{"continue", CONTINUE},
	{"sizeof", SIZEOF},
	{"const", CONST},
	{"switch", SWITCH},
	{"static", STATIC},
	{"struct", STRUCT},
	{"extern", EXTERN},
	{"default", DEFAULT},
	{"case", CASE},
	{"nil", NIL}
 };

  KWItem *kw;

  for (kw = keywords; strcmp(kw->keyword, s) != 0; kw++)
    ;

  return kw->token;
}

int SMBLookup(char *s) {
  typedef struct SMBItem {
    char *symbol;
    int token;
  } SMBItem;

  static SMBItem symbols[] = {
 	{"+", PLUS},
	{"-", MINUS},
	{"*", STAR},
	{"/", DIV},
	{"<", LESS},
	{"<=", LESSEQ},
	{">", GRTER},
	{">=", GRTEREQ},
	{"==", EQ},
	{"!=", NEQ},
	{"=", ASSIGN},
	{";", SEMICOLON},
	{",", COMMA},
	{"(", LBRKT},
	{")", RBRKT},
	{"[", LSQRBRKT},
	{"]", RSQRBRKT},
	{"{", LCLYBRKT},
	{"}", RCLYBRKT},
	{"++", INC},
	{"--", DEC},
	{"%", MOD},
	{"&&", AND},
	{"||", OR},
	{"!", NOT},
	{"+=", PLUSEQ},
	{"-=",  MINUSEQ},
	{"*=", MULEQ},
	{"/=", DIVEQ},
	{"#", PRECMP},
	{"&", ADDR},
	{".", DOT},
	{":", COLON},
	{"->", ARROW}
	
 };

  SMBItem *symb;

  for (symb = symbols; strcmp(symb->symbol, s) != 0; symb++)
    ;

  return symb->token;
}


