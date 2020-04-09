#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "sources/graphe_matrice.c"
#include "sources/graphe_liste.c"
#include "sources/tp2.c"
#include "sources/tp3.c"

#define SIZE 4


int main(int argc, char** argv) {
    printf("TP Graphes et Algorithmes\nBAUDELET Conrad & LE FEYER Aymeric\n");
    int alive = 1;

    LISTE g, g3;

    reservation_en_memoireL(6, &g);
    ajouter_arete(&g, 5, 0);
    ajouter_arete(&g, 4, 0);
    ajouter_arete(&g, 1, 0);
    ajouter_arete(&g, 2, 0);
    ajouter_arete(&g, 1, 5);
    ajouter_arete(&g, 2, 5);
    ajouter_arete(&g, 1, 3);

    reservation_en_memoire2(6, &g3);
    ajouter_arete(&g3, 5, 0);
    ajouter_arete(&g3, 4, 0);
    ajouter_arete(&g3, 1, 0);
    ajouter_arete(&g3, 2, 0);
    ajouter_arete(&g3, 1, 5);
    ajouter_arete(&g3, 2, 5);
    ajouter_arete(&g3, 1, 3);
    int m = 5;

    MATRICE g2;
    reservation_en_memoireM(6, &g2);
    ajouter_arc(&g2, 5, 0);
    ajouter_arc(&g2, 0, 5);
    ajouter_arc(&g2, 4, 0);
    ajouter_arc(&g2, 1, 0);
    ajouter_arc(&g2, 2, 0);
    ajouter_arc(&g2, 1, 5);
    ajouter_arc(&g2, 2, 5);
    ajouter_arc(&g2, 1, 3);



    // Nouveau graphe
    // reservation_en_memoire(SIZE, &m);
    // Ajouts d'arcs
    // ajouter_arc(&m, 1, 2);
    // ajouter_arc(&m, 2, 3);
    // Affichage de la matrice
    // print_matrice(&m);
    // Lancement de la fonction permettant de calculer tous les degres
    // calcul_tous_degres(&m, &dplus, &dmoins);
    // Affichage des degres
    // for (int i = 0; i < SIZE; i++) {
    //     printf("%d, %d\n", dplus[i], dmoins[i]);
    // }
    // Copie dans m2
    // copie_graphe(&m, &m2);
    // print_matrice(&m2);
    // ecrire_graphe(&m, "test.txt");
    // lire_graphe("test.txt", &m);
    // print_matrice(&m);
    int choix = 0;

    while (alive) {
        printf("-----------\n");
        printf("0 ~ QUITTER\n");
        printf("1 ~ TP2 - EX1 : BOUTEILLES\n");
        printf("2 ~ TP2 - EX2 : COURS\n");
        printf("3 ~ TP2 - EX3 : WELSH POWELL\n");
        printf("4 ~ TP3 - EX1 : PARCOURS EN PROFONDEUR\n");
        printf("5 ~ TP3 - EX2 : PARCOURS EN LARGEUR\n");
        printf("6 ~ TP3 - EX3 : CONNEXITE\n");
        printf("7 ~ AFFICHAGE DU GRAPHE\n");
        printf("Que faire ? \n");
        printf("-----------\n");
        scanf("%d", &choix);
        switch (choix)
        {
            case 1:
                // TP2 - EX1 : BOUTEILLES
                printf("--Bouteilles--\n");
                bouteilles* tabB;
                int n;
                n=0;
                tabB= (bouteilles *) malloc(sizeof(bouteilles));
                diviser_quantite(14,0,0,&n,tabB);
                break;

            case 2:
                // TP2 - EX2 : COURS
                printf("\n--Cours--\n");
                coursMatrice("ex2-matrice.txt");
                coursListe("ex2-liste.txt");
                break;

            case 3:
                // TP2 - EX3 : WELSH POWELL
                printf("--[Liste] Welsh Powell--\n");
                welsh_powell_liste(&g);
                printf("--[Matrice] Welsh Powell--\n");
                welsh_powell_matrice(&g2);
                break;

            case 4:
                // TP3 - EX1 : PARCOURS EN PROFONDEUR
                printf("--Parcours en profondeur--\n");
                parcours_en_profondeur(g3, m);
                break;

            case 5:
                // TP3 - EX2 : PARCOURS EN LARGEUR
                printf("--Parcours en largeur--\n");
                parcours_en_largeur(g3, m);
                break;

            case 6:
                // TP3 - EX3 : CONNEXITE
                printf("Cet exercice n'a pas ete realise\n");
                break;

            case 7:
                // Affichage du graphe
                affichage(&g3);
                break;

            default:
                alive = 0;
                break;
        }
    }

    return EXIT_SUCCESS;

}
