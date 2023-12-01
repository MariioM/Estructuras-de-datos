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
            // Se instancia una pila y una cola
            Stack<DescripcionUbi> pila = new Stack<DescripcionUbi>();
            Queue<DescripcionUbi> cola = new Queue<DescripcionUbi>();
            
            // Se declara una variable de control del programa y el array de los datos
            bool program = true;
            DescripcionUbi[] datosUsuario =  new DescripcionUbi[50];
            
            do
            {
                // Se imprime el menú y se diferencian entre las diferentes opciones
                switch (MenuPrincipal())
                {
                    case 1: // Leer fichero
                        LeerFichero(fichero, out datosUsuario);
                        Continuar();
                        break;
                    case 2: // Construir Estructuras
                        Console.Clear();
                        ConstruirEstructuras(ref pila, ref cola, ref datosUsuario);
                        Continuar();
                        break;
                    case 3: // Extraer nombres pilas
                        Console.Clear();
                        ExtraerPila(ref pila);
                        Continuar();
                        break;
                    case 4: // Extraer nombres cola
                        Console.Clear();
                        ExtraerCola(ref cola);
                        Continuar();
                        break;
                    case 5: // Visualizar estructuras
                        Console.Clear();
                        VisualizarEstructuras(pila, cola);
                        Continuar();
                        break;
                    case 6: // Salir
                        program = false;
                        break;
                    default:
                        throw new Exception("Internal error (wrong option input)");
                }
            } while (program);

        }

        /// <summary>
        /// Da formato al texto extraido del fichero
        /// </summary>
        /// <param name="str">Cadena de texto</param>
        /// <param name="Nombre">Apartado Nombre Fichero</param>
        /// <param name="Apellido">Apartado Apellido Fichero</param>
        /// <param name="Password">Apartado Password Fichero</param>
        public static void ExtraerDatos(string str, out string Nombre, out string Apellido, out string Password)
        {
            string[] array = str.Split(';');

            Nombre = array[0];
            Apellido= array[1];
            Password= array[2];

        }

        /// <summary>
        /// Lee el fichero con los datos
        /// </summary>
        /// <param name="NomFich">
        /// Nombre del Fichero
        /// </param>
        /// <param name="datosusu">
        /// Array que guarda los datos formateados del fichero
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
        /// Extrae todos los nombres de la pila que empiezan por una letra determinada
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
            Limpiar(ref pilaAux);
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

        /// <summary>
        /// Extrae todos los nombres de la cola que empiezan por la letra indicada
        /// </summary>
        /// <param name="Letra">Letra indicada</param>
        /// <param name="cola">Cola</param>
        /// <returns>Número de elementos eliminados</returns>
        static int ExtraerElemNomC(char Letra, ref Queue<DescripcionUbi> cola)
        {
            //Se pasa la letra a mayúsculas para evitar fallos
            string letraIgnoreMayus = Letra.ToString().ToUpper();
            //Se declara una variable que guarde la cabeza de la cola
            DescripcionUbi cabezaCola = new DescripcionUbi();
            //Variable que comprueba el tamaño de la cola
            int queueInitialSize = cola.Count;
            //Se declara una variable que guarde el número de nombres eliminados
            int deletedNames = 0;
            //Bucle para eliminar nombres
            for(int i = 0; i < queueInitialSize; i++)
            {
                cabezaCola = cola.Peek();
                if (cabezaCola.Nombre[0].ToString() != letraIgnoreMayus)
                {
                    cola.Enqueue(cola.Dequeue());
                }
                else
                {
                    cola.Dequeue();
                    deletedNames++;
                }
            }

            return deletedNames;
        }

        /// <summary>
        /// Elimina todos los elementos de la pila
        /// </summary>
        /// <param name="pila">Pila</param>
        static void Limpiar(ref Stack<DescripcionUbi> pila)
        {
            pila.Clear();
        }

        /// <summary>
        /// Elimina todos los elementos de la cola
        /// </summary>
        /// <param name="pila">Pila</param>
        static void LimpiarC(ref Queue<DescripcionUbi> cola)
        {
            cola.Clear();
        }

        /// <summary>
        /// Imprime línea a línea los elementos de la pila
        /// </summary>
        /// <param name="pila">Pila</param>
        static void ImprimirPila(Stack<DescripcionUbi> pila)
        {
            // Se instancia una pila auxiliar
            Stack<DescripcionUbi> pilaAux = new Stack<DescripcionUbi>();
            // Se declara una variable que guarde el Top Of Stack
            DescripcionUbi TOS = new DescripcionUbi();
            // Variables que comprueben el tamaño de la pila y de la pila auxiliar
            int auxStackInitialSize;
            int stackInitialSize = pila.Count;
            // Bucle para recorrer la pila
            for (int i = 0; i < stackInitialSize; i++)
            {
                //Se guarda la cima
                TOS = pila.Peek();
                Console.WriteLine(TOS.Nombre + "  " + TOS.Apellido + "  " + TOS.Password);
                AgregarPila(ref pilaAux, pila.Pop());
            }
            auxStackInitialSize = pilaAux.Count;
            // Se devuelven los elementos a la pila original
            for (int i = 0; i < auxStackInitialSize; i++)
            {
                AgregarPila(ref pila, pilaAux.Pop());
            }

        }

        /// <summary>
        /// Imprime todos los elementos de la cola
        /// </summary>
        /// <param name="cola">Cola</param>
        static void ImprimirCola(Queue<DescripcionUbi> cola)
        {
            // Se declara una variable que guarde la cabeza de la cola
            DescripcionUbi cabezaCola = new DescripcionUbi();
            // Variable que comprueba el tamaño de la cola
            int queueInitialSize = cola.Count;
            // Bucle para visualizar cola
            for (int i = 0; i < queueInitialSize; i++)
            {
                cabezaCola = cola.Peek();
                Console.WriteLine(cabezaCola.Nombre + "  " + cabezaCola.Apellido + "  " + cabezaCola.Password);

                cola.Enqueue(cola.Dequeue());
            }

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
            Console.Write("\n1) Leer Fichero\n2) Construir Estructuras\n3) Extraer Nombres Pila\n4) Extraer Nombres Cola\n5) Visualizar Estructuras\n6) Salir\n\n=> ");
            
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

        /// <summary>
        /// Muestra menú de construir estructuras
        /// </summary>
        /// <returns>Opción elegida</returns>
        static int MenuConstruirEstructuras()
        {
            // Se declara una variable de opción y otra de control
            int opcion;
            bool control = true;

            // Interfaz menú
            Console.Write("\n1) Construir Pila\n2) Construir Cola\n\n=> ");

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

        /// <summary>
        /// Muestra el menú de visualizar las estructuras
        /// </summary>
        /// <returns>Opción elegida</returns>
        static int MenuVisualizarEstructuras()
        {
            // Se declara una variable de opción y otra de control
            int opcion;
            bool control = true;

            // Interfaz menú
            Console.Write("\n1) Visualizar pila\n2) Visualizar Cola\n\n=> ");

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

        /// <summary>
        /// Controla la lógica de construir las pilas y colas
        /// </summary>
        /// <param name="pila">Pila</param>
        /// <param name="cola">Cola</param>
        /// <param name="datosUsuario">Array que almacena los datos del usuario</param>
        static void ConstruirEstructuras(ref Stack<DescripcionUbi> pila, ref Queue<DescripcionUbi> cola, ref DescripcionUbi[] datosUsuario)
        {
            // Se muestra el menú de construir estructuras
            switch (MenuConstruirEstructuras())
            {
                case 1: // Construir pila
                        // Se instancian una pila auxiliar
                    Stack<DescripcionUbi> pilaAux = new Stack<DescripcionUbi>();
                    // Array auxiliar para ordenar elementos
                    DescripcionUbi[] listaAuxiliar = new DescripcionUbi[50];
                    // Se insertan los elementos de forma inversa
                    for (int i = 0; i < datosUsuario.Length; i++)
                    {
                        AgregarPila(ref pilaAux, datosUsuario[i]);
                    }
                    // Se colocan los elementos ya ordenados en un array auxiliar
                    for (int i = 0; i < datosUsuario.Length; i++)
                    {
                        pilaAux.CopyTo(listaAuxiliar, 0);
                    }
                    for (int i = 0; i < datosUsuario.Length; i++)
                    {
                        AgregarPila(ref pila, listaAuxiliar[i]);
                    }

                    Console.WriteLine("\nPila construida correctamente");
                    break;
                case 2: // Construir colas
                        // Se insertan todos los elementos en la cola
                    for (int i = 0; i < datosUsuario.Length; i++)
                    {
                        AgregarCola(ref cola, datosUsuario[i]);
                    }
                    Console.WriteLine("\nCola construida correctamente");
                    break;
                default:
                    throw new Exception("Internal Error (Build option doesn´t exist)");
            }
        }

        /// <summary>
        /// Controla la lógica de visualizar las pilas y colas
        /// </summary>
        /// <param name="pila">Pila</param>
        /// <param name="cola">Cola</param>
        static void VisualizarEstructuras(Stack<DescripcionUbi> pila, Queue<DescripcionUbi> cola)
        {
            //Se muestra el menú de propio
            switch (MenuVisualizarEstructuras())
            {
                case 1: //Visualizar Pila
                    Console.Clear();
                    Console.WriteLine("\n\n\nVISUALIZAR ELEMENTOS PILAS");
                    Console.WriteLine("-----------------------------------");
                    ImprimirPila(pila);
                    break;
                case 2: //Visualizar cola
                    Console.Clear();
                    Console.WriteLine("\n\n\nVISUALIZAR ELEMENTOS COLAS");
                    Console.WriteLine("-----------------------------------");
                    ImprimirCola(cola);
                    break;
                default:
                    throw new Exception("Internal Error (Build option doesn´t exist)");
            }
        }

        /// <summary>
        /// Controla la lógica de extraer nombres que comiencen por una letra de la pila
        /// </summary>
        /// <param name="pila">Pila</param>
        static void ExtraerPila(ref Stack<DescripcionUbi> pila)
        {
            // Se declara una variable de control y otra que guarde el número de nombres eliminados
            bool control = true;
            int deletedNames;
            //Se pide al usuario que indique la letra
            char letra;
            do
            {
                Console.Write("\nIndique la letra inicial de los nombres a extraer => ");
                if (char.TryParse(Console.ReadLine(), out letra))
                {
                    deletedNames = ExtraerElemNomP(letra, ref pila);
                    Console.WriteLine("\n----------------------------------------------");
                    Console.WriteLine("Se han eliminado " + deletedNames + " nombres.");
                    Console.WriteLine("----------------------------------------------");
                    control = true;
                }
                else
                {
                    Console.WriteLine("El valor introducido debe ser un único carácter");
                    control = false;
                }
            } while (!control);
        }

        /// <summary>
        /// Controla la lógica de extraer nombres que comiencen por una letra de la cola
        /// </summary>
        /// <param name="cola">Cola</param>
        static void ExtraerCola(ref Queue<DescripcionUbi> cola)
        {
            // Se declara una variable de control y otra que guarde el número de nombres eliminados
            bool control = true;
            int deletedNames;
            //Se pide al usuario que indique la letra
            char letra;
            do
            {
                Console.Write("\nIndique la letra inicial de los nombres a extraer => ");
                if (char.TryParse(Console.ReadLine(), out letra))
                {
                    deletedNames = ExtraerElemNomC(letra, ref cola);
                    Console.WriteLine("\n----------------------------------------------");
                    Console.WriteLine("Se han eliminado " + deletedNames + " nombres.");
                    Console.WriteLine("----------------------------------------------");
                    control = true;
                }
                else
                {
                    Console.WriteLine("El valor introducido debe ser un único carácter");
                    control = false;
                }
            } while (!control);
        }

        /// <summary>
        /// Pide al usuario que pulse la tecla enter para continuar.
        /// </summary>
        /// <param name="limpiar">
        /// Entero que representa si se desea limpiar (1) la consola
        /// antes de mostrar el texto.
        /// </param>
        public static void Continuar()
        {
            Console.WriteLine("\nPulse Enter para continuar:");


            while (Console.ReadKey().Key != ConsoleKey.Enter) { }
            Console.Clear();
        }
    }
}
