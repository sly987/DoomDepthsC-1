//
// Created by Utilisateur on 11/11/2023.
//

#include "stdio.h"
#include "sorts.h"
#include "../Joueur/joueur.h"



void afficherSorts(struct Sorts sorts){
    printf("Voici les sorts disponibles : \n");
    printf("Sort d'attaque : %d\n", sorts.sortAttaque);
    printf("Sort de defense : %d\n ", sorts.sortDefense);
    printf("Sorts de vie : %d\n", sorts.sortPV);
    printf("<< ATTENTION ! : VOUS PERDREZ 10 POINTS DE MANA POUR CHAQUE SORTS UTILSES >>\n ");
    printf("<< MAIS POUR CHAQUE TOUR VOUS VOUS REGENEREZ DE 5 POINTS DE MANA MEME SANS LES UTILISER >>\n");
    printf("\n");
}