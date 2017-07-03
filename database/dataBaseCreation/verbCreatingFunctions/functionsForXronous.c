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

char* deleteKataklida(char* word){ 

  char *returner = calloc(1, 256);
  char *returnerb = calloc(1, 256);
  char *ending = calloc(1, 256);
  char* test = calloc(1, 256);
  int i = 0;

  // παρατατικός
  
  i = 0;
  returnerb = calloc(1, 256);
  returner = calloc(1, 256);
  for(; i < 12 ; i++){
    strcpy(ending, pathParatatikosOristiki[i]);
    printf("word + strlen(word) - strlen(ending) - 2 = '%s', '%s' ending, %lu\n", word + strlen(word) - strlen(ending) - 2, ending, strlen(ending));

    char* kappa = calloc(1,200);
    int l = 0;
    strncpy(kappa, word + strlen(word) - strlen(ending) - 2, 2);
    while(strcmp(kappa, "\0") != 0){
      
      printf("word[%d] = %s\n", l, kappa);
      strncpy(kappa, word + strlen(word) - strlen(ending) - 2 + l, 2);
      l+=2;

    }
    printf("\n");
    char* kappa2 = calloc(1,200);
    l = 0;
    strncpy(kappa2, ending, 2);
    while(strcmp(kappa2, "\0") != 0){
      printf("ending[%d] = %s\n", l, kappa2);
      strncpy(kappa2, ending + l, 2);
      l+=2;

    }
   
    if(strlen(word) < strlen(ending)){ 
      returner = NULL;

    }else if( strncmp(word + strlen(word) - strlen(ending) - 2, ending, strlen(ending)) == 0 ){
      strncpy(returnerb, word, strlen(word) - strlen(ending));
      printf("PATHITIKI FONI PARATATIKOS\n");
      strncpy(test, returnerb, 2);
      
      return returner;
    }
  }
exit(0);
  i = 0;
  returnerb = calloc(1, 256);
  returner = calloc(1, 256);
  for(; i < 7 ; i++){
    strcpy(ending, energParatatikosOristiki[i]);

    if(strlen(word) < strlen(ending)){ 
      returner = NULL;
    
    }else if( strncmp(word + strlen(word) - strlen(ending), ending, strlen(ending)) == 0 ){
      strncpy(returnerb, word, strlen(word) - strlen(ending));
      printf("ENERGITIKI FONI PARATATIKOS\n");
      strncpy(test, returnerb, 2);
      if(strcmp(test,"έ\n")){
        strncpy(returner, &returnerb[2], strlen(returnerb) - 2);
        
        return protoTonismeno(returner);
      }else{
        
        return returner;
      }
      
    }
  }

  //ενεστώτας

  i = 0;
  for(; i < 7 ; i++){
    strcpy(ending, energEndingArrayOristikiYpotaktiki[i]);

    if(strlen(word) < strlen(ending)){
      returner = NULL;

    }else if( strncmp(word + strlen(word) - strlen(ending), ending, strlen(ending)) == 0 ){
      strncpy(returner, word, strlen(word) - strlen(ending));
      printf("ENERGITIKI FONI ENESTOTAS ORISTIKIS\n");
      return returner;
      
    }
  }

  i = 0;
  for(; i < 2 ; i++){
    strcpy(ending, energEndingArrayProstaktiki[i]);
    
    if(strlen(word) < strlen(ending)){ 
      returner = NULL;
    
    }else if( strncmp(word + strlen(word) - strlen(ending), ending, strlen(ending)) == 0 ){
      strncpy(returner, word, strlen(word) - strlen(ending));
      printf("word(%s) = ending(%s)\n",word,ending);
      printf("ENERGITIKI FONI ENESTOTAS PROSTAKTIKIS\n");
      return returner;
      
    }
  }

  i = 0;
  for(; i < 7 ; i++){
    strcpy(ending, pathEndingArrayOristikiYpotaktiki[i]);
    
    if(strlen(word) < strlen(ending)){ 
      returner = NULL;
    
    }else if( strncmp(word + strlen(word) - strlen(ending), ending, strlen(ending)) == 0 ){
      strncpy(returner, word, strlen(word) - strlen(ending));
      printf("PATHITIKI FONI ENESTOTAS YPOTAKTIKIS\n");
      return returner;
      
    }
  }

  i = 0;
  for(; i < 2 ; i++){
    strcpy(ending, pathEndingArrayProstaktiki[i]);
    
    if(strlen(word) < strlen(ending)){ 
      returner = NULL;
    
    }else if( strncmp(word + strlen(word) - strlen(ending), ending, strlen(ending)) == 0 ){
      strncpy(returner, word, strlen(word) - strlen(ending));
      printf("PATHITIKI FONI ENESTOTAS PROSTAKTIKI\n");
      return returner;
      
    }
  }

  return returner;

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
    }else {
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








