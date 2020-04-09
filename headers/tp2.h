// BAUDELET Conrad (git @Conrad523)
// LE FEYER Aymeric (git @AymericLeFeyer)

#define max 10
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int B1;
    int B2;
    int B3;
} bouteilles;


//    capacites des bouteilles
#define C1                    14
#define C2                    8
#define C3                    6

//    la quantite qu'on cherche
#define QUANT_CHERCHER        7
#define min(X, Y) ( ((X) < (Y)) ? (X) : (Y) )

void ajouterHoraire(int* p1,int* p2,int* p3,int np,int nc);
int nbPlageHoraire(int* p1,int* p2,int* p3);
void coursMatrice(char* nom);
void coursListe(char* nom);

void welsh_powell_liste(LISTE *g);
void welsh_powell_matrice(MATRICE *g);