/* LIBRERÍAS ESTÁNDAR*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "Pila.h"
#include "Err.h"

void *Apilar(tPila *p, tElemento Ele)
{
   tNodo *nodo = CrearNodo(Ele);
   nodo->Sig = p->cima;
   p->cima = nodo;
}

tPila *CrearPila()
{
   tPila *pila = (tPila *)malloc(sizeof(tPila));
   pila->cima = NULL;
   return pila;
}

void VisualizarPila(tPila *pila, int num_usuarios)
{
   tNodo *nodo = pila->cima;
   while (nodo != NULL)
   {
      printf("%s - %s - %s\n", nodo->Elem.Nombre, nodo->Elem.Apellido, nodo->Elem.Password);
      nodo = nodo->Sig;
   }
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

void *Desapilar(tPila *p)
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
