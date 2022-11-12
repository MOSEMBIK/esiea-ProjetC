#include "struct.h"

int main(){
    charstruct char_struct[256] = {NULL, 0};

    int size = lire_caracteres(char_struct, "./test.txt");
    // printf("\t\n Size of char_struct : %d", size);
    // for (int i=0; i<size; i++){
    //     if (char_struct[i].occurrence != 0){
    //         printf("\n Index : %d \n Char : '%c' \n Occurence : %d\n", i, char_struct[i].ascii_char, char_struct[i].occurrence);
    //     }   
    // }

    arbrestruct arbre_struct[512] = {NULL, NULL, NULL};
    arbrestruct endcoded_arbre_struct;

    codestruct code_struct[256] = {NULL, NULL};

    unsigned char encoded_data[] = {NULL};

    creer_arbre(arbre_struct, char_struct, size, code_struct, endcoded_arbre_struct);

    encoder_fichier(encoded_data, "./test.txt", code_struct);

    compresser_fichier("./test_encode.huf", encoded_data);

    decompresser_fichier("./test_encode.huf", "./test_decode.txt", encoded_data);
    
    printf("\n\nCliquez sur ENTREE pour continuer.");
    while (scanf("%s") != '\n');
    return 0;
}

