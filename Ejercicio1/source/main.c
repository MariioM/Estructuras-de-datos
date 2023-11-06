/* LIBRERÍAS ESTÁNDAR*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
//#include "tools/Gen.h"
#include "tools/Pila.h"
#include "tools/Err.h"
#include "tools/Cola.h"
#include "tools/Lista.h"


#define OPCION_UNO 1
#define OPCION_DOS 2
#define OPCION_TRES 3
#define OPCION_CUATRO 4
#define OPCION_CINCO 5
#define OPCION_SEIS 6
#define OPCION_SIETE 7
#define OPCION_OCHO 8


#define NOM_FICHERO "fich02Copia.csv"


int LeeFichero (char *NomFichero, tElemento *p, int *Num);
void Pausar(void);
void ConstruirPilas(tPila *pPila1, tPila *pPila2, tElemento *pElemento);
tPila *ConstruirPila(tPila *pPila1, tElemento *pElemento);
tCola ConstruirCola(tCola *pCola1,  tElemento *pElemento);
tPila * ExtraerPilaOrden(tPila *pPila, char Letra);
tCola ExtraerColaOrden(tCola Cola, char Letra);

main (void)
{

  tPila *pPila1, *pPila2;

  pPila1=NULL;
  pPila2=NULL;
  char Cadena[MAX_CAR*3+2];
  char *cpToken;
  int FlgSalir;
  int TipoOperacion;
  int Num1, Num2,i;
  int Res, Num;
  tElemento e;
  tElemento *pElemento;
  int LongI, LatI;
  char Nombre[MAX_CAR];
  char Apellido[MAX_CAR];
  char Password[MAX_CAR];
  int k;
  tCola Cola1;
  tCola Cola2;
  int j;
  int Pos;
  tElemento Elemento;
  tLista pLista;
  tPosicion pPos;
  char Let;


/* A rellenar por el alumno */


  }





int LeeFichero (char *NomFichero, tElemento *p, int *Num)
{
   
/* A rellenar por el alumno */


}


void Pausar(void)
{
  /* A rellenar por el alumno*/
}

void ConstruirPilas(tPila *pPila1, tPila *pPila2, tElemento *pElemento)
{

 /*A rellenar por el alumno*/


 }

 
tPila *ConstruirPila(tPila *pPila1, tElemento *pElemento)
{

 /* A rellenar por el alumno */


}


tCola ConstruirCola(tCola *pCola1,  tElemento *pElemento)
{
/* A rellenar por el alumno */



 }


tPila * ExtraerPilaOrden(tPila *pPila, char Letra)
{

/* A rellenar por el alumno */

}


tCola ExtraerColaOrden(tCola Cola, char Letra)
{
/* A rellenar por el alumno */



}





