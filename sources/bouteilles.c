#include "../headers/graphe_matrice.h"
#include "../headers/bouteilles.h"
#include <stdbool.h>

int main(int argc, char ** argv) {
    // Bouteilles
    bouteille b1;
    bouteille b2;
    bouteille b3;

    b1.contenance_max = 14;
    b2.contenance_max = 6;
    b3.contenance_max = 8;

    b1.contenance = 14;
    b2.contenance = 0;
    b3.contenance = 0;

    b1.index = 1;
    b2.index = 2;
    b3.index = 3;

    int objectif = (int) (b1.contenance / 2);
    
    // Matrice
    MATRICE M;
    M.n = 3;

    reservation_en_memoire(M.n, &M);
    ajouter_arc(&M, 1, 2);
    ajouter_arc(&M, 1, 3);
    ajouter_arc(&M, 2, 1);
    ajouter_arc(&M, 2, 3);
    ajouter_arc(&M, 3, 1);
    ajouter_arc(&M, 3, 2);




    
    return 0;
}

// puts b1 in b2
bool transvider(bouteille *b1, bouteille *b2) {
    if ((b2->contenance_max - b2->contenance) >= b1->contenance) {
        b2->contenance += b1->contenance;
        b1->contenance = 0;
        return true;
    }
    else return false;
}