#include "word_exif_data_to_mem.h"
#include "word_type_print.h"

#include "greek_word_data.h"
#include "greek_endings.h"

#include <string.h>

int 
search_eql(char *is_cap, char *word_input_small)
{
	int len_id = (strlen(word_input_small)/2)-2;

	for(int i=0; i<word_data_sizes[len_id]; i++)
	{
		if(strcmp(word_data[len_id][i][1], word_input_small) == 0)
		{
			printf("%s (found) ", word_data[len_id][i][1]);
			//functionPrinter[type](buffer_b, is_cap);
			return 1;
		} 
	}
	return 0;
}

int
elegxos_kataliksis(char *ending)
{
	for(int i=0; i<12; i++) 
	{
		if(strcmp(ending, endings_pair_ARS_EN_AR[i]) == 0)
		{
			printf("nai enai ontos kataliksi : endings_pair_ARS_EN_AR\n");
			return 1;
		}
	}
	
	for(int i=0; i<8; i++) 
	{
		if(strcmp(ending, endings_pair_THY_EN_AR[i]) == 0)
		{
			printf("nai enai ontos kataliksi : endings_pair_THY_EN_AR\n");
			return 1;
		}
	}
	
	for(int i=0; i<16; i++) 
	{
		if(strcmp(ending, endings_pair_OUD_EN_AR[i]) == 0)
		{
			printf("nai enai ontos kataliksi : endings_pair_OUD_EN_AR\n");
			return 1;
		}
	}
	
	for(int i=0; i<11; i++) 
	{
		if(strcmp(ending, endings_pair__EN_AR[i]) == 0)
		{
			printf("nai enai ontos kataliksi : endings_pair__EN_AR\n");
			return 1;
		}
	}
	
	for(int i=0; i<8; i++) 
	{
		if(strcmp(ending, endings_pair_ARS_PL_AR[i]) == 0)
		{
			printf("nai enai ontos kataliksi : endings_pair_ARS_PL_AR\n");
			return 1;
		}
	}
	
	for(int i=0; i<4; i++) 
	{
		if(strcmp(ending, endings_pair_THY_PL_AR[i]) == 0)
		{
			printf("nai enai ontos kataliksi : endings_pair_THY_PL_AR\n");
			return 1;
		}
	}
	
	for(int i=0; i<6; i++) 
	{
		if(strcmp(ending, endings_pair_OUD_PL_AR[i]) == 0)
		{
			printf("nai enai ontos kataliksi : endings_pair_OUD_PL_AR\n");
			return 1;
		}
	}
	
	for(int i=0; i<2; i++) 
	{
		if(strcmp(ending, endings_pair_PL_AR[i]) == 0)
		{
			printf("nai enai ontos kataliksi : endings_pair_PL_AR\n");
			return 1;
		}
	}
	for(int i=0; i<18; i++)
	{
		if(strcmp(ending, endings_rima_proto_en[i]) == 0)
		{
			printf("nai enai ontos kataliksi : endings_rima_proto_en\n");
			return 1;
		}
	}
	
	for(int i=0; i<18; i++)
	{
		if(strcmp(ending, endings_rima_deutero_en[i]) == 0)
		{
			printf("nai enai ontos kataliksi : endings_rima_deutero_en\n");
			return 1;
		}
	}
	
	for(int i=0; i<18; i++)
	{
		if(strcmp(ending, endings_rima_trito_en[i]) == 0)
		{
			printf("nai enai ontos kataliksi : endings_rima_trito_en\n");
			return 1;
		}
	}
	
	for(int i=0; i<18; i++)
	{
		if(strcmp(ending, endings_rima_proto_pl[i]) == 0)
		{
			printf("nai enai ontos kataliksi : endings_rima_proto_pl\n");
			return 1;
		}
	}
	
	for(int i=0; i<18; i++)
	{
		if(strcmp(ending, endings_rima_deutero_pl[i]) == 0)
		{
			printf("nai enai ontos kataliksi : endings_rima_deutero_pl\n");
			return 1;
		}
	}
	
	for(int i=0; i<18; i++)
	{
		if(strcmp(ending, endings_rima_trito_pl[i]) == 0)
		{
			printf("nai enai ontos kataliksi : endings_rima_trito_pl\n");
			return 1;
		}
	}
	
	return 0;
}

int 
search_spcl(char *is_cap, char *word_input_small)
{
	int len = strlen(word_input_small);

	char *fragment_in = calloc(10, sizeof(char));
	char *fragment_db = calloc(10, sizeof(char));
	char *fragment_fl = calloc(10, sizeof(char));

	for (int i = 0; i < 10; ++i)
	{
		fragment_in[i] = fragment_db[i] = fragment_fl[i] = '\0';
	}

	for(int len_id=0; len_id<21; len_id++)
	{
		for(int i=0; i<word_data_sizes[len_id]; i++)
		{
			for (int j = 0; j < len; j+=2)
			{
				fragment_in[0] = word_input_small[j];
				fragment_in[1] = word_input_small[j+1];

				fragment_db[0] = (word_data[len_id][i][1])[j];
				fragment_db[1] = (word_data[len_id][i][1])[j+1];
			
				if(strcmp(fragment_in, fragment_db) != 0)
				{
					// mhdenismos gia neo elegxo
					for (int i = 0; i < 10; ++i) fragment_fl[i] = '\0';
	
					for (int k = j, l = 0; k < len; k+=2)
					{
						fragment_fl[l] = word_input_small[k];
						fragment_fl[l+1] = word_input_small[k+1];

						l+=2;
					}

					if(elegxos_kataliksis(fragment_fl))
					{
						printf("einai ontos kataliksi to: %s ?\n", fragment_fl);
						return 1;
					}
				}
			}
		}
	}
	return 0;
}




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
		
	if(!search_eql(is_cap, word_input_small))
		if(!search_spcl(is_cap, word_input_small))
			printf("%s " a_c_r "(no data in DB) " a_c_re, word_input_small);

	return 0;
}