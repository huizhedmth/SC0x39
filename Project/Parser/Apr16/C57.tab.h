/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

