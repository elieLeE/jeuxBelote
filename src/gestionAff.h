#ifndef _GESTION_AFF_H_
#define _GESTION_AFF_H_

#include <stdio.h>
#include "defines.h"
#include "gestionMain.h"
#include "gestionMemoire.h"
#include "gestionPli.h"

void affCarte(carte c);
void affJeu(carte* jeu);
void affCoul(carte *tab, int taille, const char *s, int pts);
void affMainJoueur(mainJoueur *m, char *s);
void affMainJoueurs(mainJoueur *joueurs);
void affSitMain(situationMain *sitM);
void affPointsColorMain(mainJoueur *m, char *s);
void affPli(pli *p);
void affTeam(equipe *team, char *s);
void affTeams(equipe *teams);
#endif
