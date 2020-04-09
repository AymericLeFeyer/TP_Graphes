// BAUDELET Conrad (git @Conrad523)
// LE FEYER Aymeric (git @AymericLeFeyer)

#include <stdbool.h>

void parcours_en_profondeur(LISTE G, int K);
void parcours_en_largeur(LISTE G, int K);
void pel(LISTE G, int n, int tab[], int index);
bool isIn(int* arr, int n, int val);
void pep(LISTE G, int n);
LISTE graphe_reduit(LISTE g);