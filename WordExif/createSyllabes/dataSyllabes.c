#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mikra[31] = {
    "α","ά","β","γ","δ","ε","έ","ζ","η","ή","θ",
    "ι","ί","κ","λ","μ","ν","ξ","ο","ό","π","ρ",
    "σ","τ","υ","ύ","φ","χ","ψ","ω","ώ"
};

char *megala[31] = {
    "Α","Ά","Β","Γ","Δ","Ε","Έ","Ζ","Η","Ή","Θ",
    "Ι","Ι","Κ","Λ","Μ","Ν","Ξ","Ο","Ό","Π","Ρ",
    "Σ","Τ","Υ","Ύ","Φ","Χ","Ψ","Ω","Ώ"
};

char *mikraFonienta[14] = {
    "α","ά","ε","έ","η","ή",
    "ι","ί","ο","ό","υ","ύ","ω","ώ"
};

char *mikraSymbola[18] = {
    "β","γ","δ","ζ","θ","κ",
    "λ","μ","ν","ξ","π","ρ",
    "σ","ς","τ","φ","χ","ψ"
};

char *megalaFonienta[14] = {
    "Α","Ά","Ε","Έ","Η","Ή",
    "Ι","Ι","Ο","Ό","Υ","Ύ","Ω","Ώ"
};

char *megalaSymbola[17] = {
    "Β","Γ","Δ","Ζ","Θ","Κ",
    "Λ","Μ","Ν","Ξ","Π","Ρ",
    "Σ","Τ","Φ","Χ","Ψ"
};

struct dataB{

	char *firstFonien;
	char *firstSymbol;
	char *secondFonien;
	char *secondSymbol;
	char *thirdFonien;
	char *thirdSymbol;

	int IfirstFonien;
	int IfirstSymbol;
	int IsecondFonien;
	int IsecondSymbol;
	int IthirdFonien;
	int IthirdSymbol;

};




int getSort(int a, int b, int c, int d, int e){

	int sum = a+b+c+d+e;

	if( sum == 0 ){
		return 1;
	}else if( sum == 1 ){
		return 2;
	}else if( sum == 3 ){
		return 3;
	}else if( sum == 6 ){
		return 4;
	}else if( sum == 10 ){
		return 5;
	}else{
		printf(" 15 ΛΟΛ \n");
		//exit(a+b+c);
		return 5;
	}

}




/*
* 	ΚΑΝΟΝΑΣ: ΟΛΟΚΛΗΡΩΜΕΝΟΣ
*/
char* RULE_ONE(struct dataB *data){

    char *wordSyllabus = NULL;

    if(data->IfirstFonien == 1 && data->IfirstSymbol == 2 && data->IsecondFonien == 3){
	    if(data->firstFonien != NULL && data->firstSymbol != NULL && data->secondFonien != NULL){ 
	        
	        wordSyllabus = calloc(256, sizeof(char));

	        strcat(wordSyllabus, data->firstFonien);
	        strcat(wordSyllabus, "-");
	        strcat(wordSyllabus, data->firstSymbol);
	        strcat(wordSyllabus, data->secondFonien);
			strcat(wordSyllabus, "-");

	    }
	}

    return wordSyllabus; 

}

char* RULE_TWO(struct dataB *data){

    char *wordSyllabus = NULL;

    if(data->firstFonien != NULL && data->secondFonien != NULL){

       	if( (strcmp(data->firstFonien, "ι") == 0) ){
       		// ι - α
       		if ( strcmp(data->secondFonien, "α") == 0 ){ 
        
		        wordSyllabus = calloc(256, sizeof(char));
		        if(data->IfirstSymbol == 1)
		        	strcat(wordSyllabus, data->firstSymbol);
		        strcat(wordSyllabus, data->firstFonien);
		        strcat(wordSyllabus, data->secondFonien);
	    	// ι - ά
		    }else if( strcmp(data->secondFonien, "ά") == 0 ){ 
	        
		        wordSyllabus = calloc(256, sizeof(char));

		        if(data->IfirstSymbol == 1)
		        	strcat(wordSyllabus, data->firstSymbol);
		        strcat(wordSyllabus, data->firstFonien);
		        strcat(wordSyllabus, data->secondFonien);
		    }
	    
       	}else if( strcmp(data->firstFonien, "α") == 0 ){ 
        	// α - ι
        	if( strcmp(data->secondFonien, "ι") == 0 ){
        		wordSyllabus = calloc(256, sizeof(char));

        		if(data->IfirstSymbol == 1)
		        	strcat(wordSyllabus, data->firstSymbol);
		        strcat(wordSyllabus, data->firstFonien);
		        strcat(wordSyllabus, data->secondFonien);
		    // α - ί    
        	}else if( strcmp(data->secondFonien, "ί") == 0 ){ 
        
		        wordSyllabus = calloc(256, sizeof(char));

		        if(data->IfirstSymbol == 1)
		        	strcat(wordSyllabus, data->firstSymbol);
		        strcat(wordSyllabus, data->firstFonien);
		        strcat(wordSyllabus, data->secondFonien);
	    	// α - η
       		}else if( strcmp(data->secondFonien, "η") == 0 ){ 
        
		        wordSyllabus = calloc(256, sizeof(char));

		        if(data->IfirstSymbol == 1)
		        	strcat(wordSyllabus, data->firstSymbol);
		        strcat(wordSyllabus, data->firstFonien);
		        strcat(wordSyllabus, data->secondFonien);
    		// α - ή
	    	}else if( strcmp(data->secondFonien, "ή") == 0 ){ 
        
		        wordSyllabus = calloc(256, sizeof(char));

		        if(data->IfirstSymbol == 1)
		        	strcat(wordSyllabus, data->firstSymbol);
		        strcat(wordSyllabus, data->firstFonien);
		        strcat(wordSyllabus, data->secondFonien);
		    // α - υ
		    }else if( strcmp(data->secondFonien, "υ") == 0 ){ 
	        
		        wordSyllabus = calloc(256, sizeof(char));

		        if(data->IfirstSymbol == 1)
		        	strcat(wordSyllabus, data->firstSymbol);
		        strcat(wordSyllabus, data->firstFonien);
		        strcat(wordSyllabus, data->secondFonien);
	    	// α - ύ
		    }else if( strcmp(data->secondFonien, "ύ") == 0 ){ 
	        
		        wordSyllabus = calloc(256, sizeof(char));

		        if(data->IfirstSymbol == 1)
		        	strcat(wordSyllabus, data->firstSymbol);
		        strcat(wordSyllabus, data->firstFonien);
		        strcat(wordSyllabus, data->secondFonien);
		    }

		// ε - ι
	    }else if( strcmp(data->secondFonien, "ε") == 0 ){ 
        	
        	if( strcmp(data->secondFonien, "ι") == 0 ){ 
		        wordSyllabus = calloc(256, sizeof(char));

		        if(data->IfirstSymbol == 1)
		        	strcat(wordSyllabus, data->firstSymbol);
		        strcat(wordSyllabus, data->firstFonien);
		        strcat(wordSyllabus, data->secondFonien);
	    	// ε - ί
		    }else if( strcmp(data->secondFonien, "ί") == 0 ){ 
	        
		        wordSyllabus = calloc(256, sizeof(char));

		        if(data->IfirstSymbol == 1)
		        	strcat(wordSyllabus, data->firstSymbol);
		        strcat(wordSyllabus, data->firstFonien);
		        strcat(wordSyllabus, data->secondFonien);
		    // ε - υ
		    }else if( strcmp(data->secondFonien, "υ") == 0 ){ 
	        
		        wordSyllabus = calloc(256, sizeof(char));

		        if(data->IfirstSymbol == 1)
		        	strcat(wordSyllabus, data->firstSymbol);
		        strcat(wordSyllabus, data->firstFonien);
		        strcat(wordSyllabus, data->secondFonien);
	    	// ε - ύ
		    }else if( strcmp(data->secondFonien, "ύ") == 0 ){ 
	        
		        wordSyllabus = calloc(256, sizeof(char));

		        if(data->IfirstSymbol == 1)
		        	strcat(wordSyllabus, data->firstSymbol);
		        strcat(wordSyllabus, data->firstFonien);
		        strcat(wordSyllabus, data->secondFonien);
		    }

		// υ - ι
	    }else if( strcmp(data->secondFonien, "υ") == 0 ){ 
        	
        	if( strcmp(data->secondFonien, "ι") == 0 ){ 
		        wordSyllabus = calloc(256, sizeof(char));

		        if(data->IfirstSymbol == 1)
		        	strcat(wordSyllabus, data->firstSymbol);
		        strcat(wordSyllabus, data->firstFonien);
		        strcat(wordSyllabus, data->secondFonien);
	    	// υ - ί
		    }else if( strcmp(data->secondFonien, "ί") == 0 ){ 
	        
		        wordSyllabus = calloc(256, sizeof(char));

		        if(data->IfirstSymbol == 1)
		        	strcat(wordSyllabus, data->firstSymbol);
		        strcat(wordSyllabus, data->firstFonien);
		        strcat(wordSyllabus, data->secondFonien);
		    // υ - α
		    }else if( strcmp(data->secondFonien, "α") == 0 ){ 
	        
		        wordSyllabus = calloc(256, sizeof(char));

		        if(data->IfirstSymbol == 1)
		        	strcat(wordSyllabus, data->firstSymbol);
		        strcat(wordSyllabus, data->firstFonien);
		        strcat(wordSyllabus, data->secondFonien);
	    	// υ - ά
		    }else if( strcmp(data->secondFonien, "ά") == 0 ){ 
	        
		        wordSyllabus = calloc(256, sizeof(char));

		        if(data->IfirstSymbol == 1)
		        	strcat(wordSyllabus, data->firstSymbol);
		        strcat(wordSyllabus, data->firstFonien);
		        strcat(wordSyllabus, data->secondFonien);
		    }

	    // η - υ
	    }else if( strcmp(data->secondFonien, "η") == 0 ){ 
        	
        	if( strcmp(data->secondFonien, "υ") == 0 ){ 
		        wordSyllabus = calloc(256, sizeof(char));

		        if(data->IfirstSymbol == 1)
		        	strcat(wordSyllabus, data->firstSymbol);
		        strcat(wordSyllabus, data->firstFonien);
		        strcat(wordSyllabus, data->secondFonien);
	    	// η - ύ
		    }else if( strcmp(data->secondFonien, "ύ") == 0 ){ 
	        
		        wordSyllabus = calloc(256, sizeof(char));

		        if(data->IfirstSymbol == 1)
		        	strcat(wordSyllabus, data->firstSymbol);
		        strcat(wordSyllabus, data->firstFonien);
		        strcat(wordSyllabus, data->secondFonien);
		    }
	    // ο - υ
	    }else if( strcmp(data->secondFonien, "ο") == 0 ){ 
        	
        	if( strcmp(data->secondFonien, "υ") == 0 ){ 
		        wordSyllabus = calloc(256, sizeof(char));

		        if(data->IfirstSymbol == 1)
		        	strcat(wordSyllabus, data->firstSymbol);
		        strcat(wordSyllabus, data->firstFonien);
		        strcat(wordSyllabus, data->secondFonien);
	    	// ο - ύ
		    }else if( strcmp(data->secondFonien, "ύ") == 0 ){ 
	        
		        wordSyllabus = calloc(256, sizeof(char));

		        if(data->IfirstSymbol == 1)
		        	strcat(wordSyllabus, data->firstSymbol);
		        strcat(wordSyllabus, data->firstFonien);
		        strcat(wordSyllabus, data->secondFonien);
		    // ο - ι
		    }else if( strcmp(data->secondFonien, "ι") == 0 ){ 
	        
		        wordSyllabus = calloc(256, sizeof(char));

		        if(data->IfirstSymbol == 1)
		        	strcat(wordSyllabus, data->firstSymbol);
		        strcat(wordSyllabus, data->firstFonien);
		        strcat(wordSyllabus, data->secondFonien);
	    	// ο - ί
		    }else if( strcmp(data->secondFonien, "ί") == 0 ){ 
	        
		        wordSyllabus = calloc(256, sizeof(char));

		        if(data->IfirstSymbol == 1)
		        	strcat(wordSyllabus, data->firstSymbol);
		        strcat(wordSyllabus, data->firstFonien);
		        strcat(wordSyllabus, data->secondFonien);
		    }

    	// ό - ι
	    }else if( strcmp(data->secondFonien, "ό") == 0 && 
	    			strcmp(data->secondFonien, "ι") == 0 ){ 
        
	        wordSyllabus = calloc(256, sizeof(char));
	       
	        if(data->IfirstSymbol == 1)
		        strcat(wordSyllabus, data->firstSymbol);
	        strcat(wordSyllabus, data->firstFonien);
	        strcat(wordSyllabus, data->secondFonien);
	    }

    }

    return wordSyllabus; 

}

char* RULE_THREE(struct dataB *data){ 

	if(data->IfirstFonien == 1 && data->IsecondFonien == 4){ 
		if(data->IfirstSymbol == 2 && data->IsecondSymbol == 3){ 
			// Κανόνας για το αν δεν αρχίζει ελληνική λέξη
			if(    (strcmp(data->firstSymbol, "ρ") == 0 && strcmp(data->secondSymbol, "χ") == 0)  
				|| (strcmp(data->firstSymbol, "χ") == 0 && strcmp(data->secondSymbol, "κ") == 0) 
				|| (strcmp(data->firstSymbol, "χ") == 0 && strcmp(data->secondSymbol, "π") == 0) 
				|| (strcmp(data->firstSymbol,                     data->secondSymbol	 ) == 0) 
				|| (strcmp(data->firstSymbol, "φ") == 0 && strcmp(data->secondSymbol, "π") == 0) 
				|| (strcmp(data->firstSymbol, "π") == 0 && strcmp(data->secondSymbol, "φ") == 0) 
				|| (strcmp(data->firstSymbol, "ρ") == 0 && strcmp(data->secondSymbol, "γ") == 0) ){
				
				char *wordSyllabus = calloc(256, sizeof(char));

				strcat(wordSyllabus, data->firstFonien);
				strcat(wordSyllabus, data->firstSymbol);
		        strcat(wordSyllabus, "-");
		        strcat(wordSyllabus, data->secondSymbol);
		        strcat(wordSyllabus, data->secondFonien);
				strcat(wordSyllabus, "-");

				return wordSyllabus ;

			}

			char *wordSyllabus = calloc(256, sizeof(char));

			strcat(wordSyllabus, data->firstFonien);
	        strcat(wordSyllabus, "-");
			strcat(wordSyllabus, data->firstSymbol);
	        strcat(wordSyllabus, data->secondSymbol);
	        strcat(wordSyllabus, data->secondFonien);

			return wordSyllabus ;

		}
	}

	return NULL ;

}

char* RULE_FOUR(struct dataB *data){
    
    if(data->IfirstFonien == 1 && data->IsecondFonien == 5){ 
		if(data->IfirstSymbol == 2 && data->IsecondSymbol == 3 && data->IsecondSymbol == 3){
			// Κανόνας για το αν δεν αρχίζει ελληνική λέξη
			if(    (strcmp(data->firstSymbol, "ρ") == 0 && strcmp(data->secondSymbol, "χ") == 0)  
				|| (strcmp(data->firstSymbol, "χ") == 0 && strcmp(data->secondSymbol, "κ") == 0) 
				|| (strcmp(data->firstSymbol, "χ") == 0 && strcmp(data->secondSymbol, "π") == 0) 
				|| (strcmp(data->firstSymbol,                     data->secondSymbol	 ) == 0) 
				|| (strcmp(data->firstSymbol, "φ") == 0 && strcmp(data->secondSymbol, "π") == 0) 
				|| (strcmp(data->firstSymbol, "π") == 0 && strcmp(data->secondSymbol, "φ") == 0) 
				|| (strcmp(data->firstSymbol, "ρ") == 0 && strcmp(data->secondSymbol, "γ") == 0) ){
				
				char *wordSyllabus = calloc(256, sizeof(char));

				strcat(wordSyllabus, data->firstFonien);
				strcat(wordSyllabus, data->firstSymbol);
		        strcat(wordSyllabus, "-");
		        strcat(wordSyllabus, data->secondSymbol);
	        	strcat(wordSyllabus, data->thirdSymbol);
		        strcat(wordSyllabus, data->secondFonien);
				strcat(wordSyllabus, "-");

				return wordSyllabus ;

			}

			char *wordSyllabus = calloc(256, sizeof(char));

			strcat(wordSyllabus, data->firstFonien);
	        strcat(wordSyllabus, "-");
			strcat(wordSyllabus, data->firstSymbol);
	        strcat(wordSyllabus, data->secondSymbol);
	        strcat(wordSyllabus, data->thirdSymbol);
	        strcat(wordSyllabus, data->secondFonien);

			return wordSyllabus ;

		}
	}

	return NULL ;

}

char* RULE_FIVE(struct dataB *data){
	
	if(data->IfirstSymbol != 0 && data->IsecondSymbol != 0){ printf("1\n");
		if(strcmp(data->firstSymbol, data->secondSymbol) == 0){ printf("1.1\n");
			char *wordSyllabus = calloc(256, sizeof(char));

			/*
			TA PROHGOUMENA
			*/
			for(int l = 0; l < data->IfirstSymbol; l++){
        		
        		if(data->firstFonien != NULL){
        			if(data->IfirstFonien == l){
        				strcat(wordSyllabus, data->firstFonien);
        			}
        		}else if(data->secondFonien != NULL){
        			if(data->IsecondFonien == l){
        				strcat(wordSyllabus, data->secondFonien);
        			}
        		}else if(data->thirdFonien != NULL){
        			if(data->IthirdFonien == l){
        				strcat(wordSyllabus, data->thirdFonien);
        			}
        		}else if(data->firstSymbol != NULL){
        			if(data->IfirstSymbol == l){
        				strcat(wordSyllabus, data->firstSymbol);
        			}
        		}else if(data->secondSymbol != NULL){
        			if(data->IsecondSymbol == l){
        				strcat(wordSyllabus, data->secondSymbol);
        			}
        		}else if(data->thirdSymbol != NULL){
        			if(data->IthirdSymbol == l){
        				strcat(wordSyllabus, data->thirdSymbol);
        			}
        		}

        	}
        		/*
			TA PROHGOUMENA
			*/
			strcat(wordSyllabus, data->firstSymbol);
	        strcat(wordSyllabus, "-");
	        strcat(wordSyllabus, data->secondSymbol);
	        /*
			TA EPOMENA
			*/
			for(int l = data->IsecondSymbol; l < 6; l++){
        		
        		if(data->firstFonien != NULL){
        			if(data->IfirstFonien == l){
        				strcat(wordSyllabus, data->firstFonien);
        			}
        		}else if(data->secondFonien != NULL){
        			if(data->IsecondFonien == l){
        				strcat(wordSyllabus, data->secondFonien);
        			}
        		}else if(data->thirdFonien != NULL){
        			if(data->IthirdFonien == l){
        				strcat(wordSyllabus, data->thirdFonien);
        			}
        		}else if(data->firstSymbol != NULL){
        			if(data->IfirstSymbol == l){
        				strcat(wordSyllabus, data->firstSymbol);
        			}
        		}else if(data->secondSymbol != NULL){
        			if(data->IsecondSymbol == l){
        				strcat(wordSyllabus, data->secondSymbol);
        			}
        		}else if(data->thirdSymbol != NULL){
        			if(data->IthirdSymbol == l){
        				strcat(wordSyllabus, data->thirdSymbol);
        			}
        		}

        	}

			return wordSyllabus ;			
		}

    }

    if(data->IsecondSymbol != 0 && data->IthirdSymbol != 0 ){ printf("2\n"); 
    	if(strcmp(data->secondSymbol, data->thirdSymbol) == 0){ printf("2.2\n");
    		char *wordSyllabus = calloc(256, sizeof(char));
    		printf("firstFonien:%s\nfirstSymbol:%s\nsecondFonien:%s\nsecondSymbol:%s\nthirdFonien:%s\nthirdSymbol:%s\n", data->firstFonien, data->firstSymbol, data->secondFonien, data->secondSymbol, data->thirdFonien, data->thirdSymbol);
        	printf("IfirstSymbol:%d\nIfirstSymbol:%d\nsecondFonien:%d\nIsecondSymbol:%d\nIthirdFonien:%d\nIthirdSymbol:%d\n", data->IfirstFonien, data->IfirstSymbol, data->IsecondFonien, data->IsecondSymbol, data->IthirdFonien, data->IthirdSymbol);

    		/*
			TA PROHGOUMENA
			*/

			for(int l = 0; l < data->IsecondSymbol; l++){ printf("l = %d\n", l);
        		
        		if(data->firstFonien != NULL){ printf("1\n");
        			if(data->IfirstFonien == l){  printf("1.1 %s\n", data->firstFonien);
        				strcat(wordSyllabus, data->firstFonien);
        			}
        		}else if(data->secondFonien != NULL){ printf("2\n");
        			if(data->IsecondFonien == l){ printf("2.2 %s\n",data->secondFonien);
        				strcat(wordSyllabus, data->secondFonien);
        			}
        		}else if(data->thirdFonien != NULL){ printf("3\n");
        			if(data->IthirdFonien == l){ printf("3.3 %s\n",data->thirdFonien);
        				strcat(wordSyllabus, data->thirdFonien);
        			}
        		}else if(data->firstSymbol != NULL){ printf("4\n");
        			if(data->IfirstSymbol == l){ printf("4.4 %s\n",data->firstSymbol);
        				strcat(wordSyllabus, data->firstSymbol);
        			}
        		}else if(data->secondSymbol != NULL){ printf("5\n");
        			if(data->IsecondSymbol == l){ printf("5.5 %s\n",data->secondSymbol);
        				strcat(wordSyllabus, data->secondSymbol);
        			}
        		}else if(data->thirdSymbol != NULL){ printf("6\n");
        			if(data->IthirdSymbol == l){ printf("6.6 %s\n",data->thirdSymbol);
        				strcat(wordSyllabus, data->thirdSymbol);
        			}
        		}

        	}
        	/*
			TA PROHGOUMENA
			*/
	        strcat(wordSyllabus, data->secondSymbol);
			strcat(wordSyllabus, "-");
	        strcat(wordSyllabus, data->thirdSymbol);

	         /*
			TA EPOMENA
			*/
			for(int l = data->IthirdSymbol; l < 6; l++){
        		
        		if(data->firstFonien != NULL){
        			if(data->IfirstFonien == l){
        				strcat(wordSyllabus, data->firstFonien);
        			}
        		}else if(data->secondFonien != NULL){
        			if(data->IsecondFonien == l){
        				strcat(wordSyllabus, data->secondFonien);
        			}
        		}else if(data->thirdFonien != NULL){
        			if(data->IthirdFonien == l){
        				strcat(wordSyllabus, data->thirdFonien);
        			}
        		}else if(data->firstSymbol != NULL){
        			if(data->IfirstSymbol == l){
        				strcat(wordSyllabus, data->firstSymbol);
        			}
        		}else if(data->secondSymbol != NULL){
        			if(data->IsecondSymbol == l){
        				strcat(wordSyllabus, data->secondSymbol);
        			}
        		}else if(data->thirdSymbol != NULL){
        			if(data->IthirdSymbol == l){
        				strcat(wordSyllabus, data->thirdSymbol);
        			}
        		}

        	}        	

			return wordSyllabus ;			
		}

	}

    return NULL;

}







int main(int argc, char** argv){

    FILE* f1 = fopen ("wordDatabaseSource/OpenOffice.txt", "r");
    if(!f1){ printf("ERROR f1"); exit(1); }

    FILE* f2 = fopen ("wordDatabaseSource/OpenOfficeMurtakis.txt", "r");
    if(!f2){ printf("ERROR f2"); exit(1); }

    FILE* f3 = fopen ("wordDatabaseFinal/OpenOfficeSyllabes.txt", "w+");
    if(!f3){ printf("ERROR f3"); exit(1); }

    struct dataB *data = calloc (1, sizeof(struct dataB));
    char word[256], bufferA[255], bufferB[255], FINAL[256], subbuff[5];
	char *firstFonien = NULL, *secondFonien = NULL, *thirdFonien = NULL;
    char *firstSymbol = NULL, *secondSymbol = NULL, *thirdSymbol = NULL;
    int IfirstFonien = 0, IsecondFonien = 0, IthirdFonien = 0;
    int IfirstSymbol = 0, IsecondSymbol = 0, IthirdSymbol = 0;
    int i, found, length;

    // strcpy(word, "καραγκιόζης");
    strcpy(word, "φεγγάρι");

    firstFonien = NULL, firstSymbol = NULL;
    secondFonien = NULL, secondSymbol = NULL;
    i = 0, length = strlen(word);

    while ( i < length ) {

    	found  = 0;
        memcpy( subbuff, &word[i], 2 ); subbuff[3] = '\0';

        // FIND THE LETTER 
        // για καποιο λογο ενω ειναι διαφορετικα τα ιντς τα μικρα και τα μεγαλα κανουν ματς
        for(int j=0; j<14; j++){
            // printf("%d) '%s%d%d' == '%s%d%d'\n", j, mikraFonienta[j], mikraFonienta[j][0], mikraFonienta[j][1], subbuff, subbuff[0], subbuff[1]);
            if(mikraFonienta[j][0] == subbuff[0] && mikraFonienta[j][1] == subbuff[1]){ //printf(" same \n");
                if(firstFonien == NULL){ 
                	IfirstFonien = getSort(IfirstSymbol, IsecondSymbol, IthirdSymbol, IsecondFonien, IthirdFonien);
                    firstFonien = strdup(subbuff);
                }else if(secondFonien == NULL){ 
                	IsecondFonien = getSort(IfirstSymbol, IsecondSymbol, IthirdSymbol,  IfirstFonien, IthirdFonien);
                    secondFonien = strdup(subbuff);
                }else if(thirdFonien == NULL){ 
                	IthirdFonien = getSort(IfirstSymbol, IsecondSymbol, IthirdSymbol, IfirstFonien, IsecondFonien);
                    thirdFonien = strdup(subbuff);
                }
                found = 1;
                break;
            }
        }
        if(found != 1){

	        for(int j=0; j<18; j++){
	            // printf("%d) '%s%d%d' == '%s%d%d'\n", j,  mikraSymbola[j], mikraSymbola[j][0], mikraSymbola[j][1], subbuff, subbuff[0], subbuff[1]);
	            if(mikraSymbola[j][0] == subbuff[0] && mikraSymbola[j][1] == subbuff[1]){ //printf(" same \n");
	                if(firstSymbol == NULL){  
	                	IfirstSymbol = getSort(IfirstFonien, IsecondFonien, IthirdFonien, IsecondSymbol, IthirdSymbol); 
	                    firstSymbol = strdup(subbuff); 
	                }else if(secondSymbol == NULL){  
	                	IsecondSymbol = getSort(IfirstFonien, IsecondFonien, IthirdFonien, IfirstSymbol, IthirdSymbol); 
	                    secondSymbol = strdup(subbuff); 
	                }else{ 
	                	IthirdSymbol = getSort(IfirstFonien, IsecondFonien, IthirdFonien, IfirstSymbol, IsecondSymbol); 
	                    thirdSymbol = strdup(subbuff); 
	                }
	                found = 1;
	                break;
	            }
	        }
	        if(found != 1){

		        for(int j=0; j<14; j++){
		            // printf("%d) '%s%d%d' == '%s%d%d'\n", j, megalaFonienta[j], megalaFonienta[j][0], megalaFonienta[j][1], subbuff, subbuff[0], subbuff[1]);
		            if(megalaFonienta[j][0] == subbuff[0] && megalaFonienta[j][1] == subbuff[1]){ //printf(" same \n");
		                if(firstFonien == NULL){ 
		                	IfirstFonien = getSort(IfirstSymbol, IsecondSymbol, IthirdSymbol, IsecondFonien, IthirdFonien);
		                    firstFonien = strdup(subbuff);
		                }else if(secondFonien == NULL){ 
		                	IsecondFonien = getSort(IfirstSymbol, IsecondSymbol, IthirdSymbol,  IfirstFonien, IthirdFonien);
		                    secondFonien = strdup(subbuff);
		                }else if(thirdFonien == NULL){ 
		                	IthirdFonien = getSort(IfirstSymbol, IsecondSymbol, IthirdSymbol, IfirstFonien, IsecondFonien);
		                    thirdFonien = strdup(subbuff);
		                }
		                found = 1;
		                break;
		            }
		        }
		        if(found != 1){

			        for(int j=0; j<17; j++){
			            // printf("%d) '%s%d%d' == '%s%d%d'\n", j,  megalaSymbola[j], megalaSymbola[j][0], megalaSymbola[j][1], subbuff, subbuff[0], subbuff[1]);
			            if(mikraSymbola[j][0] == subbuff[0] && mikraSymbola[j][1] == subbuff[1]){ //printf(" same \n");
			                if(firstSymbol == NULL){ 
			                	IfirstSymbol = getSort(IfirstFonien, IsecondFonien, IthirdFonien, IsecondSymbol, IthirdSymbol); 
			                    firstSymbol = strdup(subbuff); 
			                }else if(secondSymbol == NULL){ 
			                	IsecondSymbol = getSort(IfirstFonien, IsecondFonien, IthirdFonien, IfirstSymbol, IthirdSymbol); 
			                    secondSymbol = strdup(subbuff); 
			                }else{
			                	IthirdSymbol = getSort(IfirstFonien, IsecondFonien, IthirdFonien, IfirstSymbol, IsecondSymbol); 
			                    thirdSymbol = strdup(subbuff); 
			                }
			                found = 1;
			                break;
			            }
			        }
		        }
	        }
	    }
        
        data->firstFonien = firstFonien;	data->IfirstFonien = IfirstFonien;
        data->secondFonien = secondFonien;	data->IsecondFonien = IsecondFonien;
        data->thirdFonien = thirdFonien;	data->IthirdFonien = IthirdFonien;

        data->firstSymbol = firstSymbol;	data->IfirstSymbol = IfirstSymbol;
        data->secondSymbol = secondSymbol;	data->IsecondSymbol = IsecondSymbol;
        data->thirdSymbol = thirdSymbol;	data->IthirdSymbol = IthirdSymbol;
		
		printf("[%s,\t%s,\t%s,\t%s,\t%s,\t%s]\n", firstFonien, firstSymbol, secondFonien, secondSymbol, thirdFonien, thirdSymbol);
        printf("[%d,\t%d,\t%d,\t%d,\t%d,\t%d]\n", IfirstFonien, IfirstSymbol, IsecondFonien, IsecondSymbol, IthirdFonien, IthirdSymbol);
        // printf("%s-%s-%s-%s-%s-%s\n", data->firstFonien, data->firstSymbol, data->secondFonien, data->secondSymbol, data->thirdFonien, data->thirdSymbol);
        // printf("%d-%d-%d-%d-%d-%d\n", data->IfirstFonien, data->IfirstSymbol, data->IsecondFonien, data->IsecondSymbol, data->IthirdFonien, data->IthirdSymbol);

        if(RULE_FIVE(data) != NULL){ printf("RULE_FIVE\n");

            strcat(FINAL , RULE_FIVE(data));
            
            if(strcmp(firstSymbol, secondSymbol) == 0){
            	firstFonien = NULL; firstSymbol = NULL;
            	secondFonien = NULL; secondSymbol = NULL;
            	IfirstFonien = 0; IfirstSymbol = 0;
            	IsecondFonien = 0; IsecondSymbol = 0;
            }
			if(strcmp(secondSymbol, thirdSymbol) == 0){
				secondFonien = NULL; secondSymbol = NULL;
				thirdFonien = NULL; thirdSymbol = NULL;
				IsecondFonien = 0; IsecondSymbol = 0;
				IthirdFonien = 0; IthirdSymbol = 0;
			}
            
        }else if(RULE_ONE(data) != NULL){ printf("RULE_ONE\n");
            
            strcat(FINAL , RULE_ONE(data));
            
            firstFonien = NULL, firstSymbol = NULL;
            secondFonien = NULL, secondSymbol = NULL;
            thirdFonien = NULL, thirdSymbol = NULL;
            IfirstFonien = 0; IfirstSymbol = 0;
            IsecondFonien = 0; IsecondSymbol = 0;
            IthirdFonien = 0; IthirdSymbol = 0;
        
        }else if(RULE_FOUR(data) != NULL){ printf("RULE_FOUR\n");
            
            strcat(FINAL , RULE_FOUR(data));
            
            firstFonien = NULL, firstSymbol = NULL;
            secondFonien = NULL, secondSymbol = NULL;
            IfirstFonien = 0; IfirstSymbol = 0;
            IsecondFonien = 0; IsecondSymbol = 0;
        
        }else if(RULE_THREE(data) != NULL){ printf("RULE_THREE\n");
            
            strcat(FINAL , RULE_THREE(data));
            
            firstFonien = NULL, firstSymbol = NULL;
            secondFonien = NULL, secondSymbol = NULL;
            IfirstFonien = 0; IfirstSymbol = 0;
            IsecondFonien = 0; IsecondSymbol = 0;
        
        }else if(RULE_TWO(data) != NULL){ printf("RULE_TWO\n");
            
            strcat(FINAL , RULE_TWO(data));
            
            firstFonien = NULL, firstSymbol = NULL;
            secondFonien = NULL, secondSymbol = NULL;
            thirdFonien = NULL, thirdSymbol = NULL;
            IfirstFonien = 0; IfirstSymbol = 0;
            IsecondFonien = 0; IsecondSymbol = 0;
            IthirdFonien = 0; IthirdSymbol = 0;
        
        }else if(length-2 == i){ // last thing no rule to be applied
        	printf("mpika else\n");
        	printf("[%s,\t%s,\t%s,\t%s,\t%s,\t%s]\n", firstFonien, firstSymbol, secondFonien, secondSymbol, thirdFonien, thirdSymbol);
        	printf("[%d,\t%d,\t%d,\t%d,\t%d,\t%d]\n", IfirstFonien, IfirstSymbol, IsecondFonien, IsecondSymbol, IthirdFonien, IthirdSymbol);
        	for(int l = 0; l < 6; l++){
        		
        		if(firstFonien != NULL){
        			if(IfirstFonien == l){
        				strcat(FINAL, firstFonien);
        				IfirstFonien = 0;
        				firstFonien = NULL;
        			}
        		}else if(secondFonien != NULL){
        			if(IsecondFonien == l){
        				strcat(FINAL, secondFonien);
        				IsecondFonien = 0;
        				secondFonien = NULL;
        			}
        		}else if(thirdFonien != NULL){
        			if(IthirdFonien == l){
        				strcat(FINAL, thirdFonien);
        				IthirdFonien = 0;
        				thirdFonien = NULL;
        			}
        		}else if(firstSymbol != NULL){
        			if(IfirstSymbol == l){
        				strcat(FINAL, firstSymbol);
        				IfirstSymbol = 0;
        				firstSymbol = NULL;
        			}
        		}else if(secondSymbol != NULL){
        			if(IsecondSymbol == l){
        				strcat(FINAL, secondSymbol);
        				IsecondSymbol = 0;
        				secondSymbol = NULL;
        			}
        		}else if(thirdSymbol != NULL){
        			if(IthirdSymbol == l){
        				strcat(FINAL, thirdSymbol);
        				IthirdSymbol = 0;
        				thirdSymbol = NULL;
        			}
        		}

        	}
        	printf("vgika else\n");
        	printf("[%s,\t%s,\t%s,\t%s,\t%s,\t%s]\n", firstFonien, firstSymbol, secondFonien, secondSymbol, thirdFonien, thirdSymbol);
        	printf("[%d,\t%d,\t%d,\t%d,\t%d,\t%d]\n", IfirstFonien, IfirstSymbol, IsecondFonien, IsecondSymbol, IthirdFonien, IthirdSymbol);

        }

        i += 2;
    
    }
    
    printf("FINAL: %s\n", FINAL);
    






    // while (fgets(bufferA, 255, f1)!= NULL){
    //     strtok(bufferA,"\n"); 
    //     printf("bufferA %s\n", bufferA);

    // }

    // while (fgets(bufferB, 255, f2)!= NULL){
    //     strtok(bufferA,"\n"); 
    //      printf("bufferB %s\n", bufferB);

    // }

    fclose(f1);
    fclose(f2);
    fclose(f3);

    return 0;
}