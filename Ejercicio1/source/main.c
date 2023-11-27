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

int Menu();
void MenuConstruir(tPila *pPila1, tPila *pPila2, tCola *Cola1, tCola *Cola2, tLista *pLista, tElemento *pElemento, int num_usuarios);
void CalculaUsuarios(FILE *pf_usuarios, int *num_usuarios);
int LeeFichero(FILE *pf_usuarios, tElemento *usuario, int num_usuarios, char lineaDatos[]);
void Pausar(void);
void ConstruirPilas(tPila *pPila1, tPila *pPila2, tElemento *pElemento);
tPila *ConstruirPila(tPila *pPila1, tElemento *pElemento, int num_usuarios);
tCola ConstruirCola(tCola *pCola1, tElemento *pElemento, int num_usuario);
void ContruirLista(tLista *pLista, tElemento *pElemento, int num_usuario);
tPila *ExtraerPilaOrden(tPila *pPila, char Letra);
tCola ExtraerColaOrden(tCola *pCola1, char Letra, tCola *pCola2, tCola *pAux, int num_usuarios);

int main(void)
{
    // Pilas
    tPila *pPila1, *pPila2;
    pPila1 = NULL;
    pPila2 = NULL;

    // Colas
    tCola Cola1;
    tCola Cola2;
    tCola ColaAux;

    // Listas
    tLista pLista;

    // Fichero
    FILE *pf_usuarios;
    int num_usuarios;
    char Cadena[MAX_CAR * 3 + 2];

    // Elementos
    tElemento e;
    tElemento *pElemento;
    tElemento Elemento;

    // Información Usuario
    char Nombre[MAX_CAR];
    char Apellido[MAX_CAR];
    char Password[MAX_CAR];

    // Textos Menus
    char textoMenuPrincipal[] = "\n  Elija que quiere hacer: \n\t 1) Leer fichero.\n\t 2) Construir estructuras.\n\t 3) Extraer nombres pila. \n\t 4) Extraer nombres cola. \n\t 5) Visualizar estructuras \n\t 6) Salir del programa.\n  => ";
    char textoMenuVisualizar[] = "\n  Elija que opcion desea realizar: \n\t 1) Visualizar pilas.\n\t 2) Visualizar colas.\n\t 3) Visualizar listas. \n\t 4) Volver atras. \n  => ";

    char *cpToken;
    int FlgSalir;
    int TipoOperacion;
    int Num1, Num2, i;
    int Res, Num;
    int LongI, LatI;
    int k;
    int j;
    int Pos;
    tPosicion pPos;
    char name[N];
    char Let_cola;
    do
    {
        switch (Menu(textoMenuPrincipal, 1, 6))
        {
        case OPCION_UNO: // 1) Leer fichero.
            // Se calcula el número de usuarios existentes
            CalculaUsuarios(pf_usuarios, &num_usuarios);
            // Se le asigna memoria dinámica al puntero que apunta a los usuarios
            pElemento = (tElemento *)malloc(num_usuarios * sizeof(tElemento));
            // Se lee y guarda el fichero
            LeeFichero(pf_usuarios, pElemento, num_usuarios, Cadena);
            break;
        case OPCION_DOS: // 2) Construir estructuras.
            MenuConstruir(pPila1, pPila2, &Cola1, &Cola2, &pLista, pElemento, num_usuarios);
            break;
        case OPCION_TRES: // 3) Extraer nombres pila.
            break;
        case OPCION_CUATRO: // 4) Extraer nombres cola.
            fflush(stdin);
            printf("Escoja una letra: ");
            scanf("%c", &Let_cola);

            Cola2 = CrearCola();
            // Se crea una cola auxiliar
            ColaAux = CrearCola();

            // ExtraerColaOrden toma la Cola1, que es la que contiene en un principio todos los nombres, y trabajará sobre
            // ella para devolver en Cola2 los nombres con la letra buscada, y en ColaAux la cola sin esos nombres. Le paso por parámetro la letra
            // y el número de usuarios para facilitar la ejecución.
            Cola1 = ExtraerColaOrden(&Cola1, Let_cola, &Cola2, &ColaAux, num_usuarios);
            printf("Cola con los nombres: \n");
            VerCola(Cola2);
            printf("Cola sin esos nombres: \n");
            VerCola(ColaAux);

            scanf("%d");
            break;
        case OPCION_CINCO: // 5) Visualizar estructuras
            switch (Menu(textoMenuVisualizar, 1, 3))
            {
            case OPCION_UNO: // 1) Visualizar pilas.
                break;
            case OPCION_DOS: // 2) Visualizar colas.
                break;
            case OPCION_TRES: // 3) Visualizar listas.
                break;
            case OPCION_CUATRO: // 4) Volver atras.
                break;
            }
        case OPCION_SEIS: // 6) Salir del programa.
            exit(1);
            break;
        }
    } while (1);
    // Cola1 = ConstruirCola(&Cola1, pElemento, num_usuarios);
    printf("Introduzca una letra: ");
    scanf("%c", Let_cola);
    scanf("%d");

    return 0;
}

void MenuConstruir(tPila *pPila1, tPila *pPila2, tCola *Cola1, tCola *Cola2, tLista *pLista, tElemento *pElemento, int num_usuarios)
{
    char textoMenuConstruir[] = "\n  Elija que opcion desea realizar: \n\t 1) Construir pilas.\n\t 2) Construir colas.\n\t 3) Construir listas. \n\t 4) Volver atras. \n  => ";

    switch (Menu(textoMenuConstruir, 1, 4))
    {
    case OPCION_UNO: // 1) Construir pilas.
        ConstruirPilas(pPila1, pPila2, pElemento);
        break;
    case OPCION_DOS: // 2) Construir colas.
        (*Cola1) = ConstruirCola(&(*Cola1), pElemento, num_usuarios);
        (*Cola2) = ConstruirCola(&(*Cola2), pElemento, num_usuarios);
        break;
    case OPCION_TRES: // 3) Construir listas.
        ContruirLista(&(*pLista), pElemento, num_usuarios);
        break;
    case OPCION_CUATRO: // 4) Volver atras.
        break;
    }
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
        printf("Name: %s\nApellido: %s\nPassword: %s\n", usuario->Nombre, usuario->Apellido, usuario->Password);
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

tPila *ConstruirPila(tPila *pPila1, tElemento *pElemento, int num_usuarios)
{
    for (int i = 0; i < num_usuarios; i++)
    {
        Apilar(pPila1, *pElemento);
        pElemento++;
    }
    return pPila1;
}

tCola ConstruirCola(tCola *pCola1, tElemento *pElemento, int num_usuario)
{
    *pCola1 = CrearCola();
    for (int i = 0; i < num_usuario; i++)
    {
        Encolar(pCola1, *pElemento);
        pElemento++;
    }
    return *pCola1;
}

void ContruirLista(tLista *pLista, tElemento *pElemento, int num_usuario)
{
    pLista = CrearLista();
    for (int i = 0; i < num_usuario; i++)
    {
        *pLista = Insertar((*pLista), *pElemento, ConseguirPosicionFin(*pLista));
        pElemento++;
    }
}

tPila *ExtraerPilaOrden(tPila *pPila, char Letra)
{

    /* A rellenar por el alumno */
}

tCola ExtraerColaOrden(tCola *pCola1, char Letra, tCola *pCola2, tCola *pAux, int num_usuarios)
{
    // El nodo buscado será repetitivamente igualado a la cabeza de la Cola1, que irá cambiando a medida que se vaya desencolando
    tNodo *buscado;
    // Name será usado para poder comparar la letra buscada con la primera letra de cada nombre.
    char name[60];
    int i = 0;
    while (i < num_usuarios)
    {
        // Asigno la cabeza al buscado
        buscado = pCola1->pCab;
        strcpy(name, buscado->Elem.Nombre);
        if (Letra == name[0])
        {
            // Si la letra coincide, el proceso será encolar dicho nombre, su apellido y su pass en la Cola2, y posteriormente desencolar la Cola1,
            // Que acabará vacía al final del while
            Encolar(pCola2, buscado->Elem);
            if (EsColaVacia(pCola1))
            {
                printf("ERR_404. La cola está vacía.");
                break;
            }
            else
            {
                Desencolar(pCola1);
            }
        }
        else if (name[0] = "\n" && Letra == name[1])
        {
            // En algunos casos, el fichero ha guardado un "\n" antes del nombre, por lo que tendremos que comprobar también esta premisa
            Encolar(pCola2, buscado->Elem);
            if (EsColaVacia(pCola1))
            {
                printf("ERR_404. La cola está vacía.");
            }
            else
            {
                Desencolar(pCola1);
            }
        }
        else
        {
            // Si la letra no coincide, simplemente encolamos en la auxiliar, que contendrá la cola sin los nombres buscamos, y desencolamos de cola1, para que la cabeza
            // se mueva a la siguiente posición.
            Encolar(pAux, buscado->Elem);
            if (EsColaVacia(pCola1))
            {
                printf("ERR_404. La cola está vacía.");
            }
            else
            {
                Desencolar(pCola1);
            }
        }
        i++;
    }
    // MEdiante la funcion CalcularNumElementosC, veremos cuantos usuarios hay en cada cola. La cola1 obviamente tendrá 0 usuarios al acabar el while.
    printf("La cola con los nombres que empiezan por la letra %c está compuesta por %d usuarios.\n", Letra, CalcularNumElementosC(pCola2));
    printf("La cola con los nombres que no empiezan por la letra %c está compuesta por %d usuarios.\n", Letra, CalcularNumElementosC(pAux));
}
