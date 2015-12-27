#ifndef _DEFINE_CARTE_H_
#define _DEFINE_CARTE_H_

#include <stdbool.h>
#include "../defines.h"

typedef struct carte carte;
typedef enum rang rang;
typedef enum couleur couleur;
typedef enum compCarte compCarte;

enum rang{
    SEPT,
    HUIT,
    NEUF,
    VALET,
    DAME,
    ROI,
    DIX,
    AS
};

enum couleur{
    CARREAU,
    COEUR,
    PIQUE,
    TREFLE
};

enum compCarte{
    CARTE_1,
    CARTE_2,
    SAME_CARTE
};

struct carte{
    rang r;
    couleur c;
    bool dejaJoue;
};

#endif

