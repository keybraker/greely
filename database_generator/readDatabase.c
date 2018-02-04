#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordExifFunc.h"

int main(int argc, char** argv){

    FILE* f1 = fopen ("wordSyllabusGr.txt", "r");
    if(!f1){ printf("ERROR f1"); exit(1); }
    FILE* f2 = fopen ("wordSyllabusGr2.txt", "w+");
    if(!f2){ printf("ERROR f2"); exit(1); }
    FILE* f3 = fopen ("wordSyllabusGr3.txt", "w+");
    if(!f3){ printf("ERROR f2"); exit(1); }

    int     unknown = 0;
    int     all = 0;
    char    *len, *syllen;
    char    *word, *syllabes, *syllabes2, *syllabes3 ,*syl, *sylp, *sylpp;
    char    buffer[255];
    
    while (fgets(buffer,255, f1)!= NULL)    { 

        all++;
        len         = strtok(buffer,"\t");
        word        = strtok(NULL, "\t");
        syllen      = strtok(NULL, "\t");
        syllabes    = strtok(NULL, "\t");
        
        syllabes2 = calloc(strlen(syllabes),sizeof(char));
        strncpy(syllabes2, syllabes, strlen(syllabes)-1);

        syllabes3 = calloc(strlen(syllabes2), sizeof(char));
        syllabes3 = strdup(syllabes2);

        syl = strtok(syllabes3, "-");
        sylp = syl;
        sylpp = syl;
        while(syl != NULL){
            sylpp = sylp;
            sylp = syl; 
            syl = strtok(NULL, "-");
        }      
        
        // printf("word = %s\n", word);    
        // printf("syl = %s\n", syl);
        // printf("sylp = %s\n", sylp);
        // printf("sylpp = %s\n\n", sylpp);

        // IDIAITEROTHTES
        if(strcmp(word, "εδώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "άνω") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "άπω") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "εγώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|7|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "έξω") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ηχώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "φως") == 0){
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "πρεζάκιας") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μπαμπάς") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "χαζομπαμπάς") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μπέικον") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μπάσκετ") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μπαμπού") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μπαλτάς") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μπαϊπάς") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μπάγκος") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μπάσκετ") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μπάρμαν") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μόνιτορ") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μοναξιά") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μολότοφ") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μοιχεία") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μοιραία") == 0){
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μιναρές") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μιζέρια") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μετρητά") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μεταξάς") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μεσαίος") == 0){
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μεροφάι") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μερικοί") == 0){
            fprintf(f2, "%s|%s|%s|%s|7|4|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μερίδιο") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μενεξές") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μεμπτός") == 0){
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μελανιά") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μέλαθρο") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μεικτός") == 0){
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ζωή") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ροή") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "πενταροδεκάρες") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "παρεμπιπτόντως") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "σαμπουάν") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "χρωμοσαμπουάν") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "τζιτζιφιόγκος") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μπιζνεσγούμαν") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "επαμφοτερίζων") == 0){
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "εμπειρογνώμων") == 0){
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ελεφαντοστούν") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "βουλκανιζατέρ") == 0){ // AKLITO
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "αντεργκράουντ") == 0){ // AKLITO
            fprintf(f2, "%s|%s|%s|%s|1|5|0|5|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "φωτορομάντσο") == 0){ // DUNNO
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "φωτορεπόρτερ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "φωτορεπορτάζ") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "φυτοπλαγκτόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "τσαμπουκαλού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "σπορτσγούμαν") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "σουπερμάρκετ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ρεπροντιξιόν") == 0){ // AKLITO
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "προστυχάντζα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "προσλαμβάνων") == 0){ // CHECK
            fprintf(f2, "%s|%s|%s|%s|5|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "πανεπιστήμων") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μπουγιουρντί") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "οποιοσδήποτε") == 0){ // AKLITO
            fprintf(f2, "%s|%s|%s|%s|7|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "κουτσομπολιό") == 0){ // AKLITO
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "κονσόρτσιουμ") == 0){ // AKLITO
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ισχυρογνώμων") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ιλουστρασιόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ελευθερόφρων") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "γκαρνταρόμπα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "βουστροφηδόν") == 0){
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ανεπιστρεπτί") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|5|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ανακοινωθείς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|3|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "χάμπουργκερ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "φιλολογίζων") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "τρανσέξουαλ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "τηλεκοντρόλ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "τετράδιπλος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ταπεινόφρων") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "σφαγιασθείς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|0|1|0|1|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "συνθεσάιζερ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "συμπληγάδες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ρεσεψιονίστ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "προσπέκτους") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "πορτμπαγκάζ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "πολυπράγμων") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ορντινάντσα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "οποτεδήποτε") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|5|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ξανθομαλλού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ντοκιμαντέρ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); 
        }else if(strcmp(word, "μπροστάντζα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μπάρμπεκιου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μορατόριουμ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "κονσομασιόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "καλλιτέχνις") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "πανδαμάτειρα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "πανδαμάτωρ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "οσοσδήποτε") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|7|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "οπωσδήποτε") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|7|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "οπουδήποτε") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|7|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ομοθυμαδόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|7|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "οιοσδήποτε") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|7|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "νυχθημερόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|7|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μπουντουάρ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μπουλντόγκ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ματσαράγκα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μαγουλάδες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2); 
        }else if(strcmp(sylp, "τερ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "λεπτοκαρυά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "κωλοτούμπα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "κουραμπιές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "κατατεθείς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ηλεκτροσόκ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ψαρονέφρι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "χούλιγκαν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "χλιμιντρώ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "χερουβείμ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "χαμογέλιο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "φωτοφίνις") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "συνέρχεσθαι") == 0){ // CHECK
            fprintf(f2, "%s|%s|%s|%s|0|0|2|1|0|1|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "φωσφοριζέ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "φαστφούντ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "φαγιάντσα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "γιουσουρούμ") == 0){ // AKLITO
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "βασιλομήτωρ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2); 
            // GIA EDIT 
        
        
        // ARITHMITIKA
        }else if(strcmp(word, "μηδέν") == 0){
            fprintf(f2, "%s|%s|%s|%s|4|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ένα") == 0){
            fprintf(f2, "%s|%s|%s|%s|4|1|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "δυο") == 0){
            fprintf(f2, "%s|%s|%s|%s|4|2|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "τρεία") == 0){
            fprintf(f2, "%s|%s|%s|%s|4|3|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "τέσσερα") == 0){
            fprintf(f2, "%s|%s|%s|%s|4|4|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "πέντε") == 0){
            fprintf(f2, "%s|%s|%s|%s|4|5|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "έξι") == 0){
            fprintf(f2, "%s|%s|%s|%s|4|6|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "επτά") == 0){
            fprintf(f2, "%s|%s|%s|%s|4|7|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "οκτώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|4|8|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "εννέα") == 0){
            fprintf(f2, "%s|%s|%s|%s|4|9|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "δέκα") == 0){
            fprintf(f2, "%s|%s|%s|%s|4|10|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "έντεκα") == 0){
            fprintf(f2, "%s|%s|%s|%s|4|11|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "δώδεκα") == 0){
            fprintf(f2, "%s|%s|%s|%s|4|12|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "δεκατέσσερις") == 0){
            fprintf(f2, "%s|%s|%s|%s|4|14|\n", len,word,syllen,syllabes2);    
        }else if(strcmp(word, "είκοσι") == 0){
            fprintf(f2, "%s|%s|%s|%s|4|20|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "τριάντα") == 0){
            fprintf(f2, "%s|%s|%s|%s|4|30|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "σαράντα") == 0){
            fprintf(f2, "%s|%s|%s|%s|4|40|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "πενήντα") == 0){
            fprintf(f2, "%s|%s|%s|%s|4|50|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "έξιντα") == 0){
            fprintf(f2, "%s|%s|%s|%s|4|60|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "εβδομήντα") == 0){
            fprintf(f2, "%s|%s|%s|%s|4|70|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ογδόντα") == 0){
            fprintf(f2, "%s|%s|%s|%s|4|80|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ενενήντα") == 0){
            fprintf(f2, "%s|%s|%s|%s|4|90|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "εκατό") == 0){
            fprintf(f2, "%s|%s|%s|%s|4|100|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "εκατοντάκις") == 0){
            fprintf(f2, "%s|%s|%s|%s|4|100|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "χίλια") == 0){
            fprintf(f2, "%s|%s|%s|%s|4|1000|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "εκατομμύριο") == 0){
            fprintf(f2, "%s|%s|%s|%s|4|1000000|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "δισεκατομμύριο") == 0){
            fprintf(f2, "%s|%s|%s|%s|4|1000000000|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "τρισεκατομμύριο") == 0){
            fprintf(f2, "%s|%s|%s|%s|4|1000000000000|\n", len,word,syllen,syllabes2);

        // SYNDESMOI
        }else if(strcmp(word, "και") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "κι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ούτε") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ούδε") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μήτε") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μηδέ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|1|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "είτε") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|1|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "αλλά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|2|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|2|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "παρά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|2|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ομώς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|2|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ωστόσο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|2|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ενώ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|2|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μολονότι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|2|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μόνο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|2|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "λοιπόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|3|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ώστε") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|3|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "άρα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|3|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "επομένως") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|3|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "οπότε") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|3|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "δηλαδή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|4|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "πως") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|5|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "που") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|5|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ότι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|5|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "όταν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|6|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ενώ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|6|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "καθώς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|6|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "αφού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|6|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "αφότου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|6|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "πριν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|6|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μόλις") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|6|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "προτού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|6|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ώσπου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|6|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ωσότου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|6|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "γιατί") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|7|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "επειδή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|7|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "αφού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|7|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "τι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|7|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "αν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|8|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "εάν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|8|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "άμα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|8|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|9|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "που") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|10|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ώστε") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|10|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μολονότι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|11|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|12|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μην") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|12|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μήπως") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|12|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "παρά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|13|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|6|14\n", len,word,syllen,syllabes2);   

        // EPIRIMATA den douleuei gamo ti C 
        	// TOPIKA
        }else if(strcmp(word, "εδώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "εκεί") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μέσα") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "έξω") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "βόρεια") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "νότια") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|0|\n", len,word,syllen,syllabes2);
            // XRONIKA
        }else if(strcmp(word, "σήμερα") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|1|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "τώρα") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|1|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "πέρυσι") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|1|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "έπειτα") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|1|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "κάποτε") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|1|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "κατευθείαν") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|1|\n", len,word,syllen,syllabes2);
            // TROPIKA
        }else if(strcmp(word, "έτσι") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|2|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μαζί") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|2|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "όπως") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|2|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "αλλιώς") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|2|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ξαφνικά") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|2|\n", len,word,syllen,syllabes2);
            // POSOTIKA
        }else if(strcmp(word, "λίγο") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|3|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "πολύ") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|3|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "τόσο") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|3|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "κάμποσο") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|3|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "περισσότερο") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|3|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "δωρεάν") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|3|\n", len,word,syllen,syllabes2);
            // BEBAIOTIKA
        }else if(strcmp(word, "ναι") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|4|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μάλιστα") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|4|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "βέβαια") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|4|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "αλήθεια") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|4|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "σωστά") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|4|\n", len,word,syllen,syllabes2);
            // DISTAKTIKA
        }else if(strcmp(word, "ίσως") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|5|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "τάχα") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|5|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "δήθεν") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|5|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "πιθανόν") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|5|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "άραγε") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|5|\n", len,word,syllen,syllabes2);
            // ARNITIKA
        }else if(strcmp(word, "όχι") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|6|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "δεν") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|6|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μην") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|6|\n", len,word,syllen,syllabes2);
        
        }else if(strcmp(sylp, "γίς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|5|2|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νίς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|5|2|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τίς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|5|2|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πως") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|5|2|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νως") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|5|2|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στως") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|2|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντως") == 0){
            fprintf(f2, "%s|%s|%s|%s|5|2|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντως") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|5|2|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θεν") == 0){ // PREPEI NA GINEI MEMMONOMENOS ELEGXOS
            fprintf(f2, "%s|%s|%s|%s|5|2|\n", len,word,syllen,syllabes2);
       
        // METOXES 
        }else if(strcmp(word, "συνήθως") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|3|\n", len,word,syllen,syllabes2);    
        }else if(strcmp(word, "κατεπείγων") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|3|\n", len,word,syllen,syllabes2);    
        }else if(strcmp(word, "δέον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|3|\n", len,word,syllen,syllabes2);    
        }else if(strcmp(word, "καταδικασθείς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|3|\n", len,word,syllen,syllabes2);    
        }else if(strcmp(sylpp, "ρεύ") == 0 && strcmp(sylp, "ων") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|3|\n", len,word,syllen,syllabes2);

        // RIMATA
        }else if(strcmp(sylp, "ω") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ώ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σκω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σκώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "βω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "βώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δρω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δρώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θρω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θρώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μπτω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μπτώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σχω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σχώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τρω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τρώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χλω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χλώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χρω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χρώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τσω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τσώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στρω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στρώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πρω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πρώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μπω") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μπώ") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μαι") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|1|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μαί") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|1|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ται") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|1|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ταί") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|1|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νται") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νταί") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|0|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σΘαι") == 0){ // CHECK
            fprintf(f2, "%s|%s|%s|%s|0|0|2|1|0|1|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "βει") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γει") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δει") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζει") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θει") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κει") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λει") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μει") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νει") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξει") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πει") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρει") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σει") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τει") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φει") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χει") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψει") == 0){
            fprintf(f2, "%s|%s|%s|%s|0|0|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θεις") == 0){ // CHECK
            fprintf(f2, "%s|%s|%s|%s|0|0|1|0|0|1|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θείς") == 0){ // CHECK
            fprintf(f2, "%s|%s|%s|%s|0|0|1|0|0|1|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φθείς") == 0){ // CHECK
            fprintf(f2, "%s|%s|%s|%s|0|0|1|0|0|1|\n", len,word,syllen,syllabes2);

        // EPITHETA
            // ARSENIKA
        }else if(strcmp(sylp, "νών") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μων") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ων") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φρων") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);


        }else if(strcmp(sylpp, "βι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "γι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "δι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ζι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "θι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "θρι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κτι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κρι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "λι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "μι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "νι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ξι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "πι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "πρι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ρι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σμι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σπι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τρι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "στρι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ντι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ντρι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τσι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τζι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "φι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "φτι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "χι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "χνι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ψι") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);  

        }else if(strcmp(sylp, "βός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θρός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κρός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μπός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μπτός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πρός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τρός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στρός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντρός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τσός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φλός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);

        }else if(strcmp(sylp, "βος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θρος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κρος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μπος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μπτος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "προς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τρος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στρος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντρος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τσος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φλος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|0|0|0|\n", len,word,syllen,syllabes2);

        // ARSENIKA KAI THYLIKA
        }else if(strcmp(sylp, "ής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "βής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δρής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θρής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κρής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτσής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χτσής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τρής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στρής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); 
        }else if(strcmp(sylp, "ντρής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); 
        }else if(strcmp(sylp, "τσής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χτής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|4|0|0|\n", len,word,syllen,syllabes2);

            // THYLIKA
        }else if(strcmp(sylpp, "βι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "γι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "δι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ζι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "θι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "θρι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κτι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κρι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "λι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "μι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "νι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ξι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "πι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "πρι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ρι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σμι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σπι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τρι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "στρι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ντι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ντρι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τσι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τζι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "φι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "φτι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "χι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "χνι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ψι") == 0 && strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|1|0|0|\n", len,word,syllen,syllabes2); 
            //  EPITHETA H OYSIASTIKA 
        }else if(strcmp(sylp, "ή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "βή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θρή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κρή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πρή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τρή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στρή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντρή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τσή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|4|1|0|0|\n", len,word,syllen,syllabes2); 
            // OYDETERA
        }else if(strcmp(sylp, "βό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θρό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κρό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πρό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σρό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σκό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σλό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τρό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στρό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντρό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τσό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|1|2|0|0|\n", len,word,syllen,syllabes2);

        // OYSIASTIKA
            // ARSENIKA  
        }else if(strcmp(sylp, "ές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "βές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δρές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θρές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κρές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τρές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στρές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); // το πάντές
        }else if(strcmp(sylp, "ντρές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); // το πάντές
        }else if(strcmp(sylp, "τσές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψές") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);

        }else if(strcmp(sylp, "ειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "βειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δρειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θρειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κρειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τρειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στρειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); // το πάντειος
        }else if(strcmp(sylp, "ντρειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); // το πάντειος
        }else if(strcmp(sylp, "τσειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψειος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);

        }else if(strcmp(sylp, "άς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "βάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "βγάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δράς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θράς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κράς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ράς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τράς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στράς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); // το πάντάς
        }else if(strcmp(sylp, "ντράς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); // το πάντάς
        }else if(strcmp(sylp, "τσάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);

        }else if(strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "βος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γκος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γκτος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δρος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θρος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κρος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "προς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σθος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τρος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στρος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); // το πάντος
        }else if(strcmp(sylp, "ντρος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); // το πάντος
        }else if(strcmp(sylp, "τσος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χτος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);

        }else if(strcmp(sylp, "ός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "βός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δρός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θρός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κρός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σκός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τρός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στρός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); // το πάντός
        }else if(strcmp(sylp, "ντρός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); // το πάντός
        }else if(strcmp(sylp, "τσός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χμός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χτός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χλός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χκός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χρός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χπός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);

        }else if(strcmp(sylp, "ης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "βης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δρης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θρης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κρης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μπης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μπτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "της") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τρης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στρης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); // το πάντης
        }else if(strcmp(sylp, "ντρης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); // το πάντης
        }else if(strcmp(sylp, "τσης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φλης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);

        }else if(strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "βας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γκας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δρας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θρας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κρας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τρας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στρας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); // το πάντας
        }else if(strcmp(sylp, "ντρας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); // το πάντας
        }else if(strcmp(sylp, "τσας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);

        }else if(strcmp(sylpp, "βι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "γι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "δι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ζι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "θι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "θρι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κτι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κρι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "λι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "μι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "νι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ξι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "πι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "πτι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ρι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σμι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σπι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τρι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "στρι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ντι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ντρι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τσι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τζι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "φι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "φτι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "χι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "χνι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ψι") == 0 && strcmp(sylp, "στής") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);   

        }else if(strcmp(sylpp, "αί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "βαί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "γαί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "δαί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ζαί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "θαί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "θραί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "καί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κταί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κραί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "λαί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "μαί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ναί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ξαί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "παί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "πταί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ραί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σαί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σμαί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σπαί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ταί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τραί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "στραί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "νταί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ντραί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τσαί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τζαί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "φαί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "φταί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "χαί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "χναί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ψαί") == 0 && strcmp(sylp, "ος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);   

        }else if(strcmp(sylpp, "αί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "βαί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "γαί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "δαί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ζαί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "θαί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "θραί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "καί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κταί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κραί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "λαί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "μαί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ναί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ξαί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "παί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "πταί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ραί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σαί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σμαί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σπαί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ταί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τραί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "στραί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "νταί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ντραί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τσαί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τζαί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "φαί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "φταί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "χαί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "χναί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ψαί") == 0 && strcmp(sylp, "χτης") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);   

        }else if(strcmp(sylpp, "βί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "γί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "δί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ζί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "θί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "θρί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κτί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κρί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "λί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "μί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "νί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ξί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "πί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "πτί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ρί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σμί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σπί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τρί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "στρί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ντί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ντρί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τσί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τζί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "φί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "φτί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "χί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "χνί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ψί") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);   

        }else if(strcmp(sylpp, "βέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "γέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "δέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ζέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "θέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "θρέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κτέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κρέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "λέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "μέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "νέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ξέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "πέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "πτέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ρέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σμέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σπέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τρέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "στρέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ντέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ντρέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τσέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τζέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "φέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "φτέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "χέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "χνέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ψέ") == 0 && strcmp(sylp, "ας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);  

        }else if(strcmp(sylp, "βος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γνος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δρος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θρος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ιος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κρος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κλος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μπος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μνος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μπρος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πνος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σκος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπρος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τρος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στρος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντρος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντζος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τσος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χμος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χτος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χπος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χλος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);

        }else if(strcmp(sylp, "βάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δράς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θράς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ιάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κράς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ράς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τράς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στράς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντράς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τσάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);

        }else if(strcmp(sylp, "βιάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γιάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "διάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δριάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζιάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θιάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θριάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ιιάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κιάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτιάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κριάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λιάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μιάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νιάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξιάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πιάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτιάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ριάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σιάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στιάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμιάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπιάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τιάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τριάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στριάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντιάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντριάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τσιάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζιάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φιάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτιάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χιάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνιάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψιάς") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);

        }else if(strcmp(sylp, "βιος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γιος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "διος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δριος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζιος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θιος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θριος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ιος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κιος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτιος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κριος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λιος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μιος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νιος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξιος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πιος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτιος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ριος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σιος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στιος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμιος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπιος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τιος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τριος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στριος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντιος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντριος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τσιος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζιος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φιος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτιος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χιος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνιος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψιος") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);

        }else if(strcmp(sylp, "βιός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γιός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "διός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δριός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζιός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θιός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θριός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ιός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κιός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτιός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κριός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λιός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μιός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νιός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξιός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πιός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτιός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ριός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σιός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στιός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμιός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπιός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τιός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τριός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στριός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντιός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντριός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τσιός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζιός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φιός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτιός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χιός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνιός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψιός") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);

        }else if(strcmp(sylp, "βιας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γιας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "διας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δριας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζιας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θιας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θριας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ιιας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κιας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτιας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κριας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λιας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μιας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νιας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξιας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πιας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτιας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ριας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σιας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στιας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμιας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπιας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τιας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τριας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στριας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντιας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντριας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τσιας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζιας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φιας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτιας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χιας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνιας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψιας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);

        }else if(strcmp(sylp, "βας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δρας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θρας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ιας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κρας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τρας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στρας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντρας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τσας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψας") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);

        }else if(strcmp(sylp, "κτιβ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμαν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|0|0|0|\n", len,word,syllen,syllabes2);
        


            // THYLIKA
        }else if(strcmp(sylp, "λειά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μαν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);

        }else if(strcmp(sylpp, "βε") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "γε") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "δε") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ζε") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "θε") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "θρε") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κε") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κτε") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κρε") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "λε") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "με") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "νε") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ξε") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "πε") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "πτε") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ρε") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σε") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σμε") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σπε") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τε") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τρε") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "στρε") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ντε") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ντρε") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τσε") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τζε") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "φε") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "φτε") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "χε") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "χνε") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ψε") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);    

        }else if(strcmp(sylpp, "βι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "γι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "δι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ζι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "θι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "θρι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κτι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κρι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "λι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "μι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "νι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ξι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "πι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "πτι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ρι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σμι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σπι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τρι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "στρι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ντι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ντρι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τσι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τζι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "φι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "φτι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "χι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "χνι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ψι") == 0 && strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);   

        }else if(strcmp(sylpp, "βί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "γί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "δί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ζί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "θί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "θρί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κτί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κρί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "λί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "μί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "νί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ξί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "πί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "πτί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ρί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σμί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σπί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "στρί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τρί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ντί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ντρί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τσί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τζί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "φί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "φτί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "χί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "χνί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ψί") == 0 && strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);    

        }else if(strcmp(sylp, "βες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δρες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θρες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κρες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τρες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στρες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); // το πάντες
        }else if(strcmp(sylp, "ντρες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); // το πάντες
        }else if(strcmp(sylp, "τσες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψες") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|1|0|\n", len,word,syllen,syllabes2);

        }else if(strcmp(sylp, "βια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "για") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δρια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θρια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κρια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τρια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στρια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); // το πάντια
        }else if(strcmp(sylp, "ντρια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); // το πάντια
        }else if(strcmp(sylp, "τσια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψια") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);

        }else if(strcmp(sylp, "βιά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γιά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γκιά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γκριά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "διά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δριά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζιά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θιά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θριά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κιά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτιά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κριά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λιά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μιά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νιά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξιά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πιά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτιά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ριά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σιά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στιά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμιά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπιά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τιά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τριά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στριά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντιά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); // το πάντιά
        }else if(strcmp(sylp, "ντριά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); // το πάντιά
        }else if(strcmp(sylp, "τσιά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζιά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φιά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτιά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χιά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνιά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψιά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);

        }else if(strcmp(sylp, "α") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "βα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δρα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θρα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κρα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "να") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σκα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τρα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στρα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); // το πάντα
        }else if(strcmp(sylp, "ντρα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); // το πάντα
        }else if(strcmp(sylp, "τσα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντζα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χτρα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψα") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);

        }else if(strcmp(sylp, "ά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "βά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δρά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θρά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κρά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τρά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στρά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); // το πάντά
        }else if(strcmp(sylp, "ντρά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); // το πάντά
        }else if(strcmp(sylp, "τσά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψά") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
    
        }else if(strcmp(sylp, "βη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δρη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θρη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κρη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μπτη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μπη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τρη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στρη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); // το πάντη
        }else if(strcmp(sylp, "ντρη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); // το πάντη
        }else if(strcmp(sylp, "τση") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψη") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);

        }else if(strcmp(sylp, "βή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δρή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θρή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κρή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μνή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μπή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μπτή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τρή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στρή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); // το πάντή
        }else if(strcmp(sylp, "ντρή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2); // το πάντή
        }else if(strcmp(sylp, "τσή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψή") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
    
        }else if(strcmp(sylp, "βου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δρου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θρου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κρου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "που") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "του") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τρου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στρου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντρου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τσου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);  
        }else if(strcmp(sylp, "φου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);   
        }else if(strcmp(sylp, "χνου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);   
        }else if(strcmp(sylp, "ψου") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2); 

        }else if(strcmp(sylp, "βού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δρού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θρού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κρού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τρού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στρού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντρού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τσού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);  
        }else if(strcmp(sylp, "φού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);   
        }else if(strcmp(sylp, "χνού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2);   
        }else if(strcmp(sylp, "ψού") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|1|0|0|\n", len,word,syllen,syllabes2); 


            // OYDETERA
        }else if(strcmp(sylpp, "εί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "βεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "γεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "δεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "δεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ζεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "θεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "θρεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ιεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κτεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "κρεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "λεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "μεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "νεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ξεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "πεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "πτεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ρεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "στεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σμεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "σπεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "στρεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τρεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ντεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ντρεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τσεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "τζεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "φεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "φτεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "χεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "χνεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylpp, "ψεί") == 0 && strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);    

        }else if(strcmp(sylp, "ι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "βι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δρι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θρι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κλι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κρι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τρι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στρι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντρι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τσι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);  
        }else if(strcmp(sylp, "φι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);   
        }else if(strcmp(sylp, "χνι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);   
        }else if(strcmp(sylp, "ψι") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);   
         
        }else if(strcmp(sylp, "είο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "βείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δρείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θρείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ιείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κρείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μπείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πρείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τρείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στρείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντρείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τσείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φλείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψείο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);

        }else if(strcmp(sylp, "ο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "βο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δρο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θρο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ιο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κρο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μπο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πλο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πφο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πνο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "προ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "το") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τρο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στρο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντρο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τσο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φλο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χμο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψο") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);

        }else if(strcmp(sylp, "ον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "βον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δρον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θρον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ιον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κρον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μπον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "προν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τρον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στρον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντρον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τσον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψον") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);

        }else if(strcmp(sylp, "όν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "βόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δρόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θρόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ιόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κρόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μπόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πρόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ρόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τρόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στρόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντρόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τσόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);

        }else if(strcmp(sylp, "ιό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "βιό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γιό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "διό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "δριό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ζιό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θιό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "θριό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κιό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κτιό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "κριό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "λιό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μιό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "μπιό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "νιό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ξιό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πιό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πτιό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "πριό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ριό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σιό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σμιό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "σπιό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τιό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τριό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "στριό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντιό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ντριό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τσιό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζιό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φιό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "φτιό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χιό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "χνιό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "ψιό") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);

        }else if(strcmp(sylp, "γιάζ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τέρ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "γκτόν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(sylp, "τζμεντ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "βιντεοκλάμπ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "ντεγκραντέ") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|0|0|\n", len,word,syllen,syllabes2);
        }else if(strcmp(word, "μετόπισθεν") == 0){ 
            fprintf(f2, "%s|%s|%s|%s|2|2|1|0|\n", len,word,syllen,syllabes2);


        }else{ 
            unknown++;
            fprintf(f3, "%s|%s|%s|%s|\n", len,word,syllen,syllabes2);
        }
        
    }
    printf("UNKNOWN: %d/%d\n", unknown, all);
    fclose(f1);
    fclose(f2);
}