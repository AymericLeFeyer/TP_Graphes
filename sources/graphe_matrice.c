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
    printf("Affichage de la matrice\n");
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

void calcul_degres(MATRICE *g, SID I, int *dplus, int *dmoins) {
    int entrant, sortant;
    dplus = (int*)malloc(I*sizeof(int));
    dmoins = (int*)malloc(I*sizeof(int));
    for (int s = 0; s < I; s++) {
        entrant = 0;
        sortant = 0;
        for (int i = 0; i < I; i++) {
            if (est_successeur(g, i, s)) entrant++;
            if (est_successeur(g, s, i)) sortant++;
        }
        dplus[s] = sortant;
        dmoins[s] = entrant;
    }
    afficher_degres(I, dplus, dmoins);
}

void afficher_degres(int n, int *dplus, int *dmoins) {
    printf("Affichage des degres entrants et sortants\n");
    for (int i = 0; i < n; i++) {
        printf("%d(E:%d, S:%d)\n", i, dmoins[i], dplus[i]);
    }
}