/*
* This function will free up all 
* memory allocated by the database
* only when the program is about to
* finish execution
*/

#include "word_exif_data_to_mem.h"

using namespace std;

/* 
* loads all database, line by line to 
* to a mmap on execution start
*/
string*
load_data_to_mem(int size, string filepath)
{
    string buffer;
    string *database = new string[size];
    ifstream inFile;

    inFile.open(filepath);
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    int i = 0;
    while (i < size && inFile >> buffer) {
        
        if(database[i].empty() && i < size)
            database[i] = buffer;

        i++;

    }

    inFile.close();
    return database;
}

/* 
* frees up all space taken by
* the database at the begining 
*/
void 
free_data_from_mem(string *database)
{
    delete [] database;  // When done, free memory pointed to by a.
    database = nullptr;     // Clear a to prevent using invalid memory reference.
    return;
}

/*
* Normal Search
*/
bool 
normal_search(int num_of_words, int num_of_tokens, int word_pos, 
string original_word, string small_word, string database[])
{
    int  i = 0;
    size_t pos = 0;

    string  buffer_a, buffer_b, words_file[num_of_tokens], delimiter = "|";

    while (i < num_of_words && !database[i].empty())
    {
        pos = 0;
        stringstream buffer_stream(database[i]);
        string intermediate;

        for(int j = 0; getline(buffer_stream, intermediate, '|'); j++)
            words_file[j] = intermediate;

        if(!small_word.empty() && words_file[word_pos].compare(small_word) == 0){
            for(int i = 0; i < num_of_tokens; i++)
                cout << "words_file[" << i << "]: " << words_file[i] << endl;
            cout << endl;
            return true;
        } 
        i++;
    }
    return false;
}

/* 
* control panel
*/
int
word_exif_func(string word_to_search)
{
    static string *name_to_mem = nullptr;
    static string *word_to_mem = nullptr;
    static string *huge_to_mem = nullptr;

    /* Freeing all allocated memory*/
    if(word_to_search.empty()){
        if(name_to_mem != nullptr)
            free_data_from_mem(name_to_mem);
        if(word_to_mem != nullptr)
            free_data_from_mem(word_to_mem);
        if(huge_to_mem != nullptr)
            free_data_from_mem(huge_to_mem);
        return 0;
    }

    /* Opening l0 name database*/
    if(name_to_mem == nullptr)
        name_to_mem = load_data_to_mem(2189, "l0_name.txt");

    /* Opening l1 word database*/
    if(word_to_mem == nullptr)
        word_to_mem = load_data_to_mem(35282, "l1_database.txt");

    /* Opening l2 word database*/
    if(huge_to_mem == nullptr)
        huge_to_mem = load_data_to_mem(593070, "l2_database.txt");

    // prepei na perastei mikro giati allios ton pinei
    string original_word = word_to_search;
    string small_word = word_to_search;

    if(!normal_search(2189, 2, 0, original_word, small_word, name_to_mem)) /* l0_name search */
        if(!normal_search(35282, 5, 0, original_word, small_word, word_to_mem)) /* l1_word search*/ 
            if(!normal_search(593070, 1, 0, original_word, small_word, huge_to_mem)) /* l2_word search*/ 
                return 1;

    return 0;
}











/*
* binary search for length (cannot run if strlen(greekword) gives random number)
*/
// int 
// binary_search(string database[], int l, int r, int x)
// {
//     char buffer_a, len;

//     if (r >= l)
//     {
//         int mid = l + (r - l)/2;
//         strcpy(buffer_a, database[mid]);
//         len = strtok(buffer_a, "|");

//         // If the element is present at the middle 
//         // itself
//         if (atoi(len) == x)  
//             return mid;

//         // If element is smaller than mid, then 
//         // it can only be present in left subarray
//         if (atoi(len) > x) 
//             return binary_search(database, l, mid-1, x);

//         // Else the element can only be present
//         // in right subarray
//         return binary_search(database, mid+1, r, x);
//     }

//     return -1; 
// }