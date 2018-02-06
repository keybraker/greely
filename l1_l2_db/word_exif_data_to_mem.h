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

#include <bits/stdc++.h>
#include <vector>
#include <cstddef>
#include<iostream>
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
        void cout_word(int data_type){

          switch(data_type){
            case 0: print_name();       break;
            case 1: print_rima();       break;
        case 2: print_epitheto();     break;
        case 3: print_ousiastiko();   break;
        case 4: print_metoxi();     break;
        case 5: print_arithmitika();  break;
        case 6: print_epirima();    break;
        case 7: print_sundesmo();     break;
        case 8: print_antonimia();    break;
          }

        }

    private:
        int _num_of_tokens;
        string *_database;

        void
        print_name()
        {
          if(_database[0] == "0")
            cout << _database[0] << " (αρσενικό όνομα)" << endl;
          else
            cout << _database[0] << " (θηλυκό όνομα)" << endl;
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