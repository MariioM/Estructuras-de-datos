/* LIBRER�AS EST�NDAR*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "Pila.h"
#include "Err.h"

tPila *Apilar(tPila *p, tElemento Ele)
{
   tNodo *nodo = CrearNodo(Ele);
   nodo->Sig = p->cima;
   p->cima = nodo;
}

void VisualizarPila(tPila *p)
{
   /* A rellenar por el alumno */
}

int CalcularNumElementos(tPila *p)
{
}

tPila *Desapilar(tPila *p, tElemento *e)
{
   if (p != NULL)
   {
      tNodo *eliminar = p->cima;
      p->cima = p->cima->Sig;
      DestruirNodo(eliminar);
   }
}

int EsPilaVacia(tPila *p)
{
   return p->cima == NULL;
}

void EliminarParesPila(tPila **pPila)
{
   /* A rellenar por el alumno */
}
