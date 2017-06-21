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


//roi kanones gia ta prothemata menontai na ulopoihthoun
int main(int argc, char** argv){

    if(argc != 2){
        printf("too few arguments\n");
        exit(0);
    }

    FILE* f1 = fopen ("../generatedDatabases/greekRimata.txt", "r");
    if(!f1){ printf("ERROR f1"); exit(1); }

    char    *len, *syllen;
    char    *word, *syllabes, *syllabes2;
    char    *syllabes3 ,*syl, *sylp;
    char    *wcreator, *winserter;
    char    *screator, *sinserter;
    char    buffer[255];
    char    **wholeFile;
    
    int jk = 0;
    wholeFile = calloc(255/*strlen(buffer)+1*/, sizeof(char*));
    while (fgets(buffer,255, f1)!= NULL)    { 
        // oti nanai prosoxi sti calloc kai realloc
        wholeFile = realloc(wholeFile, 255*10/*strlen(buffer)+1*/* sizeof(char*));
        if(wholeFile[jk] == NULL){
            wholeFile[jk] = calloc(2*255/*strlen(buffer)+1*/, sizeof(char));
            strcpy(wholeFile[jk], buffer);
        }
        jk++;

    }

    jk--;
    int reader = jk;

    while (reader > 0)    { 

        strcpy(buffer,wholeFile[reader]);

        len         = strtok(buffer,    "|");
        word        = strtok(NULL,      "|");
        syllen      = strtok(NULL,      "|");
        syllabes    = strtok(NULL,      "|");
        
        syllabes2 = calloc(strlen(syllabes),sizeof(char));
        strcpy(syllabes2, syllabes);

        wcreator = calloc(1.5 * strlen(word),sizeof(char));
        screator = calloc(1.5 * strlen(syllabes),sizeof(char));

        syl = strtok(syllabes2, "-");
        sylp = strdup(syl);
        strcpy(wcreator, ""); 
        strcpy(screator, ""); 

        int i,exiter = toInt(syllen);
        for(i = 0; i < exiter; i++){
            
            if(i){
                strcat(wcreator,sylp); 
                strcat(screator,sylp); 
                strcat(screator,"-"); 
            }

            sylp = syl;
            syl = strtok(NULL, "-");

        }          

        if(strcmp(wcreator, "") == 0)   
            wcreator = strdup(word);

        // printf("len = %s\n", len);
        // printf("word = %s\n", word);
        // printf("syllen = %s\n", syllen);
        // printf("syllabes = %s\n", syllabes);
        // printf("sylp = %s\n", sylp);
        // printf("wcreator = %s\n", wcreator);
        // printf("screator = %s\n\n", screator);

        // if(strcmp(wcreator, "παί") == 0 && strcmp(argc, "έπαίξα") == 0 )
        //     printf("%s == %s\n", );

        if( strstr(argv[1], wcreator) != NULL ){

            printf("Core of \"%s\" is \"%s\"\n",argv[1], wcreator);
            return 1;

        }   
            
        reader--;

    }

    fclose(f1);

    printf("No core for word \"%s\" was found in Database.\n", argv[1]);
    return 0;

}