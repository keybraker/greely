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

int isName(char* name, char* type){ 

	//printf("%s - %s\n",name, type);

 	int returner = false;

	FILE *nameDatabase;
	FILE *newNameDatabase;

	if ( (nameDatabase = fopen("database [obsolete]/greekNameDatabase.txt", "r")) == NULL) { 
		printf (a_c_r"3Couldn't open file nameDatabase %d\n"a_c_re, errno);
        exit(0);
    }
    if ( (newNameDatabase = fopen("database [obsolete]/newGreekNameDatabase.txt", "w+")) == NULL) { 
		printf (a_c_r"4Couldn't open file nameDatabase %d\n"a_c_re, errno);
        exit(0);
    }

    char buffer[255];
    char *token, *token_prev, *stringer = NULL;

    while (fgets(buffer,255, nameDatabase)!= NULL)    { 
		
		stringer = NULL;

        token = strtok(buffer, "|");

        if(strcmp(token,"N") == 0) { 
	        
		   	while( token != NULL ) 
		   	{
		    	token_prev = token;
		    	token = strtok(NULL, " ");
		   	}
			token = strtok(token_prev, "|");


	        if(strcmp(token, name) == 0){ 
	        	if(type)
		        	stringer = strdup(addInfo(token,type));
		       	returner = true;  

		    }
		    if(strncmp(token, name, strlen(name)-2) == 0){
	        	if(type)
					stringer = strdup(addInfo(token,type));
		        returner = true;
				
		    }
			

		    if(stringer != NULL){ 
		    	fprintf(newNameDatabase, "%s", stringer);

		    }else{
				stringer = calloc(sizeof(buffer)+sizeof(token)+2, sizeof(char));
		 		strcpy(stringer, "N|");
		 		strcat(stringer, token);
		 		strcat(stringer, "|\n");
		    	fprintf(newNameDatabase, "%s", stringer);

		    }

		}else{

			while( token != NULL ) 
		   	{
		    	token_prev = token;
		    	token = strtok(NULL, " ");
		   	}
			token = strtok(token_prev, "|");

			stringer = calloc(sizeof("Y||0|0|\n")+sizeof(token)+2, sizeof(char));
		 	strcpy(stringer, "Y|");
		 	strcat(stringer, token);
		 	strcat(stringer, "|");
			while( token != NULL ) 
		   	{
		    	token_prev = token;
		    	token = strtok(NULL, " ");
		   	}
			token = strtok(token_prev, "|");
			strcat(stringer, token);
			strcat(stringer, "|");
			while( token != NULL ) 
		   	{
		    	token_prev = token;
		    	token = strtok(NULL, " ");
		   	}
			token = strtok(token_prev, "|"); 
			strcat(stringer, token);
			strcat(stringer, "|\n");

		    fprintf(newNameDatabase, "%s", stringer);

		}

    }

    fclose (newNameDatabase);
	fclose (nameDatabase);

		copyNewToOldFile("database [obsolete]/greekNameDatabase.txt","database [obsolete]/newGreekNameDatabase.txt");
	
	return returner;

}

char* checktype(char* name){

	return "CUCURUCU";

}

char* ousiastikoExists(char* name, char* type){ 
	
	//printf("name = %s, type = %s\n\n",name,type);
	FILE *endingDatabase;

	if ( (endingDatabase = fopen("database [obsolete]/apeutheiasmesastokodika greekEndingDatabase[genos].txt", "r")) == NULL) { 
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

","					{ 	printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext);
						yylval.stiksi = 0; 	
						return STIKSI; 
					}
"."					{ 	printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext);
						yylval.stiksi = 1; 	
						return STIKSI; 
					}
";"					{ 	printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext);
						yylval.stiksi = 2; 	
						return STIKSI; 
					}
":"					{ 	printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext);
						yylval.stiksi = 3; 	
						return STIKSI; 
					}
"!"					{ 	printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext);
						yylval.stiksi = 4; 	
						return STIKSI; 
					}
"_"					{ 	printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext);
						yylval.stiksi = 5; 	
						return STIKSI; 
					}
"("					{ 	printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext);
						yylval.stiksi = 6; 	
						return STIKSI; 
					}
")"					{ 	printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext);
						yylval.stiksi = 7; 	
						return STIKSI; 
					}
"["					{ 	printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext);
						yylval.stiksi = 8; 	
						return STIKSI; 
					}
"]"					{ 	printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext);
						yylval.stiksi = 9;	
						return STIKSI; 
					}
"{"					{ 	printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext);
						yylval.stiksi = 10; 
						return STIKSI; 
					}
"}"					{ 	printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext);
						yylval.stiksi = 11; 
						return STIKSI; 
					}
"+"					{ 	printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext);
						yylval.stiksi = 12; 
						return STIKSI; 
					}
"-"					{ 	printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext);
						yylval.stiksi = 13; 
						return STIKSI; 
					}
"*"					{ 	printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext);
						yylval.stiksi = 14; 
						return STIKSI; 
					}
"/"					{ 	printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext);
						yylval.stiksi = 15; 
						return STIKSI; 
					}
"="					{ 	printf(a_c_c"Το σημείο στίξης από τον lex είναι: %s\n", yytext);
						yylval.stiksi = 16; 
						return STIKSI; 
					}
"\n"				{ 	
						arthroBefore = NULL; 
						printf(a_c_c"Το σημείο στίξης από τον lex είναι: \\n\n");
						yylval.stiksi = 17;
						return STIKSI; 
					}

[0-9]+\.[0-9]*		{ 
						double arithmos ; sscanf(yytext,"%lf",&arithmos);
						printf(a_c_c"Ο αριθμός από τον lex είναι: %s\n", yytext); 
						yylval.arithmos = arithmos; 
						arthroBefore = NULL;
						return ARITHMOS; 
					}
[0-9]+				{ 
						int arithmos ; sscanf(yytext,"%d",&arithmos);
					  	printf(a_c_c"Ο αριθμός από τον lex είναι: %s\n"a_c_re, yytext); 
					  	yylval.arithmos = arithmos;
					  	arthroBefore = NULL;
					  	return ARITHMOS; 
					}
ο|Ο 				{
						yylval.leksi = strdup(yytext); 
						printf(a_c_c"Το οριστικό άρθρο, ενικού ονομαστικής, αρσενικού από τον lex είναι: %s\n"a_c_re, yytext); 
						arthroBefore = "ARS_EN_AR";
						return ARS_EN_AR; 
					}
η|Η 				{
						yylval.leksi = strdup(yytext); 
						printf(a_c_c"Το οριστικό άρθρο, ενικού ονομαστικής, θηλύκου από τον lex είναι: %s\n"a_c_re, yytext); 
						arthroBefore = "THY_EN_AR";
						return THY_EN_AR; 
					}
το|Το|ΤΟ 			{
						yylval.leksi = strdup(yytext); 
						printf(a_c_c"Το οριστικό άρθρο, ενικού ονομαστικής/αιτιατικής, ουδετέρου ή  αιτιατικής,αρσενικό από τον lex είναι: %s\n"a_c_re, yytext); 
						arthroBefore = "OUD_EN_AR";
						return OUD_EN_AR; 
					}
Τον|τον|ΤΟΝ  		{
						yylval.leksi = strdup(yytext); 
						printf(a_c_c"Το οριστικό άρθρο, ενικού αιτιατικής, αρσενικού από τον lex είναι: %s\n"a_c_re, yytext); 
						arthroBefore = "ARS_EN_AR";
						return ARS_EN_AR; 
					}
τη|Τη|ΤΗ 			{
						yylval.leksi = strdup(yytext); 
						printf(a_c_c"Το οριστικό άρθρο, ενικού αιτιατικής, θηλύκου από τον lex είναι: %s\n"a_c_re, yytext); 
						//lookahead gia to an einai sumfono
						arthroBefore = "THY_EN_AR";
						return THY_EN_AR; 
					}
Την|την|ΤΗΝ 		{
						yylval.leksi = strdup(yytext); 
						printf(a_c_c"Το οριστικό άρθρο, ενικού αιτιατικής, θηλύκου από τον lex είναι: %s\n"a_c_re, yytext); 
						//lookahead gia to an einai fonien
						arthroBefore = "THY_EN_AR";
						return THY_EN_AR; 
					}
του|Του|ΤΟΥ 		{
						yylval.leksi = strdup(yytext); 
						printf(a_c_c"Το οριστικό άρθρο, ενικού γενικής, αρσενικού ή ουδετέρου από τον lex είναι: %s\n"a_c_re, yytext); 
						arthroBefore = "_EN_AR";
						return _EN_AR; //lookahead
					}
της|Της|ΤΗΣ 		{
						yylval.leksi = strdup(yytext); 
						printf(a_c_c"Το οριστικό άρθρο, ενικού γενικής, θηλύκου από τον lex είναι: %s\n"a_c_re, yytext); 
						//lookahead gia to an einai sumfono
						arthroBefore = "THY_EN_AR";
						return THY_EN_AR; 
					}


οι|Οι|ΟΙ 			{
						yylval.leksi = strdup(yytext); 
						printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
						arthroBefore = "_PL_AR";
						return _PL_AR; //lookahead
					}
τους|Τους|ΤΟΥΣ 		{
						yylval.leksi = strdup(yytext); 
						printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
						arthroBefore = "ARS_EN_AR";
						return ARS_EN_AR; //lookahead
					}
τις|Τις|ΤΙΣ 		{
						yylval.leksi = strdup(yytext); 
						printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
						arthroBefore = "THY_PL_AR";
						return THY_PL_AR; 
					}
τα|Τα|ΤΑ 			 {
						yylval.leksi = strdup(yytext); 
						printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
						arthroBefore = "OUD_PL_AR";
						return OUD_PL_AR; 
					}
Των|των|ΤΩΝ 		{
						yylval.leksi = strdup(yytext); 
						printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
						arthroBefore = "_PL_AR";
						return _PL_AR; //lookahead
					}
					
Στον|στον|ΣΤΟΝ		{
						yylval.leksi = strdup(yytext); 
						printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
						arthroBefore = "ARS_EN_AR";
						return ARS_EN_AR; 
					}						




Ένας|ένας|ΈΝΑΣ|ΕΝΑΣ	{
						yylval.leksi = strdup(yytext); 
						printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
						arthroBefore = "ARS_EN_AR";
						return ARS_EN_AR; 
					}
Έναν|έναν|ΈΝΑΝ|ΕΝΑΝ	{
						yylval.leksi = strdup(yytext); 
						printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
						arthroBefore = "ARS_EN_AR";
						return ARS_EN_AR; 
					}
Ένα|ένα|ΈΝΑ|ΕΝΑ		{
						yylval.leksi = strdup(yytext); 
						printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
						arthroBefore = "OUD_EN_AR";
						return OUD_EN_AR; 
					}
Ενός|ενός|ΕΝΌΣ|ΕΝΟΣ	{
						yylval.leksi = strdup(yytext); 
						printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
						arthroBefore = "ARS_EN_AR";
						return ARS_EN_AR; 
					}
με|Με|ΜΕ 			{
						yylval.leksi = strdup(yytext); 
						printf(a_c_c"Το άρθρο από τον lex είναι '%s' και δηλώνει:\n", yytext); 
						printf("* συνοδεία, συντροφιά, παρέα\n");
						printf("* συνύπαρξη\n");
						printf("* τρόπο\n");
						printf("* μέσο ή όργανο\n");
						printf("* σχέση ή αναφορά\n");
						printf("* ισότητα, ομοιότητα, συμφωνία, φιλική ή εχθρική επικοινωνία\n");
						printf("* καιρικές συνθήκες\n");
						printf("* ψυχική κατάσταση\n");
						printf("* ιδιοκτησία, κυριότητα, κατοχή\n");
						printf("* χαρακτηριστικό, ιδιότητα, περιεχόμενο\n");
						printf("* χρόνο ή χρονικό όριο\n");
						printf("* ποσό, αντάλλαγμα\n");
						printf("* αντίθεση, εναντίωση (ισοδυναμεί με το παρά)\n"a_c_re);
						arthroBefore = "THY_EN_AR";
						return THY_EN_AR; 
					}
μια|Μια|ΜΙΑ 		{
						yylval.leksi = strdup(yytext); 
						printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
						arthroBefore = "THY_EN_AR";
						return THY_EN_AR; 
					}
μιας|Μιας|ΜΙΑΣ  	{
						yylval.leksi = strdup(yytext); 
						printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
						arthroBefore = "THY_EN_AR";
						return THY_EN_AR; 
					}
μιαν|Μιαν|ΜΙΑΝ  	{
						yylval.leksi = strdup(yytext); 
						printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
						arthroBefore = "THY_EN_AR";
						return THY_EN_AR; 
					}

[Α-ψ-ρ-π-ω-Ϋ]* 		{ 
						if(isName(yytext, arthroBefore)) 
							printf(a_c_c"Το %s είναι όνομα.\n"a_c_re,yytext);
						char* type;
						if(arthroBefore && (type = ousiastikoExists(yytext,arthroBefore))) 
							printf(a_c_c"%s %s\n"a_c_re,yytext,type); 

						arthroBefore = NULL;
						yylval.leksi = strdup(yytext); 
						printf(a_c_c"Η λέξη από τον lex είναι: %s\n"a_c_re, yytext); 
						return OUSIASTIKO; 
					}
[a-zA-Z]* 			{
						printf(a_c_c"Τα εγγλέζικα σου \"%s\", να τα πεις αλλού !\n"a_c_re, yytext); 
						arthroBefore = NULL;
					}	
" "*				{

					}
.					{
						arthroBefore = NULL;
						printf(a_c_c"Δεν υπάρχει είσοδος.\n"a_c_re); 
					}

%%
