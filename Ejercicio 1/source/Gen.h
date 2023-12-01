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

/// @brief Crea un nodo con el elemento que se le pasa como parámetro.
/// @param element
/// @return Nodo con el elemento que se le pasa como parámetro.
extern tNodo *CrearNodo(tElemento element);
/// @brief Destruye el nodo que se le pasa como parámetro.
/// @param nodo Nodo
/// @return
extern tNodo *DestruirNodo(tNodo *nodo);
