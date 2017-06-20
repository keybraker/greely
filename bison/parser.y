%{

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <assert.h>

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

    char* stikser[] = {
        "comma",
        "teleia",
        "erotimatiko",
        "anokatoteleia",
        "thaumastiko",
        "kato paula",
        "openpar",
        "closepar", 
        "openblock",
        "closeclock", 
        "openbracket",
        "closebracket", 
        "plus", 
        "minus",
        "mul", 
        "div",
        "equal", 
        "equal",
        "enter"
    };


    char* getPunctuation(int punc){

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
    char*   epitheto;
    char*   rima;
    char*   epirima;
    char*   antonumia;
    char*   arthro;
    char*   prothesi;
    char*   sundesmos;
    char*   epifonima;

    int     stiksi;

    double  arithmos;

}

%start              PROTASI

%type<leksi>        LLEKSI MEROSLOGOU LEKSEIS
%type<stiksi>       LSTIKSI
%type<arithmos>     LARITHMOS 
%type<arthro>       LARTHRO

%token<arthro>      ARS_EN_AR ARS_PL_AR THY_EN_AR THY_PL_AR OUD_EN_AR OUD_PL_AR _PL_AR _EN_AR 

%token<ousiastiko>  OUSIASTIKO 
%token<epitheto>    EPITHETO 
%token<rima>        RIMA 
%token<epirima>     EPIRIMA 
%token<antonumia>   ANTONUMIA 
%token<arthro>      ARTHRO 
%token<prothesi>    PROTHESI 
%token<sundesmos>   SUDESMOS
%token<epifonima>   EPIFONIMA 

%token<stiksi>      STIKSI
%token<arithmos>    ARITHMOS 

%%

    PROTASI:    LEKSEIS             { printf(a_c_g"|----->Η ολοκληρωμένη πρόταση είναι: ");
                                      printf(a_c_m"%s\n\n\n"a_c_re,$<leksi>1); 
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
                                        
                                        printf(a_c_y"|---->λέξεις μέρος του λόγου: %s\n\n"a_c_re,$$);

                                    }
                |                   { $$ = NULL; }
                ;

    MEROSLOGOU: LLEKSI              { $<leksi>$ = $<leksi>1;                    printf(a_c_y"|--->Το μέρος του λόγου είναι: %s\n"a_c_re,($$)); }
                |LARTHRO            { $<leksi>$ = $<arthro>1;                   printf(a_c_y"|--->Το μέρος του λόγου είναι: %s\n"a_c_re,($$)); }
                |LARITHMOS          { $<leksi>$ = calloc(1, sizeof(char*));     sprintf($<leksi>$, "%f", $1); }
                |LSTIKSI            { $<leksi>$ = strdup(getPunctuation($1));   printf(a_c_y"|--->Το μέρος του λόγου είναι: %s\n"a_c_re,($$));/*switch case*/}

    LARTHRO:    ARS_EN_AR           { $<arthro>$ = yylval.arthro;               printf(a_c_y"|-> το αρσενικό άρθρο ενικού είναι: %s\n"a_c_re,(yylval.arthro)); }
                |ARS_PL_AR          { $<arthro>$ = yylval.arthro;               printf(a_c_y"|-> το αρσενικό άρθρο πληθυντικού είναι: %s\n"a_c_re,(yylval.arthro)); }

                |THY_EN_AR          { $<arthro>$ = yylval.arthro;               printf(a_c_y"|-> το θηλυκό άρθρο ενικού είναι: %s\n"a_c_re,(yylval.arthro)); }
                |THY_PL_AR          { $<arthro>$ = yylval.arthro;               printf(a_c_y"|-> το θηλυκό άρθρο πληθυντικού είναι: %s\n"a_c_re,(yylval.arthro)); }

                |OUD_EN_AR          { $<arthro>$ = yylval.arthro;               printf(a_c_y"|-> το ουδέτερο άρθρο ενικού είναι: %s\n"a_c_re,(yylval.arthro)); }
                |OUD_PL_AR          { $<arthro>$ = yylval.arthro;               printf(a_c_y"|-> το ουδέτερο άρθρο πληθυντικού είναι: %s\n"a_c_re,(yylval.arthro)); }

                |_EN_AR             { $<arthro>$ = yylval.arthro;               printf(a_c_y"|-> το άγνωστο άρθρο ενικού είναι: %s\n"a_c_re,(yylval.arthro)); }
                |_PL_AR             { $<arthro>$ = yylval.arthro;               printf(a_c_y"|-> το άγνωστο άρθρο πληθυντικού είναι: %s\n"a_c_re,(yylval.arthro)); }

    LARITHMOS:  ARITHMOS            { $<arithmos>$ = yylval.arithmos;           printf(a_c_y"|->αριθμός είναι: %f\n"a_c_re,(yylval.arithmos)); }

    LSTIKSI:    STIKSI              { $<stiksi>$ = yylval.stiksi;               printf(a_c_y"|->σημείο στίξης είναι: %d\n"a_c_re,(yylval.stiksi)); }

    LLEKSI:     OUSIASTIKO          { $$ = yylval.ousiastiko;                 printf(a_c_y"|-->λέξη είναι: %s\n"a_c_re,(yylval.leksi)); }
                |EPITHETO           { $$ = yylval.epitheto;                 printf(a_c_y"|-->λέξη είναι: %s\n"a_c_re,(yylval.leksi)); }
                |RIMA               { $$ = yylval.rima;                 printf(a_c_y"|-->λέξη είναι: %s\n"a_c_re,(yylval.leksi)); }
                |EPIRIMA            { $$ = yylval.epirima;                 printf(a_c_y"|-->λέξη είναι: %s\n"a_c_re,(yylval.leksi)); }
                |ANTONUMIA          { $$ = yylval.antonumia;                 printf(a_c_y"|-->λέξη είναι: %s\n"a_c_re,(yylval.leksi)); }
                |ARTHRO             { $$ = yylval.arthro;                 printf(a_c_y"|-->λέξη είναι: %s\n"a_c_re,(yylval.leksi)); }
                |PROTHESI           { $$ = yylval.prothesi;                 printf(a_c_y"|-->λέξη είναι: %s\n"a_c_re,(yylval.leksi)); }
                |SUDESMOS           { $$ = yylval.sundesmos;                 printf(a_c_y"|-->λέξη είναι: %s\n"a_c_re,(yylval.leksi)); }
                |EPIFONIMA          { $$ = yylval.epifonima;                 printf(a_c_y"|-->λέξη είναι: %s\n"a_c_re,(yylval.leksi)); }

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
