#include "masterHead.h"

int main(int argc, char** argv){

    FILE* f1 = fopen ("../generatedDatabases/greekRimata.txt", "r");
    if(!f1){ printf("ERROR f1"); exit(1); }

    FILE* f2 = fopen ("../generatedDatabases/greekRimataCreator.txt", "w+");
    if(!f2){ printf("ERROR f2"); exit(1); }

    char    *len, *syllen;
    char    *word, *syllabes, *syllabes2, *syllabes3 ,*syl, *sylp, *sylpp, *sylpcmplt;
    char    *wcreator, *winserter;
    char    *screator, *sinserter;
    char    buffer[255];
    
    while (fgets(buffer,255, f1)!= NULL)    { 

        len = strtok(buffer,"|");
        word = strtok(NULL, "|");
        syllen = strtok(NULL, "|");
        syllabes = strtok(NULL, "|");
        
        syllabes2 = calloc(strlen(syllabes),sizeof(char));
        strcpy(syllabes2, syllabes);

        wcreator  = calloc(1.5 * strlen(word),sizeof(char));
        screator  = calloc(1.5 * strlen(syllabes),sizeof(char));
        sylpcmplt = calloc(10 * strlen(word),sizeof(char));

        syl = strtok(syllabes2, "-");
        sylp = strdup(syl);
        sylpp = strdup(syl);

        strcpy(sylpcmplt,"");
        strcpy(wcreator, ""); 
        strcpy(screator, ""); 

        int i,exiter = stringToInt(syllen);
        for(i = 0; i < exiter; i++){
            
            if(i){
                strcat(wcreator,sylp); 
                strcat(screator,sylp); 
                strcat(screator,"-"); 
            }

            if( strcmp(sylpcmplt,sylpp) != 0 )
                strcat(sylpcmplt,sylpp);
            sylpp = sylp;
            sylp = syl;
            syl = strtok(NULL, "-");

        }          
        
        char *check1 = calloc(strlen(sylpp),sizeof(char));
        char *check2 = calloc(strlen(sylpp),sizeof(char));

        strcpy(check1, &sylpp[(strlen(sylpp)/2)]);
        strcpy(check2, &sylpp[(strlen(sylpp)/2)]-1);

        if( strlen(sylp)/2 > 4){

            char *p = NULL, *pp = NULL;
            
            p = strtok(syllabes, "-");
            if(p != NULL) 
                pp = strdup(p);
            
            while(p){
                pp = strdup(p);
                p = strtok(NULL, "-");
            }
            sylp = strdup(pp);
        }

        if(strcmp("χωνεύω", word) == 0){

            printf("λlen = %s\n", len);
            printf("word = %s\n", word);
            printf("syllen = %s\n", syllen);
            printf("syllabes = %s\n", syllabes);
            printf("sylp = %s\n", sylp);
            printf("sylpp = %s\n", sylpp);
            printf("wcreator = %s\n", wcreator);
            printf("screator = %s\n", screator);
            printf("sylpcmplt = %s\n\n", sylpcmplt);

        }
        
        //if(strcmp("χτυπάω", word) == 0){ printf("ΧΧΧτυπάω\n\n"); }

        if(strcmp(sylp, "ω") == 0){   

            if(strcmp(sylpp,"ά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "", sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "", sylpcmplt, 1);

            }else if(strcmp(sylpp,"βά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "β", sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "β", sylpcmplt, 1);

            }else if(strcmp(sylpp,"γά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "γ", sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "γ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"δά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "δ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "δ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"ζά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "ζ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "ζ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"θά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "θ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "θ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"κά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "κ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "κ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"λά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "λ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "λ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"μά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "μ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "μ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"νά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "ν",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "ν", sylpcmplt, 1);

            }else if(strcmp(sylpp,"ξά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "ξ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "ξ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"πά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "π",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "π", sylpcmplt, 1);

            }else if(strcmp(sylpp,"ρά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "ρ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "ρ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"σά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "σ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "σ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"τά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "τ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "τ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"φά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "φ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "φ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"χά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "χ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "χ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"ψά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "ψ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "ψ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"χλά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "χλ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "χλ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"στά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "στ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "στ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"μπά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "μπ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "μπ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"πρά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "πρ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "πρ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"ντά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "ντ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "ντ", sylpcmplt, 1);

            }else if(strcmp(check1,"τά") == 0 || strcmp(check2,"τά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "τ", sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "τ", sylpcmplt, 1);

            }else if(strcmp(check1,"ρά") == 0 || strcmp(check2,"ρά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "ρ", sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "ρ", sylpcmplt, 1);

            }else if(strcmp(check1,"ά") == 0 || strcmp(check2,"ά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "", sylpcmplt, 1);

            }else if(strcmp(sylpp, "νεύ") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "", sylpcmplt, 0);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "", sylpcmplt, 2);

            }else{
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "", sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "", sylpcmplt, 1);
 
            }

        }else if(strcmp(sylp, "ώ") == 0){ 

            if(strcmp(sylpp,"ά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "", sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "", sylpcmplt, 1);

            }else if(strcmp(sylpp,"βά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "β", sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "β", sylpcmplt, 1);

            }else if(strcmp(sylpp,"γά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "γ", sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "γ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"δά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "δ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "δ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"ζά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "ζ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "ζ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"θά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "θ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "θ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"κά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "κ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "κ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"λά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "λ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "λ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"μά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "μ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "μ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"νά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "ν",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "ν", sylpcmplt, 1);

            }else if(strcmp(sylpp,"ξά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "ξ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "ξ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"πά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "π",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "π", sylpcmplt, 1);

            }else if(strcmp(sylpp,"ρά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "ρ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "ρ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"σά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "σ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "σ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"τά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "τ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "τ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"φά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "φ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "φ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"χά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "χ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "χ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"ψά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "ψ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "ψ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"χλά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "χλ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "χλ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"στά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "στ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "στ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"μπά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "μπ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "μπ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"πρά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "πρ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "πρ", sylpcmplt, 1);

            }else if(strcmp(sylpp,"ντά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "ντ",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "ντ", sylpcmplt, 1);

            }else if(strcmp(check1,"τά") == 0 || strcmp(check2,"τά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "τ", sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "τ", sylpcmplt, 1);

            }else if(strcmp(check1,"ρά") == 0 || strcmp(check2,"ρά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "ρ", sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "ρ", sylpcmplt, 1);

            }else if(strcmp(check1,"ά") == 0 || strcmp(check2,"ά") == 0){
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "",  sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "", sylpcmplt, 1);

            }else{
                enestotas(f2, word, syllabes, wcreator, screator, syllen, "", sylpcmplt, 1);
                paratatikos(f2, word, syllabes, wcreator, screator, syllen, "", sylpcmplt, 1);
 
            }

        }else if(strcmp(sylp, "βω") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "β", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "β", sylpcmplt, 0);

        }else if(strcmp(sylp, "βώ") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "β", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "β", sylpcmplt, 0);

        }else if(strcmp(sylp, "γω") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "γ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "γ", sylpcmplt, 0);

        }else if(strcmp(sylp, "γώ") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "γ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "γ", sylpcmplt, 0);

        }else if(strcmp(sylp, "δω") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "δ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "δ", sylpcmplt, 0);

        }else if(strcmp(sylp, "δω") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "δ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "δ", sylpcmplt, 0);

        }else if(strcmp(sylp, "ζω") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "ζ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "ζ", sylpcmplt, 2);

        }else if(strcmp(sylp, "ζώ") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "ζ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "ζ", sylpcmplt, 0);

        }else if(strcmp(sylp, "θω") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "θ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "θ", sylpcmplt, 0);

        }else if(strcmp(sylp, "θώ") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "θ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "θ", sylpcmplt, 0);

        }else if(strcmp(sylp, "κω") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "κ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "κ", sylpcmplt, 0);

        }else if(strcmp(sylp, "κώ") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "κ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "κ", sylpcmplt, 0);

        }else if(strcmp(sylp, "λω") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "λ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "λ", sylpcmplt, 0);

        }else if(strcmp(sylp, "λώ") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "λ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "λ", sylpcmplt, 0);

        }else if(strcmp(sylp, "μω") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "μ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "μ", sylpcmplt, 0);

        }else if(strcmp(sylp, "μώ") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "μ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "μ", sylpcmplt, 0);

        }else if(strcmp(sylp, "νω") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "ν", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "ν", sylpcmplt, 0);               

        }else if(strcmp(sylp, "νώ") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "ν", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "ν", sylpcmplt, 0);

        }else if(strcmp(sylp, "ξω") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "ξ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "ξ", sylpcmplt, 0);

        }else if(strcmp(sylp, "ξώ") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "ξ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "ξ", sylpcmplt, 0);

        }else if(strcmp(sylp, "πω") == 0){  
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "π", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "π", sylpcmplt, 0);

        }else if(strcmp(sylp, "πώ") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "π", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "π", sylpcmplt, 0);

        }else if(strcmp(sylp, "ρω") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "ρ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "ρ", sylpcmplt, 0);

        }else if(strcmp(sylp, "ρώ") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "ρ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "ρ", sylpcmplt, 0);

        }else if(strcmp(sylp, "σω") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "σ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "σ", sylpcmplt, 0);

        }else if(strcmp(sylp, "σώ") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "σ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "σ", sylpcmplt, 0);

        }else if(strcmp(sylp, "τω") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "τ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "τ", sylpcmplt, 0);

        }else if(strcmp(sylp, "τώ") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "τ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "τ", sylpcmplt, 0);

        }else if(strcmp(sylp, "φω") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "φ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "φ", sylpcmplt, 0);

        }else if(strcmp(sylp, "φώ") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "φ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "φ", sylpcmplt, 0);

        }else if(strcmp(sylp, "χω") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "χ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "χ", sylpcmplt, 0);

        }else if(strcmp(sylp, "χώ") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "χ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "χ", sylpcmplt, 0);

        }else if(strcmp(sylp, "ψω") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "ψ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "ψ", sylpcmplt, 0);

        }else if(strcmp(sylp, "ψώ") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "ψ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "ψ", sylpcmplt, 0);

        }else if(strcmp(sylp, "χλω") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "χλ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "χλ", sylpcmplt,0);

        }else if(strcmp(sylp, "χλώ") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "χλ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "χλ", sylpcmplt,0);

        }else if(strcmp(sylp, "στω") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "στ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "στ", sylpcmplt,0);

        }else if(strcmp(sylp, "στώ") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "στ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "στ", sylpcmplt,0);

        }else if(strcmp(sylp, "πρω") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "πρ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "πρ", sylpcmplt,0);

        }else if(strcmp(sylp, "πρώ") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "πρ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "πρ", sylpcmplt,0);

        }else if(strcmp(sylp, "μπω") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "μπ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "μπ", sylpcmplt, 0);

        }else if(strcmp(sylp, "μπώ") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "μπ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "μπ", sylpcmplt, 0);

        }else if(strcmp(sylp, "μαι") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "μ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "μ", sylpcmplt, 0);

        }else if(strcmp(sylp, "μαί") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "μ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "μ", sylpcmplt, 0);

        }else if(strcmp(sylp, "νται") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "ντ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "ντ", sylpcmplt, 0);

        }else if(strcmp(sylp, "νταί") == 0){
            enestotas(f2, word, syllabes, wcreator, screator, syllen, "ντ", sylpcmplt, 0);
            paratatikos(f2, word, syllabes, wcreator, screator, syllen, "ντ", sylpcmplt, 0);

        }else{ 
            // printf("                                ERROR\n");
            //exit(0);

        }
        
    }

    fclose(f1);
    fclose(f2);

}