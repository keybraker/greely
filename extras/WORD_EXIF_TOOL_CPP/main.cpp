#include "word_exif_data_to_mem.hh"

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