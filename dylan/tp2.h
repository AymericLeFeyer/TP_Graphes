/*
GUERY Angèle
HELIN Dylan

 TP2 graphes et algorithmes
*/

#ifndef TP2_GRAPHES_TP2_H
#define TP2_GRAPHES_TP2_H

#include "stdlib.h"
#include "stdio.h"
typedef struct{
    int B1;            // quantite
    int B2;            // -||-
    int B3;            // -||-
}bouteilles;


//    capacites des bouteilles
#define C1                    14
#define C2                    8
#define C3                    6
//    la quantite qu'on cherche
#define QUANT_CHERCHER        7
#define min(X, Y) ( ((X) < (Y)) ? (X) : (Y) )

void ajouterTaille(bouteilles* t,int n);
bouteilles initB(int a, int b, int c);
void afficherBouteilles(bouteilles b);
int diviser_quantite(int a, int b, int c, int* n, bouteilles* tabB);
void afficherTab(bouteilles *t,int n);
#endif //TP2_GRAPHES_TP2_H
