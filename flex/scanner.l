%{

	#include <stdio.h>
	#include <string.h>
	
	#include "parser.h"

%}

%option noyywrap
%option yylineno

%%

","						{ yylval.stiksi = 0; return STIKSI; }
"."						{ yylval.stiksi = 1; return STIKSI; }
";"						{ yylval.stiksi = 2; return STIKSI; }
":"						{ yylval.stiksi = 3; return STIKSI; }
"!"						{ yylval.stiksi = 4; return STIKSI; }
"-"						{ yylval.stiksi = 5; return STIKSI; }
"("						{ yylval.stiksi = 6; return STIKSI; }
")"						{ yylval.stiksi = 7; return STIKSI; }

"\n"					{ yylval.stiksi = 8; return STIKSI; }
[0-9]+\.[0-9]*			{ double arithmos ; sscanf(yytext,"%lf",&arithmos);
						  yylval.arithmos = arithmos; return ARITHMOS; 
						}
[0-9]+					{ int arithmos ; sscanf(yytext,"%d",&arithmos);
						  yylval.arithmos = arithmos; printf("telos\n"); return ARITHMOS; 
						}
[a-zA-Z][a-zA-Z0-9_]* 	{ yylval.leksi = strdup(yytext); return LEKSI; }

%%
