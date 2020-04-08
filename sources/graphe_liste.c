#include "../headers/graphe_liste.h"


void reservation_en_memoireL(int n, LISTE *g){
    g->n=n;
    g->listes=(MAILLON **)malloc(n*sizeof(MAILLON *));
    for (int i = 0;i<n;i++){
        g->listes[i]=(MAILLON *)malloc(sizeof(MAILLON));
        if(g->listes[i]){
            g->listes[i]->s = -1;
            g->listes[i]->poids = -1;
            g->listes[i]->suivant = NULL;
        }
    }
}

void liberation_memoire(LISTE *g){
    free(g);
    free(g->listes);
    }

    void ajouter_arete(LISTE *g, SID i, SID j) { 
            int miC=0;
            int mjC=0;

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


        if(!Mi){
            g->listes[i]=NouveauJ;
             miC=1;
        }

        if(!Mj){
            g->listes[j]=NouveauI;
             mjC=1;
        }


        while(Mj && Mi){
            if((Mj->s)==i || (Mi->s)==j)present=1;
            Mj=Mj->suivant;
            Mi=Mi->suivant;
        }



        if(!present){
            
            if(miC==0){
                Mi=g->listes[i];
                while(Mi->suivant!=NULL){
                    Mi=Mi->suivant;
                }
                Mi->suivant=NouveauJ;

            }
            if(mjC==0){
                Mj=g->listes[j];
                while(Mj->suivant!=NULL){
                        Mj=Mj->suivant;
                } Mj->suivant=NouveauI;
            }
            

        }
    }

int est_adjacent(LISTE *g, SID i, SID j){
    int present=0;
    MAILLON *Mi=g->listes[i];
    MAILLON *Mj=g->listes[j];
    while(Mj && Mi){
            if((Mj->s)==i || (Mi->s)==j)present=1;
            Mj=Mj->suivant;
            Mi=Mi->suivant;
        }
        return present;


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
            if(Mi->s==j)g->listes[i]=g->listes[i]->suivant;
            if(Mj->s==i)g->listes[j]=g->listes[j]->suivant;
            while(Mi->suivant!=NULL){
                Mi->suivant=(Mi->suivant)->suivant;
            }
            while(Mj->suivant!=NULL){
                Mj->suivant=(Mj->suivant)->suivant;
            }


        }
}

void affichage(LISTE *g){  
    int i;
    for(i=0;i<(g->n);i++){
        printf("%d(%d)",i,degre(g,i));
        MAILLON *m=g->listes[i];
        while(m){
            printf("   %d  ",m->s);
            m=m->suivant;
        }
        printf("\n");

    }

}

void ajouter_poidsL(LISTE *g, SID i, SID j){
    MAILLON* courant = g->listes[i];
    if(courant == NULL){
        g->listes[i]=(MAILLON *)calloc(1,sizeof(MAILLON));
        g->listes[i]->s = j;
        g->listes[i]->poids = 1;
    }else{
        while(courant != NULL){
            if(courant->s == j){
                courant->poids = courant->poids + 1;
                return;
            }
            courant = courant->suivant;
        }
    }
}

void lire_graphe(char *nom, LISTE *g){
    char temp[64];
    int n,i,j;
    FILE *f=fopen(nom,"r");
    if (f != NULL){
        fgets(temp,64,f);
        sscanf(temp,"%d",&n);
        reservation_en_memoireL(n, g);
        while (fgets(temp,64,f)!=NULL){
            sscanf(temp,"%d",&i);
            for(int k=1;k<64;k++){
                if(temp[k]=='\n' || temp[k]=='\0'){
                    break;
                }
                if(temp[k]!=' '){
                    sscanf(temp+k,"%d",&j);
                    if(est_adjacent(g, i, j)==1){
                        ajouter_poidsL(g, i, j);
                    }else{
                        ajouter_arete(g, i, j);
                    }
                    // printf("%d %d\n",i,j);
                }
            }
            // printf("\n");
        }
        fclose(f);
    }
    else{
        printf("Impossible d'ouvrir le fichier %s",nom);
    }
}

void ecrit_graphe(LISTE *g, char *nom){
    FILE   *fichier;
    int i ;
    fichier=fopen(nom,"w");
    if (fichier != NULL){
        fprintf(fichier," %d \n",g->n);    
        for(i=0;i<(g->n);i++){
            MAILLON *m=g->listes[i];
            while(m){
                fprintf(fichier," %d %d \n",m->s,i);
                m=m->suivant;
            }
        }
    }
    fclose(fichier);
}



int TP2_EXO2_GRAPHE(){
    //TP2 EXO 2
    LISTE G;
    int n=6;
    reservation_en_memoireL(n,&G);
   
       
    ajouter_arete(&G,0,3);
    ajouter_arete(&G,0,4);

    ajouter_arete(&G,1,3);
    ajouter_arete(&G,1,4);
    ajouter_arete(&G,1,5);

    ajouter_arete(&G,2,3);
    ajouter_arete(&G,2,4);
    ajouter_arete(&G,2,5);

    ecrit_graphe(&G,"TP2 EXO2.txt");
   printf("%d",nb_arrete(&G));


}

LISTE graphe_alea_toire(int n ,int m){
        LISTE G;
    reservation_en_memoireL(n,&G);
   srand (time (NULL));
   while(nb_arrete(&G)!=m){
       int a=(int)(rand() / (double)RAND_MAX * (n));
       int b=(int)(rand() / (double)RAND_MAX * (n));
       if(a!=b)ajouter_arete(&G,a,b);
   }
    return G;
}

 int nb_arrete(LISTE *g){
    int nb=0;
    int i;
    for(i=0;i<(g->n);i++){
            MAILLON *m=g->listes[i];
            while(m){
                nb++;
                m=m->suivant;
            }
        }
        return nb/2;
}

int degre(LISTE *g,int n){
        int nb=0;

    MAILLON *m=g->listes[n];
            while(m){
                nb++;
                m=m->suivant;
            }
            return nb;
}



void welsh_wowell(LISTE *g){
    //etape 1 ranger dans l'ordre décroissant
    int tab_couleur[g->n];
    int tab_degre[g->n];
    int i;
    for ( i =0;i<(g->n);i++){
        tab_degre[i]=i;
        tab_couleur[i]=0;
            }

    int c;
    int d;
    int swap;
    for (c = 0 ; c < (g->n); c++)
    {
    for (d = 0 ; d < (g->n) - c -1 ; d++)
    {
      if (degre(g,tab_degre[d]) < degre(g,tab_degre[d+1])) 
      {
        swap       = tab_degre[d];
        tab_degre[d]   = tab_degre[d+1];
        tab_degre[d+1] = swap;
      }
    }
  }

  //Etape 2 choisir une couleur
  i=0;
  int couleur=1;
  int changement=1;
  int j=0;
  while(changement){
      changement=0;
      i=0;
    while(i!=((g->n)+1)){
      if(tab_couleur[i]==0){
          
          if(changement){
              int peutPas=0;
              for(j=0;j<(g->n);j++){
                  if(est_adjacent(g,tab_degre[i],tab_degre[j]) && couleur==tab_couleur[j]){
                      peutPas=1;
                  }   
              }
              if(!peutPas)tab_couleur[i]=couleur;
          }
          else{
            tab_couleur[i]=couleur;
            changement=1;
          }
    }
    i++;
  }
  couleur++;

  }
  
  for (int i =0;i<(g->n);i++){
        printf("%d(%d)\n",tab_degre[i],tab_couleur[i]);
    }

}



// int main(){
//     LISTE g=graphe_alea_toire(6,7);
//    affichage(&g);
//    welsh_wowell(&g);
// }

/*
int main_test(){
        LISTE G;
    int n=6;
    reservation_en_memoireL(n,&G);
   
    
   ajouter_arete(&G,1,3);
   ajouter_arete(&G,1,5);
   ajouter_arete(&G,1,4);
   ajouter_arete(&G,1,5);
    
    int i_adj=1;
    int j_adj=2;
    printf("\n%d adjacent à %d ? %d\n\n",i_adj,j_adj,est_adjacent(&G,i_adj,j_adj));
    
    
    ecrit_graphe(&G,"fichier.txt");
    lire_graphe("fichier.txt",&G);
     affichage(&G);

}*/