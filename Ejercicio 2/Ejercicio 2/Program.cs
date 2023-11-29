using System;
// TADS fuertemente tipados
// TADS pila, colas, etc.
using System.Collections;
using System.Collections.Generic;
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
            //Se instancia una pila y una cola
            Stack<DescripcionUbi> pila = new Stack<DescripcionUbi>();
            Queue<DescripcionUbi> cola = new Queue<DescripcionUbi>();
            //Se declara una variable de control del programa y el array de los datos
            bool program = true;
            DescripcionUbi[] datosUsuario =  new DescripcionUbi[50];
            do
            {
                // Se imprime el menú y se diferencian entre las diferentes opciones
                switch (MenuPrincipal())
                {
                    case 1: // Leer fichero
                        Console.Clear();
                        LeerFichero(fichero, out datosUsuario);
                        break;
                    case 2: // Construir Estructuras
                        Console.Clear();
                        //Se muestra el menú de construir estructuras
                        switch (MenuConstruirEstructuras())
                        {
                            case 1: //Construir pila
                                Console.Clear();
                                //Se instancian una pila auxiliar
                                Stack<DescripcionUbi> pilaAux = new Stack<DescripcionUbi>();
                                //Array auxiliar para ordenar elementos
                                DescripcionUbi[] listaAuxiliar = new DescripcionUbi[50];
                                //Se insertan los elementos de forma inversa
                                for (int i = 0; i < datosUsuario.Length; i++)
                                {
                                    AgregarPila(ref pilaAux, datosUsuario[i]);
                                }
                                //Se colocan los elementos ya ordenados en un array auxiliar
                                for(int i = 0; i < datosUsuario.Length; i++)
                                {
                                    pilaAux.CopyTo(listaAuxiliar, 0);
                                }
                                for(int i = 0; i < datosUsuario.Length; i++) 
                                {
                                    AgregarPila(ref pila, listaAuxiliar[i]);
                                }
                                break;
                            case 2: //Construir colas
                                Console.Clear();
                                //Se insertan todos los elementos en la cola
                                for (int i = 0; i < datosUsuario.Length; i++)
                                {
                                    AgregarCola(ref cola, datosUsuario[i]);
                                }
                                break;
                            default:
                                throw new Exception("Internal Error (Build option doesn´t exist)");
                        }
                        break;
                    case 3: // Extraer nombres pilas
                        Console.Clear();
                        //Se declara una variable de control y otra que guarde el número de nombres eliminados
                        bool control = true;
                        int deletedNames;
                        //Se pide al usuario que indique la letra
                        char letra;
                        do { 
                            Console.Write("Indique la letra inicial de los nombres a extraer => ");
                            if(char.TryParse(Console.ReadLine(), out letra))
                            {
                                deletedNames = ExtraerElemNomP(letra, ref pila);
                                Console.WriteLine("----------------------------------------------");
                                Console.WriteLine("Se han eliminado " + deletedNames + " nombres.");
                                Console.WriteLine("----------------------------------------------");
                                Console.WriteLine("Pulse cualquier tecla para continuar...");
                                Console.ReadKey();
                                Console.Clear();
                                control = true;
                            }
                            else
                            {
                                Console.WriteLine("El valor introducido debe ser un único carácter"); 
                                control= false;
                            }
                        }while( !control );
                        break;
                    case 4: // Extraer nombres cola
                        break;
                    case 5: // Visualizar estructuras
                        break;
                    case 6: // Salir
                        program = false;
                        break;
                    default:
                        throw new Exception("Internal error (wrong option input)");
                }
            } while (program);

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
        }

        static void leercadena(out string cadena)
        {
            cadena = null;
        }

        /// <summary>
        /// Agrega un elemento a una pila
        /// </summary>
        /// <param name="pila">Pila</param>
        /// <param name="valor">Elemento</param>

        static void AgregarPila(ref Stack<DescripcionUbi> pila, DescripcionUbi valor)
        {
            pila.Push(valor);
        }

        /// <summary>
        /// Extrae todos los nombres que empiezan por una letra determinada
        /// </summary>
        /// <param name="Letra">Letra indicada</param>
        /// <param name="pila">Pila</param>
        static int ExtraerElemNomP(char Letra, ref Stack<DescripcionUbi> pila)
        {
            //Se pasa la letra a mayúsculas para evitar fallos
            string letraIgnoreMayus = Letra.ToString().ToUpper();
            //Se instancia una pila auxiliar
            Stack<DescripcionUbi> pilaAux = new Stack<DescripcionUbi>();
            //Se declara una variable que guarde el Top Of Stack
            DescripcionUbi TOS = new DescripcionUbi();
            //Variables que comprueben el tamaño de la pila y de la pila auxiliar
            int auxStackInitialSize;
            int stackInitialSize = pila.Count;
            //Se declara una variable que guarde el número de nombres eliminados
            int deletedNames = 0;
            //Bucle para comprobar los nombres
            for (int i = 0; i < stackInitialSize; i++)
            {
                //Se guarda la cima
                TOS = pila.Peek();
                if (TOS.Nombre[0].ToString() != letraIgnoreMayus) //Se comprueba si el nombre empieza por la letra indicada
                {
                    //Si no lo hace, se guarda en la pila auxiliar
                    AgregarPila(ref pilaAux, pila.Pop());
                }
                else //Si empieza por la letra, se elimina
                {
                    pila.Pop();
                    deletedNames++;
                }
            }
            auxStackInitialSize = pilaAux.Count;
            //Se devuelven los elementos a la pila original
            for (int i = 0; i < auxStackInitialSize; i++)
            {
                AgregarPila(ref pila, pilaAux.Pop());
            }
            return deletedNames;
        }

        /// <summary>
        /// Agrega un elemento a una cola
        /// </summary>
        /// <param name="Cola">Cola</param>
        /// <param name="valor">Elemento</param>

        static void AgregarCola(ref Queue<DescripcionUbi> Cola, DescripcionUbi valor)
        {
            Cola.Enqueue(valor);
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

        static int MenuConstruirEstructuras()
        {
            // Se declara una variable de opción y otra de control
            int opcion;
            bool control = true;

            // Interfaz menú
            Console.Write("1) Construir Pila\n2) Construir Cola\n\n\n=> ");

            // Se pide al usuario la opción deseada
            if (int.TryParse(Console.ReadLine(), out opcion))
            {
                control = true;
            }
            else
            {
                control = false;
                Console.WriteLine("Valor introducido incorrecto. El valor debe ser un número entero");
            }

            if (opcion < 1 || opcion > 2)
            {
                control = false;
                Console.WriteLine("Opción Incorrecta. Elija una opción válida");
            }

            return opcion;
        }
    }
}
