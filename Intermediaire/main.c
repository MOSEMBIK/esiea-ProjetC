#include <stdio.h>
#include <string.h>


int input_reader(int nb_a_retirer, int max){
    printf("Combien prenez-vous d'allumettes ? (entre 1 et %d compris)\n", max);
    scanf("%d", &nb_a_retirer);
    while(nb_a_retirer > max || nb_a_retirer < 1) {
        printf("Erreur ! Prise invalide : %d\n", nb_a_retirer);
        printf("Recommencez !\n");

        fflush(stdin);
        scanf("%d", &nb_a_retirer);
    }
    return nb_a_retirer;
}


int game(int nb_allumettes, char joueur_actuel[]){
    int nb_a_retirer = 0;
    printf("Nombre d'allumettes restantes : %d\n", nb_allumettes);
    for(int i=0; i<nb_allumettes; i++){
        printf("| ");
    }
    printf("\nAu tour de %s\n", joueur_actuel);

    if(nb_allumettes >= 3){
        nb_a_retirer = input_reader(nb_a_retirer, 3);
    }

    if(nb_allumettes == 2){
        nb_a_retirer = input_reader(nb_a_retirer, 2);
    }

    if(nb_allumettes == 1){
        nb_a_retirer = 1;
    }

    printf("%s prend %d allumette(s)\n", joueur_actuel, nb_a_retirer);
    printf("\n");
    nb_allumettes = nb_allumettes - nb_a_retirer;

    return nb_allumettes;
}


int main() {
    char joueur1[20];
    char joueur2[20];
    char joueur_actuel[20];
    int niveau = 1;
    int nb_allumettes = 20;

    printf("Nom du joueur 1 :");
    scanf("%s", joueur1);
    fflush(stdin);
    printf("Nom du joueur 2 :");
    scanf("%s", joueur2);
    fflush(stdin);

    printf("Jeu contre %s, niveau %d, avec %d allumettes au depart \n", joueur2, niveau, nb_allumettes);
    printf("\n");

    strncpy(joueur_actuel, joueur1, 20);
    while(nb_allumettes != 0){
        if(strcmp(joueur_actuel, joueur1) == 0){
            nb_allumettes = game(nb_allumettes, joueur_actuel);
            strncpy(joueur_actuel, joueur2, 20);
        } else if(strcmp(joueur_actuel, joueur2) == 0){
            nb_allumettes = game(nb_allumettes, joueur_actuel);
            strncpy(joueur_actuel, joueur1, 20);
        }
    }

    printf("FIN DE PARTIE\n");
    printf("Le joueur %s a gagne !\n", joueur_actuel);
}
