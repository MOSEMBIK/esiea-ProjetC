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
        return;
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
        return;
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
    printf("\n\n COMPRESSING FILE...");
    printf("\n\n 1.");
    FILE *fPointer;
    fPointer = fopen(fichier_output, "w");

    printf("\n\n 2.");
    if(fPointer == NULL){
        printf("Erreur fopen\n");
        return;
    }

    printf("\n\n 3.");
    fprintf(fPointer, "%s", encoded_char);

    printf("\n\n 4.");
    fclose(fPointer);    
}


void decompresser_fichier(char fichier_encode[], char fichier_decode[], arbrestruct arbre_struct[]) {
    printf("\n\n UNCOMPRESSING FILE...");
    printf("\n\n 1.");
    FILE *fPointer;
    char singleLine[MAX_BUFFER_SIZE];
    fPointer = fopen(fichier_encode, "r");

    printf("\n\n 2.");
    if(fPointer == NULL){
        printf("Erreur fopen\n");
        return;
    }

    printf("\n\n 3.");
    int count = 0;
    unsigned char output[] = {NULL};
    arbrestruct tmp = arbre_struct[0];

    while(!feof(fPointer)){
        printf("\n\n 3.1");
        fgets(singleLine, MAX_BUFFER_SIZE, fPointer);
        printf("\n\n 3.2");
        for(int i=0; i<strlen(singleLine); i++){
            if(tmp.value.ascii_char == NULL){
                if(singleLine[i] == 0){
                    tmp = *tmp.a_gauche;
                } else if(singleLine[i] == 1) {
                    tmp = *tmp.a_droite;
                }
            } else {
                output[count] = tmp.value.ascii_char;
                count++;
            }
        }
    }

    printf("\n\n 5.");
    fclose(fPointer);

    printf("Writing part");
    fPointer = fopen(fichier_decode, "w");

    printf("\n\n 2.");
    if(fPointer == NULL){
        printf("Erreur fopen\n");
        return;
    }

    printf("\n\n 3.");
    fprintf(fPointer, "%s", output);

    printf("\n\n 5.");
    fclose(fPointer);
}