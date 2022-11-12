#include "struct.h"

int main(){
    charstruct char_struct[256] = {NULL, 0};
    arbrestruct arbre_struct[512] = {NULL, NULL, NULL};
    codestruct code_struct[256] = {NULL, NULL};

    unsigned char encoded_data[] = {NULL};
    int size;
    arbrestruct endcoded_arbre_struct;
    char code[32] = {NULL};
    char code2[32] = {NULL};


    /* --------------------------------------------------------------------- */
    /* ----------------------- LECTURE DE L'INPUT -------------------------- */
    /* --------------------------------------------------------------------- */
    printf("\n\n---------------------------------\n\n");
    printf("\n\nREADING FILE...");
    size = lire_caracteres(char_struct, "./test.txt");
    // printf("\n\n Size of char_struct : %d", size);
    // for (int i=0; i<size; i++){
    //     if (char_struct[i].occurrence != 0){
    //         if (char_struct[i].ascii_char != '\n') {
    //             printf("\n   Index : %d \n   Char : '%c' \n   Occurence : %d\n", i, char_struct[i].ascii_char, char_struct[i].occurrence);
    //         } else
    //             printf("\n   Index : %d \n   Char : '\\n' \n   Occurence : %d\n", i, char_struct[i].occurrence);
    //     }   
    // }


    /* --------------------------------------------------------------------- */
    /* ----------------------- CREATION ARBRE BIN -------------------------- */
    /* --------------------------------------------------------------------- */
    printf("\n\n---------------------------------\n\n");
    printf("\n\nBUILDING TREES...");
    endcoded_arbre_struct = creer_arbre(arbre_struct, char_struct, size, endcoded_arbre_struct);
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


    /* --------------------------------------------------------------------- */
    /* ---------------------- TABLE CORRESPONDANCES ------------------------ */
    /* --------------------------------------------------------------------- */
    printf("\n\n---------------------------------\n\n");
    printf("\n\nCREATING TABLE...");
    int inte = 0;
    creer_table_g(code_struct, &endcoded_arbre_struct, &inte, code);
    creer_table_d(code_struct, &endcoded_arbre_struct, &inte, code2);
    printf("\n\n Table :");
    for (int i=0; i<size; i++){
        printf("\n\n   char : '%c'\n   code : %s", code_struct[i].ascii_char, &code_struct[i].code);
    }


    /* --------------------------------------------------------------------- */
    /* -----------------------                    -------------------------- */
    /* --------------------------------------------------------------------- */
    printf("\n\n---------------------------------\n\n");
    // encoder_fichier(encoded_data, "./test.txt", code_struct);


    /* --------------------------------------------------------------------- */
    /* -----------------------                    -------------------------- */
    /* --------------------------------------------------------------------- */
    printf("\n\n---------------------------------\n\n");
    // compresser_fichier("./test_encode.huf", encoded_data);


    /* --------------------------------------------------------------------- */
    /* -----------------------                    -------------------------- */
    /* --------------------------------------------------------------------- */
    printf("\n\n---------------------------------\n\n");
    // decompresser_fichier("./test_encode.huf", "./test_decode.txt", encoded_data);
    



    printf("\n\nCliquez sur ENTREE pour continuer.");
    while (scanf("%c") != '\n');
    return 0;
}

