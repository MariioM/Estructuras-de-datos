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
  // Creamos la cola dinámica
  tCola *cola = (tCola *)malloc(sizeof(tCola));
  cola->pCab = NULL;
  cola->pCol = NULL;
  return *cola;
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
  if (EsColaVacia(c) == 0)
  { // Si está vacía, es apuntar con primero y último a ese nuevo nodo
    c->pCab = nuevo;
    c->pCol = nuevo;
  }
  else
  { // si no está vacía, se inserta al final.
    c->pCol->Sig = nuevo;
    c->pCol = nuevo;
  }
}

void Desencolar(tCola *c)
{
  tNodo *aux;

  if (EsColaVacia(c) == 0)
  {
    printf("ERROR al desencolar. La cola est� vac�a. \n");
  }
  else
  {
    // El proceso de desencolar se basa en "eliminar" la cabeza haciendo que ésta apunte al siguiente elemento.
    aux = c->pCab;
    c->pCab = aux->Sig;

    if (c->pCab == NULL)
    {
      // En el caso de que la cabeza sea nula, automáticamente la ultima posición será nula también.
      c->pCol = NULL;
    }
  }
}

int EsColaVacia(tCola *c)
{
   if (c->pCab == NULL)
   {
      return 0;
   }
   else
   {
      return 1;
   }
}

void VisualizarCola(tCola c)
{
  // Se treata de un simple bucle que recorre toda la cola y muestra mediante un printf todos los elementos.
  tNodo *reco = c.pCab;
  while (reco != NULL)
  {
    printf("%s - %s - %s", reco->Elem.Nombre, reco->Elem.Apellido, reco->Elem.Password);
    reco = reco->Sig;
  }
  printf("\n");
}

int CalcularNumElementosC(tCola *c)
{
  // Esta función devolverá el número de elementos de la cola que se le pase por parámetro.
  int num_elementos = 0;
  // Inicializamos el nodo a la cabeza de la cola
  tNodo *nodos = c->pCab;
  while (nodos != NULL)
  {
    // Después de incrementar el número, haremos que el puntero nodo apunte al siguiente elemento en la cola.
    num_elementos++;
    nodos = nodos->Sig;
  }
  return num_elementos;
}

tCola DestruirCola(tCola *c){
  //Inicializamos el nodo a la cabeza de la cola
  tNodo *nodo = c->pCab;
  while(nodo != NULL){
    //Después de incrementar el número, haremos que el puntero nodo apunte al siguiente elemento en la cola.
    Desencolar(c);
    nodo = c->pCab;
  }
  return *c;
}



