#ifndef _GESTION_PARTIE_H_
#define _GESTION_PARTIE_H_

#include <stdlib.h>
//#include "../defines.h"
#include "defineGame.h"
#include "../gestionEquipe/defineEquipe.h"
#include "../gestionJoueurs/gestionMain.h"
#include "../gestionJeuCarte/gestionJeuCarte.h"
#include "../autres/gestionAff.h"
#include "../gestionGame/gestionPli.h"
#include "../gestionEquipe/gestionEquipe.h"
#include "gestionSituationMain.h"

bool gameOver(int ptsEq1, int ptsEq2);
void game(carte *jeu);
void initGame(equipe *teams, situationMain *sitM);
void initMain(equipe *teams, situationMain *sitM);
void endGame(equipe *teams);

#endif
