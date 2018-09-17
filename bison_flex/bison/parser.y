%{
    #include "../bison_flex/analyzer_funcs/word_exif_data_to_mem.h"
    //#include "../word_exif_tool/word_exif_data_to_mem.hh"

    char* stiksiToString[18] = 
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

    char *stiksiToStringName[18] = 
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
    char*   sundesmos;
    char*   epifonima;

    double  arithmos;

    int     stiksi;
}

%start              PROTASI

%type<leksi>        LLEKSI MEROSLOGOU LEKSEIS
%type<stiksi>       LSTIKSI
%type<arithmos>     LARITHMOS 
%type<arthro>       LARTHRO

%token<arthro>      ARS_EN_AR ARS_PL_AR THY_EN_AR THY_PL_AR OUD_EN_AR OUD_PL_AR _PL_AR _EN_AR 

%token<ousiastiko>  OUSIASTIKO 
%token<onomata>     ONOMATA 
%token<epitheto>    EPITHETO 
%token<rima>        RIMA 
%token<epirima>     EPIRIMA 
%token<antonumia>   ANTONUMIA 
%token<arthro>      ARTHRO 
%token<prothesi>    PROTHESI 
%token<sundesmos>   SUDESMOS
%token<epifonima>   EPIFONIMA 

%token<stiksi>      STIKSI
%token<arithmos>    ARITHMOSFLOAT ARITHMOSINT 

%%

    PROTASI:    LEKSEIS             { 
                                        //printf(a_c_g"\nΗ ολοκληρωμένη πρόταση είναι: ");
                                        //printf(a_c_m"%s\n\n\n",$<leksi>1); 
                                        word_exif_func(NULL);
                                        printf("\n");
                                    }
                                    ;

    LEKSEIS:    LEKSEIS MEROSLOGOU {    

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
                |                   { $$ = NULL; }
                ;
                                    // TO $$ krataei ti pliroforia
    MEROSLOGOU: LLEKSI              
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
                	$<leksi>$ = strdup(stiksiToStringName[$1]);                               
                }

    LARTHRO:    ARS_EN_AR           
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

    LARITHMOS:  ARITHMOSFLOAT       
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

    LSTIKSI:    STIKSI              
                { 
                    $<stiksi>$ = yylval.stiksi;               
                    if(yylval.stiksi == 17)
                    {
                        printf("\n");
                    }
                    else 
                    {
                        printf("\"%s\" %s (", stiksiToString[yylval.stiksi], stiksiToStringName[yylval.stiksi]); 
                        printf(italic bold"σημείο στίξης" italic_re); 
                        printf(") ");
                    }
                }

    LLEKSI:     OUSIASTIKO          { $$ = yylval.ousiastiko;   word_exif_func(yylval.leksi); }
                |ONOMATA            { $$ = yylval.onomata;                                    }                                                                   
                |EPITHETO           { $$ = yylval.epitheto;     word_exif_func(yylval.leksi); }
                |RIMA               { $$ = yylval.rima;         word_exif_func(yylval.leksi); }
                |EPIRIMA            { $$ = yylval.epirima;      word_exif_func(yylval.leksi); }
                |ANTONUMIA          { $$ = yylval.antonumia;    word_exif_func(yylval.leksi); }
                |ARTHRO             { $$ = yylval.arthro;       word_exif_func(yylval.leksi); }
                |PROTHESI           { $$ = yylval.prothesi;     word_exif_func(yylval.leksi); }
                |SUDESMOS           { $$ = yylval.sundesmos;    word_exif_func(yylval.leksi); }
                |EPIFONIMA          { $$ = yylval.epifonima;    word_exif_func(yylval.leksi); }

%%


int yyerror (char* yaccProvidedMessage)
{
   printf("%s\n", yaccProvidedMessage);
   return 0;
}

int main(int argc, char** argv){
    	
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
