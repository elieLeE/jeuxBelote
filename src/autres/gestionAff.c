#include "gestionAff.h"

int maxIndice(int *nbreC){
    int i = 0, max = nbreC[0];
    for(i=1; i<NBRE_COUL; i++){
	if(nbreC[i]>max){
	    max = nbreC[i];
	}
    }
    return max;
}

//CARTE
void affCarte(carte c){
    printf("%s de %s", nameRang(c.r), nameCoul(c.c));
}

//PLI
void affPli(pli *p){
    int i;
    printf("gain J%d : ", p->meneur);
    for(i=0; i<NBRE_JOUEURS; i++){
	affCarte(p->tabCarte[i]);
	printf(", ");
    }
    printf("\n");
}

//EQUIPE
void affTeam(equipe *team, char *s){
    int i;
    printf("%s : %d plis, %d pts, %d pts total\n", s, team->nbrePliDone, team->ptsActuel, team->ptsTotal);
    for(i=0; i<team->nbrePliDone; i++){
	printf("pli %d => ", i);
	affPli(&team->tabPli[i]);
    }
    printf("\n");
}

void affTeams(equipe *teams){
    affTeam(&teams[0], "Team 1");
    affTeam(&teams[1], "Team 2");
}

//MAIN
void affPointsColorMain(mainJoueur *m, char *s){
    couleur c;
    printf("%s => ", s);
    for(c=CARREAU; c<=TREFLE; c++){
	printf("%s : %d, ", nameCoul(c), valMain(m, COULEUR_SIMPLE, c));
    }
    printf("\n");
}

void affCoul(carte *tab, int taille, const char *s, int pts){
    int i = 0;
    printf("%s : ", s);
    for(i=0; i<taille; i++){
	if(!tab[i].dejaJoue){
	    printf("%s, ", nameRang(tab[i].r));
	}
    }
    printf(" => %d pts\n", pts);
}

void affMainJoueur(mainJoueur *m, char *s){
    couleur c;
    int sum = m->nbreCarteRestantes[0] + m->nbreCarteRestantes[1] + m->nbreCarteRestantes[2] + m->nbreCarteRestantes[3];
    printf("%s : %d cartes\n", s, sum);

    for(c=CARREAU; c<=TREFLE; c++){
	affCoul(m->tabCarte[c], m->nbreCarteInit[c], nameCoul(c), valMain(m, COULEUR_SIMPLE, c));
    }
    printf("SANS ATOUT : %d\n", valMain(m, SANS_ATOUT, c));
    printf("TOUT ATOUT : %d\n", valMain(m, TOUT_ATOUT, c));
    printf("\n");
}

void affMainJoueurs(mainJoueur *joueurs){
    int i;
    char *s = my_malloc(2*sizeof(char));
    for(i=0; i<NBRE_JOUEURS; i++){
	sprintf(s, "J%d", i);
	affMainJoueur(&joueurs[i], s);
    }
}
//SITUATION
void affSitMain(situationMain *sitM){
    printf("firstJoueur : J%d, preneur : J%d, cartePrise : %s de %s, mode : %s, coulAtout : %s\n", sitM->firstJoueur, sitM->preneur, nameRang(sitM->cartePrise.r), nameCoul(sitM->cartePrise.c), nameModeAtout(sitM->modeMain), nameCoul(sitM->coulAtout));
}

//JEU
void affJeu(carte* jeu){
    int i =0;
    for(i=0; i<NBRE_CARTES; i++){
	affCarte(jeu[i]);
	printf("\n");
    }
}
