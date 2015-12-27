#ifndef _MAIN_JOUEURS_H_
#define _MAIN_JOUEURS_H_

#include "../gestionJeuCarte/defineCarte.h"
#include "../defines.h"

typedef struct mainJoueur mainJoueur;
typedef enum enchereChoixAtout enchereChoixAtout;

enum enchereChoixAtout{
    AUCUNE_ENCHERE,
    COULEUR_SIMPLE,
    SANS_ATOUT,
    TOUT_ATOUT
};

struct mainJoueur{
    carte tabCarte[NBRE_COUL][NBRE_CARTE_COUL];
    //rang tabCarte[NBRE_COUL][8];
    int nbreCarteInit[NBRE_COUL];
    int nbreCarteRestantes[NBRE_COUL];
};

#endif
