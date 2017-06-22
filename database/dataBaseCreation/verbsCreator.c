#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int toInt(char a[]) {
  int c, sign, offset, n;
 
  if (a[0] == '-') {  // Handle negative integers
    sign = -1;
  }else{
    sign = 0;
  }
 
  if (sign == -1) {  // Set starting position to convert
    offset = 1;
  }
  else {
    offset = 0;
  }
 
  n = 0;
 
  for (c = offset; a[c] != '\0'; c++) {
    n = n * 10 + a[c] - '0';
  }
 
  if (sign == -1) {
    n = -n;
  }
 
  return n;
}

void createXronous(FILE* f2, char *word, char* syllabes, char *wcreator, char *screator, char *syllen, char* ch, char *cm, int version){ 

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

        strcpy(fwinserter, cm);
        strcat(fwinserter, ch);
        strcat(fwinserter,"ώ"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sώ|0|0|0|0|0|\n",fwinserter,syllen,cm,ch);

        strcpy(fwinserter, cm);
        strcat(fwinserter, ch);
        strcat(fwinserter,"άς"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sάς|0|0|0|0|0|\n",fwinserter,syllen,cm,ch);

        strcpy(fwinserter, cm);
        strcat(fwinserter, ch);
        strcat(fwinserter,"ά"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sά|0|0|0|0|0|\n",fwinserter,syllen,cm,ch);

        strcpy(fwinserter, cm);
        strcat(fwinserter, ch);
        strcat(fwinserter,"άει"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sά-ει|0|0|0|0|0|\n",fwinserter,syllen,cm,ch);

        strcpy(fwinserter, cm);
        strcat(fwinserter, ch);
        strcat(fwinserter,"άμε"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sά-με|0|0|0|0|0|\n",fwinserter,syllen,cm,ch);

        strcpy(fwinserter, cm);
        strcat(fwinserter, ch);
        strcat(fwinserter,"άτε"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sά-τε|0|0|0|0|0|\n",fwinserter,syllen,cm,ch);
        
        strcpy(fwinserter, cm);
        strcat(fwinserter, ch);
        strcat(fwinserter,"άν"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sάν|0|0|0|0|0|\n",fwinserter,syllen,cm,ch);

        strcpy(fwinserter, cm);
        strcat(fwinserter, ch);
        strcat(fwinserter,"ούν"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sούν|0|0|0|0|0|\n",fwinserter,syllen,cm,ch);

        strcpy(fwinserter, cm);
        strcat(fwinserter, ch);
        strcat(fwinserter,"άνε"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sά-νε|0|0|0|0|0|\n",fwinserter,syllen,cm,ch);

        strcpy(fwinserter, cm);
        strcat(fwinserter, ch);
        strcat(fwinserter,"ούνε"); 
        fwinserter = strdup(fwinserter);
        fprintf(f2, "%s|%s|%s-%sού-νε|0|0|0|0|0|\n",fwinserter,syllen,cm,ch);

    }

}

int main(int argc, char** argv){

    FILE* f1 = fopen ("../generatedDatabases/greekRimata.txt", "r");
    if(!f1){ printf("ERROR f1"); exit(1); }

    FILE* f2 = fopen ("../generatedDatabases/greekRimataCreator.txt", "w+");
    if(!f2){ printf("ERROR f2"); exit(1); }

    char    *len, *syllen;
    char    *word, *syllabes, *syllabes2, *syllabes3 ,*syl, *sylp, *sylpp, *sylpcmplt;
    char    *wcreator, *winserter;
    char    *screator, *sinserter;
    char    buffer[255];
    
    while (fgets(buffer,255, f1)!= NULL)    { 

        len = strtok(buffer,"|");
        word = strtok(NULL, "|");
        syllen = strtok(NULL, "|");
        syllabes = strtok(NULL, "|");
        
        syllabes2 = calloc(strlen(syllabes),sizeof(char));
        strcpy(syllabes2, syllabes);

        wcreator  = calloc(1.5 * strlen(word),sizeof(char));
        screator  = calloc(1.5 * strlen(syllabes),sizeof(char));
        sylpcmplt = calloc(10 *strlen(word),sizeof(char));

        syl = strtok(syllabes2, "-");
        sylp = strdup(syl);
        sylpp = strdup(syl);

        strcpy(sylpcmplt,"");
        strcpy(wcreator, ""); 
        strcpy(screator, ""); 

        int i,exiter = toInt(syllen);
        for(i = 0; i < exiter; i++){
            
            if(i){
                strcat(wcreator,sylp); 
                strcat(screator,sylp); 
                strcat(screator,"-"); 
            }

            if( strcmp(sylpcmplt,sylpp) != 0 )
                strcat(sylpcmplt,sylpp);
            sylpp = sylp;
            sylp = syl;
            syl = strtok(NULL, "-");

        }          

        // printf("len = %s\n", len);
        // printf("word = %s\n", word);
        // printf("syllen = %s\n", syllen);
        // printf("syllabes = %s\n", syllabes);
        // printf("sylp = %s\n", sylp);
        // printf("sylpp = %s\n", sylpp);
        // printf("wcreator = %s\n", wcreator);
        // printf("screator = %s\n\n", screator);

        char *check1 = calloc(strlen(sylpp),sizeof(char));
        char *check2 = calloc(strlen(sylpp),sizeof(char));

        strcpy(check1, &sylpp[(strlen(sylpp)/2)]);
        strcpy(check2, &sylpp[(strlen(sylpp)/2)]-1);

        if(strcmp(sylp, "ω") == 0){
       
            if(strcmp(sylpp,"πά") == 0){ 
                createXronous(f2, word, syllabes, wcreator, screator, syllen, "π",  sylpcmplt, 1);
            }else if(strcmp(check1,"τά") == 0 || strcmp(check2,"τά") == 0){
                createXronous(f2, word, syllabes, wcreator, screator, syllen, "τ", sylpcmplt, 1);
            }else if(strcmp(check1,"ρά") == 0 || strcmp(check2,"ρά") == 0){
                createXronous(f2, word, syllabes, wcreator, screator, syllen, "ρ", sylpcmplt, 1);
            }else if(strcmp(check1,"ά") == 0 || strcmp(check2,"ά") == 0){
                createXronous(f2, word, syllabes, wcreator, screator, syllen, "",  sylpcmplt, 1);
            }else{
                createXronous(f2, word, syllabes, wcreator, screator, syllen, "", sylpcmplt, 0); 
            }

        }else if(strcmp(sylp, "ώ") == 0){ 

            if(strcmp(check1,"ά") == 0 || strcmp(check2,"ά") == 0){
                createXronous(f2, word, syllabes, wcreator, screator, syllen, "",  sylpcmplt, 1);
            }else if(strcmp(check1,"τά") == 0 || strcmp(check2,"τά") == 0){
                createXronous(f2, word, syllabes, wcreator, screator, syllen, "τ", sylpcmplt, 1);
            }else if(strcmp(check1,"ρά") == 0 || strcmp(check2,"ρά") == 0){
                createXronous(f2, word, syllabes, wcreator, screator, syllen, "ρ", sylpcmplt, 1);
            }else{
                createXronous(f2, word, syllabes, wcreator, screator, syllen, "", sylpcmplt, 0); 
            }

        }else if(strcmp(sylp, "βω") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "β", sylpcmplt, 0);
        }else if(strcmp(sylp, "στω") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "β", sylpcmplt, 0);
        }else if(strcmp(sylp, "στώ") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "στ", sylpcmplt, 1);
        }else if(strcmp(sylp, "βώ") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "στ", sylpcmplt, 1);
        }else if(strcmp(sylp, "γω") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "γ", sylpcmplt, 0);
        }else if(strcmp(sylp, "γώ") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "γ", sylpcmplt, 0);
        }else if(strcmp(sylp, "δω") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "δ", sylpcmplt, 0);
        }else if(strcmp(sylp, "δω") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "δ", sylpcmplt, 0);
        }else if(strcmp(sylp, "ζω") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "ζ", sylpcmplt, 0);
        }else if(strcmp(sylp, "ζώ") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "ζ", sylpcmplt, 0);
        }else if(strcmp(sylp, "θω") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "θ", sylpcmplt, 0);
        }else if(strcmp(sylp, "θώ") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "θ", sylpcmplt, 0);
        }else if(strcmp(sylp, "κω") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "κ", sylpcmplt, 0);
        }else if(strcmp(sylp, "κώ") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "κ", sylpcmplt, 0);
        }else if(strcmp(sylp, "λω") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "λ", sylpcmplt, 0);
        }else if(strcmp(sylp, "λώ") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "λ", sylpcmplt, 0);
        }else if(strcmp(sylp, "μω") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "μ", sylpcmplt, 0);
        }else if(strcmp(sylp, "μώ") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "μ", sylpcmplt, 0);
        }else if(strcmp(sylp, "νω") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "ν", sylpcmplt, 0);
        }else if(strcmp(sylp, "νώ") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "ν", sylpcmplt, 0);
        }else if(strcmp(sylp, "ξω") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "ξ", sylpcmplt, 0);
        }else if(strcmp(sylp, "ξώ") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "ξ", sylpcmplt, 0);
        }else if(strcmp(sylp, "πω") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "π", sylpcmplt, 0);
        }else if(strcmp(sylp, "πώ") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "π", sylpcmplt, 0);
        }else if(strcmp(sylp, "ρω") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "ρ", sylpcmplt, 0);
        }else if(strcmp(sylp, "ρώ") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "ρ", sylpcmplt, 0);
        }else if(strcmp(sylp, "σω") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "σ", sylpcmplt, 0);
        }else if(strcmp(sylp, "σώ") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "σ", sylpcmplt, 0);
        }else if(strcmp(sylp, "τω") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "τ", sylpcmplt, 0);
        }else if(strcmp(sylp, "τώ") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "τ", sylpcmplt, 0);
        }else if(strcmp(sylp, "φω") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "φ", sylpcmplt, 0);
        }else if(strcmp(sylp, "φώ") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "φ", sylpcmplt, 0);
        }else if(strcmp(sylp, "χω") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "χ", sylpcmplt, 0);
        }else if(strcmp(sylp, "χώ") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "χ", sylpcmplt, 0);
        }else if(strcmp(sylp, "ψω") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "ψ", sylpcmplt, 0);
        }else if(strcmp(sylp, "ψώ") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "ψ", sylpcmplt, 0);
        }else if(strcmp(sylp, "χλω") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "χλ", sylpcmplt, 0);
        }else if(strcmp(sylp, "χλώ") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "χλ", sylpcmplt, 0);
        }else if(strcmp(sylp, "στω") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "στ", sylpcmplt, 0);
        }else if(strcmp(sylp, "στώ") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "στ", sylpcmplt, 0);
        }else if(strcmp(sylp, "πρω") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "πρ", sylpcmplt, 0);
        }else if(strcmp(sylp, "πρώ") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "πρ", sylpcmplt, 0);
        }else if(strcmp(sylp, "μπω") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "μπ", sylpcmplt, 0);
        }else if(strcmp(sylp, "μπώ") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "μπ", sylpcmplt, 0);
        }else if(strcmp(sylp, "μαι") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "μ", sylpcmplt, 0);
        }else if(strcmp(sylp, "μαί") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "μ", sylpcmplt, 0);
        }else if(strcmp(sylp, "νται") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "ντ", sylpcmplt, 0);
        }else if(strcmp(sylp, "νταί") == 0){
            createXronous(f2, word, syllabes, wcreator, screator, syllen, "ντ", sylpcmplt, 0);
        }else{ 
            // printf("                                ERROR\n");
            //exit(0);
        }
        
    }

    fclose(f1);
    fclose(f2);

}