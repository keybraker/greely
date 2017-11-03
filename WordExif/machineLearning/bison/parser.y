%{

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <assert.h>
    // #include "../WordExif/includerino.h"

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

%token<arthro>      Ars_En_Onm En_Gen Ars_En_Ait Pl_Onm Pl_Gen 
%token<arthro>      Ars_Pl_Ait Thy_En_Onm Thy_En_Gen Thy_En_Ait 
%token<arthro>      Thy_Pl_Ait Oud_En_OnmAit Oud_Pl_OnmAit

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

    PROTASI:    LEKSEIS				{}
                                    ;

    LEKSEIS:    LEKSEIS MEROSLOGOU  {}
                |                   { $$ = NULL; }
                ;
                                    // TO $$ krataei ti pliroforia
    MEROSLOGOU: LLEKSI              { $<leksi>$ = $<leksi>1;                                                    }
                |LARTHRO            { $<leksi>$ = $<arthro>1;                                                   }
                |LARITHMOS          { $<leksi>$ = calloc(1, sizeof(char*));     sprintf($<leksi>$, "%f", $1);   }
                |LSTIKSI            { $<leksi>$ = strdup(stiksiToStringName[$1]);                               }

    LARTHRO:    Ars_En_Onm			{ $<arthro>$ = yylval.arthro; }
                |En_Gen				{ $<arthro>$ = yylval.arthro; }

                |Ars_En_Ait			{ $<arthro>$ = yylval.arthro; }
                |Pl_Onm				{ $<arthro>$ = yylval.arthro; }

                |Pl_Gen				{ $<arthro>$ = yylval.arthro; }
                |Ars_Pl_Ait			{ $<arthro>$ = yylval.arthro; }

                |Thy_En_Onm			{ $<arthro>$ = yylval.arthro; }
                |Thy_En_Gen			{ $<arthro>$ = yylval.arthro; }

               	|Thy_En_Ait			{ $<arthro>$ = yylval.arthro; }
                |Thy_Pl_Ait			{ $<arthro>$ = yylval.arthro; }

                |Oud_En_OnmAit		{ $<arthro>$ = yylval.arthro; }
                |Oud_Pl_OnmAit		{ $<arthro>$ = yylval.arthro; }

    LARITHMOS:  ARITHMOSFLOAT       { $<arithmos>$ = yylval.arithmos;   }
                |ARITHMOSINT        { $<arithmos>$ = yylval.arithmos;   }

    LSTIKSI:    STIKSI              { $<stiksi>$ = yylval.stiksi;   }

    LLEKSI:     OUSIASTIKO          { $$ = yylval.ousiastiko;   }
                |ONOMATA            { $$ = yylval.onomata;  	}
                |EPITHETO           { $$ = yylval.epitheto; 	}
                |RIMA               { $$ = yylval.rima; 		}
                |EPIRIMA            { $$ = yylval.epirima;  	}
                |ANTONUMIA          { $$ = yylval.antonumia;    }
                |ARTHRO             { $$ = yylval.arthro;   	}
                |PROTHESI           { $$ = yylval.prothesi; 	}
                |SUDESMOS           { $$ = yylval.sundesmos;    }
                |EPIFONIMA          { $$ = yylval.epifonima;    }

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
