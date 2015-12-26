#ifndef _GESTION_MAIN_H_
#define _GESTION_MAIN_H_

#include <stdbool.h>
#include "defines.h"
#include "gestionCarte.h"
#include "gestionAff.h"
#include "tabCarte.h"

void addCarte(mainJoueur *m, carte *c);
int valMain(mainJoueur *m, couleur coulAtout);
bool prendColor(mainJoueur *m, couleur coulAtout);
bool priseNonObligatoire(mainJoueur *m, couleur *c);
couleur priseObligatoire(mainJoueur *m);
carte choixCarte(mainJoueur *m, situationMain *sitM, int numJ);
void insertionCarteTrie(carte *tabCarte, carte* newCarte, int nbreCarte, couleur coulAtout);
void trierTabCarte(carte* tabCarte, int taille, couleur coulAtout);
void trierMainJoueur(mainJoueur *m, couleur coulAtout);
void trierMainJoueurs(mainJoueur *joueurs, couleur coulAtout);
void choixModeMain(mainJoueur *joueurs, situationMain *sitM, carte carteVisible);

#endif
