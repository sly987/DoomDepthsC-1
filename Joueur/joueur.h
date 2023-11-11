#ifndef JOUEUR_H
#define JOUEUR_H

typedef struct  {
    int vie;
    int attaquesParTour;
    int attaqueMin;
    int attaqueMax;
    int defense;
    int mana;
    int vieMax;
}Joueur;


struct Monstre;

void afficherJoueur(Joueur joueur);

#endif
