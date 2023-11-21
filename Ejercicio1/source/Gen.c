/* LIBRERÍAS ESTÁNDAR*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "Gen.h"

tNodo *CrearNodo(tElemento element)
{
    tNodo *nodo = (tNodo *)malloc(sizeof(tNodo));
    nodo->Elem = element;
    nodo->Sig = NULL;
    return nodo;
}

tNodo *DestruirNodo(tNodo *nodo)
{
    nodo->Sig = NULL;
    free(nodo);
}
