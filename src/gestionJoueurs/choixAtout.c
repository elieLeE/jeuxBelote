#include "choixAtout.h"

/*
 * ajouter sans atout et tout atout
 * gestion plus exterioriser => priseOrNot(mainJoueur *joueur, carte *carteVisible, couleur *colorChosen, enchereChoixAtout enc, bool tour1, bool humanPlayer, bool priseObligatoire)
 * */
void choixModeMain(mainJoueur *joueurs, situationMain *sitM, carte carteVisible){
    fprintf(stderr, "ajouter gestion joueur => choix atout\n");
    int actualJoueur = sitM->firstJoueur;
    int compt = 0;
    bool tourComplet = false;
    enchereChoixAtout maxEnch = COULEUR_SIMPLE;
    structChoixAtout s;
    initStructChoixAtout(&s, &carteVisible);
    //A SUPPRIMER
    s.ench = AUCUNE_ENCHERE;
    while(true){
	//si il y a eu 1 prise => on etudie
	s.humanPlayer = (actualJoueur == 0);
	if(s.tourOne){
	    if(compt == NBRE_JOUEURS){
		s.tourOne = false;
		compt = 0;
		printf("tour2\n");
	    }
	}
	else {
	    if(s.ench == AUCUNE_ENCHERE){
		if(compt == NBRE_JOUEURS-1){
		    printf("prise obligatoire\n");
		    s.priseOb = true;
		}
	    }
	    else if(compt == NBRE_JOUEURS){
		tourComplet  =true;
	    }
	}
	printf("J%d", actualJoueur);
	if(priseOrNot(&joueurs[actualJoueur], &s)){
	    printf(" => prise\n");
	    s.preneur = actualJoueur;
	    if((s.ench == maxEnch) || s.priseOb || tourComplet){
		break;
	    }
	    compt = 0;
	    tourComplet = false;
	}
	else{
	    printf(" => refus\n");
	}
	getchar();
	actualJoueur = (actualJoueur + 1)%4;
	compt++;
    }
    //A SUPPRIMER
    s.ench = COULEUR_SIMPLE;
    setParamChoixAtout(sitM, &s);
    affSitMain(sitM);
}

bool priseOrNot(mainJoueur *m, structChoixAtout *s){
    bool result;
    if(s->tourOne){
	s->coulChosen = s->carteVisible.c;
	 if((result=prendColor(m, &(s->carteVisible), s->humanPlayer))){
	     s->ench = COULEUR_SIMPLE;
	 }
	 return result;
    }
    else{
	if(s->priseOb){
	    s->coulChosen = priseObligatoire(m, &(s->carteVisible), s->humanPlayer);
	    return true;
	}
	else{
	    return priseNonObligatoire(m, &(s->carteVisible), &(s->coulChosen), s->humanPlayer);
	}
    }
}

void initStructChoixAtout(structChoixAtout *s, carte *c){
    s->carteVisible = *c;
    s->ench = AUCUNE_ENCHERE;
    s->tourOne = true;
    s->priseOb = false;
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
    return ((valMain(m, COULEUR_SIMPLE, c->c) + valCarte(c->r, true)) >= LIM_PRISE);
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
    int max = valMain(m, COULEUR_SIMPLE, CARREAU);
    int val;
    for(c=COEUR; c<NBRE_COUL; c++){
	val = valMain(m, COULEUR_SIMPLE, c);
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

const char* nameModeAtout(enchereChoixAtout m){
    static const char* name[4] = {"AUCUNE ENCHERE", "COULEUR SIMPLE", "SANS ATOUT", "TOUT ATOUT"};
    return name[m];
}
