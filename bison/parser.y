%{

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <assert.h>
    #include "../WordExif/includerino.h"

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

    char *stiksiToString[17] = { 
        
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
    };

    char *mikra[31] = {
        "α","ά","β","γ","δ","ε","έ","ζ","η","ή","θ",
        "ι","ί","κ","λ","μ","ν","ξ","ο","ό","π","ρ",
        "σ","τ","υ","ύ","φ","χ","ψ","ω","ώ"
    };

    char *megala[31] = {
        "Α","Ά","Β","Γ","Δ","Ε","Έ","Ζ","Η","Ή","Θ",
        "Ι","Ι","Κ","Λ","Μ","Ν","Ξ","Ο","Ό","Π","Ρ",
        "Σ","Τ","Υ","Ύ","Φ","Χ","Ψ","Ω","Ώ"
    };

    char *getPunctuation(int punc){

        switch (punc) {
            case 0:     return ","; break;
            case 1:     return "."; break;
            case 2:     return ";"; break; 
            case 3:     return ":"; break;
            case 4:     return "!"; break; 
            case 5:     return "_"; break;
            case 6:     return "("; break; 
            case 7:     return ")"; break;
            case 8:     return "["; break; 
            case 9:     return "]"; break;
            case 10:    return "{"; break; 
            case 11:    return "}"; break;
            case 12:    return "+"; break; 
            case 13:    return "-"; break;
            case 14:    return "*"; break; 
            case 15:    return "/"; break;
            case 16:    return "="; break; 
            case 17:    return "~"; break;

            default:    exit(0);
        }
    }

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
    MEROSLOGOU: LLEKSI              { $<leksi>$ = $<leksi>1;                                                    }
                |LARTHRO            { $<leksi>$ = $<arthro>1;                                                   }
                |LARITHMOS          { $<leksi>$ = calloc(1, sizeof(char*));     sprintf($<leksi>$, "%f", $1);   }
                |LSTIKSI            { $<leksi>$ = strdup(getPunctuation($1));                                   }

    LARTHRO:    ARS_EN_AR           { $<arthro>$ = yylval.arthro;               printf("%s (", yylval.arthro); printf(italic bold"οριστικό άρθρο γένους αρσσενικό, ενικού" italic_re);       printf(") "); }
                |ARS_PL_AR          { $<arthro>$ = yylval.arthro;               printf("%s (", yylval.arthro); printf(italic bold"οριστικό άρθρο γένους αρσσενικό, πληθυντικού" italic_re);  printf(") "); }

                |THY_EN_AR          { $<arthro>$ = yylval.arthro;               printf("%s (", yylval.arthro); printf(italic bold"οριστικό άρθρο γένους θηλυκό, ενικού" italic_re);          printf(") "); }
                |THY_PL_AR          { $<arthro>$ = yylval.arthro;               printf("%s (", yylval.arthro); printf(italic bold"οριστικό άρθρο γένους θηλυκό, πληθυντικού" italic_re);     printf(") "); }

                |OUD_EN_AR          { $<arthro>$ = yylval.arthro;               printf("%s (", yylval.arthro); printf(italic bold"οριστικό άρθρο γένους ουδέτερο ενικού" italic_re);        printf(") "); }
                |OUD_PL_AR          { $<arthro>$ = yylval.arthro;               printf("%s (", yylval.arthro); printf(italic bold"οριστικό άρθρο γένους ουδέτερο πληθυντικού" italic_re);   printf(") "); }

                |_EN_AR             { $<arthro>$ = yylval.arthro;               printf("%s (", yylval.arthro); printf(italic bold"οριστικό άρθρο γένους αγνώστου ενικού" italic_re);         printf(") "); }
                |_PL_AR             { $<arthro>$ = yylval.arthro;               printf("%s (", yylval.arthro); printf(italic bold"οριστικό άρθρο γένους αγνώστου πληθυντικού" italic_re);    printf(") "); }

    LARITHMOS:  ARITHMOSFLOAT       { $<arithmos>$ = yylval.arithmos;           printf(a_c_r"%f (float αριθμός) ", (yylval.arithmos)); }
                |ARITHMOSINT        { $<arithmos>$ = yylval.arithmos;           printf(a_c_r"%d (int αριθμός) ", (int)(yylval.arithmos)); }

    LSTIKSI:    STIKSI              { $<stiksi>$ = yylval.stiksi;               if(yylval.stiksi == 17){printf("\n");}else{printf("%s (", stiksiToString[yylval.stiksi]); printf(italic bold"σημείο στίξης" italic_re); printf(") ");} }

    LLEKSI:     OUSIASTIKO          { $$ = yylval.ousiastiko;                   printf(""); WordExifFunctioner(yylval.leksi); printf(""); }
                |ONOMATA            { $$ = yylval.onomata;                      printf("%s (", yylval.leksi); printf(italic bold"όνομα" italic_re); printf(") ");}                                                                   
                |EPITHETO           { $$ = yylval.epitheto;                     printf(""); WordExifFunctioner(yylval.leksi); printf(""); }
                |RIMA               { $$ = yylval.rima;                         printf(""); WordExifFunctioner(yylval.leksi); printf(""); }
                |EPIRIMA            { $$ = yylval.epirima;                      printf(""); WordExifFunctioner(yylval.leksi); printf(""); }
                |ANTONUMIA          { $$ = yylval.antonumia;                    printf(""); WordExifFunctioner(yylval.leksi); printf(""); }
                |ARTHRO             { $$ = yylval.arthro;                       printf(""); WordExifFunctioner(yylval.leksi); printf(""); }
                |PROTHESI           { $$ = yylval.prothesi;                     printf(""); WordExifFunctioner(yylval.leksi); printf(""); }
                |SUDESMOS           { $$ = yylval.sundesmos;                    printf(""); WordExifFunctioner(yylval.leksi); printf(""); }
                |EPIFONIMA          { $$ = yylval.epifonima;                    printf(""); WordExifFunctioner(yylval.leksi); printf(""); }

%%


int yyerror (char* yaccProvidedMessage){

   printf("%s\n", yaccProvidedMessage);
   return 0;

}

int main(int argc, char** argv){
    
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

    return 0;
}
