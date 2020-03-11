#include <stdio.h>
#include <stdlib.h>

#include "sources/graphe_matrice.c"
#include "sources/graphe_liste.c"

#define SIZE 4

int main(int argc, char** argv) {
    MATRICE m;
    MATRICE m2;
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
    // for (int i = 0; i < SIZE; i++) {
    //     printf("%d, %d\n", dplus[i], dmoins[i]);
    // }
    // Copie dans m2
    // copie_graphe(&m, &m2);
    // print_matrice(&m2);
    // ecrire_graphe(&m, "test.txt");
    lire_graphe("test.txt", &m);
    print_matrice(&m);

    return EXIT_SUCCESS;
    
}