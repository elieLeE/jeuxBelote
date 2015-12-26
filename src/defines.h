#ifndef _DEFINES_H_
#define _DEFINES_H_

#include <stdio.h>
#include <stdbool.h>

#define NBRE_CARTES 32
#define NBRE_CARTE_FiRST_DIVISION 5
#define NBRE_CARTE_MAIN 8
#define NBRE_CARTE_COUL 8
#define NBRE_COUL 4

#define NBRE_PLIS 8

#define NBRE_EQ 2
#define NBRE_JOUEURS 4

#define LIM_PRISE 50
#define LIM_GAIN 500

#define BELOTE_ET_RE 20
#define DIX_DE_DER 10
#define CONTRAT_NON_REMPLIE 162
#define CAPOT 252

#define LITIGE_CONTRAT 81
#define MIN_PTS_CONTRAT 82

typedef struct carte carte;
typedef struct mainJoueur mainJoueur;
typedef struct situationMain situationMain;
typedef struct pli pli;
typedef struct equipe equipe;
typedef enum rang rang;
typedef enum couleur couleur;
typedef enum compCarte compCarte;

enum rang{
    SEPT,
    HUIT,
    NEUF,
    VALET,
    DAME,
    ROI,
    DIX,
    AS
};

enum couleur{
    CARREAU,
    COEUR,
    PIQUE,
    TREFLE
};

enum compCarte{
    CARTE_1,
    CARTE_2,
    SAME_CARTE
};

enum numEquipe{
    EQUIPE_1,
    EQUIPE_2
};

struct carte{
    rang r;
    couleur c;
    bool dejaJoue;
};

struct mainJoueur{
    carte tabCarte[NBRE_COUL][8];
    //rang tabCarte[NBRE_COUL][8];
    int nbreCarteInit[NBRE_COUL];
    int nbreCarteRestantes[NBRE_COUL];
};

struct pli{
    carte tabCarte[4];
    int nbreCarte;
    int meneur;
    couleur coulAsked;
};

struct equipe{
    pli tabPli[NBRE_PLIS];
    int nbrePliDone;
    int ptsTotal;
    int ptsActuel;
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

const char* nameCoul(couleur c);
const char* nameRang(rang r);

#endif
