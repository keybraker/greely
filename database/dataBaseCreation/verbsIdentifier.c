#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define a_c_r     "\x1b[31m"
#define a_c_g     "\x1b[32m"
#define a_c_y     "\x1b[33m"
#define a_c_b     "\x1b[34m"
#define a_c_m     "\x1b[35m"
#define a_c_c     "\x1b[36m"
#define a_c_re    "\x1b[0m"
#define under     "\e[4m"
#define under_re  "\e[0m"
#define italic    "\e[3m"
#define italic_re "\e[0m"
#define bold      "\e[1m"
#define bold_re   "\e[0m"

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

char *xts[] = {

    "Ενεστώτα",
    "Παρατατικο",
    "Αόριστο",
    "Εξακολουθητικό Μέλλοντα",
    "Στιγμιαίο Μέλλοντα",
    "Συντεταγμένο Μέλλοντα",
    "Συντελεσμένο Μέλλοντα",
    "Παρακείμενο",
    "Υπερσυντέλικο"
    
};

char *pts[] = {

    "πρώτο",
    "δεύτερο",
    "τρίτο"
    
};

char *ats[] = {

    "ενικού",
    "πλυθηντικού"
    
};

char *kts[] = {

    "οριστική",
    "υποτακτική",
    "προστακτική",
    "οριστική ή υποτακτική"
    
};

char *fts[] = {

    "ενεργητική",
    "παθητική"
    
};;

//roi kanones gia ta prothemata menontai na ulopoihthoun
int main(int argc, char** argv){

    if(argc != 2){
        printf("too few arguments\n");
        exit(0);
    }

    FILE* f1 = fopen ("../generatedDatabases/greekRimataCreator.txt", "r");
    if(!f1){ printf("ERROR f1\n"); exit(1); }

    char    buffer[255], *word;

    while (fgets(buffer,255, f1)!= NULL)    { 

        word = strtok(buffer, "|");

        strtok(NULL, "|");
        strtok(NULL, "|");

        if(strcmp(word, argv[1]) == 0){ 
            
            printf("\nΤο ρήμα \"");
            printf(a_c_r"%s"a_c_re,argv[1]);
            printf("\", είναι: \n");
            printf("➥ χρόνου ");
            printf(a_c_r"%s\n"a_c_re, xts[toInt(strtok(NULL, "|"))]);
            printf("➥ ");
            printf(a_c_r"%s"a_c_re, pts[toInt(strtok(NULL, "|"))]);
            printf(" πρόσωπο ");
            printf(a_c_r"%s\n"a_c_re, ats[toInt(strtok(NULL, "|"))]);
            printf("➥ ");
            printf(a_c_r"%s"a_c_re, kts[toInt(strtok(NULL, "|"))] );
            printf(" έγκλιση\n➥ ");
            printf(a_c_r"%s"a_c_re, fts[toInt(strtok(NULL, "|"))]);
            printf(" φωνή.\n");

            fclose(f1);
            return 1;

        }

    }

    fclose(f1);

    printf("Word \"%s\" was found in Database.\n", argv[1]);
    return 0;

}