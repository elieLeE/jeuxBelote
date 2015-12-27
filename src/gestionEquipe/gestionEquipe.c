#include "gestionEquipe.h"

void addPli(equipe *eq, pli newPli){
    eq->tabPli[eq->nbrePliDone] = newPli;
    eq->nbrePliDone++;
}

bool verifSumPoints(int *pts){
    int sum = pts[EQUIPE_1] + pts[EQUIPE_2];
    return ((sum == 162) || (sum == 182));
}

void addPoints(equipe *eqs, situationMain *sitM){
    int i, j;
    int pts[NBRE_EQ] = {0, 0};
    int equipePreneuse = (sitM->preneur)%2;
    int equipeNonPreneuse = (equipePreneuse +1)%2;
    couleur coulAtout = sitM->coulAtout;
    if(eqs[EQUIPE_1].nbrePliDone == 8){
	eqs[EQUIPE_1].ptsActuel += 250;
    }
    else if(eqs[EQUIPE_2].nbrePliDone == 8){
	eqs[EQUIPE_2].ptsActuel += 250;
    }
    else{
	if(sitM->numJoueurBeloteEtRe[0] == sitM->numJoueurBeloteEtRe[1]){
	    pts[sitM->numJoueurBeloteEtRe[0]] += BELOTE_ET_RE;
	}
	for(i=0; i<NBRE_EQ; i++){
	    for(j=0; j<eqs[i].nbrePliDone; j++){
		pts[i] += valPli(&eqs[i].tabPli[j], coulAtout);
	    }
	}
	pts[(sitM->actualPli.meneur)%NBRE_EQ] += DIX_DE_DER;
	if(!verifSumPoints(pts)){
	    fprintf(stderr, "comptage points incorrecte\n");
	}
	else{
	    if(pts[equipePreneuse] == LITIGE_CONTRAT){
		sitM->ptsLitige += LITIGE_CONTRAT;
		eqs[equipeNonPreneuse].ptsActuel += LITIGE_CONTRAT;
	    }
	    else {
		if(pts[equipePreneuse] > pts[equipeNonPreneuse]){
		    eqs[equipePreneuse].ptsActuel += pts[equipePreneuse];
		    eqs[equipePreneuse].ptsActuel += sitM->ptsLitige;
		    eqs[equipeNonPreneuse].ptsActuel += pts[equipeNonPreneuse];
		}
		else{
		    eqs[equipeNonPreneuse].ptsActuel += CONTRAT_NON_REMPLIE;
		    eqs[equipeNonPreneuse].ptsActuel += sitM->ptsLitige;
		}
		sitM->ptsLitige = 0;
	    }
	}
    }
    eqs[EQUIPE_1].ptsTotal += eqs[EQUIPE_1].ptsActuel;
    eqs[EQUIPE_2].ptsTotal += eqs[EQUIPE_2].ptsActuel;
}

void initEquipe(equipe *eq){
    eq->ptsTotal = 0;
}

void reInitEquipe(equipe *eq){
    eq->nbrePliDone = 0;
    eq->ptsActuel = 0;
}
