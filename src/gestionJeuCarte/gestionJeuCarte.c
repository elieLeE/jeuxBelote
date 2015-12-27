#include "gestionJeuCarte.h"

void initJeu(rang jeu[NBRE_COUL][NBRE_CARTE_COUL]){
    couleur i;
    rang j;
    for(i=0; i<NBRE_COUL; i++){
	for(j=0; j<NBRE_CARTE_COUL; j++){
	    jeu[i][j] = j;
	}
    }
}

void melangeJeu(carte *jeu){
    bool done[NBRE_CARTES] = {false};
    int p, i, j;
    for(i=0; i<NBRE_COUL; i++){
	for(j=SEPT; j<=AS; j++){
	    do{
		p = rand()%(NBRE_CARTES-0);
	    }while(done[p]);
	    jeu[p].c = i;
	    jeu[p].r = j;
	    done[p] = true;
	}
    }
}

void coupeJeu(carte *jeu){
    int p;
    carte copie[NBRE_CARTES];
    p = rand()%(NBRE_CARTES-0);
    copieTab(copie, jeu, NBRE_CARTES);
    copieTab(jeu, copie+p, NBRE_CARTES-p);
    copieTab(jeu+(NBRE_CARTES-p), copie, p);
}

void distribution(carte* jeu, mainJoueur *joueurs, situationMain *sitM){
    coupeJeu(jeu);
    firstDistribution(jeu, joueurs, sitM->firstJoueur);
    choixModeMain(joueurs, sitM, jeu[20]);
    secondeDistribution(jeu, joueurs, sitM->firstJoueur, sitM->preneur);
    trierMainJoueurs(joueurs, sitM->coulAtout);
}
void firstDistribution(carte* jeu, mainJoueur *joueurs, int firstJoueur){
    int h, i, j, k, p, lim;
    
    for(i=0; i<NBRE_JOUEURS; i++){
	joueurs[i].nbreCarteInit[0] = 0;
	joueurs[i].nbreCarteInit[1] = 0;
	joueurs[i].nbreCarteInit[2] = 0;
	joueurs[i].nbreCarteInit[3] = 0;
    }

    lim = 3;
    p = firstJoueur;
    for(h=0, j=0; h<2; h++){
	for(i=0; i<NBRE_JOUEURS; i++, j+=lim){
	    for(k=0; k<lim; k++){
		addCarte(&joueurs[p], &jeu[j+k]);
	    }
	    if(p==3){
		p = 0;
	    }
	    else{
		p++;
	    }
	}
	lim = 2;
	p = firstJoueur;
    }
}

void secondeDistribution(carte* jeu, mainJoueur *joueurs, int firstJoueur, int preneur){
    int i, j, k, p, lim;
    couleur c;
    lim = 3;
    p = firstJoueur;
    addCarte(&joueurs[preneur], &jeu[20]);
    for(i=0, j=21; i<NBRE_JOUEURS; i++, j+=lim){
	if(p == preneur){
	    lim = 2;
	}
	else{
	    lim = 3;
	}
	for(k=0; k<lim; k++){
	    addCarte(&joueurs[p], &jeu[j+k]);
	}
	if(p==3){
	    p = 0;
	}
	else{
	    p++;
	}
    }
    for(i=0; i<NBRE_JOUEURS; i++){
	for(c=CARREAU; c<=TREFLE; c++){
	    joueurs[i].nbreCarteRestantes[c] = joueurs[i].nbreCarteInit[c];
	}
    }
}

void reconstitutionJeu(carte* jeu, equipe teams[NBRE_EQ]){
    copiePlisEqsToJeu(jeu, &teams[0]);
    copiePlisEqsToJeu(jeu + (4*teams[0].nbrePliDone), &teams[1]);
    if(!verifJeuCarte(jeu)){
	fprintf(stderr, "reconstitution jeu incorrecte, fichier %s, ligne %d\n", __FILE__, __LINE__);
    }
}

void copiePlisEqsToJeu(carte *jeu, equipe *eq){
    int i, j;
    for(i=0; i<eq->nbrePliDone; i++){
	for(j=0; j<NBRE_JOUEURS; j++){
	    jeu[4*i+j] = eq->tabPli[i].tabCarte[j];
	}
    }
}

bool verifJeuCarte(carte *jeu){
    rang r;
    couleur c;
    carte testCarte;
    for(c=CARREAU; c<=TREFLE; c++){
	testCarte.c = c;
	for(r=SEPT; r<=AS; r++){
	    testCarte.r = r;
	    if(!searchCarteJeu(jeu, &testCarte)){
		return false;
	    }
	}
    }
    return true;
}

bool searchCarteJeu(carte *jeu, carte *c){
    int i;
    for(i=0; i<NBRE_CARTES; i++){
	if(sameCarte(&jeu[i], c)){
	    return true;
	}
    }
    return false;
}
