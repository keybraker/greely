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

char* type = NULL;	
char* arthroBefore = NULL;
char* arthroBeforeBefore = NULL;
char* memoryName = NULL;
char* memoryType = NULL;

// char* arsEnik[12] = 	{ ας, άς, , ης, ής, ές, ούς, ός };
// char* thyEnik[12] = 	{ α, ά, η, ή};
// char* oydEnik[12] = 	{ };
// char* enik[12]    = 	{ };

// char* arsPlyth[12] = 	{ };
// char* thyPlyth[12] = 	{ ές, εις};
// char* oydPlyth[12] = 	{ };
// char* plyth[2]     =     { };

/*
* A function or checking if a noun is a 
* name and printing it.
* Lookup the complete database 
* Has to get bitmapped and linked for pooling.
*/
int verbCheck(char* word){
	return 0;
}

int nameCheck(char* name){ 

	FILE* f1 = fopen ("../name/nameDatabaseFinal/nameGr.txt", "a+");
    if(!f1){ printf("1ERROR f1"); exit(1); }

    char    *word = calloc (255, sizeof(char)) ;
    char    *type = calloc (255, sizeof(char)) ;
    char    buffer[255];
    
    // 0 for men
    // 1 for women
    while (fgets(buffer,255, f1)!= NULL){
        word = strtok(buffer,"|"); 
        type = strtok(NULL,"|"); 
        if(strncmp(name, word, strlen(name)) == 0 && ( strlen(name)+2 == strlen(word) || strlen(name) == strlen(word) ) ){
        	
        	if(strcmp("0", type) == 0){
        		printf("("); printf(a_c_r italic bold"%s - όνομα αρσενικό" italic_re, name); printf(") ");
        	}else{
        		printf("("); printf(a_c_r italic bold"%s - όνομα θηλυκό" italic_re, name); printf(") ");
        	}
        	
        	return 1;
        }
       
        
    }

    fclose(f1);
    return 0;

}

void reset(){
	printf("reset\n");

	if(memoryName != NULL && memoryType != NULL){
		FILE* f1  = fopen ("generatedOusiastika.txt", "a+");
	    if(!f1){ printf("2ERROR f1 "); exit(1); }

	    fprintf(f1, "%s|%s|ousiastiko|\n", memoryName, memoryType);
	    fclose(f1);
	}

	arthroBefore = NULL;
	memoryName = NULL;
	memoryType = NULL;
}

void arthro_epitheto_ousiastiko(char* name, char* type){ 
	
	memoryName = strdup(name);
	memoryType = strdup(type);

}

void memory_no_arthro(char* name){

	if(verbCheck(name)){
		FILE* f1  = fopen ("generatedOusiastika.txt", "a+");
	    if(!f1){ printf("2ERROR f1 "); exit(1); }

	    fprintf(f1, "%s|%s|ousiastiko|\n", memoryName, memoryType);
	    fclose(f1);

	}else if(memoryName != NULL && memoryType != NULL){
		FILE* f1  = fopen ("generatedOusiastika.txt", "a+");
	    if(!f1){ printf("2ERROR f1 "); exit(1); }

	    fprintf(f1, "%s|%s|epitheto|\n", memoryName, memoryType);
	    fprintf(f1, "%s|%s|ousiastiko|\n", name, memoryType);
	    fclose(f1);

	}	


	arthroBefore = NULL;
	memoryName = NULL;
	memoryType = NULL;

}

void memory_arthro(char* name, char* type){ 
	
	FILE* f1  = fopen ("generatedOusiastika.txt", "a+");
    if(!f1){ printf("ERROR f1 "); exit(1); }

    fprintf(f1, "%s|%s|ousiastiko|\n", memoryName, memoryType);
    fclose(f1);

	arthroBefore = NULL;
	memoryName = NULL;
	memoryType = NULL;

	arthro_epitheto_ousiastiko(name, type);
}

%}

%option noyywrap
%option yylineno

%%

","					{ /*---------------------------------------------------------------------- STIKSEIS ----------------------------------------------------------------------*/
						yylval.stiksi = 0;
						reset(); 	
						return STIKSI; 
					}
"."					{
						yylval.stiksi = 1; 
						reset();
						return STIKSI; 
					}
";"					{
						yylval.stiksi = 2;
						reset(); 	
						return STIKSI; 
					}
":"					{
						yylval.stiksi = 3;
						reset(); 	
						return STIKSI; 
					}
"!"					{
						yylval.stiksi = 4; 
						reset();	
						return STIKSI; 
					}
"_"					{
						yylval.stiksi = 5; 	
						return STIKSI; 
					}
"("					{
						yylval.stiksi = 6; 	
						return STIKSI; 
					}
")"					{
						yylval.stiksi = 7; 	
						return STIKSI; 
					}
"["					{
						yylval.stiksi = 8; 	
						return STIKSI; 
					}
"]"					{
						yylval.stiksi = 9;	
						return STIKSI; 
					}
"{"					{
						yylval.stiksi = 10; 
						return STIKSI; 
					}
"}"					{
						yylval.stiksi = 11; 
						return STIKSI; 
					}
"+"					{
						yylval.stiksi = 12; 
						return STIKSI; 
					}
"-"					{
						yylval.stiksi = 13; 
						return STIKSI; 
					}
"*"					{
						yylval.stiksi = 14; 
						return STIKSI; 
					}
"/"					{
						yylval.stiksi = 15; 
						return STIKSI; 
					}
"="					{
						yylval.stiksi = 16; 
						return STIKSI; 
					}
"\n"				{
						arthroBefore = NULL; 
						yylval.stiksi = 17;
						reset();
						return STIKSI; 
					}

[0-9]+\.[0-9]*		{   /*---------------------------------------------------------------------- ARITHMOI ----------------------------------------------------------------------*/
						double arithmos ; sscanf(yytext,"%lf",&arithmos);
						yylval.arithmos = arithmos; 
						arthroBefore = NULL;
						return ARITHMOSFLOAT; 
					}
[0-9]+				{ 
						int arithmos ; sscanf(yytext,"%d",&arithmos);
					  	yylval.arithmos = arithmos;
					  	arthroBefore = NULL;
					  	return ARITHMOSINT; 
					}

ο|Ο 				{	/*______________________________________________________________________ ARTHRA ______________________________________________________________________*/
						yylval.leksi = strdup(yytext); 
						arthroBefore = "Ars_En_Onm";

						return Ars_En_Onm; 
					}
του|Του|ΤΟΥ 		{
						yylval.leksi = strdup(yytext); 
						arthroBefore = "En_Gen";

						return En_Gen; //lookahead
					}
Τον|τον|ΤΟΝ  		{
						yylval.leksi = strdup(yytext); 
						arthroBefore = "Ars_En_Ait";

						return Ars_En_Ait; 
					}
Στον|στον|ΣΤΟΝ		{
						yylval.leksi = strdup(yytext); 
						arthroBefore = "Ars_En_Ait";
						return Ars_En_Ait; 
					}	
οι|Οι|ΟΙ 			{
						yylval.leksi = strdup(yytext); 
						arthroBefore = "Pl_Onm";
						return Pl_Onm; //lookahead
					}
Των|των|ΤΩΝ 		{
						yylval.leksi = strdup(yytext); 
						arthroBefore = "Pl_Gen";
						return Pl_Gen; //lookahead
					}
τους|Τους|ΤΟΥΣ 		{
						yylval.leksi = strdup(yytext); 
						arthroBefore = "Ars_Pl_Ait";
						return Ars_Pl_Ait; //lookahead
					}


η|Η 				{
						yylval.leksi = strdup(yytext); 
						arthroBefore = "Thy_En_Onm";
						return Thy_En_Onm; 
					}
της|Της|ΤΗΣ 		{
						yylval.leksi = strdup(yytext); 
						//lookahead gia to an einai sumfono
						arthroBefore = "Thy_En_Gen";
						return Thy_En_Gen; 
					}
τη|Τη|ΤΗ 			{
						yylval.leksi = strdup(yytext); 
						//lookahead gia to an einai sumfono
						arthroBefore = "Thy_En_Ait";
						return Thy_En_Ait; 
					}
Την|την|ΤΗΝ 		{
						yylval.leksi = strdup(yytext); 
						//lookahead gia to an einai fonien
						arthroBefore = "Thy_En_Ait";
						return Thy_En_Ait; 
					}
τις|Τις|ΤΙΣ 		{
						yylval.leksi = strdup(yytext); 
						arthroBefore = "Thy_Pl_Ait";
						return Thy_Pl_Ait; 
					}


το|Το|ΤΟ 			{
						yylval.leksi = strdup(yytext); 
						arthroBefore = "Oud_En_OnmAit";
						return Oud_En_OnmAit; 
					}
τα|Τα|ΤΑ 			{
						yylval.leksi = strdup(yytext); 
						arthroBefore = "Oud_Pl_OnmAit";
						return Oud_Pl_OnmAit; 
					}


Ένας|ένας|ΈΝΑΣ|ΕΝΑΣ	{
						// EINAI ARITHMITIKO/ ARTHRO/ ANTONUMIA
						yylval.leksi = strdup(yytext); 
						arthroBefore = "Ars_En_Onm";
						return Ars_En_Onm; 
					}
Έναν|έναν|ΈΝΑΝ|ΕΝΑΝ	{
						// EINAI ARITHMITIKO/ ARTHRO/ ANTONUMIA
						yylval.leksi = strdup(yytext); 
						arthroBefore = "Ars_En_Ait";
						return Ars_En_Ait; 
					}
Ένα|ένα|ΈΝΑ|ΕΝΑ		{
						// EINAI ARITHMITIKO/ ARTHRO/ ANTONUMIA
						yylval.leksi = strdup(yytext); 
						arthroBefore = "Ars_En_Onm";
						return Ars_En_Onm; 
					}
Ενός|ενός|ΕΝΌΣ|ΕΝΟΣ	{
						yylval.leksi = strdup(yytext); 
						arthroBefore = "En_Gen";
						return En_Gen; 
					}
μια|Μια|ΜΙΑ 		{
						yylval.leksi = strdup(yytext); 
						arthroBefore = "Thy_En_Onm";
						return Thy_En_Onm; 
					}
μιας|Μιας|ΜΙΑΣ  	{
						yylval.leksi = strdup(yytext); 
						arthroBefore = "Thy_En_Gen";
						return Thy_En_Gen; 
					}
μιαν|Μιαν|ΜΙΑΝ  	{
						yylval.leksi = strdup(yytext); 
						arthroBefore = "Thy_En_Ait";
						return Thy_En_Ait; 
					}

[Α-ψ-ρ-π-ω-Ϋ]* 		{   /*---------------------------------------------------------------------- LEKSEIS ----------------------------------------------------------------------*/
						if(nameCheck(yytext)) {
							yylval.leksi = strdup(yytext); 
							return ONOMATA; 
						}

						// This is for updating ouastika database with the knowledge obtained
						// by the arthra infront of the ousiastika !
						
						if(memoryName == NULL && memoryType == NULL && arthroBefore != NULL){ 
							printf("arthro_epitheto_ousiastiko (%s-%s)\n", yytext, arthroBefore);
							arthro_epitheto_ousiastiko(yytext, arthroBefore);

						}else if(memoryName != NULL && memoryType != NULL && arthroBefore == NULL){ 
							printf("memory_no_arthro (%s)\n", yytext);
							memory_no_arthro(yytext);

						}else if(memoryName != NULL && memoryType != NULL && arthroBefore != NULL){ 
							printf("memory_arthro (%s-%s)\n", yytext, arthroBefore);
							memory_arthro(yytext, arthroBefore);

						}else{
							printf("ELSERINONER (%s-%s-%s-%s)\n",yytext, arthroBefore, memoryName, memoryType);

						}

						type = NULL;
						arthroBefore = NULL;
						arthroBeforeBefore = NULL;
						
						yylval.leksi = strdup(yytext);
						return OUSIASTIKO;
					}

[a-zA-Z]* 			{	/*---------------------------------------------------------------------- AGGLIKA ----------------------------------------------------------------------*/
						printf(a_c_c"%s ("a_c_re, yytext);
						printf(italic bold"εγγλέζικα" italic_re);       
						printf(") "); 
						arthroBefore = NULL;
					}

" "*				{

					}
.					{
						arthroBefore = NULL;
						printf(a_c_r"Δεν υπάρχει είσοδος.\n"a_c_re); 
					}

%%
