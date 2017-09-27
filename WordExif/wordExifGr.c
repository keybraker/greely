/*
* IF ABSOLUTE MATCH IS NOT FOUND, CORE IS SEARCHED USING THIS
* FUNCTION
*
*
*
*
*
*
*
*
*/

#include "includerino.h"
#include "wordExifFunc.h"

//fortonei olo to arxeio se ena pinaka kai ton diabazei anapoda 
//roi kanones gia ta prothemata menontai na ulopoihthoun
int WordExifFunctioner(char* wordInput){

    /*---------------------------------------------------------------------- OPEN DATABASES ----------------------------------------------------------------------*/
    FILE* f1 = fopen ("wordExif/wordSyllabusGr2.txt", "r");
    if(!f1){ printf("ERROR f1"); exit(1); }

    FILE* f2 = fopen ("database [obsolete]/apeutheiasmesastokodika greekTransform.txt", "r");
    if(!f2){ printf("ERROR f1"); exit(1); }

    int     type, jk = 0;
    char    *len, *syllen;
    char    *word, *syllabes, *syllabesEditable;
    char    *wordWithoutEnding;
    char    *buffer = calloc(255*33636,sizeof(char*));
    char    **wholeFile = calloc(255*33636,sizeof(char));

    /*---------------------------------------------------------------------- READING FILES ----------------------------------------------------------------------*/
    //THIS MUST HAPPEN ONLY ONCE YOU LAUNCH THE PROGRAM NOT EVERY TIME
    while (fgets(buffer,255, f1)!= NULL)    { 
        if(wholeFile[jk] == NULL){
            wholeFile[jk] = calloc(255 * strlen(buffer)+1, sizeof(char));
            strcpy(wholeFile[jk], buffer);
        }else{
          printf("error\n");
          return 1;
        }
        jk++;

    };

    fclose(f1);

    jk--;
    int reader = jk;

    /*---------------------------------------------------------------------- STIKSEIS ----------------------------------------------------------------------*/
    while (reader > 0)    {

        strcpy(buffer, wholeFile[reader]);

        len         = strtok(buffer,    "|");
        word        = strtok(NULL,      "|");
        syllen      = strtok(NULL,      "|");
        syllabes    = strtok(NULL,      "|");
        type        = toInt(strtok(NULL,      "|"));

        // KANEI TO PROTO GRAMMA MIKRO GIATI I VASI EINAI ME MIKRA
        char* oldWordInput = calloc(16,sizeof(char));
        char* kluks = calloc(255*33636,sizeof(char));
        while (fgets(kluks,255, f2)!= NULL)    { 

            char* one = strtok(kluks,    "|");
            char* two = strtok(NULL,      "|");
            strtok(one, "\n"); // delete trailing \n
            strtok(two, "\n"); // delete trailing \n
            if(strncmp(two, wordInput, strlen(two)) == 0){
                strcpy(oldWordInput, wordInput);
                strcpy(wordInput, one);
                strncat(wordInput, oldWordInput + 2, strlen(oldWordInput)+1 - 1);
                break;
            }
            
        };
        /////////////////

        if( strcmp(word, wordInput) == 0 ){
            // goes to array finds type
            // calls the type defined
            // function and executes it
            functionPrinter[type](wholeFile[reader]);
            return 0;

        } 

        reader--;

    }

    reader = jk;

    while (reader > 0)    { 

        strcpy(buffer, wholeFile[reader]);

        len         = strtok(buffer,    "|");
        word        = strtok(NULL,      "|");
        syllen      = strtok(NULL,      "|");
        syllabes    = strtok(NULL,      "|");
        type        = toInt(strtok(NULL,      "|"));

        syllabesEditable = calloc(strlen(syllabes),sizeof(char));     
        strcpy(syllabesEditable, syllabes);  
        wordWithoutEnding = calloc(255 * strlen(word),sizeof(char));
        strcpy(wordWithoutEnding, strtok(syllabesEditable, "-")); 
  
        for(int i = 2; i < toInt(syllen); i++){ // kano int = 2 etsi oste h teleutaia sullabi na min antigrafei
            strcat(wordWithoutEnding,strtok(NULL, "-")); 
        }
        
        // printf("\n>len = %s\n", len);
        // printf("word = %s\n", word);
        // printf("syllen = %s\n", syllen);
        // printf("syllabes = %s\n", syllabes);
        // printf("type = %d\n", type);
        // printf("wordWithoutEnding = %s\n", wordWithoutEnding);
        // printf("syllabesEditable = %s\n", syllabesEditable);

        if( strncmp(wordWithoutEnding, wordInput, strlen(wordWithoutEnding)) == 0 ){
            printf("%s [" , wordInput);
            printf(italic bold "%s"italic_re, wordWithoutEnding);
            printf("] ");
            return 0;

        }   
            
        reader--;

    }

    fclose(f2);
    printf("%s [" , wordInput);
    printf(italic bold "_"italic_re);
    printf("] ");

    return 0;
}