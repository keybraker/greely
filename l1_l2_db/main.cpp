#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string>

#include "word_exif_data_to_mem.h"

using namespace std;

int main() 
{	
	word_exif_func("Γερμανία");
	word_exif_func("εξαγιασμένα");
	word_exif_func("πρωτοπόρος");
	word_exif_func("Πέτρος");
	word_exif_func("");
    return 0;
}