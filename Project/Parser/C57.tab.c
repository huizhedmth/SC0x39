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
     READ = 267,
     PRINT = 268,
     BREAK = 269,
     CONTINUE = 270,
     SWITCH = 271,
     CASE = 272,
     DEFAULT = 273,
     SIZEOF = 274,
     CONST = 275,
     EQ = 276,
     NEQ = 277,
     INC = 278,
     DEC = 279,
     AND = 280,
     OR = 281,
     LESSEQ = 282,
     GRTEREQ = 283,
     ID = 284,
     NUM = 285,
     FNUM = 286,
     STRING = 287,
     OTHER = 288,
     DECPRE = 289,
     INCPRE = 290,
     UMINUS = 291,
     DECPOST = 292,
     INCPOST = 293
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
#define READ 267
#define PRINT 268
#define BREAK 269
#define CONTINUE 270
#define SWITCH 271
#define CASE 272
#define DEFAULT 273
#define SIZEOF 274
#define CONST 275
#define EQ 276
#define NEQ 277
#define INC 278
#define DEC 279
#define AND 280
#define OR 281
#define LESSEQ 282
#define GRTEREQ 283
#define ID 284
#define NUM 285
#define FNUM 286
#define STRING 287
#define OTHER 288
#define DECPRE 289
#define INCPRE 290
#define UMINUS 291
#define DECPOST 292
#define INCPOST 293




/* Copy the first part of user declarations.  */
#line 15 "C57.y"

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
#line 208 "C57.tab.c"

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
#define YYLAST   558

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNRULES -- Number of states.  */
#define YYNSTATES  218

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,     2,     2,    42,     2,     2,
      52,    53,    40,    38,    34,    39,     2,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    56,    49,
      36,    35,    37,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,    55,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    44,
      45,    46,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    20,
      21,    27,    29,    31,    35,    37,    39,    40,    45,    46,
      52,    55,    58,    64,    70,    76,    78,    80,    81,    85,
      87,    90,    94,    99,   105,   107,   111,   113,   115,   118,
     122,   127,   132,   135,   136,   139,   140,   142,   144,   146,
     148,   150,   152,   154,   156,   158,   160,   162,   164,   166,
     168,   174,   182,   188,   196,   206,   208,   209,   212,   216,
     220,   224,   228,   231,   234,   239,   243,   249,   252,   254,
     258,   260,   262,   263,   269,   273,   277,   281,   285,   289,
     293,   297,   301,   305,   309,   313,   317,   321,   324,   327,
     329,   332,   335,   338,   341,   345,   347,   349,   351,   353,
     358,   363,   364,   370,   372,   373,   377
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      58,     0,    -1,    59,    -1,    59,    60,    -1,    60,    -1,
      61,    -1,    69,    -1,    70,    -1,    63,    64,    49,    -1,
      -1,    20,    62,    63,    64,    49,    -1,     5,    -1,    11,
      -1,    64,    34,    65,    -1,    65,    -1,    29,    -1,    -1,
      29,    35,    66,    95,    -1,    -1,    29,    50,    67,    95,
      51,    -1,    63,    29,    -1,     7,    29,    -1,    68,    52,
      71,    53,    77,    -1,    68,    52,    71,    53,    49,    -1,
      68,    52,    74,    53,    49,    -1,    72,    -1,     7,    -1,
      -1,    72,    34,    73,    -1,    73,    -1,    63,    29,    -1,
      20,    63,    29,    -1,    63,    29,    50,    51,    -1,    20,
      63,    29,    50,    51,    -1,    75,    -1,    75,    34,    76,
      -1,    76,    -1,    63,    -1,    20,    63,    -1,    63,    50,
      51,    -1,    20,    63,    50,    51,    -1,    54,    78,    79,
      55,    -1,    78,    61,    -1,    -1,    79,    80,    -1,    -1,
      94,    -1,    77,    -1,    81,    -1,    82,    -1,    83,    -1,
      84,    -1,    86,    -1,    87,    -1,    88,    -1,    89,    -1,
      90,    -1,    93,    -1,    91,    -1,    92,    -1,     4,    52,
      95,    53,    80,    -1,     4,    52,    95,    53,    80,     3,
      80,    -1,     8,    52,    95,    53,    80,    -1,    10,    80,
       8,    52,    95,    53,    49,    -1,     9,    52,    85,    49,
      85,    49,    85,    53,    80,    -1,    95,    -1,    -1,     6,
      49,    -1,     6,    95,    49,    -1,    12,    96,    49,    -1,
      13,    95,    49,    -1,    13,    32,    49,    -1,    14,    49,
      -1,    15,    49,    -1,    17,    30,    56,    80,    -1,    18,
      56,    80,    -1,    16,    52,    95,    53,    80,    -1,    95,
      49,    -1,    49,    -1,    96,    35,    95,    -1,    98,    -1,
      29,    -1,    -1,    29,    97,    50,    95,    51,    -1,    95,
      38,    95,    -1,    95,    39,    95,    -1,    95,    40,    95,
      -1,    95,    41,    95,    -1,    95,    42,    95,    -1,    95,
      36,    95,    -1,    95,    27,    95,    -1,    95,    37,    95,
      -1,    95,    28,    95,    -1,    95,    21,    95,    -1,    95,
      22,    95,    -1,    95,    25,    95,    -1,    95,    26,    95,
      -1,    43,    95,    -1,    39,    95,    -1,    96,    -1,    23,
      96,    -1,    24,    96,    -1,    96,    23,    -1,    96,    24,
      -1,    52,    95,    53,    -1,    30,    -1,    31,    -1,    99,
      -1,   100,    -1,    19,    52,    63,    53,    -1,    19,    52,
      95,    53,    -1,    -1,    29,   101,    52,   102,    53,    -1,
     103,    -1,    -1,   103,    34,    95,    -1,    95,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    93,    93,   101,   111,   115,   116,   117,   121,   124,
     124,   131,   137,   146,   156,   160,   176,   176,   195,   195,
     220,   228,   241,   255,   261,   270,   275,   282,   292,   302,
     306,   318,   330,   344,   361,   365,   375,   379,   387,   396,
     406,   420,   433,   443,   447,   457,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     478,   485,   495,   504,   513,   523,   524,   531,   535,   543,
     551,   556,   566,   573,   580,   589,   597,   606,   607,   614,
     620,   624,   629,   629,   640,   646,   652,   658,   664,   670,
     676,   682,   688,   694,   700,   706,   712,   718,   723,   728,
     729,   734,   739,   744,   749,   750,   755,   760,   761,   765,
     770,   778,   778,   791,   796,   800,   810
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ELSE", "IF", "INT", "RETURN", "VOID",
  "WHILE", "FOR", "DO", "DOUBLE", "READ", "PRINT", "BREAK", "CONTINUE",
  "SWITCH", "CASE", "DEFAULT", "SIZEOF", "CONST", "EQ", "NEQ", "INC",
  "DEC", "AND", "OR", "LESSEQ", "GRTEREQ", "ID", "NUM", "FNUM", "STRING",
  "OTHER", "','", "'='", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'!'", "DECPRE", "INCPRE", "UMINUS", "DECPOST", "INCPOST", "';'", "'['",
  "']'", "'('", "')'", "'{'", "'}'", "':'", "$accept", "program",
  "declaration_list", "declaration", "var_declaration", "@1",
  "var_type_specifier", "var_decl_list", "var_decl", "@2", "@3",
  "func_header", "func_declaration", "func_prototype", "formal_params",
  "formal_list", "formal_param", "informal_params", "informal_list",
  "informal_param", "compound_statement", "local_declarations",
  "statement_list", "statement", "if_statement", "while_statement",
  "do_while_statement", "for_statement", "for_header_expression",
  "return_statement", "read_statement", "print_statement",
  "break_statement", "continue_statement", "case_statement",
  "default_statement", "switch_statement", "expression_statement",
  "expression", "var", "@4", "r_value", "sizeof_expression", "call", "@5",
  "args", "arg_list", 0
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
     285,   286,   287,   288,    44,    61,    60,    62,    43,    45,
      42,    47,    37,    33,   289,   290,   291,   292,   293,    59,
      91,    93,    40,    41,   123,   125,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    60,    61,    62,
      61,    63,    63,    64,    64,    65,    66,    65,    67,    65,
      68,    68,    69,    70,    70,    71,    71,    71,    72,    72,
      73,    73,    73,    73,    74,    75,    75,    76,    76,    76,
      76,    77,    78,    78,    79,    79,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      81,    81,    82,    83,    84,    85,    85,    86,    86,    87,
      88,    88,    89,    90,    91,    92,    93,    94,    94,    95,
      95,    96,    97,    96,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    99,
      99,   101,   100,   102,   102,   103,   103
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     3,     0,
       5,     1,     1,     3,     1,     1,     0,     4,     0,     5,
       2,     2,     5,     5,     5,     1,     1,     0,     3,     1,
       2,     3,     4,     5,     1,     3,     1,     1,     2,     3,
       4,     4,     2,     0,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     7,     5,     7,     9,     1,     0,     2,     3,     3,
       3,     3,     2,     2,     4,     3,     5,     2,     1,     3,
       1,     1,     0,     5,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     1,
       2,     2,     2,     2,     3,     1,     1,     1,     1,     4,
       4,     0,     5,     1,     0,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    11,     0,    12,     9,     0,     2,     4,     5,     0,
       0,     6,     7,    21,     0,     1,     3,    15,     0,    14,
      27,     0,    16,    18,     0,     8,    26,     0,    37,     0,
      25,    29,     0,    34,    36,    15,     0,     0,     0,    13,
      38,    30,     0,     0,     0,     0,     0,    10,     0,     0,
       0,    81,   105,   106,     0,     0,     0,    17,    99,    80,
     107,   108,     0,    31,     0,     0,    39,    23,    43,    22,
       0,     0,    28,    24,     0,    37,    35,     0,    81,   100,
     101,     0,     0,    98,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   102,
     103,     0,    19,     0,    40,    32,    45,     0,    38,     0,
       0,     0,   114,   104,    93,    94,    95,    96,    90,    92,
      89,    91,    84,    85,    86,    87,    88,    79,    33,    42,
       0,     0,   109,   110,     0,   116,     0,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,    41,    47,    44,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    58,    59,    57,    46,     0,    83,   112,
       0,     0,    67,     0,     0,    66,     0,     0,     0,     0,
      72,    73,     0,     0,     0,    77,   115,     0,    68,     0,
       0,    65,     0,    69,    71,    70,     0,     0,    75,     0,
       0,    66,     0,     0,    74,    60,    62,     0,     0,    76,
       0,    66,     0,    61,     0,    63,     0,    64
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    14,     9,    18,    19,    37,
      38,    10,    11,    12,    29,    30,    31,    32,    33,    34,
     152,   106,   131,   153,   154,   155,   156,   157,   190,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    58,
      81,    59,    60,    61,    82,   136,   137
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -196
static const yytype_int16 yypact[] =
{
       4,  -196,     6,  -196,  -196,    34,     4,  -196,  -196,    19,
      10,  -196,  -196,  -196,    17,  -196,  -196,   -14,    38,  -196,
      66,    37,  -196,  -196,    37,  -196,  -196,    17,   -25,    15,
      35,  -196,    23,    48,  -196,    53,    56,   241,   241,  -196,
     -21,    42,    44,   -44,    74,    51,    78,  -196,    41,    72,
      72,   -38,  -196,  -196,   241,   241,   241,     5,   160,  -196,
    -196,  -196,   392,    61,    70,    71,  -196,  -196,  -196,  -196,
      17,    96,  -196,  -196,    17,    77,  -196,   180,    82,  -196,
    -196,    86,    76,  -196,  -196,   260,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,  -196,
    -196,   241,  -196,    89,  -196,  -196,   115,   117,    94,    97,
     282,   241,   241,  -196,   516,   516,   120,   509,   406,   406,
     406,   406,   148,   148,  -196,  -196,  -196,     5,  -196,  -196,
      37,   100,  -196,  -196,   414,     5,    98,   119,   111,   197,
     114,   116,   163,    72,   224,   121,   147,   145,   168,   144,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,   436,  -196,  -196,
     241,   241,  -196,   461,   241,   241,   193,   156,   158,   486,
    -196,  -196,   241,   152,   163,  -196,     5,   304,  -196,   326,
     164,     5,   162,  -196,  -196,  -196,   348,   163,  -196,   163,
     163,   241,   241,   163,  -196,   215,  -196,   173,   370,  -196,
     163,   241,   175,  -196,   172,  -196,   163,  -196
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -196,  -196,  -196,   223,   124,  -196,    -7,   210,   209,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,   190,  -196,  -196,   189,
     194,  -196,  -196,  -119,  -196,  -196,  -196,  -196,  -195,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,   -37,   -47,
    -196,  -196,  -196,  -196,  -196,  -196,  -196
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -112
static const yytype_int16 yytable[] =
{
      57,    62,    79,    80,    41,    67,   207,    21,    63,     1,
      68,     2,   -82,    28,  -111,     3,   214,    83,    84,    85,
      40,    22,     1,   176,     4,    42,    86,    87,     3,    64,
      88,    89,    90,    91,    15,    13,    23,    71,   -20,    75,
     110,    92,    93,    94,    95,    96,    97,    98,    17,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    20,   107,   127,   198,    35,   108,    43,    44,
     109,     1,    24,    26,   134,   135,    45,     3,   204,     1,
     205,   206,    46,     1,   209,     3,    27,    25,    22,     3,
      24,   213,    65,    77,    70,    66,   177,   217,    74,   130,
      73,    78,   173,    23,   138,    47,   139,   179,   140,   141,
     142,   103,   143,   144,   145,   146,   147,   148,   149,    48,
       1,   104,   105,    49,    50,    41,     3,    42,   112,    51,
      52,    53,   -82,   186,   187,     4,   111,   189,   191,    54,
     128,    86,    87,    55,    64,   196,    63,    90,    91,   150,
     132,   169,    56,   170,    68,   151,    92,    93,    94,    95,
      96,    97,    98,   171,   191,   208,   174,   138,   175,   139,
     180,   140,   141,   142,   191,   143,   144,   145,   146,   147,
     148,   149,    48,    99,   100,     1,    49,    50,    96,    97,
      98,     3,    51,    52,    53,   101,   181,   182,   183,    48,
     184,   192,    54,    49,    50,   193,    55,   194,   197,    51,
      52,    53,   150,   201,   202,    56,    48,    68,   210,    54,
      49,    50,   211,    55,   215,   216,    51,    52,    53,    16,
     129,    36,    56,    39,    72,    76,    54,    69,     0,     0,
      55,     0,     0,    48,     0,     0,   172,    49,    50,    56,
       0,     0,     0,    51,    52,    53,   178,     0,     0,     0,
      48,     0,     0,    54,    49,    50,     0,    55,     0,     0,
      51,    52,    53,     0,     0,     0,    56,     0,     0,     0,
      54,    86,    87,     0,    55,    88,    89,    90,    91,     0,
       0,     0,     0,    56,     0,     0,    92,    93,    94,    95,
      96,    97,    98,    86,    87,     0,     0,    88,    89,    90,
      91,     0,     0,   113,     0,     0,     0,     0,    92,    93,
      94,    95,    96,    97,    98,    86,    87,     0,     0,    88,
      89,    90,    91,     0,     0,   133,     0,     0,     0,     0,
      92,    93,    94,    95,    96,    97,    98,    86,    87,     0,
       0,    88,    89,    90,    91,     0,     0,   199,     0,     0,
       0,     0,    92,    93,    94,    95,    96,    97,    98,    86,
      87,     0,     0,    88,    89,    90,    91,     0,     0,   200,
       0,     0,     0,     0,    92,    93,    94,    95,    96,    97,
      98,    86,    87,     0,     0,    88,    89,    90,    91,     0,
       0,   203,     0,     0,     0,     0,    92,    93,    94,    95,
      96,    97,    98,    86,    87,     0,     0,    88,    89,    90,
      91,     0,     0,   212,     0,     0,     0,     0,    92,    93,
      94,    95,    96,    97,    98,    86,    87,     0,     0,    88,
      89,    90,    91,   102,    94,    95,    96,    97,    98,     0,
      92,    93,    94,    95,    96,    97,    98,    86,    87,     0,
       0,    88,    89,    90,    91,   168,     0,     0,     0,     0,
       0,     0,    92,    93,    94,    95,    96,    97,    98,     0,
       0,     0,    86,    87,     0,   185,    88,    89,    90,    91,
       0,     0,     0,     0,     0,     0,     0,    92,    93,    94,
      95,    96,    97,    98,     0,     0,     0,    86,    87,     0,
     188,    88,    89,    90,    91,     0,     0,     0,     0,     0,
       0,     0,    92,    93,    94,    95,    96,    97,    98,     0,
      86,    87,     0,     0,    88,   195,    90,    91,     0,     0,
       0,     0,     0,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    92,    93,    94,    95,    96,    97,    98
};

static const yytype_int16 yycheck[] =
{
      37,    38,    49,    50,    29,    49,   201,    14,    29,     5,
      54,     7,    50,    20,    52,    11,   211,    54,    55,    56,
      27,    35,     5,   142,    20,    50,    21,    22,    11,    50,
      25,    26,    27,    28,     0,    29,    50,    44,    52,    46,
      77,    36,    37,    38,    39,    40,    41,    42,    29,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    52,    70,   101,   184,    29,    74,    53,    34,
      77,     5,    34,     7,   111,   112,    53,    11,   197,     5,
     199,   200,    34,     5,   203,    11,    20,    49,    35,    11,
      34,   210,    50,    52,    20,    51,   143,   216,    20,   106,
      49,    29,   139,    50,     4,    49,     6,   144,     8,     9,
      10,    50,    12,    13,    14,    15,    16,    17,    18,    19,
       5,    51,    51,    23,    24,    29,    11,    50,    52,    29,
      30,    31,    50,   170,   171,    20,    50,   174,   175,    39,
      51,    21,    22,    43,    50,   182,    29,    27,    28,    49,
      53,    53,    52,    34,    54,    55,    36,    37,    38,    39,
      40,    41,    42,    52,   201,   202,    52,     4,    52,     6,
      49,     8,     9,    10,   211,    12,    13,    14,    15,    16,
      17,    18,    19,    23,    24,     5,    23,    24,    40,    41,
      42,    11,    29,    30,    31,    35,    49,    52,    30,    19,
      56,     8,    39,    23,    24,    49,    43,    49,    56,    29,
      30,    31,    49,    49,    52,    52,    19,    54,     3,    39,
      23,    24,    49,    43,    49,    53,    29,    30,    31,     6,
     106,    21,    52,    24,    44,    46,    39,    43,    -1,    -1,
      43,    -1,    -1,    19,    -1,    -1,    49,    23,    24,    52,
      -1,    -1,    -1,    29,    30,    31,    32,    -1,    -1,    -1,
      19,    -1,    -1,    39,    23,    24,    -1,    43,    -1,    -1,
      29,    30,    31,    -1,    -1,    -1,    52,    -1,    -1,    -1,
      39,    21,    22,    -1,    43,    25,    26,    27,    28,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    36,    37,    38,    39,
      40,    41,    42,    21,    22,    -1,    -1,    25,    26,    27,
      28,    -1,    -1,    53,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    41,    42,    21,    22,    -1,    -1,    25,
      26,    27,    28,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    40,    41,    42,    21,    22,    -1,
      -1,    25,    26,    27,    28,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    36,    37,    38,    39,    40,    41,    42,    21,
      22,    -1,    -1,    25,    26,    27,    28,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,    41,
      42,    21,    22,    -1,    -1,    25,    26,    27,    28,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      40,    41,    42,    21,    22,    -1,    -1,    25,    26,    27,
      28,    -1,    -1,    53,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    41,    42,    21,    22,    -1,    -1,    25,
      26,    27,    28,    51,    38,    39,    40,    41,    42,    -1,
      36,    37,    38,    39,    40,    41,    42,    21,    22,    -1,
      -1,    25,    26,    27,    28,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    21,    22,    -1,    49,    25,    26,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    -1,    21,    22,    -1,
      49,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    39,    40,    41,    42,    -1,
      21,    22,    -1,    -1,    25,    49,    27,    28,    -1,    -1,
      -1,    -1,    -1,    27,    28,    36,    37,    38,    39,    40,
      41,    42,    36,    37,    38,    39,    40,    41,    42
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     7,    11,    20,    58,    59,    60,    61,    63,
      68,    69,    70,    29,    62,     0,    60,    29,    64,    65,
      52,    63,    35,    50,    34,    49,     7,    20,    63,    71,
      72,    73,    74,    75,    76,    29,    64,    66,    67,    65,
      63,    29,    50,    53,    34,    53,    34,    49,    19,    23,
      24,    29,    30,    31,    39,    43,    52,    95,    96,    98,
      99,   100,    95,    29,    50,    50,    51,    49,    54,    77,
      20,    63,    73,    49,    20,    63,    76,    52,    29,    96,
      96,    97,   101,    95,    95,    95,    21,    22,    25,    26,
      27,    28,    36,    37,    38,    39,    40,    41,    42,    23,
      24,    35,    51,    50,    51,    51,    78,    63,    63,    63,
      95,    50,    52,    53,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    51,    61,
      63,    79,    53,    53,    95,    95,   102,   103,     4,     6,
       8,     9,    10,    12,    13,    14,    15,    16,    17,    18,
      49,    55,    77,    80,    81,    82,    83,    84,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    51,    53,
      34,    52,    49,    95,    52,    52,    80,    96,    32,    95,
      49,    49,    52,    30,    56,    49,    95,    95,    49,    95,
      85,    95,     8,    49,    49,    49,    95,    56,    80,    53,
      53,    49,    52,    53,    80,    80,    80,    85,    95,    80,
       3,    49,    53,    80,    85,    49,    53,    80
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
#line 93 "C57.y"
    {
				root = create_ast_node(ROOT);
				root->left_child = (yyvsp[(1) - (1)]);
				(yyval) = root;
			;}
    break;

  case 3:
#line 101 "C57.y"
    {
				ast_node t = (yyvsp[(1) - (2)]);
				if (t!=NULL){
				   while (t->right_sibling != NULL)
				   	 t = t->right_sibling;
				   t->right_sibling = (yyvsp[(2) - (2)]);
				   (yyval) = (yyvsp[(1) - (2)]);
				}else
				   (yyval) = (yyvsp[(2) - (2)]);
			;}
    break;

  case 4:
#line 111 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 5:
#line 115 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 6:
#line 116 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 7:
#line 117 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 8:
#line 121 "C57.y"
    { 
				(yyval) = (yyvsp[(2) - (3)]);
			;}
    break;

  case 9:
#line 124 "C57.y"
    {g_flag_const = 1;;}
    break;

  case 10:
#line 124 "C57.y"
    { 
			      	(yyval) = (yyvsp[(4) - (5)]);
				g_flag_const = 0;
			;}
    break;

  case 11:
#line 131 "C57.y"
    {
				ast_node t = create_ast_node(TYPE);
				t->value.string = strdup("INT");
				strcpy(g_type, t->value.string);
				(yyval) = t;
			;}
    break;

  case 12:
#line 137 "C57.y"
    {
				ast_node t = create_ast_node(TYPE);
				t->value.string = strdup("DOUBLE");
				strcpy(g_type, t->value.string);
				(yyval) = t;
			;}
    break;

  case 13:
#line 146 "C57.y"
    {
				ast_node t = (yyvsp[(1) - (3)]);
				if (t!=NULL){
				   while (t->right_sibling != NULL)
				   	 t = t->right_sibling;
				   t->right_sibling = (yyvsp[(3) - (3)]);
				   (yyval) = (yyvsp[(1) - (3)]);
				}else
				   (yyval) = (yyvsp[(3) - (3)]);
			;}
    break;

  case 14:
#line 156 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 15:
#line 160 "C57.y"
    {
				ast_node t = create_ast_node(VAR_DECL);
				(yyval) = t;
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
			;}
    break;

  case 16:
#line 176 "C57.y"
    {
				ast_node t = create_ast_node(IDENTIFIER);
				t->value.string = strdup(savedIdText);
				(yyval) = t;
			;}
    break;

  case 17:
#line 180 "C57.y"
    {
				ast_node t = create_ast_node(VAR_DECL);
				(yyval) = t;
				ast_node t1 = create_ast_node(STORAGE);
				if (g_flag_const == 1)
				   t1->value.string = strdup("CONST");
				else
				   t1->value.string = strdup("NORMAL");
				ast_node t2  = create_ast_node(TYPE);
				t2->value.string = strdup(g_type);
				t->left_child = t1;
				t1->right_sibling = t2;
				t2->right_sibling = (yyvsp[(3) - (4)]);
				(yyvsp[(3) - (4)])->right_sibling = (yyvsp[(4) - (4)]);
			;}
    break;

  case 18:
#line 195 "C57.y"
    {
				ast_node t = create_ast_node(IDENTIFIER);
				t->value.string = strdup(savedIdText);
				(yyval) = t;
			;}
    break;

  case 19:
#line 199 "C57.y"
    {
				ast_node t = create_ast_node(VAR_DECL);
				(yyval) = t;
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
				t2->right_sibling = (yyvsp[(3) - (5)]);
				(yyvsp[(3) - (5)])->right_sibling = (yyvsp[(4) - (5)]);
			;}
    break;

  case 20:
#line 220 "C57.y"
    {
				ast_node t = create_ast_node(FUNC_HEADER);
				t->left_child = (yyvsp[(1) - (2)]);
				ast_node t1 = create_ast_node(IDENTIFIER);
				t1->value.string = strdup(savedIdText);
				(yyvsp[(1) - (2)])->right_sibling = t1;
				(yyval) = t;
			;}
    break;

  case 21:
#line 228 "C57.y"
    {
			     	ast_node t = create_ast_node(FUNC_HEADER);
				ast_node t1 = create_ast_node(TYPE);
				t1->value.string = strdup("VOID");
				t->left_child = t1;
				(yyval) = t;
				ast_node t2 = create_ast_node(IDENTIFIER);
				t2->value.string = strdup(savedIdText);
				t1->right_sibling = t2;
			;}
    break;

  case 22:
#line 241 "C57.y"
    {
				ast_node t = create_ast_node(FUNC_DECL);
				(yyval) = t;
				t->left_child = (yyvsp[(1) - (5)]);
				(yyvsp[(1) - (5)])->right_sibling = (yyvsp[(3) - (5)]);
				(yyvsp[(3) - (5)])->right_sibling = (yyvsp[(5) - (5)]);
			;}
    break;

  case 23:
#line 255 "C57.y"
    {
				ast_node t = create_ast_node(FUNC_PROTO);
				(yyval) = t;
				t->left_child = (yyvsp[(1) - (5)]);
				t->left_child->right_sibling = (yyvsp[(3) - (5)]);
			;}
    break;

  case 24:
#line 261 "C57.y"
    {
				ast_node t = create_ast_node(FUNC_PROTO);
				(yyval) = t;
				t->left_child = (yyvsp[(1) - (5)]);
				t->left_child->right_sibling = (yyvsp[(3) - (5)]);
			;}
    break;

  case 25:
#line 270 "C57.y"
    {
				ast_node t = create_ast_node(FUNC_PARAMS);
				(yyval) = t;
				t->left_child = (yyvsp[(1) - (1)]);
			;}
    break;

  case 26:
#line 275 "C57.y"
    {
				ast_node t = create_ast_node(FUNC_PARAMS);
				(yyval) = t;
				ast_node t1 = create_ast_node(TYPE);
				t1->value.string = strdup("VOID");
				t->left_child = t1;
			;}
    break;

  case 27:
#line 282 "C57.y"
    {
				ast_node t = create_ast_node(FUNC_PARAMS);
				(yyval) = t;
				ast_node t1 = create_ast_node(TYPE);
				t1->value.string = strdup("VOID");
				t->left_child = t1;
			;}
    break;

  case 28:
#line 292 "C57.y"
    {
				ast_node t = (yyvsp[(1) - (3)]);
				if (t!=NULL){
				   while (t->right_sibling != NULL)
				   	 t = t->right_sibling;
				   t->right_sibling = (yyvsp[(3) - (3)]);
				   (yyval) = (yyvsp[(1) - (3)]);
				}else
				   (yyval) = (yyvsp[(3) - (3)]);
			;}
    break;

  case 29:
#line 302 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 30:
#line 306 "C57.y"
    {
				ast_node t2 = create_ast_node(PARAM);
				ast_node t = create_ast_node(IDENTIFIER);
				t->value.string = strdup(savedIdText);
				ast_node t1 = create_ast_node(STORAGE);
				t1->value.string = strdup("NORMAL");
			
				(yyval) = t2;
				t2->left_child = t1;
				t1->right_sibling = (yyvsp[(1) - (2)]);
				(yyvsp[(1) - (2)])->right_sibling = t;
			;}
    break;

  case 31:
#line 318 "C57.y"
    {
				ast_node t2 = create_ast_node(PARAM);
				ast_node t = create_ast_node(IDENTIFIER);
				t->value.string = strdup(savedIdText);
				ast_node t1 = create_ast_node(STORAGE);	
				t1->value.string = strdup("CONST");
				
				(yyval) = t2;
				t2->left_child = t1;
				t1->right_sibling = (yyvsp[(2) - (3)]);
				(yyvsp[(2) - (3)])->right_sibling = t;
			;}
    break;

  case 32:
#line 330 "C57.y"
    {
				ast_node t2 = create_ast_node(PARAM);
				(yyvsp[(1) - (4)])->value.string = (char*)realloc((yyvsp[(1) - (4)])->value.string, 15);
				strcat((yyvsp[(1) - (4)])->value.string, " ARRAY");
				ast_node t = create_ast_node(IDENTIFIER);
				t->value.string = strdup(savedIdText);
				ast_node t1 = create_ast_node(STORAGE);
			        t1->value.string = strdup("NORMAL");
				
				(yyval) = t2;
				t2->left_child = t1;
				t1->right_sibling = (yyvsp[(1) - (4)]);
				(yyvsp[(1) - (4)])->right_sibling = t;
			;}
    break;

  case 33:
#line 344 "C57.y"
    {
				ast_node t2 = create_ast_node(PARAM);
				(yyvsp[(2) - (5)])->value.string = (char*)realloc((yyvsp[(2) - (5)])->value.string, 15);
				strcat((yyvsp[(2) - (5)])->value.string, " ARRAY");
				ast_node t = create_ast_node(IDENTIFIER);
				t->value.string = strdup(savedIdText);
				ast_node t1 = create_ast_node(STORAGE);
			        t1->value.string = strdup("CONST");
				
				(yyval) = t2;
				t2->left_child = t1;
				t1->right_sibling = (yyvsp[(2) - (5)]);
				(yyvsp[(2) - (5)])->right_sibling = t;
			;}
    break;

  case 34:
#line 361 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 35:
#line 365 "C57.y"
    {
				ast_node t = (yyvsp[(1) - (3)]);
				if (t!=NULL){
				   while (t->right_sibling != NULL)
				   	 t = t->right_sibling;
				   t->right_sibling = (yyvsp[(3) - (3)]);
				   (yyval) = (yyvsp[(1) - (3)]);
				}else
				   (yyval) = (yyvsp[(3) - (3)]);
			;}
    break;

  case 36:
#line 375 "C57.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 37:
#line 379 "C57.y"
    {
				ast_node t2 = create_ast_node(PARAM);
				ast_node t = create_ast_node(STORAGE);
				t->value.string = strdup("NORMAL");
				(yyval) = t2;
				t2->left_child = t;
				t->right_sibling = (yyvsp[(1) - (1)]);
			;}
    break;

  case 38:
#line 387 "C57.y"
    {
				ast_node t2 = create_ast_node(PARAM);
				ast_node t1 = create_ast_node(STORAGE);	
				t1->value.string = strdup("CONST");
				
				(yyval) = t2;
				t2->left_child = t1;
				t1->right_sibling = (yyvsp[(2) - (2)]);
			;}
    break;

  case 39:
#line 396 "C57.y"
    {
				ast_node t2 = create_ast_node(PARAM);
				ast_node t1 = create_ast_node(STORAGE);	
				t1->value.string = strdup("NORMAL");
				(yyval) = t2;
				t2->left_child = t1;
				(yyvsp[(1) - (3)])->value.string = (char*)realloc((yyvsp[(1) - (3)])->value.string, 15);
				strcat((yyvsp[(1) - (3)])->value.string, " ARRAY");
				t1->right_sibling = (yyvsp[(1) - (3)]);
			;}
    break;

  case 40:
#line 406 "C57.y"
    {
				ast_node t2 = create_ast_node(PARAM);
				(yyvsp[(2) - (4)])->value.string = (char*)realloc((yyvsp[(2) - (4)])->value.string, 15);
				strcat((yyvsp[(2) - (4)])->value.string, " ARRAY");
				ast_node t1 = create_ast_node(STORAGE);
			        t1->value.string = strdup("CONST");
				
				(yyval) = t2;
				t2->left_child = t1;
				t1->right_sibling = (yyvsp[(2) - (4)]);
			;}
    break;

  case 41:
#line 420 "C57.y"
    {
			    	ast_node t = create_ast_node(CMPD_STMT);
				ast_node t1 = create_ast_node(LOCAL_DECL);
				ast_node t2 = create_ast_node(STMT_LIST);
				t->left_child = t1;
				t1->right_sibling = t2;
				t1->left_child = (yyvsp[(2) - (4)]);
				t2->left_child = (yyvsp[(3) - (4)]);
				(yyval) = t;
			;}
    break;

  case 42:
#line 433 "C57.y"
    {
				ast_node t = (yyvsp[(1) - (2)]);
				if (t!=NULL){
				   while (t->right_sibling != NULL)
				   	 t = t->right_sibling;
				   t->right_sibling = (yyvsp[(2) - (2)]);
				   (yyval) = (yyvsp[(1) - (2)]);
				}else
				   (yyval) = (yyvsp[(2) - (2)]);
			;}
    break;

  case 43:
#line 443 "C57.y"
    {(yyval) = NULL;;}
    break;

  case 44:
#line 447 "C57.y"
    {
				ast_node t = (yyvsp[(1) - (2)]);
				if (t!=NULL){
				   while (t->right_sibling != NULL)
				   	 t = t->right_sibling;
				   t->right_sibling = (yyvsp[(2) - (2)]);
				   (yyval) = (yyvsp[(1) - (2)]);
				}else
				   (yyval) = (yyvsp[(2) - (2)]);
			;}
    break;

  case 45:
#line 457 "C57.y"
    {(yyval) = NULL;}
    break;

  case 46:
#line 461 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 47:
#line 462 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 48:
#line 463 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 49:
#line 464 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 50:
#line 465 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 51:
#line 466 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 52:
#line 467 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 53:
#line 468 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 54:
#line 469 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 55:
#line 470 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 56:
#line 471 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 57:
#line 472 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 58:
#line 473 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 59:
#line 474 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 60:
#line 478 "C57.y"
    {
			   ast_node t = create_ast_node(IF_STMT);
			   (yyval) = t;
			   t->left_child = (yyvsp[(3) - (5)]);
			   (yyvsp[(3) - (5)])->right_sibling = (yyvsp[(5) - (5)]);
			;}
    break;

  case 61:
#line 485 "C57.y"
    {
			   ast_node t = create_ast_node(IF_ELSE_STMT);
			   (yyval) = t;
			   t->left_child = (yyvsp[(3) - (7)]);
			   (yyvsp[(3) - (7)])->right_sibling = (yyvsp[(5) - (7)]);
			   (yyvsp[(5) - (7)])->right_sibling = (yyvsp[(7) - (7)]);
			;}
    break;

  case 62:
#line 495 "C57.y"
    {
			      ast_node t = create_ast_node(WHILE_STMT);
			      (yyval) = t;
			      t->left_child = (yyvsp[(3) - (5)]);
			      (yyvsp[(3) - (5)])->right_sibling = (yyvsp[(5) - (5)]);
			;}
    break;

  case 63:
#line 504 "C57.y"
    {
			   ast_node t = create_ast_node(DO_WHILE_STMT);
			   (yyval) = t;
			   t->left_child = (yyvsp[(2) - (7)]);
			   (yyvsp[(2) - (7)])->right_sibling = (yyvsp[(5) - (7)]);
			;}
    break;

  case 64:
#line 513 "C57.y"
    {
			    ast_node t = create_ast_node(FOR_STMT);
			    (yyval) = t;
			    t->left_child = (yyvsp[(3) - (9)]);
			    (yyvsp[(3) - (9)])->right_sibling = (yyvsp[(5) - (9)]);
			    (yyvsp[(5) - (9)])->right_sibling = (yyvsp[(9) - (9)]);
			    (yyvsp[(9) - (9)])->right_sibling = (yyvsp[(7) - (9)]);
			;}
    break;

  case 66:
#line 524 "C57.y"
    {
				ast_node t = create_ast_node(EMPTY);
				(yyval) = t;
			;}
    break;

  case 67:
#line 531 "C57.y"
    {
			       ast_node t = create_ast_node(RETURN_STMT);
			       (yyval) = t;
			;}
    break;

  case 68:
#line 535 "C57.y"
    {
			       ast_node t = create_ast_node(RETURN_STMT);
			       (yyval) = t;
			       t->left_child = (yyvsp[(2) - (3)]);
			;}
    break;

  case 69:
#line 543 "C57.y"
    {
			     ast_node t = create_ast_node(READ_STMT);
			     (yyval) = t;
			     t->left_child = (yyvsp[(2) - (3)]);
			;}
    break;

  case 70:
#line 551 "C57.y"
    {
			      ast_node t = create_ast_node(PRINT_STMT);
			      (yyval) = t;
			      t->left_child = (yyvsp[(2) - (3)]);
			;}
    break;

  case 71:
#line 556 "C57.y"
    {
			      ast_node t = create_ast_node(PRINT_STMT);
			      (yyval) = t;  
			      ast_node t1 = create_ast_node(STR_LITERAL);
			      t1->value.string = strdup(savedLiteralText);
			      t->left_child = t1;
			;}
    break;

  case 72:
#line 566 "C57.y"
    {
			      ast_node t = create_ast_node(BREAK_STMT);
			      (yyval) = t;
			;}
    break;

  case 73:
#line 573 "C57.y"
    {
			      ast_node t = create_ast_node(CONTINUE_STMT);
			      (yyval) = t;
			;}
    break;

  case 74:
#line 580 "C57.y"
    {
			     ast_node t = create_ast_node(CASE_STMT);
			     (yyval) = t;
			     t->value.int_value = atoi(savedLiteralText);
			     t->right_sibling = (yyvsp[(4) - (4)]);
			;}
    break;

  case 75:
#line 589 "C57.y"
    {
			     ast_node t = create_ast_node(DEFAULT_STMT);
			     (yyval) = t;
			     t->right_sibling = (yyvsp[(3) - (3)]);
			;}
    break;

  case 76:
#line 597 "C57.y"
    {
			     ast_node t = create_ast_node(SWITCH_STMT);
			     (yyval) = t;
			     t->left_child = (yyvsp[(3) - (5)]);
			     (yyvsp[(3) - (5)])->right_sibling = (yyvsp[(5) - (5)]);
			;}
    break;

  case 77:
#line 606 "C57.y"
    {(yyval) = (yyvsp[(1) - (2)]);;}
    break;

  case 78:
#line 607 "C57.y"
    {
				ast_node t = create_ast_node(EMPTY);
				(yyval) = t;
			;}
    break;

  case 79:
#line 614 "C57.y"
    {
			    ast_node t = create_ast_node(OP_ASSIGN);
			    (yyval) = t;
			    t->left_child = (yyvsp[(1) - (3)]);
			    (yyvsp[(1) - (3)])->right_sibling = (yyvsp[(3) - (3)]);
			;}
    break;

  case 80:
#line 620 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 81:
#line 624 "C57.y"
    {
				ast_node t = create_ast_node(IDENTIFIER);
				t->value.string = strdup(savedIdText);
				(yyval) = t;
			;}
    break;

  case 82:
#line 629 "C57.y"
    {			
			   	ast_node t = create_ast_node(IDENTIFIER);
				t->value.string = strdup(savedIdText);
				(yyval) = t;
			;}
    break;

  case 83:
#line 633 "C57.y"
    {
				(yyval) = (yyvsp[(2) - (5)]);
				(yyval)->left_child = (yyvsp[(4) - (5)]);
			;}
    break;

  case 84:
#line 640 "C57.y"
    {
			    ast_node t = create_ast_node(OP_PLUS);
			    (yyval) = t;
			    t->left_child = (yyvsp[(1) - (3)]);
			    (yyvsp[(1) - (3)])->right_sibling = (yyvsp[(3) - (3)]);
			;}
    break;

  case 85:
#line 646 "C57.y"
    {
			    ast_node t = create_ast_node(OP_MINUS);
			    (yyval) = t;
			    t->left_child = (yyvsp[(1) - (3)]);
			    (yyvsp[(1) - (3)])->right_sibling = (yyvsp[(3) - (3)]);
			;}
    break;

  case 86:
#line 652 "C57.y"
    {
			    ast_node t = create_ast_node(OP_TIMES);
			    (yyval) = t;
			    t->left_child = (yyvsp[(1) - (3)]);
			    (yyvsp[(1) - (3)])->right_sibling = (yyvsp[(3) - (3)]);
			;}
    break;

  case 87:
#line 658 "C57.y"
    {
			    ast_node t = create_ast_node(OP_DIVIDE);
			    (yyval) = t;
			    t->left_child = (yyvsp[(1) - (3)]);
			    (yyvsp[(1) - (3)])->right_sibling = (yyvsp[(3) - (3)]);
			;}
    break;

  case 88:
#line 664 "C57.y"
    {
			    ast_node t = create_ast_node(OP_MOD);
			    (yyval) = t;
			    t->left_child = (yyvsp[(1) - (3)]);
			    (yyvsp[(1) - (3)])->right_sibling = (yyvsp[(3) - (3)]);
			;}
    break;

  case 89:
#line 670 "C57.y"
    {
			    ast_node t = create_ast_node(OP_LESS);
			    (yyval) = t;
			    t->left_child = (yyvsp[(1) - (3)]);
			    (yyvsp[(1) - (3)])->right_sibling = (yyvsp[(3) - (3)]);
			;}
    break;

  case 90:
#line 676 "C57.y"
    {
			    ast_node t = create_ast_node(OP_LESSEQ);
			    (yyval) = t;
			    t->left_child = (yyvsp[(1) - (3)]);
			    (yyvsp[(1) - (3)])->right_sibling = (yyvsp[(3) - (3)]);
			;}
    break;

  case 91:
#line 682 "C57.y"
    {
			    ast_node t = create_ast_node(OP_GRTER);
			    (yyval) = t;
			    t->left_child = (yyvsp[(1) - (3)]);
			    (yyvsp[(1) - (3)])->right_sibling = (yyvsp[(3) - (3)]);
			;}
    break;

  case 92:
#line 688 "C57.y"
    {
			    ast_node t = create_ast_node(OP_GRTEREQ);
			    (yyval) = t;
			    t->left_child = (yyvsp[(1) - (3)]);
			    (yyvsp[(1) - (3)])->right_sibling = (yyvsp[(3) - (3)]);
			;}
    break;

  case 93:
#line 694 "C57.y"
    {
			    ast_node t = create_ast_node(OP_EQUALS);
			    (yyval) = t;
			    t->left_child = (yyvsp[(1) - (3)]);
			    (yyvsp[(1) - (3)])->right_sibling = (yyvsp[(3) - (3)]);
			;}
    break;

  case 94:
#line 700 "C57.y"
    {
			    ast_node t = create_ast_node(OP_NEQ);
			    (yyval) = t;
			    t->left_child = (yyvsp[(1) - (3)]);
			    (yyvsp[(1) - (3)])->right_sibling = (yyvsp[(3) - (3)]);
			;}
    break;

  case 95:
#line 706 "C57.y"
    {
			    ast_node t = create_ast_node(OP_AND);
			    (yyval) = t;
			    t->left_child = (yyvsp[(1) - (3)]);
			    (yyvsp[(1) - (3)])->right_sibling = (yyvsp[(3) - (3)]);
			;}
    break;

  case 96:
#line 712 "C57.y"
    {
			    ast_node t = create_ast_node(OP_OR);
			    (yyval) = t;
			    t->left_child = (yyvsp[(1) - (3)]);
			    (yyvsp[(1) - (3)])->right_sibling = (yyvsp[(3) - (3)]);
			;}
    break;

  case 97:
#line 718 "C57.y"
    {
			    ast_node t = create_ast_node(OP_NOT);
			    (yyval) = t;
			    t->left_child = (yyvsp[(2) - (2)]);
			;}
    break;

  case 98:
#line 723 "C57.y"
    {
			    ast_node t = create_ast_node(OP_MINUS);
			    (yyval) = t;
			    t->left_child = (yyvsp[(2) - (2)]);
			;}
    break;

  case 99:
#line 728 "C57.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 100:
#line 729 "C57.y"
    {
			    ast_node t = create_ast_node(OP_INC_PRE);
			    t->left_child = (yyvsp[(2) - (2)]);
			    (yyval) = t;
			;}
    break;

  case 101:
#line 734 "C57.y"
    {
			    ast_node t = create_ast_node(OP_DEC_PRE);
			    t->left_child = (yyvsp[(2) - (2)]);
			    (yyval) = t;
			;}
    break;

  case 102:
#line 739 "C57.y"
    {
			    ast_node t = create_ast_node(OP_INC_POST);
			    t->left_child = (yyvsp[(1) - (2)]);
			    (yyval) = t;
			;}
    break;

  case 103:
#line 744 "C57.y"
    {
			    ast_node t = create_ast_node(OP_DEC_POST);
			    t->left_child = (yyvsp[(1) - (2)]);
			    (yyval) = t;
			;}
    break;

  case 104:
#line 749 "C57.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 105:
#line 750 "C57.y"
    {
				ast_node t = create_ast_node(INT_LITERAL);
				t->value.int_value = atoi(savedLiteralText);
				(yyval) = t;
			;}
    break;

  case 106:
#line 755 "C57.y"
    {
				ast_node t = create_ast_node(DOUBLE_LITERAL);
				t->value.double_value = atof(savedLiteralText);
				(yyval) = t;
			;}
    break;

  case 107:
#line 760 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 108:
#line 761 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 109:
#line 765 "C57.y"
    {
			       ast_node t = create_ast_node(SIZE_OF);
			       (yyval) = t;
			       t->left_child = (yyvsp[(3) - (4)]);
			;}
    break;

  case 110:
#line 770 "C57.y"
    {
			       ast_node t = create_ast_node(SIZE_OF);
			       (yyval) = t;
			       t->left_child = (yyvsp[(3) - (4)]);
			;}
    break;

  case 111:
#line 778 "C57.y"
    {
			   ast_node t = create_ast_node(IDENTIFIER);
			   t->value.string = strdup(savedIdText);
			   (yyval) = t;
			;}
    break;

  case 112:
#line 782 "C57.y"
    {
			   ast_node t = create_ast_node(CALL);
			   t->left_child = (yyvsp[(2) - (5)]);
			   (yyvsp[(2) - (5)])->right_sibling = (yyvsp[(4) - (5)]);
			   (yyval) = t;
			;}
    break;

  case 113:
#line 791 "C57.y"
    {
				ast_node t = create_ast_node(ARGS);
				(yyval) = t;
				t->left_child = (yyvsp[(1) - (1)]);
			;}
    break;

  case 114:
#line 796 "C57.y"
    {(yyval) = NULL;;}
    break;

  case 115:
#line 800 "C57.y"
    {
				ast_node t = (yyvsp[(1) - (3)]);
				if (t!=NULL){
				   while (t->right_sibling != NULL)
				   	 t = t->right_sibling;
				   t->right_sibling = (yyvsp[(3) - (3)]);
				   (yyval) = (yyvsp[(1) - (3)]);
				}else
				   (yyval) = (yyvsp[(3) - (3)]);
			;}
    break;

  case 116:
#line 810 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;


/* Line 1267 of yacc.c.  */
#line 2729 "C57.tab.c"
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


#line 816 "C57.y"
	/* code section */
void set_debug()
{
	extern int yydebug;
	yydebug = 1;
}

void yyerror(char const* s)
{
	fprintf(stderr, "%s\n", s);
}

