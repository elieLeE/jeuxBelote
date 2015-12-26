#include "gestionCarte.h"

int valCarte(rang r, bool atout){
    static int valNonAtout[NBRE_CARTE_COUL] = {0, 0, 0, 2, 3, 4, 10, 11};
    static int valAtout[NBRE_CARTE_COUL] = {0, 0, 14, 20, 3, 4, 10, 11};
    if(r>=SEPT && r<=AS){
	if(atout){
	    return valAtout[r];
	}
	else{
	    return valNonAtout[r];
	}
    }
    fprintf(stderr, "rang inconnu, fichier %s, ligne %d\n", __FILE__, __LINE__);
    return 0;
}

/*
 * return CARTE_1 si c1 > c2
 * return CARTE_2 si c1 < c2
 * return SAME_CARTE si c1 = c2
 * la carte c1 est considere comme maitre (pose avant)
 * */
compCarte comparaisonCarte(carte *c1, carte *c2, couleur coulAtout){
    bool atout;
    if(sameCarte(c1, c2)){
	return SAME_CARTE;
    }
    else if(c1->c == c2->c){
	atout = (c1->c == coulAtout);
	if(valCarte(c1->r, atout) > valCarte(c2->r, atout)){
	    return CARTE_1;
	}
	else{
	    return CARTE_2;
	}
    }
    else{
	if(c2->c == coulAtout){
	    return CARTE_2;
	}
	else{
	    return CARTE_1;
	}
    }
}

bool sameCarte(carte *c1, carte *c2){
    return ((c1->r == c2->r) && (c1->c == c2->c));
}

void echangeCarte(carte *c1, carte *c2){
    carte c = *c1;
    *c1 = *c2;
    *c2 = c;
}

bool beloteOrRe(carte *c, couleur coulAtout){
    return ((c->c == coulAtout) && ((c->r == DAME) || (c->r == ROI)));
}

const char * nameCarte(carte *c){
    char *s = my_malloc(20*sizeof(char));
    sprintf(s, "%s de %s", nameRang(c->r), nameCoul(c->c));
    return s;
}
