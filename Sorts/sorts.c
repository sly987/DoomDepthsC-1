//
// Created by Utilisateur on 11/11/2023.
//

#include "stdio.h"
#include "sorts.h"
#include "../Joueur/joueur.h"



void afficherSorts(sort sorts[]){
    printf("Voici les sorts disponibles : \n");
    for(int i =0; i<3; i++){
        printf("%d : %s\n",i, sorts[i].nom);
        printf("%s et consomme %d mana\n", sorts[i].effet, sorts[i].consommation);
    }

    printf("<<POUR CHAQUE TOUR VOUS VOUS REGENEREZ DE 5 POINTS DE MANA MEME SANS LES UTILISER >>\n");
    printf("\n");
}