#include <stdlib.h>
#include <stdio.h>

#include "../headers/graphe_matrice.h"

// Fonctions de manipulation via une matrice d'adjacence

void reservation_en_memoire(int n, MATRICE *g) {
    g->n = n;
    g->M = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        g->M[i] = malloc(n * sizeof(int));
    }
}

void print_matrice(MATRICE *g) {
    printf("Affichage de la matrice\n");
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            if (j != g->n - 1) printf("%d | ", g->M[i][j]);
            else printf("%d", g->M[i][j]);
        }
        printf("\n");
    }
}

void liberation_matrice(MATRICE *g) {
    for (int i = 0; i < g->n; i++) {
        free(g->M[i]);
    }
    free(g->M);
}

void ajouter_arc(MATRICE *g, SID i, SID j) {
    if (g->M[i][j] == 0) g->M[i][j] = 1;
    else printf("Cet arc existe deja\n");
}

void retirer_arc(MATRICE *g, SID i, SID j) {
    if (g->M[i][j] == 1) g->M[i][j] = 0;
    else printf("Cet arc n'existe pas\n");
}

int est_successeur(MATRICE *g, SID i, SID j) {
    return g->M[i][j];
}

void calcul_degres(MATRICE *g, SID I, int *dplus, int *dmoins) {
    for (int i = 0; i < g->n; i++) {
        if (est_successeur(g, i, I)) (*dmoins)++;
        if (est_successeur(g, I, i)) (*dplus)++;
    }
    
}

void calcul_tous_degres(MATRICE *g, int **dplus, int **dmoins) {
    *dplus = (int*)malloc(g->n * sizeof(int));
    *dmoins = (int*)malloc(g->n * sizeof(int));
    for (int i = 0; i < g->n; i++) {
        int plus = 0;
        int moins = 0;

        calcul_degres(g, i, &plus, &moins);
        (*dplus)[i] = plus;
        (*dmoins)[i] = moins;

    }
    
}


void copie_graphe(MATRICE *g1, MATRICE *g2) {

}