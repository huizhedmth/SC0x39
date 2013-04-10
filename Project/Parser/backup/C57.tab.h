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
     PLUS = 277,
     MINUS = 278,
     STAR = 279,
     DIV = 280,
     LESS = 281,
     LESSEQ = 282,
     GRTER = 283,
     GRTEREQ = 284,
     EQ = 285,
     NEQ = 286,
     ASSIGN = 287,
     SEMICOLON = 288,
     COMMA = 289,
     LBRKT = 290,
     RBRKT = 291,
     LSQRBRKT = 292,
     RSQRBRKT = 293,
     LCLYBRKT = 294,
     RCLYBRKT = 295,
     INC = 296,
     DEC = 297,
     MOD = 298,
     AND = 299,
     OR = 300,
     NOT = 301,
     PLUSEQ = 302,
     MINUSEQ = 303,
     MULEQ = 304,
     DIVEQ = 305,
     PRECMP = 306,
     ADDR = 307,
     DOT = 308,
     COLON = 309,
     ID = 310,
     NUM = 311,
     FNUM = 312,
     STRING = 313,
     ILLEGALID = 314,
     OTHER = 315
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
#define PLUS 277
#define MINUS 278
#define STAR 279
#define DIV 280
#define LESS 281
#define LESSEQ 282
#define GRTER 283
#define GRTEREQ 284
#define EQ 285
#define NEQ 286
#define ASSIGN 287
#define SEMICOLON 288
#define COMMA 289
#define LBRKT 290
#define RBRKT 291
#define LSQRBRKT 292
#define RSQRBRKT 293
#define LCLYBRKT 294
#define RCLYBRKT 295
#define INC 296
#define DEC 297
#define MOD 298
#define AND 299
#define OR 300
#define NOT 301
#define PLUSEQ 302
#define MINUSEQ 303
#define MULEQ 304
#define DIVEQ 305
#define PRECMP 306
#define ADDR 307
#define DOT 308
#define COLON 309
#define ID 310
#define NUM 311
#define FNUM 312
#define STRING 313
#define ILLEGALID 314
#define OTHER 315




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

