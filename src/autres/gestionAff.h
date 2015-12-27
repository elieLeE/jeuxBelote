#ifndef _GESTION_AFF_H_
#define _GESTION_AFF_H_

#include <stdio.h>
#include "../gestionJoueurs/defineJoueurs.h"
#include "../gestionGame/defineGame.h"
#include "../gestionEquipe/defineEquipe.h"
#include "../gestionJeuCarte/gestionCarte.h"
#include "../gestionJoueurs/choixAtout.h"
#include "gestionMemoire.h"

void affCarte(carte c);

void affJeu(carte* jeu);

void affCoul(carte *tab, int taille, const char *s, int pts);
void affMainJoueur(mainJoueur *m, char *s);
void affMainJoueurs(mainJoueur *joueurs);
void affPointsColorMain(mainJoueur *m, char *s);

void affSitMain(situationMain *sitM);

void affPli(pli *p);

void affTeam(equipe *team, char *s);
void affTeams(equipe *teams);

#endif
