#ifndef _CHOIX_ATOUT_H_
#define _CHOIX_ATOUT_H_

#include <stdbool.h>
#include "defineJoueurs.h"
#include "../gestionGame/defineGame.h"
#include "../gestionJeuCarte/gestionCarte.h"
#include "../autres/gestionAff.h"
#include "../gestionGame/gestionSituationMain.h"
#include "gestionMain.h"

const char* nameModeAtout(enchereChoixAtout m);
void choixModeMain(mainJoueur *joueurs, situationMain *sitM, carte carteVisible);

bool priseOrNot(mainJoueur *m, structChoixAtout *s);
void initStructChoixAtout(structChoixAtout *s, carte* c);

bool prendColor(mainJoueur *m, carte *c, bool humanPlayer);
bool prendColorHumanPlayer(mainJoueur *m, carte *c);
bool prendColorIA(mainJoueur *m, carte *c);

bool priseNonObligatoire(mainJoueur *m, carte *c, couleur *colorChosen, bool humanPlayer);
bool priseNonObligatoireHumanPlayer(mainJoueur *m, carte *c, couleur *colorChosen);
bool priseNonObligatoireIA(mainJoueur *m, carte *c, couleur *colorChosen);

couleur priseObligatoire(mainJoueur *m, carte *carteVis, bool humanPlayer);
couleur priseObligatoireHumanPlayer(mainJoueur *m, carte *carteVis);
couleur priseObligatoireIA(mainJoueur *m, carte* carteVis);

#endif
