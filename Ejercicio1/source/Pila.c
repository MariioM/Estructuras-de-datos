/* LIBRERÍAS ESTÁNDAR*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "Pila.h"
#include "Err.h"

extern tPila *Apilar(tPila *p, tElemento Ele)
{
   tNodo *nodo = CrearNodo(Ele);
   nodo->Sig = p->cima;
   p->cima = nodo;
}

void VisualizarPila(tPila *p)
{
   printf("Visualiza");
}

int CalcularNumElementos(tPila *p)
{
   int longitud = 0;
   tNodo *actual = p->cima;

   while (actual != NULL)
   {
      longitud++;
      actual = actual->Sig;
   }
   return longitud;
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
   if (p->cima == NULL)
   {
      return 0;
   }
   else
   {
      return 1;
   }
}

void EliminarParesPila(tPila **pPila)
{
   /* A rellenar por el alumno */
}