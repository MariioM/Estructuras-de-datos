/* LIBRERÍAS ESTÁNDAR*/

#ifndef GENEST
#include "Gen.h"
#define GENEST 1
#endif

typedef struct
{
  tNodo *pCab, *pCol; /* Punteros a la cabeza y la cola. */
} tCola;

/// @brief Crear una cola vacía.
/// @return Cola vacía.
extern tCola CrearCola();
/// @brief Inserta un elemento el final de la cola.
/// @param c Puntero a la cola
/// @param E Elemento
extern void Encolar(tCola *c, tElemento E);
/// @brief Elimina el elemento del principio de la cola.
/// @param c Puntero a la cola
/// @param E Elemento
extern void Desencolar(tCola *c);
/// @brief Comprueba si la cola está vacía.
/// @param c Puntero a la cola
/// @return NULL si la cola está vacía.
extern int EsColaVacia(tCola *c);
/// @brief Imprime los elementos de la cola.
/// @param c Puntero a la cola
/// @return
extern void VerCola(tCola c);
/// @brief Calcula el número de elementos de la cola.
/// @param c Puntero a la cola
/// @return Número de elementos.
extern int CalcularNumElementosC(tCola *c);
extern tCola DestruirCola(tCola *c);
