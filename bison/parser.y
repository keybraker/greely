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

    enum stikser {

        comma,
        teleia,
        erotimatiko,
        anokatoteleia,
        thaumastiko,
        paula,
        openpar,
        closepar, 
        enter

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

    char*   epitheto;
    char*   ousiastiko;
    char*   arthro;

    int     stiksi;

    double  arithmos;

}

%start              PROTASI

%type<leksi>        LLEKSI MEROSLOGOU
%type<stiksi>       LSTIKSI
%type<arithmos>     LARITHMOS 

%token<epitheto>    EPITHETO
%token<ousiastiko>  OUSIA
%token<arthro>      ARTHRO

%token<leksi>       LEKSI 
%token<stiksi>      STIKSI
%token<arithmos>    ARITHMOS 

%%

    PROTASI:    LEKSEIS            { printf("Sentence is complete\n"); }
                ;

    LEKSEIS:    LEKSEIS MEROSLOGOU { printf("LEKSEIS MEROSLOGOU\n"); }
                |
                ;

    MEROSLOGOU: LLEKSI      { $$ = $1; }
                |LARITHMOS   { /*sprintf($$, "%d", $1);*/ }
                |LSTIKSI     { $$ = "kappa"; /*switch case*/}

    LLEKSI:     LEKSI       { $<leksi>$ = yylval.leksi; printf("leksi is %s\n",(yylval.leksi)); }

    LARITHMOS:  ARITHMOS    { $<arithmos>$ = yylval.arithmos; printf("arithmos is %f\n",(yylval.arithmos)); }

    LSTIKSI:    STIKSI      { $<stiksi>$ = yylval.stiksi; printf("stiksi is %d\n",(yylval.stiksi)); }

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
