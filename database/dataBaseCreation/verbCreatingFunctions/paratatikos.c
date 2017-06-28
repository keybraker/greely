#include "xronoi.h"

void paratatikos(FILE* f2, char *word, char* syllabes, char *wcreator, char *screator, char *syllen, char* ch, char *cm, int version){ 

    // fprintf(f2, "\nPARATATIKOS\n");

    // char* wcreatorAtono = calloc(1,1024);
    // char* wcreatorTeleutaioTonismeno = calloc(1,1024);
    // char* wcreatorProtoTonismeno = calloc(1,1024);

    // wcreatorAtono = atono(wcreator);
    // wcreatorProtoTonismeno = protoTonismeno(wcreatorAtono);
    // wcreatorTeleutaioTonismeno = teleutaioTonismeno(wcreatorAtono);

    // if(strcmp(word, "χτυπάω")==0){

    //     printf("para word = %s\n", word);
    //     printf("syllabes = %s\n", syllabes);      
    //     printf("syllen = %s\n", syllen);
    //     printf("wcreator = %s\n", wcreator);
    //     printf("wcreatorAtono = %s\n", wcreatorAtono);
    //     printf("wcreatorProtoTonismeno = %s\n", wcreatorProtoTonismeno);
    //     printf("wcreatorTeleutaioTonismeno = %s\n", wcreatorTeleutaioTonismeno);
    //     printf("screator = %s\n", screator);
    //     printf("ch = %s\n", ch);
    //     printf("cm = %s\n", cm);
    //     printf("version = %d\n\n", version);

    // }

    // fprintf(f2, "-> ENERGITIKI\n");

    // char *fwinserter = calloc(1,255), *fsinserter; 
    // strcpy(fwinserter,"");

    // if(version == 0){
        
    //     //fwinserter = strdup(wcreator);
    //     //oles sulabes mia mia me tono -> xoris
        
    //     fwinserter = strdup(wcreatorTeleutaioTonismeno);
    //     strcat(fwinserter,ch); 
    //     strcat(fwinserter,"α"); 
    //     fwinserter = strdup(fwinserter);
    //     fsinserter = strdup(screator);
    //     strcat(fsinserter, ch);
    //     strcat(fsinserter,"α");
    //     fprintf(f2, "έ%s|%s|έ%s|1|0|0|0|0|\n",fwinserter,syllen,fsinserter);

    //     fwinserter = strdup(wcreatorTeleutaioTonismeno);
    //     strcat(fwinserter,ch);
    //     strcat(fwinserter,"ες"); 
    //     fwinserter = strdup(fwinserter);
    //     fsinserter = strdup(screator);
    //     strcat(fsinserter, ch);
    //     strcat(fsinserter,"ες");
    //     fprintf(f2, "έ%s|%s|έ%s|1|1|0|0|0|\n", fwinserter, syllen, fsinserter);

    //     fwinserter = strdup(wcreatorTeleutaioTonismeno);
    //     strcat(fwinserter,ch);
    //     strcat(fwinserter,"ε"); 
    //     fwinserter = strdup(fwinserter);
    //     fsinserter = strdup(screator);
    //     strcat(fsinserter, ch);
    //     strcat(fsinserter,"ε");
    //     fprintf(f2, "έ%s|%s|έ%s|1|2|0|0|0|\n", fwinserter, syllen, fsinserter);

    //     fwinserter = strdup(wcreator);
    //     strcat(fwinserter,ch);
    //     strcat(fwinserter,"αμε"); 
    //     fwinserter = strdup(fwinserter);
    //     fsinserter = strdup(screator);
    //     strcat(fsinserter, ch);
    //     strcat(fsinserter,"α-με");
    //     fprintf(f2, "%s|%s|%s|1|0|1|0|0|\n", fwinserter, syllen, fsinserter);

    //     fwinserter = strdup(wcreator);
    //     strcat(fwinserter,ch);
    //     strcat(fwinserter,"ατε"); 
    //     fwinserter = strdup(fwinserter);
    //     fsinserter = strdup(screator);
    //     strcat(fsinserter, ch);
    //     strcat(fsinserter,"α-τε");
    //     fprintf(f2, "%s|%s|%s|1|1|1|0|0|\n", fwinserter, syllen, fsinserter);

    //     fwinserter = strdup(wcreatorTeleutaioTonismeno);
    //     strcat(fwinserter,ch);
    //     strcat(fwinserter,"αν");
    //     fwinserter = strdup(fwinserter);
    //     fsinserter = strdup(screator);
    //     strcat(fsinserter, ch);
    //     strcat(fsinserter,"αν");
    //     fprintf(f2, "έ%s|%s|έ%s|1|2|1|0|0|\n", fwinserter, syllen, fsinserter);

    //     fwinserter = strdup(wcreator);
    //     strcat(fwinserter,ch);
    //     strcat(fwinserter,"ανε");
    //     fwinserter = strdup(fwinserter);
    //     fsinserter = strdup(screator);
    //     strcat(fsinserter, ch);
    //     strcat(fsinserter,"α-νε");
    //     fprintf(f2, "%s|%s|%s|1|2|1|0|0|\n", fwinserter, syllen, fsinserter);

    // }else if(version == 1){ 

    //     //fprintf(f2, "%s|%s|%s|0|0|0|0|0|\n", word,syllen,syllabes);

    //     //fwinserter = strdup(wcreator);
    //     fwinserter = calloc(50, sizeof(char));

    //     if(stringToInt(syllen) <= 2) { 
            
    //     }else{
    //         strcpy(fwinserter, cm);
    //         strcat(fwinserter, ch);
    //         strcat(fwinserter,"ούσα"); 
    //         fwinserter = strdup(fwinserter);
    //         fprintf(f2, "%s|%s|%s-%sού-σα|1|0|0|0|0|\n",fwinserter,syllen,cm,ch); 
    //     }
        

    //     if(stringToInt(syllen) <= 2) { 
    //         strcpy(fwinserter, ch); 
    //     }else{
    //         strcpy(fwinserter, wcreatorTeleutaioTonismeno);
    //         strcat(fwinserter, ch); 
    //     }
    //     strcat(fwinserter,"αγα"); 
    //     fwinserter = strdup(fwinserter);
    //     fprintf(f2, "%s|%s|%s-%sα-γα|1|0|0|0|0|\n",fwinserter,syllen,cm,ch);

    //     if(stringToInt(syllen) <= 2) { 
            
    //     }else{
    //         strcpy(fwinserter, cm);
    //         strcat(fwinserter, ch);
    //         strcat(fwinserter,"ούσες"); 
    //         fwinserter = strdup(fwinserter);
    //         fprintf(f2, "%s|%s|%s-%sού-σες|1|1|0|0|0|\n",fwinserter,syllen,cm,ch); 
    //     }
        

    //     if(stringToInt(syllen) <= 2) { 
    //         strcpy(fwinserter, ch); 
    //     }else{
    //         strcpy(fwinserter, wcreatorTeleutaioTonismeno);
    //         strcat(fwinserter, ch); 
    //     }
    //     strcat(fwinserter,"αγες"); 
    //     fwinserter = strdup(fwinserter);
    //     fprintf(f2, "%s|%s|%s-%sα-γες|1|1|0|0|0|\n",fwinserter,syllen,cm,ch);

    //     if(stringToInt(syllen) <= 2) { 
    //         strcpy(fwinserter, ch); 
    //     }else{
    //         strcpy(fwinserter, cm);
    //         strcat(fwinserter, ch); 
    //     }
    //     strcat(fwinserter,"ούσε"); 
    //     fwinserter = strdup(fwinserter);
    //     fprintf(f2, "%s|%s|%s-%sού-σε|1|2|0|0|0|\n",fwinserter,syllen,cm,ch);

    //     if(stringToInt(syllen) <= 2) { 
    //         strcpy(fwinserter, ch); 
    //     }else{
    //         strcpy(fwinserter, wcreatorTeleutaioTonismeno);
    //         strcat(fwinserter, ch); 
    //     }
    //     strcat(fwinserter,"αγε"); 
    //     fwinserter = strdup(fwinserter);
    //     fprintf(f2, "%s|%s|%s-%sα-γε|1|2|0|0|0|\n",fwinserter,syllen,cm,ch);
        
    //     if(stringToInt(syllen) <= 2) { 
    //         strcpy(fwinserter, ch); 
    //     }else{
    //         strcpy(fwinserter, cm);
    //         strcat(fwinserter, ch); 
    //     }
    //     strcat(fwinserter,"ούσαμε"); 
    //     fwinserter = strdup(fwinserter);
    //     fprintf(f2, "%s|%s|%s-%sού-σα-με|1|0|1|0|0|\n",fwinserter,syllen,cm,ch);

    //     if(stringToInt(syllen) <= 2) { 
            
    //     }else{
    //         strcpy(fwinserter, cm);
    //         strcat(fwinserter, ch);
    //         strcat(fwinserter,"άγαμε"); 
    //         fwinserter = strdup(fwinserter);
    //         fprintf(f2, "%s|%s|%s-%sά-γα-με|1|0|1|0|0|\n",fwinserter,syllen,cm,ch); 
    //     }

    //     if(stringToInt(syllen) <= 2) { 
    //         strcpy(fwinserter, ch); 
    //     }else{
    //         strcpy(fwinserter, cm);
    //         strcat(fwinserter, ch); 
    //     }
    //     strcat(fwinserter,"ούσατε"); 
    //     fwinserter = strdup(fwinserter);
    //     fprintf(f2, "%s|%s|%s-%sού-σα-τε|1|1|1|0|0|\n",fwinserter,syllen,cm,ch);

    //     if(stringToInt(syllen) <= 2) { 
            
    //     }else{
    //         strcpy(fwinserter, cm);
    //         strcat(fwinserter, ch);
    //         strcat(fwinserter,"άγατε"); 
    //         fwinserter = strdup(fwinserter);
    //         fprintf(f2, "%s|%s|%s-%sά-γα-τε|1|1|1|0|0|\n",fwinserter,syllen,cm,ch); 
    //     }

    //     if(stringToInt(syllen) <= 2) { 
    //         strcpy(fwinserter, ch); 
    //     }else{
    //         strcpy(fwinserter, cm);
    //         strcat(fwinserter, ch); 
    //     }
    //     strcat(fwinserter,"ούσαν"); 
    //     fwinserter = strdup(fwinserter);
    //     fprintf(f2, "%s|%s|%s-%sού-σα-ν|1|2|1|0|0|\n",fwinserter,syllen,cm,ch);

    //     if(stringToInt(syllen) <= 2) { 
    //         strcpy(fwinserter, ch); 
    //     }else{
    //         strcpy(fwinserter, cm);
    //         strcat(fwinserter, ch); 
    //     }
    //     strcat(fwinserter,"ούσανε"); 
    //     fwinserter = strdup(fwinserter);
    //     fprintf(f2, "%s|%s|%s-%sού-σα-νε|1|2|1|0|0|\n",fwinserter,syllen,cm,ch);

    //     if(stringToInt(syllen) <= 2) { 
            
    //     }else{
    //         strcpy(fwinserter, wcreatorTeleutaioTonismeno);
    //         strcat(fwinserter, ch);
    //         strcat(fwinserter,"αγαν"); 
    //         fwinserter = strdup(fwinserter);
    //         fprintf(f2, "%s|%s|%s-%sα-γαν|1|2|1|0|0|\n",fwinserter,syllen,cm,ch); 
    //     }

    // }else if (version == 2){
        
    //     //fwinserter = strdup(wcreator);
    //     //oles sulabes mia mia me tono -> xoris

    //     fwinserter = strdup(wcreatorProtoTonismeno);
    //     strcat(fwinserter,ch); 
    //     strcat(fwinserter,"α"); 
    //     fwinserter = strdup(fwinserter);
    //     fsinserter = strdup(screator);
    //     strcat(fsinserter, ch);
    //     strcat(fsinserter,"α");
    //     fprintf(f2, "%s|%s|%s|1|0|0|0|0|\n",fwinserter,syllen,fsinserter);

    //     fwinserter = strdup(wcreatorProtoTonismeno);
    //     strcat(fwinserter,ch);
    //     strcat(fwinserter,"ες"); 
    //     fwinserter = strdup(fwinserter);
    //     fsinserter = strdup(screator);
    //     strcat(fsinserter, ch);
    //     strcat(fsinserter,"ες");
    //     fprintf(f2, "%s|%s|%s|1|1|0|0|0|\n", fwinserter, syllen, fsinserter);

    //     fwinserter = strdup(wcreatorProtoTonismeno);
    //     strcat(fwinserter,ch);
    //     strcat(fwinserter,"ε"); 
    //     fwinserter = strdup(fwinserter);
    //     fsinserter = strdup(screator);
    //     strcat(fsinserter, ch);
    //     strcat(fsinserter,"ε");
    //     fprintf(f2, "%s|%s|%s|1|2|0|0|0|\n", fwinserter, syllen, fsinserter);

    //     fwinserter = strdup(wcreator);
    //     strcat(fwinserter,ch);
    //     strcat(fwinserter,"αμε"); 
    //     fwinserter = strdup(fwinserter);
    //     fsinserter = strdup(screator);
    //     strcat(fsinserter, ch);
    //     strcat(fsinserter,"α-με");
    //     fprintf(f2, "%s|%s|%s|1|0|1|0|0|\n", fwinserter, syllen, fsinserter);

    //     fwinserter = strdup(wcreator);
    //     strcat(fwinserter,ch);
    //     strcat(fwinserter,"ατε"); 
    //     fwinserter = strdup(fwinserter);
    //     fsinserter = strdup(screator);
    //     strcat(fsinserter, ch);
    //     strcat(fsinserter,"α-τε");
    //     fprintf(f2, "%s|%s|%s|1|1|1|0|0|\n", fwinserter, syllen, fsinserter);

    //     fwinserter = strdup(wcreatorProtoTonismeno);
    //     strcat(fwinserter,ch);
    //     strcat(fwinserter,"αν");
    //     fwinserter = strdup(fwinserter);
    //     fsinserter = strdup(screator);
    //     strcat(fsinserter, ch);
    //     strcat(fsinserter,"αν");
    //     fprintf(f2, "%s|%s|%s|1|2|1|0|0|\n", fwinserter, syllen, fsinserter);

    //     fwinserter = strdup(wcreator);
    //     strcat(fwinserter,ch);
    //     strcat(fwinserter,"ανε");
    //     fwinserter = strdup(fwinserter);
    //     fsinserter = strdup(screator);
    //     strcat(fsinserter, ch);
    //     strcat(fsinserter,"α-νε");
    //     fprintf(f2, "%s|%s|%s|1|2|1|0|0|\n", fwinserter, syllen, fsinserter);

    // }















    // fprintf(f2, "-> PATHITIKI\n");
    // strcpy(fwinserter,"");
        
    // //fwinserter = strdup(wcreator);
    // //oles sulabes mia mia me tono -> xoris
    
    // fwinserter = strdup(cm);
    // strcat(fwinserter,ch); 
    // strcat(fwinserter,"ιόμουνα"); 
    // fwinserter = strdup(fwinserter);
    // fsinserter = strdup(screator);
    // strcat(fsinserter, ch);
    // strcat(fsinserter,"ιό-μου-να");
    // fprintf(f2, "%s|%s|%s|1|0|0|0|0|\n",fwinserter,syllen,fsinserter);

    // fwinserter = strdup(cm);
    // strcat(fwinserter,ch); 
    // strcat(fwinserter,"ιόμουν"); 
    // fwinserter = strdup(fwinserter);
    // fsinserter = strdup(screator);
    // strcat(fsinserter, ch);
    // strcat(fsinserter,"ιό-μουν");
    // fprintf(f2, "%s|%s|%s|1|0|0|0|0|\n",fwinserter,syllen,fsinserter);

    // fwinserter = strdup(cm);
    // strcat(fwinserter,ch);
    // strcat(fwinserter,"ιόσουνα"); 
    // fwinserter = strdup(fwinserter);
    // fsinserter = strdup(screator);
    // strcat(fsinserter, ch);
    // strcat(fsinserter,"ιό-σου-να");
    // fprintf(f2, "%s|%s|%s|1|1|0|0|0|\n", fwinserter, syllen, fsinserter);

    // fwinserter = strdup(cm);
    // strcat(fwinserter,ch);
    // strcat(fwinserter,"ιόσουν"); 
    // fwinserter = strdup(fwinserter);
    // fsinserter = strdup(screator);
    // strcat(fsinserter, ch);
    // strcat(fsinserter,"ιό-σουν");
    // fprintf(f2, "%s|%s|%s|1|1|0|0|0|\n", fwinserter, syllen, fsinserter);

    // fwinserter = strdup(cm);
    // strcat(fwinserter,ch);
    // strcat(fwinserter,"ιόταν"); 
    // fwinserter = strdup(fwinserter);
    // fsinserter = strdup(screator);
    // strcat(fsinserter, ch);
    // strcat(fsinserter,"ιό-ταν");
    // fprintf(f2, "%s|%s|%s|1|2|0|0|0|\n", fwinserter, syllen, fsinserter);

    // fwinserter = strdup(cm);
    // strcat(fwinserter,ch);
    // strcat(fwinserter,"ιότανε"); 
    // fwinserter = strdup(fwinserter);
    // fsinserter = strdup(screator);
    // strcat(fsinserter, ch);
    // strcat(fsinserter,"ιό-τα-νε");
    // fprintf(f2, "%s|%s|%s|1|2|0|0|0|\n", fwinserter, syllen, fsinserter);

    // fwinserter = strdup(cm);
    // strcat(fwinserter,ch);
    // strcat(fwinserter,"ιόμασταν"); 
    // fwinserter = strdup(fwinserter);
    // fsinserter = strdup(screator);
    // strcat(fsinserter, ch);
    // strcat(fsinserter,"ιό-μα-σταν");
    // fprintf(f2, "%s|%s|%s|1|0|1|0|0|\n", fwinserter, syllen, fsinserter);

    // fwinserter = strdup(cm);
    // strcat(fwinserter,ch);
    // strcat(fwinserter,"ιόμαστε"); 
    // fwinserter = strdup(fwinserter);
    // fsinserter = strdup(screator);
    // strcat(fsinserter, ch);
    // strcat(fsinserter,"ιό-μα-στε");
    // fprintf(f2, "%s|%s|%s|1|0|1|0|0|\n", fwinserter, syllen, fsinserter);

    // fwinserter = strdup(cm);
    // strcat(fwinserter,ch);
    // strcat(fwinserter,"ιόσασταν"); 
    // fwinserter = strdup(fwinserter);
    // fsinserter = strdup(screator);
    // strcat(fsinserter, ch);
    // strcat(fsinserter,"ιό-σα-σταν");
    // fprintf(f2, "%s|%s|%s|1|1|1|0|0|\n", fwinserter, syllen, fsinserter);

    // fwinserter = strdup(cm);
    // strcat(fwinserter,ch);
    // strcat(fwinserter,"ιόσαστε"); 
    // fwinserter = strdup(fwinserter);
    // fsinserter = strdup(screator);
    // strcat(fsinserter, ch);
    // strcat(fsinserter,"ιό-σα-στε");
    // fprintf(f2, "%s|%s|%s|1|1|1|0|0|\n", fwinserter, syllen, fsinserter);

    // fwinserter = strdup(cm);
    // strcat(fwinserter,ch);
    // strcat(fwinserter,"ιόνταν");
    // fwinserter = strdup(fwinserter);
    // fsinserter = strdup(screator);
    // strcat(fsinserter, ch);
    // strcat(fsinserter,"ιό-νταν");
    // fprintf(f2, "%s|%s|%s|1|2|1|0|0|\n", fwinserter, syllen, fsinserter);

    // fwinserter = strdup(cm);
    // strcat(fwinserter,ch);
    // strcat(fwinserter,"ιόντουσαν");
    // fwinserter = strdup(fwinserter);
    // fsinserter = strdup(screator);
    // strcat(fsinserter, ch);
    // strcat(fsinserter,"ιό-ντου-σα-ν");
    // fprintf(f2, "%s|%s|%s|1|2|1|0|0|\n", fwinserter, syllen, fsinserter);

    

}