#include "triageMain.h"

void insertionCarteTrie(carte *tabCarte, carte *newCarte, int nbreCarte, couleur coulAtout){
    int pos = nbreCarte;
    tabCarte[nbreCarte] = *newCarte;
    while(pos>0 &&(comparaisonCarte(&tabCarte[pos], &tabCarte[pos-1], coulAtout) == CARTE_1)){
	echangeCarte(&tabCarte[pos-1], &tabCarte[pos]);
	pos--;
    }
}

void trierTabCarte(carte* tabCarte, int taille, couleur coulAtout){
    int i;
    carte copieTabCarte[NBRE_CARTE_MAIN];
    copieTab(copieTabCarte, tabCarte, taille);
    for(i=0; i<taille; i++){
	insertionCarteTrie(tabCarte, &copieTabCarte[i], i, coulAtout);
    }
}

void trierMainJoueur(mainJoueur *m, couleur coulAtout){
    couleur c;
    for(c=CARREAU; c<=TREFLE; c++){
	trierTabCarte(m->tabCarte[c], m->nbreCarteInit[c], coulAtout);
    }
}

void trierMainJoueurs(mainJoueur *joueurs, couleur coulAtout){
    int i;
    for(i=0; i<NBRE_JOUEURS; i++){
	trierMainJoueur(&joueurs[i], coulAtout);
    }
}

