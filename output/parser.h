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
     EPITHETO = 258,
     OUSIA = 259,
     ARS_EN_AR = 260,
     ARS_PL_AR = 261,
     THY_EN_AR = 262,
     THY_PL_AR = 263,
     OUD_EN_AR = 264,
     OUD_PL_AR = 265,
     _PLY_AR = 266,
     _EN_AR = 267,
     LEKSI = 268,
     STIKSI = 269,
     ARITHMOS = 270
   };
#endif
/* Tokens.  */
#define EPITHETO 258
#define OUSIA 259
#define ARS_EN_AR 260
#define ARS_PL_AR 261
#define THY_EN_AR 262
#define THY_PL_AR 263
#define OUD_EN_AR 264
#define OUD_PL_AR 265
#define _PLY_AR 266
#define _EN_AR 267
#define LEKSI 268
#define STIKSI 269
#define ARITHMOS 270




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 82 "bison/parser.y"
{
    
    char*   leksi;

    char*   epitheto;
    char*   ousiastiko;
    char*   arthro;

    int     stiksi;

    double  arithmos;

}
/* Line 1529 of yacc.c.  */
#line 93 "output/parser.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

