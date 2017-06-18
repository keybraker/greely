%{

	#include <stdio.h>
	#include <string.h>
	
	#include "parser.h"

	#define a_c_r     "\x1b[31m"
    #define a_c_g     "\x1b[32m"
    #define a_c_y     "\x1b[33m"
    #define a_c_b     "\x1b[34m"
    #define a_c_m     "\x1b[35m"
    #define a_c_c     "\x1b[36m"
    #define a_c_re    "\x1b[0m"
    #define under     "\e[4m"
    #define under_re  "\e[0m"
    #define italic    "\e[3m"
    #define italic_re "\e[0m"
    #define bold      "\e[1m"
    #define bold_re   "\e[0m"

	#define false 0
	#define true 1

	int isName(char* name){

		FILE *nameDatabase;

		if ( (nameDatabase = fopen("database/greekNameDatabase.txt", "r")) == NULL) { 
			printf (a_c_r"Couldn't open file nameDatabase %d\n"a_c_re, errno);
	        exit(0);
	    }

	    char buffer[255];
	    int j = 0, k = 0, bsize = 0, tmp = 0;
	    
	    while (fgets(buffer,255, nameDatabase)!= NULL)    {
	        	        
	        bsize = buffer[0] - '0'; bsize *= 10;
	        if(buffer[1] == ' ') j = 2;
	        else tmp = buffer[1] - '0'; bsize += tmp; j = 3;

	        if(bsize == strlen(name)+1 || bsize == strlen(name)){ 
				
				/*for me*/
				if(strcmp(name, "Ιωάννης") == 0){
	        		printf("bsize = %d ", bsize);			
					printf("strlen(name) = %lu \n", strlen(name));	
	        	}
	        	if(strcmp(name, "Ιωάννη") == 0){
	        		printf("bsize = %d ", bsize);			
					printf("strlen(name) = %lu \n", strlen(name));	
	        	}
				
				k = j;
		        while( j-k < bsize ){
		      
		        	if(buffer[j] != name[j-k]) break;
		        	j++;
		        	
		        }

		        if( j-k == bsize) return true;

		    }

	    }

		fclose (nameDatabase);
		return false;
	}
%}

%option noyywrap
%option yylineno

%%

","						{ printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext); yylval.stiksi = 0; 	return STIKSI; }
"."						{ printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext); yylval.stiksi = 1; 	return STIKSI; }
";"						{ printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext); yylval.stiksi = 2; 	return STIKSI; }
":"						{ printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext); yylval.stiksi = 3; 	return STIKSI; }
"!"						{ printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext); yylval.stiksi = 4; 	return STIKSI; }
"_"						{ printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext); yylval.stiksi = 5; 	return STIKSI; }
"("						{ printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext); yylval.stiksi = 6; 	return STIKSI; }
")"						{ printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext); yylval.stiksi = 7; 	return STIKSI; }
"["						{ printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext); yylval.stiksi = 8; 	return STIKSI; }
"]"						{ printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext); yylval.stiksi = 9;	return STIKSI; }
"{"						{ printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext); yylval.stiksi = 10; 	return STIKSI; }
"}"						{ printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext); yylval.stiksi = 11; 	return STIKSI; }
"+"						{ printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext); yylval.stiksi = 12; 	return STIKSI; }
"-"						{ printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext); yylval.stiksi = 13; 	return STIKSI; }
"*"						{ printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext); yylval.stiksi = 14; 	return STIKSI; }
"/"						{ printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext); yylval.stiksi = 15; 	return STIKSI; }
"="						{ printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext); yylval.stiksi = 16; 	return STIKSI; }

"\n"					{ printf(a_c_c"Το σημείο στίξης από τον lex είναι: \\n\n"); yylval.stiksi = 17; 	return STIKSI; }

[0-9]+\.[0-9]*			{ 
							double arithmos ; sscanf(yytext,"%lf",&arithmos);
							printf(a_c_c"Ο αριθμός από τον lex είναι: %s\n", yytext); 
							yylval.arithmos = arithmos; return ARITHMOS; 
						}
[0-9]+					{ 
							int arithmos ; sscanf(yytext,"%d",&arithmos);
						  	printf(a_c_c"Ο αριθμός από τον lex είναι: %s\n"a_c_re, yytext); 
						  	yylval.arithmos = arithmos; return ARITHMOS; 
						}
ο|Ο 					{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							return ARS_EN_AR; 
						}
η|Η 					{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							return THY_EN_AR; 
						}
οι|Οι|ΟΙ 				{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							return _PLY_AR; 
						}
το|Το|ΤΟ 			 	{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							return OUD_EN_AR; 
						}
τα|Τα|ΤΑ 			 	{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							return OUD_PL_AR; 
						}
Τον|τον|ΤΟΝ  			{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							return ARS_EN_AR; 
						}
τους|Τους|ΤΟΥΣ 			{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							return _EN_AR; //μπορει να ειναι μονα ουγετερο-αρσενικο φιξ πιο μετα
						}
τη|Τη|ΤΗ|Την|την|ΤΗΝ 	{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							return THY_EN_AR; 
						}
Των|των|ΤΩΝ 			{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							return _PLY_AR; 
						}
Ένας|ένας|ΈΝΑΣ|ΕΝΑΣ		{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							return ARS_EN_AR; 
						}
Έναν|έναν|ΈΝΑΝ|ΕΝΑΝ		{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							return ARS_EN_AR; 
						}
Ένα|ένα|ΈΝΑ|ΕΝΑ			{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							return OUD_EN_AR; 
						}
Ενός|ενός|ΕΝΌΣ|ΕΝΟΣ		{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							return ARS_EN_AR; 
						}
μια|Μια|ΜΙΑ 			{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							return THY_EN_AR; 
						}
μιας|Μιας|ΜΙΑΣ  		{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							return THY_EN_AR; 
						}
μιαν|Μιαν|ΜΙΑΝ  		{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							return THY_EN_AR; 
						}

[Α-ψ-ρ-π-ω-Ϋ][Α-ψ-ρ-π-ω-Ϋ]* 	{ 
							if(isName(yytext)){
								printf("%s is name\n",yytext);
							}else{
								printf("%s isn't name\n",yytext);
							}

							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Η λέξη από τον lex είναι: %s\n"a_c_re, yytext); 
							return LEKSI; 
						}
[a-zA-Z][a-zA-Z]* 	{
							printf(a_c_c"Τα εγγλέζικα σου \"%s\", να τα πεις αλλού !\n"a_c_re, yytext); 
						}	
" "*					{

						}
.						{
							printf(a_c_c"Δεν υπάρχει είσοδος.\n"a_c_re); 
						}

%%
