#include "choixAtout.h"

/*
 * ajouter sans atout et tout atout
 * gestion plus exterioriser => priseOrNot(mainJoueur *joueur, carte *carteVisible, couleur *colorChosen, enchereChoixAtout enc, bool tour1, bool humanPlayer, bool priseObligatoire)
 * */
void choixModeMain(mainJoueur *joueurs, situationMain *sitM, carte carteVisible){
    fprintf(stderr, "ajouter gestion joueur => choix atout\n");
    int actualJoueur = sitM->firstJoueur;
    int oldFirstJoueur = actualJoueur;
    bool oneColor = true;
    couleur colorChosen = carteVisible.c;
    int preneur;
    while(true){
	if(oneColor){
	    if(prendColor(&joueurs[actualJoueur], &carteVisible, (actualJoueur == 0))){
		preneur = actualJoueur;
		break;
	    }
	}
	else{
	    if(priseNonObligatoire(&joueurs[actualJoueur], &carteVisible, &colorChosen, (actualJoueur == 0))){
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
		colorChosen = priseObligatoire(&joueurs[actualJoueur], &carteVisible, (actualJoueur == 0));
		preneur = actualJoueur;
		break;
	    }
	}
    }
    sitM->coulAtout = colorChosen;
    sitM->preneur = preneur;
    sitM->cartePrise = carteVisible;
}

bool priseOrNot(mainJoueur *m, carte *carteVis, couleur *colorChosen, enchereChoixAtout *ench, bool tour1, bool humanPlayer, bool priseOb){
    if(tour1){
	*colorChosen = carteVis->c;
	return prendColor(m, carteVis, humanPlayer);
    }
    else{
	if(priseOb){
	    *colorChosen = priseObligatoire(m, carteVis, humanPlayer);
	    return true;
	}
	else{
	    return priseNonObligatoire(m, carteVis, colorChosen, humanPlayer);
	}
    }
}

bool prendColor(mainJoueur *m, carte *c, bool humanPlayer){
    if(humanPlayer){
	return prendColorHumanPlayer(m, c);
    }
    else{
	return prendColorIA(m, c);
    }
}

bool prendColorHumanPlayer(mainJoueur *m, carte *c){
    if(!AVEC_HUMAN_PLAYER){
	return prendColorIA(m, c);
    }
    int choix = -1;
    printf("a votre tour de parler : carte visible => %s\n", nameCarte(c));
    printf("vos cartes : \n");
    affMainJoueur(m, "");
    printf("entrez votre choix : (1 => prise, 0 => refus)\n");
    while(true){
	scanf("%d", &choix);
	if((choix == 0) || (choix == 1)){
	    break;
	}
	else{
	    printf("choix non compris\n");
	}
    }
    return (choix == 1);
}

bool prendColorIA(mainJoueur *m, carte *c){
    return ((valMain(m, c->c) + valCarte(c->r, true)) >= LIM_PRISE);
}

bool priseNonObligatoire(mainJoueur *m, carte *c, couleur *coulChosen, bool humanPlayer){
    if(humanPlayer){
	return priseNonObligatoireHumanPlayer(m, c, coulChosen);
    }
    else{
	return priseNonObligatoireIA(m, c, coulChosen);
    }
}

bool priseNonObligatoireHumanPlayer(mainJoueur *m, carte *c, couleur *coulChosen){
    fprintf(stderr, "priseNonObligatoireHumanPlayer NOT YET IMPLEMENTED\n");
    return priseNonObligatoireIA(m, c, coulChosen);
}

bool priseNonObligatoireIA(mainJoueur *m, carte *carteVis, couleur *coulChosen){
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
    return ((max + valCarte(carteVis->r, false)) >= LIM_PRISE);
}

couleur priseObligatoire(mainJoueur *m, carte* carteVis, bool humanPlayer){
    if(humanPlayer){
	return priseObligatoireHumanPlayer(m, carteVis);
    }
    else{
	return priseObligatoireIA(m, carteVis);
    }
}

couleur priseObligatoireHumanPlayer(mainJoueur *m, carte *carteVis){
    fprintf(stderr, "priseObligatoireHumanPlayer NOT YET IMPLEMENTED\n");
    return priseObligatoireIA(m, carteVis);
}

couleur priseObligatoireIA(mainJoueur *m, carte *carteVis){
    couleur c;
    priseNonObligatoireIA(m, carteVis, &c);
    return c;
}


