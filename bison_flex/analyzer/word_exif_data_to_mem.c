#include "word_exif_data_to_mem.h"
#include "word_syllab_arrays.h"

#include "greek_word_data.h"
#include "greek_verb_energitiki.h"
#include "greek_verb_pathitiki.h"

#include <string.h>

/*
* Makes all capital words in a greek
* word lower case.
*/
char* 
capital_to_lower(char* word)
{
    char* capital = calloc(16,sizeof(char));

    for(int i = 0; i < 31; i++)
    {
        if(strncmp(megala[i], word, strlen(megala[i])) == 0)
        {
            strcpy(capital, word);
            strcpy(word, mikra[i]);
            strncat(word, capital + 2, strlen(capital) + 1 - 1);
            break;
        }
    }
    
    return word;
}

/*
*	Searches if the given ending is of a verb.
*	Of it is, a string is returned containing the 
*	necessary information, for the verb classification.
*/
void *
verb_ending_checker(void *ending_void, int return_type)
{
	greek_tense *num_type = (greek_tense *) malloc (sizeof(greek_tense));
	char *ending = (char *) ending_void;

	for(int i=0; i<6; i++) 
	{
		if(!strcmp(ending, enestotas_oristikis_enegitikis[i][0]))
		{
			if(return_type)
			{
				return enestotas_oristikis_enegitikis[i][1];
			}
			else
			{
				num_type->tense = 0;
				num_type->face = i;

				return num_type;
			}
		}
		if(!strcmp(ending, paratatikos_oristikis_enegitikis[i][0]))
		{
			if(return_type)
			{
				return paratatikos_oristikis_enegitikis[i][1];
			}
			else
			{
				num_type->tense = 1;
				num_type->face = i;
				
				return num_type;
			}
		}

		for(int l=0; l<3; l++) 
		{
			if(!strcmp(ending, stigmiaios_mellontas_oristikis_enegitikis[l][i][0]))
			{
				if(return_type)
				{
					return stigmiaios_mellontas_oristikis_enegitikis[l][i][1];
				}
				else
				{
					num_type->tense = 2;
					num_type->face = i;

					return num_type;
				}
			}
			if(!strcmp(ending, aoristos_oristikis_enegitikis[l][i][0]))
			{
				if(return_type)
				{
					return aoristos_oristikis_enegitikis[l][i][1];
				}
				else
				{
					num_type->tense = 3;
					num_type->face = i;

					return num_type;
				}
			}
		}
	}

	return NULL;
}

/*
*	Searches if the given ending is of a noun.
*	Of it is, a string is returned containing the 
*	necessary information, for the noun classification.
*/
void *
noun_ending_checker(void *ending_void, int return_type)
{
	return NULL;
}

/*
*	Searches if the given ending is of a adjectives.
*	Of it is, a string is returned containing the 
*	necessary information, for the adjectives classification.
*/
void *
adj_ending_checker(void *ending_void, int return_type)
{
	return NULL;
}

typedef void* (*f)(void*, int);

/*
*	Array with function for every type of word
*/
f srch_type[3] = 
{
  &verb_ending_checker,
  &noun_ending_checker,
  &adj_ending_checker
};




/*
*	Database is searched for a perfect match
*/
void * 
srch_eql(void *word_small_void)
{
	char *word_small = (char *) word_small_void;

	char *final = NULL;
	int len_id = (strlen(word_small)/2)-2;

	for(int i=0; i<word_data_sizes[len_id]; i++)
	{
		if(strcmp(word_data[len_id][i][1], word_small) == 0)
		{
			//printf("%s (found) ", word_data[len_id][i][1]);
			//functionPrinter[type](buffer_b, is_cap);
			final = strdup("(found)");
			return final;
		} 
	}

	return NULL;
}

/*
*	Special search is done to find out what exact state a word is in.
*	for example with input "παίζεις" determination of the word being 
*	a verb is already established and separation of core and ending
*	is done in order to find the state of it.
*/
void *
srch_spcl(void *word_small_void, int type, int return_type)
{
	char *word_small = (char *) word_small_void;

	int len = strlen(word_small);

	greek_tense *num_type = (greek_tense *) malloc (sizeof(greek_tense));

	char *value = NULL;
	char *final = NULL;
	char *frgm_fl = NULL;

	frgm_fl = calloc(30, sizeof(char));

	if(return_type)
	{
		for (int j = 0; j < len; j+=2)
		{
			// mhdenismos gia neo elegxo
			for (int i = 0; i < 30; ++i) 
				frgm_fl[i] = '\0';

			for (int k = j, l = 0; k < len; k+=2)
			{
				frgm_fl[l] = word_small[k];
				frgm_fl[l+1] = word_small[k+1];

				l+=2;
			}

			if((value = (char *) srch_type[type](frgm_fl, return_type)))
			{
				final = strdup("ρήμα ~ ");
				strcat(final, value);

				return final;
			}
		}

		return NULL;
		/* THIS GETS THE WORD, LETTER BY LETTER FROM THE BACK
			BUT DOESNT WORK CORRECTLY FOR THIS CASE eq. χάνει, χάσει
		for (int j = len; j > 0; j-=2)
		{
			// mhdenismos gia neo elegxo
			for (int i=0; i<30; i++) 
				frgm_fl[i] = '\0';

			for (int k=len-1, l=len-j-1; k>j; k-=2, l-=2)
			{
				frgm_fl[l-1] = word_small[k-1];
				frgm_fl[l] = word_small[k];
			}

			if((value = (char *) srch_type[type](frgm_fl, return_type)))
			{
				final = strdup("ρήμα ~ ");
				strcat(final, value);

				return final;
			}
		}

		return NULL;
		*/
	}
	else
	{	
		for (int j = 0; j < len; j+=2)
		{
			// mhdenismos gia neo elegxo
			for (int i = 0; i < 30; ++i) 
				frgm_fl[i] = '\0';

			for (int k = j, l = 0; k < len; k+=2)
			{
				frgm_fl[l] = word_small[k];
				frgm_fl[l+1] = word_small[k+1];

				l+=2;
			}

			if((num_type = (greek_tense *) srch_type[type](frgm_fl, return_type)))
			{
				return num_type;
			}
		}

		num_type->tense = -1;
		num_type->face = -1;

		return num_type;

		/* THIS GETS THE WORD, LETTER BY LETTER FROM THE BACK
			BUT DOESNT WORK CORRECTLY FOR THIS CASE eq. χάνει, χάσει
		for (int j = len; j > 0; j-=2)
		{
			// mhdenismos gia neo elegxo
			for (int i=0; i<30; i++) 
				frgm_fl[i] = '\0';

			for (int k=len-1, l=len-j-1; k>j; k-=2, l-=2)
			{
				frgm_fl[l-1] = word_small[k-1];
				frgm_fl[l] = word_small[k];
			}

			if((num_type = (greek_tense *) srch_type[type](frgm_fl, return_type)))
			{
				printf("greek_tense->tense %d\n", num_type->tense);
				printf("greek_tense->face %d\n", num_type->face);
				return num_type;
			}
		}

		num_type->tense = -1;
		num_typeface = -1;
		
		return num_type;
		*/
	}

	return NULL;
}

greek_tense *
word_exif_func(char* word, int type, int return_type)
{    
	/* Makes string all small characters */
	char *word_cap = strdup(word);
	char *word_small = capital_to_lower(word);

	greek_tense *num_type = (greek_tense *) malloc (sizeof(greek_tense));
	num_type->tense = -1;
	num_type->face = -1;

	char *output = NULL;
	char *is_capital = NULL;

	if(strcmp(word_cap, word_small) != 0)
		is_capital = word_cap;

	if(return_type)
	{
		if((output = (char *) srch_spcl(word_small, type, return_type)))
		{
			printf("%s (%s) ", word, output);
		}
		else
		{
			printf("%s " a_c_r "(no data in database) " a_c_re, word);
		}
	}
	else
	{
		if((num_type = (greek_tense *) srch_spcl(word_small, type, return_type)))
		{
			return num_type;
		}
		else
		{
			printf("%s " a_c_r "(no data in database) " a_c_re, word);
		}
	}

	num_type->tense = -1;
	num_type->face = -1;

	return num_type;
}

int type_of_word(char *word)
{
	/* Makes string all small characters */
	char *word_cap = strdup(word);
	char *word_small = capital_to_lower(word);

	char *output = NULL;
	char *is_capital = NULL;

	if(strcmp(word_cap, word_small) != 0)
		is_capital = word_cap;

	int len = strlen(word_small);

	char *value = NULL;
	char *final = NULL;
	char *frgm_fl = NULL;

	frgm_fl = calloc(30, sizeof(char));

	for (int j = len; j > 0; j-=2)
	{
		// mhdenismos gia neo elegxo
		for (int i=0; i<30; i++) 
			frgm_fl[i] = '\0';

		for (int k=len-1, l=len-j-1; k>j; k-=2, l-=2)
		{
			frgm_fl[l-1] = word_small[k-1];
			frgm_fl[l] = word_small[k];
		}

		if((char *) verb_ending_checker(frgm_fl, 1))
			return 0; // verb_ending_checker
		if((char *) noun_ending_checker(frgm_fl, 1))
			return 1; // noun_ending_checker
		if((char *) adj_ending_checker(frgm_fl, 1))
			return 2; // adjc_ending_checker
	}

	return 3;
}