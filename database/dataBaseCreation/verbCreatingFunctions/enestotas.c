#include "xronoi.h"

void enestotas(struct allData *data){ 

    char* AxorisKataklida = calloc(1,1024);
    char* xorisKataklidaLT = calloc(1,1024);
    char* xorisKataklidaPT = calloc(1,1024);

    AxorisKataklida     = atono(data->xorisKataklida);
    xorisKataklidaLT    = protoTonismeno(AxorisKataklida);
    xorisKataklidaPT    = teleutaioTonismeno(AxorisKataklida);

    if(strcmp("λύνω", data->word) == 0 || strcmp("χωνεύω", data->word) == 0 || strcmp("αντιπροσωπεύω", data->word) == 0){

        printf("\nenestots:\n");
        printf("data->length            = %d\n", data->length);
        printf("data->word              = %s\n", data->word);
        printf("data->xorisKataklida    = %s\n", data->xorisKataklida);
        printf("data->AxorisKataklida   = %s\n", data->AxorisKataklida);
        printf("data->xorisKataklidaLT  = %s\n", data->xorisKataklidaLT);
        printf("data->xorisKataklidaPT  = %s\n", data->xorisKataklidaPT);

    }

    FILE* f1 = fopen ("../generatedDatabases/greekRimata.txt", "r");
    if(!f1){ printf("ERROR f1"); exit(1); }

    char buffer[255];
    while (fgets(buffer,255, f1)!= NULL)    { 

    }



    // if( strcmp() == 0 ){

    // }

}


