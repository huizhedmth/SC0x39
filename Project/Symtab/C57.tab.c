/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ELSE = 258,
     IF = 259,
     INT = 260,
     RETURN = 261,
     VOID = 262,
     WHILE = 263,
     FOR = 264,
     DO = 265,
     DOUBLE = 266,
     BREAK = 267,
     CONTINUE = 268,
     CONST = 269,
     SWITCH = 270,
     STATIC = 271,
     STRUCT = 272,
     EXTERN = 273,
     DEFAULT = 274,
     CASE = 275,
     NIL = 276,
     READ = 277,
     PRINT = 278,
     SEMICOLON = 279,
     LBRKT = 280,
     RBRKT = 281,
     LSQRBRKT = 282,
     RSQRBRKT = 283,
     LCLYBRKT = 284,
     RCLYBRKT = 285,
     PRECMP = 286,
     COLON = 287,
     INC = 288,
     DEC = 289,
     ID = 290,
     NUM = 291,
     FNUM = 292,
     STRING = 293,
     ILLEGALID = 294,
     OTHER = 295,
     COMMA = 296,
     DIVEQ = 297,
     MULEQ = 298,
     MINUSEQ = 299,
     PLUSEQ = 300,
     ASSIGN = 301,
     OR = 302,
     AND = 303,
     NEQ = 304,
     EQ = 305,
     GRTEREQ = 306,
     GRTER = 307,
     LESSEQ = 308,
     LESS = 309,
     MINUS = 310,
     PLUS = 311,
     MOD = 312,
     DIV = 313,
     STAR = 314,
     SIZEOF = 315,
     DECPRE = 316,
     INCPRE = 317,
     NOT = 318,
     UMINUS = 319,
     DEREF = 320,
     ADDR = 321,
     DECPOST = 322,
     INCPOST = 323,
     DOT = 324,
     ARROW = 325
   };
#endif
/* Tokens.  */
#define ELSE 258
#define IF 259
#define INT 260
#define RETURN 261
#define VOID 262
#define WHILE 263
#define FOR 264
#define DO 265
#define DOUBLE 266
#define BREAK 267
#define CONTINUE 268
#define CONST 269
#define SWITCH 270
#define STATIC 271
#define STRUCT 272
#define EXTERN 273
#define DEFAULT 274
#define CASE 275
#define NIL 276
#define READ 277
#define PRINT 278
#define SEMICOLON 279
#define LBRKT 280
#define RBRKT 281
#define LSQRBRKT 282
#define RSQRBRKT 283
#define LCLYBRKT 284
#define RCLYBRKT 285
#define PRECMP 286
#define COLON 287
#define INC 288
#define DEC 289
#define ID 290
#define NUM 291
#define FNUM 292
#define STRING 293
#define ILLEGALID 294
#define OTHER 295
#define COMMA 296
#define DIVEQ 297
#define MULEQ 298
#define MINUSEQ 299
#define PLUSEQ 300
#define ASSIGN 301
#define OR 302
#define AND 303
#define NEQ 304
#define EQ 305
#define GRTEREQ 306
#define GRTER 307
#define LESSEQ 308
#define LESS 309
#define MINUS 310
#define PLUS 311
#define MOD 312
#define DIV 313
#define STAR 314
#define SIZEOF 315
#define DECPRE 316
#define INCPRE 317
#define NOT 318
#define UMINUS 319
#define DEREF 320
#define ADDR 321
#define DECPOST 322
#define INCPOST 323
#define DOT 324
#define ARROW 325




/* Copy the first part of user declarations.  */
#line 11 "C57.y"

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



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 273 "C57.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   486

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNRULES -- Number of states.  */
#define YYNSTATES  206

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   325

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    21,
      26,    30,    32,    34,    38,    40,    42,    43,    48,    49,
      55,    56,    63,    64,    71,    74,    77,    79,    81,    82,
      86,    88,    91,    93,    98,   102,   107,   110,   111,   114,
     115,   117,   119,   121,   123,   125,   127,   129,   131,   133,
     135,   137,   139,   141,   143,   146,   148,   154,   162,   168,
     176,   180,   188,   190,   191,   194,   198,   202,   206,   210,
     214,   216,   218,   219,   225,   229,   233,   237,   241,   245,
     249,   253,   257,   261,   265,   269,   273,   277,   280,   283,
     285,   288,   291,   294,   297,   301,   303,   305,   307,   309,
     310,   316,   318,   319,   323,   325,   328,   331,   336,   340,
     346,   351
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      72,     0,    -1,    73,    -1,    73,    74,    -1,    74,    -1,
      75,    -1,    84,    -1,    85,    -1,    14,    76,    77,    24,
      -1,    76,    14,    77,    24,    -1,    76,    77,    24,    -1,
       5,    -1,    11,    -1,    77,    41,    78,    -1,    78,    -1,
      35,    -1,    -1,    35,    79,    46,   103,    -1,    -1,    35,
      80,    27,   103,    28,    -1,    -1,    76,    35,    82,    25,
      86,    26,    -1,    -1,     7,    35,    83,    25,    86,    26,
      -1,    81,    89,    -1,    81,    24,    -1,    87,    -1,     7,
      -1,    -1,    87,    41,    88,    -1,    88,    -1,    76,    35,
      -1,    76,    -1,    76,    35,    27,    28,    -1,    76,    27,
      28,    -1,    29,    90,    91,    30,    -1,    90,    75,    -1,
      -1,    91,    92,    -1,    -1,    93,    -1,    89,    -1,    94,
      -1,    95,    -1,    96,    -1,    97,    -1,   100,    -1,   101,
      -1,   102,    -1,   111,    -1,   112,    -1,   115,    -1,   113,
      -1,   114,    -1,   103,    24,    -1,    24,    -1,     4,    25,
     103,    26,    92,    -1,     4,    25,   103,    26,    92,     3,
      92,    -1,     8,    25,   103,    26,    92,    -1,    10,    92,
       8,    25,   103,    26,    24,    -1,     9,    98,    92,    -1,
      25,    99,    24,    99,    24,    99,    26,    -1,   103,    -1,
      -1,     6,    24,    -1,     6,   103,    24,    -1,    22,   104,
      24,    -1,    23,   103,    24,    -1,    23,    38,    24,    -1,
     104,    46,   103,    -1,   106,    -1,    35,    -1,    -1,    35,
     105,    27,   103,    28,    -1,   103,    56,   103,    -1,   103,
      55,   103,    -1,   103,    59,   103,    -1,   103,    58,   103,
      -1,   103,    57,   103,    -1,   103,    54,   103,    -1,   103,
      53,   103,    -1,   103,    52,   103,    -1,   103,    51,   103,
      -1,   103,    50,   103,    -1,   103,    49,   103,    -1,   103,
      48,   103,    -1,   103,    47,   103,    -1,    63,   103,    -1,
      55,   103,    -1,   104,    -1,    33,   104,    -1,    34,   104,
      -1,   104,    33,    -1,   104,    34,    -1,    25,   103,    26,
      -1,   107,    -1,    36,    -1,    37,    -1,   116,    -1,    -1,
      35,   108,    25,   109,    26,    -1,   110,    -1,    -1,   110,
      41,   103,    -1,   103,    -1,    12,    24,    -1,    13,    24,
      -1,    20,    36,    32,    92,    -1,    19,    32,    92,    -1,
      15,    25,   103,    26,    92,    -1,    60,    25,    76,    26,
      -1,    60,    25,   103,    26,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   100,   100,   107,   118,   121,   122,   123,   126,   132,
     138,   146,   151,   158,   168,   171,   176,   176,   184,   184,
     199,   199,   207,   207,   218,   226,   233,   234,   235,   239,
     249,   253,   263,   271,   285,   300,   315,   325,   328,   338,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   357,   358,   361,   367,   377,   385,
     393,   402,   413,   414,   417,   421,   428,   435,   440,   449,
     455,   458,   463,   463,   478,   484,   490,   496,   502,   508,
     514,   520,   526,   532,   538,   544,   550,   556,   561,   566,
     569,   574,   579,   584,   589,   590,   591,   596,   601,   604,
     604,   616,   617,   620,   630,   633,   639,   645,   653,   660,
     667,   672
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ELSE", "IF", "INT", "RETURN", "VOID",
  "WHILE", "FOR", "DO", "DOUBLE", "BREAK", "CONTINUE", "CONST", "SWITCH",
  "STATIC", "STRUCT", "EXTERN", "DEFAULT", "CASE", "NIL", "READ", "PRINT",
  "SEMICOLON", "LBRKT", "RBRKT", "LSQRBRKT", "RSQRBRKT", "LCLYBRKT",
  "RCLYBRKT", "PRECMP", "COLON", "INC", "DEC", "ID", "NUM", "FNUM",
  "STRING", "ILLEGALID", "OTHER", "COMMA", "DIVEQ", "MULEQ", "MINUSEQ",
  "PLUSEQ", "ASSIGN", "OR", "AND", "NEQ", "EQ", "GRTEREQ", "GRTER",
  "LESSEQ", "LESS", "MINUS", "PLUS", "MOD", "DIV", "STAR", "SIZEOF",
  "DECPRE", "INCPRE", "NOT", "UMINUS", "DEREF", "ADDR", "DECPOST",
  "INCPOST", "DOT", "ARROW", "$accept", "program", "declaration_list",
  "declaration", "var_declaration", "type_specifier", "var_decl_list",
  "var_decl", "@1", "@2", "func_header", "@3", "@4", "func_declaration",
  "func_prototype", "formal_params", "formal_list", "formal_param",
  "compound_statement", "local_declarations", "statement_list",
  "statement", "expression_statement", "if_statement", "while_statement",
  "do_while_statement", "for_statement", "for_header",
  "for_header_expression", "return_statement", "read_statement",
  "print_statement", "expression", "var", "@5", "r_value", "call", "@6",
  "args", "arg_list", "break_statement", "continue_statement",
  "case_statement", "default_statement", "switch_statement",
  "sizeof_expression", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    73,    73,    74,    74,    74,    75,    75,
      75,    76,    76,    77,    77,    78,    79,    78,    80,    78,
      82,    81,    83,    81,    84,    85,    86,    86,    86,    87,
      87,    88,    88,    88,    88,    89,    90,    90,    91,    91,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    93,    93,    94,    94,    95,    96,
      97,    98,    99,    99,   100,   100,   101,   102,   102,   103,
     103,   104,   105,   104,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   108,
     107,   109,   109,   110,   110,   111,   112,   113,   114,   115,
     116,   116
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     4,     4,
       3,     1,     1,     3,     1,     1,     0,     4,     0,     5,
       0,     6,     0,     6,     2,     2,     1,     1,     0,     3,
       1,     2,     1,     4,     3,     4,     2,     0,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     5,     7,     5,     7,
       3,     7,     1,     0,     2,     3,     3,     3,     3,     3,
       1,     1,     0,     5,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     1,
       2,     2,     2,     2,     3,     1,     1,     1,     1,     0,
       5,     1,     0,     3,     1,     2,     2,     4,     3,     5,
       4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    11,     0,    12,     0,     0,     2,     4,     5,     0,
       0,     6,     7,    22,     0,     1,     3,     0,    15,     0,
      14,    25,    37,    24,     0,    15,     0,     0,     0,     0,
       0,    10,     0,    39,    28,     8,     9,     0,     0,    28,
      13,    36,     0,     0,    27,    32,     0,    26,    30,     0,
       0,     0,    71,    96,    97,     0,     0,     0,    17,    89,
      70,    95,    98,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,    35,    41,
      38,    40,    42,    43,    44,    45,    46,    47,    48,     0,
      49,    50,    52,    53,    51,     0,    31,    23,     0,     0,
      71,    90,    91,     0,     0,    88,     0,    87,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,    93,     0,    19,    21,     0,    64,     0,     0,
      63,     0,     0,   105,   106,     0,     0,     0,     0,     0,
       0,    54,    34,     0,    29,    94,     0,   102,     0,     0,
      86,    85,    84,    83,    82,    81,    80,    79,    75,    74,
      78,    77,    76,    69,     0,    65,     0,     0,    62,    60,
       0,     0,   108,     0,    66,    68,    67,    33,     0,   104,
       0,   101,   110,   111,     0,     0,    63,     0,     0,   107,
      73,   100,     0,    56,    58,     0,     0,   109,   103,     0,
      63,     0,    57,     0,    59,    61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    45,    19,    20,    28,    29,
      10,    30,    24,    11,    12,    46,    47,    48,    79,    33,
      43,    80,    81,    82,    83,    84,    85,   131,   167,    86,
      87,    88,    89,    59,   103,    60,    61,   104,   180,   181,
      90,    91,    92,    93,    94,    62
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -160
static const yytype_int16 yypact[] =
{
      46,  -160,   -30,  -160,    35,    16,    46,  -160,  -160,    -7,
      82,  -160,  -160,  -160,    -2,  -160,  -160,    -2,   -10,   -20,
    -160,  -160,  -160,  -160,    29,    -8,     6,     7,    12,    41,
      62,  -160,    -2,    45,    56,  -160,  -160,    66,    66,    56,
    -160,  -160,    -3,   152,  -160,    10,    36,    64,  -160,    66,
      85,    85,    39,  -160,  -160,    66,    72,    66,   395,     9,
    -160,  -160,  -160,   367,    91,    98,   -11,    99,   100,   210,
     103,   104,   105,   106,    95,    85,   216,  -160,  -160,  -160,
    -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,   144,
    -160,  -160,  -160,  -160,  -160,   107,   109,  -160,    35,   267,
     110,  -160,  -160,   113,   116,  -160,    79,  -160,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,  -160,  -160,    66,  -160,  -160,    66,  -160,   233,    66,
      66,   210,   124,  -160,  -160,    66,   210,   119,   128,   129,
     248,  -160,  -160,   120,  -160,  -160,    66,    66,   131,   282,
     407,   418,   427,   427,    88,    88,    88,    88,    37,    37,
    -160,  -160,  -160,   395,   301,  -160,   316,   130,   395,  -160,
     134,   335,  -160,   210,  -160,  -160,  -160,  -160,   382,   395,
     140,   132,  -160,  -160,   210,   210,    66,    66,   210,  -160,
    -160,  -160,    66,   166,  -160,   146,   350,  -160,   395,   210,
      66,   154,  -160,   153,  -160,  -160
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -160,  -160,  -160,   174,   150,     2,    71,   158,  -160,  -160,
    -160,  -160,  -160,  -160,  -160,   145,  -160,   108,   194,  -160,
    -160,   -66,  -160,  -160,  -160,  -160,  -160,  -160,  -159,  -160,
    -160,  -160,   -37,   -41,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,  -160,  -160,  -160,  -160,  -160
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -100
static const yytype_int16 yytable[] =
{
      58,    63,     9,   132,    31,    13,    14,    17,     9,   101,
     102,    17,    99,   127,    49,   -20,    15,   -18,   105,   -18,
     107,    32,    50,    51,    52,    53,    54,   195,    18,   128,
      35,    36,    25,    25,   138,    42,   -16,    95,   -16,   140,
       1,   203,   121,   122,    55,    96,     3,    32,    32,    56,
       1,     1,    57,     2,    34,   123,     3,     3,    37,     4,
       4,     1,    97,    44,   -99,   169,   -72,     3,    38,   149,
     172,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,     1,    26,   163,    39,    27,   164,
       3,    49,   166,   168,   118,   119,   120,   106,   171,    50,
      51,    52,    53,    54,    49,    98,    21,   189,   148,   178,
     179,    22,    50,    51,    52,    53,    54,   125,   193,   194,
     100,    55,   197,   126,   129,   130,    56,   133,   134,    57,
     135,   137,   170,   202,    55,   142,   143,   -72,   136,    56,
     146,   147,    57,   116,   117,   118,   119,   120,   177,   168,
     196,   173,   174,   175,   186,   198,    65,   182,    66,   187,
      67,    68,    69,   168,    70,    71,   191,    72,   141,   199,
     200,    73,    74,   192,    75,    76,    77,    49,   204,   205,
      16,    22,    78,    41,    64,    50,    51,    52,    53,    54,
      40,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    23,     0,   144,    55,     0,     0,
       0,     0,    56,     0,    65,    57,    66,     0,    67,    68,
      69,     0,    70,    71,     0,    72,     0,     0,     0,    73,
      74,     0,    75,    76,    77,    49,     0,     0,     0,    22,
       0,    49,     0,    50,    51,    52,    53,    54,     0,    50,
      51,    52,    53,    54,   139,     0,     0,   165,     0,     0,
       0,     0,     0,     0,     0,    55,     0,     0,     0,     0,
      56,    55,   176,    57,     0,     0,    56,     0,     0,    57,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   145,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   183,     0,
       0,     0,     0,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   184,     0,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   185,     0,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   188,     0,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   201,     0,     0,     0,
       0,     0,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   124,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     190,     0,     0,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   112,   113,
     114,   115,   116,   117,   118,   119,   120
};

static const yytype_int16 yycheck[] =
{
      37,    38,     0,    69,    24,    35,     4,    14,     6,    50,
      51,    14,    49,    24,    25,    25,     0,    27,    55,    27,
      57,    41,    33,    34,    35,    36,    37,   186,    35,    66,
      24,    24,    35,    35,    75,    33,    46,    27,    46,    76,
       5,   200,    33,    34,    55,    35,    11,    41,    41,    60,
       5,     5,    63,     7,    25,    46,    11,    11,    46,    14,
      14,     5,    26,     7,    25,   131,    27,    11,    27,   106,
     136,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,     5,    14,   123,    25,    17,   126,
      11,    25,   129,   130,    57,    58,    59,    25,   135,    33,
      34,    35,    36,    37,    25,    41,    24,   173,   106,   146,
     147,    29,    33,    34,    35,    36,    37,    26,   184,   185,
      35,    55,   188,    25,    25,    25,    60,    24,    24,    63,
      25,    36,     8,   199,    55,    28,    27,    27,    32,    60,
      27,    25,    63,    55,    56,    57,    58,    59,    28,   186,
     187,    32,    24,    24,    24,   192,     4,    26,     6,    25,
       8,     9,    10,   200,    12,    13,    26,    15,    24,     3,
      24,    19,    20,    41,    22,    23,    24,    25,    24,    26,
       6,    29,    30,    33,    39,    33,    34,    35,    36,    37,
      32,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    10,    -1,    98,    55,    -1,    -1,
      -1,    -1,    60,    -1,     4,    63,     6,    -1,     8,     9,
      10,    -1,    12,    13,    -1,    15,    -1,    -1,    -1,    19,
      20,    -1,    22,    23,    24,    25,    -1,    -1,    -1,    29,
      -1,    25,    -1,    33,    34,    35,    36,    37,    -1,    33,
      34,    35,    36,    37,    38,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,
      60,    55,    24,    63,    -1,    -1,    60,    -1,    -1,    63,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    26,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    26,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    26,    -1,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    26,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    26,    -1,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    26,    -1,    -1,    -1,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    28,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      28,    -1,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    51,    52,
      53,    54,    55,    56,    57,    58,    59
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     7,    11,    14,    72,    73,    74,    75,    76,
      81,    84,    85,    35,    76,     0,    74,    14,    35,    77,
      78,    24,    29,    89,    83,    35,    77,    77,    79,    80,
      82,    24,    41,    90,    25,    24,    24,    46,    27,    25,
      78,    75,    76,    91,     7,    76,    86,    87,    88,    25,
      33,    34,    35,    36,    37,    55,    60,    63,   103,   104,
     106,   107,   116,   103,    86,     4,     6,     8,     9,    10,
      12,    13,    15,    19,    20,    22,    23,    24,    30,    89,
      92,    93,    94,    95,    96,    97,   100,   101,   102,   103,
     111,   112,   113,   114,   115,    27,    35,    26,    41,   103,
      35,   104,   104,   105,   108,   103,    25,   103,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    33,    34,    46,    28,    26,    25,    24,   103,    25,
      25,    98,    92,    24,    24,    25,    32,    36,   104,    38,
     103,    24,    28,    27,    88,    26,    27,    25,    76,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,    24,   103,    99,   103,    92,
       8,   103,    92,    32,    24,    24,    24,    28,   103,   103,
     109,   110,    26,    26,    26,    26,    24,    25,    26,    92,
      28,    26,    41,    92,    92,    99,   103,    92,   103,     3,
      24,    26,    92,    99,    24,    26
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 100 "C57.y"
    {
				ast_node t = create_ast_node(ROOT);
  				t->left_child = (yyvsp[(1) - (1)]);
 				root = (yyval) = t; 
			;}
    break;

  case 3:
#line 107 "C57.y"
    {		
				/* standard solution to recursive lists */	
  				ast_node t = (yyvsp[(1) - (2)]);
 				if (t != NULL) {
   					while (t->right_sibling != NULL)
       						t = t->right_sibling;
     					t->right_sibling = (yyvsp[(2) - (2)]);
   					(yyval) = (yyvsp[(1) - (2)]);
  				}else
					(yyval) = (yyvsp[(2) - (2)]);
			;}
    break;

  case 4:
#line 118 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 5:
#line 121 "C57.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 6:
#line 122 "C57.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 7:
#line 123 "C57.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 8:
#line 126 "C57.y"
    {
				ast_node t = create_ast_node(VAR_DECL);
				t->left_child = (yyvsp[(2) - (4)]);
				t->left_child->right_sibling = (yyvsp[(3) - (4)]);
				(yyval) = t;
			;}
    break;

  case 9:
#line 132 "C57.y"
    {
				ast_node t = create_ast_node(VAR_DECL);
				t->left_child = (yyvsp[(1) - (4)]);
				t->left_child->right_sibling = (yyvsp[(3) - (4)]);
				(yyval) = t;
			;}
    break;

  case 10:
#line 138 "C57.y"
    {
				ast_node t = create_ast_node(VAR_DECL);
				t->left_child = (yyvsp[(1) - (3)]);
				t->left_child->right_sibling = (yyvsp[(2) - (3)]);
				(yyval) = t;
			;}
    break;

  case 11:
#line 146 "C57.y"
    {
				ast_node t = create_ast_node(TYPE);	/* save type info */
				t->value.string = strdup(savedKwText);
				(yyval) = t;
			;}
    break;

  case 12:
#line 151 "C57.y"
    {
				ast_node t = create_ast_node(TYPE);
				t->value.string = strdup(savedKwText);
				(yyval) = t;
			;}
    break;

  case 13:
#line 158 "C57.y"
    {
  				ast_node t = (yyvsp[(1) - (3)]);
 				if (t != NULL) {
   					while (t->right_sibling != NULL)
       						t = t->right_sibling;
     					t->right_sibling = (yyvsp[(3) - (3)]);
   					(yyval) = (yyvsp[(1) - (3)]);
  				}else
					(yyval) = (yyvsp[(3) - (3)]);
			;}
    break;

  case 14:
#line 168 "C57.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 15:
#line 171 "C57.y"
    {
				ast_node t = create_ast_node(IDENT);
				t->value.string = retrieve_id(the_id_table, savedIdText);
				(yyval) = t;
			;}
    break;

  case 16:
#line 176 "C57.y"
    {
				ast_node t = create_ast_node(IDENT);
				t->value.string = retrieve_id(the_id_table, savedIdText);
				(yyvsp[(1) - (1)]) = t;
			;}
    break;

  case 17:
#line 180 "C57.y"
    {
				(yyvsp[(1) - (4)])->left_child = (yyvsp[(4) - (4)]);
				(yyval) = (yyvsp[(1) - (4)]);
			;}
    break;

  case 18:
#line 184 "C57.y"
    {
				ast_node t = create_ast_node(IDENT);
				char* tmp = (char*)malloc(strlen(savedIdText)+3);
				strcat(tmp, savedIdText);
				strcat(tmp, "[]");
				tmp = retrieve_id(the_id_table, tmp);
				t->value.string = tmp;
				(yyvsp[(1) - (1)]) = t;
			;}
    break;

  case 19:
#line 192 "C57.y"
    {
				(yyvsp[(1) - (5)])->left_child = (yyvsp[(4) - (5)]);
				(yyval) = (yyvsp[(1) - (5)]);
			;}
    break;

  case 20:
#line 199 "C57.y"
    {
				ast_node t = create_ast_node(FUNC_HEADER);
				t->value.string = retrieve_id(the_id_table, savedIdText);
				(yyval) = t;
			;}
    break;

  case 21:
#line 203 "C57.y"
    {
				(yyval) = (yyvsp[(3) - (6)]);
				(yyval)->left_child = (yyvsp[(5) - (6)]);
			;}
    break;

  case 22:
#line 207 "C57.y"
    {
				ast_node t = create_ast_node(FUNC_HEADER);
				t->value.string = retrieve_id(the_id_table, savedIdText);
				(yyval) = t;
			;}
    break;

  case 23:
#line 211 "C57.y"
    {
				(yyval) = (yyvsp[(3) - (6)]);
				(yyval)->left_child = (yyvsp[(5) - (6)]);
			;}
    break;

  case 24:
#line 218 "C57.y"
    {
				ast_node t = create_ast_node(FUNC_DECL);
				t->left_child = (yyvsp[(1) - (2)]);
				t->left_child->right_sibling = (yyvsp[(2) - (2)]);
				(yyval) = t;
			;}
    break;

  case 25:
#line 226 "C57.y"
    {
				ast_node t = create_ast_node(FUNC_PROTO);
				t->left_child = (yyvsp[(1) - (2)]);
				(yyval) = t;
			;}
    break;

  case 26:
#line 233 "C57.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 27:
#line 234 "C57.y"
    { (yyval) = NULL;;}
    break;

  case 28:
#line 235 "C57.y"
    { (yyval) = NULL;;}
    break;

  case 29:
#line 239 "C57.y"
    {
  				ast_node t = (yyvsp[(1) - (3)]);
 				if (t != NULL) {
   					while (t->right_sibling != NULL)
       						t = t->right_sibling;
     					t->right_sibling = (yyvsp[(3) - (3)]);
   					(yyval) = (yyvsp[(1) - (3)]);
  				}else
					(yyval) = (yyvsp[(3) - (3)]);
			;}
    break;

  case 30:
#line 249 "C57.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 31:
#line 253 "C57.y"
    {
				ast_node t1 = create_ast_node(TYPE);
				t1->value.string = strdup(savedKwText);	/* save type info */
				ast_node t2 = create_ast_node(IDENT);
				t2->value.string = retrieve_id(the_id_table, savedIdText);
				ast_node t = create_ast_node(FORMAL_PARAM);
				t->left_child = t1;
				t->left_child->right_sibling = t2;
				(yyval) = t;
			;}
    break;

  case 32:
#line 263 "C57.y"
    {
				ast_node t = create_ast_node(FORMAL_PARAM);
				ast_node t1 = create_ast_node(TYPE);
				t1->value.string = strdup(savedKwText);
				t->left_child = t1;
				(yyval) = t;
			;}
    break;

  case 33:
#line 271 "C57.y"
    {
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
				(yyval) = t;
			;}
    break;

  case 34:
#line 285 "C57.y"
    {
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
				(yyval) = t;
			;}
    break;

  case 35:
#line 300 "C57.y"
    {
				ast_node t = create_ast_node(CMPD_STMT);
				ast_node t1 = create_ast_node(LOCAL_DECL);
				if ((yyvsp[(2) - (4)]) != NULL){
					t1->left_child= (yyvsp[(2) - (4)]);
					t->left_child = t1;
					t->left_child->right_sibling = (yyvsp[(3) - (4)]);
				}else{
					t1 = NULL;
					t->left_child = (yyvsp[(3) - (4)]);
				}
				(yyval) = t;
			;}
    break;

  case 36:
#line 315 "C57.y"
    {
  				ast_node t = (yyvsp[(1) - (2)]);
 				if (t != NULL) {
   					while (t->right_sibling != NULL)
       						t = t->right_sibling;
     					t->right_sibling = (yyvsp[(2) - (2)]);
   					(yyval) = (yyvsp[(1) - (2)]);
  				}else
					(yyval) = (yyvsp[(2) - (2)]);
			;}
    break;

  case 37:
#line 325 "C57.y"
    { (yyval) = NULL;;}
    break;

  case 38:
#line 328 "C57.y"
    {
  				ast_node t = (yyvsp[(1) - (2)]);
 				if (t != NULL) {
   					while (t->right_sibling != NULL)
       						t = t->right_sibling;
     					t->right_sibling = (yyvsp[(2) - (2)]);
   					(yyval) = (yyvsp[(1) - (2)]);
  				}else
					(yyval) = (yyvsp[(2) - (2)]);
			;}
    break;

  case 39:
#line 338 "C57.y"
    {(yyval) = NULL;;}
    break;

  case 40:
#line 341 "C57.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 41:
#line 342 "C57.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 42:
#line 343 "C57.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 43:
#line 344 "C57.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 44:
#line 345 "C57.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 45:
#line 346 "C57.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 46:
#line 347 "C57.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 47:
#line 348 "C57.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 48:
#line 349 "C57.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 49:
#line 350 "C57.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 50:
#line 351 "C57.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 51:
#line 352 "C57.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 52:
#line 353 "C57.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 53:
#line 354 "C57.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 54:
#line 357 "C57.y"
    {(yyval) = (yyvsp[(1) - (2)]);;}
    break;

  case 55:
#line 358 "C57.y"
    {(yyval) = create_ast_node(EMPTY_STMT);;}
    break;

  case 56:
#line 361 "C57.y"
    {
				ast_node t = create_ast_node(IF_STMT);
				t->left_child = (yyvsp[(3) - (5)]);
				t->left_child->right_sibling = (yyvsp[(5) - (5)]);
				(yyval) = t;
			;}
    break;

  case 57:
#line 367 "C57.y"
    {
				ast_node t = create_ast_node(IF_ELSE_STMT);
				t->left_child = (yyvsp[(3) - (7)]);
				t->left_child->right_sibling = (yyvsp[(5) - (7)]);
				t->left_child->right_sibling->right_sibling = (yyvsp[(7) - (7)]);
				(yyval) = t;
			;}
    break;

  case 58:
#line 377 "C57.y"
    {
				ast_node t = create_ast_node(WHILE_STMT);
				t->left_child = (yyvsp[(3) - (5)]);
				t->left_child->right_sibling = (yyvsp[(5) - (5)]);
				(yyval) = t;
			;}
    break;

  case 59:
#line 385 "C57.y"
    {
				ast_node t = create_ast_node(DO_WHILE_STMT);
				t->left_child = (yyvsp[(5) - (7)]);	/* set first child to be the loop condition */
				t->left_child->right_sibling = (yyvsp[(2) - (7)]);
				(yyval) = t;
			;}
    break;

  case 60:
#line 393 "C57.y"
    {
				ast_node t = create_ast_node(FOR_STMT);
				t->left_child = (yyvsp[(2) - (3)]);
				/* this is guaranteed not to dereference a null pointer, see rule "for_header" below */
				t->left_child->right_sibling->right_sibling->right_sibling = (yyvsp[(3) - (3)]);
				(yyval) = t;
			;}
    break;

  case 61:
#line 402 "C57.y"
    {
				/* hold place for empty for_header_expression */
				if((yyvsp[(2) - (7)]) == NULL)(yyvsp[(2) - (7)]) = create_ast_node(BOZO);
				if((yyvsp[(4) - (7)]) == NULL)(yyvsp[(4) - (7)]) = create_ast_node(BOZO);				
				if((yyvsp[(6) - (7)]) == NULL)(yyvsp[(6) - (7)]) = create_ast_node(BOZO);						
				(yyval) = (yyvsp[(2) - (7)]);
				(yyval)->right_sibling = (yyvsp[(4) - (7)]);
				(yyval)->right_sibling->right_sibling = (yyvsp[(6) - (7)]);		
			;}
    break;

  case 62:
#line 413 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 63:
#line 414 "C57.y"
    {(yyval) = NULL;;}
    break;

  case 64:
#line 417 "C57.y"
    {
				ast_node t = create_ast_node(RTN_STMT);
				(yyval) = t;
			;}
    break;

  case 65:
#line 421 "C57.y"
    {
				ast_node t = create_ast_node(RTN_STMT);
				(yyval) = t;
				(yyval)->left_child = (yyvsp[(2) - (3)]);	/* return value */
			;}
    break;

  case 66:
#line 428 "C57.y"
    {
				ast_node t = create_ast_node(READ_STMT);
				(yyval) = t;
				(yyval)->left_child = (yyvsp[(2) - (3)]);
			;}
    break;

  case 67:
#line 435 "C57.y"
    {
				ast_node t = create_ast_node(PRINT_STMT);
				(yyval) = t;
				(yyval)->left_child = (yyvsp[(2) - (3)]);
			;}
    break;

  case 68:
#line 440 "C57.y"
    {
				ast_node t = create_ast_node(PRINT_STMT);
				ast_node t1 = create_ast_node(STRING_LITERAL);
				t1->value.string = strdup(savedStrText);
				t->left_child = t1;
				(yyval) = t;
			;}
    break;

  case 69:
#line 449 "C57.y"
    {
				ast_node t = create_ast_node(OP_ASSIGN);
				t->left_child = (yyvsp[(1) - (3)]);
				t->left_child->right_sibling = (yyvsp[(3) - (3)]);
				(yyval) = t;
			;}
    break;

  case 70:
#line 455 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 71:
#line 458 "C57.y"
    {
 				ast_node t = create_ast_node(IDENT);
  				t->value.string = retrieve_id(the_id_table, savedIdText);
				(yyval) = t;
			;}
    break;

  case 72:
#line 463 "C57.y"
    {
				ast_node t = create_ast_node(IDENT);
				char* tmp = (char*)malloc(strlen(savedIdText)+3);
				strcat(tmp, savedIdText);
				strcat(tmp, "[]");
				tmp = retrieve_id(the_id_table, tmp);
				t->value.string = tmp;
				t->value.string = tmp;
				(yyvsp[(1) - (1)]) = t;
			;}
    break;

  case 73:
#line 472 "C57.y"
    {
				(yyvsp[(1) - (5)])->left_child = (yyvsp[(4) - (5)]);
				(yyval) = (yyvsp[(1) - (5)]);		
			;}
    break;

  case 74:
#line 478 "C57.y"
    {
 				ast_node t = create_ast_node(OP_PLUS);
  				t->left_child = (yyvsp[(1) - (3)]);
  				t->left_child->right_sibling = (yyvsp[(3) - (3)]);
				(yyval) = t;
			;}
    break;

  case 75:
#line 484 "C57.y"
    {
 				ast_node t = create_ast_node(OP_MINUS);
  				t->left_child = (yyvsp[(1) - (3)]);
  				t->left_child->right_sibling = (yyvsp[(3) - (3)]);
				(yyval) = t;
			;}
    break;

  case 76:
#line 490 "C57.y"
    {
 				ast_node t = create_ast_node(OP_TIMES);
  				t->left_child = (yyvsp[(1) - (3)]);
  				t->left_child->right_sibling = (yyvsp[(3) - (3)]);
				(yyval) = t;
			;}
    break;

  case 77:
#line 496 "C57.y"
    {
 				ast_node t = create_ast_node(OP_DIVIDE);
  				t->left_child = (yyvsp[(1) - (3)]);
  				t->left_child->right_sibling = (yyvsp[(3) - (3)]);
				(yyval) = t;
			;}
    break;

  case 78:
#line 502 "C57.y"
    {
 				ast_node t = create_ast_node(OP_MOD);
  				t->left_child = (yyvsp[(1) - (3)]);
  				t->left_child->right_sibling = (yyvsp[(3) - (3)]);
				(yyval) = t;
			;}
    break;

  case 79:
#line 508 "C57.y"
    {
 				ast_node t = create_ast_node(OP_LESS);
  				t->left_child = (yyvsp[(1) - (3)]);
  				t->left_child->right_sibling = (yyvsp[(3) - (3)]);
				(yyval) = t;
			;}
    break;

  case 80:
#line 514 "C57.y"
    {
 				ast_node t = create_ast_node(OP_LESSEQ);
  				t->left_child = (yyvsp[(1) - (3)]);
  				t->left_child->right_sibling = (yyvsp[(3) - (3)]);
				(yyval) = t;
			;}
    break;

  case 81:
#line 520 "C57.y"
    {
 				ast_node t = create_ast_node(OP_GRTER);
  				t->left_child = (yyvsp[(1) - (3)]);
  				t->left_child->right_sibling = (yyvsp[(3) - (3)]);
				(yyval) = t;
			;}
    break;

  case 82:
#line 526 "C57.y"
    {
 				ast_node t = create_ast_node(OP_GRTEREQ);
  				t->left_child = (yyvsp[(1) - (3)]);
  				t->left_child->right_sibling = (yyvsp[(3) - (3)]);
				(yyval) = t;
			;}
    break;

  case 83:
#line 532 "C57.y"
    {
 				ast_node t = create_ast_node(OP_EQUALS);
  				t->left_child = (yyvsp[(1) - (3)]);
  				t->left_child->right_sibling = (yyvsp[(3) - (3)]);
				(yyval) = t;
			;}
    break;

  case 84:
#line 538 "C57.y"
    {
 				ast_node t = create_ast_node(OP_NEQ);
  				t->left_child = (yyvsp[(1) - (3)]);
  				t->left_child->right_sibling = (yyvsp[(3) - (3)]);
				(yyval) = t;
			;}
    break;

  case 85:
#line 544 "C57.y"
    {
 				ast_node t = create_ast_node(OP_AND);
  				t->left_child = (yyvsp[(1) - (3)]);
  				t->left_child->right_sibling = (yyvsp[(3) - (3)]);
				(yyval) = t;
			;}
    break;

  case 86:
#line 550 "C57.y"
    {
 				ast_node t = create_ast_node(OP_OR);
  				t->left_child = (yyvsp[(1) - (3)]);
  				t->left_child->right_sibling = (yyvsp[(3) - (3)]);
				(yyval) = t;
			;}
    break;

  case 87:
#line 556 "C57.y"
    {
 				ast_node t = create_ast_node(OP_NOT);	
				t->left_child = (yyvsp[(2) - (2)]);
				(yyval) = t;
			;}
    break;

  case 88:
#line 561 "C57.y"
    {
 				ast_node t = create_ast_node(OP_UMINUS);	
				t->left_child = (yyvsp[(2) - (2)]);
				(yyval) = t;
			;}
    break;

  case 89:
#line 566 "C57.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			;}
    break;

  case 90:
#line 569 "C57.y"
    {
 				ast_node t = create_ast_node(INC_PRE);	
				t->left_child = (yyvsp[(2) - (2)]);
				(yyval) = t;
			;}
    break;

  case 91:
#line 574 "C57.y"
    {
 				ast_node t = create_ast_node(DEC_PRE);	
				t->left_child = (yyvsp[(2) - (2)]);
				(yyval) = t;
			;}
    break;

  case 92:
#line 579 "C57.y"
    {
 				ast_node t = create_ast_node(INC_POST);	
				t->left_child = (yyvsp[(1) - (2)]);
				(yyval) = t;
			;}
    break;

  case 93:
#line 584 "C57.y"
    {
 				ast_node t = create_ast_node(DEC_POST);	
				t->left_child = (yyvsp[(1) - (2)]);
				(yyval) = t;
			;}
    break;

  case 94:
#line 589 "C57.y"
    {(yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 95:
#line 590 "C57.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 96:
#line 591 "C57.y"
    {
  				ast_node t = create_ast_node(INT_LITERAL);
 				t->value.int_value = atoi(savedLiteralText);
 				(yyval) = t; 
			;}
    break;

  case 97:
#line 596 "C57.y"
    {
  				ast_node t = create_ast_node(DOUBLE_LITERAL);
 				t->value.double_value = atof(savedLiteralText);
 				(yyval) = t; 
			;}
    break;

  case 99:
#line 604 "C57.y"
    {
				ast_node t = create_ast_node(IDENT);
				t->value.string = retrieve_id(the_id_table, savedIdText);	/* func ID */
				(yyvsp[(1) - (1)]) = t;
			;}
    break;

  case 100:
#line 608 "C57.y"
    {
				ast_node t = create_ast_node(CALL);
				t->value.string = retrieve_id(the_id_table, savedIdText);	/* func ID */
				t->left_child = (yyvsp[(4) - (5)]);
				(yyval) = t;
			;}
    break;

  case 101:
#line 616 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 102:
#line 617 "C57.y"
    {(yyval) = NULL;;}
    break;

  case 103:
#line 620 "C57.y"
    {
  				ast_node t = (yyvsp[(1) - (3)]);
 				if (t != NULL) {
   					while (t->right_sibling != NULL)
       						t = t->right_sibling;
     					t->right_sibling = (yyvsp[(3) - (3)]);
   					(yyval) = (yyvsp[(1) - (3)]);
  				}else
					(yyval) = (yyvsp[(3) - (3)]);
			;}
    break;

  case 104:
#line 630 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 105:
#line 633 "C57.y"
    {
				ast_node t = create_ast_node(BREAK_STMT);
				(yyval) = t;
			;}
    break;

  case 106:
#line 639 "C57.y"
    {
				ast_node t = create_ast_node(CONTINUE_STMT);
				(yyval) = t;
			;}
    break;

  case 107:
#line 645 "C57.y"
    {
				ast_node t = create_ast_node(CASE_STMT);
				t->value.int_value = atoi(savedLiteralText);	/* NUM */
				t->right_sibling = (yyvsp[(4) - (4)]);
				(yyval) = t;
			;}
    break;

  case 108:
#line 653 "C57.y"
    {
				ast_node t = create_ast_node(DEFAULT_STMT);
				t->right_sibling = (yyvsp[(3) - (3)]);
				(yyval) = t;
			;}
    break;

  case 109:
#line 660 "C57.y"
    {
				ast_node t = create_ast_node(SWITCH_STMT);
				t->left_child = (yyvsp[(5) - (5)]);
				(yyval) = t;
			;}
    break;

  case 110:
#line 667 "C57.y"
    {
				ast_node t = create_ast_node(SIZE_OF);
				t->left_child = (yyvsp[(3) - (4)]);
				(yyval) = t;
			;}
    break;

  case 111:
#line 672 "C57.y"
    {
				ast_node t = create_ast_node(SIZE_OF);
				t->left_child = (yyvsp[(3) - (4)]);
				(yyval) = t;
			;}
    break;


/* Line 1267 of yacc.c.  */
#line 2664 "C57.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 685 "C57.y"
	/* code section */
void set_debug()
{
	extern int yydebug;	
	yydebug = 1;
}






	

