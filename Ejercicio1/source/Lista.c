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
    nuevo->Sig = l.Primero;

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
    /*if (EsListaVacia(l)) // Lista vacia
    {
        printf("Error al eliminar: Lista vacia.\n");
    }
    else if (p <= 0) // Borrar en la posición 0 o una negativa
    {
        tNodo *aux = l.Primero;
        l.Primero = l.Primero->Sig;

        if (l.Primero == NULL) // La lista sólo tenía un elemento
        {
            l.Ultimo = NULL;
        }

        free(aux);
    }
    else if (p >= CalcularNumeroElementosLista(l)) // Borrar en la posición final o una mayor.
    {
        tNodo *aux = l.Primero;

        if (l.Primero == l.Ultimo) // La lista sólo tenía un elemento
        {
            l.Primero = NULL;
            l.Ultimo = NULL;
            free(aux);
        }
        else
        {
            while (aux->Sig != l.Ultimo)
            {
                aux = aux->Sig;
            }

            // aux = penúltimo elemento
            free(l.Ultimo);
            l.Ultimo = aux;
            l.Ultimo->Sig = NULL;
        }
    }
    else // Borrar dentro de los límites
    {
        // Apunta al primer elemento
        tPosicion aux = l.Primero;
        tPosicion borrar;

        // Mover aux a la posición anterior a la que quiero borrar
        int i = 0;
        for (i = 0; i < p - 1; i++)
        {
            aux = aux->Sig;
        }

        // Borrar el nodo
        borrar = aux->Sig;
        aux->Sig = borrar->Sig;
        free(borrar);
    }
    */
}

tElemento Recuperar(tPosicion p)
{
    /* A rellenar por el alumno */
}

int EsListaVacia(tLista l)
{
    return (l.Primero == NULL);
}

tPosicion ConseguirPosicionFin(tLista l)
{
    return l.Ultimo;
}

tPosicion ConseguirPosicionPrincipio(tLista l)
{
    return l.Primero;
}

tPosicion ConseguirPosicionSiguiente(tPosicion p)
{
    /* A rellenar por el alumno */
}

void VisualizarLista(tLista l)
{
    tPosicion aux = l.Primero;

    printf("Contenido lista: ");
    while (aux != NULL)
    {
        printf("%d -> ", aux->Elem);
        aux = aux->Sig;
    }
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
