//
// Created by Utilisateur on 11/11/2023.
//

#ifndef DOOMDEPTHSC_SORTS_H
#define DOOMDEPTHSC_SORTS_H



typedef struct{
    char* nom;
    char* effet;
    int puissance;
    int consommation;
}sort;
extern sort sorts[];
void afficherSorts(sort sorts[3]);

#endif //DOOMDEPTHSC_SORTS_H
