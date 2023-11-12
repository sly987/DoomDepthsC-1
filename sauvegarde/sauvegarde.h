#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H

#include "../Joueur/joueur.h"
#include "../carte/carte.h"
#include "../equipement/arme.h"
#include "../equipement/armure.h"

typedef struct {
    Joueur heros;
    //armure armure1;
    //arme arme1;
    Map carte;
    int joueurX;
    int joueurY;
} GameState;


void sauvegarderPartie(GameState gameState);
int chargerPartie(GameState *gameState);

#endif // SAUVEGARDE_H
