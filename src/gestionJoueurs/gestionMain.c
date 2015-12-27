#include "gestionMain.h"

/*
 * Constitution de la main
 * */
void addCarte(mainJoueur *m, carte *c){
    couleur coul = c->c;
    rang r = c->r;
    int p = m->nbreCarteInit[coul];
    m->tabCarte[coul][p].r = r;
    m->tabCarte[coul][p].c = coul;
    m->tabCarte[coul][p].dejaJoue = false;
    m->nbreCarteInit[coul]++;
}

int valMain(mainJoueur *m, couleur coulAtout){
    int val = 0, j;
    couleur i;
    bool atout;
    for(i=0; i<NBRE_COUL; i++){
	atout = (coulAtout == i);
	for(j=0; j<m->nbreCarteInit[i]; j++){
	    val += valCarte(m->tabCarte[i][j].r, atout);
	}
    }
    return val;
}

