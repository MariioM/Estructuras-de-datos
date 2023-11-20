/* LIBRER�AS EST�NDAR*/
#define EXT TODO

#define MAX_CAR 50


typedef struct {
    char  Nombre[MAX_CAR];
    char Apellido[MAX_CAR];
    char Password[MAX_CAR];
} tElemento;

typedef struct _pnodo {
    tElemento Elem;
    struct _pnodo *Sig;
} tNodo;








