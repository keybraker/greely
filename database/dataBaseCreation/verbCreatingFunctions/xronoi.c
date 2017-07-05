#include "xronoi.h"

char* xronoi(char** file, int lines, struct allData *data){ 

    printf("IN XRONOI\n");
    
    char* AxorisKataklida = calloc(1,1024);
    char* xorisKataklidaLT = calloc(1,1024);
    char* xorisKataklidaPT = calloc(1,1024);

    AxorisKataklida     = atono(data->xorisKataklida);
    xorisKataklidaLT    = protoTonismeno(AxorisKataklida);
    xorisKataklidaPT    = teleutaioTonismeno(AxorisKataklida);

    char *wordNoEndOrigin = calloc(1, 256);
    strcpy(wordNoEndOrigin, deleteKataklida(data->word));
    printf("deleteKataklida(data->word)) = %s\n", deleteKataklida(data->word));
    strcat(wordNoEndOrigin, "ω");
    printf("\n\nwordNoEndOrigin = %s\n", wordNoEndOrigin);

    char *wordwithoutending = calloc (1, 256);
    char *helper = calloc (1, 256);
    char buffer[255];
    char *len, *word2, *syllen, *syllabes;
    int  reader = lines, k = 0, j = 0;

    while(k < reader){
        
        len         = strtok(file[k], "|");
        word2       = strtok(   NULL, "|");
        syllen      = strtok(   NULL, "|");
        syllabes    = strtok(   NULL, "|");

        // printf("%d) %s\n",  k, wordNoEndOrigin);
        // printf("%d) %s\n",  k, len);
        // printf("%d) %s\n",  k, word2);
        // printf("%d) %s\n",  k, syllen);
        // printf("%d) %s\n",  k, syllabes);
        
        j=1;
        strcpy(wordwithoutending, "");
        helper = strtok(syllabes, "-");
        if(stringToInt(syllen) != 1){
            while(j < stringToInt(syllen)){
                strcat(wordwithoutending, helper);
                helper = strtok(NULL, "-");
                j++;
            }
        }else{
            strcpy(wordwithoutending, word2);
        }

        char* returner = calloc(1, 255);
        // printf("BEFORE: \n");
        // printf("%s == %s\n", wordNoEndOrigin, word2);
        if( strcmp(wordNoEndOrigin, word2) == 0 ){

            sprintf(returner, "Core of \"%s\" is \"%s\"\n", data->word, word2);
            return returner;

        }   

        k++;
    }

    return NULL;

}


