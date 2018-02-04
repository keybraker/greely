/*
* This function will free up all 
* memory allocated by the database
* only when the program is about to
* finish execution
*/

#include "word_type_print.h"
#include "word_exif_data_to_mem.h"

int length = 0;

/* 
* loads all database, line by line to 
* to a mmap on execution start
*/
char **
load_data_to_mem(char *filepath)
{
    FILE    * database_file;
    char    * buffer = calloc(255, sizeof(char));
    char    ** file_to_mem = calloc(255*8912, sizeof(char*));
    int i = 0;

    database_file = fopen (filepath, "r");
    if(!database_file)
    { 
        printf("cannot open word_data_gr.txt"); 
        exit(1); 
    }
    
    while (fgets(buffer, 255, database_file)!= NULL) { 

        if(file_to_mem[i] == NULL)
        {
            file_to_mem[i] = calloc(strlen(buffer)*255, sizeof(char));
            strcpy(file_to_mem[i], buffer);
        }
        else
        {
          printf("error\n");
          return NULL;
        }

        i++;

    };

    length = i;
    fclose(database_file);
    return file_to_mem;
}

/* 
* frees up all space taken by
* the database at the begining 
*/
void 
free_data_from_mem(char **file_to_mem)
{
    free(file_to_mem);
    return;
}

/*
* binary search for length (cannot run if strlen(greekword) gives random number)
*/
int 
binary_search(char **file_to_mem, int l, int r, int x)
{
    char *buffer_a = calloc(255, sizeof(char));
    char *len;

    if (r >= l)
    {
        int mid = l + (r - l)/2;
        strcpy(buffer_a, file_to_mem[mid]);
        len = strtok(buffer_a, "|");

        // If the element is present at the middle 
        // itself
        if (atoi(len) == x)  
            return mid;

        // If element is smaller than mid, then 
        // it can only be present in left subarray
        if (atoi(len) > x) 
            return binary_search(file_to_mem, l, mid-1, x);

        // Else the element can only be present
        // in right subarray
        return binary_search(file_to_mem, mid+1, r, x);
    }

    return -1;
    
}

/*
* Normal Search
*/
void 
normal_search(char *isCap, char *wordInputSmall, char **file_to_mem)
{

    int  type = 0, i = 0;
    char *buffer_a = calloc(255, sizeof(char));
    char *buffer_b = calloc(255, sizeof(char));
    char *len, *syllen, *word, *syllabes;

    while ( file_to_mem[i] != NULL )
    {
        strcpy(buffer_a, file_to_mem[i]);
        strcpy(buffer_b, file_to_mem[i]);

        len = strtok(buffer_a, "|");
        word = strtok(NULL, "|");
        syllen = strtok(NULL, "|");
        syllabes = strtok(NULL, "|");
        type = toInt(strtok(NULL, "|"));

        if( strcmp(word, wordInputSmall) == 0 ){
            /* 
                goes to array finds type
                calls the type defined
                function and executes it 
            */
            functionPrinter[type](buffer_b, isCap);
            return;
        } 

        //printf("%s", file_to_mem[i]);
        i++;
    }
}

/* 
* control panel
*/
int
word_exif_func(char* wordInput)
{    
    static char **file_to_mem = NULL;

    /* Freeing all allocated memory*/
    if(wordInput == NULL && file_to_mem != NULL)
    {
        free_data_from_mem(file_to_mem);
        return 0;
    }

    /* Opening file and loading it to memory*/
    if(file_to_mem == NULL)
        file_to_mem = load_data_to_mem("bison_flex/analyzer_funcs/word_data_gr.txt");

    /* Makes string all small characters */
    char *wordInputCap = strdup(wordInput);
    char *wordInputSmall = capToSmall(wordInput);
    wordInput = strdup(wordInputCap);

    char *isCap = NULL;
    if(strcmp(wordInputCap, wordInputSmall) != 0)
        isCap = wordInputCap;
        
    normal_search(isCap, wordInputSmall, file_to_mem);

    return 0;
}