#include <stdbool.h>

typedef struct{
    int contenance;
    int contenance_max;
    int index;
} bouteille;

bool transvider(bouteille *b1, bouteille *b2);

void afficher_bouteilles(bouteille b1, bouteille b2, bouteille b3);

void parcours(bouteille *b1, bouteille *b2, bouteille *b3, int objectif, int index, int max);