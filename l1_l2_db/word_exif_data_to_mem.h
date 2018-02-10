#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/mman.h>
#include <assert.h>

//#include <bits/stdc++.h>
#include <vector>
#include <cstddef>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string> 

using namespace std;

#define a_c_r     "\x1b[31m"
#define a_c_g     "\x1b[32m"
#define a_c_y     "\x1b[33m"
#define a_c_b     "\x1b[34m"
#define a_c_m     "\x1b[35m"
#define a_c_c     "\x1b[36m"
#define a_c_re    "\x1b[0m"
#define under     "\e[4m"
#define under_re  "\e[0m"
#define italic    "\e[3m"
#define italic_re "\e[0m"
#define bold      "\e[1m"
#define bold_re   "\e[0m"

int 
word_exif_func(string wordInput);

enum Suit { 
  verb, noun, adj, Spades,  no_tag, 
  adv, quant, adj_noun, properN, 
  excl, excl_noun, adv_adj_star 
};  

class print_word_info 
{
    public:
        /* constructor */
        print_word_info(){}
        print_word_info(int num_of_tokens, string word_tokens[]){
            _num_of_tokens = num_of_tokens;
            _database = new string[num_of_tokens];

            for(int i = 0; i < _num_of_tokens; i++)
                _database = word_tokens;
        }

        /* initiallizing values */
        void set_word(int num_of_tokens, string word_tokens[]){
            _num_of_tokens = num_of_tokens;
            _database = new string[num_of_tokens];

            for(int i = 0; i < _num_of_tokens; i++)
                _database = word_tokens;
        }

        /* functions on data */
        void cout_word(){

          if(_num_of_tokens == 2)
             print_name();        
          else if(_database[4] == "verb")
             print_rima();        
          else if(_database[4] == "noun")
             print_epitheto();    
          else if(_database[4] == "adj")
             print_ousiastiko();  
          else if(_database[4] == "excl")
             print_metoxi();      
          else if(_database[4] == "")
             print_arithmitika(); 
          else if(_database[4] == "")
             print_epirima();     
          else if(_database[4] == "")
             print_sundesmo();    
          else if(_database[4] == "")
             print_antonimia();
          else
            print_antonimia();

        }

    private:
        int _num_of_tokens;
        string *_database;

        void
        print_name()
        {
          if(_database[0] == "0") cout << _database[0] << " (αρσενικό όνομα)" << endl;
          else cout << _database[0] << " (θηλυκό όνομα)" << endl;
        }

        void
        print_rima()
        {
          cout << _database[0] << " (";
          for(int i = 1; i < _num_of_tokens-1; i++)
            cout << _database[i] << ", "; 
          cout << _database[_num_of_tokens-1] << ") " << endl;
        }

        void
        print_epitheto()
        {
          cout << _database[0] << " (";
          for(int i = 1; i < _num_of_tokens-1; i++)
            cout << _database[i] << ", "; 
          cout << _database[_num_of_tokens-1] << ") " << endl;
        }

        void
        print_ousiastiko()
        {
          cout << _database[0] << " (";
          for(int i = 1; i < _num_of_tokens-1; i++)
            cout << _database[i] << ", "; 
          cout << _database[_num_of_tokens-1] << ") " << endl;
        }

        void
        print_metoxi()
        {
          cout << _database[0] << " (";
          for(int i = 1; i < _num_of_tokens-1; i++)
            cout << _database[i] << ", "; 
          cout << _database[_num_of_tokens-1] << ") " << endl;
        }

        void
        print_arithmitika()
        {
          cout << _database[0] << " (";
          for(int i = 1; i < _num_of_tokens-1; i++)
            cout << _database[i] << ", "; 
          cout << _database[_num_of_tokens-1] << ") " << endl;
        }

        void
        print_epirima()
        {
          cout << _database[0] << " (";
          for(int i = 1; i < _num_of_tokens-1; i++)
            cout << _database[i] << ", "; 
          cout << _database[_num_of_tokens-1] << ") " << endl;
        }

        void
        print_sundesmo()
        {
          cout << _database[0] << " (";
          for(int i = 1; i < _num_of_tokens-1; i++)
            cout << _database[i] << ", "; 
          cout << _database[_num_of_tokens-1] << ") " << endl;
        }

        void
        print_antonimia()
        {
          cout << _database[0] << " (";
          for(int i = 1; i < _num_of_tokens-1; i++)
            cout << _database[i] << ", "; 
          cout << _database[_num_of_tokens-1] << ") " << endl;
        }
};