#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H

#include "../Joueur/joueur.h"
#include "../carte/carte.h"
#include "../equipement/arme.h"
#include "../equipement/armure.h"

typedef struct {
    Joueur heros;

    armure listeArmures[4];
    int nbArmure;
    armure armureEquipe;
    short equiperArmure;

    arme listeArmes[4];
    int nbArme;
    arme armeEquipe;
    short equiperArme;

    Map carte;
    int joueurX;
    int joueurY;
} GameState;


void sauvegarderPartie(GameState gameState);
int chargerPartie(GameState *gameState);

#endif // SAUVEGARDE_H
