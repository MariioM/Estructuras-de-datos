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

/// @brief Menú que permite al usuario navegar entre las diferentes opciones.
/// @return Entero que representa la opción elegida por el usuario.
int Menu();
/// @brief Calcula el número total de usuarios que contiene el fichero.
/// @param pf_usuarios  Puntero al fichero que contiene los datos.
/// @param num_usuarios Puntero al número de usuarios.
void CalculaUsuarios(FILE *pf_usuarios, int *num_usuarios);
/// @brief Lee el fichero y guarda los datos en un puntero de tipo tElemento
/// @param pf_usuarios Puntero al fichero que contiene los datos
/// @param usuario Puntero al elemento que controla los datos de los usuarios
/// @param num_usuarios Puntero al número de usuarios
/// @param lineaDatos Cadena de caracteres que contiene los datos de los usuarios
/// @return Devuelve 0 si se ha leído correctamente, y -1 si ha habido algún error
int LeeFichero(FILE *pf_usuarios, tElemento *usuario, int num_usuarios, char lineaDatos[]);
/// @brief Gestiona la construcción de las pilas
/// @param pPila1 Puntero a la pila que se va a construir
/// @param pElemento Puntero al elemento que contiene los datos de los usuarios
/// @param num_usuarios Número de usuarios
/// @return Puntero a la pila construida
tPila *ConstruirPila(tPila *pPila1, tElemento *pElemento, int num_usuarios);
/// @brief Gestiona la construcción de las colas
/// @param pCola1 Puntero a la cola que se va a construir
/// @param pElemento Puntero al elemento que contiene los datos de los usuarios
/// @param num_usuario Número de usuarios
/// @return Cola construida
tCola ConstruirCola(tCola *pCola1, tElemento *pElemento, int num_usuario);
/// @brief Gestiona la construcción de las listas
/// @param pLista Puntero a la lista que se va a construir
/// @param pElemento Puntero al elemento que contiene los datos de los usuarios
/// @param num_usuario Número de usuarios
/// @return
tLista *ConstruirLista(tLista *pLista, tElemento *pElemento, int num_usuario);
/// @brief Extrae los nombres de la pila que comienzan por una letra y los guarda en una pila auxiliar
/// @param pPila Puntero a la pila que contiene los nombres
/// @param Letra Letra por la que se va a filtrar
/// @param pPila2 Puntero a la pila auxiliar donde se van a guardar los nombres que comienzan por la letra
/// @param num_usuarios Número de usuarios
/// @param aux1 Puntero al número de elementos de la pila que no comienzan por la letra
/// @param aux2 Puntero al número de elementos de la pila que comienzan por la letra
/// @return
void *ExtraerPilaOrden(tPila *pPila, char Letra, tPila *pPila2, int *aux1, int *aux2);
/// @brief Extre los nombres de la cola que comienzan por una letra y los guarda en una cola auxiliar
/// @param pCola1 Puntero a la cola que contiene los nombres
/// @param Letra Letra por la que se va a filtrar
/// @param pCola2 Puntero a la cola auxiliar donde se van a guardar los nombres que comienzan por la letra
/// @param pAux Puntero a la cola auxiliar donde se van a guardar los nombres que no comienzan por la letra
/// @return
tCola ExtraerColaOrden(tCola *pCola1, char Letra, tCola *pCola2, tCola *pAux);


int main(void)
{
    // Elemento
    tElemento *pElemento;

    // Pilas
    tPila *pPila1, *pPila2;
    pPila1 = NULL;
    pPila2 = NULL;
    char Let_pila;
    int tam_aux1, tam_aux2;

    // Colas
    tCola Cola1;
    tCola Cola2;
    tCola ColaAux;
    char Let_cola;

    // Listas
    tLista *pLista;

    // Fichero
    FILE *pf_usuarios;
    int num_usuarios;
    char Cadena[MAX_CAR * 3 + 2];

    // Textos Menus
    char textoMenuPrincipal[] = "\n  Elija que quiere hacer: \n\t 1) Leer fichero.\n\t 2) Construir estructuras.\n\t 3) Extraer nombres pila. \n\t 4) Extraer nombres cola. \n\t 5) Visualizar estructuras \n\t 6) Salir del programa.\n  => ";
    char textoMenuConstruir[] = "\n  Elija que opcion desea realizar: \n\t 1) Construir pilas.\n\t 2) Construir colas.\n\t 3) Construir listas. \n\t 4) Volver atras. \n  => ";
    char textoMenuVisualizar[] = "\n  Elija que opcion desea realizar: \n\t 1) Visualizar pilas.\n\t 2) Visualizar colas.\n\t 3) Visualizar listas. \n\t 4) Volver atras. \n  => ";

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
            switch (Menu(textoMenuConstruir, 1, 4))
            {
            case OPCION_UNO: // 1) Construir pilas.
                pPila1 = CrearPila();
                pPila1 = ConstruirPila(pPila1, pElemento, num_usuarios);
                printf("  Pila construida correctamente!\n");
                break;
            case OPCION_DOS: // 2) Construir colas.
                Cola1 = ConstruirCola(&Cola1, pElemento, num_usuarios);
                Cola2 = CrearCola();
                // Se crea una cola auxiliar
                ColaAux = CrearCola();
                printf("  Cola construida correctamente!\n");
                break;
            case OPCION_TRES: // 3) Construir listas.
                pLista = CrearLista();
                pLista = ConstruirLista(pLista, pElemento, num_usuarios);
                printf("  Lista construida correctamente!\n");
                break;
            case OPCION_CUATRO: // 4) Volver atras.
                break;
            }
            break;
        case OPCION_TRES: // 3) Extraer nombres pila.
            pPila2 = CrearPila();
            fflush(stdin);
            printf("Escoja una letra: ");
            scanf("%c", &Let_pila);
            ExtraerPilaOrden(pPila1, Let_pila, pPila2, num_usuarios, &tam_aux1, &tam_aux2);
            // TEST
            printf("\n\n  * Pila con nombres que no empiezan por %c;", Let_pila);
            VisualizarPila(pPila1, tam_aux1);
            printf("\n\n  * Pila con nombres que empiezan por %c:", Let_pila);
            VisualizarPila(pPila2, tam_aux2);
            break;
        case OPCION_CUATRO: // 4) Extraer nombres cola.
            fflush(stdin);
            printf("Escoja una letra: ");
            scanf("%c", &Let_cola);

            // ExtraerColaOrden toma la Cola1, que es la que contiene en un principio todos los nombres, y trabajará sobre
            // ella para devolver en Cola2 los nombres con la letra buscada, y en ColaAux la cola sin esos nombres. Le paso por parámetro la letra
            // y el número de usuarios para facilitar la ejecución.
            Cola1 = ExtraerColaOrden(&Cola1, Let_cola, &Cola2, &ColaAux, num_usuarios);
            printf("\n\n  * Cola con los nombres: \n");
            VisualizarCola(Cola2);
            printf("\n\n  * Cola sin esos nombres: \n");
            VisualizarCola(Cola1);
            //En el caso de que se vuelva a pedir que extraigamos un nombre de la cola, 
            //debemos antes destruir la Cola2, para inicializarla de nuevo
            Cola2 = DestruirCola(&Cola2);
            break;
        case OPCION_CINCO: // 5) Visualizar estructuras
            switch (Menu(textoMenuVisualizar, 1, 3))
            {
            case OPCION_UNO: // 1) Visualizar pilas.
                printf("\nPila:\n");
                VisualizarPila(pPila1, num_usuarios);
                break;
            case OPCION_DOS: // 2) Visualizar colas.
                printf("\nCola:\n");
                VisualizarCola(Cola1);
                break;
            case OPCION_TRES: // 3) Visualizar listas.
                printf("\nLista:\n");
                VisualizarLista(pLista);
                break;
            case OPCION_CUATRO: // 4) Volver atras.
                break;
            }
            break;
        case OPCION_SEIS: // 6) Salir del programa.
            exit(1);
            break;
        }
    } while (1);

    return 0;
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


tLista *ConstruirLista(tLista *pLista, tElemento *pElemento, int num_usuario)
{
    pLista = CrearLista();
    for (int i = 0; i < num_usuario; i++)
    {
        *pLista = Insertar((*pLista), *pElemento, ConseguirPosicionFin(*pLista));
        pElemento++;
    }

    return pLista;
}
tPila *ConstruirPila(tPila *pPila1, tElemento *pElemento, int num_usuarios)
{
    tPila *pPilaAux = CrearPila();
    for (int i = 0; i < num_usuarios; i++)
    {
        Apilar(pPilaAux, *pElemento);
        pElemento++;
    }
    for (int i = 0; i < num_usuarios; i++)
    {
        Apilar(pPila1, pPilaAux->cima->Elem);
        Desapilar(pPilaAux);
    }
    DestruirPila(pPilaAux);
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

void *ExtraerPilaOrden(tPila *pPila, char Letra, tPila *pPila2, int num_usuarios, int *aux1, int *aux2)
{
    tPila *pAux1, *pAux2;
    pAux1 = CrearPila();
    pAux2 = CrearPila();
    // El nodo buscado será repetitivamente igualado a la cabeza de la Cola1, que irá cambiando a medida que se vaya desencolando
    tNodo *buscar;
    // Name será usado para poder comparar la letra buscada con la primera letra de cada nombre.
    char nombre[60];
    while (!EsPilaVacia(pAux1))
    {
        // Asigno la cabeza al buscado
        buscar = pPila->cima;
        strcpy(nombre, buscar->Elem.Nombre);
        if (Letra == nombre[0])
        {
            // Si la letra coincide, el proceso será encolar dicho nombre, su apellido y su pass en la Cola2, y posteriormente desencolar la Cola1,
            // Que acabará vacía al final del while
            Apilar(pAux2, buscar->Elem);
            if (!EsPilaVacia(pPila))
            {
                printf("ERR_404. La cola está vacía.");
                break;
            }
            else
            {
                Desapilar(pPila);
            }
        }
        else if (nombre[0] = "\n" && Letra == nombre[1])
        {
            // En algunos casos, el fichero ha guardado un "\n" antes del nombre, por lo que tendremos que comprobar también esta premisa
            Apilar(pAux2, buscar->Elem);
            if (!EsPilaVacia(pPila))
            {
                printf("ERR_404. La cola está vacía.");
            }
            else
            {
                Desapilar(pPila);
            }
        }
        else
        {
            // Si la letra no coincide, simplemente encolamos en la auxiliar, que contendrá la cola sin los nombres buscamos, y desencolamos de cola1, para que la cabeza
            // se mueva a la siguiente posición.
            Apilar(pAux1, buscar->Elem);
            if (!EsPilaVacia(pPila))
            {
                printf("ERR_404. La cola está vacía.");
            }
            else
            {
                Desapilar(pPila);
            }
        }
        j++;
    }

    // Luego hay que ordenar las pilas, de modo que no se enseñen de forma invertida
    *aux1 = CalcularNumElementos(pAux1);
    *aux2 = CalcularNumElementos(pAux2);

    for (j = 0; j < *aux1; j++)
    {

        Apilar(pPila, pAux1->cima->Elem);
        Desapilar(pAux1);
    }
    for (j = 0; j < *aux2; j++)
    {

        Apilar(pPila2, pAux2->cima->Elem);
        Desapilar(pAux2);
    }
    DestruirPila(pAux1);
    DestruirPila(pAux2);
}

tCola ExtraerColaOrden(tCola *pCola1, char Letra, tCola *pCola2, tCola *pAux)
{
    // El nodo buscado será repetitivamente igualado a la cabeza de la Cola1, que irá cambiando a medida que se vaya desencolando
    tNodo *buscado;
    // Name será usado para poder comparar la letra buscada con la primera letra de cada nombre.
    char name[60];
    int i = -1;
    while (i != 0)
    {
        // Asigno la cabeza al buscado
        buscado = pCola1->pCab;
        strcpy(name, buscado->Elem.Nombre);
        if (Letra == name[0])
        {
            // Si la letra coincide, el proceso será encolar dicho nombre, su apellido y su pass en la Cola2, y posteriormente desencolar la Cola1,
            // Que acabará vacía al final del while
            Encolar(pCola2, buscado->Elem);
            Desencolar(pCola1);
        }
        else if (name[0] = "\n" && Letra == name[1])
        {
            // En algunos casos, el fichero ha guardado un "\n" antes del nombre, por lo que tendremos que comprobar también esta premisa
            Encolar(pCola2, buscado->Elem);
            Desencolar(pCola1);
        }
        else
        {
            // Si la letra no coincide, simplemente encolamos en la auxiliar, que contendrá la cola sin los nombres buscamos, y desencolamos de cola1, para que la cabeza
            // se mueva a la siguiente posición.
            Encolar(pAux, buscado->Elem);

            Desencolar(pCola1);
        }
        i = EsColaVacia(pCola1);
    }
    int j = 0;
    int tam_aux = CalcularNumElementosC(pAux);
    //Como me interesa devolver los elementos que no coinciden con la letra de la auxiliar a la cola1, ejecuto el siguiente bucle.
    while (j < tam_aux)
    {
        Encolar(pCola1, pAux->pCab->Elem);
        Desencolar(pAux);
        j++;
    }
    // Mediante la funcion CalcularNumElementosC, veremos cuantos usuarios hay en cada cola. La cola1 obviamente tendrá 0 usuarios al acabar el while.
    printf("La cola con los nombres que empiezan por la letra %c esta compuesta por %d usuarios.\n", Letra, CalcularNumElementosC(pCola2));
    printf("La cola con los nombres que no empiezan por la letra %c esta compuesta por %d usuarios.\n", Letra, CalcularNumElementosC(pCola1));
    return *pCola1;
}
