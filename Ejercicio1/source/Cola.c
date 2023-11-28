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
  if (EsColaVacia(c))
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

  if (EsColaVacia(c))
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
  return (c->pCab == NULL);
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
