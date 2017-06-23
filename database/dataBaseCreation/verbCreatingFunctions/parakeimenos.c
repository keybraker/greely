#include "parakeimenos.h"

void parakeimenos(FILE* f2, char *word, char* syllabes, char *wcreator, char *screator, char *syllen, char* ch, char *cm, int version){ 

    char *fwinserter, *fsinserter; 

    if(version == 0){
        fprintf(f2, "%s|%s|%s|0|0|0|0|0|\n", word,syllen,syllabes);

        fwinserter = strdup(wcreator);
        strcat(fwinserter,ch); 
        strcat(fwinserter,"εις"); 
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"εις");
        fprintf(f2, "%s|%s|%s|0|0|0|0|0|\n",fwinserter,syllen,fsinserter);

        fwinserter = strdup(wcreator);
        strcat(fwinserter,ch);
        strcat(fwinserter,"ει"); 
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"ει");
        fprintf(f2, "%s|%s|%s|0|0|0|0|0|\n", fwinserter, syllen, fsinserter);

        fwinserter = strdup(wcreator);
        strcat(fwinserter,ch);
        strcat(fwinserter,"ουμε"); 
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"ουμε");
        fprintf(f2, "%s|%s|%s|0|0|0|0|0|\n", fwinserter, syllen, fsinserter);

        fwinserter = strdup(wcreator);
        strcat(fwinserter,ch);
        strcat(fwinserter,"ετε"); 
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"ετε");
        fprintf(f2, "%s|%s|%s|0|0|0|0|0|\n", fwinserter, syllen, fsinserter);

        fwinserter = strdup(wcreator);
        strcat(fwinserter,ch);
        strcat(fwinserter,"ουν"); 
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"ουν");
        fprintf(f2, "%s|%s|%s|0|0|0|0|0|\n", fwinserter, syllen, fsinserter);

        fwinserter = strdup(wcreator);
        strcat(fwinserter,ch);
        strcat(fwinserter,"ουνε");
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"ουνε");
        fprintf(f2, "%s|%s|%s|0|0|0|0|0|\n", fwinserter, syllen, fsinserter);

    }else if(version == 1){ 

        fprintf(f2, "%s|%s|%s|0|0|0|0|0|\n", word,syllen,syllabes);

        //fwinserter = strdup(wcreator);
        fwinserter = calloc(50, sizeof(char));

        if(stringToInt(syllen) <= 2) { 
            
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch);
            strcat(fwinserter,"ώ"); 
            fwinserter = strdup(fwinserter);
            fprintf(f2, "%s|%s|%s-%sώ|0|0|0|0|0|\n",fwinserter,syllen,cm,ch); 
        }
        

        if(stringToInt(syllen) <= 2) { 
            strcpy(fwinserter, ch); 
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch); 
        }
        strcat(fwinserter,"άς"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sάς|0|0|0|0|0|\n",fwinserter,syllen,cm,ch);

        if(stringToInt(syllen) <= 2) { 
            
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch);
            strcat(fwinserter,"ά"); 
            fwinserter = strdup(fwinserter);
            fprintf(f2, "%s|%s|%s-%sά|0|0|0|0|0|\n",fwinserter,syllen,cm,ch); 
        }
        

        if(stringToInt(syllen) <= 2) { 
            strcpy(fwinserter, ch); 
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch); 
        }
        strcat(fwinserter,"άει"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sά-ει|0|0|0|0|0|\n",fwinserter,syllen,cm,ch);

        if(stringToInt(syllen) <= 2) { 
            strcpy(fwinserter, ch); 
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch); 
        }
        strcat(fwinserter,"άμε"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sά-με|0|0|0|0|0|\n",fwinserter,syllen,cm,ch);

        if(stringToInt(syllen) <= 2) { 
            strcpy(fwinserter, ch); 
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch); 
        }
        strcat(fwinserter,"άτε"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sά-τε|0|0|0|0|0|\n",fwinserter,syllen,cm,ch);
        
        if(stringToInt(syllen) <= 2) { 
            strcpy(fwinserter, ch); 
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch); 
        }
        strcat(fwinserter,"άν"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sάν|0|0|0|0|0|\n",fwinserter,syllen,cm,ch);

        if(stringToInt(syllen) <= 2) { 
            
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch);
            strcat(fwinserter,"ούν"); 
            fwinserter = strdup(fwinserter);
            fprintf(f2, "%s|%s|%s-%sούν|0|0|0|0|0|\n",fwinserter,syllen,cm,ch); 
        }
        
        if(stringToInt(syllen) <= 2) { 
            strcpy(fwinserter, ch); 
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch); 
        }
        strcat(fwinserter,"άνε"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sά-νε|0|0|0|0|0|\n",fwinserter,syllen,cm,ch);

        if(stringToInt(syllen) <= 2) { 

        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch);
            strcat(fwinserter,"ούνε"); 
            fwinserter = strdup(fwinserter);
            fprintf(f2, "%s|%s|%s-%sού-νε|0|0|0|0|0|\n",fwinserter,syllen,cm,ch); 
        }
        
    }

}