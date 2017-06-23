#include "enestotas.h"

void enestotas(FILE* f2, char *word, char* syllabes, char *wcreator, char *screator, char *syllen, char* ch, char *cm, int version){ 

    char *fwinserter, *fsinserter; 

    //energitiki foni

    if(version == 0){

        // oristiki/upotaktiki klisi
        
        fprintf(f2, "%s|%s|%s|0|0|0|3|0|\n", word,syllen,syllabes);

        fwinserter = strdup(wcreator);
        strcat(fwinserter,ch); 
        strcat(fwinserter,"εις"); 
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"εις");
        fprintf(f2, "%s|%s|%s|0|1|0|3|0|\n",fwinserter,syllen,fsinserter);

        fwinserter = strdup(wcreator);
        strcat(fwinserter,ch);
        strcat(fwinserter,"ει"); 
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"ει");
        fprintf(f2, "%s|%s|%s|0|2|0|3|0|\n", fwinserter, syllen, fsinserter);

        fwinserter = strdup(wcreator);
        strcat(fwinserter,ch);
        strcat(fwinserter,"ουμε"); 
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"ου-με");
        fprintf(f2, "%s|%s|%s|0|0|1|3|0|\n", fwinserter, syllen, fsinserter);

        fwinserter = strdup(wcreator);
        strcat(fwinserter,ch);
        strcat(fwinserter,"ετε"); 
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"ε-τε");
        fprintf(f2, "%s|%s|%s|0|1|1|3|0|\n", fwinserter, syllen, fsinserter);

        fwinserter = strdup(wcreator);
        strcat(fwinserter,ch);
        strcat(fwinserter,"ουν"); 
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"ουν");
        fprintf(f2, "%s|%s|%s|0|2|1|3|0|\n", fwinserter, syllen, fsinserter);

        fwinserter = strdup(wcreator);
        strcat(fwinserter,ch);
        strcat(fwinserter,"ουνε");
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"ου-νε");
        fprintf(f2, "%s|%s|%s|0|2|1|3|0|\n", fwinserter, syllen, fsinserter);

        // gia na einai ena rima stin upotaktiki klisi 8a prepei 
        // na ginetai panta check oti to lookbehind tou itan να, οταν, κτλ.

        // prostaktiki

        fwinserter = strdup(wcreator);
        strcat(fwinserter,ch); 
        strcat(fwinserter,"ε"); 
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"ε");
        fprintf(f2, "%s|%s|%s|0|1|0|2|0|\n",fwinserter,syllen,fsinserter);

        fwinserter = strdup(wcreator);
        strcat(fwinserter,ch);
        strcat(fwinserter,"ετε"); 
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"ε-τε");
        fprintf(f2, "%s|%s|%s|0|1|1|2|0|\n", fwinserter, syllen, fsinserter);


    }else if(version == 1){ 

        // oristiki klisi

        fprintf(f2, "%s|%s|%s|0|0|0|3|0|\n", word,syllen,syllabes);

        fwinserter = calloc(50, sizeof(char));

        if(stringToInt(syllen) <= 2) { 
            
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch);
            strcat(fwinserter,"ώ"); 
            fwinserter = strdup(fwinserter);
            fprintf(f2, "%s|%s|%s-%sώ|0|0|0|3|0|\n",fwinserter,syllen,cm,ch); 
        }
        

        if(stringToInt(syllen) <= 2) { 
            strcpy(fwinserter, ch); 
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch); 
        }
        strcat(fwinserter,"άς"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sάς|0|1|0|3|0|\n",fwinserter,syllen,cm,ch);

        if(stringToInt(syllen) <= 2) { 
            
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch);
            strcat(fwinserter,"ά"); 
            fwinserter = strdup(fwinserter);
            fprintf(f2, "%s|%s|%s-%sά|0|2|0|3|0|\n",fwinserter,syllen,cm,ch); 
        }
        

        if(stringToInt(syllen) <= 2) { 
            strcpy(fwinserter, ch); 
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch); 
        }
        strcat(fwinserter,"άει"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sά-ει|0|2|0|3|0|\n",fwinserter,syllen,cm,ch);

        if(stringToInt(syllen) <= 2) { 
            strcpy(fwinserter, ch); 
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch); 
        }
        strcat(fwinserter,"άμε"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sά-με|0|0|1|3|0|\n",fwinserter,syllen,cm,ch);

        if(stringToInt(syllen) <= 2) { 
            strcpy(fwinserter, ch); 
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch); 
        }
        strcat(fwinserter,"άτε"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sά-τε|0|1|1|3|0|\n",fwinserter,syllen,cm,ch);
        
        if(stringToInt(syllen) <= 2) { 
            strcpy(fwinserter, ch); 
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch); 
        }
        strcat(fwinserter,"άν"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sάν|0|2|1|3|0|\n",fwinserter,syllen,cm,ch);

        if(stringToInt(syllen) <= 2) { 
            
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch);
            strcat(fwinserter,"ούν"); 
            fwinserter = strdup(fwinserter);
            fprintf(f2, "%s|%s|%s-%sούν|0|2|1|3|0|\n",fwinserter,syllen,cm,ch); 
        }
        
        if(stringToInt(syllen) <= 2) { 
            strcpy(fwinserter, ch); 
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch); 
        }
        strcat(fwinserter,"άνε"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sά-νε|0|2|1|3|0|\n",fwinserter,syllen,cm,ch);

        if(stringToInt(syllen) <= 2) { 

        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch);
            strcat(fwinserter,"ούνε"); 
            fwinserter = strdup(fwinserter);
            fprintf(f2, "%s|%s|%s-%sού-νε|0|2|1|3|0|\n",fwinserter,syllen,cm,ch); 
        }
        
    }

    //pathitiki foni

    if(version == 0){

        // oristiki/upotaktiki klisi
        
        fwinserter = strdup(wcreator);
        strcat(fwinserter,ch); 
        strcat(fwinserter,"ομαι"); 
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"ο-μαι");
        fprintf(f2, "%s|%s|%s|0|1|0|3|1|\n",fwinserter,syllen,fsinserter);

        fwinserter = strdup(wcreator);
        strcat(fwinserter,ch); 
        strcat(fwinserter,"εσαι"); 
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"ε-σαι");
        fprintf(f2, "%s|%s|%s|0|1|0|3|1|\n",fwinserter,syllen,fsinserter);

        fwinserter = strdup(wcreator);
        strcat(fwinserter,ch);
        strcat(fwinserter,"εται"); 
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"ε-ται");
        fprintf(f2, "%s|%s|%s|0|2|0|3|1|\n", fwinserter, syllen, fsinserter);

        fwinserter = strdup(wcreator);
        strcat(fwinserter,ch);
        strcat(fwinserter,"όμαστε"); // fix τονος
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"ό-μα-στε");
        fprintf(f2, "%s|%s|%s|0|0|1|3|1|\n", fwinserter, syllen, fsinserter);

        fwinserter = strdup(wcreator);
        strcat(fwinserter,ch);
        strcat(fwinserter,"εστε"); 
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"ε-στε");
        fprintf(f2, "%s|%s|%s|0|1|1|3|1|\n", fwinserter, syllen, fsinserter);

        fwinserter = strdup(wcreator);
        strcat(fwinserter,ch);
        strcat(fwinserter,"όσαστε");//τονος 
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"ό-σα-στε");
        fprintf(f2, "%s|%s|%s|0|2|1|3|1|\n", fwinserter, syllen, fsinserter);

        fwinserter = strdup(wcreator);
        strcat(fwinserter,ch);
        strcat(fwinserter,"ονται");
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"ο-νται");
        fprintf(f2, "%s|%s|%s|0|2|1|3|1|\n", fwinserter, syllen, fsinserter);

        // gia na einai ena rima stin upotaktiki klisi 8a prepei 
        // na ginetai panta check oti to lookbehind tou itan να, οταν, κτλ.

        // prostaktiki

        fwinserter = strdup(wcreator);
        strcat(fwinserter,ch); 
        strcat(fwinserter,"ου"); 
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"ου");
        fprintf(f2, "%s|%s|%s|0|1|0|2|1|\n",fwinserter,syllen,fsinserter);

        fwinserter = strdup(wcreator);// φιξ με απο πανω ιδιο
        strcat(fwinserter,ch);
        strcat(fwinserter,"εστε"); 
        fwinserter = strdup(fwinserter);
        fsinserter = strdup(screator);
        strcat(fsinserter, ch);
        strcat(fsinserter,"ε-στε");
        fprintf(f2, "%s|%s|%s|0|1|1|2|1|\n", fwinserter, syllen, fsinserter);


    }else if(version == 1){ 

        // oristiki klisi

        fwinserter = calloc(50, sizeof(char));

        if(stringToInt(syllen) <= 2) { 
            
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch);
            strcat(fwinserter,"ιέμαι"); 
            fwinserter = strdup(fwinserter);
            fprintf(f2, "%s|%s|%s-%sιέ-μαι|0|0|0|3|1|\n",fwinserter,syllen,cm,ch); 
        }
        

        if(stringToInt(syllen) <= 2) { 
            strcpy(fwinserter, ch); 
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch); 
        }
        strcat(fwinserter,"ιέσαι"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sιέ-σαι|0|1|0|3|1|\n",fwinserter,syllen,cm,ch);

        if(stringToInt(syllen) <= 2) { 
            
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch);
            strcat(fwinserter,"ιέται"); 
            fwinserter = strdup(fwinserter);
            fprintf(f2, "%s|%s|%s-%sιέ-ται|0|2|0|3|1|\n",fwinserter,syllen,cm,ch); 
        }
        

        if(stringToInt(syllen) <= 2) { 
            strcpy(fwinserter, ch); 
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch); 
        }
        strcat(fwinserter,"ιόμαστε"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sιό-μα-στε|0|2|0|3|1|\n",fwinserter,syllen,cm,ch);

        if(stringToInt(syllen) <= 2) { 
            strcpy(fwinserter, ch); 
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch); 
        }
        strcat(fwinserter,"ιέσται"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sιέ-σται|0|0|1|3|1|\n",fwinserter,syllen,cm,ch);

        if(stringToInt(syllen) <= 2) { 
            strcpy(fwinserter, ch); 
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch); 
        }
        strcat(fwinserter,"ιούνται"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sιού-νται|0|1|1|3|1|\n",fwinserter,syllen,cm,ch);
        
        if(stringToInt(syllen) <= 2) { 
            strcpy(fwinserter, ch); 
        }else{
            strcpy(fwinserter, cm);
            strcat(fwinserter, ch); 
        }
       
        
    }
}