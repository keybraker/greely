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

char* arthroBefore = NULL;

void copyNewToOldFile(char* old, char* new){

	FILE *older;
	FILE *newer;

	if ( (newer = fopen(new, "r") ) == NULL) { 
		printf (a_c_r"1Couldn't open file nameDatabase %d\n"a_c_re, errno);
        exit(0);
    }
    if ( (older = fopen(old, "w+") ) == NULL) { 
		printf (a_c_r"2Couldn't open file nameDatabase %d\n"a_c_re, errno);
        exit(0);
    }

    char buffer[255];
    while (fgets(buffer,255, newer)!= NULL) { 
    	fprintf(older, "%s", buffer);
    }

    fclose(older);
	fclose(newer);

}

char* addInfo(char* token, char* type){

	char* stringer = calloc(sizeof(token)+sizeof("|0|0\n")+3, sizeof(char));
	
	if (strcmp(type,"ARS_EN_AR") == 0){
		strcpy(stringer, "Y|");
		strcat(stringer, token);
		strcat(stringer, "|0|0|\n");
		return stringer;

	}else if (strcmp(type,"THY_EN_AR") == 0){ 
		strcpy(stringer, "Y|");
		strcat(stringer, token);
		strcat(stringer, "|1|0|\n");
		return stringer;

	}else if (strcmp(type,"OUD_EN_AR") == 0){
		strcpy(stringer, "Y|");
		strcat(stringer, token);
		strcat(stringer, "|2|0|\n");
		return stringer;

	}else if (strcmp(type,"_EN_AR") == 0){
		strcpy(stringer, "Y|");
		strcat(stringer, token);
		strcat(stringer, "|3|0|\n");
		return stringer;

	}else if (strcmp(type,"ARS_PL_AR") == 0){
		strcpy(stringer, "Y|");
		strcat(stringer, token);
		strcat(stringer, "|0|1|\n");
		return stringer;

	}else if (strcmp(type,"THY_PL_AR") == 0){
		strcpy(stringer, "Y|");
		strcat(stringer, token);
		strcat(stringer, "|1|1|\n");
		return stringer;

	}else if (strcmp(type,"OUD_PL_AR") == 0){
		strcpy(stringer, "Y|");
		strcat(stringer, token);
		strcat(stringer, "|2|1|\n");
		return stringer;

	}else if (strcmp(type,"_PL_AR") == 0){
		strcpy(stringer, "Y|");
		strcat(stringer, token);
		strcat(stringer, "|3|1|\n");
		return stringer;

	}else{
		return NULL;
	}

}

/*
* A function or checking if a noun is a 
* name and printing it.
* Lookup the complete database 
* Has to get bitmapped and linked for pooling.
*/
int nameCheck(char* name){ 

	FILE* f1 = fopen ("bison_flex/analyzer_funcs/name_gr.txt", "r");
    if(!f1){ printf("Couldn't open bison_flex/analyzer_funcs/name_gr.txt"); exit(1); }

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
        		printf("'%s' (", name); printf(a_c_y italic bold"όνομα αρσενικό" italic_re); printf(") ");
        	}else{
        		printf("'%s' (", name); printf(a_c_y italic bold"όνομα θηλυκό" italic_re); printf(") ");
        	}
        	
        	return 1;
        }
       
        
    }

    fclose(f1);
    return 0;

}

char* checktype(char* name){

	return "CUCURUCU";

}

char* ousiastikoExists(char* name, char* type){ 
	
	//printf("name = %s, type = %s\n\n",name,type);
	FILE *endingDatabase;

	if ( (endingDatabase = fopen("bison_flex/analyzer_funcs/greek_ending_genos.txt", "r")) == NULL) { 
		printf (a_c_r"5Couldn't open file endingDatabase %d\n"a_c_re, errno);
        exit(0);
    }

    char buffer[255];
    int length = 0;
    char *token_prev, *token;

    while (fgets(buffer,255, endingDatabase)!= NULL)    { 

    	token = strtok(buffer, "\t");		

    	//printf("token = %s, type = %s\n",token,type);
	
        if(strncmp(token, type, strlen(type)) == 0){  
			
			int tokenlen = 0;
			int namelen = strlen(name);

        	token = strtok(buffer, ",");
		   	while( token != NULL ) 
		   	{
		   		tokenlen = strlen(token);
		   					  
		   		//printf("name = %s, token = %s 	\n",name,token);

		   		//if( strncmp(name+namelen-tokenlen, token, tokenlen) == 0 ){
		   		if(strcmp(type,token) == 0){

		   			if (strcmp(type,"ARS_EN_AR") == 0){
		   				fclose (endingDatabase);
		   				return "~ αρσενικό ενικού ~";
		   			}else if (strcmp(type,"THY_EN_AR") == 0){
		   				fclose (endingDatabase);		
		   				return "~ θηλυκό ενικού ~";
		   			}else if (strcmp(type,"OUD_EN_AR") == 0){
		   				fclose (endingDatabase);
		   				return "~ ουδέτερο ενικού ~";
		   			}else if (strcmp(type,"_EN_AR") == 0){
						fclose (endingDatabase);
						return checktype(name);
		   			}else if (strcmp(type,"ARS_PL_AR") == 0){
						fclose (endingDatabase);
						return "~ αρσενικό πληθυντικού ~";
		   			}else if (strcmp(type,"THY_PL_AR") == 0){
		   			 	fclose (endingDatabase);
		   			 	return "~ θηλυκό πληθυντικού ~";
		   			}else if (strcmp(type,"OUD_PL_AR") == 0){
		   			 	fclose (endingDatabase);
		   			 	return "~ ουδέτερο πληθυντικού ~";
		   			}else if (strcmp(type,"_PL_AR") == 0){
		   				fclose (endingDatabase);
		   				return checktype(name);

		   			}else{
		   				exit(0);
		   			}
		   			
		   		}
		   		break; //added
		    	token = strtok(NULL, ",");
		   	}

	    }

    }

	fclose (endingDatabase);
	return NULL;
}

%}

%option noyywrap
%option yylineno

%%

","					{ 	/*---------------------------------------------------------------------- STIKSEIS ----------------------------------------------------------------------*/
						yylval.stiksi = 0; 	
						return STIKSI; 
					}
"."					{ 	
						yylval.stiksi = 1; 	
						return STIKSI; 
					}
";"					{ 	
						yylval.stiksi = 2; 	
						return STIKSI; 
					}
":"					{ 	
						yylval.stiksi = 3; 	
						return STIKSI; 
					}
"!"					{ 	
						yylval.stiksi = 4; 	
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

ο|Ο 				{	/*---------------------------------------------------------------------- ARTHRA ----------------------------------------------------------------------*/
						yylval.leksi = strdup(yytext); 
						arthroBefore = "ARS_EN_AR";
						return ARS_EN_AR; 
					}
η|Η 				{
						yylval.leksi = strdup(yytext); 
						arthroBefore = "THY_EN_AR";
						return THY_EN_AR; 
					}
το|Το|ΤΟ 			{
						yylval.leksi = strdup(yytext); 
						arthroBefore = "OUD_EN_AR";
						return OUD_EN_AR; 
					}
Τον|τον|ΤΟΝ  		{
						yylval.leksi = strdup(yytext); 
						arthroBefore = "ARS_EN_AR";
						return ARS_EN_AR; 
					}
τη|Τη|ΤΗ 			{
						yylval.leksi = strdup(yytext); 
						//lookahead gia to an einai sumfono
						arthroBefore = "THY_EN_AR";
						return THY_EN_AR; 
					}
Την|την|ΤΗΝ 		{
						yylval.leksi = strdup(yytext); 
						//lookahead gia to an einai fonien
						arthroBefore = "THY_EN_AR";
						return THY_EN_AR; 
					}
του|Του|ΤΟΥ 		{
						yylval.leksi = strdup(yytext); 
						arthroBefore = "_EN_AR";
						return _EN_AR; //lookahead
					}
της|Της|ΤΗΣ 		{
						yylval.leksi = strdup(yytext); 
						//lookahead gia to an einai sumfono
						arthroBefore = "THY_EN_AR";
						return THY_EN_AR; 
					}




οι|Οι|ΟΙ 			{
						yylval.leksi = strdup(yytext); 
						arthroBefore = "_PL_AR";
						return _PL_AR; //lookahead
					}
τους|Τους|ΤΟΥΣ 		{
						yylval.leksi = strdup(yytext); 
						arthroBefore = "ARS_EN_AR";
						return ARS_EN_AR; //lookahead
					}
τις|Τις|ΤΙΣ 		{
						yylval.leksi = strdup(yytext); 
						arthroBefore = "THY_PL_AR";
						return THY_PL_AR; 
					}
τα|Τα|ΤΑ 			{
						yylval.leksi = strdup(yytext); 
						arthroBefore = "OUD_PL_AR";
						return OUD_PL_AR; 
					}
Των|των|ΤΩΝ 		{
						yylval.leksi = strdup(yytext); 
						arthroBefore = "_PL_AR";
						return _PL_AR; //lookahead
					}
					
Στον|στον|ΣΤΟΝ		{
						yylval.leksi = strdup(yytext); 
						arthroBefore = "ARS_EN_AR";
						return ARS_EN_AR; 
					}						




Ένας|ένας|ΈΝΑΣ|ΕΝΑΣ	{ 
						// EINAI ARITHMITIKO/ ARTHRO/ ANTONUMIA
						yylval.leksi = strdup(yytext); 
						arthroBefore = "ARS_EN_AR";
						return ARS_EN_AR; 
					}
Έναν|έναν|ΈΝΑΝ|ΕΝΑΝ	{ 
						// EINAI ARITHMITIKO/ ARTHRO/ ANTONUMIA
						yylval.leksi = strdup(yytext); 
						arthroBefore = "ARS_EN_AR";
						return ARS_EN_AR; 
					}
Ένα|ένα|ΈΝΑ|ΕΝΑ		{ 
						// EINAI ARITHMITIKO/ ARTHRO/ ANTONUMIA
						yylval.leksi = strdup(yytext); 
						arthroBefore = "OUD_EN_AR";
						return OUD_EN_AR; 
					}
Ενός|ενός|ΕΝΌΣ|ΕΝΟΣ	{
						yylval.leksi = strdup(yytext); 
						arthroBefore = "ARS_EN_AR";
						return ARS_EN_AR; 
					}
μια|Μια|ΜΙΑ 		{
						yylval.leksi = strdup(yytext); 
						arthroBefore = "THY_EN_AR";
						return THY_EN_AR; 
					}
μιας|Μιας|ΜΙΑΣ  	{
						yylval.leksi = strdup(yytext); 
						arthroBefore = "THY_EN_AR";
						return THY_EN_AR; 
					}
μιαν|Μιαν|ΜΙΑΝ  	{
						yylval.leksi = strdup(yytext); 
						arthroBefore = "THY_EN_AR";
						return THY_EN_AR; 
					} 

[Α-ψ-ρ-π-ω-Ϋ]* 		{   /*---------------------------------------------------------------------- LEKSEIS ----------------------------------------------------------------------*/
						if(nameCheck(yytext)) {
							yylval.leksi = strdup(yytext); 
							return ONOMATA; 
						}
						char* type;
						// This is for updating ouastika database with the knowledge obtained
						// by the arthra infront of the ousiastika !
						if(arthroBefore && (type = ousiastikoExists(yytext, arthroBefore)))
							// printf(a_c_c"%s %s "a_c_re,yytext,type);

						arthroBefore = NULL;
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
