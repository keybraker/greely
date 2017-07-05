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
        // oti nanai prosoxi sti calloc kai realloc
        file = realloc(file, 255*10/*strlen(buffer)+1*/* sizeof(char*));
        if(file[i] == NULL){
            file[i] = calloc(2*255/*strlen(buffer)+1*/, sizeof(char));
            strcpy(file[i], buffer);

        }
        i++;

    }

    word                    = argv[1]; printf("mpika1\n");
    xorisKataklida          = deleteKataklida(word); printf("mpika2\n");
    AxorisKataklida         = atono(xorisKataklida); printf("mpika3\n");
    xorisKataklidaLT        = protoTonismeno(AxorisKataklida); printf("mpika4\n");
    xorisKataklidaPT        = teleutaioTonismeno(AxorisKataklida); printf("mpika5\n");

    data->length            = strlen(word); printf("mpika6\n");
    data->word              = word; printf("mpika7\n");
    data->xorisKataklida    = xorisKataklida; printf("mpika8\n");
    data->AxorisKataklida   = AxorisKataklida; printf("mpika9\n");
    data->xorisKataklidaLT  = xorisKataklidaLT; printf("mpika10\n");
    data->xorisKataklidaPT  = xorisKataklidaPT; printf("mpika11\n");

    if( (returner = xronoi(file, i, data)) != NULL )
        printf("%s\n", returner); 
   
    printf("END REACHED\n");
    return 0;

}