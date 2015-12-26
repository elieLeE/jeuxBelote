#include "gestionMain.h"

void addCarte(mainJoueur *m, carte *c){
    couleur coul = c->c;
    rang r = c->r;
    int p = m->nbreCarteInit[coul];
    m->tabCarte[coul][p].r = r;
    m->tabCarte[coul][p].c = coul;
    m->tabCarte[coul][p].dejaJoue = false;
    m->nbreCarteInit[coul]++;
}

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

bool prendColor(mainJoueur *m, couleur coulAtout){
    return (valMain(m, coulAtout) >= 50);
}

bool priseNonObligatoire(mainJoueur *m, couleur *coulChosen){
    couleur c, cMax = CARREAU;
    int max = valMain(m, CARREAU);
    int val;
    for(c=COEUR; c<NBRE_COUL; c++){
	val = valMain(m, c);
	if(val>max){
	    max = val;
	    cMax = c;
	}
	else if(val == max){
	    if(m->nbreCarteInit[c] > m->nbreCarteInit[cMax]){
		max = val;
		cMax = c;
	    }
	}
    }
    *coulChosen = cMax;
    return (max >= 50);
}

couleur priseObligatoire(mainJoueur *m){
    couleur c;
    priseNonObligatoire(m, &c);
    return c;
}

carte choixCarte(mainJoueur *m, situationMain *sitM, int numJ){
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
    fprintf(stderr, "plus de cartes disponibles, joueur %d, fonction %s\n", numJ, __FILE__);
    carte newCarte; 
    return newCarte;
}

void choixModeMain(mainJoueur *joueurs, situationMain *sitM, carte carteVisible){
    fprintf(stderr, "ajouter gestion joueur => choix atout\n");
    int actualJoueur = sitM->firstJoueur;
    int oldFirstJoueur = actualJoueur;
    bool oneColor = true;
    couleur colorChosen = carteVisible.c;
    int preneur;
    while(true){
	if(oneColor){
	    if(prendColor(&joueurs[actualJoueur], colorChosen)){
		preneur = actualJoueur;
		break;
	    }
	}
	else{
	    if(priseNonObligatoire(&joueurs[actualJoueur], &colorChosen)){
		preneur = actualJoueur;
		break;
	    }
	}
	actualJoueur = (actualJoueur + 1)%4;
	if(actualJoueur == oldFirstJoueur){
	    if(oneColor){
		oneColor = false;
	    }
	    else{
		actualJoueur--;
		if(actualJoueur < 0){
		    actualJoueur = 3;
		}
		colorChosen = priseObligatoire(&joueurs[actualJoueur]);
		preneur = actualJoueur;
		break;
	    }
	}
    }
    sitM->coulAtout = colorChosen;
    sitM->preneur = preneur;
    sitM->cartePrise = carteVisible;
}
