#include <stdio.h>
#include <stdlib.h>

#include "sources/graphe_matrice.c"
#include "sources/graphe_liste.c"

#define SIZE 4

int main(int argc, char** argv) {
    MATRICE m;
    int *dplus;
    int *dmoins;

    // Nouveau graphe
    reservation_en_memoire(SIZE, &m);
    // Ajouts d'arcs
    ajouter_arc(&m, 1, 2);
    ajouter_arc(&m, 2, 3);
    // Affichage de la matrice
    print_matrice(&m);
    // Lancement de la fonction permettant de calculer tous les degres
    calcul_tous_degres(&m, &dplus, &dmoins);
    // Affichage des degres
    for (int i = 0; i < SIZE; i++) {
        printf("%d, %d\n", dplus[i], dmoins[i]);
    }
    

    return EXIT_SUCCESS;
    
}