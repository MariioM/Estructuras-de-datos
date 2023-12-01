/* LIBRERÍAS ESTÁNDAR*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/* VARIABLES DEFINIDAS */
#define MAX_CAR 25

/* INICIALIZACION DE TADs */

/// @brief Tipo de dato abstracto elemento
typedef struct
{
  char Ciudad[MAX_CAR]; // Nombre de la ciudad
} tElemento;

/// @brief Tipo de dato abstracto nodo
typedef struct _pnodo
{
  tElemento Elem;     // Elemento que contiene el nodo
  struct _pnodo *Sig; // Puntero al siguiente nodo
} tNodo;

/// @brief Tipo de dato abstracto pila
typedef struct pila
{
  tNodo *cima; // Puntero al nodo de la cima
} tPila;

/// @brief Tipo de dato auxiliar que contiene el nombre de la ciudad y el número de repeticiones
typedef struct
{
  char Ciudad[MAX_CAR]; // Nombre de la ciudad
  int Rep;              // Número de repeticiones
} tRegAux;

/* INICIALIZACIÓN DE FUNCIONES. */

/// @brief Inicializa una pila a NULL
/// @return Pila inicializada a NULL
tPila *CrearPunt();
/// @brief Crea pila vacia
/// @return Pila vacía
tPila *CrearPila();
/// @brief Crea un nodo
/// @param element Elemento que se va a guardar en el nodo
/// @return Puntero al nodo
tNodo *CrearNodo(tElemento element);
/// @brief Destruye un nodo
/// @param nodo Puntero al nodo
/// @return Puntero al nodo
tNodo *DestruirNodo(tNodo *nodo);
/// @brief  Inserta un elemento en la cima de la pila.
/// @param p Pila
/// @param Ele Elemento
/// @return Pila con el elemento insertado en la cima.
void *Apilar(tPila *p, tElemento Ele);
/// @brief Lee el fichero y guarda los datos en un puntero de tipo tElemento
/// @param NomFichero Puntero al fichero que contiene los datos
/// @param ciudades Puntero al elemento que controla los datos de las ciudades
/// @param num_usuarios Entero que representa el número de ciudades
/// @param pPila Puntero a la pila donde se guardarán los datos
/// @return Devuelve un puntero a la pila con los datos del fichero
tPila *LeeFichero(FILE *NomFichero, tElemento *ciudades, int Num, tPila *pPila);
/// @brief Imprime los elementos de la pila
/// @param p Pila
void VisualizarPila(tPila *p);
/// @brief Elimina el elemento de la cima de la pila
/// @param p Pila
/// @param e Elemento
/// @return Pila sin el elemento de la cima
void *Desapilar(tPila *p);
/// @brief Elimina los elementos repetidos de la pila (deja el más cercano a la cima)
/// @param pPila1 Puntero a la pila
/// @param Num1 Número de ciudades
/// @param pAux Puntero a la pila auxiliar
/// @return
tPila *EliminarRepeticiones(tPila *pPila1, int Num1, tPila *pAux);
/// @brief Calcula el número total de ciudades que contiene el fichero
/// @param NomFichero  Puntero al fichero que contiene los datos
/// @param num_ciudades Puntero al número de ciudades
void CalculaCiudades(FILE *NomFichero, int *num_ciudades);
/// @brief Menú que permite al usuario navegar entre las diferentes opciones.
/// @return Entero que representa la opción elegida por el usuario.
int Menu(char texto[], int limite_inferior, int limite_superior);

int main(void)
{
  // Texto menú
  char textoMenuPrincipal[] = "\n  Elija que quiere hacer: \n\t 1) Construir pilas a partir de los ficheros\n\t 2) Visualizar pilas\n\t 3) Buscar y eliminar reps \n\t 4) Salir \n=> ";
  // Pilas
  tPila *pPila1;
  tPila *pPila2;
  tPila *pAux, *pAux2;
  // Elementos
  tElemento *pciudades;
  // Ciudades
  int num_ciudades;
  FILE *cities1;
  FILE *cities2;

  do
  {
    switch (Menu(textoMenuPrincipal, 1, 4))
    {
    case 1: // 1) Construir pilas a partir de del los ficheros
      cities1 = fopen("./fichadic21.csv", "r");
      CalculaCiudades(cities1, &num_ciudades);
      printf("\nCaso 1\n");
      pPila1 = CrearPila();
      pPila2 = CrearPila();
      pAux = CrearPila();
      pAux2 = CrearPila();
      pciudades = (tElemento *)malloc(MAX_CAR * sizeof(tElemento));
      cities1 = fopen("./fichadic21.csv", "r");
      pPila1 = LeeFichero(cities1, pciudades, num_ciudades, pPila1);
      cities1 = fopen("./fichadic21.csv", "r");
      pAux = LeeFichero(cities1, pciudades, num_ciudades, pAux);
      cities2 = fopen("./fichadic22.csv", "r");
      pPila2 = LeeFichero(cities2, pciudades, num_ciudades, pPila2);
      cities2 = fopen("./fichadic22.csv", "r");
      pAux2 = LeeFichero(cities2, pciudades, num_ciudades, pAux2);
      printf("\n");
      break;
    case 2: // 2) Visualizar pilas
      printf("\nCaso 2\n\nPila 1\n------\n");
      VisualizarPila(pPila1);
      printf("\n\nPila 2\n------\n");
      VisualizarPila(pPila2);
      break;

    case 3: // 3) Buscar y eliminar reps
      printf("\nCaso 3\n\nRepeticiones pila 1\n-------------------\n");
      pPila1 = EliminarRepeticiones(pPila1, num_ciudades, pAux);
      printf("\nRepeticiones pila 2\n-------------------\n");
      pPila2 = EliminarRepeticiones(pPila2, num_ciudades, pAux2);
      break;
    case 4: // 4) Salir

      printf("Saliendo...");
      exit(1);
      break;
    default: // 6) Salir del programa.

      break;
    }
  } while (1);
}
void CalculaCiudades(FILE *NomFichero, int *num_ciudades)
{
  // Se define una variable de control
  char control;
  *num_ciudades = 1;
  // Se abre el fichero donde se encuentran los datos
  // Control de apertura fichero
  if (NomFichero == NULL)
  {
    *num_ciudades = 0;
    printf("Error al abrir el fichero.");
    fclose(NomFichero);
  }
  // Se lee el numero de filas del fichero
  while (control != EOF)
  {
    control = fgetc(NomFichero);
    if (control == '\n')
    {
      *num_ciudades += 1;
    }
  }
  fclose(NomFichero);
}
tPila *CrearPunt()
{
  return (NULL); /* Devolvemos un valor NULL para inicializar */
}

tPila *CrearPila()
{
  tPila *pila = (tPila *)malloc(sizeof(tPila));
  pila->cima = NULL;
  return pila;
}

void *Apilar(tPila *p, tElemento Ele)
{

  tNodo *nodo = CrearNodo(Ele);
  nodo->Sig = p->cima;
  p->cima = nodo; /* Devolvemos un puntero al nuevo tope. */
}
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
tPila *LeeFichero(FILE *NomFichero, tElemento *ciudades, int Num, tPila *pPila)
{

  // Se abre el fichero
  // Control de apertura fichero
  if (NomFichero == NULL)
  {
    printf("Error al abrir el fichero.");
  }
  int i = 0;
  while (i < Num)
  {
    fscanf(NomFichero, "%s", ciudades->Ciudad);
    Apilar(pPila, *ciudades);
    ciudades++;
    i++;
  }
  ciudades -= Num;
  fclose(NomFichero); // Cierra el archivo después de leer los datos

  printf("\nExito al cargar las pilas.");
  return pPila; // Devuelve 0 para indicar éxito
}

void VisualizarPila(tPila *pPila)
{
  tNodo *nodo = pPila->cima;
  while (nodo != NULL)
  {
    printf("%s\n", nodo->Elem.Ciudad);
    nodo = nodo->Sig;
  }
  printf("\n");
}

void *Desapilar(tPila *p)
{
  if (p != NULL)
  {
    tNodo *eliminar = p->cima;
    p->cima = p->cima->Sig;
  }
}

tPila *EliminarRepeticiones(tPila *pPila1, int Num1, tPila *pAux)
{
  tPila *pAux_repes = CrearPila();
  tPila *pSolucion = CrearPila();
  tPila *pReconstruir = CrearPila();
  tNodo *candidato;
  tNodo *posible_repe;
  tNodo *repetido;
  int contador;
  int control = 0;
  while (Num1 > 0) // Este bucle simplemente recorrerá ciudad por ciudad, buscando repeticiones.
  {
    control = 0;
    contador = 0;
    candidato = pPila1->cima; // Asignamos repe a la cima, sera la que usaremos para comparar con el resto
    Desapilar(pPila1);        // Nueva cima, siguiente elemento
    Desapilar(pAux);          // Nueva cima, siguiente elemento
    posible_repe = pPila1->cima;
    while (posible_repe->Elem.Ciudad != NULL) // Este bucle será el encargado de coger una ciudad y compararla con todas las ciudades que tiene por debajo.
    {
      if (strcmp(candidato->Elem.Ciudad, posible_repe->Elem.Ciudad) == 0) // Comparo para recoger en una pila auxiliar aquellas ciudades repetidas
      {
        Apilar(pAux_repes, posible_repe->Elem);
        control = 1;
      }

      Desapilar(pAux);
      Apilar(pReconstruir, posible_repe->Elem);
      contador++;
      posible_repe = pAux->cima;
    }
    if (control == 0)
    {
      Apilar(pSolucion, candidato->Elem);
    }
    for (int i = 0; i < contador; i++) // Este bucle es un bucle para que la pila auxiliar vuelva a la posición correcta, y que no se quede vacía.
    {
      Apilar(pAux, pReconstruir->cima->Elem);
      Desapilar(pReconstruir);
    }
    Num1--;
  }
  VisualizarPila(pAux_repes);
  return pSolucion;
}

int Menu(char texto[], int limite_inferior, int limite_superior)
{
  int opcion;
  do
  {
    printf("%s", texto);
    scanf("%d", &opcion);
  } while (opcion < limite_inferior || opcion > limite_superior);
}
