/* LIBRERÍAS ESTÁNDAR*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "Cola.h"
#include "Err.h"

tCola CrearCola()
{
  tCola cola;
  cola.pCab = NULL;
  cola.pCol = NULL;
  return cola;
}

void Encolar(tCola *c, tElemento E)
{
  // Crear un nodo
  tNodo *nuevo;
  nuevo = (tNodo *)malloc(sizeof(tNodo));

  // Asignarle los valores
  nuevo->Elem = E;
  nuevo->Sig = NULL;

  // recolocar punteros
  if (EsColaVacia(c))
  { // Si está vacía, es apuntar con primero y último a ese nuevo nodo
    c->pCab = nuevo;
    c->pCol = nuevo;
  }
  else
  { // si no está vacía, se inserta al final.
    c->pCab->Sig = nuevo;
    c->pCol = nuevo;
  }
}

void Desencolar(tCola *c, tElemento *E)
{
  tNodo *aux;

  if (EsColaVacia(c))
  {
    printf("ERROR al desencolar. La cola est� vac�a. \n");
  }
  else
  {
    aux = c->pCab;
    c->pCab = aux->Sig; // C->primero = C->primero->sig;

    if (c->pCab == NULL)
    { // la cola solo tenia un nodo.
      c->pCol = NULL;
    }
    free(aux);
  }
}

int EsColaVacia(tCola *c)
{
  return (c->pCab == NULL);
}

int VerCola(tCola c)
{

  /* A rellenar por el alumno */
}

int CalcularNumElementosC(tCola *c)
{

  /* A rellenar por el alumno */
}
