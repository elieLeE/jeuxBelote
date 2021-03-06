#ifndef _GESTION_CARTE_H_
#define _GESTION_CARTE_H_

#include <stdio.h>
#include <stdbool.h>
#include "gestionMemoire.h"
#include "defines.h"

bool sameCarte(carte *c1, carte *c2);
int valCarte(rang r, bool atout);
void echangeCarte(carte *c1, carte *c2);
compCarte comparaisonCarte(carte *c1, carte *c2, couleur coulAtout);
bool beloteOrRe(carte *c, couleur coulAtout);
const char * nameCarte(carte *c);

#endif
