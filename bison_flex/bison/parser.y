%{
	#include "../bison_flex/analyzer_funcs/word_exif_data_to_mem.h"
	#include "string.h"
	//#include "../word_exif_tool/word_exif_data_to_mem.hh"

	char * 
	sundesmoi_pair[53][53] = 
	{
		{
			"και",
			"κι",
			"ούτε",
			"μήτε",
			"μήδε",
			"ούδε",
			"ή",
			"είτε",
			"αν",
			"αλλά",
			"μα",
			"παρά",
			"όμως",
			"ωστόσο",
			"μόνο",
			"που",
			"λοιπόν",
			"ώστε",
			"άρα",
			"επομένως",
			"οπότε",
			"δηλαδή",
			"ότι",
			"πως",
			"μη",
			"μην",
			"μήπως",
			"να",
			"άμα",
			"όταν",
			"ενώ",
			"καθώς",
			"αφού",
			"αφότου",
			"πριν",
			"μόλις",
			"προτού",
			"ώσπου",
			"ωσότου",
			"σαν",
			"επειδή",
			"τι",
			"εάν",
			"για"
			"γιατί",
			"μολονότι",
			"αν και",
			"μόνο που",
			"σαν που",
			"πριν να",
			"ώστε να",
			"για να"
		},
		{
			"συμπλεκτικός",
			"συμπλεκτικός",
			"συμπλεκτικός",
			"συμπλεκτικός",
			"συμπλεκτικός",
			"συμπλεκτικός",
			"διαχωριστικός",
			"διαχωριστικός",
			"υποθετικός",
			"αντιθετικός",
			"αντιθετικός",
			"πρόθεση ~ αντιθετικός - συγκριτικός",
			"αντιθετικός",
			"αντιθετικός",
			"επίρρημα ~ αντιθετικός",
			"αναφορική αντωνυμία ~ ειδικός - αποτελεσματικός - χρονικός - αιτιολογικός - εναντιωματικός",
			"επιφώνημα ~ συμπερασματικός",
			"αποτελεσματικός, συμπερασματικός",
			"συμπερασματικός",
			"συμπερασματικός",
			"συμπερασματικός",
			"επεξηγηματικός",
			"ειδικός - αιτιολογικός",
			"ειδικός - αιτιολογικός (σπανιότερα)",
			"ενδοιαστικός",
			"ενδοιαστικός",
			"ενδοιαστικός",
			"μόριο ~ βουλητικός - τελικός",
			"υποθετικός - χρονικός",
			"χρονικός",
			"αντιθετικός - χρονικός - εναντιωματικός",
			"επίρρημα ~ χρονικός",
			"Χρονικοί",
			"Χρονικοί",
			"πρόθεση - επίρρημα ~ χρονικός",
			"επίρρημα ~ χρονικός",
			"χρονικός",
			"χρονικός",
			"χρονικός",
			"πρόθεση - επίρρημα ~ χρονικός - υποθετικός",
			"αιτιολογικός",
			"(ποιητικό) ερωτηματική αντωνυμία ~ αιτιολογικός",
			"υποθετικός",
			"συμπερασματικός",
			"αιτιολογικός",
			"εναντιωματικός - αντιθετικός",
			"εναντιωματικός - αντιθετικός",
			"αντιθετικός",
			"αιτιολογικός",
			"χρονικός",
			"αποτελεσματικός",
			"πρόθεση ~ τελικός"
		}
	};

	char * 
	stiksi_to_string[18] = 
	{
		",",
		".",
		";",
		":",
		"!",
		"_",
		"(",
		")",
		"[",
		"]",
		"{",
		"}",
		"+",
		"-",
		"*",
		"/",
		"=",
		"~"
	};

	char *
	stiksi_to_string_name[18] = 
	{
		"κόμμα",
		"τελεία",
		"ερωτηματικό",
		"ανώ και κάτω τελεία",
		"θαυμαστικό",
		"κάτω παύλα",
		"άνοιγμα παρένθεσης",
		"κλείσιμο παρένθεσης", 
		"άνοιγμα μπλόκ",
		"κλείσιμο μπλόκ", 
		"άνοιγμα αγκύλης",
		"κλείσιμο αγκύλης",
		"πρόσθεση", 
		"μείων",
		"επί", 
		"διά",
		"ίσον",
		"περίπου"
	};

	int yylex       (void);
	int yyerror     (char* yaccProvidedMessage);
	
	extern FILE*    yyin;
	extern FILE*    yyout;
	extern char*    yytext;
	extern int      yylineno;
%}

%union
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
	char*   epifonima;

	double  arithmos;

	int     sundesmos;
	int     stiksi;
}

%start              PROTASI

%type<leksi>		LEKSEIS LLEKSI MEROSLOGOU
%type<stiksi>		LSTIKSI
%type<arithmos>		LARITHMOS 
%type<arthro>		LARTHRO
%type<sundesmos>	LSUNDESMOS

%token<arthro>		ARS_EN_AR ARS_PL_AR THY_EN_AR THY_PL_AR OUD_EN_AR OUD_PL_AR _PL_AR _EN_AR 

%token<ousiastiko>	OUSIASTIKO 
%token<onomata>		ONOMATA 
%token<epitheto>	EPITHETO 
%token<rima>		RIMA 
%token<epirima>		EPIRIMA 
%token<antonumia>	ANTONUMIA 
%token<arthro>		ARTHRO 
%token<prothesi>	PROTHESI 
%token<epifonima>	EPIFONIMA 

%token<sundesmos>	SUNDESMOS

%token<stiksi>	STIKSI
%token<arithmos>    ARITHMOSFLOAT ARITHMOSINT 

%%

	PROTASI:	LEKSEIS				{
										printf(a_c_g"\n\nΗ ολοκληρωμένη πρόταση είναι: " a_c_m "%s\n" a_c_re, $<leksi>1); 
										word_exif_func(NULL);
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
										//printf("    ➥ λέξεις μέρος του λόγου: %s\n\n",$$);
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
				|LSUNDESMOS
				{
					printf("$1 : %d\n", $1);
					$<leksi>$ = strdup(sundesmoi_pair[0][$1]);
				}
				;

	LARTHRO:	ARS_EN_AR
				{
					$<arthro>$ = yylval.arthro;
					printf("%s (", yylval.arthro);
					printf(a_c_m italic bold"οριστικό άρθρο ενικού, γένους αρσσενικό" italic_re);	
					printf(") "); 
				}
				|ARS_PL_AR
				{
					$<arthro>$ = yylval.arthro;
					printf("%s (", yylval.arthro);
					printf(a_c_m italic bold"οριστικό άρθρο πληθυντικού, γένους αρσσενικό" italic_re);
					printf(") "); 
				}
				|THY_EN_AR
				{
					$<arthro>$ = yylval.arthro;
					printf("%s (", yylval.arthro);
					printf(a_c_m italic bold"οριστικό άρθρο ενικού, γένους θηλυκό" italic_re);
					printf(") ");
				 }
				|THY_PL_AR
				{
					$<arthro>$ = yylval.arthro;
					printf("%s (", yylval.arthro);
					printf(a_c_m italic bold"οριστικό άρθρο πληθυντικού, γένους θηλυκό" italic_re);
					printf(") "); 
				}
				|OUD_EN_AR
				{
					$<arthro>$ = yylval.arthro;
					printf("%s (", yylval.arthro);
					printf(a_c_m italic bold"οριστικό άρθρο ενικού, γένους ουδέτερο" italic_re);
					printf(") "); 
				}
				|OUD_PL_AR
				{
					$<arthro>$ = yylval.arthro;
					printf("%s (", yylval.arthro);
					printf(a_c_m italic bold"οριστικό άρθρο πληθυντικού, γένους ουδέτερο" italic_re);
					printf(") "); 
				}
				|_EN_AR
				{
					$<arthro>$ = yylval.arthro;
					printf("%s (", yylval.arthro);
					printf(a_c_m italic bold"οριστικό άρθρο ενικού, γένους αγνώστου" italic_re);
					printf(") "); 
				}
				|_PL_AR
				{
					$<arthro>$ = yylval.arthro;
					printf("%s (", yylval.arthro);
					printf(a_c_m italic bold"οριστικό άρθρο πληθυντικού, γένους αγνώστου" italic_re);
					printf(") ");
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
						printf("\"%s\" %s (", stiksi_to_string[yylval.stiksi], stiksi_to_string_name[yylval.stiksi]); 
						printf(italic bold"σημείο στίξης" italic_re); 
						printf(") ");
					}
				}
				;

	LSUNDESMOS: SUNDESMOS SUNDESMOS
				{
					if		($<sundesmos>$ == 8  && $2 == 0)
					{
						printf("\"%s\" (" italic bold "%s σύνδεσμος" italic_re ") ", sundesmoi_pair[0][46], sundesmoi_pair[1][46]);
						$<sundesmos>$ = 46;
					}
					else if	($<sundesmos>$ == 15 && $2 == 14)
					{
						printf("\"%s\" (" italic bold "%s σύνδεσμος" italic_re ") ", sundesmoi_pair[0][47], sundesmoi_pair[1][47]);
						$<sundesmos>$ = 47;
					}
					else if	($<sundesmos>$ == 15 && $2 == 39)
					{
						printf("\"%s\" (" italic bold "%s σύνδεσμος" italic_re ") ", sundesmoi_pair[0][48], sundesmoi_pair[1][48]);
						$<sundesmos>$ = 48;
					}
					else if	($<sundesmos>$ == 27 && $2 == 34)
					{
						printf("\"%s\" (" italic bold "%s σύνδεσμος" italic_re ") ", sundesmoi_pair[0][49], sundesmoi_pair[1][49]);
						$<sundesmos>$ = 49;
					}
					else if	($<sundesmos>$ == 27 && $2 == 17)
					{
						printf("\"%s\" (" italic bold "%s σύνδεσμος" italic_re ") ", sundesmoi_pair[0][50], sundesmoi_pair[1][50]);
						$<sundesmos>$ = 50;
					}
					else if	($<sundesmos>$ == 27 && $2 == 43)
					{
						printf("\"%s\" (" italic bold "%s σύνδεσμος" italic_re ") ", sundesmoi_pair[0][51], sundesmoi_pair[1][51]);
						$<sundesmos>$ = 51;
					}
					else
					{
						printf(a_c_r "\n\nΗ χρήση \"%s %s\" ενδέχεται να είναι λανθασμένη\n\n" a_c_re, sundesmoi_pair[0][$$], sundesmoi_pair[0][$2]);
						exit(0);
					}
				}
				|
				SUNDESMOS
				{
					printf("\"%s\" (" italic bold "%s σύνδεσμος" italic_re ") ", sundesmoi_pair[0][$1], sundesmoi_pair[1][$1]);
					$<sundesmos>$ = $1;
				}
				;

	LLEKSI:		OUSIASTIKO	{$<leksi>$ = yylval.ousiastiko;   word_exif_func(yylval.leksi);	}
				|ONOMATA	{$<leksi>$ = yylval.onomata;									}
				|EPITHETO	{$<leksi>$ = yylval.epitheto;     word_exif_func(yylval.leksi);	}
				|RIMA		{$<leksi>$ = yylval.rima;         word_exif_func(yylval.leksi);	}
				|EPIRIMA	{$<leksi>$ = yylval.epirima;      word_exif_func(yylval.leksi);	}
				|ANTONUMIA	{$<leksi>$ = yylval.antonumia;    word_exif_func(yylval.leksi);	}
				|ARTHRO		{$<leksi>$ = yylval.arthro;       word_exif_func(yylval.leksi);	}
				|PROTHESI	{$<leksi>$ = yylval.prothesi;     word_exif_func(yylval.leksi);	}
				|EPIFONIMA	{$<leksi>$ = yylval.epifonima;    word_exif_func(yylval.leksi);	}
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
