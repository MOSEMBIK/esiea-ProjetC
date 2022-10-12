#include <stdio.h>


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


int game(int nb_allumettes, char joueur_actuel){
    int nb_a_retirer = 0;
    printf("Nombre d'allumettes restantes : %d\n", nb_allumettes);
    for(int i=0; i<nb_allumettes; i++){
        printf("| ");
    }
    printf("\nAu tour de %c\n", joueur_actuel);

    if(nb_allumettes >= 3){
        nb_a_retirer = input_reader(nb_a_retirer, 3);
    }

    if(nb_allumettes == 2){
        nb_a_retirer = input_reader(nb_a_retirer, 2);
    }

    if(nb_allumettes == 1){
        nb_a_retirer = 1;
    }

    printf("%c prend %d allumette(s)\n", joueur_actuel, nb_a_retirer);
    printf("\n");
    nb_allumettes = nb_allumettes - nb_a_retirer;

    return nb_allumettes;
}


int main() {
    char joueur1;
    char joueur2;
    char joueur_actuel;
    int niveau = 1;
    int nb_allumettes = 20;

    printf("Nom du joueur 1 :");
    scanf("%c", &joueur1);
    fflush(stdin);
    printf("Nom du joueur 2 :");
    scanf("%c", &joueur2);
    fflush(stdin);

    printf("Jeu contre %c, niveau %d, avec %d allumettes au depart \n", joueur2, niveau, nb_allumettes);
    printf("\n");

    joueur_actuel = joueur1;
    while(nb_allumettes != 0){
        if(joueur_actuel == joueur1){
            nb_allumettes = game(nb_allumettes, joueur_actuel);
            joueur_actuel = joueur2;
        } else if(joueur_actuel == joueur2){
            nb_allumettes = game(nb_allumettes, joueur_actuel);
            joueur_actuel = joueur1;
        }
    }

    printf("FIN DE PARTIE\n");
    printf("Le joueur %c a gagne !\n", joueur_actuel);
}
