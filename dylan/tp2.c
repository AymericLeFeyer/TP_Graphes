/*
GUERY Angèle
HELIN Dylan

 TP2 graphes et algorithmes
*/

#include "tp2.h"


void ajouterTaille(bouteilles* t,int n){
    bouteilles * t2;
    t2 = (bouteilles*) malloc(n*sizeof(bouteilles));
    for(int i=0;i<n;i++){
        t2[i].B1=t[i].B1;
        t2[i].B2=t[i].B2;
        t2[i].B3=t[i].B3;
        /*afficherBouteilles(t[i]);
        afficherBouteilles(t2[i]);*/
    }
    t=t2;
}

bouteilles initB(int a, int b, int c){
    bouteilles bouteille;
    bouteille.B1=a;
    bouteille.B2=b;
    bouteille.B3=c;
    return bouteille;
}

void afficherBouteilles(bouteilles b){
    printf("( %d , %d , %d )",b.B1,b.B2,b.B3);
}

void afficherTab(bouteilles *t,int n){
    for (int i=0;i<n;i++){
        afficherBouteilles(t[i]);
    }
    printf("\n\n");
}

int diviser_quantite(int a, int b, int c, int *n, bouteilles* tabB){
    bouteilles bouteille = initB(a,b,c);
    for (int i = 0 ; i < *n ; i++){
        if ( (tabB[i].B1 == a) && (tabB[i].B2 == b) && (tabB[i].B3 == c) ){
            printf(" < ");
            return 0;
        }
    }
    *n = *n + 1;
    ajouterTaille(tabB,*n);
    tabB[*n-1]=bouteille;
    printf("\n");
    afficherBouteilles(bouteille);

    int quantite_transvider;
    int nouvelle_quantite;
    if ( (a > 0) ){                //        on le fait dabord avec la premiere bouteille
        if (b < C2){
            nouvelle_quantite = min(b+min(a,C2),C2);
            quantite_transvider = nouvelle_quantite - b;
            diviser_quantite(a-quantite_transvider,nouvelle_quantite,c,n,tabB);
        }
        if (c < C3){
            nouvelle_quantite = min(c+min(a,C3),C3);
            quantite_transvider = nouvelle_quantite - c;
            diviser_quantite(a-quantite_transvider,b,nouvelle_quantite,n,tabB);
        }
    }
    if ( (b > 0) ){            //        ensuite avec la deuxieme bouteille
        if (c < C3){
            nouvelle_quantite = min(c+min(b,C3),C3);
            quantite_transvider = nouvelle_quantite - c;
            diviser_quantite(a,b-quantite_transvider,nouvelle_quantite,n,tabB);
        }
        if (a < C1){
            nouvelle_quantite = min(a+min(b,C1),C1);
            quantite_transvider = nouvelle_quantite - a;
            diviser_quantite(nouvelle_quantite,b-quantite_transvider,c,n,tabB);
        }
    }
    if ( (c > 0) ){            //        troisieme bouteille
        if (a < C1){
            nouvelle_quantite = min(a+min(c,C1),C1);
            quantite_transvider = nouvelle_quantite - a;
            diviser_quantite(nouvelle_quantite,b,c-quantite_transvider,n,tabB);
        }
        if (b < C2){
            nouvelle_quantite = min(b+min(b,C3),C3);
            quantite_transvider = nouvelle_quantite - b;
            diviser_quantite(a,nouvelle_quantite,c-quantite_transvider,n,tabB);
        }
    }

    if ( (a == QUANT_CHERCHER) && (b == QUANT_CHERCHER) )
        return 1;
    else
        return 0;
}

int main() {
    bouteilles* tabB;
    int n;
    n=0;
    tabB= (bouteilles *) malloc(sizeof(bouteilles));
    diviser_quantite(14,0,0,&n,tabB);
    return 0;
}

/*int main(void){
    diviser_quantite(14,0,0);
    getchar();
    return 0;
}*/

/*int main(){

    tabB a = (bouteilles *) calloc(3, sizeof(bouteilles));
    printf("%d", sizeof(a));
    return 0;
    int p1[max];
    int p2[max];
    int p3[max];
    int np; //quel prof
    int nc; //quel classe


}*/

/*void tabZero(int* p1,int* p2,int* p3){
    int i;
    for(i=0;i<max;i++){
        p1[i]=0;
        p2[i]=0;
        p3[i]=0;
    }
}

void ajoutHoraire(int* p1,int* p2,int* p3,int* np,int* nc){
    int i;
    if(np == 1){
        for(i=0 ; i<max; i++){
            if(p1[i]==0 && p2[i]!=nc && p3!=nc){
                p1=nc;
                break;
            }
        }
    }
    else{
        if(np == 2){
            for(i=0 ; i<max; i++){
                if(p2[i]==0 && p1[i]!=nc && p3!=nc){
                    p2=nc;
                    break;
                }
            }

        }
        else{
            if(np == 3){
                for(i=0 ; i<max; i++){
                    if(p3[i]==0 && p1[i]!=nc && p2!=nc){
                        p3=nc;
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
}*/