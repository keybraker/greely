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

#include "master_header.h"
#include "word_type_print.h"

//fortonei olo to arxeio se ena pinaka kai ton diabazei anapoda 
//roi kanones gia ta prothemata menontai na ulopoihthoun
int WordExifFunctioner(char* wordInput){

    /*---------------------------------------------------------------------- OPEN DATABASES ----------------------------------------------------------------------*/
    FILE* f1 = fopen ("bison_flex/analyzer_funcs/word_data_gr.txt", "r");
    if(!f1){ printf("cannot open word_data_gr.txt"); exit(1); }

    int     type, jk = 0;
    char    *len, *syllen, *isCap;
    char    *word, *syllabes, *syllabesEditable;
    char    *wordWithoutEnding, *wordInputSmall, *wordInputCap;
    char    *buffer = calloc(255, sizeof(char));
    char    **wholeFile = calloc(255*8912, sizeof(char*));

    /*---------------------------------------------------------------------- READING FILES ----------------------------------------------------------------------*/
    //THIS MUST HAPPEN ONLY ONCE YOU LAUNCH THE PROGRAM NOT EVERY TIME
    while (fgets(buffer, 255, f1)!= NULL)    { 

        if(wholeFile[jk] == NULL){
            wholeFile[jk] = calloc(strlen(buffer)*255, sizeof(char));
            strcpy(wholeFile[jk], buffer);
        }else{
          printf("error\n");
          return 1;
        }
        jk++;

    };
    jk--;
    fclose(f1);

    wordInputCap = strdup(wordInput);
    wordInputSmall = capToSmall(wordInput);
    wordInput = strdup(wordInputCap);

    isCap = NULL;
    if(strcmp(wordInputCap, wordInputSmall) != 0)
        isCap = wordInputCap;

    int reader = jk;

    /*----------------------------------------------------------------- LEKSEIS APO WORDEXIFGR -----------------------------------------------------------------*/
    while (reader > 0)    {

        strcpy(buffer, wholeFile[reader]);

        len         = strtok(buffer,    "|");
        word        = strtok(NULL,      "|");
        syllen      = strtok(NULL,      "|");
        syllabes    = strtok(NULL,      "|");
        type        = toInt(strtok(NULL,      "|"));

        if( strcmp(word, wordInputSmall) == 0 ){
            // goes to array finds type
            // calls the type defined
            // function and executes it
            functionPrinter[type](wholeFile[reader], isCap);
            return 0;

        } 

        reader--;

    }

    reader = jk;

    /*------------------------------------------------ AN DEN BRETHEI STI BASH PSAXNOUME TI RIZA THS LEKSEIS GIA EDIT META -------------------------------------*/
    while (reader > 0)    { 

        strcpy(buffer, wholeFile[reader]);

        len         = strtok(buffer, "|");
        word        = strtok(NULL, "|");
        syllen      = strtok(NULL, "|");
        syllabes    = strtok(NULL, "|");
        type        = toInt(strtok(NULL, "|"));

        syllabesEditable = calloc(strlen(syllabes), sizeof(char));     
        strcpy(syllabesEditable, syllabes);  
        wordWithoutEnding = calloc(255 * strlen(word), sizeof(char));
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

        if( strncmp(wordWithoutEnding, wordInputSmall, strlen(wordWithoutEnding)) == 0 ){
            printf("%s-[" , wordInputSmall);
            printf(italic bold "%s"italic_re, wordWithoutEnding);
            printf("] ");
            return 0;

        }   
            
        reader--;

    }

    printf("%s-[" , wordInputSmall);
    printf(italic bold "_"italic_re);
    printf("] ");

    return 0;
}