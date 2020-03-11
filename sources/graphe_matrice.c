#include <stdlib.h>
#include <stdio.h>

#include "../headers/graphe_matrice.h"

// Fonctions de manipulation via une matrice d'adjacence

void reservation_en_memoire(int n, MATRICE *g) {
    g->n = n;
    // Allocation dynamique du premier tableau
    g->M = malloc(n * sizeof(int*));
    // Allocation dynamique pour chaque tableau dans le tableau
    for (int i = 0; i < n; i++) {
        g->M[i] = malloc(n * sizeof(int));
    }
}

void print_matrice(MATRICE *g) {
    printf("Affichage de la matrice\n");
    // Parcours de la matrice et affichage
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            if (j != g->n - 1) printf("%d | ", g->M[i][j]);
            else printf("%d", g->M[i][j]);
        }
        printf("\n");
    }
}

void liberation_matrice(MATRICE *g) {
    // On libere tous les tableaux du tableau
    for (int i = 0; i < g->n; i++) {
        free(g->M[i]);
    }
    // On libere le tableau final
    free(g->M);
}

void ajouter_arc(MATRICE *g, SID i, SID j) {
    // On ajoute l'arc s'il existe pas
    if (g->M[i][j] == 0) g->M[i][j] = 1;
    else printf("Cet arc existe deja\n");
}

void retirer_arc(MATRICE *g, SID i, SID j) {
    // On retire l'arc s'il existe
    if (g->M[i][j] == 1) g->M[i][j] = 0;
    else printf("Cet arc n'existe pas\n");
}

int est_successeur(MATRICE *g, SID i, SID j) {
    // j est successeur de i s'il y a une correspondance dans la matrice
    return g->M[i][j];
}

void calcul_degres(MATRICE *g, SID I, int *dplus, int *dmoins) {
    // On compte le nombre de entrant/sortant dans chaque sommet
    for (int i = 0; i < g->n; i++) {
        if (est_successeur(g, i, I)) (*dmoins)++;
        if (est_successeur(g, I, i)) (*dplus)++;
    }
    
}

void calcul_tous_degres(MATRICE *g, int **dplus, int **dmoins) {
    // Allocation dynamique des deux tableaux
    *dplus = (int*)malloc(g->n * sizeof(int));
    *dmoins = (int*)malloc(g->n * sizeof(int));
    // Parcours de tous les sommets
    for (int i = 0; i < g->n; i++) {
        // Reinitialisation des valeurs tampoins
        int plus = 0;
        int moins = 0;
        // Calcul pour le sommet i
        calcul_degres(g, i, &plus, &moins);
        // On entre ces valeurs dans les tableaux
        (*dplus)[i] = plus;
        (*dmoins)[i] = moins;
    }
}

void copie_graphe(MATRICE *g1, MATRICE *g2) {
    // Allocation et copie de n
    reservation_en_memoire(g1->n, g2);
    // Parcours de g1 et copie dans g2
    for (int i = 0; i < g1->n; i++) {
        for (int j = 0; j < g1->n; j++) {
            g2->M[i][j] = g1->M[i][j];
        }
    }
}

void lire_graphe(char*nom, MATRICE *g) {
    FILE* f = NULL;
    f = fopen(nom, "r");
    fscanf(f, "%d\n", &(g->n));
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            fscanf(f, "%d ", &(g->M[i][j]));
        }
        fscanf(f, "\n");
    }

}

void ecrire_graphe(MATRICE *g, char *nom) {
    FILE* f = NULL;
    f = fopen(nom, "w");
    fprintf(f, "%d\n", g->n);
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            fprintf(f, "%d ", g->M[i][j]);
        }
        fprintf(f, "\n");
    }
}