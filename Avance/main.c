#include "struct.h"

int main(){
    charstruct char_struct[] = {NULL, 0};
    arbrestruct arbre_struct[] = {NULL, NULL, NULL};
    codestruct code_struct[] = {NULL, NULL};

    unsigned char encoded_data[] = {NULL};

    lire_caracteres(char_struct, "./test.txt");
    
    printf("%c : %d\n", 'e', char_struct['e'].occurrence);

    creer_arbre(arbre_struct, char_struct, code_struct);

    encoder_fichier(encoded_data, "./test.txt", code_struct);

    compresser_fichier("./test_encode.txt", encoded_data);

    decompresser_fichier("./test_encode.txt", "./test_decode.txt", encoded_data);
    
    printf("\n\nCliquez sur ENTREE pour continuer.");
    while (scanf("%s") != '\n');
    return 0;
}

