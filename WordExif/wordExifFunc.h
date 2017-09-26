#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordExifStruct.h"

#define UNDER  "\033[4m"
#define DEUNDER "\033[0m"

char *deleteSlashN(char* withSlashN){
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

// #0
void printRima(char* rima){

  int  Xronos, Prosopos, Arithmos, Klisi, Foni;
  char *word;

      strtok(rima, "|");
  word    = strtok(NULL, "|");
      strtok(NULL, "|");
      strtok(NULL, "|");
      strtok(NULL, "|");

  Xronos  = toInt(strtok(NULL, "|"));
  Prosopos  = toInt(strtok(NULL, "|"));
  Arithmos  = toInt(strtok(NULL, "|"));
  Klisi   = toInt(strtok(NULL, "|"));
  Foni    = toInt(strtok(NULL, "|"));

  printf("Η λέξη ");
  printf(UNDER "%s" DEUNDER, word);
  printf(" είναι ρήμα, %s πρόσωπο %s %s, %s φώνης, %s κλίσης.\n\n", prosopo[Prosopos], arithmos[Arithmos], xronos[Xronos], foni[Foni], klisi[Klisi]);

}

// #1
void printEpitheto(char* epitheto){

  int  Genos, Arithmos, Ptosi;
  char *word;

              strtok(epitheto, "|");
  word      = strtok(NULL, "|");
              strtok(NULL, "|");
              strtok(NULL, "|");
        strtok(NULL, "|");

  Genos   = toInt(strtok(NULL, "|"));
  Arithmos  = toInt(strtok(NULL, "|"));
  Ptosi   = toInt(strtok(NULL, "|"));

  printf("Η λέξη ");
  printf(UNDER "%s" DEUNDER, word);
  printf(" είναι επίθετο, %s αριθμου , γένος %s , %s πτώση.\n\n", arithmos[Arithmos], genos[Genos], ptosi[Ptosi]);

}

// #2
void printOusiastiko(char* ousiastiko){

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

  printf("Η λέξη ");
  printf(UNDER "%s" DEUNDER, word);
  printf(" είναι ουσιαστικό, %s αριθμου , γένος %s , %s πτώση.\n\n", arithmos[Arithmos], genos[Genos], ptosi[Ptosi]);

}

// #3
void printMetoxi(char* metoxi){

  strtok(metoxi, "|");
  char *word  = strtok(NULL, "|");

  printf("Η λέξη ");
  printf(UNDER "%s" DEUNDER, word);
  printf(" είναι μετοχή.\n\n");

}

// #4
void printArithmitika(char* arithmitika){

  strtok(arithmitika, "|");
  char *word  = strtok(NULL, "|");
            strtok(NULL, "|");
            strtok(NULL, "|");
            strtok(NULL, "|");

  int actualNum = toInt(strtok(NULL, "|"));

  printf("Η λέξη ");
  printf(UNDER "%s" DEUNDER, word);
  printf(" είναι αριθμητικό, με πραματική τιμή: %d.\n\n", actualNum);

}

// #5
void printEpirima(char* epirima){

  int  Katigoria;
  char *word;

              strtok(epirima, "|");
  word      = strtok(NULL, "|");
              strtok(NULL, "|");
              strtok(NULL, "|");
              strtok(NULL, "|");

  Katigoria = toInt(strtok(NULL, "|"));

  printf("Η λέξη ");
  printf(UNDER "%s" DEUNDER, word);
  printf(" είναι %s επίρρημα.\n\n", epirimata[Katigoria]); // trollarei i c koita to c -> s

}

// #6
void printSundesmo(char* sundesmo){

  int  Katigoria;
  char *word;

              strtok(sundesmo, "|");
  word      = strtok(NULL, "|");
              strtok(NULL, "|");
              strtok(NULL, "|");
              strtok(NULL, "|");

  Katigoria = toInt(strtok(NULL, "|"));

  printf("Η λέξη ");
  printf(UNDER "%s" DEUNDER, word);
  printf(" είναι %s σύνδεσμος.\n\n", sundesmos[Katigoria]); // trollarei i c koita to c -> s

}

// #7
void printAntonimia(char* antonimia){

  strtok(antonimia, "|");
  char *word  = strtok(NULL, "|");

  printf("Η λέξη ");
  printf(UNDER "%s" DEUNDER, word);
  printf(" είναι αντωνυμία.\n\n");

}

// a k r a i o 
typedef void (*f)(char*); 
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


