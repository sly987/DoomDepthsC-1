#include "sauvegarde.h"
#include <stdio.h>
#include <stdlib.h>
// Fonction pour sauvegarder la partie
void sauvegarderPartie(GameState gameState) {
    FILE *fichier = fopen("sauvegarde.dat", "wb");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier de sauvegarde.\n");
        return;
    }

    fwrite(&gameState.heros, sizeof(Joueur), 1, fichier);


    fwrite(&gameState.nbArme, sizeof(int), 1, fichier);
    fwrite(&gameState.listeArmes, sizeof(arme[4]), 1, fichier);
    fwrite(&gameState.armeEquipe, sizeof(arme), 1, fichier);
    fwrite(&gameState.equiperArme, sizeof(short), 1, fichier);

    fwrite(&gameState.nbArmure, sizeof(int), 1, fichier);
    fwrite(&gameState.listeArmures, sizeof(armure[4]), 1, fichier);
    fwrite(&gameState.armureEquipe, sizeof(armure), 1, fichier);
    fwrite(&gameState.equiperArmure, sizeof(short), 1, fichier);



    fwrite(&gameState.carte, sizeof(Map), 1, fichier);
    fwrite(&gameState.joueurX, sizeof(int), 1, fichier);
    fwrite(&gameState.joueurY, sizeof(int), 1, fichier);

    fclose(fichier);
}


// Fonction pour charger la partie
int chargerPartie(GameState *gameState) {
    FILE *fichier = fopen("sauvegarde.dat", "rb");
    if (fichier == NULL) {
        printf("Aucun fichier de sauvegarde trouvé.\n");
        return 0;  // Échec de chargement
    }

    if (fread(&gameState->heros, sizeof(Joueur), 1, fichier) != 1) {
        printf("Erreur de lecture des données du joueur.\n");
        fclose(fichier);
        return 0;
    }

    if (fread(&gameState->nbArme, sizeof(int), 1, fichier) != 1) {
        printf("Erreur de lecture du nombre d'armes.\n");
        fclose(fichier);
        return 0;
    }

    if (fread(&gameState->listeArmes, sizeof(arme[4]), 1, fichier) != 1) {
        printf("Erreur de lecture sur la liste des armes.\n");
        fclose(fichier);
        return 0;
    }

    if (fread(&gameState->armeEquipe, sizeof(arme), 1, fichier) != 1) {
        printf("Erreur de lecture sur l'arme equipé.\n");
        fclose(fichier);
        return 0;
    }

    if (fread(&gameState->equiperArme, sizeof(short), 1, fichier) != 1) {
        printf("Aucune arme équipé.\n");
        fclose(fichier);
        return 0;
    }

    if (fread(&gameState->nbArmure, sizeof(int), 1, fichier) != 1) {
        printf("Erreur de lecture sur le nombre des armures.\n");
        fclose(fichier);
        return 0;
    }
    if (fread(&gameState->listeArmures, sizeof(armure[4]), 1, fichier) != 1) {
        printf("Erreur de lecture sur la liste des armures.\n");
        fclose(fichier);
        return 0;
    }



    if (fread(&gameState->armureEquipe, sizeof(armure), 1, fichier) != 1) {
        printf("Erreur de lecture sur l'armure équipé.\n");
        fclose(fichier);
        return 0;
    }

    if (fread(&gameState->equiperArmure, sizeof(short), 1, fichier) != 1) {
        printf("Aucune armure équipé.\n");
        fclose(fichier);
        return 0;
    }



    if (fread(&gameState->carte, sizeof(Map), 1, fichier) != 1) {
        printf("Erreur de lecture des données de la carte.\n");
        fclose(fichier);
        return 0;
    }

    if (fread(&gameState->joueurX, sizeof(int), 1, fichier) != 1
    ||fread(&gameState->joueurY, sizeof(int), 1, fichier) != 1) {
        printf("Erreur de lecture de la position du joueur.\n");
        fclose(fichier);
        return 0;  // Échec de chargement
    }

    fclose(fichier);

    return 1;
}


