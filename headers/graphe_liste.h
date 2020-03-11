typedef int SID;

typedef struct maillon {
    SID s;
    struct maillon *suivant;
} MAILLON;

typedef struct {
    int n;
    MAILLON **listes;
} LISTE;
