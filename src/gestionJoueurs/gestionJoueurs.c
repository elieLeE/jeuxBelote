#include "gestionJoueurs.h"

const char* nameJoueur(int n){
    static const char* name[NBRE_JOUEURS] = {"MOI", "EST", "NORD", "OUEST"};
    assert((n>=0) && (n<NBRE_JOUEURS));
    return name[n];
}

