#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
    
    FILE* f1 = fopen ("wordDatabaseSource/OpenOffice.txt", "r");
    if(!f1){ printf("ERROR f1"); exit(1); }

    char    *word = calloc (255, sizeof(char)) ;
    char    bufferA[255], bufferB[255];
    int is = 0, num = 0;

    while (fgets(bufferA, 255, f1)!= NULL){
        strtok(bufferA,"\n"); 
        
        FILE* f2 = fopen ("wordDatabaseSource/OpenOfficeMurtakis.txt", "r");
        if(!f2){ printf("ERROR f2"); exit(1); }

    	printf("%d%%) %s\n", (num*100)/593070, bufferA);
        while (fgets(bufferB, 255, f2)!= NULL){
            strtok(bufferB,"\n"); 
            
            if(strcmp(bufferA, bufferB) == 0){
                is = 1;
                break;
            }
            
        }

        fclose(f2);

        if(!is){

        	FILE* f3  = fopen ("wordDatabaseFinal/OpenOfficeMerge.txt", "a+");
    		if(!f3){ printf("ERROR f3 "); exit(1); }

    		printf("' -> ADDED TO DATABASE\n");
            fprintf(f3, "%s\n", bufferA);

            fclose(f3);
            

        }else{
            printf("\n");
            is = 0;
        }

        num++;
        
    }
    
    fclose(f1);
}