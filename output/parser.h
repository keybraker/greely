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
     ARS_EN_AR = 258,
     ARS_PL_AR = 259,
     THY_EN_AR = 260,
     THY_PL_AR = 261,
     OUD_EN_AR = 262,
     OUD_PL_AR = 263,
     _PL_AR = 264,
     _EN_AR = 265,
     OUSIASTIKO = 266,
     ONOMATA = 267,
     EPITHETO = 268,
     RIMA = 269,
     EPIRIMA = 270,
     ANTONUMIA = 271,
     ARTHRO = 272,
     PROTHESI = 273,
     SUDESMOS = 274,
     EPIFONIMA = 275,
     STIKSI = 276,
     ARITHMOS = 277
   };
#endif
/* Tokens.  */
#define ARS_EN_AR 258
#define ARS_PL_AR 259
#define THY_EN_AR 260
#define THY_PL_AR 261
#define OUD_EN_AR 262
#define OUD_PL_AR 263
#define _PL_AR 264
#define _EN_AR 265
#define OUSIASTIKO 266
#define ONOMATA 267
#define EPITHETO 268
#define RIMA 269
#define EPIRIMA 270
#define ANTONUMIA 271
#define ARTHRO 272
#define PROTHESI 273
#define SUDESMOS 274
#define EPIFONIMA 275
#define STIKSI 276
#define ARITHMOS 277




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 94 "bison/parser.y"
{
    
    char*   leksi;

    char*   ousiastiko;
    char*   onomata;
    char*   epitheto;
    char*   rima;
    char*   epirima;
    char*   antonumia;
    char*   arthro;
    char*   prothesi;
    char*   sundesmos;
    char*   epifonima;

    double  arithmos;

    int     stiksi;

}
/* Line 1529 of yacc.c.  */
#line 114 "output/parser.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

