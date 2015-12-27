#include "gestionPli.h"

pli nextPli(mainJoueur *joueurs, situationMain *sitM){
    int numJ = sitM->actualPli.meneur, i;
    carte newCarte, *tab = sitM->actualPli.tabCarte;
    for(i=0; i<NBRE_JOUEURS; i++){
	newCarte = choixCarte(&joueurs[numJ], sitM, (numJ == 0));
	tab[numJ] = newCarte;
	if(comparaisonCarte(&(tab[sitM->actualPli.meneur]), &newCarte, sitM->coulAtout) == CARTE_2){
	    sitM->actualPli.meneur = numJ;
	}
	setBeloteEtRe(sitM, &newCarte, numJ);
	numJ = (numJ+1)%4;
    }
    miseAJourSitM(sitM);
    return sitM->previousPli;
}

int valPli(pli* p, couleur coulAtout){
    int i, n = (NBRE_CARTES/NBRE_PLIS);
    int sum = 0;
    for(i=0; i<n; i++){
	sum += valCarte(p->tabCarte[i].r, (p->tabCarte[i].c == coulAtout));
    }
    return sum;
}
