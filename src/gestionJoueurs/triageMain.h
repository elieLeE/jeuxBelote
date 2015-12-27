#ifndef _TRIAGE_MAIN_H_
#define _TRIAGE_MAIN_H_

#include <stdbool.h>
//#include "../defines.h"
#include "defineJoueurs.h"
#include "../gestionJeuCarte/gestionCarte.h"
#include "../autres/gestionAff.h"
#include "../autres/tabCarte.h"

void insertionCarteTrie(carte *tabCarte, carte* newCarte, int nbreCarte, couleur coulAtout);
void trierTabCarte(carte* tabCarte, int taille, couleur coulAtout);
void trierMainJoueur(mainJoueur *m, couleur coulAtout);
void trierMainJoueurs(mainJoueur *joueurs, couleur coulAtout);

#endif
