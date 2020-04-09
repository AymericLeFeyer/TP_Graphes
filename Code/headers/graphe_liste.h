// BAUDELET Conrad (git @Conrad523)
// LE FEYER Aymeric (git @AymericLeFeyer)

#ifdef SID
typedef int SID;
#endif

typedef struct maillon {
    SID s;
    struct maillon *suivant; /* Pointeur vers le maillon suivant */
    int poids;
} MAILLON;

typedef struct {
    int n;
    MAILLON **listes;
} LISTE;


/*
R´eservation de l’espace m´emoire n´ecessaire pour repr´esenter un graphe
comportant n sommets. Cette fonction initialisera ´egalement le graphe
de sorte `a ce qu’il soit initialement sans arˆete :*/
// Il y a en deux, nous avons eu des soucis entre Windows et Linux
void reservation_en_memoireL(int n, LISTE *g);
void reservation_en_memoire2(int n, LISTE *g);

/*2. Lib´eration de la m´emoire occup´ee par le graphe g :*/
void liberation_memoire(LISTE *g);

/*Ajout d’une arˆete entre les sommets i et j dans le graphe g si elle
n’existe pas d´ej`a :*/
void ajouter_arete(LISTE *g, SID i, SID j);

/*4. Retrait de l’arˆete entre les sommets i et j si elle existe dans le graphe
g :*/
void retirer_arete(LISTE *g, SID i, SID j);

/*5. Affichage d’un graphe sous forme textuelle (une ligne par sommet avec
le sommet en d´ebut de ligne et la liste de ses sommets adjacents ensuite) :*/
void affichage(LISTE *g);

void ajouter_poidsL(LISTE *g, SID i, SID j);

/*6. Fonction qui retourne 1 si j est adjacent `a i dans le graphe g, 0 sinon :*/
int est_adjacent(LISTE *g, SID i, SID j);

/*7. Lecture et rangement dans g du graphe contenu dans le fichier de nom
physique nom :*/
void lire_graphe(char *nom, LISTE *g);

/*8. Ecriture du graphe ´ g dans le fichier de nom physique nom :*/
void ecrit_graphe(LISTE *g, char *nom);

int nb_arrete(LISTE *g);
int degre(LISTE *g,int n);
