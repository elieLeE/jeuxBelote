#ifndef _GESTION_SITUATION_MAIN_H_
#define _GESTION_SITUATION_MAIN_H_

#include "../gestionJeuCarte/gestionCarte.h"
#include "defineGame.h"

void reInitSitMain(situationMain *sitM);
void miseAJourSitM(situationMain *sitM);
void setBeloteEtRe(situationMain *sitM, carte *c, int numJ);
void setParamChoixAtout(situationMain *sitM, structChoixAtout *s);

#endif
