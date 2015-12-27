#include "gestionSituationMain.h"

void miseAJourSitM(situationMain *sitM){
    sitM->eqDixDeDer = (sitM->actualPli.meneur)%NBRE_EQ;
    sitM->firstJoueur = sitM->actualPli.meneur;
    sitM->previousPli = sitM->actualPli;
    sitM->nbrePliDone++;
    sitM->actualPli.nbreCarte = 0;
}

void reInitSitMain(situationMain *sitM){
    sitM->nbreAtoutsTombes = 0;
    sitM->firstJoueur = (sitM->firstJoueur+1)%4;
    sitM->nbrePliDone = 0;
    sitM->numJoueurBeloteEtRe[0] = -1;
    sitM->numJoueurBeloteEtRe[1] = -1;
    sitM->actualPli.meneur = sitM->firstJoueur;
}

void setBeloteEtRe(situationMain *sitM, carte *c, int numJ){
    if(beloteOrRe(c, sitM->coulAtout)){
	if(sitM->numJoueurBeloteEtRe[0] == -1){
	    sitM->numJoueurBeloteEtRe[0] = numJ;
	}
	else{
	    sitM->numJoueurBeloteEtRe[1] = numJ;
	}
    }
}

