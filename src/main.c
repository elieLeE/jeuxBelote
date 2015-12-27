#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "gestionGame/gestionPartie.h"

int main(){
    carte jeu[NBRE_CARTES];
    srand(time(NULL));

    melangeJeu(jeu);
    game(jeu);


    return 0;
}
