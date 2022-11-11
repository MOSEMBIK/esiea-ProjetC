#ifndef __STRUCT_H__
#define __STRUCT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000


typedef struct char_struct
{
    unsigned char ascii_char;
    int occurrence;
} charstruct;


typedef struct arbre_struct
{
    charstruct value;
    struct arbre_struct * a_gauche;
    struct arbre_struct * a_droite;
} arbrestruct;


void lire_caracteres(charstruct[], char[]);

void creer_arbre(arbrestruct[], charstruct[]);

void encoder_frequences();

void associer_frequences_encodage();

void creer_nouveau_fichier();

void compresser_fichier();

void decompresser_fichier();

#endif