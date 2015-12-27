#ifndef _DEFINE_EQUIPE_H_
#define _DEFINE_EQUIPE_H_

#include "../gestionGame/defineGame.h"
#include "../defines.h"

typedef struct equipe equipe;
typedef enum numEquipe numEquipe;

enum numEquipe{
    EQUIPE_1,
    EQUIPE_2
};

struct equipe{
    pli tabPli[NBRE_PLIS];
    int nbrePliDone;
    int ptsTotal;
    int ptsActuel;
};

#endif
