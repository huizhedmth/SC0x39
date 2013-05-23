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
int g_scope = 0;		/* current scope */


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
#define YYLAST   571

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNRULES -- Number of states.  */
#define YYNSTATES  219

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
     122,   127,   128,   134,   137,   138,   141,   142,   144,   146,
     148,   150,   152,   154,   156,   158,   160,   162,   164,   166,
     168,   170,   176,   184,   190,   198,   208,   210,   211,   214,
     218,   222,   226,   230,   233,   236,   241,   245,   251,   254,
     256,   260,   262,   264,   265,   271,   275,   279,   283,   287,
     291,   295,   299,   303,   307,   311,   315,   319,   323,   326,
     329,   331,   334,   337,   340,   343,   347,   349,   351,   353,
     355,   360,   365,   366,   372,   374,   375,   379
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      58,     0,    -1,    59,    -1,    59,    60,    -1,    60,    -1,
      61,    -1,    69,    -1,    70,    -1,    63,    64,    49,    -1,
      -1,    20,    62,    63,    64,    49,    -1,     5,    -1,    11,
      -1,    64,    34,    65,    -1,    65,    -1,    29,    -1,    -1,
      29,    35,    66,    96,    -1,    -1,    29,    50,    67,    96,
      51,    -1,    63,    29,    -1,     7,    29,    -1,    68,    52,
      71,    53,    77,    -1,    68,    52,    71,    53,    49,    -1,
      68,    52,    74,    53,    49,    -1,    72,    -1,     7,    -1,
      -1,    72,    34,    73,    -1,    73,    -1,    63,    29,    -1,
      20,    63,    29,    -1,    63,    29,    50,    51,    -1,    20,
      63,    29,    50,    51,    -1,    75,    -1,    75,    34,    76,
      -1,    76,    -1,    63,    -1,    20,    63,    -1,    63,    50,
      51,    -1,    20,    63,    50,    51,    -1,    -1,    54,    78,
      79,    80,    55,    -1,    79,    61,    -1,    -1,    80,    81,
      -1,    -1,    95,    -1,    77,    -1,    82,    -1,    83,    -1,
      84,    -1,    85,    -1,    87,    -1,    88,    -1,    89,    -1,
      90,    -1,    91,    -1,    94,    -1,    92,    -1,    93,    -1,
       4,    52,    96,    53,    81,    -1,     4,    52,    96,    53,
      81,     3,    81,    -1,     8,    52,    96,    53,    81,    -1,
      10,    81,     8,    52,    96,    53,    49,    -1,     9,    52,
      86,    49,    86,    49,    86,    53,    81,    -1,    96,    -1,
      -1,     6,    49,    -1,     6,    96,    49,    -1,    12,    97,
      49,    -1,    13,    96,    49,    -1,    13,    32,    49,    -1,
      14,    49,    -1,    15,    49,    -1,    17,    30,    56,    81,
      -1,    18,    56,    81,    -1,    16,    52,    96,    53,    81,
      -1,    96,    49,    -1,    49,    -1,    97,    35,    96,    -1,
      99,    -1,    29,    -1,    -1,    29,    98,    50,    96,    51,
      -1,    96,    38,    96,    -1,    96,    39,    96,    -1,    96,
      40,    96,    -1,    96,    41,    96,    -1,    96,    42,    96,
      -1,    96,    36,    96,    -1,    96,    27,    96,    -1,    96,
      37,    96,    -1,    96,    28,    96,    -1,    96,    21,    96,
      -1,    96,    22,    96,    -1,    96,    25,    96,    -1,    96,
      26,    96,    -1,    43,    96,    -1,    39,    96,    -1,    97,
      -1,    23,    97,    -1,    24,    97,    -1,    97,    23,    -1,
      97,    24,    -1,    52,    96,    53,    -1,    30,    -1,    31,
      -1,   100,    -1,   101,    -1,    19,    52,    63,    53,    -1,
      19,    52,    96,    53,    -1,    -1,    29,   102,    52,   103,
      53,    -1,   104,    -1,    -1,   104,    34,    96,    -1,    96,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    93,    93,   102,   112,   116,   117,   118,   122,   125,
     125,   132,   139,   149,   159,   163,   184,   184,   208,   208,
     238,   248,   265,   281,   288,   298,   304,   313,   325,   335,
     339,   355,   371,   389,   410,   419,   429,   433,   443,   454,
     466,   482,   482,   499,   509,   513,   523,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   544,   552,   563,   573,   583,   594,   595,   603,   608,
     617,   626,   632,   644,   652,   660,   670,   679,   689,   690,
     698,   705,   709,   717,   717,   731,   738,   745,   752,   759,
     766,   773,   780,   787,   794,   801,   808,   815,   822,   828,
     834,   835,   841,   847,   853,   859,   860,   866,   872,   873,
     877,   883,   892,   892,   908,   914,   918,   928
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
  "informal_param", "compound_statement", "@4", "local_declarations",
  "statement_list", "statement", "if_statement", "while_statement",
  "do_while_statement", "for_statement", "for_header_expression",
  "return_statement", "read_statement", "print_statement",
  "break_statement", "continue_statement", "case_statement",
  "default_statement", "switch_statement", "expression_statement",
  "expression", "var", "@5", "r_value", "sizeof_expression", "call", "@6",
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
      76,    78,    77,    79,    79,    80,    80,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    82,    82,    83,    84,    85,    86,    86,    87,    87,
      88,    89,    89,    90,    91,    92,    93,    94,    95,    95,
      96,    96,    97,    98,    97,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
     100,   100,   102,   101,   103,   103,   104,   104
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     3,     0,
       5,     1,     1,     3,     1,     1,     0,     4,     0,     5,
       2,     2,     5,     5,     5,     1,     1,     0,     3,     1,
       2,     3,     4,     5,     1,     3,     1,     1,     2,     3,
       4,     0,     5,     2,     0,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     7,     5,     7,     9,     1,     0,     2,     3,
       3,     3,     3,     2,     2,     4,     3,     5,     2,     1,
       3,     1,     1,     0,     5,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       1,     2,     2,     2,     2,     3,     1,     1,     1,     1,
       4,     4,     0,     5,     1,     0,     3,     1
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
       0,    82,   106,   107,     0,     0,     0,    17,   100,    81,
     108,   109,     0,    31,     0,     0,    39,    23,    41,    22,
       0,     0,    28,    24,     0,    37,    35,     0,    82,   101,
     102,     0,     0,    99,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     104,     0,    19,     0,    40,    32,    44,     0,    38,     0,
       0,     0,   115,   105,    94,    95,    96,    97,    91,    93,
      90,    92,    85,    86,    87,    88,    89,    80,    33,    46,
     110,   111,     0,   117,     0,   114,    43,     0,     0,    84,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    79,    42,    48,    45,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    59,    60,    58,
      47,     0,   116,     0,    68,     0,     0,    67,     0,     0,
       0,     0,    73,    74,     0,     0,     0,    78,     0,    69,
       0,     0,    66,     0,    70,    72,    71,     0,     0,    76,
       0,     0,    67,     0,     0,    75,    61,    63,     0,     0,
      77,     0,    67,     0,    62,     0,    64,     0,    65
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    14,     9,    18,    19,    37,
      38,    10,    11,    12,    29,    30,    31,    32,    33,    34,
     156,   106,   129,   138,   157,   158,   159,   160,   161,   191,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      58,    81,    59,    60,    61,    82,   134,   135
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -171
static const yytype_int16 yypact[] =
{
      61,  -171,   -17,  -171,  -171,     4,    61,  -171,  -171,     7,
     -14,  -171,  -171,  -171,    71,  -171,  -171,    -5,   -25,  -171,
      81,    17,  -171,  -171,    17,  -171,  -171,    71,   -24,     9,
      35,  -171,    18,    39,  -171,   -21,    -1,   195,   195,  -171,
     -23,    37,    34,    40,    23,    46,    73,  -171,    47,    69,
      69,   -42,  -171,  -171,   195,   195,   195,   478,    79,  -171,
    -171,  -171,   359,    57,    72,    75,  -171,  -171,  -171,  -171,
      71,    95,  -171,  -171,    71,    80,  -171,    86,    84,  -171,
    -171,    85,    91,  -171,  -171,   227,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,  -171,
    -171,   195,  -171,    94,  -171,  -171,  -171,   102,    87,    98,
     249,   195,   195,  -171,   529,   529,   522,   500,   146,   146,
     146,   146,   120,   120,  -171,  -171,  -171,   478,  -171,   122,
    -171,  -171,   381,   478,   114,   134,  -171,    17,   140,  -171,
    -171,   195,   121,    -8,   124,   125,   192,    69,    89,   123,
     129,   128,   144,   126,  -171,  -171,  -171,  -171,  -171,  -171,
    -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,
    -171,   403,   478,   195,  -171,   428,   195,   195,   173,   141,
     142,   453,  -171,  -171,   195,   137,   192,  -171,   271,  -171,
     293,   148,   478,   147,  -171,  -171,  -171,   315,   192,  -171,
     192,   192,   195,   195,   192,  -171,   200,  -171,   163,   337,
    -171,   192,   195,   164,  -171,   167,  -171,   192,  -171
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -171,  -171,  -171,   211,    99,  -171,    -7,   206,   205,  -171,
    -171,  -171,  -171,  -171,  -171,  -171,   186,  -171,  -171,   187,
     189,  -171,  -171,  -171,  -121,  -171,  -171,  -171,  -171,  -170,
    -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,   -37,
     -47,  -171,  -171,  -171,  -171,  -171,  -171,  -171
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -113
static const yytype_int16 yytable[] =
{
      57,    62,    79,    80,    15,    41,    63,    21,   -83,    24,
    -112,    48,    13,    28,    22,    49,    50,    83,    84,    85,
      40,    51,    52,    53,    25,   178,    42,    64,     1,    23,
      22,    54,   208,    24,     3,    55,    17,    71,    20,    75,
     110,   174,   215,    70,    56,    23,    35,   -20,    47,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    43,   107,   127,   199,     1,   108,     2,    44,
     109,    45,     3,    46,   132,   133,     1,   205,     1,   206,
     207,     4,     3,   210,     3,    66,     1,    65,    26,    67,
     214,     1,     3,    74,    68,    73,   218,     3,    78,    77,
     179,    27,    99,   100,   172,    48,   175,   103,    48,    49,
      50,   181,    49,    50,   101,    51,    52,    53,    51,    52,
      53,   180,   137,   104,    41,    54,   105,     1,    54,    55,
      42,    63,    55,     3,   -83,   111,   188,    64,    56,   190,
     192,    56,     4,   112,   142,   128,   143,   197,   144,   145,
     146,   130,   147,   148,   149,   150,   151,   152,   153,    48,
      96,    97,    98,    49,    50,   192,   209,   140,   141,    51,
      52,    53,   182,   173,   185,   192,   176,   177,   183,    54,
     184,   193,   186,    55,    94,    95,    96,    97,    98,   154,
     194,   195,    56,   198,    68,   155,   142,   202,   143,   203,
     144,   145,   146,   211,   147,   148,   149,   150,   151,   152,
     153,    48,   212,   216,    48,    49,    50,    16,    49,    50,
     217,    51,    52,    53,    51,    52,    53,    36,   136,    39,
      72,    54,    69,    76,    54,    55,     0,     0,    55,     0,
       0,   154,     0,     0,    56,     0,    68,    56,    86,    87,
       0,     0,    88,    89,    90,    91,     0,     0,     0,     0,
       0,     0,     0,    92,    93,    94,    95,    96,    97,    98,
      86,    87,     0,     0,    88,    89,    90,    91,     0,     0,
     113,     0,     0,     0,     0,    92,    93,    94,    95,    96,
      97,    98,    86,    87,     0,     0,    88,    89,    90,    91,
       0,     0,   131,     0,     0,     0,     0,    92,    93,    94,
      95,    96,    97,    98,    86,    87,     0,     0,    88,    89,
      90,    91,     0,     0,   200,     0,     0,     0,     0,    92,
      93,    94,    95,    96,    97,    98,    86,    87,     0,     0,
      88,    89,    90,    91,     0,     0,   201,     0,     0,     0,
       0,    92,    93,    94,    95,    96,    97,    98,    86,    87,
       0,     0,    88,    89,    90,    91,     0,     0,   204,     0,
       0,     0,     0,    92,    93,    94,    95,    96,    97,    98,
      86,    87,     0,     0,    88,    89,    90,    91,     0,     0,
     213,     0,     0,     0,     0,    92,    93,    94,    95,    96,
      97,    98,    86,    87,     0,     0,    88,    89,    90,    91,
     102,     0,     0,     0,     0,     0,     0,    92,    93,    94,
      95,    96,    97,    98,    86,    87,     0,     0,    88,    89,
      90,    91,   139,     0,     0,     0,     0,     0,     0,    92,
      93,    94,    95,    96,    97,    98,     0,     0,     0,    86,
      87,     0,   187,    88,    89,    90,    91,     0,     0,     0,
       0,     0,     0,     0,    92,    93,    94,    95,    96,    97,
      98,     0,     0,     0,    86,    87,     0,   189,    88,    89,
      90,    91,     0,     0,     0,     0,     0,     0,     0,    92,
      93,    94,    95,    96,    97,    98,     0,     0,     0,    86,
      87,     0,   196,    88,    89,    90,    91,     0,     0,     0,
       0,     0,     0,     0,    92,    93,    94,    95,    96,    97,
      98,    86,    87,     0,     0,    88,     0,    90,    91,     0,
       0,     0,     0,     0,     0,     0,    92,    93,    94,    95,
      96,    97,    98,    86,    87,     0,     0,     0,     0,    90,
      91,     0,     0,     0,     0,     0,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    92,    93,    94,    95,    96,
      97,    98
};

static const yytype_int16 yycheck[] =
{
      37,    38,    49,    50,     0,    29,    29,    14,    50,    34,
      52,    19,    29,    20,    35,    23,    24,    54,    55,    56,
      27,    29,    30,    31,    49,   146,    50,    50,     5,    50,
      35,    39,   202,    34,    11,    43,    29,    44,    52,    46,
      77,    49,   212,    20,    52,    50,    29,    52,    49,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    53,    70,   101,   186,     5,    74,     7,    34,
      77,    53,    11,    34,   111,   112,     5,   198,     5,   200,
     201,    20,    11,   204,    11,    51,     5,    50,     7,    49,
     211,     5,    11,    20,    54,    49,   217,    11,    29,    52,
     147,    20,    23,    24,   141,    19,   143,    50,    19,    23,
      24,   148,    23,    24,    35,    29,    30,    31,    29,    30,
      31,    32,   129,    51,    29,    39,    51,     5,    39,    43,
      50,    29,    43,    11,    50,    50,   173,    50,    52,   176,
     177,    52,    20,    52,     4,    51,     6,   184,     8,     9,
      10,    53,    12,    13,    14,    15,    16,    17,    18,    19,
      40,    41,    42,    23,    24,   202,   203,    53,    34,    29,
      30,    31,    49,    52,    30,   212,    52,    52,    49,    39,
      52,     8,    56,    43,    38,    39,    40,    41,    42,    49,
      49,    49,    52,    56,    54,    55,     4,    49,     6,    52,
       8,     9,    10,     3,    12,    13,    14,    15,    16,    17,
      18,    19,    49,    49,    19,    23,    24,     6,    23,    24,
      53,    29,    30,    31,    29,    30,    31,    21,   129,    24,
      44,    39,    43,    46,    39,    43,    -1,    -1,    43,    -1,
      -1,    49,    -1,    -1,    52,    -1,    54,    52,    21,    22,
      -1,    -1,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    39,    40,    41,    42,
      21,    22,    -1,    -1,    25,    26,    27,    28,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      41,    42,    21,    22,    -1,    -1,    25,    26,    27,    28,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    42,    21,    22,    -1,    -1,    25,    26,
      27,    28,    -1,    -1,    53,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    41,    42,    21,    22,    -1,    -1,
      25,    26,    27,    28,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    36,    37,    38,    39,    40,    41,    42,    21,    22,
      -1,    -1,    25,    26,    27,    28,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    36,    37,    38,    39,    40,    41,    42,
      21,    22,    -1,    -1,    25,    26,    27,    28,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      41,    42,    21,    22,    -1,    -1,    25,    26,    27,    28,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    42,    21,    22,    -1,    -1,    25,    26,
      27,    28,    51,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    -1,    21,
      22,    -1,    49,    25,    26,    27,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    21,    22,    -1,    49,    25,    26,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    -1,    21,
      22,    -1,    49,    25,    26,    27,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,    41,
      42,    21,    22,    -1,    -1,    25,    -1,    27,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      40,    41,    42,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    -1,    -1,    -1,    -1,    -1,    27,    28,    36,    37,
      38,    39,    40,    41,    42,    36,    37,    38,    39,    40,
      41,    42
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
      24,    29,    30,    31,    39,    43,    52,    96,    97,    99,
     100,   101,    96,    29,    50,    50,    51,    49,    54,    77,
      20,    63,    73,    49,    20,    63,    76,    52,    29,    97,
      97,    98,   102,    96,    96,    96,    21,    22,    25,    26,
      27,    28,    36,    37,    38,    39,    40,    41,    42,    23,
      24,    35,    51,    50,    51,    51,    78,    63,    63,    63,
      96,    50,    52,    53,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    51,    79,
      53,    53,    96,    96,   103,   104,    61,    63,    80,    51,
      53,    34,     4,     6,     8,     9,    10,    12,    13,    14,
      15,    16,    17,    18,    49,    55,    77,    81,    82,    83,
      84,    85,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    96,    52,    49,    96,    52,    52,    81,    97,
      32,    96,    49,    49,    52,    30,    56,    49,    96,    49,
      96,    86,    96,     8,    49,    49,    49,    96,    56,    81,
      53,    53,    49,    52,    53,    81,    81,    81,    86,    96,
      81,     3,    49,    53,    81,    86,    49,    53,    81
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
				(yyval)->scope = g_scope;
			;}
    break;

  case 3:
#line 102 "C57.y"
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
#line 112 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 5:
#line 116 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 6:
#line 117 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 7:
#line 118 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 8:
#line 122 "C57.y"
    { 
				(yyval) = (yyvsp[(2) - (3)]);
			;}
    break;

  case 9:
#line 125 "C57.y"
    {g_flag_const = 1;;}
    break;

  case 10:
#line 125 "C57.y"
    { 
			      	(yyval) = (yyvsp[(4) - (5)]);
				g_flag_const = 0;
			;}
    break;

  case 11:
#line 132 "C57.y"
    {
				ast_node t = create_ast_node(TYPE);
				t->value.string = strdup("INT");
				strcpy(g_type, t->value.string);
				(yyval) = t;
				(yyval)->scope = g_scope;
			;}
    break;

  case 12:
#line 139 "C57.y"
    {
				ast_node t = create_ast_node(TYPE);
				t->value.string = strdup("DOUBLE");
				strcpy(g_type, t->value.string);
				(yyval) = t;
				(yyval)->scope = g_scope;
			;}
    break;

  case 13:
#line 149 "C57.y"
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
#line 159 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 15:
#line 163 "C57.y"
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
				t3->scope = g_scope;	/* save scope */
				t3->lineNumber = lineNumber;	/* save line number */
				t->scope = g_scope;
				t1->scope = g_scope;
				t2->scope = g_scope;
			;}
    break;

  case 16:
#line 184 "C57.y"
    {
				ast_node t = create_ast_node(IDENTIFIER);
				t->value.string = strdup(savedIdText);
				(yyval) = t;
				t->scope = g_scope;
				t->lineNumber = lineNumber;
			;}
    break;

  case 17:
#line 190 "C57.y"
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
				t->scope = g_scope;
				t1->scope = g_scope;
				t2->scope = g_scope;
			;}
    break;

  case 18:
#line 208 "C57.y"
    {
				ast_node t = create_ast_node(IDENTIFIER);
				t->value.string = strdup(savedIdText);
				(yyval) = t;
				t->scope = g_scope;
				t->lineNumber = lineNumber;
			;}
    break;

  case 19:
#line 214 "C57.y"
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
				t->scope = g_scope;
				t1->scope = g_scope;
				t2->scope = g_scope;
			;}
    break;

  case 20:
#line 238 "C57.y"
    {
				ast_node t = create_ast_node(FUNC_HEADER);
				t->left_child = (yyvsp[(1) - (2)]);
				ast_node t1 = create_ast_node(IDENTIFIER);
				t1->value.string = strdup(savedIdText);
				(yyvsp[(1) - (2)])->right_sibling = t1;
				(yyval) = t;
				t->scope = g_scope;
				t1->lineNumber = lineNumber;
			;}
    break;

  case 21:
#line 248 "C57.y"
    {
			     	ast_node t = create_ast_node(FUNC_HEADER);
				ast_node t1 = create_ast_node(TYPE);
				t1->value.string = strdup("VOID");
				t->left_child = t1;
				(yyval) = t;
				ast_node t2 = create_ast_node(IDENTIFIER);
				t2->value.string = strdup(savedIdText);
				t1->right_sibling = t2;
				t->scope = g_scope;
				t1->scope = g_scope;
				t2->scope = g_scope;
				t2->lineNumber = lineNumber;
			;}
    break;

  case 22:
#line 265 "C57.y"
    {
				ast_node t = create_ast_node(FUNC_DECL);
				(yyval) = t;
				t->left_child = (yyvsp[(1) - (5)]);
				(yyvsp[(1) - (5)])->right_sibling = (yyvsp[(3) - (5)]);
				(yyvsp[(3) - (5)])->right_sibling = (yyvsp[(5) - (5)]);
				t->scope = g_scope;
				t->lineNumber = lineNumber;
			;}
    break;

  case 23:
#line 281 "C57.y"
    {
				ast_node t = create_ast_node(FUNC_PROTO);
				(yyval) = t;
				t->left_child = (yyvsp[(1) - (5)]);
				t->left_child->right_sibling = (yyvsp[(3) - (5)]);
				t->scope = g_scope;
			;}
    break;

  case 24:
#line 288 "C57.y"
    {
				ast_node t = create_ast_node(FUNC_PROTO);
				(yyval) = t;
				t->left_child = (yyvsp[(1) - (5)]);
				t->left_child->right_sibling = (yyvsp[(3) - (5)]);
				t->scope = g_scope;
			;}
    break;

  case 25:
#line 298 "C57.y"
    {
				ast_node t = create_ast_node(FUNC_PARAMS);
				(yyval) = t;
				t->left_child = (yyvsp[(1) - (1)]);
				t->scope = g_scope;
			;}
    break;

  case 26:
#line 304 "C57.y"
    {
				ast_node t = create_ast_node(FUNC_PARAMS);
				(yyval) = t;
				ast_node t1 = create_ast_node(TYPE);
				t1->value.string = strdup("VOID");
				t->left_child = t1;
				t->scope = g_scope;
				t1->scope = g_scope;
			;}
    break;

  case 27:
#line 313 "C57.y"
    {
				ast_node t = create_ast_node(FUNC_PARAMS);
				(yyval) = t;
				ast_node t1 = create_ast_node(TYPE);
				t1->value.string = strdup("VOID");
				t->left_child = t1;
				t->scope = g_scope;
				t1->scope = g_scope;
			;}
    break;

  case 28:
#line 325 "C57.y"
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
#line 335 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 30:
#line 339 "C57.y"
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
				t->scope = g_scope;
				t1->scope = g_scope;
				t2->scope = g_scope;
				t->lineNumber = lineNumber;
			;}
    break;

  case 31:
#line 355 "C57.y"
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
				t->scope = g_scope;
				t1->scope = g_scope;
				t2->scope = g_scope;
				t->lineNumber = lineNumber;
			;}
    break;

  case 32:
#line 371 "C57.y"
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
				t->scope = g_scope;								
				t1->scope = g_scope;
				t2->scope = g_scope;
				t->lineNumber = lineNumber;
			;}
    break;

  case 33:
#line 389 "C57.y"
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
				t->scope = g_scope;
				t1->scope = g_scope;
				t2->scope = g_scope;
				t->lineNumber = lineNumber;
			;}
    break;

  case 34:
#line 410 "C57.y"
    {
				ast_node t = create_ast_node(FUNC_PARAMS);
				(yyval) = t;
				t->left_child = (yyvsp[(1) - (1)]);
				t->scope = g_scope;
 			;}
    break;

  case 35:
#line 419 "C57.y"
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
#line 429 "C57.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 37:
#line 433 "C57.y"
    {
				ast_node t2 = create_ast_node(PARAM);
				ast_node t = create_ast_node(STORAGE);
				t->value.string = strdup("NORMAL");
				(yyval) = t2;
				t2->left_child = t;
				t->right_sibling = (yyvsp[(1) - (1)]);
				t->scope = g_scope;
				t2->scope = g_scope;
			;}
    break;

  case 38:
#line 443 "C57.y"
    {
				ast_node t2 = create_ast_node(PARAM);
				ast_node t1 = create_ast_node(STORAGE);	
				t1->value.string = strdup("CONST");
				
				(yyval) = t2;
				t2->left_child = t1;
				t1->right_sibling = (yyvsp[(2) - (2)]);
				t1->scope = g_scope;
				t2->scope = g_scope;
			;}
    break;

  case 39:
#line 454 "C57.y"
    {
				ast_node t2 = create_ast_node(PARAM);
				ast_node t1 = create_ast_node(STORAGE);	
				t1->value.string = strdup("NORMAL");
				(yyval) = t2;
				t2->left_child = t1;
				(yyvsp[(1) - (3)])->value.string = (char*)realloc((yyvsp[(1) - (3)])->value.string, 15);
				strcat((yyvsp[(1) - (3)])->value.string, " ARRAY");
				t1->right_sibling = (yyvsp[(1) - (3)]);
				t1->scope = g_scope;
				t2->scope = g_scope;
			;}
    break;

  case 40:
#line 466 "C57.y"
    {
				ast_node t2 = create_ast_node(PARAM);
				(yyvsp[(2) - (4)])->value.string = (char*)realloc((yyvsp[(2) - (4)])->value.string, 15);
				strcat((yyvsp[(2) - (4)])->value.string, " ARRAY");
				ast_node t1 = create_ast_node(STORAGE);
			        t1->value.string = strdup("CONST");
				
				(yyval) = t2;
				t2->left_child = t1;
				t1->right_sibling = (yyvsp[(2) - (4)]);
				t1->scope = g_scope;
				t2->scope = g_scope;
			;}
    break;

  case 41:
#line 482 "C57.y"
    {g_scope++;;}
    break;

  case 42:
#line 482 "C57.y"
    {
			    	ast_node t = create_ast_node(CMPD_STMT);
				ast_node t1 = create_ast_node(LOCAL_DECL);
				ast_node t2 = create_ast_node(STMT_LIST);
				t->left_child = t1;
				t1->right_sibling = t2;
				t1->left_child = (yyvsp[(3) - (5)]);
				t2->left_child = (yyvsp[(4) - (5)]);
				(yyval) = t;
				t->scope = g_scope;
				t1->scope = g_scope;
				t2->scope = g_scope;
				g_scope--;
			;}
    break;

  case 43:
#line 499 "C57.y"
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

  case 44:
#line 509 "C57.y"
    {(yyval) = NULL;;}
    break;

  case 45:
#line 513 "C57.y"
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

  case 46:
#line 523 "C57.y"
    {(yyval) = NULL;}
    break;

  case 47:
#line 527 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 48:
#line 528 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 49:
#line 529 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 50:
#line 530 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 51:
#line 531 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 52:
#line 532 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 53:
#line 533 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 54:
#line 534 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 55:
#line 535 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 56:
#line 536 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 57:
#line 537 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 58:
#line 538 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 59:
#line 539 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 60:
#line 540 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 61:
#line 544 "C57.y"
    {
			   ast_node t = create_ast_node(IF_STMT);
			   (yyval) = t;
			   t->left_child = (yyvsp[(3) - (5)]);
			   (yyvsp[(3) - (5)])->right_sibling = (yyvsp[(5) - (5)]);
				t->scope = g_scope;
			;}
    break;

  case 62:
#line 552 "C57.y"
    {
			   ast_node t = create_ast_node(IF_ELSE_STMT);
			   (yyval) = t;
			   t->left_child = (yyvsp[(3) - (7)]);
			   (yyvsp[(3) - (7)])->right_sibling = (yyvsp[(5) - (7)]);
			   (yyvsp[(5) - (7)])->right_sibling = (yyvsp[(7) - (7)]);
				t->scope = g_scope;
			;}
    break;

  case 63:
#line 563 "C57.y"
    {
			      ast_node t = create_ast_node(WHILE_STMT);
			      (yyval) = t;
			      t->left_child = (yyvsp[(3) - (5)]);
			      (yyvsp[(3) - (5)])->right_sibling = (yyvsp[(5) - (5)]);
				t->scope = g_scope;
			;}
    break;

  case 64:
#line 573 "C57.y"
    {
			   ast_node t = create_ast_node(DO_WHILE_STMT);
			   (yyval) = t;
			   t->left_child = (yyvsp[(2) - (7)]);
			   (yyvsp[(2) - (7)])->right_sibling = (yyvsp[(5) - (7)]);
				t->scope = g_scope;
			;}
    break;

  case 65:
#line 583 "C57.y"
    {
			    ast_node t = create_ast_node(FOR_STMT);
			    (yyval) = t;
			    t->left_child = (yyvsp[(3) - (9)]);
			    (yyvsp[(3) - (9)])->right_sibling = (yyvsp[(5) - (9)]);
			    (yyvsp[(5) - (9)])->right_sibling = (yyvsp[(9) - (9)]);
			    (yyvsp[(9) - (9)])->right_sibling = (yyvsp[(7) - (9)]);
				t->scope = g_scope;
			;}
    break;

  case 67:
#line 595 "C57.y"
    {
				ast_node t = create_ast_node(EMPTY);
				(yyval) = t;
				t->scope = g_scope;
			;}
    break;

  case 68:
#line 603 "C57.y"
    {
			       ast_node t = create_ast_node(RETURN_STMT);
			       (yyval) = t;
				t->scope = g_scope;
			;}
    break;

  case 69:
#line 608 "C57.y"
    {
			       ast_node t = create_ast_node(RETURN_STMT);
			       (yyval) = t;
			       t->left_child = (yyvsp[(2) - (3)]);
				t->scope = g_scope;
			;}
    break;

  case 70:
#line 617 "C57.y"
    {
			     ast_node t = create_ast_node(READ_STMT);
			     (yyval) = t;
			     t->left_child = (yyvsp[(2) - (3)]);
				t->scope = g_scope;
			;}
    break;

  case 71:
#line 626 "C57.y"
    {
			      ast_node t = create_ast_node(PRINT_STMT);
			      (yyval) = t;
			      t->left_child = (yyvsp[(2) - (3)]);
				t->scope = g_scope;
			;}
    break;

  case 72:
#line 632 "C57.y"
    {
			      ast_node t = create_ast_node(PRINT_STMT);
			      (yyval) = t;  
			      ast_node t1 = create_ast_node(STR_LITERAL);
			      t1->value.string = strdup(savedLiteralText);
			      t->left_child = t1;
				t->scope = g_scope;
				t1->scope = g_scope;
			;}
    break;

  case 73:
#line 644 "C57.y"
    {
			      ast_node t = create_ast_node(BREAK_STMT);
			      (yyval) = t;
				t->scope = g_scope;
			;}
    break;

  case 74:
#line 652 "C57.y"
    {
			      ast_node t = create_ast_node(CONTINUE_STMT);
			      (yyval) = t;
				t->scope = g_scope;
			;}
    break;

  case 75:
#line 660 "C57.y"
    {
			     ast_node t = create_ast_node(CASE_STMT);
			     (yyval) = t;
			     t->value.int_value = atoi(savedLiteralText);
			     t->right_sibling = (yyvsp[(4) - (4)]);
				t->scope = g_scope;
			;}
    break;

  case 76:
#line 670 "C57.y"
    {
			     ast_node t = create_ast_node(DEFAULT_STMT);
			     (yyval) = t;
			     t->right_sibling = (yyvsp[(3) - (3)]);
				t->scope = g_scope;
			;}
    break;

  case 77:
#line 679 "C57.y"
    {
			     ast_node t = create_ast_node(SWITCH_STMT);
			     (yyval) = t;
			     t->left_child = (yyvsp[(3) - (5)]);
			     (yyvsp[(3) - (5)])->right_sibling = (yyvsp[(5) - (5)]);
				t->scope = g_scope;
			;}
    break;

  case 78:
#line 689 "C57.y"
    {(yyval) = (yyvsp[(1) - (2)]);;}
    break;

  case 79:
#line 690 "C57.y"
    {
				ast_node t = create_ast_node(EMPTY);
				(yyval) = t;
				t->scope = g_scope;
			;}
    break;

  case 80:
#line 698 "C57.y"
    {
			    ast_node t = create_ast_node(OP_ASSIGN);
			    (yyval) = t;
			    t->left_child = (yyvsp[(1) - (3)]);
			    (yyvsp[(1) - (3)])->right_sibling = (yyvsp[(3) - (3)]);
				t->scope = g_scope;
			;}
    break;

  case 81:
#line 705 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 82:
#line 709 "C57.y"
    {
				ast_node t = create_ast_node(IDENTIFIER);
				t->value.string = strdup(savedIdText);
				(yyval) = t;
				t->scope = g_scope;
				t->lineNumber = lineNumber;
				t->scope = g_scope;
			;}
    break;

  case 83:
#line 717 "C57.y"
    {			
			   	ast_node t = create_ast_node(IDENTIFIER);
				t->value.string = strdup(savedIdText);
				(yyval) = t;
				t->scope = g_scope;
				t->lineNumber = lineNumber;
				t->scope = g_scope;
			;}
    break;

  case 84:
#line 724 "C57.y"
    {
				(yyval) = (yyvsp[(2) - (5)]);
				(yyval)->left_child = (yyvsp[(4) - (5)]);
			;}
    break;

  case 85:
#line 731 "C57.y"
    {
			    ast_node t = create_ast_node(OP_PLUS);
			    (yyval) = t;
			    t->left_child = (yyvsp[(1) - (3)]);
			    (yyvsp[(1) - (3)])->right_sibling = (yyvsp[(3) - (3)]);
				t->scope = g_scope;
			;}
    break;

  case 86:
#line 738 "C57.y"
    {
			    ast_node t = create_ast_node(OP_MINUS);
			    (yyval) = t;
			    t->left_child = (yyvsp[(1) - (3)]);
			    (yyvsp[(1) - (3)])->right_sibling = (yyvsp[(3) - (3)]);
				t->scope = g_scope;
			;}
    break;

  case 87:
#line 745 "C57.y"
    {
			    ast_node t = create_ast_node(OP_TIMES);
			    (yyval) = t;
			    t->left_child = (yyvsp[(1) - (3)]);
			    (yyvsp[(1) - (3)])->right_sibling = (yyvsp[(3) - (3)]);
				t->scope = g_scope;
			;}
    break;

  case 88:
#line 752 "C57.y"
    {
			    ast_node t = create_ast_node(OP_DIVIDE);
			    (yyval) = t;
			    t->left_child = (yyvsp[(1) - (3)]);
			    (yyvsp[(1) - (3)])->right_sibling = (yyvsp[(3) - (3)]);
				t->scope = g_scope;
			;}
    break;

  case 89:
#line 759 "C57.y"
    {
			    ast_node t = create_ast_node(OP_MOD);
			    (yyval) = t;
			    t->left_child = (yyvsp[(1) - (3)]);
			    (yyvsp[(1) - (3)])->right_sibling = (yyvsp[(3) - (3)]);
				t->scope = g_scope;
			;}
    break;

  case 90:
#line 766 "C57.y"
    {
			    ast_node t = create_ast_node(OP_LESS);
			    (yyval) = t;
			    t->left_child = (yyvsp[(1) - (3)]);
			    (yyvsp[(1) - (3)])->right_sibling = (yyvsp[(3) - (3)]);
				t->scope = g_scope;
			;}
    break;

  case 91:
#line 773 "C57.y"
    {
			    ast_node t = create_ast_node(OP_LESSEQ);
			    (yyval) = t;
			    t->left_child = (yyvsp[(1) - (3)]);
			    (yyvsp[(1) - (3)])->right_sibling = (yyvsp[(3) - (3)]);
				t->scope = g_scope;
			;}
    break;

  case 92:
#line 780 "C57.y"
    {
			    ast_node t = create_ast_node(OP_GRTER);
			    (yyval) = t;
			    t->left_child = (yyvsp[(1) - (3)]);
			    (yyvsp[(1) - (3)])->right_sibling = (yyvsp[(3) - (3)]);
				t->scope = g_scope;
			;}
    break;

  case 93:
#line 787 "C57.y"
    {
			    ast_node t = create_ast_node(OP_GRTEREQ);
			    (yyval) = t;
			    t->left_child = (yyvsp[(1) - (3)]);
			    (yyvsp[(1) - (3)])->right_sibling = (yyvsp[(3) - (3)]);
				t->scope = g_scope;
			;}
    break;

  case 94:
#line 794 "C57.y"
    {
			    ast_node t = create_ast_node(OP_EQUALS);
			    (yyval) = t;
			    t->left_child = (yyvsp[(1) - (3)]);
			    (yyvsp[(1) - (3)])->right_sibling = (yyvsp[(3) - (3)]);
				t->scope = g_scope;
			;}
    break;

  case 95:
#line 801 "C57.y"
    {
			    ast_node t = create_ast_node(OP_NEQ);
			    (yyval) = t;
			    t->left_child = (yyvsp[(1) - (3)]);
			    (yyvsp[(1) - (3)])->right_sibling = (yyvsp[(3) - (3)]);
				t->scope = g_scope;
			;}
    break;

  case 96:
#line 808 "C57.y"
    {
			    ast_node t = create_ast_node(OP_AND);
			    (yyval) = t;
			    t->left_child = (yyvsp[(1) - (3)]);
			    (yyvsp[(1) - (3)])->right_sibling = (yyvsp[(3) - (3)]);
				t->scope = g_scope;
			;}
    break;

  case 97:
#line 815 "C57.y"
    {
			    ast_node t = create_ast_node(OP_OR);
			    (yyval) = t;
			    t->left_child = (yyvsp[(1) - (3)]);
			    (yyvsp[(1) - (3)])->right_sibling = (yyvsp[(3) - (3)]);
				t->scope = g_scope;
			;}
    break;

  case 98:
#line 822 "C57.y"
    {
			    ast_node t = create_ast_node(OP_NOT);
			    (yyval) = t;
			    t->left_child = (yyvsp[(2) - (2)]);
				t->scope = g_scope;
			;}
    break;

  case 99:
#line 828 "C57.y"
    {
			    ast_node t = create_ast_node(OP_MINUS);
			    (yyval) = t;
			    t->left_child = (yyvsp[(2) - (2)]);
				t->scope = g_scope;
			;}
    break;

  case 100:
#line 834 "C57.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 101:
#line 835 "C57.y"
    {
			    ast_node t = create_ast_node(OP_INC_PRE);
			    t->left_child = (yyvsp[(2) - (2)]);
			    (yyval) = t;
				t->scope = g_scope;
			;}
    break;

  case 102:
#line 841 "C57.y"
    {
			    ast_node t = create_ast_node(OP_DEC_PRE);
			    t->left_child = (yyvsp[(2) - (2)]);
			    (yyval) = t;
				t->scope = g_scope;
			;}
    break;

  case 103:
#line 847 "C57.y"
    {
			    ast_node t = create_ast_node(OP_INC_POST);
			    t->left_child = (yyvsp[(1) - (2)]);
			    (yyval) = t;
				t->scope = g_scope;
			;}
    break;

  case 104:
#line 853 "C57.y"
    {
			    ast_node t = create_ast_node(OP_DEC_POST);
			    t->left_child = (yyvsp[(1) - (2)]);
			    (yyval) = t;
				t->scope = g_scope;
			;}
    break;

  case 105:
#line 859 "C57.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 106:
#line 860 "C57.y"
    {
				ast_node t = create_ast_node(INT_LITERAL);
				t->value.int_value = atoi(savedLiteralText);
				(yyval) = t;
				t->scope = g_scope;
			;}
    break;

  case 107:
#line 866 "C57.y"
    {
				ast_node t = create_ast_node(DOUBLE_LITERAL);
				t->value.double_value = atof(savedLiteralText);
				(yyval) = t;
				t->scope = g_scope;
			;}
    break;

  case 108:
#line 872 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 109:
#line 873 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 110:
#line 877 "C57.y"
    {
			       ast_node t = create_ast_node(SIZE_OF);
			       (yyval) = t;
			       t->left_child = (yyvsp[(3) - (4)]);
				t->scope = g_scope;
			;}
    break;

  case 111:
#line 883 "C57.y"
    {
			       ast_node t = create_ast_node(SIZE_OF);
			       (yyval) = t;
			       t->left_child = (yyvsp[(3) - (4)]);
				t->scope = g_scope;
			;}
    break;

  case 112:
#line 892 "C57.y"
    {
			   ast_node t = create_ast_node(IDENTIFIER);
			   t->value.string = strdup(savedIdText);
			   (yyval) = t;
				t->scope = g_scope;
				t->lineNumber = lineNumber;
			;}
    break;

  case 113:
#line 898 "C57.y"
    {
			   ast_node t = create_ast_node(CALL);
			   t->left_child = (yyvsp[(2) - (5)]);
			   (yyvsp[(2) - (5)])->right_sibling = (yyvsp[(4) - (5)]);
			   (yyval) = t;
				t->scope = g_scope;
			;}
    break;

  case 114:
#line 908 "C57.y"
    {
				ast_node t = create_ast_node(ARGS);
				(yyval) = t;
				t->left_child = (yyvsp[(1) - (1)]);
				t->scope = g_scope;
			;}
    break;

  case 115:
#line 914 "C57.y"
    {(yyval) = NULL;;}
    break;

  case 116:
#line 918 "C57.y"
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

  case 117:
#line 928 "C57.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;


/* Line 1267 of yacc.c.  */
#line 2857 "C57.tab.c"
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


#line 934 "C57.y"
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

