#include "word_exif_data_to_mem.h"
#include "word_type_print.h"

#include "greek_word_data.h"
#include "greek_verb_energitiki.h"
#include "greek_verb_pathitiki.h"

#include <string.h>

/*
*	Searches if the given ending is of a verb.
*	Of it is, a string is returned containing the 
*	necessary information, for the verb classification.
*/
void *
verb_ending_checker(void *ending_void)
{
	char *ending = (char *) ending_void;

	for(int i=0; i<6; i++) 
	{
		if(!strcmp(ending, enestotas_oristikis_enegitikis[i][0]))
			return enestotas_oristikis_enegitikis[i][1];
		if(!strcmp(ending, paratatikos_oristikis_enegitikis[i][0]))
			return paratatikos_oristikis_enegitikis[i][1];

		for(int l=0; l<3; l++) 
		{
			if(!strcmp(ending, stigmiaios_mellontas_oristikis_enegitikis[l][i][0]))
				return stigmiaios_mellontas_oristikis_enegitikis[l][i][1];
			if(!strcmp(ending, aoristos_oristikis_enegitikis[l][i][0]))
				return aoristos_oristikis_enegitikis[l][i][1];
		}
	}

	return NULL;
}

/*
*	Searches if the given ending is of a verb.
*	Of it is, a string is returned containing the 
*	necessary information, for the verb classification.
*/
int
noun_adjective_ending_checker(char *ending)
{
	return 0;
}

/*
*	Database is searched for a perfect match
*/
void * 
srch_eql(void *is_cap_void, void *word_input_small_void)
{
	char *is_cap = (char *) is_cap_void;
	char *word_input_small = (char *) word_input_small_void;

	char *final = NULL;
	int len_id = (strlen(word_input_small)/2)-2;

	for(int i=0; i<word_data_sizes[len_id]; i++)
	{
		if(strcmp(word_data[len_id][i][1], word_input_small) == 0)
		{
			//printf("%s (found) ", word_data[len_id][i][1]);
			//functionPrinter[type](buffer_b, is_cap);
			strcpy(final, is_cap);
			strcat(final, " (found) ");

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
srch_spcl(void *is_cap_void, void *word_input_small_void)
{
	char *is_cap = (char *) is_cap_void;
	char *word_input_small = (char *) word_input_small_void;

	int len = strlen(word_input_small);

	char *value = NULL;
	char *final = NULL;
	char *fragment_fl = calloc(30, sizeof(char));

	// mhdenismos gia neo elegxo
	for (int i = 0; i < 30; ++i)
		fragment_fl[i] = '\0';

	for (int j = 0; j < len; j+=2)
	{
		// mhdenismos gia neo elegxo
		for (int i = 0; i < 30; ++i) 
			fragment_fl[i] = '\0';

		for (int k = j, l = 0; k < len; k+=2)
		{
			fragment_fl[l] = word_input_small[k];
			fragment_fl[l+1] = word_input_small[k+1];

			l+=2;
		}

		if((value = (char *) verb_ending_checker(fragment_fl)))
		{
			strcpy(final, is_cap);
			strcat(final, " (ρήμα ");
			strcat(final, value);
			strcat(final, ") ");

			return final;
		}
		// else if(value = strdup(verb_ending_checker(fragment_fl)) != NULL)	return 1; // noun_ending_checker
		// else if(value = strdup(verb_ending_checker(fragment_fl)) != NULL)	return 2; // adjc_ending_checker
	}

	return NULL;
}

// true if found
// false if not found
int
word_exif_func(char* word_input)
{    
	/* Makes string all small characters */
	char *word_input_cap = strdup(word_input);
	char *word_input_small = capToSmall(word_input);
	char *output = NULL;
	char *is_capital = NULL;

	if(strcmp(word_input_cap, word_input_small) != 0)
		is_capital = word_input_cap;

	if((output = (char *) srch_eql(is_capital, word_input_small)) != NULL)
	{
		if((output = (char *) srch_spcl(is_capital, word_input_small)) != NULL)
		{
			printf("%s " a_c_r "(no data in DB) " a_c_re, word_input_small);
			return 0;
		}
		else
		{
			printf("output 1: %s\n", output);
		}
	}
	else
	{
		printf("output 2: %s\n", output);
	}

	return 1;
}