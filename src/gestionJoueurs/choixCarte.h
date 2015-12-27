#ifndef _CHOIX_CARTE_H_
#define _CHOIX_CARTE_H_

#include <stdbool.h>
//#include "../defines.h"
#include "defineJoueurs.h"
#include "../gestionGame/defineGame.h"

carte choixCarte(mainJoueur *m, situationMain *sitM, bool humanPlayer);
carte choixCarteHumanPlayer(mainJoueur *m, situationMain *sitM);
carte choixCarteIA(mainJoueur *m, situationMain *sitM);

#endif
