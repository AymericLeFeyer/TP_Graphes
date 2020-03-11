#include "../headers/graphe_liste.h"


void reservation_en_memoire(int n, LISTE *g){
  g->listes=malloc(n*sizeof(MAILLON));
    g->n=n;
}

void liberation_memoire(LISTE *g){
    free(g);
    free(g->listes);
    }

    void ajouter_arete(LISTE *g, SID i, SID j) { 

        MAILLON *Mi=g->listes[i];
        MAILLON *Mj=g->listes[j];
        int present=0;
        int x=0;
            MAILLON *NouveauI=malloc(sizeof(MAILLON));
            NouveauI->s=i;
            NouveauI->suivant=NULL;
            MAILLON *NouveauJ=malloc(sizeof(MAILLON));;
            NouveauJ->s=j;
            NouveauJ->suivant=NULL;


        if(!Mi || !Mj){
            g->listes[i]=NouveauJ;
            g->listes[j]=NouveauI;
            return;
        }


        while(Mj && Mi){
            if((Mj->s)==i || (Mi->s)==j)present=1;
            Mj=Mj->suivant;
            Mi=Mi->suivant;
        }



        if(!present){
            
            Mi=g->listes[i];
            while(Mi->suivant!=NULL){
                Mi=Mi->suivant;
            }
            while(Mj->suivant!=NULL){
                Mj=Mj->suivant;
            }

            Mi->suivant=NouveauJ;
            Mj->suivant=NouveauI;

        }
    }

void retirer_arete(LISTE *g, SID i, SID j){
        MAILLON *Mi=g->listes[i];
        MAILLON *Mj=g->listes[j];
        int present=0;

        while(Mj && Mi){
            if((Mj->s)==i || (Mi->s)==j)present=1;
            Mj=Mj->suivant;
            Mi=Mi->suivant;
        }



        if(present){
            if(g->listes[i]->s==j)g->listes[i]=g->listes[i]->suivant;
            if(g->listes[j]->s==i)g->listes[j]=g->listes[j]->suivant;
            while(Mi->suivant!=NULL){
                Mi->suivant=(Mi->suivant)->suivant;s
            }
            while(Mj->suivant!=NULL){
                Mj->suivant=(Mj->suivant)->suivant;
            }


        }
}

void affichage(LISTE *g){  
    int i;
    for(i=0;i<(g->n);i++){
        printf("%d",i);
        MAILLON *m=g->listes[i];
        while(m){
            printf("   %d  ",m->s);
            m=m->suivant;
        }
        printf("\n",i);

    }

}

int main(){
    LISTE G;
    int n=10;
    reservation_en_memoire(n,&G);
    ajouter_arete(&G,1,3);
    ajouter_arete(&G,1,5);

    affichage(&G);
}