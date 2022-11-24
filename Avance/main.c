#include "struct.h"

#define SRC_FILE "./test3.txt"


void file_compressor(datasaver save){
    charstruct char_struct[256] = {NULL, 0};
    arbrestruct arbre_struct[512] = {NULL, NULL, NULL};
    codestruct code_struct[256] = {NULL, NULL};

    char encoded_data[MAX_BIT] = {NULL};
    int size;
    arbrestruct endcoded_arbre_struct;
    char code[32] = {NULL};
    char code2[32] = {NULL};


    /* --------------------------------------------------------------------- */
    /* ------------------------ LECTURE DE L'INPUT ------------------------- */
    /* --------------------------------------------------------------------- */
    printf("\n---------------------------------\n");
    printf("\n\nREADING FILE...");
    size = lire_caracteres(char_struct, SRC_FILE);
    printf("\n -- Read ! --");
    // Uncomment following to print read data
    /*
    printf("\n\n Size of char_struct : %d", size);
    for (int i=0; i<size; i++){
        if (char_struct[i].occurrence != 0){
            if (char_struct[i].ascii_char != '\n') {
                printf("\n   Index : %d \n   Char : '%c' \n   Occurence : %d\n", i, char_struct[i].ascii_char, char_struct[i].occurrence);
            } else
                printf("\n   Index : %d \n   Char : '\\n' \n   Occurence : %d\n", i, char_struct[i].occurrence);
        }   
    }
    */


    /* --------------------------------------------------------------------- */
    /* ------------------------ CREATION ARBRE BIN ------------------------- */
    /* --------------------------------------------------------------------- */
    printf("\n\n---------------------------------\n");
    printf("\n\nBUILDING TREES...");
    endcoded_arbre_struct = creer_arbre(arbre_struct, char_struct, size, endcoded_arbre_struct);
    printf("\n -- Built ! --");
    // Uncomment following to print Tree data
    /*
    printf("\n\n Tree data :");
    printf(
        "\n   Root Char : '%c'\n   Root Occurence : %d\n     Char Gauche : '%c'\n     Occurrence Gauche : %d\n\n     Char Droit : '%c'\n     Occurrence Droit : %d",  
        endcoded_arbre_struct.value.ascii_char, 
        endcoded_arbre_struct.value.occurrence, 
        endcoded_arbre_struct.a_gauche->value.ascii_char, 
        endcoded_arbre_struct.a_gauche->value.occurrence, 
        endcoded_arbre_struct.a_droite->value.ascii_char, 
        endcoded_arbre_struct.a_droite->value.occurrence
    );
    */


    /* --------------------------------------------------------------------- */
    /* ----------------------- TABLE CORRESPONDANCES ----------------------- */
    /* --------------------------------------------------------------------- */
    printf("\n\n---------------------------------\n");
    printf("\n\nCREATING TABLE...");
    int inte = 0;
    creer_table_g(code_struct, &endcoded_arbre_struct, &inte, code);
    creer_table_d(code_struct, &endcoded_arbre_struct, &inte, code2);
    printf("\n -- Created ! --");
    // Uncomment following to print Table
    /*
    printf("\n\n Table :");
    for (int i=0; i<size; i++){
        if (code_struct[i].ascii_char == '\n') {
            printf("\n  > '\\n'  :            |  < %s >", &code_struct[i].code);
        } else
            printf("\n  > '%c'   :            |  < %s >", code_struct[i].ascii_char, &code_struct[i].code);
    }
    */


    /* --------------------------------------------------------------------- */
    /* -------------------------- ENCODING DATA ---------------------------- */
    /* --------------------------------------------------------------------- */
    printf("\n\n---------------------------------\n");
    printf("\n\nENCODING FILE...");
    encoder_fichier(encoded_data, SRC_FILE, code_struct, size);
    printf("\n -- Encoded ! --");
    // Uncomment following to print Encoded data
    /*
    printf("\n\n Encoded data : \n%s", encoded_data);
    */


    /* --------------------------------------------------------------------- */
    /* ------------------------  COMPRESSING FILE  ------------------------- */
    /* --------------------------------------------------------------------- */
    printf("\n\n---------------------------------\n");
    printf("\n\nCOMPRESSING FILE...");
    compresser_fichier("./test_encode.bin", encoded_data);
    printf("\n -- Compressed ! --");
}

void file_uncompressor(char encoded_file_name[], arbrestruct * endcoded_arbre_struct, int size){
    /* --------------------------------------------------------------------- */
    /* ------------------------ UNCOMPRESSING FILE ------------------------- */
    /* --------------------------------------------------------------------- */
    printf("\n\n---------------------------------\n");
    printf("\n\nUNCOMPRESSING FILE...");
    decompresser_fichier(strcat(encoded_file_name, ".bin"), strcat(encoded_file_name, "_decode.txt"), &endcoded_arbre_struct, size);
    printf("\n -- Uncompressed ! --");
    
}


int main(){
    datasaver saves[300];

    printf("\n\n ----- Data Compressor. -----");
    printf("\n Based on Huffman algorithm.");
    
    while(1){
        char file_name[33];
        scanf("%s", &file_name);

        

    }

    printf("\n\nCliquez sur ENTREE pour continuer.");
    while (scanf("%c") != '\n');
    return 0;
}

