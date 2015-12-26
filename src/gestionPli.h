#ifndef _GESTION_PLI_H_
#define _GESTION_PLI_H_

#include "defines.h"
#include "gestionMain.h"
#include "gestionSituationMain.h"

pli nextPli(mainJoueur *joueurs, situationMain *sitM);
int valPli(pli* p, couleur atout);

#endif
