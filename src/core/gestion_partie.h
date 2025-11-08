#ifndef __GESTION_PARTIE_H__
#define __GESTION_PARTIE_H__

#include "carte.h"

typedef struct card_played_t {
    const carte_t *card;
    int idx_player;
} card_played_t;

typedef struct trick_t {
    card_played_t cards[NBRE_JOUEURS];
    int idx_player_won;
} trick_t;

void start_new_game(carte_t jeu[]);

#endif
