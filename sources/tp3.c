#include "../headers/tp3.h"
#include <stdbool.h>

int tab1[10000];
int index1 = 0;


void parcours_en_profondeur(LISTE G, int K) {
    for (int i = 0; i < 10000; i++) {
        tab1[i] = -1;
    }
    tab1[index1] = K;
    index1++;

    printf("%d ", K);
    pep(G, K);

    printf("\n");

    
}

void parcours_en_largeur(LISTE G, int K) {
    int tab[10000];
    for (int i = 0; i < 10000; i++) {
        tab[i] = -1;
    }
    int index = 0;
    tab[index] = K;
    index++;
    printf("%d ", K);
    pel(G, K, tab, index);
    printf("\n");
}

bool isIn(int* arr, int n, int val) {
    bool debug = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            if (debug) printf("\nOui pour %d\n", val);
            return true;
        }
    }
    if (debug) printf("\nNon pour %d\n", val);
    return false;
}

// aff(int n, int[] tab) {
//     pour tous les suivants s de n {
//         si s n'est pas dans tab {
//             aff(s)
//             on ajoute s dans tab
//             si s est le dernier suivant {
                    // on passe une ligne
//              }
//         }
//     }
// }

void pel(LISTE G, int n, int tab[], int index) {
    int nouveaux[1000] = {-1};
    int ind = 0;
    MAILLON *m=G.listes[n];
    while(m){

        if (!isIn(tab, 1000, m->s)) {
            printf("%d ",m->s);
            tab[index++] = m->s; 
            nouveaux[ind++] = m->s;
        }
        
        m=m->suivant;  
    }
    for (int i = 0; i < ind; i++) {
        pel(G, nouveaux[i], tab, index);
    }


}


void pep(LISTE G, int n) {
    int nouveaux[1000] = {-1};
    int ind = 0;
    MAILLON *m=G.listes[n];
    while(m){

        if (!isIn(tab1, 1000, m->s)) {
            printf("%d ", m->s);
            tab1[index1++] = m->s; 
            pep(G, m->s);
            n++;
        }
        
        m=m->suivant;  
    }
    

}