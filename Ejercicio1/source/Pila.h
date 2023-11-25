/* LIBRERÍAS ESTÁNDAR*/

#ifndef GENEST
#include "Gen.h"
#define GENEST 1
#endif

typedef struct pila
{
  tNodo *cima;
} tPila;

/// @brief  Inserta un elemento en la cima de la pila.
/// @param p Pila
/// @param Ele Elemento
/// @return Pila con el elemento insertado en la cima.
extern tPila *Apilar(tPila *p, tElemento Ele);
/// @brief Imprime los elementos de la pila.
/// @param p Pila.
extern void VisualizarPila(tPila *p);
/// @brief Calcula el número de elementos de la pila.
/// @param p Pila.
/// @return Número de elementos.
extern int CalcularNumElementos(tPila *p);
/// @brief Elimina el elemento de la cima de la pila.
/// @param p Pila
/// @param e Elemento
/// @return Pila sin el elemento de la cima.
extern tPila *Desapilar(tPila *p, tElemento *e);
/// @brief
/// @param pPila Puntero a la pila
extern void IntercambiarParesImparesPila(tPila **pPila);
/// @brief
/// @param pPila Puntero a la pila
extern void EliminarParesPila(tPila **pPila);
/// @brief Crea pila vacia
/// @return Pila vacía
extern tPila *CrearPila();
