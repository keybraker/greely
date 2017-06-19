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
			printf (a_c_r"Couldn't open file nameDatabase %d\n"a_c_re, errno);
	        exit(0);
	    }
	    if ( (older = fopen(old, "w+") ) == NULL) { 
			printf (a_c_r"Couldn't open file nameDatabase %d\n"a_c_re, errno);
	        exit(0);
	    }

		
	    char buffer[255];
	    while (fgets(buffer,255, newer)!= NULL) { 
	    	fprintf(older, "%s", buffer);
	    }

	    fclose(older);
		fclose(newer);

	}

	char* addInfo(char* buffer, char* token_prev, char* type){

		char* stringer = calloc(sizeof(buffer)+sizeof(token_prev)+sizeof(" 0 0\n")+3, sizeof(char));

		if (strcmp(type,"ARS_EN_AR") == 0){
			strcpy(stringer, buffer);
			strcat(stringer, " ");
			strcat(stringer, token_prev);
			strcat(stringer, " 0 0\n");
			return stringer;

		}else if (strcmp(type,"THY_EN_AR") == 0){
			strcpy(stringer, buffer);
			strcat(stringer, " ");
			strcat(stringer, token_prev);
			strcat(stringer, " 1 0\n");
			return stringer;

		}else if (strcmp(type,"OUD_EN_AR") == 0){
			strcpy(stringer, buffer);
			strcat(stringer, " ");
			strcat(stringer, token_prev);
			strcat(stringer, " 2 0\n");
			return stringer;

		}else if (strcmp(type,"_EN_AR") == 0){
			strcpy(stringer, buffer);
			strcat(stringer, " ");
			strcat(stringer, token_prev);
			strcat(stringer, " 3 0\n");	
			return stringer;

		}else if (strcmp(type,"ARS_PL_AR") == 0){
			strcpy(stringer, buffer);
			strcat(stringer, " ");
			strcat(stringer, token_prev);
			strcat(stringer, " 0 1\n");	
			return stringer;

		}else if (strcmp(type,"THY_PL_AR") == 0){
			strcpy(stringer, buffer);
			strcat(stringer, " ");
			strcat(stringer, token_prev);
			strcat(stringer, " 1 1\n");	
			return stringer;

		}else if (strcmp(type,"OUD_PL_AR") == 0){
			strcpy(stringer, buffer);
			strcat(stringer, " ");
			strcat(stringer, token_prev);
			strcat(stringer, " 2 1\n");	
			return stringer;

		}else if (strcmp(type,"_PL_AR") == 0){
			strcpy(stringer, buffer);
			strcat(stringer, " ");
			strcat(stringer, token_prev);
			strcat(stringer, " 3 1\n");	
			return stringer;

		}else{
			return NULL;
		}

	}

	int isName(char* name, char* type){ 
		printf("%s - %s\n",name, type);

	 	int returner = false;

		FILE *nameDatabase;
		FILE *newNameDatabase;

		if ( (nameDatabase = fopen("database/greekNameDatabase.txt", "r")) == NULL) { 
			printf (a_c_r"Couldn't open file nameDatabase %d\n"a_c_re, errno);
	        exit(0);
	    }
	    if ( (newNameDatabase = fopen("database/newGreekNameDatabase.txt", "w+")) == NULL) { 
			printf (a_c_r"Couldn't open file nameDatabase %d\n"a_c_re, errno);
	        exit(0);
	    }

	    char buffer[255];
	    int  i = 0, bsize = 0, tmp = 0, length = 0;
	    char *token_prev, *token, *stringer = NULL;

		char str1[20];
   		printf("1)Enter name: ");
   		scanf("%s", str1);

	    while (fgets(buffer,255, nameDatabase)!= NULL)    { 
			
			stringer = NULL;
	  	      
	        bsize = buffer[0] - '0'; bsize *= 10;
	        if(buffer[1] != ' ') tmp = buffer[1] - '0'; bsize += tmp; 

	        token = strtok(buffer, "\t");
		   	while( token != NULL ) 
		   	{
		    	token_prev = token;
		    	token = strtok(NULL, " ");
		   	}
			token_prev = strtok(token_prev, "\n");

	        if(bsize == strlen(name) && strcmp(token_prev, name) == 0){ 
		        stringer = strdup(addInfo(buffer,token_prev,type));
		       	returner = true;  

		    }
		    if(bsize-2 == strlen(name) && strncmp(token_prev, name, bsize-2) == 0){
				stringer = strdup(addInfo(buffer,token_prev,type));
		        returner = true;
				
		    }
			

		    if(stringer != NULL){ 
		    	fprintf(newNameDatabase, "%s", stringer);

		    }else{
				stringer = calloc(sizeof(buffer)+sizeof(token_prev)+2, sizeof(char));
		 		strcpy(stringer, buffer);
		 		strcat(stringer, " ");
		 		strcat(stringer, token_prev);
		 		strcat(stringer, "\n");
		    	fprintf(newNameDatabase, "%s", stringer);

		    }

	    }

	    fclose (newNameDatabase);
		fclose (nameDatabase);

   		printf("2)Enter name: ");
   		scanf("%s", str1);

   		copyNewToOldFile("database/greekNameDatabase.txt","database/newGreekNameDatabase.txt");
		
		return returner;
	}

	char* checktype(char* name){

		return "CUCURUCU";
	}

	char* ousiastikoExists(char* name, char* type){ 

		FILE *endingDatabase;

		if ( (endingDatabase = fopen("database/greekEndingDatabase[genos].txt", "r")) == NULL) { 
			printf (a_c_r"Couldn't open file endingDatabase %d\n"a_c_re, errno);
	        exit(0);
	    }

	    char buffer[255];
	    int length = 0;
	    char *token_prev, *token;

	    while (fgets(buffer,255, endingDatabase)!= NULL)    { 

	    	token = strtok(buffer, "\t");				
	        if(strncmp(token, type, strlen(type)) == 0){  
				
				int tokenlen = 0;
				int namelen = strlen(name);

	        	token = strtok(buffer, ",");
			   	while( token != NULL ) 
			   	{
			   		tokenlen = strlen(token);
			   		if(token != NULL && strncmp(name+namelen-tokenlen, token, tokenlen) == 0){

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

"\n"					{ arthroBefore = NULL; printf(a_c_c"Το σημείο στίξης από τον lex είναι: \\n\n"); yylval.stiksi = 17; 	return STIKSI; }

[0-9]+\.[0-9]*			{ 
							double arithmos ; sscanf(yytext,"%lf",&arithmos);
							printf(a_c_c"Ο αριθμός από τον lex είναι: %s\n", yytext); 
							yylval.arithmos = arithmos; 
							arthroBefore = NULL;
							return ARITHMOS; 
						}
[0-9]+					{ 
							int arithmos ; sscanf(yytext,"%d",&arithmos);
						  	printf(a_c_c"Ο αριθμός από τον lex είναι: %s\n"a_c_re, yytext); 
						  	yylval.arithmos = arithmos;
						  	arthroBefore = NULL;
						  	return ARITHMOS; 
						}
ο|Ο 					{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							arthroBefore = "ARS_EN_AR";
							return ARS_EN_AR; 
						}
η|Η 					{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							arthroBefore = "THY_EN_AR";
							return THY_EN_AR; 
						}
οι|Οι|ΟΙ 				{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							arthroBefore = "_PL_AR";
							return _PL_AR; //lookahead
						}
το|Το|ΤΟ 			 	{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							arthroBefore = "OUD_EN_AR";
							return OUD_EN_AR; 
						}
τα|Τα|ΤΑ 			 	{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							arthroBefore = "OUD_PL_AR";
							return OUD_PL_AR; 
						}
Τον|τον|ΤΟΝ  			{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							arthroBefore = "ARS_EN_AR";
							return ARS_EN_AR; 
						}
Στον|στον|ΣΤΟΝ			{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							arthroBefore = "ARS_EN_AR";
							return ARS_EN_AR; 
						}						
του|Του|ΤΟΥ 			{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							arthroBefore = "_EN_AR";
							return _EN_AR; //lookahead
						}
τους|Τους|ΤΟΥΣ 			{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							arthroBefore = "ARS_EN_AR";
							return ARS_EN_AR; //lookahead
						}
τη|Τη|ΤΗ|Την|την|ΤΗΝ 	{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							arthroBefore = "THY_EN_AR";
							return THY_EN_AR; 
						}
τις|Τις|ΤΙΣ 			{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							arthroBefore = "THY_PL_AR";
							return THY_PL_AR; 
						}
Των|των|ΤΩΝ 			{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							arthroBefore = "_PL_AR";
							return _PL_AR; //lookahead
						}
Ένας|ένας|ΈΝΑΣ|ΕΝΑΣ		{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							arthroBefore = "ARS_EN_AR";
							return ARS_EN_AR; 
						}
Έναν|έναν|ΈΝΑΝ|ΕΝΑΝ		{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							arthroBefore = "ARS_EN_AR";
							return ARS_EN_AR; 
						}
Ένα|ένα|ΈΝΑ|ΕΝΑ			{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							arthroBefore = "OUD_EN_AR";
							return OUD_EN_AR; 
						}
Ενός|ενός|ΕΝΌΣ|ΕΝΟΣ		{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							arthroBefore = "ARS_EN_AR";
							return ARS_EN_AR; 
						}
μια|Μια|ΜΙΑ 			{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							arthroBefore = "THY_EN_AR";
							return THY_EN_AR; 
						}
μιας|Μιας|ΜΙΑΣ  		{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							arthroBefore = "THY_EN_AR";
							return THY_EN_AR; 
						}
μιαν|Μιαν|ΜΙΑΝ  		{
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Το άρθρο από τον lex είναι: %s\n"a_c_re, yytext); 
							arthroBefore = "THY_EN_AR";
							return THY_EN_AR; 
						}

[Α-ψ-ρ-π-ω-Ϋ][Α-ψ-ρ-π-ω-Ϋ]* 	{ 

							if(isName(yytext, arthroBefore)) printf(a_c_c"Το %s είναι όνομα.\n"a_c_re,yytext);
							char* type;
							if(arthroBefore && (type = ousiastikoExists(yytext,arthroBefore))) 
								printf(a_c_c"%s %s\n"a_c_re,yytext,type); 

							arthroBefore = NULL;
							yylval.leksi = strdup(yytext); 
							printf(a_c_c"Η λέξη από τον lex είναι: %s\n"a_c_re, yytext); 
							return LEKSI; 
						}
[a-zA-Z][a-zA-Z]* 	{
							printf(a_c_c"Τα εγγλέζικα σου \"%s\", να τα πεις αλλού !\n"a_c_re, yytext); 
							arthroBefore = NULL;
						}	
" "*					{

						}
.						{
							arthroBefore = NULL;
							printf(a_c_c"Δεν υπάρχει είσοδος.\n"a_c_re); 
						}

%%
