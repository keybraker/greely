 %{
    
    #include "../bison_flex/analyzer_funcs/data_to_mem_and_free/word_exif_data_to_mem.h"

    char* stiksiToString[18] = {

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

    char *stiksiToStringName[18] = { 

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

%union{
    
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
                                        printf("\n");
                                    }
                                    ;

    LEKSEIS:    LEKSEIS MEROSLOGOU {    

                                        if($1 == NULL && $2 != NULL){ 
                                            $$ = (char*) calloc (strlen($2)+1, sizeof(char));
                                            strcpy($$,$2); 

                                        }else if($$ != NULL && $1 != NULL && $2 != NULL){ 
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
                    printf(a_c_m italic bold"οριστικό άρθρο γένους αρσσενικό, ενικού" italic_re);       
                    printf(") "); 
                }
                |ARS_PL_AR          
                {
                    $<arthro>$ = yylval.arthro;
                    printf("%s (", yylval.arthro);
                    printf(a_c_m italic bold"οριστικό άρθρο γένους αρσσενικό, πληθυντικού" italic_re);
                    printf(") "); 
                }
                |THY_EN_AR          
                { 
                    $<arthro>$ = yylval.arthro;               
                    printf("%s (", yylval.arthro); 
                    printf(a_c_m italic bold"οριστικό άρθρο γένους θηλυκό, ενικού" italic_re);          
                    printf(") ");
                 }
                |THY_PL_AR          
                { 
                    $<arthro>$ = yylval.arthro;               
                    printf("%s (", yylval.arthro); 
                    printf(a_c_m italic bold"οριστικό άρθρο γένους θηλυκό, πληθυντικού" italic_re);     
                    printf(") "); 
                }

                |OUD_EN_AR          
                { 
                    $<arthro>$ = yylval.arthro;               
                    printf("%s (", yylval.arthro); 
                    printf(a_c_m italic bold"οριστικό άρθρο γένους ουδέτερο ενικού" italic_re);        
                    printf(") "); 
                }
                |OUD_PL_AR          
                { 
                    $<arthro>$ = yylval.arthro;               
                    printf("%s (", yylval.arthro); 
                    printf(a_c_m italic bold"οριστικό άρθρο γένους ουδέτερο πληθυντικού" italic_re);   
                    printf(") "); 
                }

                |_EN_AR             
                { 
                    $<arthro>$ = yylval.arthro;               
                    printf("%s (", yylval.arthro); 
                    printf(a_c_m italic bold"οριστικό άρθρο γένους αγνώστου ενικού" italic_re);         
                    printf(") "); 
                }
                |_PL_AR             
                { 
                    $<arthro>$ = yylval.arthro;               
                    printf("%s (", yylval.arthro); 
                    printf(a_c_m italic bold"οριστικό άρθρο γένους αγνώστου πληθυντικού" italic_re);    
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
                    if(yylval.stiksi == 17){
                        printf("\n");
                    }
                    else {
                        printf("%s %s (", stiksiToString[yylval.stiksi], stiksiToStringName[yylval.stiksi]); 
                        printf(italic bold"σημείο στίξης" italic_re); 
                        printf(") ");
                    }
                }

    LLEKSI:     OUSIASTIKO          
    			{ 
    				$$ = yylval.ousiastiko;                   
    				printf(" "); 
    				word_exif_func(yylval.leksi); 
    				printf(" "); 
    			}
                |ONOMATA            
                { 
                	$$ = yylval.onomata;                        
                }                                                                   
                |EPITHETO           
                { 
                	$$ = yylval.epitheto;                     
                	printf(" ");
					word_exif_func(yylval.leksi); 
					printf(" "); 
                }
                |RIMA               
                { 
                	$$ = yylval.rima;                         
                	printf(" "); 
                	word_exif_func(yylval.leksi); 
                	printf(" "); 
                }
                |EPIRIMA            
                { 
                	$$ = yylval.epirima;                      
                	printf(" "); 
                	word_exif_func(yylval.leksi); 
                	printf(" "); 
                }
                |ANTONUMIA          
                { 
                	$$ = yylval.antonumia;                    
                	printf(" "); 
                	word_exif_func(yylval.leksi); 
                	printf(" "); 
                }
                |ARTHRO             
                { 
                	$$ = yylval.arthro;                       
                	printf(" "); 
                	word_exif_func(yylval.leksi); 
                	printf(" "); 
                }
                |PROTHESI           
                { 
                	$$ = yylval.prothesi;                     
                	printf(" "); 
                	word_exif_func(yylval.leksi); 
                	printf(" "); 
                }
                |SUDESMOS           
                { 
                	$$ = yylval.sundesmos;                    
                	printf(" "); 
                	word_exif_func(yylval.leksi); 
                	printf(" "); 
                }
                |EPIFONIMA          
                { 
                	$$ = yylval.epifonima;                    
                	printf(" "); 
                	word_exif_func(yylval.leksi); 
                	printf(" "); 
                }

%%


int yyerror (char* yaccProvidedMessage){

   printf("%s\n", yaccProvidedMessage);
   return 0;

}

int main(int argc, char** argv){
    	
    printf("\n");

    if(argc > 2){
        if(!(yyin = fopen(argv[1], "r"))){
            fprintf(stderr,"Cannot read file: %s\n",argv[1]);
            return 1;
        }
        if(!(yyout = fopen(argv[2], "w"))){
            fprintf(stderr,"Cannot write file: %s\n",argv[1]);
            return 1;
        }
        stdout = yyout ;
    }
    else if(argc > 1){
        if(!(yyin = fopen(argv[1], "r"))){
            fprintf(stderr,"Cannot read file: %s\n",argv[1]);
            return 1;
        }
    }
    else{
        yyin = stdin;
    }

    yyparse();

    printf("\n");

    return 0;
}
