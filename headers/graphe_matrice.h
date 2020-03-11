typedef int SID;

typedef struct {
    int n; // Nombre de somments
    int **M; // Matrice d'adjacence 
} MATRICE;

void reservation_en_memoire(int n, MATRICE *g);
// Reservation de l'espace memoire necessaire pour representer un graphe comportant n somments. 
// Cette fonction initialisera egalement le graphe de sorte a ce qu'il soit initialement sans arcs

void print_matrice(int n, MATRICE *g);
// Affichage de la matrice

void liberation_matrice(int n, MATRICE *g);
// Liberation en memoire de la matrice 

void ajouter_arc(MATRICE *g, SID i, SID j);
// Ajoute un arc entre les somments i et j s'il n'existe pas deja

void retirer_arc(MATRICE *g, SID i, SID j);
// Retire un arc entre les sommets i et j s'il existe

int est_successeur(MATRICE *g, SID i, SID j);
// Retourne 1 si j est successeur de i, 0 sinon