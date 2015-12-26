#include "gestionPartie.h"

void game(carte *jeu){
    mainJoueur joueurs[NBRE_JOUEURS];
    situationMain sitM;
    equipe teams[NBRE_EQ];
    int i, numMain = 1, fJ;
    pli newPli;

    initGame(teams, &sitM);
    while(gameOver(teams[EQUIPE_1].ptsTotal, teams[EQUIPE_2].ptsTotal)){
	initMain(teams, &sitM);
	distribution(jeu, joueurs, &sitM);
	fJ = sitM.firstJoueur;
	printf("main %d, atout : %s\n", numMain, nameCoul(sitM.coulAtout));
	affMainJoueurs(joueurs);
	for(i=0; i<NBRE_PLIS; i++){
	    newPli = nextPli(joueurs, &sitM);
	    addPli(&teams[(newPli.meneur)%NBRE_EQ], newPli);
	    printf("pli %d, firstJoueur : %d => ", i, fJ);
	    fJ = newPli.meneur;
	    affPli(&newPli);
	    printf("\n");
	}
	printf("\n\n");
	addPoints(teams, &sitM);
	affTeams(teams);
	reconstitutionJeu(jeu, teams);
	numMain++;
	getchar();
	//teams[0].ptsTotal = 501;
    }
    endGame(teams);
}

void initGame(equipe *teams, situationMain *sitM){
    sitM->ptsLitige = 0;
    sitM->firstJoueur = rand()%(NBRE_JOUEURS -0);
    initEquipe(&teams[EQUIPE_1]);
    initEquipe(&teams[EQUIPE_2]);
}

void initMain(equipe *teams, situationMain *sitM){
    reInitSitMain(sitM);
    reInitEquipe(&teams[EQUIPE_1]);        	
    reInitEquipe(&teams[EQUIPE_2]);        	
}

void endGame(equipe *teams){
    printf("partie termine !\n");
    printf("equipe gagnante : %s\n", (teams[0].ptsTotal > teams[1].ptsTotal)? "NOUS":"EUX");
    printf("score final : %d - %d\n", teams[0].ptsTotal, teams[1].ptsTotal);
}

bool gameOver(int ptsEq1, int ptsEq2){
    return !((ptsEq1 >= LIM_GAIN) || (ptsEq2 >= LIM_GAIN));
}

