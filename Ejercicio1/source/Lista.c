/* LIBRERÍAS ESTÁNDAR*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "Lista.h"
#include "Err.h"

tLista *CrearLista()
{
    tLista *lista = (tLista *)malloc(sizeof(tLista));
    lista->Primero = NULL;
    lista->Ultimo = NULL;
    return lista;
}

tLista Insertar(tLista l, tElemento e, tPosicion p)
{
    // Crear un nuevo nodo
    tNodo *nuevo;
    nuevo = (tNodo *)malloc(sizeof(tNodo));

    // Asignar el elemento al nuevo nodo
    nuevo->Elem = e;
    nuevo->Sig = NULL;

    // recolocar punteros
    if (EsListaVacia(l))
    {
        l.Primero = nuevo;
        l.Ultimo = nuevo;
    }
    else
    {
        l.Ultimo->Sig = nuevo;
        l.Ultimo = nuevo;
    }

    return l;
}

tLista Borrar(tLista l, tPosicion p)
{
    /* */
}

tElemento Recuperar(tPosicion p)
{
    return p->Elem;
}

tPosicion ConseguirPosicionFin(tLista l)
{
    return l.Ultimo;
}

tPosicion ConseguirPosicionPrincipio(tLista l)
{
    return l.Primero;
}

tPosicion ConseguirPosicionSiguiente(tPosicion l)
{
    return l->Sig;
}

int EsListaVacia(tLista l)
{
    return (l.Primero == NULL);
}

void VisualizarLista(tLista *l)
{
    tPosicion aux = l->Primero;

    while (aux != NULL)
    {
        printf("%s - %s - %s", aux->Elem.Nombre, aux->Elem.Apellido, aux->Elem.Password);
        aux = aux->Sig;
    }

    printf("\n");
}

int CalcularNumeroElementosLista(tLista l)
{
    int numElementos = 0;
    tPosicion aux = l.Primero;

    printf("Contenido lista: ");
    while (aux != NULL)
    {
        numElementos++;
        aux = aux->Sig;
    }
}
