/*
* This function will free up all 
* memory allocated by the database
* only when the program is about to
* finish execution
*/

#include "word_type_print.h"
#include "word_exif_data_to_mem.h"
#include "greek_word_data.h"
/*
* Normal Search
*/
void 
search(char *is_cap, char *word_input_small)
{
	int len = (strlen(word_input_small)/2)-2;

	for(int i=0; i<word_data_sizes[len]; i++)
	{
		if(strcmp(word_data[len][i][1], word_input_small) == 0){
			printf("%s (found) ", word_data[len][i][1]);
			//functionPrinter[type](buffer_b, is_cap);
			return;
		} 
	}
	printf("%s " a_c_r "(no data in DB) " a_c_re, word_input_small);
}

/* 
* control panel
*/
int
word_exif_func(char* word_input)
{    
	/* Makes string all small characters */
	char *word_input_cap = strdup(word_input);
	char *word_input_small = capToSmall(word_input);
	word_input = strdup(word_input_cap);

	char *is_cap = NULL;
	if(strcmp(word_input_cap, word_input_small) != 0)
		is_cap = word_input_cap;
		
	search(is_cap, word_input_small);

	return 0;
}