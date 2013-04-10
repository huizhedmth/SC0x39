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
     SIZEOF = 269,
     CONST = 270,
     SWITCH = 271,
     STATIC = 272,
     STRUCT = 273,
     EXTERN = 274,
     DEFAULT = 275,
     CASE = 276,
     NIL = 277,
     PLUS = 278,
     MINUS = 279,
     STAR = 280,
     DIV = 281,
     LESS = 282,
     LESSEQ = 283,
     GRTER = 284,
     GRTEREQ = 285,
     ASSIGN = 286,
     SEMICOLON = 287,
     COMMA = 288,
     LBRKT = 289,
     RBRKT = 290,
     LSQRBRKT = 291,
     RSQRBRKT = 292,
     LCLYBRKT = 293,
     RCLYBRKT = 294,
     INC = 295,
     DEC = 296,
     MOD = 297,
     NOT = 298,
     PLUSEQ = 299,
     MINUSEQ = 300,
     MULEQ = 301,
     DIVEQ = 302,
     PRECMP = 303,
     COLON = 304,
     ID = 305,
     NUM = 306,
     FNUM = 307,
     STRING = 308,
     ILLEGALID = 309,
     OTHER = 310,
     OR = 311,
     AND = 312,
     NEQ = 313,
     EQ = 314,
     ARROW = 315,
     DOT = 316,
     ADDR = 317,
     UMINUS = 318
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
#define SIZEOF 269
#define CONST 270
#define SWITCH 271
#define STATIC 272
#define STRUCT 273
#define EXTERN 274
#define DEFAULT 275
#define CASE 276
#define NIL 277
#define PLUS 278
#define MINUS 279
#define STAR 280
#define DIV 281
#define LESS 282
#define LESSEQ 283
#define GRTER 284
#define GRTEREQ 285
#define ASSIGN 286
#define SEMICOLON 287
#define COMMA 288
#define LBRKT 289
#define RBRKT 290
#define LSQRBRKT 291
#define RSQRBRKT 292
#define LCLYBRKT 293
#define RCLYBRKT 294
#define INC 295
#define DEC 296
#define MOD 297
#define NOT 298
#define PLUSEQ 299
#define MINUSEQ 300
#define MULEQ 301
#define DIVEQ 302
#define PRECMP 303
#define COLON 304
#define ID 305
#define NUM 306
#define FNUM 307
#define STRING 308
#define ILLEGALID 309
#define OTHER 310
#define OR 311
#define AND 312
#define NEQ 313
#define EQ 314
#define ARROW 315
#define DOT 316
#define ADDR 317
#define UMINUS 318




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

