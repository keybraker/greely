#include "verbCreatingFunctions/xronoi.h"

int main(int argc, char** argv){
        
    if(argc != 2){
        printf("too few arguments\n");
        exit(0);
    }

    char* word = calloc(1, 64);

    struct allData *data    = calloc (sizeof(struct allData), 1);
    char* xorisKataklida    = calloc(1, 256);
    char* AxorisKataklida   = calloc(1, 256);
    char* xorisKataklidaLT  = calloc(1, 256);
    char* xorisKataklidaPT  = calloc(1, 256);
    char* returner          = calloc(1, 256);
    char* buffer            = calloc(1, 256);
    char** file             = calloc(1, 256);
    int i                   = 0;
    
    FILE* f1 = fopen ("../generatedDatabases/greekRimata.txt", "r");
    if(!f1){ printf("ERROR f1"); exit(1); }

    while (fgets(buffer,255, f1)!= NULL)    { 
        // oti nanai prosoxi sti calloc kai realloc
        file = realloc(file, 255*10/*strlen(buffer)+1*/* sizeof(char*));
        if(file[i] == NULL){
            file[i] = calloc(2*255/*strlen(buffer)+1*/, sizeof(char));
            strcpy(file[i], buffer);

        }
        i++;

    }


    word                    = argv[1];
    xorisKataklida          = deleteKataklida(word);
    AxorisKataklida         = atono(xorisKataklida);
    xorisKataklidaLT        = protoTonismeno(AxorisKataklida);
    xorisKataklidaPT        = teleutaioTonismeno(AxorisKataklida);

    data->length            = strlen(word);
    data->word              = word;
    data->xorisKataklida    = xorisKataklida;
    data->AxorisKataklida   = AxorisKataklida;
    data->xorisKataklidaLT  = xorisKataklidaLT;
    data->xorisKataklidaPT  = xorisKataklidaPT;

    if(strcmp("λύνω", data->word) == 0 || strcmp("χωνεύω", data->word) == 0 || strcmp("αντιπροσωπεύω", data->word) == 0){

        printf("\nekso:\n");
        printf("data->length            = %d\n", data->length);
        printf("data->word              = %s\n", data->word);
        printf("data->xorisKataklida    = %s\n", data->xorisKataklida);
        printf("data->AxorisKataklida   = %s\n", data->AxorisKataklida);
        printf("data->xorisKataklidaLT  = %s\n", data->xorisKataklidaLT);
        printf("data->xorisKataklidaPT  = %s\n", data->xorisKataklidaPT);

    }

    if( (returner = enestotas(file, i, data)) != NULL )
        printf("%s\n", returner); 
    /*

    */
    printf("END REACHED\n");
    return 0;

}