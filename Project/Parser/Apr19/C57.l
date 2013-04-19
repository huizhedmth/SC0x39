%{
/* C57.l				
 * 
 * Flex source codes that define rules for generating a lexer 
 * for the C57 language
 *
 * By Huizhe Li, Master Student, Dartmouth College
 *
 * Reference: 
 * 
 * the idea of handling string literal and performing
 * symbol-lookup are borrowed from cscan.l
 * 
 * comments handling are borrowed from codes by Professor Cormen, Dartmouth College.
 */
%}



 /* definition section */
 /**********************/
%{
#include "C57.tab.h"
#include <string.h>

int lineNumber = 1;

#define MAXTOKENLENGTH 201
#define MAXSTRLENGTH 201

char savedIdText[MAXTOKENLENGTH];
char savedLiteralText[MAXTOKENLENGTH];
char savedKwText[MAXTOKENLENGTH];	/* for type info */
char savedStrText[MAXSTRLENGTH];	/* for string literals */
%}

%x string

	/* C- */
white		[ \t]+
space		[ \t]
newline		\n
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
read		read
print		print

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

keyword		{_keyword}|{break}|{continue}|{sizeof}|{const}|{switch}|{case}|{default}|{read}|{print}
keyword_ex	{keyword}|{static}|{struct}|{extern}|{nil}
symbol		{_symbol}|{inc}|{dec}|{mod}|{logical}
symbol_ex	{symbol}|{addr}|{opeq}|{precmp}|{dot}|{arrow}

	/* other */
illegal		({digit})(_|{letter}|{digit})+





 /* rule section */
 /****************/
%%

"/""*"          {
                  int prevChar = '\0', thisChar;
		  for ( ; ; ) {
		    if ((thisChar = input()) == EOF) {
		      fprintf(stderr, "EOF in comment\n");
		      return 0;
		    }
		    else if (thisChar == '/' && prevChar == '*')
		      break;
		    else {
		      if (thisChar == '\n') lineNumber++;
		      prevChar = thisChar;
		    }
		  }
                }

\"           { BEGIN(string); }
<string>\n   return OTHER;
<string>\\\" { yymore(); }
<string>\"   {
  BEGIN(INITIAL);			/* go back to normal state */
  yytext[--yyleng] = '\0';		/* remove the trailing double-quote */
  strncpy(savedStrText, yytext, MAXSTRLENGTH-1);
  return STRING;
 }
<string>.    { yymore(); }

{newline}				lineNumber++;
{white}					/* ignore white spaces */
{keyword_ex}				{	strncpy(savedKwText, yytext, MAXTOKENLENGTH-1);
						return KWLookup(yytext);}
{id}					{	strncpy(savedIdText, yytext, MAXTOKENLENGTH-1);
    						return ID;}
{num}					{	strncpy(savedLiteralText, yytext, MAXTOKENLENGTH-1);
						return NUM;}
{illegal}				return ILLEGALID;
{fnum}					{	strncpy(savedLiteralText, yytext, MAXTOKENLENGTH-1);
						return FNUM;}
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
	{"nil", NIL},
	{"read", READ},
	{"print", PRINT}
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


