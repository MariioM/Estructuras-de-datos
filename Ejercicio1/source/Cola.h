/* LIBRERÍAS ESTÁNDAR*/

#ifndef GENEST
#include "Gen.h"
#define GENEST 1
#endif

typedef struct
{
  tNodo *pCab, *pCol; /* Punteros a la cabeza y la cola. */
} tCola;

extern int Encolar(tCola *p, tElemento E);
extern int Desencolar(tCola *p, tElemento *E);
extern int EsColaVacia(tCola *p);
extern int VerCola(tCola p);
extern int CalcularNumElementosC(tCola *p);
extern tCola CrearCola();
