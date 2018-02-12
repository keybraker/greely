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
  article, verb, noun, adj, no_tag, 
  adv, quant, adj_noun, properN, 
  noun_properN, conj, part, part_noun,
  excl, excl_noun, adv_adj 
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

        	/* abnormal prints */
			if(_num_of_tokens == 5)
			 	print_name();        
			else if(_database[5] == "no_tag")
			 	print_no_tag(); 

        	/* normal prints */
			else if(_database[5] == "verb")
			 	print_epitheto();    
			else if(_database[5] == "noun")
			 	print_ousiastiko();   
			else if(_database[5] == "adv")
			 	print_epirima();     
			else if(_database[5] == "adj")
			 	print_metoxi();     
			else if(_database[5] == "adv_adj")
			 	print_arithmitika(); 
			else if(_database[5] == "article")
			 	print_arithmitika(); 
			else if(_database[5] == "quant")
			 	print_sundesmo();    
			else if(_database[5] == "quant_adj")
			 	print_antonimia();
			else if(_database[5] == "excl")
			 	print_epitheto(); 
			else if(_database[5] == "excl_noun")
			 	print_epitheto();    
			else if(_database[5] == "properN")
			 	print_ousiastiko();  
			else if(_database[5] == "noun_properN")
			 	print_metoxi();      
			else if(_database[5] == "conj")
			 	print_arithmitika(); 
			else if(_database[5] == "part")
			 	print_epirima();     
			else if(_database[5] == "part_noun")
			 	print_sundesmo();    
			else
				cout << _database[0]
					 << " no info for type: " 
					 << _database[5] << endl;

        }

    private:
        int _num_of_tokens;
        string *_database;

        void
        print_name()
        {
          if(_database[4] == "0"){
          	cout << bold << _database[1] << bold_re << a_c_y
          		 << italic " (αρσενικό όνομα)" italic_re 
          		 << a_c_y " ~ {"
		         << _database[2] << ": "
		         << _database[3] << "} " a_c_re << endl;
          }else{
          	cout << bold << _database[1] << bold_re << a_c_y
          		 << italic " (θηλυκό όνομα)" italic_re 
          		 << a_c_y " ~ {"
		         << _database[2] << ": "
		         << _database[3] << "} " a_c_re << endl;
          } 
        }

        void
        print_no_tag()
        {
          cout << bold under << _database[1] << bold_re under_re 
          	   << a_c_r " ~ {"
	           << _database[2] << ": "
	           << _database[3] << "} " a_c_re << endl;
        }

        void
        print_rima()
        {
        	cout 
			<< bold << _database[1] << bold_re << a_c_y
			<< " ~ " << _database[5] << " syll[" << _database[2] << "] {" 
			<< _database[3] << "} occ[" << _database[4] << "]"
		 	<< a_c_re << endl;
        }

        void
        print_epitheto()
        {
        	cout 
			<< bold << _database[1] << bold_re << a_c_y
			<< " ~ " << _database[5] << " {" << _database[2] << ": " 
			<< _database[3] << "} occ[" << _database[4] << "]"
		 	<< a_c_re << endl;
        }

        void
        print_ousiastiko()
        {
        	cout 
			<< bold << _database[1] << bold_re << a_c_y
			<< " ~ " << _database[5] << " {" << _database[2] << ": " 
			<< _database[3] << "} occ[" << _database[4] << "]"
		 	<< a_c_re << endl;
        }

        void
        print_metoxi()
        {
        	cout 
			<< bold << _database[1] << bold_re << a_c_y
			<< " ~ " << _database[5] << " {" << _database[2] << ": " 
			<< _database[3] << "} occ[" << _database[4] << "]"
		 	<< a_c_re << endl;
        }

        void
        print_arithmitika()
        {
        	cout 
			<< bold << _database[1] << bold_re << a_c_y
			<< " ~ " << _database[5] << " {" << _database[2] << ": " 
			<< _database[3] << "} occ[" << _database[4] << "]"
		 	<< a_c_re << endl;
        }

        void
        print_epirima()
        {
        	cout 
			<< bold << _database[1] << bold_re << a_c_y
			<< " ~ " << _database[5] << " {" << _database[2] << ": " 
			<< _database[3] << "} occ[" << _database[4] << "]"
		 	<< a_c_re << endl;
        }

        void
        print_sundesmo()
        {
        	cout 
			<< bold << _database[1] << bold_re << a_c_y
			<< " ~ " << _database[5] << " {" << _database[2] << ": " 
			<< _database[3] << "} occ[" << _database[4] << "]"
		 	<< a_c_re << endl;
        }

        void
        print_antonimia()
        {
			cout 
			<< bold << _database[1] << bold_re << a_c_y
			<< " ~ " << _database[5] << " {" << _database[2] << ": " 
			<< _database[3] << "} occ[" << _database[4] << "]"
		 	<< a_c_re << endl;
        }
};