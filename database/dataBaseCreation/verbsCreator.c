#include "verbCreatingFunctions/xronoi.h"

int main(int argc, char** argv){
        
    char* word = calloc(1, 64);
    word = "λύνω";

    struct allData *data = calloc (sizeof(struct allData), 1);
    char* xorisKataklida    = calloc(1, 256);
    char* AxorisKataklida   = calloc(1, 256);
    char* xorisKataklidaLT  = calloc(1, 256);
    char* xorisKataklidaPT  = calloc(1, 256);

    xorisKataklida = deleteKataklida(word);
    AxorisKataklida = atono(xorisKataklida);
    xorisKataklidaLT = protoTonismeno(AxorisKataklida);
    xorisKataklidaPT = teleutaioTonismeno(AxorisKataklida);

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

    enestotas(data);
    /*

    */
        

}