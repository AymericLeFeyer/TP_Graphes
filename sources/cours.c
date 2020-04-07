#include "../headers/cours.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    return 0;
}

void tabZero(int* p1,int* p2,int* p3){
    int i;
    for(i=0;i<max;i++){
        p1[i]=0;
        p2[i]=0;
        p3[i]=0;
    }
}

void ajoutHoraire(int* p1,int* p2,int* p3,int np,int nc){
    int i;
    if(np == 1){
        for(i=0 ; i<max; i++){
            if(p1[i]==0 && p2[i]!=nc && p3[i]!=nc){
                p1[i]=nc;
                break;
            }
        }
    }
    else{
        if(np == 2){
            for(i=0 ; i<max; i++){
                if(p2[i]==0 && p1[i]!=nc && p3[i]!=nc){
                    p2[i]=nc;
                    break;
                }
            }

        }
        else{
            if(np == 3){
                for(i=0 ; i<max; i++){
                    if(p3[i]==0 && p1[i]!=nc && p2[i]!=nc){
                        p3[i]=nc;
                        break;
                    }
                }
            }
        }
    }
}

int nbPlageHoraire(int* p1,int* p2,int* p3){
    int nb=0;
    int i;
    for(i=0; i<max;i++){
        if(p1[i]!=0 || p2[i]!=0 || p3[i]!=0){
            nb++;
        }
    }
    return nb;
}

void exercice2_TP2_Matrice(char* nom){
    MATRICE g;
    lire_grapheM(nom, &g);
    int p1[max];
    int p2[max];
    int p3[max];
    tabZero(p1,p2,p3);
    int np; //quel prof
    int nc; //quel classe
    int i,j;
    for(i=0;i<g.n;i++){
        for(j=0;j<g.n;j++){
            for(int k=0;k<g.M[i][j];k++){
                ajoutHoraire(p1,p2,p3,i+1,j+1);
            }
        }
    }
    printf("nombre de jours minimum necessaires : %d",nbPlageHoraire(p1,p2,p3));
}

void exercice2_TP2_Liste(char* nom){
    LISTE g;
    lire_graphe(nom, &g);
    int p1[max];
    int p2[max];
    int p3[max];
    tabZero(p1,p2,p3);
    int np; //quel prof
    int nc; //quel classe
    int i;
    affichage(&g);
    MAILLON * courant=NULL;
    for(i=0;i<g.n;i++){
        courant = g.listes[i];
        while(courant != NULL){
            for(int k=0;k<courant->poids;k++){
                ajoutHoraire(p1,p2,p3,i+1,courant->s);
            }
            courant=courant->suivant;
        }
    }
    printf("nombre de jours minimum necessaires : %d",nbPlageHoraire(p1,p2,p3));
}

