#ifndef GENEST
#include "Gen.h"
#define GENEST 1
#endif

typedef tNodo *tPosicion;
/* Cada posicion se referencia con un puntero. */

typedef struct
{                            /* Definimos el tipo lista con un puntero */
  tPosicion Primero, Ultimo; /* al primero y ultimo nodos. */
} tLista;

extern tLista CrearLista();
extern tLista Insertar(tLista l, tElemento e, tPosicion p);
extern tLista Borrar(tLista l, tPosicion p);
extern tElemento Recuperar(tPosicion p);
extern int EsListaVacia(tLista l);
extern tPosicion ConseguirPosicionFin(tLista l);
extern tPosicion ConseguirPosicionPrincipio(tLista l);
extern tPosicion ConseguirPosicionSiguiente(tPosicion p);
extern void VisualizarLista(tLista p);
extern int CalcularNumeroElementosLista(tLista p);
