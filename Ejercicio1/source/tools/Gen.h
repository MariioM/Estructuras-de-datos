/* LIBRER�AS EST�NDAR*/
#define EXT TODO

#define MAX_CAR 50

typedef struct
{
    char Nombre[MAX_CAR];
    char Apellido[MAX_CAR];
    char Password[MAX_CAR];
} tElemento;

typedef struct _pnodo
{
    tElemento Elem;
    struct _pnodo *Sig;
} tNodo;

tNodo *CrearNodo(tElemento element)
{
    tNodo *nodo = (tNodo *)malloc(sizeof(tNodo));
    nodo->Elem = element;
    nodo->Sig = NULL;
    return nodo;
}

tNodo *DestruirNodo(tNodo *nodo)
{
    nodo->Sig = NULL;
    free(nodo);
}
