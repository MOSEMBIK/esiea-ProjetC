#include "struct.h"


int aStructComparator(arbrestruct * first, arbrestruct * second) {
    int firstInt = first->value.occurrence;
    int secondInt = second->value.occurrence;
    return firstInt - secondInt;
}


int lire_caracteres(charstruct char_struct[], char nom_fichier[]){
    printf("\n\n READING FILE...");
    printf("\n\n 1.");
    FILE *fPointer;
    fPointer = fopen(nom_fichier, "r");
    char singleLine[MAX_BUFFER_SIZE];

    printf("\n\n 2.");
    if(fPointer == NULL){
        printf("Erreur fopen\n");
        return -1;
    }

    printf("\n\n 3.");
    int char_idx = 0;
    int char_count = 0;
    charindexstruct arr[MAX_BUFFER_SIZE] = {NULL, 0};
    while(!feof(fPointer)){
        fgets(singleLine, MAX_BUFFER_SIZE, fPointer);
        for(int i=0; i<strlen(singleLine); i++){
            if (arr[singleLine[i]].ascii_char == NULL){
                arr[singleLine[i]].ascii_char = singleLine[i];
                arr[singleLine[i]].index = char_count;
                char_count++;
            }
            char_idx = arr[singleLine[i]].index;
            if (char_struct[char_idx].ascii_char == NULL)
                char_struct[char_idx].ascii_char = singleLine[i];
            char_struct[char_idx].occurrence++;
        }
    }

    printf("\n\n 4.");
    fclose(fPointer);

    return char_count;
}


void creer_arbre(arbrestruct arbre_struct[], charstruct char_struct[], int cst_size, codestruct code[], arbrestruct endcoded_arbre_struct){
    printf("\n\n BUILDING TREES...");
    int arbre_with_occ = 0;

    // Construction des arbres
    printf("\n\n 1.");
    for (int i=0; i<cst_size; i++){
        arbre_struct[i].value.ascii_char = char_struct[i].ascii_char;
        arbre_struct[i].value.occurrence = char_struct[i].occurrence;

    }

    // Tri des arbre sur occurrence de value
    printf("\n\n 2.");
    qsort(arbre_struct, cst_size, sizeof(arbrestruct), aStructComparator);
    printf("\t\n Size of char_struct : %d\n", cst_size);
    for (int i=0; i<cst_size; i++){
        if (arbre_struct[i].value.occurrence != 0){
            printf("\n Index : %d \n Char : '%c' \n Occurence : %d\n", i, arbre_struct[i].value.ascii_char, arbre_struct[i].value.occurrence);
            arbre_with_occ++;
        }   
    }

    // Processing de la list arbre_struct
    printf("\n\n 2.");
    int cpt_a_idx = 0;
    printf("\n\n 2.1");
    while(cpt_a_idx < 256){
        printf("\n\n 2.1.1");
        qsort(arbre_struct, (cst_size + (cpt_a_idx/2)), sizeof(arbrestruct), aStructComparator);

        //printf("\n\n 2.1.2");
        arbre_struct[cst_size+(cpt_a_idx/2)].value.ascii_char = NULL;
        printf("\n Index 1 : %d", 0 + cpt_a_idx);
        printf("\n Char G : '%c'", arbre_struct[0 + cpt_a_idx].value.ascii_char);
        printf("\n Occ G : %d", arbre_struct[0 + cpt_a_idx].value.occurrence);
        printf("\n Index 2 : %d", 1 + cpt_a_idx);
        printf("\n Char D : '%c'", arbre_struct[1 + cpt_a_idx].value.ascii_char);
        printf("\n Occ D : %d", arbre_struct[1 + cpt_a_idx].value.occurrence);
        arbre_struct[cst_size+(cpt_a_idx/2)].value.occurrence = arbre_struct[0 + cpt_a_idx].value.occurrence + arbre_struct[1 + cpt_a_idx].value.occurrence;
        arbre_struct[cst_size+(cpt_a_idx/2)].a_gauche = &arbre_struct[0 + cpt_a_idx];
        arbre_struct[cst_size+(cpt_a_idx/2)].a_droite = &arbre_struct[1 + cpt_a_idx];
        if(arbre_struct[cst_size+(cpt_a_idx/2)].value.occurrence != 0){
            printf("\n\n Index : %d", cst_size+(cpt_a_idx/2));
            printf("\n Global occ : %d", arbre_struct[cst_size+(cpt_a_idx/2)].value.occurrence);
            printf("\n Char G : '%c'", arbre_struct[cst_size+(cpt_a_idx/2)].a_gauche->value.ascii_char);
            printf("\n Occ G : %d", arbre_struct[cst_size+(cpt_a_idx/2)].a_gauche->value.occurrence);
            printf("\n Char D : '%c'", arbre_struct[cst_size+(cpt_a_idx/2)].a_droite->value.ascii_char);
            printf("\n Occ D : %d", arbre_struct[cst_size+(cpt_a_idx/2)].a_droite->value.occurrence);
        } else {
            break;
        }
        cpt_a_idx += 2;
    }
    
    printf("\n\n 2.2");
    // printf("\n Occ G : %d", arbre_struct[78].a_gauche->value.occurrence);
    // printf(
    //     "\n Index : %d\n Char : '%c'\n Occurence : %d\n Char Gauche : %c\n Occurrence Gauche : %d\n Char Droit : %c\n Occurrence Droit : %d", 
    //     50, 
    //     arbre_struct[50].value.ascii_char, 
    //     arbre_struct[50].value.occurrence, 
    //     arbre_struct[50].a_gauche->value.ascii_char, 
    //     arbre_struct[50].a_gauche->value.occurrence, 
    //     arbre_struct[50].a_droite->value.ascii_char, 
    //     arbre_struct[50].a_droite->value.occurrence
    // );
    int last_index = 0;
    for (int i=cst_size; i<cpt_a_idx; i++){
        if (arbre_struct[i].value.occurrence != 0){
            printf(
                "\n\n Index : %d\n Char : '%c'\n Occurence : %d\n Char Gauche : '%c'\n Occurrence Gauche : %d\n Char Droit : '%c'\n Occurrence Droit : %d", 
                i, 
                arbre_struct[i].value.ascii_char, 
                arbre_struct[i].value.occurrence, 
                arbre_struct[i].a_gauche->value.ascii_char, 
                arbre_struct[i].a_gauche->value.occurrence, 
                arbre_struct[i].a_droite->value.ascii_char, 
                arbre_struct[i].a_droite->value.occurrence
            );
            last_index = i-1;
        }
    }
    endcoded_arbre_struct = arbre_struct[last_index];

    printf("\n Char : '%c' \n Occurence : %d\n", endcoded_arbre_struct.a_gauche->value.ascii_char, endcoded_arbre_struct.a_gauche->value.occurrence);

    // Création du tableau de correspondances

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
    fPointer = fopen(fichier_output, "wb");

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
    fPointer = fopen(fichier_encode, "rb");

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
