#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){

    FILE* f1 = fopen ("../greekWordDatabase.txt", "r");
    if(!f1){ printf("ERROR f1"); exit(1); }
    FILE* f2 = fopen ("../generatedDatabases/greekRimata.txt", "w+");
    if(!f2){ printf("ERROR f2"); exit(1); }
    FILE* f3 = fopen ("../generatedDatabases/greekYpoloipa.txt", "w+");
    if(!f3){ printf("ERROR f2"); exit(1); }

    char    *len, *syllen;
    char    *word, *syllabes, *syllabes2, *syllabes3 ,*syl, *sylp;
    char    buffer[255];
    
    while (fgets(buffer,255, f1)!= NULL)    { 

        len = strtok(buffer,"\t");
        word = strtok(NULL, "\t");
        syllen = strtok(NULL, "\t");
        syllabes = strtok(NULL, "\t");
        
        syllabes2 = calloc(strlen(syllabes),sizeof(char));
        strncpy(syllabes2, syllabes, strlen(syllabes)-1);

        syllabes3 = calloc(strlen(syllabes2), sizeof(char));
        syllabes3 = strdup(syllabes2);

        syl = strtok(syllabes3, "-");
        while(syl != NULL){
            sylp = syl;
            syl = strtok(NULL, "-");
        }          

        if(strcmp(sylp, "ω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ώ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "βω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "βώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χλω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χλώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πρω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πρώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μπω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μπώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μαι") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|1|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μαί") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|1|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νται") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νταί") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else{ 
            fprintf(f3, "%s|%s|%s|%s|\n", len,word,syllen,syllabes2);
        }
        
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
}