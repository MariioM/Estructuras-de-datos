
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "Lista.h"
#include "Err.h"


tLista CrearLista() {

 /* A rellenar por el alumno */

}

/*
 *
 * Función: Insertar
 *
 * inserta e en la posición p+1 de la lista l. Los elementos que estan a partir de la posición p+1
 * se desplazan una posición.
 * Parámetro de entrada:
 * Elemento, Posicion
 * Parámetro de entrada/salida:
 *        Lista.
 * Parámetro de salida:  Lista.
 *
 */

tLista Insertar(tLista l, tElemento e, tPosicion p) {

/* A rellenar por el alumno */

}
/*
 *
 * Función: Borrar
 *
 * Borra el elemento de la posición p de la lista l.
 * Parámetro de entrada:
 * Elemento, Posicion
 * Parámetro de entrada/salida:
 *        Lista.
 * Parámetro de salida:  Lista.
 *
 */


tLista Borrar(tLista l, tPosicion p) {

/* A rellenar por el alumno */

}


/*
 *
 * Función: Recuperar
 *
 * Devuelve el elemento de la posicion p de la lista l.
 * Parámetro de entrada:
 *  Posicion
 * Parámetro de entrada/salida:
 *        Lista.
 * Parámetro de salida:  Elemento.
 *
 */

tElemento Recuperar(tPosicion p) {
/* A rellenar por el alumno */

}

/*
 *
 * Función: EsListaVacia
 *
 * Devuelve el elemento de la posicion p de la lista l.
 * Parámetro de entrada:
 *  Lista
 * Parámetro de entrada/salida:
 *        Lista.
 * Parámetro de salida: TRUE/FALSE.
 *
 */
int EsListaVacia (tLista l) {
/* A rellenar por el alumno */
}
/*
 *
 * Función: ConseguirPosicionFin
 *
 * Devuelve un puntero al último elemento de la lista.
 * Parámetro de entrada:
 *  Lista
 * Parámetro de entrada/salida:
 *  No tiene.
 * Parámetro de salida:  Puntero al ultimo elemento de la lista
 *
 */
tPosicion ConseguirPosicionFin(tLista l) {
/* A rellenar por el alumno */

}

/*
 *
 * Función: ConseguirPosicionPrincipio
 *
 * Devuelve un puntero al último elemento de la lista.
 * Parámetro de entrada:
 *  Lista
 * Parámetro de entrada/salida:
 *  No tiene.
 * Parámetro de salida:  Puntero al primer elemento de la lista
 *
 */
tPosicion ConseguirPosicionPrincipio(tLista l) {
/* A rellenar por el alumno */

}
/*
 *
 * Función: ConseguirPosicionSiguiente
 *
 * Devuelve un puntero al elemento de la lista que sigue al que se le pasa como parametro.
 * Parámetro de entrada:
 *  Lista
 *   Elemento de la Lista
 * Parámetro de entrada/salida:
 *  No tiene.
 * Parámetro de salida:  puntero al elemento de la lista que sigue al que se le pasa como parametro.
 *
 */
tPosicion ConseguirPosicionSiguiente(tPosicion p) {
/* A rellenar por el alumno */

}

/*
 *
 * Función: VisualizarLista
 *
 * Imprime los elementos de la Lista
 * Parámetro de entrada:
 *
 *  Lista
 * Parámetro de entrada/salida:
 *  No tiene.
 * Parámetro de salida:  No tiene.
 *
 */
void VisualizarLista(tLista p) {
/* A rellenar por el alumno */



}

/*
 *
 * Función: VisualizarLista
 *
 * Imprime los elementos de la Lista
 * Parámetro de entrada:
 *
 *  Lista
 * Parámetro de entrada/salida:
 *  No tiene.
 * Parámetro de salida:  Número de elementos.
 *
 */
int CalcularNumeroElementosLista(tLista p) {

/* A rellenar por el alumno */

}
