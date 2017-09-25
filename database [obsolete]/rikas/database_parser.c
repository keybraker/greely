#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct database_struct{
    char* word;
    int length;
    float lemmafreq;
    float wordfreq;
    float zipfreq;
    char* syllabes;
    int syll_length;
};
typedef struct database_struct database_struct;

int get_line_size(FILE *f){
    char buffer[255];
    int i = 0;
    int c;
    while (fgets(buffer,255, f)!=NULL)    {
        i++;
    }
    rewind(f);

    return i;
}


int main(int argc, char** argv){
    FILE* f;
    if(argc != 2){
        printf("Not enough arguments\n");
        exit(1);
    }
    f = fopen (argv[1], "r");
    if(!f){
        printf("ERROR");
        exit(1);
    }
    FILE *output, *names, *names_db;
    int i, line_size, size, syll_length;
    char* word, *syllabes;
    float lemmafreq, zipfreq, wordfreq;
 
 
    output = fopen("database.txt", "w+");
    fprintf(output, "Word\tLength\tSyllabes\tSyllLength\n");
    line_size = get_line_size(f);
    word = calloc(1, 50);
    syllabes = calloc(1, 50);
    database_struct** db = calloc(line_size, sizeof(database_struct));
    for(i = 0;i < line_size; i++){

        // database_struct* new = calloc(1, sizeof(database_struct));
        // new->word = 

        fscanf(f, "%s %d %f %f %f %s %d", word, &size, &lemmafreq, &wordfreq, &zipfreq, syllabes, &syll_length);
        
        fprintf(output, "%s\t%d\t%s\t%d\n", word, size, syllabes, syll_length);
    }
    fclose(f);
    fclose(output);
    

    names = fopen("greekNames.txt", "r+");
    names_db = fopen("greekNames_db.txt", "w+");
    line_size = get_line_size(names);
    for(i = 0;i < line_size; i++){


        fscanf(names, "%s", word);
        fprintf(names_db, "%s\t%d\n", word, (int)strlen(word));
    }
    fclose(names);
    fclose(names_db);
}