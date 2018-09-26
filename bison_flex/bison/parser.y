%{

	#include "../bison_flex/analyzer/word_exif_data_to_mem.h"

	#include <stdlib.h>
	#include <stdio.h>
	#include <stdint.h>
	#include <string.h>
	#include <fcntl.h>
	#include <sys/stat.h>
	#include <sys/mman.h>
	#include <unistd.h>
	#include <sys/mman.h>

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

	#include "../bison_flex/bison/greek_protheseis.h"
	#include "../bison_flex/bison/greek_stikseis.h"
	#include "../bison_flex/bison/greek_moria.h"
	#include "../bison_flex/bison/greek_sundesmoi.h"

	int yylex		(void);
	int yyerror		(char* yaccProvidedMessage);
	
	extern FILE*	yyin;
	extern FILE*	yyout;
	extern char*	yytext;
	extern int		yylineno;
%}

%union
{
	char*	leksi;

	char*	ousiastiko;
	char*	onomata;
	char*	epitheto;
	char*	rima;
	char*	epirima;
	char*	antonumia;
	char*	arthro;
	char*	epifonima;

	double  arithmos;

	int		prothesi;
	int		syndesmos;
	int		morio;
	int		stiksi;
}

%start				PROTASI

%type<leksi>		LEKSEIS LLEKSI MEROSLOGOU
%type<stiksi>		LSTIKSI
%type<arithmos>		LARITHMOS 
%type<arthro>		LARTHRO
%type<morio>		LMORIO
%type<syndesmos>	LSYNDESMOS
%type<prothesi>		LPROTHESI

%token<arthro>		ARS_EN_AR ARS_PL_AR THY_EN_AR 
%token<arthro>		THY_PL_AR OUD_EN_AR OUD_PL_AR _PL_AR _EN_AR 

%token<ousiastiko>	OUSIASTIKO 
%token<onomata>		ONOMATA 
%token<epitheto>	EPITHETO 
%token<rima>		RIMA 
%token<epirima>		EPIRIMA 
%token<antonumia>	ANTONUMIA 
%token<arthro>		ARTHRO 
%token<epifonima>	EPIFONIMA 

%token<prothesi>	PROTHESI 
%token<morio>		MORIO
%token<syndesmos>	SYNDESMOS

%token<stiksi>		STIKSI
%token<arithmos>    ARITHMOSFLOAT ARITHMOSINT 

%%

	PROTASI:	LEKSEIS				{
										printf(a_c_g"\n\nΗ ολοκληρωμένη πρόταση είναι: " a_c_m "%s\n" a_c_re, $<leksi>1); 
										printf("\n");
									}
									;

	LEKSEIS:	LEKSEIS MEROSLOGOU	{
										if($1 == NULL && $2 != NULL)
										{
											$$ = (char*) calloc (strlen($2)+1, sizeof(char));
											strcpy($$,$2); 
										}
										else if($$ != NULL && $1 != NULL && $2 != NULL)
										{
											$$ = (char*) calloc (strlen($1)+strlen($2)+2, sizeof(char));
											strcpy($$, $1); strcat($$, " "); 
											strcat($$, $2);
										}
										//printf("	➥ λέξεις μέρος του λόγου: %s\n\n",$$);
									}
									| 
									{
										$$ = NULL;
									}
									;
	MEROSLOGOU:	LLEKSI
				{
					$<leksi>$ = $<leksi>1;
				}
				|LARTHRO
				{
					$<leksi>$ = $<arthro>1;
				}
				|LARITHMOS
				{
					$<leksi>$ = calloc(1, sizeof(char*));
					sprintf($<leksi>$, "%f", $1);
				}
				|LSTIKSI
				{
					$<leksi>$ = strdup(stiksi_to_string_name[$1]);
				}
				|LMORIO
				{
					$<leksi>$ = strdup(moria_pair[0][$1]);
				}
				|LSYNDESMOS
				{
					$<leksi>$ = strdup(sundesmoi_pair[0][$1]);
				}
				|LPROTHESI
				{
					$<leksi>$ = strdup(protheseis_pair[$1]);
				}
				;

	LARTHRO:	ARS_EN_AR
				{
					$<arthro>$ = yylval.arthro;
					printf("%s ("
					a_c_m italic bold
					"οριστικό άρθρο ενικού, γένους αρσσενικό" 
					italic_re ") "
					, yylval.arthro);
				}
				|ARS_PL_AR
				{
					$<arthro>$ = yylval.arthro;
					printf("%s ("
					a_c_m italic bold
					"οριστικό άρθρο πληθυντικού, γένους αρσσενικό" 
					italic_re ") "
					, yylval.arthro);
				}
				|THY_EN_AR
				{
					$<arthro>$ = yylval.arthro;
					printf("%s ("
					a_c_m italic bold
					"οριστικό άρθρο ενικού, γένους θηλυκό" 
					italic_re ") "
					, yylval.arthro);
				 }
				|THY_PL_AR
				{
					$<arthro>$ = yylval.arthro;
					printf("%s ("
					a_c_m italic bold
					"οριστικό άρθρο πληθυντικού, γένους θηλυκό" 
					italic_re ") "
					, yylval.arthro);
				}
				|OUD_EN_AR
				{
					$<arthro>$ = yylval.arthro;
					printf("%s ("
					a_c_m italic bold
					"οριστικό άρθρο ενικού, γένους ουδέτερο" 
					italic_re ") "
					, yylval.arthro);
				}
				|OUD_PL_AR
				{
					$<arthro>$ = yylval.arthro;
					printf("%s ("
					a_c_m italic bold
					"οριστικό άρθρο πληθυντικού, γένους ουδέτερο" 
					italic_re ") "
					, yylval.arthro);
				}
				|_EN_AR
				{
					$<arthro>$ = yylval.arthro;
					printf("%s ("
					a_c_m italic bold
					"οριστικό άρθρο ενικού, γένους αγνώστου" 
					italic_re ") "
					, yylval.arthro);
				}
				|_PL_AR
				{
					$<arthro>$ = yylval.arthro;
					printf("%s ("
					a_c_m italic bold
					"οριστικό άρθρο πληθυντικού, γένους αγνώστου" 
					italic_re ") "
					, yylval.arthro);
				}
				;

	LARITHMOS:	ARITHMOSFLOAT
				{
					$<arithmos>$ = yylval.arithmos;
					printf("%f (", yylval.arithmos); printf(a_c_r italic bold"float αριθμός" italic_re);
					printf(") "); 
				}
				|ARITHMOSINT
				{
					$<arithmos>$ = yylval.arithmos;
					printf("%d (", (int) yylval.arithmos); printf(a_c_r italic bold"int αριθμός" italic_re);
					printf(") "); 
				}
				;

	LSTIKSI:	STIKSI
				{
					$<stiksi>$ = yylval.stiksi;
					if(yylval.stiksi == 17)
					{
						printf("\n");
					}
					else 
					{
						printf("\"%s\" (%s ~ " italic bold "σημείο στίξης" italic_re ") ",
						stiksi_to_string[yylval.stiksi], 
						stiksi_to_string_name[yylval.stiksi]);
					}
				}
				;

	LMORIO:		MORIO
				{
					$<morio>$ = yylval.morio;
					printf("\"%s\" (" italic bold "πρόθεση [%s]" italic_re ") ",
					moria_pair[$1][0],
					moria_pair[$1][1]);
				}
				;

	LSYNDESMOS: SYNDESMOS SYNDESMOS
				{
					if($<syndesmos>$ == 8  && $2 == 0)
					{
						printf("\"%s\" (" italic bold "%s σύνδεσμος" italic_re ") ",
						sundesmoi_pair[0][46], 
						sundesmoi_pair[1][46]);
						$<syndesmos>$ = 46;
					}
					else if($<syndesmos>$ == 14 && $2 == 15)
					{
						printf("\"%s\" (" italic bold "%s σύνδεσμος" italic_re ") ",
						sundesmoi_pair[0][47], 
						sundesmoi_pair[1][47]);
						$<syndesmos>$ = 47;
					}
					else if($<syndesmos>$ == 39 && $2 == 15)
					{
						printf("\"%s\" (" italic bold "%s σύνδεσμος" italic_re ") ",
						sundesmoi_pair[0][48], 
						sundesmoi_pair[1][48]);
						$<syndesmos>$ = 48;
					}
					else if($<syndesmos>$ == 34 && $2 == 27)
					{
						printf("\"%s\" (" italic bold "%s σύνδεσμος" italic_re ") ",
						sundesmoi_pair[0][49], 
						sundesmoi_pair[1][49]);
						$<syndesmos>$ = 49;
					}
					else if($<syndesmos>$ == 17 && $2 == 27)
					{
						printf("\"%s\" (" italic bold "%s σύνδεσμος" italic_re ") ",
						sundesmoi_pair[0][50], 
						sundesmoi_pair[1][50]);
						$<syndesmos>$ = 50;
					}
					else if($<syndesmos>$ == 43 && $2 == 27)
					{
						printf("\"%s\" (" italic bold "%s σύνδεσμος" italic_re ") ",
						sundesmoi_pair[0][51], 
						sundesmoi_pair[1][51]);
						$<syndesmos>$ = 51;
					}
					else
					{
						printf(a_c_r "\"%s %s\" (ενδέχεται να είναι λανθασμένος συνδιασμός συνδέσμων) " a_c_re,
						sundesmoi_pair[0][$$],
						sundesmoi_pair[0][$2]);
						exit(0);
					}
				}
				|
				SYNDESMOS
				{
					printf("\"%s\" (" italic bold "%s σύνδεσμος" italic_re ") ",
					sundesmoi_pair[0][$1], 
					sundesmoi_pair[1][$1]);
					$<syndesmos>$ = $1;
				}
				;

	LPROTHESI:	PROTHESI	
				{
					$<prothesi>$ = yylval.prothesi;
					printf("\"%s\" (" italic bold "πρόθεση" italic_re ") ",
					protheseis_pair[$1]);
				}
				;

	LLEKSI:		ONOMATA				{$<leksi>$ = yylval.onomata;	}
				|OUSIASTIKO			{$<leksi>$ = yylval.ousiastiko;	word_exif_func(yytext, 1, 1);	}
				|EPITHETO			{$<leksi>$ = yylval.epitheto;	word_exif_func(yytext, 2, 1);	}
				|RIMA				{$<leksi>$ = yylval.rima;		word_exif_func(yytext, 0, 1);	}
				|LSYNDESMOS RIMA	{$<leksi>$ = yylval.rima; 		printf("SYNDESMOS RIMA");	word_exif_func(yytext, 0, 0);	}
				|LMORIO RIMA		{$<leksi>$ = yylval.rima; 		printf("MORIO RIMA");	word_exif_func(yytext, 0, 0);	}
				|EPIRIMA			{$<leksi>$ = yylval.epirima;	}
				|ANTONUMIA			{$<leksi>$ = yylval.antonumia;	}
				|ARTHRO				{$<leksi>$ = yylval.arthro;		}
				|EPIFONIMA			{$<leksi>$ = yylval.epifonima;	}
				;

%%


int
yyerror (char* yaccProvidedMessage)
{
	printf("%s\n", yaccProvidedMessage);
	return 0;
}

int
main(int argc, char** argv)
{
	printf("\n");
	
	if(argc > 2)
	{
		if(!(yyin = fopen(argv[1], "r")))
		{
			fprintf(stderr,"Cannot read file: %s\n",argv[1]);
			return 1;
		}
		if(!(yyout = fopen(argv[2], "w")))
		{
			fprintf(stderr,"Cannot write file: %s\n",argv[1]);
			return 1;
		}
		stdout = yyout ;
	}
	else if(argc > 1)
	{
		if(!(yyin = fopen(argv[1], "r")))
		{
			fprintf(stderr,"Cannot read file: %s\n",argv[1]);
			return 1;
		}
	}
	else
	{
		yyin = stdin;
	}

	yyparse();

	printf("\n");

	return 0;
}
