#include "functionsForXronous.h"

char *energEndingArrayOristikiYpotaktiki[] = {

    "ω",
    "εις",
    "ει",
    "ουμε",
    "ετε",
    "ουν",
    "ουνε"

};

char *energEndingArrayProstaktiki[] = {

    "ε",
    "ετε"

};

char *pathEndingArrayOristikiYpotaktiki[] = {

    "ομαι",
    "εσαι",
    "εται",
    "όμαστε",
    "εστε",
    "όσαστε",
    "ονται"

};

char *pathEndingArrayProstaktiki[] = {

    "ου",
    "εστε"

};

char *energParatatikosOristiki[] = {

    "α",
    "ες",
    "ε",
    "αμε",
    "ατε",
    "αν",
    "ανε"

};

char *pathParatatikosOristiki[] = {

    "όμουν","όμουνα",
    "όσουν","όσουνα",
    "όταν","ότανε",
    "όμασταν","όμαστε",
    "όσασταν","όσαστε",
    "ονταν","όντουσαν"

};

struct katalixis* bufferKatalixis(struct katalixis* master){ 

  // ΕΝΕΣΤΩΤΑΣ
  // ΕΝΕΡΓΗΤΙΚΗ
  master = loadKatalixis(master, "ω",0,0,0);
  master = loadKatalixis(master, "εις",0,0,0);
  master = loadKatalixis(master, "ει",0,0,0);
  master = loadKatalixis(master, "ουμε",0,0,0);
  master = loadKatalixis(master, "ετε",0,0,0);
  master = loadKatalixis(master, "ουν",0,0,0);
  master = loadKatalixis(master, "ουνε",0,0,0);

  master = loadKatalixis(master, "ε",0,0,0);
  master = loadKatalixis(master, "ετε",0,0,0);
  
  // ΠΑΘΗΤΙΚΗ
  master = loadKatalixis(master, "ομαι",0,0,0);
  master = loadKatalixis(master, "εσαι",0,0,0);
  master = loadKatalixis(master, "εται",0,0,0);
  master = loadKatalixis(master, "όμαστε",0,0,0);
  master = loadKatalixis(master, "εστε",0,0,0);
  master = loadKatalixis(master, "όσαστε",0,0,0);
  master = loadKatalixis(master, "ονται",0,0,0);

  master = loadKatalixis(master, "ου",0,0,0);
  master = loadKatalixis(master, "εστε",0,0,0);

  return master;

}

struct katalixis* loadKatalixis(struct katalixis* master, char *kata, int xronos, int foni, int klisi){ 
  

  if(!master){ 
    
    master = calloc (sizeof(struct katalixis), 1);
    master->katalixi = calloc (sizeof(char), strlen(kata));

    strcpy(master->katalixi, kata);
    master->xronos = xronos;
    master->foni = foni;
    master->klisi = klisi;
    master->next = NULL;

  }else{ 
    
    struct katalixis* reader = master;

    while(reader->next){ 
      reader = reader->next;
    }

    struct katalixis* new = calloc (sizeof(struct katalixis), 1);
    new->katalixi = calloc (sizeof(char), strlen(kata));

    strcpy(new->katalixi, kata);
    new->xronos = xronos;
    new->foni = foni;
    new->klisi = klisi;
    new->next = NULL;

    reader->next = new;

  }

  return master;

}













int stringToInt(char a[]) {
  
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

char* deleteKataklida(char* word, struct katalixis* master){ 

  char *returner = calloc(1, 256);
  char *returnerb = calloc(1, 256);
  char *ending = calloc(1, 256);
  char* test = calloc(1, 256);
  int i = 0;

  returnerb = calloc(1, 256);
  returner = calloc(1, 256);

  word = atono(word);

  struct katalixis* reader = master;
  while(reader){ 
    
    ending = atono(reader->katalixi);
    printf("%s, %s, %lu\n", word + strlen(word) - strlen(ending) , ending, strlen(ending));

    if(strlen(word) < strlen(ending)){ 
      returner = NULL;

    }else if( strncmp(word + strlen(word) - strlen(ending) , ending, strlen(ending)) == 0 ){
      strncpy(returner, word, strlen(word) - strlen(ending));

      return protoTonismeno(returner);
    }

    reader = reader->next;
  }

    

    
  

  return "NOTHING";

}

char* afaireshTonou(char *sulabi){

    if( strcmp(sulabi, "ά") == 0 ){
        return "α";
    }else if( strcmp(sulabi, "έ") == 0 ){
        return "ε";
    }else if( strcmp(sulabi, "ή") == 0 ){
        return "η";
    }else if( strcmp(sulabi, "ί") == 0 ){
        return "ι";
    }else if( strcmp(sulabi, "ό") == 0 ){
        return "ο";
    }else if( strcmp(sulabi, "ύ") == 0 ){
        return "υ";
    }else if( strcmp(sulabi, "ώ") == 0 ){
        return "ω";
    }else if( strcmp(sulabi, "́") == 0 ){
        return "";
    }else{
        return sulabi;
    }

} 

char* prosthesiTonou(char *sulabi){

    if( strcmp(sulabi, "α") == 0 ){
        return "ά";
    }else if( strcmp(sulabi, "ε") == 0 ){
        return "έ";
    }else if( strcmp(sulabi, "η") == 0 ){
        return "ή";
    }else if( strcmp(sulabi, "ι") == 0 ){
        return "ί";
    }else if( strcmp(sulabi, "ο") == 0 ){
        return "ό";
    }else if( strcmp(sulabi, "υ") == 0 ){
        return "ύ";
    }else if( strcmp(sulabi, "ω") == 0 ){
        return "ώ";
    }else{
        return sulabi;
    }

} 

int isPhoneien(char *sulabi){

    if( strcmp(sulabi, "α") == 0 ){
        return 1;
    }else if( strcmp(sulabi, "ε") == 0 ){
        return 1;
    }else if( strcmp(sulabi, "η") == 0 ){
        return 1;
    }else if( strcmp(sulabi, "ι") == 0 ){
        return 1;
    }else if( strcmp(sulabi, "ο") == 0 ){
        return 1;
    }else if( strcmp(sulabi, "υ") == 0 ){
        return 1;
    }else if( strcmp(sulabi, "ω") == 0 ){
        return 1;
    }else if( strcmp(sulabi, "ά") == 0 ){
        return 1;
    }else if( strcmp(sulabi, "έ") == 0 ){
        return 1;
    }else if( strcmp(sulabi, "ή") == 0 ){
        return 1;
    }else if( strcmp(sulabi, "ί") == 0 ){
        return 1;
    }else if( strcmp(sulabi, "ό") == 0 ){
        return 1;
    }else if( strcmp(sulabi, "ύ") == 0 ){
        return 1;
    }else if( strcmp(sulabi, "ώ") == 0 ){
        return 1;
    }else {
        return 0;
    }

} 

char* atono(char* wcreator){

  if(!wcreator)
    return "";

  int i = 0, j = 0, lastPhonien = 0;
  char *wcreatorJoker = calloc(1,1024), *wcreatorAtono = calloc(1,1024);
  strcpy(wcreatorAtono,"");

  while(strlen(wcreator) > j){  

      strncpy(wcreatorJoker, wcreator + j, (j+2) - j);
      strcat(wcreatorAtono, afaireshTonou(wcreatorJoker));

      i ++ ;
      j += 2;
  
  }

  return wcreatorAtono;

}

char* teleutaioTonismeno(char* wcreatorAtono){

  int i = 0, j = 0, lastPhonien = 0;
  char *wcreatorJoker = calloc(1,1024), *wcreatorTeleutaioTonismeno = calloc(1,1024);

  while(strlen(wcreatorAtono) > j ){    

      strncpy(wcreatorJoker, wcreatorAtono + j, (j+2) - j);
      if(isPhoneien(wcreatorJoker)){ lastPhonien = j; }
      
      i ++ ;
      j += 2;
  
  }

  i = 0, j = 0;
  while(strlen(wcreatorAtono) > j){    

      if(j == lastPhonien){
          strncpy(wcreatorJoker, wcreatorAtono + j, (j+2) - j);
          strcat(wcreatorTeleutaioTonismeno, prosthesiTonou(wcreatorJoker));
      }else{
          strncat(wcreatorTeleutaioTonismeno, wcreatorAtono + j, (j+2) - j);
      }

      i ++ ;
      j += 2;
  
  }

  return wcreatorTeleutaioTonismeno;

}

char* protoTonismeno(char* wcreatorAtono){

  int i = 0, j = 0, done = 0;
  char *wcreatorJoker = calloc(1,1024), *wcreatorProtoTonismeno = calloc(1,1024);

  while(strlen(wcreatorAtono) > j){    

      strncpy(wcreatorJoker, wcreatorAtono + j, (j+2) - j);
      if(isPhoneien(wcreatorJoker) && done == 0){
          strcat(wcreatorProtoTonismeno, prosthesiTonou(wcreatorJoker));
          done = 1;
      }else{
          strcat(wcreatorProtoTonismeno, wcreatorJoker);
      }

      i ++ ;
      j += 2;

    }

    return wcreatorProtoTonismeno;

}








