#ifndef __STRUCT_H__
#define __STRUCT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000

/* ----------------------------------------------------------------- */
/* STUCTURES */

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


typedef struct code_struct
{
    unsigned char ascii_char;
    unsigned char code[32];
} codestruct;

/* ----------------------------------------------------------------- */
/* FONCTIONS */

//
// 
// param1 : 
// param2 : 
void lire_caracteres(charstruct[], char[]);

// Crée une liste d'arbre contenant des charstruct et les concatenes puis 
// retourne une liste de codestruct liant char et encodage
//
// param1 : char vide servant d'output ("" -> "110011101010001110...")
// param2 : texte en input
// param3 : codestruct
void creer_arbre(arbrestruct[], charstruct[], codestruct[]); // ToDo

// Prend texte input et retourne string binaire encodee selon code
//
// param1 : char vide servant d'output ("" -> "110011101010001110...")
// param2 : texte en input
// param3 : codestruct
void encoder_fichier(char[], char[], codestruct[]);

// Prend string binaire encodee selon arbre et l'ecrit dans un fichier .txt
//
// param1 : path fichier d'output 
// param2 : texte encode
void compresser_fichier(char[], char[]);

// Inverse de compresser en suivant arbre
//
// param1 : path fichier d'input encodee
// param2 : path fichier d'output
// param3 : arbrestruct
void decompresser_fichier(char[], char[], arbrestruct[]);

#endif