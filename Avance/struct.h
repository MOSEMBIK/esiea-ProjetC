#ifndef __STRUCT_H__
#define __STRUCT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000

struct char_struct
{
    int nombre;
    unsigned long frequence;
};

int lire_caracteres(struct char_struct*, char[]);

void creer_arbre();

void encoder_frequences();

void associer_frequences_encodage();

void creer_nouveau_fichier();

void compresser_fichier();

void decompresser_fichier();

#endif