/* LIBRERÍAS ESTÁNDAR*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "Pila.h"
#include "Err.h"
#include "Cola.h"
#include "Lista.h"

#define OPCION_UNO 1
#define OPCION_DOS 2
#define OPCION_TRES 3
#define OPCION_CUATRO 4
#define OPCION_CINCO 5
#define OPCION_SEIS 6
#define OPCION_SIETE 7
#define OPCION_OCHO 8

#define NOM_FICHERO "fich02.csv"
#define NUM_CHAR_FICH 50
#define N 50

void CalculaUsuarios(FILE *pf_usuarios, int *num_usuarios);
int LeeFichero(FILE *pf_usuarios, tElemento *usuario, int num_usuarios, char lineaDatos[]);
void Pausar(void);
void ConstruirPilas(tPila *pPila1, tPila *pPila2, tElemento *pElemento);
tPila *ConstruirPila(tPila *pPila1, tElemento *pElemento);
tCola ConstruirCola(tCola *pCola1, tElemento *pElemento, int num_usuario);
tPila *ExtraerPilaOrden(tPila *pPila, char Letra);
tCola ExtraerColaOrden(tCola Cola, char Letra);

int main(void)
{
    // Pilas
    tPila *pPila1, *pPila2;
    pPila1 = NULL;
    pPila2 = NULL;

    // Colas
    tCola Cola1;
    tCola Cola2;

    // Listas
    tLista pLista;

    // Fichero
    FILE *pf_usuarios;
    int num_usuarios;

    char Cadena[MAX_CAR * 3 + 2];
    char *cpToken;
    int FlgSalir;
    int TipoOperacion;
    int Num1, Num2, i;
    int Res, Num;
    tElemento e;
    tElemento *pElemento;
    int LongI, LatI;
    char Nombre[MAX_CAR];
    char Apellido[MAX_CAR];
    char Password[MAX_CAR];
    int k;
    int j;
    int Pos;
    tElemento Elemento;
    tPosicion pPos;
    char Let_cola;
    char name[N];

    /* Lectura del fichero */
    // Se calcula el número de usuarios existentes
    CalculaUsuarios(pf_usuarios, &num_usuarios);
    // Se le asigna memoria dinámica al puntero que apunta a los usuarios
    pElemento = (tElemento *)malloc(num_usuarios * sizeof(tElemento));
    // Se lee y guarda el fichero
    LeeFichero(pf_usuarios, pElemento, num_usuarios, Cadena);
    ConstruirPila(pPila1, pElemento);
    Cola1 = ConstruirCola(&Cola1, pElemento, num_usuarios);
    printf("Introduzca una letra: ");
    scanf("%c", Let_cola);

    scanf("%d");
    return 0;
}

void CalculaUsuarios(FILE *pf_usuarios, int *num_usuarios)
{
    // Se define una variable de control
    char control;
    *num_usuarios = 1;
    // Se abre el fichero donde se encuentran los datos
    pf_usuarios = fopen("../data/fich02.csv", "r");
    // Control de apertura fichero
    if (pf_usuarios == NULL)
    {
        *num_usuarios = 0;
        printf("Error al abrir el fichero.");
        fclose(pf_usuarios);
    }
    // Se lee el numero de filas del fichero
    while (control != EOF)
    {
        control = fgetc(pf_usuarios);
        if (control == '\n')
        {
            *num_usuarios += 1;
        }
    }
    fclose(pf_usuarios);
}

int LeeFichero(FILE *pf_usuarios, tElemento *usuario, int num_usuarios, char lineaDatos[])
{
    // Se abre el fichero
    pf_usuarios = fopen("../data/fich02.csv", "r");
    // Control de apertura fichero
    if (pf_usuarios == NULL)
    {
        printf("Error al abrir el fichero.");
        return -1; // Devuelve un valor para indicar error
    }
    for (int i = 0; i < num_usuarios; i++)
    {
        fscanf(pf_usuarios, "%[^;];%[^;];%s", usuario->Nombre, usuario->Apellido, usuario->Password);
        usuario++;
    }
    usuario -= num_usuarios;
    fclose(pf_usuarios); // Cierra el archivo después de leer los datos

    // Imprime los datos almacenados
    printf("Datos almacenados:\n");
    for (int i = 0; i < num_usuarios; i++)
    {
        printf("Nombre: %s\nApellido: %s\nPassword: %s\n", usuario->Nombre, usuario->Apellido, usuario->Password);
        usuario++;
    }
    return 0; // Devuelve 0 para indicar éxito
}

void Pausar(void)
{
    /* A rellenar por el alumno*/
}

void ConstruirPilas(tPila *pPila1, tPila *pPila2, tElemento *pElemento)
{
}

tPila *ConstruirPila(tPila *pPila1, tElemento *pElemento)
{
    pPila1 = CrearPila();
    pElemento = (tElemento *)malloc(sizeof(tElemento));
    while (pElemento != NULL)
    {
        Apilar(pPila1, *pElemento);
        pElemento++;
    }
}

tCola ConstruirCola(tCola *pCola1, tElemento *pElemento, int num_usuario)
{
    *pCola1 = CrearCola();
    for (int i = 0; i < num_usuario; i++)
    {
        Encolar(pCola1, *pElemento);
        pElemento++;
    }
    printf("Exito");
}

tPila *ExtraerPilaOrden(tPila *pPila, char Letra)
{

    /* A rellenar por el alumno */
}

tCola ExtraerColaOrden(tCola Cola, char Letra)
{
    /* A rellenar por el alumno */
}
