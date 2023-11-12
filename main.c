#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Monstre/monstre.h"
#include "Joueur/joueur.h"
#include "equipement/listeArme.h"
#include "equipement/listeArmure.h"
#include "carte/listeCarte.h"
#include "combat/combat.h"
#include "Monstre/listeBoss.h"
#include "sauvegarde/sauvegarde.h"
#include "Sorts/listeSort.h"
#include "Sorts/sorts.h"
#include <unistd.h>
int main() {
    srand(time(NULL));

    char choix;
    printf("Bienvenue dans DoomDepthsC!\n");
    printf("1. Nouvelle partie\n");
    printf("2. Charger une partie\n");
    do {
        scanf(" %c", &choix);
    } while (choix != '1' && choix != '2');
    system("cls");
    Joueur heros;
    arme armeR3[] = {dague, baton, marteau};
    arme armeR2[] = {epee, hache};
    arme armeR1[] = {excalibur};
    armes[0] = armeR3;
    armes[1] = armeR2;
    armes[2] = armeR1;

    armure armureR3[] = {cuir};
    armure armureR2[] = {fer};
    armure armureR1[] = {adamantium};
    armures[0] = armureR3;
    armures[1] = armureR2;
    armures[2] = armureR1;
    sorts[0]=bouleDeFeu;
    sorts[1]=murDeFer;
    sorts[2]=toucherDivin;

    if (choix == '1') {
        // Initialiser un nouveau jeu
//        printf("Bienvenue a toi, hero\nOn vous attendez avec impatience\n");
//        sleep(2);
//        printf("Pour le bien du peuple, sauvez nous des griffes du roi demon!\n");
//        sleep(3);
//        printf("Il ne reste plus beaucoup de temps!\n");
//        sleep(2);
//        printf("Les autres heros affrontent l'armee de demons et les tiennent occuper pour l'instant\n");
//        sleep(4);
//        printf("Nous sommes a un champ du chateau du roi demon\n");
//        sleep(3);
//        printf("Pour etre le plus rapide et discret possible, je n'ai pas pris d'equipement avec moi\n");
//        sleep(5);
//        printf("Attaquer le roi demon quand vous serez pret\n");
//        sleep(2);
//        printf("Les espoirs du monde repose sur vos epaules\n");
//        sleep(2);
//        printf("signe : un malheureux\n\n");
//        sleep(1);
//        printf("vous reposez la lettre\n");
//        sleep(5);
//        system("cls");
        heros = (Joueur){
                .vie = 100,
                .attaquesParTour = 2,
                .attaqueMin = 50,
                .attaqueMax = 80,
                .defense = 20,
                .mana=100,
                .vieMax=100
        };
        changerCarte('0');
        joueurX = 2;
        joueurY = 2;
    } else if (choix == '2') {
        // Charger une partie sauvegardée
        GameState gameState;
        gameState.heros = heros;
        gameState.carte = carteActuel;


        if (chargerPartie(&gameState) == 0) {
            printf("Impossible de charger la partie. Nouvelle partie en cours.\n");
            heros = (Joueur){
                    .vie = 100,
                    .attaquesParTour = 2,
                    .attaqueMin = 50,
                    .attaqueMax = 80,
                    .defense = 20
            };

            changerCarte('0');
            joueurX = 2;
            joueurY = 2;
        } else {
            heros = gameState.heros;
            carteActuel = gameState.carte;



            // Remplissez gameState avec d'autres données de la partie, si nécessaire
        }
    }

    char input = ' ';
    while (input != 'p') {
        afficherMap(carteActuel);
        printf("taper la touche h pour voir les touches\n");
        fflush(stdin);
        scanf(" %c", &input);
        if (input == '!') {
            GameState gameStateToSave;
            gameStateToSave.heros = heros;
            gameStateToSave.carte = carteActuel;
            // Remplissez gameStateToSave avec d'autres données de la partie, si nécessaire



            sauvegarderPartie(gameStateToSave);
            printf("Partie sauvegardée.\n");
        }else if(input =='h'){
            printf("z pour monter d'une case\ns por descendre d'une case\nq pour aller d'une case vers la gauche\nd pour aller d'une case vers la droite\n");
            printf("j pour voir les stats du joueur et l'equipement equipe\n");
            printf("w pour voir la liste des armes possede\na pour voir la liste des armures possede\n");
            printf("! pour sauvegarder\np pour quitter le jeu\n");
        }else if(input =='j'){
            afficherJoueur(heros);
            afficherArmeEquipe();
            printf("\n");
            afficherArmureEquipe();
            printf("\n");
        }else if(input =='w'){
            afficherListeArme(nbArme, &heros );
        }else if(input =='a'){
            afficherListeArmure(nbArmure, &heros);
        }
        else {
            bouger(input, &heros);
        }
        fflush(stdout);
        if (heros.vie <= 0) {
            break;
        }
    }


    return 0;
}
