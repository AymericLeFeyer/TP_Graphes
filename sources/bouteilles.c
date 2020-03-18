#include "../sources/graphe_matrice.c"
#include "../headers/bouteilles.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

    reservation_en_memoire(M.n + 1, &M); // on commence pas a 0
    ajouter_arc(&M, 1, 2);
    ajouter_arc(&M, 1, 3);
    ajouter_arc(&M, 2, 1);
    ajouter_arc(&M, 2, 3);
    ajouter_arc(&M, 3, 1);
    ajouter_arc(&M, 3, 2);

    transvider(&b1, &b2);

    
    afficher_bouteilles(b1, b2, b3);

    parcours(&b1, &b2, &b3, objectif, 1, 3);



    
    return 0;
}

// puts b1 in b2
bool transvider(bouteille *b1, bouteille *b2) {
    b2->contenance += b1->contenance;
    b1->contenance = 0;
    if (b2->contenance > b2->contenance_max) {
        b1->contenance = b2->contenance - b2->contenance_max;
        b2->contenance = b2->contenance_max;
    }
    return true;
}

// Affiche les bouteilles
void afficher_bouteilles(bouteille b1, bouteille b2, bouteille b3) {
    printf("%d, %d, %d\n", b1.contenance, b2.contenance, b3.contenance);
}

void parcours(bouteille *b1, bouteille *b2, bouteille *b3, int objectif, int index, int max) {
    if (max == 0) return;
    if (b2->contenance == objectif && b3->contenance == objectif) {
        printf("Oiu");
        return;
    }
    afficher_bouteilles(*b1, *b2, *b3);
    printf("%d\n", index);
    bouteille temp1;
    temp1.contenance = b1->contenance;
    temp1.contenance_max = b1->contenance_max;
    bouteille temp2;
    temp2.contenance = b2->contenance;
    temp2.contenance_max = b2->contenance_max;
    bouteille temp3;
    temp3.contenance = b3->contenance;
    temp3.contenance_max = b3->contenance_max;

    if (index == 1) {
        transvider(b1, b2);
        transvider(&temp1, &temp3);
        parcours(b1, b2, b3, objectif, 2, max - 1);
        parcours(b1, b2, b3, objectif, 3, max - 1);
        parcours(&temp1, b2, &temp3, objectif, 2, max - 1);
        parcours(&temp1, b2, &temp3, objectif, 3, max - 1);
    }

    if (index == 2) {
        transvider(b2, b1);
        transvider(&temp2, &temp3);
        parcours(b1, b2, b3, objectif, 1, max - 1);
        parcours(b1, b2, b3, objectif, 3, max - 1);
        parcours(b1, &temp2, &temp3, objectif, 1, max - 1);
        parcours(b1, &temp2, &temp3, objectif, 3, max - 1);
    }

    if (index == 3) {
        transvider(b3, b1);
        transvider(&temp3, &temp2);
        parcours(b1, b2, b3, objectif, 1, max - 1);
        parcours(b1, b2, b3, objectif, 2, max - 1);
        parcours(b1, &temp2, &temp3, objectif, 1, max - 1);
        parcours(b1, &temp2, &temp3, objectif, 2, max - 1);
    }

    



}