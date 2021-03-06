#ifndef _GESTION_EQUIPE_H_
#define _GESTION_EQUIPE_H_

//#include "../defines.h"
#include "defineEquipe.h"
#include "../gestionGame/gestionPli.h"

void reInitEquipe(equipe *eq);
void addPli(equipe *eq, pli newPli);
void addPoints(equipe *eqs, situationMain *sitM);
void initEquipe(equipe *eq);
const char* nameEquipe(numEquipe num);

#endif
