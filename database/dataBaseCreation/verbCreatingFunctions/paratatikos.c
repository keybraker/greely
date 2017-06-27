#include "paratatikos.h"


void paratatikos(FILE* f2, char *word, char* syllabes, char *wcreator, char *screator, char *syllen, char* ch, char *cm, int version){ 

    fprintf(f2, "\nPARATATIKOS\n");

    char* wcreatorAtono = calloc(1,1024);
    char* wcreatorTeleutaioTonismeno = calloc(1,1024);
    char* wcreatorProtoTonismeno = calloc(1,1024);

    wcreatorAtono = atono(wcreator);
    wcreatorTeleutaioTonismeno = protoTonismeno(wcreatorAtono);
    wcreatorProtoTonismeno = teleutaioTonismeno(wcreatorAtono);

    // if(strcmp(word, "χωνεύω")==0){

    //     printf("para word = %s\n", word);
    //     printf("syllabes = %s\n", syllabes);
    //     printf("wcreator = %s\n", wcreator);
    //     printf("wcreatorAtono = %s\n", wcreatorAtono);
    //     printf("wcreatorTeleutaioTonismeno = %s\n", wcreatorTeleutaioTonismeno);
    //     printf("screator = %s\n", screator);
    //     printf("syllen = %s\n", syllen);
    //     printf("ch = %s\n", ch);
    //     printf("cm = %s\n", cm);
    //     printf("version = %d\n\n", version);

    // }

    char *fwinserter = calloc(1,255), *fsinserter; 
    strcpy(fwinserter,"");

    if(version == 0){
        
        //fwinserter = strdup(wcreator);
        //oles sulabes mia mia me tono -> xoris
        
        fwinserter = strdup(wcreatorAtono);
        strcat(fwinserter,ch); 
        strcat(fwinserter,"α"); 
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"α");
        fprintf(f2, "έ%s|%s|έ%s|0|0|0|0|0|\n",fwinserter,syllen,fsinserter);

        fwinserter = strdup(wcreatorAtono);
        strcat(fwinserter,ch);
        strcat(fwinserter,"ες"); 
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"ες");
        fprintf(f2, "έ%s|%s|έ%s|0|0|0|0|0|\n", fwinserter, syllen, fsinserter);

        fwinserter = strdup(wcreatorAtono);
        strcat(fwinserter,ch);
        strcat(fwinserter,"ε"); 
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"ε");
        fprintf(f2, "έ%s|%s|έ%s|0|0|0|0|0|\n", fwinserter, syllen, fsinserter);

        fwinserter = strdup(wcreator);
        strcat(fwinserter,ch);
        strcat(fwinserter,"αμε"); 
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"αμε");
        fprintf(f2, "%s|%s|%s|0|0|0|0|0|\n", fwinserter, syllen, fsinserter);

        fwinserter = strdup(wcreator);
        strcat(fwinserter,ch);
        strcat(fwinserter,"ατε"); 
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"ατε");
        fprintf(f2, "%s|%s|%s|0|0|0|0|0|\n", fwinserter, syllen, fsinserter);

        fwinserter = strdup(wcreatorAtono);
        strcat(fwinserter,ch);
        strcat(fwinserter,"αν");
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"αν");
        fprintf(f2, "έ%s|%s|έ%s|0|0|0|0|0|\n", fwinserter, syllen, fsinserter);

        fwinserter = strdup(wcreator);
        strcat(fwinserter,ch);
        strcat(fwinserter,"ανε");
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"ανε");
        fprintf(f2, "%s|%s|%s|0|0|0|0|0|\n", fwinserter, syllen, fsinserter);

    }else if(version == 1){ 

        //fprintf(f2, "%s|%s|%s|0|0|0|0|0|\n", word,syllen,syllabes);

        //fwinserter = strdup(wcreator);
        fwinserter = calloc(50, sizeof(char));

        if(stringToInt(syllen) <= 2) { 
            
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch);
            strcat(fwinserter,"ούσα"); 
            fwinserter = strdup(fwinserter);
            fprintf(f2, "%s|%s|%s-%sού-σα|0|0|0|0|0|\n",fwinserter,syllen,cm,ch); 
        }
        

        if(stringToInt(syllen) <= 2) { 
            strcpy(fwinserter, ch); 
        }else{
            strcpy(fwinserter, wcreatorTeleutaioTonismeno);
            strcat(fwinserter, ch); 
        }
        strcat(fwinserter,"αγα"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sα-γα|0|0|0|0|0|\n",fwinserter,syllen,cm,ch);

        if(stringToInt(syllen) <= 2) { 
            
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch);
            strcat(fwinserter,"ούσες"); 
            fwinserter = strdup(fwinserter);
            fprintf(f2, "%s|%s|%s-%sού-σες|0|0|0|0|0|\n",fwinserter,syllen,cm,ch); 
        }
        

        if(stringToInt(syllen) <= 2) { 
            strcpy(fwinserter, ch); 
        }else{
            strcpy(fwinserter, wcreatorTeleutaioTonismeno);
            strcat(fwinserter, ch); 
        }
        strcat(fwinserter,"αγες"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sα-γες|0|0|0|0|0|\n",fwinserter,syllen,cm,ch);

        if(stringToInt(syllen) <= 2) { 
            strcpy(fwinserter, ch); 
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch); 
        }
        strcat(fwinserter,"ούσε"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sούσε|0|0|0|0|0|\n",fwinserter,syllen,cm,ch);

        if(stringToInt(syllen) <= 2) { 
            strcpy(fwinserter, ch); 
        }else{
            strcpy(fwinserter, wcreatorTeleutaioTonismeno);
            strcat(fwinserter, ch); 
        }
        strcat(fwinserter,"αγε"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sα-γε|0|0|0|0|0|\n",fwinserter,syllen,cm,ch);
        
        if(stringToInt(syllen) <= 2) { 
            strcpy(fwinserter, ch); 
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch); 
        }
        strcat(fwinserter,"ούσαμε"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sού-σα-με|0|0|0|0|0|\n",fwinserter,syllen,cm,ch);

        if(stringToInt(syllen) <= 2) { 
            
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch);
            strcat(fwinserter,"άγαμε"); 
            fwinserter = strdup(fwinserter);
            fprintf(f2, "%s|%s|%s-%sά-γα-με|0|0|0|0|0|\n",fwinserter,syllen,cm,ch); 
        }

        if(stringToInt(syllen) <= 2) { 
            strcpy(fwinserter, ch); 
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch); 
        }
        strcat(fwinserter,"ούσατε"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sού-σα-τε|0|0|0|0|0|\n",fwinserter,syllen,cm,ch);

        if(stringToInt(syllen) <= 2) { 
            
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch);
            strcat(fwinserter,"άγατε"); 
            fwinserter = strdup(fwinserter);
            fprintf(f2, "%s|%s|%s-%sά-γα-τε|0|0|0|0|0|\n",fwinserter,syllen,cm,ch); 
        }

        if(stringToInt(syllen) <= 2) { 
            strcpy(fwinserter, ch); 
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch); 
        }
        strcat(fwinserter,"ούσαν"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sού-σα-ν|0|0|0|0|0|\n",fwinserter,syllen,cm,ch);

        if(stringToInt(syllen) <= 2) { 
            strcpy(fwinserter, ch); 
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch); 
        }
        strcat(fwinserter,"ούσανε"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sού-σα-νε|0|0|0|0|0|\n",fwinserter,syllen,cm,ch);

        if(stringToInt(syllen) <= 2) { 
            
        }else{
            strcpy(fwinserter, wcreatorTeleutaioTonismeno);
            strcat(fwinserter, ch);
            strcat(fwinserter,"αγαν"); 
            fwinserter = strdup(fwinserter);
            fprintf(f2, "%s|%s|%s-%sα-γαν|0|0|0|0|0|\n",fwinserter,syllen,cm,ch); 
        }

    }else if (version == 2){
        
        //fwinserter = strdup(wcreator);
        //oles sulabes mia mia me tono -> xoris
        
        fwinserter = strdup(wcreatorProtoTonismeno);
        strcat(fwinserter,ch); 
        strcat(fwinserter,"α"); 
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"α");
        fprintf(f2, "%s|%s|%s|0|0|0|0|0|\n",fwinserter,syllen,fsinserter);

        fwinserter = strdup(wcreatorProtoTonismeno);
        strcat(fwinserter,ch);
        strcat(fwinserter,"ες"); 
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"ες");
        fprintf(f2, "%s|%s|%s|0|0|0|0|0|\n", fwinserter, syllen, fsinserter);

        fwinserter = strdup(wcreatorProtoTonismeno);
        strcat(fwinserter,ch);
        strcat(fwinserter,"ε"); 
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"ε");
        fprintf(f2, "%s|%s|%s|0|0|0|0|0|\n", fwinserter, syllen, fsinserter);

        fwinserter = strdup(wcreator);
        strcat(fwinserter,ch);
        strcat(fwinserter,"αμε"); 
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"αμε");
        fprintf(f2, "%s|%s|%s|0|0|0|0|0|\n", fwinserter, syllen, fsinserter);

        fwinserter = strdup(wcreator);
        strcat(fwinserter,ch);
        strcat(fwinserter,"ατε"); 
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"ατε");
        fprintf(f2, "%s|%s|%s|0|0|0|0|0|\n", fwinserter, syllen, fsinserter);

        fwinserter = strdup(wcreatorProtoTonismeno);
        strcat(fwinserter,ch);
        strcat(fwinserter,"αν");
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"αν");
        fprintf(f2, "%s|%s|%s|0|0|0|0|0|\n", fwinserter, syllen, fsinserter);

        fwinserter = strdup(wcreator);
        strcat(fwinserter,ch);
        strcat(fwinserter,"ανε");
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"ανε");
        fprintf(f2, "%s|%s|%s|0|0|0|0|0|\n", fwinserter, syllen, fsinserter);

    }


}