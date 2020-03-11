typedef int SID;

typedef struct {
    int n; // Nombre de somments
    int **M; // Matrice d'adjacence 
} MATRICE;

void reservation_en_memoire(int n, MATRICE *g);
// Reservation de l'espace memoire necessaire pour representer un graphe comportant n somments. 
// Cette fonction initialisera egalement le graphe de sorte a ce qu'il soit initialement sans arcs

void print_matrice(MATRICE *g);
// Affichage de la matrice

void liberation_matrice(MATRICE *g);
// Liberation en memoire de la matrice 

void ajouter_arc(MATRICE *g, SID i, SID j);
// Ajoute un arc entre les somments i et j s'il n'existe pas deja

void retirer_arc(MATRICE *g, SID i, SID j);
// Retire un arc entre les sommets i et j s'il existe

int est_successeur(MATRICE *g, SID i, SID j);
// Retourne 1 si j est successeur de i, 0 sinon

void calcul_degres(MATRICE *g, SID I, int *dplus, int *dmoins);
// Generation de deux entiers, dplus et dmoins, contenant pour un
// sommet I son degre sortant (dplus) et son degre entrant (dmoins)
// Degre entrant : nombre d'arc entrant dans s
// Degre sortant : nombre d'arc sortant de s

void calcul_tous_degres(MATRICE *g, int **dplus, int **dmoins);
// Generation de deux tableaux, dplus et dmoins, contenant pour chaque
// sommet i son degre sortant (dplus[i]) et son degre entrant (dmoins[i])
// Degre entrant : nombre d'arc entrant dans s
// Degre sortant : nombre d'arc sortant de s

void copie_graphe(MATRICE *g1, MATRICE *g2);
// Copie du graphe g1 dans le graphe g2

void lire_graphe(char *nom, MATRICE *g);
// Lit un graphe depuis le fichier nom et met le contenu dans g

void ecrire_graphe(MATRICE *g, char *nom);
// Ecrit le contenu du graphe g dans le fichier nom