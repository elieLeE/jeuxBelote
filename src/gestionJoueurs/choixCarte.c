#include "choixCarte.h"

carte choixCarte(mainJoueur *m, situationMain *sitM, bool humanPlayer){
    if(humanPlayer){
	return choixCarteHumanPlayer(m, sitM);
    }
    else{
	return choixCarteIA(m, sitM);
    }
}

carte choixCarteHumanPlayer(mainJoueur *m, situationMain *sitM){
    return choixCarteIA(m, sitM);
}

carte choixCarteIA(mainJoueur *m, situationMain *sitM){
    /*if(i==0){
	sitM->actualPli.coulAsked = sitM->actualPli.tab[0].c;
    }*/
    fprintf(stderr, "fonction choixCarte NOT YET IMPLEMENTED, ajouter gestion joueur => choix atout\n");
    couleur c;
    int i;
    for(c=CARREAU; c<=TREFLE; c++){
	if(m->nbreCarteRestantes[c]>0){
	    for(i=0; i<m->nbreCarteInit[c]; i++){
		if(!(m->tabCarte[c][i].dejaJoue)){
		    m->tabCarte[c][i].dejaJoue = true;
		    m->nbreCarteRestantes[c]--;
		    return m->tabCarte[c][i];
		}
	    }
	}
    }
    carte newCarte; 
    return newCarte;
}

