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

void print_matrice(int n, MATRICE *g) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j != n - 1) printf("%d | ", g->M[i][j]);
            else printf("%d", g->M[i][j]);
        }
        printf("\n");
    }
}

void liberation_matrice(int n, MATRICE *g) {
    for (int i = 0; i < n; i++) {
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