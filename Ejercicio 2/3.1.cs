
using System;
// TADS fuertemente tipados
// TADS pila, colas, etc.
using System.Collections;
using System.ComponentModel;
using System.IO;
using System.Text.RegularExpressions;




namespace PRACTICA2_P4_V1

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

            /* A rellenar por el alumno */

        }

        public static void LeerFichero(string NomFich, out string[] datosusu)
        {
            /* A rellenar por el alumno */

        }


        static void leercadena(out string cadena)
        {
            /* A rellenar por el alumno */


        }

        /** añade un nuevo elemento a la pila */

        static void agregarPila(ref Stack pila, DescripcionUbi valor)
        {
            /* A rellenar por el alumno */

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
    }
}








