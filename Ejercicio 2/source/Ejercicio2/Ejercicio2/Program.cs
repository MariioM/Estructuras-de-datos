using System;
// TADS fuertemente tipados
// TADS pila, colas, etc.
using System.Collections;
using System.ComponentModel;
using System.IO;
using System.Text.RegularExpressions;

namespace Ejercicio2

{

    class Program
    {
        struct DescripcionUbi
        {
            public string Nombre;
            public string Apellido;
            public string Password;
        }
        static void Main(string[] args)
        {
            //Se inicia el menú y se controlan las diversas opciones
            switch (MenuPrincipal())
            {
                case 1: //Leer fichero
                    break;
                case 2:
                    MenuConstruirEstructuras();
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                default:
                    Console.WriteLine("Internal error (Incorrect option)");
                    break;
            }

            Console.ReadLine();
        }

        public static void ExtraerDatos(string str, out string Nombre, out string Apellido, out string Password)
        {

            Nombre = "s";
            Apellido= "a";
            Password= "s";
        }

        public static void LeerFichero(string NomFich, out string[] datosusu)
        {
            datosusu = new string[NomFich.Length];

        }


        static void leercadena(out string cadena)
        {
            cadena= "s";


        }

        /** añade un nuevo elemento a la pila */

        static void agregarPila(ref Stack pila, DescripcionUbi valor)
        {
            
        }

        static void ExtraerElemNomP(char Letra, ref Stack pila)
        {
            /* A rellenar por el alumno */

        }

        /** muestra menu y retorna opción */

        static void agregarCola(ref Queue Cola, DescripcionUbi valor)
        {
            /* A rellenar por el alumno */

        }


        static void ExtraerElemNomC(char Letra, ref Queue cola)
        {

            /* A rellenar por el alumno */

        }

        /** Elimina todo los elementos de la pila */
        static void limpiar(ref Stack pila)
        {
            /* A rellenar por el alumno */

        }

        static void limpiarC(ref Queue cola)
        {
            /* A rellenar por el alumno */

        }



        /** Elimina elemento de la pila */
        static void eliminar(ref Stack pila)
        {
            /* A rellenar por el alumno */

        }

        static void eliminarC(ref Queue cola)
        {
            /* A rellenar por el alumno */

        }

        static void imprimirPila(Stack pila)
        {
            /* A rellenar por el alumno */

        }

        static void imprimirCola(Queue cola)
        {
            /* A rellenar por el alumno */

        }

        /// @brief Muestra el menú principal
        /// @returns Opción elegida
        static int MenuPrincipal()
        {
            //Se declara una variable de opción y otra de control
            int option;
            bool control = false;
            //Interfaz gráfica
            do
            {
                Console.WriteLine("1. Leer fichero.\n2. Construir Estructuras.\n3. Extraer nombres pila.\n4. Extraer nombres cola.\n5. Visualizar estructuras.\n6. Salir.\n\n\n=>");
                if (int.TryParse(Console.ReadLine(), out option))
                {
                    control = true;
                }
                else
                {
                    control = false;
                    Console.WriteLine("Valor incorrecto. El valor introducido debe ser un número");
                }
                if (option < 1 || option > 6)
                {
                    control = false;
                    Console.WriteLine("Introduzca una opción válida");
                }

            } while (!control);

            return option;
        }

        static int MenuConstruirEstructuras()
        {
            return 0;
        }

    }
}

