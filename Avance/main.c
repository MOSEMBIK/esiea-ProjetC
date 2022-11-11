#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000

struct char_struct
{
    int nombre;
    unsigned long frequence;
};

struct char_struct *char_struct;


int lire_caracteres(char nom_fichier[]){
    int char_count = 0;
    FILE *fPointer;
    fPointer = fopen(nom_fichier, "r");
    char singleLine[MAX_BUFFER_SIZE];

    if(fPointer == NULL){
        printf("Erreur fopen\n");
        return 1;
    }

    char_struct = malloc(sizeof(struct char_struct));

    while(!feof(fPointer)){
        fgets(singleLine, MAX_BUFFER_SIZE, fPointer);
        for(int i=0; i<strlen(singleLine); i++){
            printf("%d\n", char_struct[singleLine[i]].nombre);
            char_struct[singleLine[i]].nombre++;
            char_count++;
        }
    }

    printf("%d", char_count);

    fclose(fPointer);
    return char_count;
}


struct char_struct * generer_frequences(int char_count){
    for(int i=0; i<sizeof(struct char_struct); i++){
        char_struct[i].frequence = char_struct[i].nombre / char_count;
    }
    return char_struct;
}


void creer_arbre(){
    return;
}


void encoder_frequences(){
    return;
}


void associer_frequences_encodage(){
    return;
}


void creer_nouveau_fichier(){
    return;
}


void compresser_fichier(){
    return;
}


void decompresser_fichier(){
    return;
}


int main(){
    lire_caracteres("./test.txt");
    return 0;
}
