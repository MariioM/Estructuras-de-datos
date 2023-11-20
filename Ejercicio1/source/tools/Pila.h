/* LIBRER�AS EST�NDAR*/

#ifndef GENEST
#include "Gen.h"
#define GENEST 1
#endif

typedef struct pila
{
  tNodo *cima;
} tPila;

extern tPila *Apilar(tPila *p, tElemento Ele);
extern void VisualizarPila(tPila *p);
extern int CalcularNumElementos(tPila *p);
extern tPila *Desapilar(tPila *p, tElemento *e);
extern void IntercambiarParesImparesPila(tPila **pPila);
extern void EliminarParesPila(tPila **pPila);
