#ifndef _GESTION_PLI_H_
#define _GESTION_PLI_H_

//#include "../defines.h"
#include "defineGame.h"
#include "../gestionJoueurs/defineJoueurs.h"
#include "../gestionJoueurs/choixCarte.h"
#include "../gestionGame/gestionSituationMain.h"


pli nextPli(mainJoueur *joueurs, situationMain *sitM);
int valPli(pli* p, couleur atout);

#endif
