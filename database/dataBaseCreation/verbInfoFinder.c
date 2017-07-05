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

    struct katalixis* master = NULL;
    master = bufferKatalixis(master);

    while (fgets(buffer,255, f1)!= NULL)    { 

        file = realloc(file, 255 * 10 * sizeof(char*));
        if(file[i] == NULL){
            file[i] = calloc(2*255, sizeof(char));
            strcpy(file[i], buffer);

        }
        i++;

    }

    word                    = argv[1]; 
    xorisKataklida          = deleteKataklida(word, master); 
    AxorisKataklida         = atono(xorisKataklida); 
    xorisKataklidaLT        = protoTonismeno(AxorisKataklida); 
    xorisKataklidaPT        = teleutaioTonismeno(AxorisKataklida); 

    data->length            = strlen(word); 
    data->word              = word; 
    data->xorisKataklida    = xorisKataklida; 
    data->AxorisKataklida   = AxorisKataklida; 
    data->xorisKataklidaLT  = xorisKataklidaLT; 
    data->xorisKataklidaPT  = xorisKataklidaPT; 

    if( (returner = xronoi(file, master, i, data)) != NULL )
        printf("%s\n", returner); 
   
    printf("END REACHED\n");
    return 0;

}