using System;
// TADS fuertemente tipados
// TADS pila, colas, etc.
using System.Collections;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;




namespace Ejecicio_2

{

    class Program
    {
        public const string fichero = @"../../../data/fich02.csv";

        public struct DescripcionUbi
        {
            public string Nombre;
            public string Apellido;
            public string Password;
        }


        static void Main(string[] args)
        {
            DescripcionUbi[] datosUsuario; 

            // Se imprime el menú y se diferencian entre las diferentes opciones
            switch(MenuPrincipal())
            {
                case 1: // Leer fichero
                    LeerFichero(fichero, out datosUsuario);
                    break;
                case 2: // Construir Estructuras
                    break;
                case 3: // Extraer nombres pilas
                    break;
                case 4: // Extraer nombres cola
                    break;
                case 5: // Visualizar estructuras
                    break;
                case 6: // Salir
                    break;
                default:
                    Console.WriteLine("Internal error (wrong option input)");
                    break;
            }

        }


        public static void ExtraerDatos(string str, out string Nombre, out string Apellido, out string Password)
        {
            string[] array = str.Split(';');

            Nombre = array[0];
            Apellido= array[1];
            Password= array[2];

        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="NomFich">
        /// </param>
        /// <param name="NomFich">
        /// </param>
        public static void LeerFichero(string NomFich, out DescripcionUbi[] datosusu)
        {
            DescripcionUbi[] arrayUsuario = new DescripcionUbi[50];
            int indice = 0;

            if (!File.Exists(NomFich))
            {
                Console.WriteLine("\nError! El archivo no existe.");
                datosusu = null;
                Console.ReadKey();
                return;
            }

            FileStream archivo = File.Open(NomFich, FileMode.Open, FileAccess.Read);
            StreamReader reader = new StreamReader(archivo);

            do
            {
                DescripcionUbi informacionUsuario = new DescripcionUbi();
                var linea = reader.ReadLine();
                ExtraerDatos(linea, out informacionUsuario.Nombre, out informacionUsuario.Apellido, out informacionUsuario.Password);
                arrayUsuario[indice++] = informacionUsuario;
            } while (!reader.EndOfStream);

            datosusu = arrayUsuario;

            Console.WriteLine("\nArchivo leido correctamente!");

            archivo.Close();

            Console.ReadKey();

        }

        static void leercadena(out string cadena)
        {
            cadena = null;
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

        static void imprimirPila(Stack pila)
        {
            /* A rellenar por el alumno */

        }



        
        static void imprimirCola(Queue cola)
        {
            /* A rellenar por el alumno */

        }


        /// <summary>
        /// Imprime el menú principal.
        /// </summary>
        /// <returns>
        /// Opción elegida.
        /// </returns>
        static int MenuPrincipal()
        {
            // Se declara una variable de opción y otra de control
            int opcion;
            bool control = true;
            
            // Interfaz menú
            Console.Write("1) Leer Fichero\n2) Construir Estructuras\n3) Extraer Nombres Pila\n4) Extraer Nombres Cola\n5) Visualizar Estructuras\n6) Salir\n\n=> ");
            
            // Se pide al usuario la opción deseada
            if(int.TryParse(Console.ReadLine(), out opcion))
            {
                control = true;
            }
            else
            {
                control = false;
                Console.WriteLine("Valor introducido incorrecto. El valor debe ser un número entero");
            }

            if (opcion < 1 || opcion > 6)
            {
                control = false;
                Console.WriteLine("Opción Incorrecta. Elija una opción válida");
            }

            return opcion;
        }
    }
}
