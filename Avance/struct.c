#include "struct.h"


void lire_caracteres(charstruct char_struct[], char nom_fichier[]){
    printf("\n\n READING FILE...");
    printf("\n\n 1.");
    int char_count = 0;
    FILE *fPointer;
    fPointer = fopen(nom_fichier, "r");
    char singleLine[MAX_BUFFER_SIZE];

    printf("\n\n 2.");
    if(fPointer == NULL){
        printf("Erreur fopen\n");
        return 1;
    }

    printf("\n\n 3.");
    while(!feof(fPointer)){
        printf("\n\n 3.1");
        fgets(singleLine, MAX_BUFFER_SIZE, fPointer);
        printf("\n\n 3.2");
        for(int i=0; i<strlen(singleLine); i++){
            char_struct[singleLine[i]].occurrence++;
        }
    }

    printf("\n\n 4.");
    fclose(fPointer);
}


void creer_arbre(arbrestruct arbre_struct[], charstruct char_struct[], codestruct code[]){

}


void encoder_fichier(char void_char[], char nom_fichier[], codestruct code[]){
    printf("\n\n ENCODING FILE...");
    printf("\n\n 1.");
    int char_count = 0;
    FILE *fPointer;
    fPointer = fopen(nom_fichier, "r");
    char singleLine[MAX_BUFFER_SIZE];

    printf("\n\n 2.");
    if(fPointer == NULL){
        printf("Erreur fopen\n");
        return 1;
    }

    printf("\n\n 3.");
    int count = 0;
    while(!feof(fPointer)){
        printf("\n\n 3.1");
        fgets(singleLine, MAX_BUFFER_SIZE, fPointer);
        printf("\n\n 3.2");
        for(int i=0; i<strlen(singleLine); i++){
            void_char[count] = code[singleLine[i]].code;
            count++;
        }
    }

    printf("\n\n 4.");
    fclose(fPointer);
}



void compresser_fichier(char fichier_output[], char encoded_char[]) {
    
}


void decompresser_fichier(char fichier_encode[], char fichier_decode[], arbrestruct arbre_struct[]) {

}