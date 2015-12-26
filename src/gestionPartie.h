#ifndef _GESTION_PARTIE_H_
#define _GESTION_PARTIE_H_

#include <stdlib.h>
#include "defines.h"
#include "gestionMain.h"
#include "gestionJeuCarte.h"
#include "gestionAff.h"
#include "gestionPli.h"
#include "gestionEquipe.h"
#include "gestionSituationMain.h"

bool gameOver(int ptsEq1, int ptsEq2);
void game(carte *jeu);
void initGame(equipe *teams, situationMain *sitM);
void initMain(equipe *teams, situationMain *sitM);
void endGame(equipe *teams);

#endif
