#include "struct.h"

int main(){
    charstruct char_struct[] = {NULL, 0};
    arbrestruct arbre_struct[] = {NULL, NULL, NULL};

    lire_caracteres(char_struct, "./test.txt");

    creer_arbre(arbre_struct, char_struct);

    printf("%c : %d\n", 'e', char_struct['e'].occurrence);
    
    printf("\n\nCliquez sur ENTREE pour continuer.");
    while (scanf("%s") != '\n');
    return 0;
}
