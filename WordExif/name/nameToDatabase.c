#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){

    FILE* f1 = fopen ("nameDatabaseSource/arsenika.txt", "r");
    if(!f1){ printf("ERROR f1"); exit(1); }
    
    FILE* f2 = fopen ("nameDatabaseSource/gunaikia.txt", "r");
    if(!f2){ printf("ERROR f2"); exit(1); }

    FILE* f3  = fopen ("nameDatabaseFinal/nameGr.txt", "w+");
    if(!f3){ printf("ERROR f3 "); exit(1); }

    char    *word = calloc (255, sizeof(char)) ;
    char    buffer[255];
    
    // 0 for men
    // 1 for women
    while (fgets(buffer,255, f1)!= NULL){
        strtok(buffer,"\n"); 
        fprintf(f3, "%s|0|\n", buffer);
        
    }
     while (fgets(buffer,255, f2)!= NULL){
        strtok(buffer,"\n"); 
        fprintf(f3, "%s|1|\n", buffer);
        
    }
    
    fclose(f1);
    fclose(f2);
    fclose(f3);
}