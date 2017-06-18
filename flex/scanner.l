%{

	#include <stdio.h>
	#include <string.h>
	
	#include "parser.h"

%}

%option noyywrap
%option yylineno

%%

","						{ yylval.stiksi = 0; 	return STIKSI; }
"."						{ yylval.stiksi = 1; 	return STIKSI; }
";"						{ yylval.stiksi = 2; 	return STIKSI; }
":"						{ yylval.stiksi = 3; 	return STIKSI; }
"!"						{ yylval.stiksi = 4; 	return STIKSI; }
"_"						{ yylval.stiksi = 5; 	return STIKSI; }
"("						{ yylval.stiksi = 6; 	return STIKSI; }
")"						{ yylval.stiksi = 7; 	return STIKSI; }
"["						{ yylval.stiksi = 8; 	return STIKSI; }
"]"						{ yylval.stiksi = 9;	return STIKSI; }
"{"						{ yylval.stiksi = 10; 	return STIKSI; }
"}"						{ yylval.stiksi = 11; 	return STIKSI; }
"+"						{ yylval.stiksi = 12; 	return STIKSI; }
"-"						{ yylval.stiksi = 13; 	return STIKSI; }
"*"						{ yylval.stiksi = 14; 	return STIKSI; }
"/"						{ yylval.stiksi = 15; 	return STIKSI; }
"="						{ yylval.stiksi = 16; 	return STIKSI; }

"\n"					{ yylval.stiksi = 17; 	return STIKSI; }

[0-9]+\.[0-9]*			{ 
							double arithmos ; sscanf(yytext,"%lf",&arithmos);
							printf("Ο αριθμός από τον lex είναι: %s\n", yytext); 
							yylval.arithmos = arithmos; return ARITHMOS; 
						}
[0-9]+					{ 
							int arithmos ; sscanf(yytext,"%d",&arithmos);
						  	printf("Ο αριθμός από τον lex είναι: %s\n", yytext); 
						  	yylval.arithmos = arithmos; return ARITHMOS; 
						}
ο|Ο 					{
							yylval.leksi = strdup(yytext); 
							printf("Το άρθρο από τον lex είναι: %s\n", yytext); 
							return ARSENIKO_ARTHRO; 
						}
η|Η 					{
							yylval.leksi = strdup(yytext); 
							printf("Το άρθρο από τον lex είναι: %s\n", yytext); 
							return THILIKO_ARTHRO; 
						}
το|Το|ΤΟ|Τον|τον|ΤΟΝ 	{
							yylval.leksi = strdup(yytext); 
							printf("Το άρθρο από τον lex είναι: %s\n", yytext); 
							return OUDETERO_ARTHRO; 
						}
τη|Τη|ΤΗ|Την|την|ΤΗΝ 	{
							yylval.leksi = strdup(yytext); 
							printf("Το άρθρο από τον lex είναι: %s\n", yytext); 
							return THILIKO_ARTHRO; 
						}
Ένας|ένας|ΈΝΑΣ|ΕΝΑΣ		{
							yylval.leksi = strdup(yytext); 
							printf("Το άρθρο από τον lex είναι: %s\n", yytext); 
							return ARSENIKO_ARTHRO; 
						}
Έναν|έναν|ΈΝΑΝ|ΕΝΑΝ		{
							yylval.leksi = strdup(yytext); 
							printf("Το άρθρο από τον lex είναι: %s\n", yytext); 
							return ARSENIKO_ARTHRO; 
						}
Ένα|ένα|ΈΝΑ|ΕΝΑ		{
							yylval.leksi = strdup(yytext); 
							printf("Το άρθρο από τον lex είναι: %s\n", yytext); 
							return OUDETERO_ARTHRO; 
						}
Ενός|ενός|ΕΝΌΣ|ΕΝΟΣ		{
							yylval.leksi = strdup(yytext); 
							printf("Το άρθρο από τον lex είναι: %s\n", yytext); 
							return ARSENIKO_ARTHRO; 
						}
μια|Μια|ΜΙΑ 			{
							yylval.leksi = strdup(yytext); 
							printf("Το άρθρο από τον lex είναι: %s\n", yytext); 
							return THILIKO_ARTHRO; 
						}
μιας|Μιας|ΜΙΑΣ  		{
							yylval.leksi = strdup(yytext); 
							printf("Το άρθρο από τον lex είναι: %s\n", yytext); 
							return THILIKO_ARTHRO; 
						}
μιαν|Μιαν|ΜΙΑΝ  		{
							yylval.leksi = strdup(yytext); 
							printf("Το άρθρο από τον lex είναι: %s\n", yytext); 
							return THILIKO_ARTHRO; 
						}

[α-ωΑ-Ω][α-ωΑ-Ω0-9_]* 	{ 
							yylval.leksi = strdup(yytext); 
							printf("Η λέξη από τον lex είναι: %s\n", yytext); 
							return LEKSI; 
						}
[ά-ώΆ-Ώ][ά-ώΆ-Ώ0-9_]* 	{ 
							yylval.leksi = strdup(yytext); 
							printf("Η λέξη από τον lex είναι: %s\n", yytext); 
							return LEKSI; 
						}
.						{
							printf("Δεν υπάρχει είσοδος.\n"); 
						}

%%
