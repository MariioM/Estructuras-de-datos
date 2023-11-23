
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "Cola.h"
#include "Err.h"

/*
 *
 * Función: CrearCola
 *      Crea una cola vacía.
 * Parámetro de entrada/salida:
 *        No tiene.
 * Parámetro de salida:  Devuelve una cola vacía.
 *
 */

tCola CrearCola()
{
    tCola cola;
    cola.pCab = NULL;
    cola.pCol = NULL;
    return cola;
}

void Encolar(tCola *p, tElemento E)
{
  // Crear un nodo
    tNodo *nuevo;
    nuevo = (tNodo *) malloc (sizeof(tNodo));

    // Asignarle los valores
    nuevo->Elem = E;
    nuevo->Sig = NULL;

    // recolocar punteros
    if (EsColaVacia(p)) {   // Si est� vac�a, es apuntar con primero y �ltimo a ese nuevo nodo
        p->pCab = nuevo;
        p->pCol = nuevo;
    }
    else {  // si no est� vac�a, se inserta al final.
        p->pCab->Sig = nuevo;
        p->pCol = nuevo;
    }
}

void Desencolar(tCola *p, tElemento *E)
{
  tNodo *aux;

    if (EsColaVacia(p)) {
        printf("ERROR al desencolar. La cola est� vac�a. \n");
    }
    else {
        aux = p->pCab;
        p->pCab = aux->Sig; //C->primero = C->primero->sig;

        if (p->pCab == NULL) { //la cola solo tenia un nodo.
            p->pCol = NULL;
        }
        free(aux);
    }
}

int EsColaVacia(tCola *p)
{
  return (p->pCab == NULL);
}

int VerCola(tCola p)
{

  /* A rellenar por el alumno */
}

int CalcularNumElementosC(tCola *p)
{

  /* A rellenar por el alumno */
}
