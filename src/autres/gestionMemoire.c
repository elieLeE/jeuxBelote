#include "gestionMemoire.h"

void* my_malloc(int taille){
    void* p = malloc(taille);
    if(p==NULL){
	fprintf(stderr, "allocation impossible => taille : %d\n", taille);
	exit(0);
    }

    return p;
}

