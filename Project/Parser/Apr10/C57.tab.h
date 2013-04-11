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
     SEMICOLON = 277,
     LBRKT = 278,
     RBRKT = 279,
     LSQRBRKT = 280,
     RSQRBRKT = 281,
     LCLYBRKT = 282,
     RCLYBRKT = 283,
     PRECMP = 284,
     COLON = 285,
     INC = 286,
     DEC = 287,
     ID = 288,
     NUM = 289,
     FNUM = 290,
     STRING = 291,
     ILLEGALID = 292,
     OTHER = 293,
     COMMA = 294,
     DIVEQ = 295,
     MULEQ = 296,
     MINUSEQ = 297,
     PLUSEQ = 298,
     ASSIGN = 299,
     OR = 300,
     AND = 301,
     NEQ = 302,
     EQ = 303,
     GRTEREQ = 304,
     GRTER = 305,
     LESSEQ = 306,
     LESS = 307,
     MINUS = 308,
     PLUS = 309,
     MOD = 310,
     DIV = 311,
     STAR = 312,
     SIZEOF = 313,
     DECPRE = 314,
     INCPRE = 315,
     NOT = 316,
     UMINUS = 317,
     DEREF = 318,
     ADDR = 319,
     DECPOST = 320,
     INCPOST = 321,
     DOT = 322,
     ARROW = 323
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
#define SEMICOLON 277
#define LBRKT 278
#define RBRKT 279
#define LSQRBRKT 280
#define RSQRBRKT 281
#define LCLYBRKT 282
#define RCLYBRKT 283
#define PRECMP 284
#define COLON 285
#define INC 286
#define DEC 287
#define ID 288
#define NUM 289
#define FNUM 290
#define STRING 291
#define ILLEGALID 292
#define OTHER 293
#define COMMA 294
#define DIVEQ 295
#define MULEQ 296
#define MINUSEQ 297
#define PLUSEQ 298
#define ASSIGN 299
#define OR 300
#define AND 301
#define NEQ 302
#define EQ 303
#define GRTEREQ 304
#define GRTER 305
#define LESSEQ 306
#define LESS 307
#define MINUS 308
#define PLUS 309
#define MOD 310
#define DIV 311
#define STAR 312
#define SIZEOF 313
#define DECPRE 314
#define INCPRE 315
#define NOT 316
#define UMINUS 317
#define DEREF 318
#define ADDR 319
#define DECPOST 320
#define INCPOST 321
#define DOT 322
#define ARROW 323




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

