#include <stdio.h>
#include <stdlib.h>

#include "sources/graphe_matrice.c"
#include "sources/graphe_liste.c"

#define SIZE 4

int main(int argc, char** argv) {
    MATRICE m;

    reservation_en_memoire(SIZE, &m);
    ajouter_arc(&m, 1, 2);
    print_matrice(SIZE, &m);
    printf("%d\n", est_successeur(&m, 1, 2));

    return EXIT_SUCCESS;
    
}