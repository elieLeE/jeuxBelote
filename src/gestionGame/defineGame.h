#ifndef _DEFINE_GAME_H_
#define _DEFINE_GAME_H_

#include "../gestionJeuCarte/defineCarte.h"
#include "../defines.h"

typedef struct pli pli;
typedef struct situationMain situationMain;

struct pli{
    carte tabCarte[NBRE_JOUEURS];
    int nbreCarte;
    int meneur;
    couleur coulAsked;
};

struct situationMain{
    rang atoutTombes[NBRE_CARTE_COUL];
    pli previousPli, actualPli;
    couleur coulAtout;
    carte cartePrise;
    int nbreAtoutsTombes;
    int firstJoueur;	//peux changer a chaque main => celui qui fait le dernier pli entame le suivant
    int preneur;
    int nbrePliDone;
    int numJoueurBeloteEtRe[2];
    int ptsLitige;
    int eqDixDeDer;
};

#endif
