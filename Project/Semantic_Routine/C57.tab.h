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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

