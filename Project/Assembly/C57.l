%{
/* C57.l
 *
 * This file contains flex source code that defines rules for generating
 * a lexer for the C57 language.
 *
 * 05/16/2013
 *
 * Modified based on its first version and comments by THC, Dartmouth college.
 *
 * Currently it recognizes tokens just enough to meet the minimum requirements
 * for graduate students.
 * 
 * Reference: the methods of processing string literal and keyword-lookup came from
 * cscan.l, THC, Dartmouth college.
 *
 * by Huizhe Li, Master Student, Dartmouth College
 */
%}


%{
#include "C57.tab.h"
#include <string.h>

#define MAXTOKENLEN 200

int KWLookup(char* s);
int SYMBLookup(char* s);
int lineNumber = 1;

char savedIdText[MAXTOKENLEN];
char savedLiteralText[MAXTOKENLEN];
%}

%x string

white		[ \t]+
newline		\n
letter		[a-zA-Z]
digit		[0-9]
id		(_|{letter})(_|{letter}|{digit})*
sngl_char_symb	"+"|"-"|"*"|"/"|"<"|">"|"="|";"|","|"("|")"|"["|"]"|"{"|"}"|"%"|"!"|":"
dbl_char_symb	"<="|">="|"=="|"!="|"++"|"--"|"&&"|"||"
num		{digit}+
fnum		{num}"."{num}|"."{num}

illegal		({digit})(_|{letter}|{digit})+

 /* rule section */
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


\"          	 { BEGIN(string); }
<string>\n 	  return OTHER;
<string>\\\"	 { yymore(); }
<string>\"   	 {
		  BEGIN(INITIAL);			/* go back to normal state */
 		  yytext[--yyleng] = '\0';		/* remove the trailing double-quote */
		  strcpy(savedLiteralText, yytext);
		  return STRING;
		 }
<string>.    	 { yymore(); }


{newline}      		lineNumber++;
{white}			/* ignore white spaces */
{id}			{int ret = KWLookup(yytext);
			 strcpy(savedIdText, yytext);
			 return ret;
			 }	/* may return a keyword or token ID */
{sngl_char_symb} 	{return (int)yytext[0];}		/* return ASCII code directly */
{dbl_char_symb}		{return SYMBLookup(yytext);}	
{num}			{strcpy(savedLiteralText, yytext);return NUM;}
{fnum}			{strcpy(savedLiteralText, yytext);return FNUM;}
{illegal}		{return OTHER;}
<<EOF>>			{return 0;}

.			{return OTHER;}


 /* user code */
%%

int KWLookup(char* s)
{
  typedef struct KWItem {
    char* keyword;
    int token;
  } KWItem;

  static KWItem keywords[] = {
    {"if", IF},
    {"else", ELSE},
    {"int", INT},
    {"return", RETURN},
    {"void", VOID},
    {"while", WHILE},
    {"for", FOR},
    {"do", DO},
    {"double", DOUBLE},
    {"read", READ},
    {"print", PRINT},
    {"break", BREAK},
    {"continue", CONTINUE},
    {"switch", SWITCH},
    {"case", CASE},
    {"default", DEFAULT},
    {"sizeof", SIZEOF},
    {"const", CONST},
    {"place_holder", ID}
  };

  int table_length = 19;
  keywords[table_length-1].keyword = s;
  KWItem* kw;

  for (kw = keywords; strcmp(kw->keyword, s)!=0; kw++)
    ;
 
  return kw->token;
}

int SYMBLookup(char* s)
{
  typedef struct SYMBItem {
    char* symbol;
    int token;
  } SYMBItem;

  static SYMBItem symbols[] = {
    {"<=", LESSEQ},
    {">=", GRTEREQ},
    {"==", EQ},
    {"!=", NEQ},
    {"++", INC},
    {"--", DEC},
    {"&&", AND},
    {"||", OR}
  };

  SYMBItem* symbol;

  for (symbol = symbols; strcmp(symbol->symbol, s)!=0; symbol++) /* guaranteed to be found */
    ;

  return symbol->token;
}
