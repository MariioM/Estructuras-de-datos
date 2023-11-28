/* LIBRERÍAS ESTÁNDAR*/

#ifndef GENEST
#include "Gen.h"
#define GENEST 1
#endif

typedef tNodo *tPosicion; // Cada posicion se referencia con un puntero.

typedef struct
{                            // El tipo lista con un puntero
  tPosicion Primero, Ultimo; // al primero y ultimo nodos.
} tLista;

/// @brief Crea una lista vacía.
/// @return Lista vacía.
extern tLista *CrearLista();

/// @brief Inserta e en la posición p+1 de la lista l. Los elementos que estan a partir de la posición p+1 se desplazan una posición.
/// @param l Lista
/// @param e Elemento
/// @param p Posición
/// @return Lista con el elemento e en la posición p+1.
extern tLista Insertar(tLista l, tElemento e, tPosicion p);
/// @brief Borra el elemento de la posición p de la lista l.
/// @param l Lista
/// @param p Posición
/// @return Lista sin el elemento de la posición p.
extern tLista Borrar(tLista l, tPosicion p);
/// @brief Devuelve el elemento de la posicion p de la lista l.
/// @param p Posición.
/// @return Elemento en la posición p.
extern tElemento Recuperar(tPosicion p);

/// @brief Devuelve un puntero al último elemento de la lista.
/// @param l Lista.
/// @return Puntero al último elemento de la lista.
extern tPosicion ConseguirPosicionFin(tLista l);
/// @brief Devuelve un puntero al último elemento de la lista.
/// @param l Lista.
/// @return Puntero al primer elemento de la lista.
extern tPosicion ConseguirPosicionPrincipio(tLista l);
/// @brief Devuelve un puntero al elemento de la lista que sigue al que se le pasa como parametro.
/// @param p Posición.
/// @return Puntero al elemento de la lista que sigue al que se le pasa como parámetro.
extern tPosicion ConseguirPosicionSiguiente(tPosicion p);

/// @brief Comprueba si la lista está vacía.
/// @param l Lista
/// @return 1 si la lista está vacía, 0 en caso contrario.
extern int EsListaVacia(tLista l);
/// @brief Imprime los elementos de la Lista.
/// @param l Lista.
extern void VisualizarLista(tLista p);
/// @brief Calcula el número de elementos de la lista.
/// @param l Lista.
/// @return Número de elementos.
extern int CalcularNumeroElementosLista(tLista p);
