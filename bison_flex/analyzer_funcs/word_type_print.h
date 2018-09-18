#include "word_syllab_arrays.h"


char *delete_slash_n(char* withSlashN){
  strtok(withSlashN, "\n");
  return withSlashN;

}

int toInt(char a[]) {
  int c, sign, offset, n;
 
  if (a[0] == '-') {  // Handle negative integers
    sign = -1;
  }else{
    sign = 0;
  }
 
  if (sign == -1) {  // Set starting position to convert
    offset = 1;
  }
  else {
    offset = 0;
  }
 
  n = 0;
 
  for (c = offset; a[c] != '\0'; c++) {
    n = n * 10 + a[c] - '0';
  }
 
  if (sign == -1) {
    n = -n;
  }
 
  return n;

}

/*
* Κάνει το πρώτο κεφαλαίο γράμμα
* σε μικρό, διότι η λέξεις τις 
* βάσεις είναι σε μικρά
*/
char* capToSmall(char* wordInput){

    char* oldWordInput = calloc(16,sizeof(char));

    for(int i = 0; i < 31; i++){

        if(strncmp(megala[i], wordInput, strlen(megala[i])) == 0){
            strcpy(oldWordInput, wordInput);
            strcpy(wordInput, mikra[i]);
            strncat(wordInput, oldWordInput + 2, strlen(oldWordInput)+1 - 1);
            break;
        }
        
    };

    return wordInput;

}

// #0
void printRima(char* rima, char* isCap){

  int  Xronos, Prosopos, Arithmos, Klisi, Foni;
  char *word;

      strtok(rima, "|");
  word    = strtok(NULL, "|");
      strtok(NULL, "|");
      strtok(NULL, "|");
      strtok(NULL, "|");

  Xronos    = toInt(strtok(NULL, "|"));
  Prosopos  = toInt(strtok(NULL, "|"));
  Arithmos  = toInt(strtok(NULL, "|"));
  Klisi     = toInt(strtok(NULL, "|"));
  Foni      = toInt(strtok(NULL, "|"));

  if(isCap){
    printf("%s (" , isCap);
    printf(a_c_c italic bold "ρήμα, %s πρόσωπο %s %s, %s φώνης, %s κλίσης"DEUNDER, prosopo[Prosopos], arithmos[Arithmos], xronos[Xronos], foni[Foni], klisi[Klisi]);
    printf(") ");
  }else{
    printf("%s (" , word);
    printf(a_c_c italic bold "ρήμα, %s πρόσωπο %s %s, %s φώνης, %s κλίσης"DEUNDER, prosopo[Prosopos], arithmos[Arithmos], xronos[Xronos], foni[Foni], klisi[Klisi]);
    printf(") ");
  }

}

// #1
void printEpitheto(char* epitheto, char* isCap){

  int  Genos, Arithmos, Ptosi;
  char *word;

              strtok(epitheto, "|");
  word      = strtok(NULL, "|");
              strtok(NULL, "|");
              strtok(NULL, "|");
        strtok(NULL, "|");

  Genos     = toInt(strtok(NULL, "|"));
  Arithmos  = toInt(strtok(NULL, "|"));
  Ptosi     = toInt(strtok(NULL, "|"));

  if(isCap){
    printf("%s (" , isCap);
    printf(a_c_c italic bold "επίθετο, %s αριθμου, γένος %s, %s πτώση"DEUNDER, arithmos[Arithmos], genos[Genos], ptosi[Ptosi]);
    printf(") ");
  }else{
    printf("%s (" , word);
    printf(a_c_c italic bold "επίθετο, %s αριθμου, γένος %s, %s πτώση"DEUNDER, arithmos[Arithmos], genos[Genos], ptosi[Ptosi]);
    printf(") ");
  }

}

// #2
void printOusiastiko(char* ousiastiko, char* isCap){

  int  Genos, Arithmos, Ptosi;
  char *word;

              strtok(ousiastiko, "|");
  word      = strtok(NULL, "|");
              strtok(NULL, "|");
              strtok(NULL, "|");
              strtok(NULL, "|");

  Genos     = toInt(strtok(NULL, "|"));
  Arithmos  = toInt(strtok(NULL, "|"));
  Ptosi     = toInt(strtok(NULL, "|"));
  
  if(isCap){
    printf("%s (" , isCap);
    printf(a_c_c italic bold "ουσιαστικό, %s αριθμού, γένος %s, %s πτώση"DEUNDER, arithmos[Arithmos], genos[Genos], ptosi[Ptosi]);
    printf(") ");
  }else{
    printf("%s (" , word);
    printf(a_c_c italic bold "ουσιαστικό, %s αριθμού, γένος %s, %s πτώση"DEUNDER, arithmos[Arithmos], genos[Genos], ptosi[Ptosi]);
    printf(") ");
  }

}

// #3
void printMetoxi(char* metoxi, char* isCap){

  strtok(metoxi, "|");
  char *word  = strtok(NULL, "|");

  if(isCap){
    printf("%s (" , isCap);
    printf(a_c_c italic bold "μετοχή" DEUNDER);
    printf(") ");
  }else{
    printf("%s (" , word);
    printf(a_c_c italic bold "μετοχή" DEUNDER);
    printf(") ");
  } 

}

// #4
void printArithmitika(char* arithmitika, char* isCap){

  strtok(arithmitika, "|");
  char *word  = strtok(NULL, "|");
            strtok(NULL, "|");
            strtok(NULL, "|");
            strtok(NULL, "|");

  int actualNum = toInt(strtok(NULL, "|"));

  if(isCap){
    printf("%s (", isCap);
    printf(a_c_c italic bold "αριθμητικό, με πραματική τιμή: %d"DEUNDER, actualNum);
    printf(") ");
  }else{
    printf("%s (", word);
    printf(a_c_c italic bold "αριθμητικό, με πραματική τιμή: %d"DEUNDER, actualNum);
    printf(") ");
  }

}

// #5
void printEpirima(char* epirima, char* isCap){

  int  Katigoria;
  char *word;

              strtok(epirima, "|");
  word      = strtok(NULL, "|");
              strtok(NULL, "|");
              strtok(NULL, "|");
              strtok(NULL, "|");

  Katigoria = toInt(strtok(NULL, "|"));

  if(isCap){
    printf("%s (", isCap);
    printf(a_c_c italic bold "%s επίρρημα"DEUNDER, epirimata[Katigoria]);
    printf(") ");
  }else{
    printf("%s (", word);
    printf(a_c_c italic bold "%s επίρρημα"DEUNDER, epirimata[Katigoria]);
    printf(") ");
  }

}

// #6
void printSundesmo(char* sundesmo, char* isCap){

  int  Katigoria;
  char *word;

              strtok(sundesmo, "|");
  word      = strtok(NULL, "|");
              strtok(NULL, "|");
              strtok(NULL, "|");
              strtok(NULL, "|");

  Katigoria = toInt(strtok(NULL, "|"));

  if(isCap){
    printf("%s (", isCap);
    printf(a_c_c italic bold "%s σύνδεσμος"DEUNDER, sundesmos[Katigoria]);
    printf(") ");
  }else{  
    printf("%s (", word);
    printf(a_c_c italic bold "%s σύνδεσμος"DEUNDER, sundesmos[Katigoria]);
    printf(") ");
  }

}

// #7
void printAntonimia(char* antonimia, char* isCap){

  strtok(antonimia, "|");
  char *word  = strtok(NULL, "|");
  
  if(isCap){
    printf("%s (", isCap);
    printf(a_c_c italic bold "αντωνυμία"DEUNDER);
    printf(") ");
  }else{  
    printf("%s (", word);
    printf(a_c_c italic bold "αντωνυμία"DEUNDER);
    printf(") ");
  }

}

// a k r a i o 
typedef void (*f)(char*, char*); 
f functionPrinter[8] = {
  &printRima,
  &printEpitheto,
  &printOusiastiko,
  &printMetoxi,
  &printArithmitika, 
  &printEpirima,
  &printSundesmo,
  &printAntonimia
 }; 
// a k r a i o 


