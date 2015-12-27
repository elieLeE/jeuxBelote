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
    m->nbreCarteRestantes[coul]++;
}

int valMain(mainJoueur *m, enchereChoixAtout modeMain, couleur coulAtout){
    int val = 0, j;
    couleur i;
    bool atout;
    for(i=0; i<NBRE_COUL; i++){
	//atout = (((modeMain == COULEUR_SIMPLE) || (modeMain == AUCUNE_ENCHERE))?(coulAtout == i):((modeMain == SANS_ATOUT)?false:true));
	switch(modeMain){
	    case AUCUNE_ENCHERE:
	    case COULEUR_SIMPLE:
		atout = (i==coulAtout);
		break;
	    case SANS_ATOUT:
		atout = false;
		break;
	    case TOUT_ATOUT:
		atout = true;
		break;
	}
	for(j=0; j<m->nbreCarteInit[i]; j++){
	    val += valCarte(m->tabCarte[i][j].r, atout);
	}
    }
    return val;
}

