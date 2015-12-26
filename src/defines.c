#include "defines.h"

const char* nameRang(rang r){
    static const char* name[NBRE_CARTE_COUL] = {"SEPT", "HUIT", "NEUF", "VALET", "DAME", "ROI", "DIX", "AS"};
    if(r>=SEPT && r<=AS){
	return name[r];
    }
    printf("nameRang 2\n");
    fprintf(stderr, "rang inconnu : %d, fichier %s, ligne %d\n", r, __FILE__, __LINE__);
    return "";
}

const char* nameCoul(couleur c){
    static const char* name[NBRE_COUL] = {"CARREAU", "COEUR", "PIQUE", "TREFLE"};
    if(c>=CARREAU && c<=TREFLE){
	return name[c];
    }
    fprintf(stderr, "couleur inconnue : %d, fichier %s, ligne %d\n", c, __FILE__, __LINE__);
    return "";
}
