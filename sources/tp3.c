// BAUDELET Conrad (git @Conrad523)
// LE FEYER Aymeric (git @AymericLeFeyer)

#include "../headers/tp3.h"
#include <stdbool.h>

int tab1[10000];
int index1 = 0;

// Parcours en profondeur
// G la liste a parcourir
// K le premier sommet
void parcours_en_profondeur(LISTE G, int K) {
    // On initialise le tableau
    for (int i = 0; i < 10000; i++) {
        tab1[i] = -1;
    }
    // La premiere valeur du tableau est le sommet K
    tab1[index1] = K;
    index1++;

    // On affiche ce sommet
    printf("%d ", K);

    // On appelle la fonction recursive
    pep(G, K);

    printf("\n");


}

// Parcours en largeur
// G la liste a parcourir
// K le premier sommet
void parcours_en_largeur(LISTE G, int K) {
    // On initialise le tableau
    int tab[10000];
    for (int i = 0; i < 10000; i++) {
        tab[i] = -1;
    }
    int index = 0;
    // La premiere valeur du tableau est le sommet K
    tab[index] = K;
    index++;
    // On affiche le sommet K
    printf("%d ", K);

    // On appelle la fonction recursive
    pel(G, K, tab, index);
    printf("\n");
}

// Fonction contient?
// arr le tableau d'entiers, et n sa taille
// val la valeur a chercher
bool isIn(int* arr, int n, int val) {
    // Mettre cette valeur a true pour avoir les messages
    bool debug = false;
    // On parcours tout le tableau
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            // Si on trouve la valeur on retourne true
            if (debug) printf("\nOui pour %d\n", val);
            return true;
        }
    }
    // Sinon on retourne false
    if (debug) printf("\nNon pour %d\n", val);
    return false;
}

// Pseudo-langage
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

// Fonction recursive pour le parcours en largeur
void pel(LISTE G, int n, int tab[], int index) {
    // Liste des nouvelles valeurs
    int nouveaux[1000] = {-1};
    int ind = 0;
    // Maillon qui sera utilisé pour parcourir
    MAILLON *m=G.listes[n];

    while(m){
        // Tant que m existe
        if (!isIn(tab, 1000, m->s)) {
            // Si la valeur n'est pas deja dans le tableau, on la met et on l'affiche
            // Cela est utile pour ne pas afficher plusieurs fois le meme sommet
            printf("%d ",m->s);
            tab[index++] = m->s;
            nouveaux[ind++] = m->s;
        }
        // On passe au maillon suivant
        m=m->suivant;
    }
    // Pour chaque suivant de ce maillon, on appelle pel
    for (int i = 0; i < ind; i++) {
        pel(G, nouveaux[i], tab, index);
    }


}

// Fonction recursive pour le parcours en profondeur
void pep(LISTE G, int n) {
    // Liste des nouvelles valeurs
    int nouveaux[1000] = {-1};
    int ind = 0;
    // Maillon 
    MAILLON *m=G.listes[n];
    while(m){
        // Tant que m existe
        if (!isIn(tab1, 1000, m->s)) {
            // Si la valeur n'est pas deja dans le tableau, on l'ajoute
            printf("%d ", m->s);
            tab1[index1++] = m->s;
            // On appelle pep
            pep(G, m->s);
            n++;
        }
        // On passe au maillon suivant
        m=m->suivant;
    }


}

LISTE graphe_reduit(LISTE g) {
    // Aucune idee 
    // ¯\_(ツ)_/¯
}