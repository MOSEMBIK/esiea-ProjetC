#include "struct.h"


int aStructComparator(arbrestruct * first, arbrestruct * second){
    int firstInt = first->value.occurrence;
    int secondInt = second->value.occurrence;
    return firstInt - secondInt;
}



void decToBinary(int n, char char_tmp[]){
    // array to store binary number
    char tmp[8] = {'0', '0', '0', '0', '0', '0', '0', '0'};
    char binaryNum[8] = {NULL};

    // counter for binary array
    int i = 0;
    while (n > 0) {
        // storing remainder in binary array
        tmp[i] = (n % 2) + '0';
        n = n / 2;
        i++;
    }

    //printf("%s ", tmp);
    // printing binary array in reverse order
    // for(int j=0; j<8; j++){
    //     if(tmp[j] == NULL){
    //         tmp[j] = '0';
    //     }
    // }

    printf("%s\n", tmp);
    strrev(tmp);
    //printf("%s\n", tmp);

    strcpy(char_tmp, binaryNum);
    //printf("%s ", char_tmp);
}



int lire_caracteres(charstruct char_struct[], char nom_fichier[]){
    // printf("\n\n 1.");
    FILE *fPointer;
    fPointer = fopen(nom_fichier, "r");
    char singleLine[MAX_BUFFER_SIZE];

    // printf("\n\n 2.");
    if(fPointer == NULL){
        printf("Erreur fopen\n");
        return -1;
    }

    // printf("\n\n 3.");
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
        // printf("\n %d", strlen(singleLine));
    }

    // printf("\n\n 4.");
    fclose(fPointer);

    return char_count;
}



arbrestruct creer_arbre(arbrestruct arbre_struct[], charstruct char_struct[], int cst_size, arbrestruct endcoded_arbre_struct){
    int arbre_with_occ = 0;

    // Construction des arbres
    //printf("\n\n 1.");
    for (int i=0; i<cst_size; i++){
        arbre_struct[i].value.ascii_char = char_struct[i].ascii_char;
        arbre_struct[i].value.occurrence = char_struct[i].occurrence;

    }

    // Processing de la list arbre_struct
    // printf("\n\n 2.");
    int cpt_a_idx = 0;
    // printf("\n\n 2.1");
    int new_occ = 0;
    int last_index = 0;
    while(cpt_a_idx < 256){
        //printf("\n\n 2.1.1");
        qsort(arbre_struct, (cst_size + (cpt_a_idx/2)), sizeof(arbrestruct), aStructComparator);

        //printf("\n\n 2.1.2");
        arbre_struct[cst_size+(cpt_a_idx/2)].value.ascii_char = NULL;
        new_occ = arbre_struct[0 + cpt_a_idx].value.occurrence + arbre_struct[1 + cpt_a_idx].value.occurrence;
        if(new_occ != 0){
            arbre_struct[cst_size+(cpt_a_idx/2)].value.occurrence = new_occ;
            arbre_struct[cst_size+(cpt_a_idx/2)].a_gauche = &arbre_struct[0 + cpt_a_idx];
            arbre_struct[cst_size+(cpt_a_idx/2)].a_droite = &arbre_struct[1 + cpt_a_idx];
        } else {
            //printf("\n\n BREAK");
            last_index = cst_size+(cpt_a_idx/2) - 1;
            break;
        }
        cpt_a_idx += 2;
    }
    
    return arbre_struct[last_index];
}



void creer_table_g(codestruct code_struct[], arbrestruct * endcoded_arbre_struct, int * i, char code[]){
    // printf("\n\n\n\n\n\n\n\nGENERATING TABLE...");
    // printf("\nLEFT");
    // printf("\nProcessed char : %d", *i);
    // printf("\nBranch |");
    // printf(
    //     "\n Root Char : '%c'\n Root Occurence : %d\n\n    Char Gauche : '%c'\n    Occurrence Gauche : %d\n\n    Char Droit : '%c'\n    Occurrence Droit : %d",  
    //     endcoded_arbre_struct->value.ascii_char, 
    //     endcoded_arbre_struct->value.occurrence, 
    //     endcoded_arbre_struct->a_gauche->value.ascii_char, 
    //     endcoded_arbre_struct->a_gauche->value.occurrence, 
    //     endcoded_arbre_struct->a_droite->value.ascii_char, 
    //     endcoded_arbre_struct->a_droite->value.occurrence
    // );
    char ch;




    // Parcours Gauche
    if (endcoded_arbre_struct->a_gauche->value.ascii_char == NULL){
        // printf("\n\n left null - GO LEFT");
        ch = '0';
        code = strncat(code, &ch, 1);
        // printf("\n RECURSIVE CALL");
        creer_table_g(code_struct, endcoded_arbre_struct->a_gauche, i, code);
    } else {
        ch = '0';
        code = strncat(code, &ch, 1);
        code_struct[*i].ascii_char = endcoded_arbre_struct->a_gauche->value.ascii_char;
        strcpy(code_struct[*i].code, code);
        

        // printf("\n\n Add to codestruct [%d] : ", *i);
        // printf("\n   left -\n       char : '%c'\n       code : %s", code_struct[*i].ascii_char, code_struct[*i].code);
        ++*i;
    }
    code[strlen(code)-1] = '\0';



    // Parcours Droit
    if (endcoded_arbre_struct->a_droite->value.ascii_char == NULL){
        // printf("\n\n right null - GO RIGHT");
        ch = '1';
        code = strncat(code, &ch, 1);
        // printf("\n RECURSIVE CALL");
        creer_table_g(code_struct, endcoded_arbre_struct->a_droite, i, code);
    } else {
        ch = '1';
        code = strncat(code, &ch, 1);
        code_struct[*i].ascii_char = endcoded_arbre_struct->a_droite->value.ascii_char;
        strcpy(code_struct[*i].code, code);
        

        // printf("\n\n Add to codestruct [%d] : ", *i);
        // printf("\n   right -\n       char : '%c'\n       code : %s", code_struct[*i].ascii_char, code_struct[*i].code);
        ++*i;
    }
    code[strlen(code)-1] = '\0';
}

void creer_table_d(codestruct code_struct[], arbrestruct * endcoded_arbre_struct, int * i, char code[]){
    // printf("\n\n\n\n\n\n\n\nGENERATING TABLE...");
    // printf("\nRIGHT");
    // printf("\nProcessed char : %d", *i);
    // printf("\nBranch |");
    // printf(
    //     "\n Root Char : '%c'\n Root Occurence : %d\n\n    Char Gauche : '%c'\n    Occurrence Gauche : %d\n\n    Char Droit : '%c'\n    Occurrence Droit : %d",  
    //     endcoded_arbre_struct->value.ascii_char, 
    //     endcoded_arbre_struct->value.occurrence, 
    //     endcoded_arbre_struct->a_gauche->value.ascii_char, 
    //     endcoded_arbre_struct->a_gauche->value.occurrence, 
    //     endcoded_arbre_struct->a_droite->value.ascii_char, 
    //     endcoded_arbre_struct->a_droite->value.occurrence
    // );
    char ch;



    // Parcours Droit
    if (endcoded_arbre_struct->a_droite->value.ascii_char == NULL){
        // printf("\n\n right null - GO RIGHT");
        ch = '0';
        code = strncat(code, &ch, 1);
        // printf("\n RECURSIVE CALL");
        creer_table_d(code_struct, endcoded_arbre_struct->a_droite, i, code);
    } else {
        ch = '1';
        code = strncat(code, &ch, 1);
        code_struct[*i].ascii_char = endcoded_arbre_struct->a_droite->value.ascii_char;
        strcpy(code_struct[*i].code, code);
        

        // printf("\n\n Add to codestruct [%d] : ", *i);
        // printf("\n   right -\n       char : '%c'\n       code : %s", code_struct[*i].ascii_char, code_struct[*i].code);
        ++*i;
    }
    code[strlen(code)-1] = '\0';




    // Parcours Gauche
    if (endcoded_arbre_struct->a_gauche->value.ascii_char == NULL){
        // printf("\n\n left null - GO LEFT");
        ch = '1';
        code = strncat(code, &ch, 1);
        // printf("\n RECURSIVE CALL");
        creer_table_d(code_struct, endcoded_arbre_struct->a_gauche, i, code);
    } else {
        ch = '0';
        code = strncat(code, &ch, 1);
        code_struct[*i].ascii_char = endcoded_arbre_struct->a_gauche->value.ascii_char;
        strcpy(code_struct[*i].code, code);
        

        // printf("\n\n Add to codestruct [%d] : ", *i);
        // printf("\n   left -\n       char : '%c'\n       code : %s", code_struct[*i].ascii_char, code_struct[*i].code);
        ++*i;
    }
    code[strlen(code)-1] = '\0';
}



void encoder_fichier(char void_char[], char nom_fichier[], codestruct code_struct[], int size){
    printf("\n\nENCODING FILE...");
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
        // printf("\n\n 3.1");
        fgets(singleLine, MAX_BUFFER_SIZE, fPointer);
        // printf("\n\n 3.2");
        for(int i=0; i<strlen(singleLine); i++){
            // printf("\n\n Line char : '%c'", singleLine[i]);
            for (int j=0; j<size; j++){
                if (code_struct[j].ascii_char == singleLine[i]){
                    //printf("\n Struct char : '%c'", code_struct[j].ascii_char);
                    //printf("\n Struct code : %d", &code_struct[j].code);
                    void_char = strncat(void_char, code_struct[j].code, sizeof(code_struct[j].code));
                }
            }
            // printf("\n\n --------");
        }
    }
    fclose(fPointer);
}



void compresser_fichier(char fichier_output[], char encoded_char[]) {
    printf("\n\nCOMPRESSING FILE...");
    printf("\n\n 1.");
    FILE *fPointer;
    FILE *fPointer2;
    fPointer = fopen(fichier_output, "wb");
    fclose(fPointer);
    fPointer = fopen(fichier_output, "wb+");

    printf("\n\n 2.");
    if(fPointer == NULL){
        printf("Erreur fopen\n");
        return;
    }

    printf("\n\n 3.");
    for(int i=0; i<strlen(encoded_char); i+=8){
        char substring[9] = {NULL};
        int count = 0;
        
        for(int j=0; j<8; j++){
            substring[j] = encoded_char[j+i];
        }

        for(int j=7; j>=0; j--){
            if(substring[j] == '1'){
                count += pow(2,7-j);
            }
        }

        //set value to write
        unsigned char to_write;
        to_write = count;
        printf("%d ", to_write);

        //attempt to write to file
        if(fwrite(&to_write, sizeof to_write, 1, fPointer) != 1){
            fprintf(stderr, "Error writing to file!\n");
            exit(EXIT_FAILURE);
        }
    }

    printf("\n\n 4.");
    fclose(fPointer);    
}



void decompresser_fichier(char fichier_encode[], char fichier_decode[], arbrestruct arbre_struct[], int size) {
    printf("\n\nUNCOMPRESSING FILE...");
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

    int val;
    char decode[size];
    char char_tmp[8];
	while ((val=fgetc(fPointer)) != EOF){
        printf("%d ", val);
        decToBinary(val, char_tmp);

        //printf("%s ", char_tmp);

        strcat(decode, char_tmp);
        //printf("%s\n", decode);
	}

    while((val=fgetc(fPointer)) != EOF){
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