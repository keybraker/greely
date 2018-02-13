/*
* This function will free up all 
* memory allocated by the database
* only when the program is about to
* finish execution
*/

#include "word_exif_data_to_mem.hh"
#include "word_endings.hh"

#define MEM_NO_ALLOC 0
#define MEM_ALLOC 1

using namespace std;

/*
* String starts with 
*/
inline bool 
starts_with(std::string mainStr, std::string toMatch)
{
    if(mainStr.find(toMatch) == 0)
        return true;
    else
        return false;
}

/*
* String ends with 
*/
inline bool 
ends_with(std::string const & value, std::string const & ending)
{
    if (ending.size() > value.size()) return false;
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

/*
* Greek upper case to 
* lower case converter
*/
string 
tolower_gr(string origin)
{
    string new_word = "";
    string joker = "";

    for (int i = 0; i < origin.length(); i += 2){
        joker = origin[i]; joker += origin[i+1];
        for(int j = 0; j < 32; j++){
            if(cap_gr[j] == joker){
                if(j == 22 && i+2 == origin.length())
                    new_word += low_gr[23];
                else
                    new_word += low_gr[j];
                break;
            }
            else if(j == 31){
                new_word += joker;
            }
        }
    } 
    return new_word;
}

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
    delete [] database; // When done, free memory pointed to by a.
    database = nullptr; // Clear a to prevent using invalid memory reference.
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
    string  buffer_a, buffer_b, words_file[num_of_tokens], delimiter = "|";

    while (i < num_of_words && !database[i].empty())
    {
        int k = 0;
        size_t current, previous = 0;
        buffer_a = database[i];

        current = buffer_a.find('|');
        if(current == string::npos)
            words_file[k] = buffer_a.substr(previous, current - previous);

        while (current != string::npos) {
            words_file[k] = buffer_a.substr(previous, current - previous);
            previous = current + 1;
            current = buffer_a.find('|', previous);
            // cout << "(" << k << "): " << words_file[k] << ", ";
            k++;
        }

        if(!small_word.empty() && words_file[word_pos].compare(small_word) == 0){
            
            words_file[word_pos] = original_word; 
            print_word_info word_for_print;
            word_for_print.set_word(num_of_tokens, words_file);
            word_for_print.cout_word();

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

    /* Freeing all allocated memory*/
    if(word_to_search.empty()){
        if(name_to_mem != nullptr)
            free_data_from_mem(name_to_mem);
        if(word_to_mem != nullptr)
            free_data_from_mem(word_to_mem);
        return 0;
    }
    /* Opening l0 name database*/
    if(name_to_mem == nullptr)
        name_to_mem = load_data_to_mem(2189, "../db_txt_xlsx/l0_name.txt");

    /* Opening l1 word database*/
    if(word_to_mem == nullptr)
        word_to_mem = load_data_to_mem(595926, "../db_txt_xlsx/l1_database.txt");

    // prepei na perastei mikro giati allios ton pinei
    string original_word = word_to_search;
    string small_word = tolower_gr(word_to_search);

    if(!normal_search(2189, 5, 1, original_word, small_word, name_to_mem)){ /* l0_name search */
        if(!normal_search(595926, 6, 1, original_word, small_word, word_to_mem)){ /* l1_word search */
            cout << "no info for " << small_word << endl;
            return 0;
        }
    }
    return 1;
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