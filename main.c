#include <stdio.h>
#include <stdlib.h>

#include "sources/graphe_matrice.c"
#include "sources/graphe_liste.c"

#define SIZE 4

int main(int argc, char** argv) {
    MATRICE m;
    int *dplus, *dmoins;

    reservation_en_memoire(SIZE, &m);
    ajouter_arc(&m, 1, 2);
    ajouter_arc(&m, 2, 3);
    print_matrice(SIZE, &m);
    calcul_degres(&m, SIZE, dplus, dmoins);

    return EXIT_SUCCESS;
    
}