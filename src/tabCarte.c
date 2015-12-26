#include "tabCarte.h"

void copieTab(carte *dest, carte *src, int taille){
    int i = 0;
    for(i=0; i<taille; i++){
	dest[i] = src[i];
    }
}

