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
            /* A rellenar por el alumno */


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
        /** muestra menu y retorna opción */




        static int menu()
        {
            return 0;

        }

        static void imprimirPila(Stack pila)
        {
            /* A rellenar por el alumno */

        }




        static void imprimirCola(Queue cola)
        {
            /* A rellenar por el alumno */

        }
    }
}

