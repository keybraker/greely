#include<iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string> 
#include "word_exif_data_to_mem.h"

using namespace std;

int main() 
{
	// word_exif_func("άχτι");
	// word_exif_func("");

	print_word_info tsiakkas;
	string stand[4] = {"genos", "paka", "rolex", "hot"};
	tsiakkas.set_word(4, stand);
	tsiakkas.cout_word(2);

	print_word_info namer;
	string stand2[2] = {"Αντιγόνη", "1"};
	namer.set_word(2, stand2);
	namer.cout_word(0);

    return 0;
}