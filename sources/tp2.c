// BAUDELET Conrad (git @Conrad523)
// LE FEYER Aymeric (git @AymericLeFeyer)

#include "../headers/tp2.h"

// Bouteilles (repris depuis le code en cpp)

// Complexite : O(n)
void ajouterTaille(bouteilles* t,int n){
    bouteilles * t2;
    t2 = (bouteilles*) malloc(n*sizeof(bouteilles));
    for(int i=0;i<n;i++){
        t2[i].B1=t[i].B1;
        t2[i].B2=t[i].B2;
        t2[i].B3=t[i].B3;
    }
    t=t2;
}

// Complexite : O(1)
bouteilles initB(int a, int b, int c){
    // Initialisation des bouteilles avec les valeurs a b et c
    bouteilles bouteille;
    bouteille.B1=a;
    bouteille.B2=b;
    bouteille.B3=c;
    return bouteille;
}

// Complexite : O(1)
void afficherBouteilles(bouteilles b){
    // Affichage des bouteilles
    printf("(%d , %d , %d)", b.B1, b.B2, b.B3);
}

// Complexite : O(n)
void afficherTab(bouteilles *t,int n){
    // Affichage de toutes les bouteilles avec l'appel de afficherBouteilles(bouteilles b)
    for (int i=0;i<n;i++){
        afficherBouteilles(t[i]);
    }
    printf("\n\n");
}

// Complexite : O(n)
int diviser_quantite(int a, int b, int c, int *n, bouteilles* tabB){
    // On init les bouteilles
    bouteilles bouteille = initB(a,b,c);
    // On parcours
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
    if ( (a > 0) ){
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
    if ( (b > 0) ){
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
    if ( (c > 0) ){
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

// Cours 

// Complexite : O(n)
void ajouterHoraire(int* p1, int* p2, int* p3, int np, int nc){
    switch (np) {
        // En fonction de np, on ajoute a p1 p2 ou p3 la valeur nc si c'est possible
        case 1:
            for(int i = 0 ; i < max; i++){
                if(p1[i]==0 && p2[i]!=nc && p3[i]!=nc){
                    p1[i]=nc;
                    break;
                }
            }
            break;
        
        case 2:
            for(int i = 0 ; i < max; i++){
                if(p2[i]==0 && p1[i]!=nc && p3[i]!=nc){
                    p2[i]=nc;
                    break;
                }
            }
            break;

        case 3:
            for(int i = 0 ; i < max; i++){
                if(p3[i] == 0 && p1[i]!=nc && p2[i]!=nc){
                    p3[i]=nc;
                    break;
                }
            }

            break;

        default:
            break;
    }
}

// Complexite : O(n)
int nbPlageHoraire(int* p1,int* p2,int* p3){
    // Compte le nombre de plages horaires
    int nb=0;
    int i;
    for(i=0; i<max;i++){
        if(p1[i]!=0 || p2[i]!=0 || p3[i]!=0){
            nb++;
        }
    }
    return nb;
}

// Complexite : O(n^2)
void coursMatrice(char* nom){
    MATRICE g;
    lire_grapheM(nom, &g);
    // Initialisation des tableaux
    int p1[max] = {0};
    int p2[max] = {0};
    int p3[max] = {0};

    // On parcours les matrices et on ajoute les horaires
    for(int i = 0; i<g.n; i++){
        for(int j=0; j<g.n; j++){
            for(int k=0; k<g.M[i][j]; k++){
                ajouterHoraire(p1, p2, p3, i+1, j+1);
            }
        }
    }
    printf("[Matrice] Nombre de jours minimum necessaires : %d\n",nbPlageHoraire(p1,p2,p3));
}

// Complexite : O(n^2)
void coursListe(char* nom){
    LISTE g;
    lire_graphe(nom, &g);
    // On init les tableaux
    int p1[max] = {0};
    int p2[max] = {0};
    int p3[max] = {0};

    MAILLON* courant = NULL;
    for(int i = 0; i<g.n ; i++){
        courant = g.listes[i];
        while(courant){
            for(int k = 0; k < courant->poids; k++){
                ajouterHoraire(p1, p2, p3, i+1, courant->s);
            }
            courant = courant->suivant;
        }
    }
    printf("[Liste] Nombre de jours minimum necessaires : %d\n",nbPlageHoraire(p1,p2,p3));
}

// Welsh Powell

void welsh_powell_liste(LISTE *g){
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

void welsh_powell_matrice(MATRICE *g){
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
            if (degreM(g,tab_degre[d]) < degreM(g,tab_degre[d+1]))
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
                        if(est_adjacentM(*g,tab_degre[i],tab_degre[j]) && couleur==tab_couleur[j]){
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

