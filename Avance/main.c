#include "struct.h"

int main(){
    charstruct char_struct[256] = {NULL, 0};
    arbrestruct arbre_struct[512] = {NULL, NULL, NULL, NULL};
    arbrestruct endcoded_arbre_struct;
    codestruct code_struct[256] = {NULL, NULL};

    unsigned char encoded_data[] = {NULL};


    int size = lire_caracteres(char_struct, "./test.txt");
    printf("\t\n Size of char_struct : %d", size);
    for (int i=0; i<size; i++){
        if (char_struct[i].occurrence != 0){
            printf("\n Index : %d \n Char : '%c' \n Occurence : %d\n", i, char_struct[i].ascii_char, char_struct[i].occurrence);
        }   
    }

    creer_arbre(arbre_struct, char_struct, size, endcoded_arbre_struct);
    printf("\n\n Built tree :");
    printf(
        "\n Root Char : '%c'\n Root Occurence : %d\n\n Char Gauche : '%c'\n Occurrence Gauche : %d\n\n Char Droit : '%c'\n Occurrence Droit : %d",  
        endcoded_arbre_struct.value.ascii_char, 
        endcoded_arbre_struct.value.occurrence, 
        endcoded_arbre_struct.a_gauche->value.ascii_char, 
        endcoded_arbre_struct.a_gauche->value.occurrence, 
        endcoded_arbre_struct.a_droite->value.ascii_char, 
        endcoded_arbre_struct.a_droite->value.occurrence
    );

    creer_table(code_struct, endcoded_arbre_struct, endcoded_arbre_struct);

    for(int i=0; i<size; i++){
        printf("\n %c : %s", code_struct[i].ascii_char, code_struct[i].code);
    }

    encoder_fichier(encoded_data, "./test.txt", code_struct);

    compresser_fichier("./test_encode.huf", encoded_data);

    decompresser_fichier("./test_encode.huf", "./test_decode.txt", encoded_data);
    
    printf("\n\nCliquez sur ENTREE pour continuer.");
    while (scanf("%s") != '\n');
    return 0;
}

