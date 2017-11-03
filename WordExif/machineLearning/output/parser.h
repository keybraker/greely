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
     Ars_En_Onm = 258,
     En_Gen = 259,
     Ars_En_Ait = 260,
     Pl_Onm = 261,
     Pl_Gen = 262,
     Ars_Pl_Ait = 263,
     Thy_En_Onm = 264,
     Thy_En_Gen = 265,
     Thy_En_Ait = 266,
     Thy_Pl_Ait = 267,
     Oud_En_OnmAit = 268,
     Oud_Pl_OnmAit = 269,
     OUSIASTIKO = 270,
     ONOMATA = 271,
     EPITHETO = 272,
     RIMA = 273,
     EPIRIMA = 274,
     ANTONUMIA = 275,
     ARTHRO = 276,
     PROTHESI = 277,
     SUDESMOS = 278,
     EPIFONIMA = 279,
     STIKSI = 280,
     ARITHMOSFLOAT = 281,
     ARITHMOSINT = 282
   };
#endif
/* Tokens.  */
#define Ars_En_Onm 258
#define En_Gen 259
#define Ars_En_Ait 260
#define Pl_Onm 261
#define Pl_Gen 262
#define Ars_Pl_Ait 263
#define Thy_En_Onm 264
#define Thy_En_Gen 265
#define Thy_En_Ait 266
#define Thy_Pl_Ait 267
#define Oud_En_OnmAit 268
#define Oud_Pl_OnmAit 269
#define OUSIASTIKO 270
#define ONOMATA 271
#define EPITHETO 272
#define RIMA 273
#define EPIRIMA 274
#define ANTONUMIA 275
#define ARTHRO 276
#define PROTHESI 277
#define SUDESMOS 278
#define EPIFONIMA 279
#define STIKSI 280
#define ARITHMOSFLOAT 281
#define ARITHMOSINT 282




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 64 "bison/parser.y"
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
#line 123 "output/parser.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

