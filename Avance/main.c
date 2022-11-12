#include "struct.h"

int main(){
    charstruct char_struct[256] = {NULL, 0};
    arbrestruct arbre_struct[512] = {NULL, NULL, NULL};
    codestruct code_struct[256] = {NULL, NULL};

    unsigned char encoded_data[] = {NULL};

    printf("\n\n---------------------------------\n\n");
    int size = lire_caracteres(char_struct, "./test.txt");
    printf("\n\n Size of char_struct : %d\n", size);
    for (int i=0; i<size; i++){
        if (char_struct[i].occurrence != 0){
            if (char_struct[i].ascii_char != '\n') {
                printf("\n   Index : %d \n   Char : '%c' \n   Occurence : %d\n", i, char_struct[i].ascii_char, char_struct[i].occurrence);
            } else
                printf("\n   Index : %d \n   Char : '\\n' \n   Occurence : %d\n", i, char_struct[i].occurrence);
        }   
    }

    printf("\n\n---------------------------------\n\n");
    arbrestruct endcoded_arbre_struct = creer_arbre(arbre_struct, char_struct, size, endcoded_arbre_struct);
    printf("\n\n Built tree :");
    printf(
        "\n Root Char : '%c'\n Root Occurence : %d\n   Char Gauche : '%c'\n   Occurrence Gauche : %d\n\n   Char Droit : '%c'\n   Occurrence Droit : %d",  
        endcoded_arbre_struct.value.ascii_char, 
        endcoded_arbre_struct.value.occurrence, 
        endcoded_arbre_struct.a_gauche->value.ascii_char, 
        endcoded_arbre_struct.a_gauche->value.occurrence, 
        endcoded_arbre_struct.a_droite->value.ascii_char, 
        endcoded_arbre_struct.a_droite->value.occurrence
    );

    printf("\n\n---------------------------------\n\n");
    creer_table(code_struct, endcoded_arbre_struct);

    printf("\n\n---------------------------------\n\n");
    encoder_fichier(encoded_data, "./test.txt", code_struct);

    printf("\n\n---------------------------------\n\n");
    compresser_fichier("./test_encode.huf", encoded_data);

    printf("\n\n---------------------------------\n\n");
    decompresser_fichier("./test_encode.huf", "./test_decode.txt", encoded_data);
    
    printf("\n\nCliquez sur ENTREE pour continuer.");
    while (scanf("%c") != '\n');
    return 0;
}

