#ifndef _GESTION_JEU_CARTE_H_
#define _GESTION_JEU_CARTE_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
//#include "../defines.h"
#include "../gestionEquipe/defineEquipe.h"
#include "../gestionJoueurs/defineJoueurs.h"
#include "../gestionGame/defineGame.h"
#include "../gestionJoueurs/triageMain.h"
#include "../autres/gestionAff.h"
#include "../autres/tabCarte.h"
#include "../gestionJoueurs/gestionMain.h"

void melangeJeu(carte *jeu);
void coupeJeu(carte *jeu);
void initJeu(rang jeu[NBRE_COUL][NBRE_CARTE_COUL]);
void copiePlisEqsToJeu(carte *jeu, equipe *eq);
void reconstitutionJeu(carte* jeu, equipe teams[NBRE_EQ]);
void distribution(carte* jeu, mainJoueur *joueurs, situationMain *sitM);
void firstDistribution(carte* jeu, mainJoueur *joueurs, int firstJoueur);
void secondeDistribution(carte* jeu, mainJoueur *joueurs, int firstJoueur, int preneur);
bool verifJeuCarte(carte *jeu);
bool searchCarteJeu(carte *jeu, carte *c);

#endif
