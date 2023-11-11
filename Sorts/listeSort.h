//
// Created by yweng on 11/11/2023.
//

#ifndef DOOMDEPTHSC_LISTESORT_H
#define DOOMDEPTHSC_LISTESORT_H
#include "sorts.h"
#include <stdio.h>
#include <stdlib.h>
extern sort sorts[];
sort bouleDeFeu={
        .nom="boule de feu",
        .effet="lance une boule de feu",
        .puissance=100,
        .consommation=10
};
sort murDeFer={
        .nom="mur de fer",
        .effet="invoque un mur de fer qui protege le lanceur contre une attaque",
        .puissance=1,
        .consommation=30
};
sort toucherDivin={
        .nom="toucher divin",
        .effet="soigne le lanceur",
        .puissance=40,
        .consommation=10
};

#endif //DOOMDEPTHSC_LISTESORT_H
