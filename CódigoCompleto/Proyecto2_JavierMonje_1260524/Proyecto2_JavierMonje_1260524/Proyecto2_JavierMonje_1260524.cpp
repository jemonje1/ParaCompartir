//Universidad Rafael Landívar - Programacion Avanzada - Proyecto 02 -  Serpientes y Escaleras - Javier Monje

//Los comentarios son la documentacion interna del proyecto

//librerias y directiva a utilizar, el uso de cada una se justifica en el documento escrito adjunto

/*Para evitar problemas en el proyecto enviado, se comentaron las funciones relacionadas a la música del juego para su correcta
compilación y ejecución, estas funcionalidades en la música serán exclusivas para mostrar en la presentación del proyecto,
cabe destacar que la lógica del juego se mantiene totalmente igual*/

#pragma comment(lib, "winmm.lib")
#include <iostream> 
#include <sstream>
#include <random>
#include <time.h>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include <Windows.h>
#include <MMsystem.h>
//Clases creadas
#include "Jugador.h" 
#include "Casilla.h"
#include "Dado.h"
#include "ListaJugadores.h"
#include "Tablero.h"
#include "PilaGanadores.h"
//definiciones para agregar color
#define RESET     "\033[0m"       // Blanco
#define RED       "\033[31m"      // Rojo
#define BRIGHT_RED     "\033[91m"   // Rojo clarito
#define BLUE      "\033[34m"      // Azul
#define BRIGHT_CYAN    "\033[96m"  //Cian clarito
#define CYAN      "\033[36m"      // Cian
#define BOLD_YELLOW   "\033[1m\033[33m"  // Amarillo claro
#define SUPERWHITE      "\033[97m"  //Blanco Claro
#define BRIGHT_MAGENTA "\033[95m"   //Magenta claro

using namespace std;

//prototipos de funciones
void bienvenida();
void menuEscrito();
void mostrarInstrucciones();
void solicitudTablero();
void solicitudJugadores();
void juego(Tablero tablero);
void mostrarMenuJugador();
void tiempo();
void tiempoDos();
int opciones;
void mostrarPos(Tablero tablero, Jugador jugador);
void caerCasilla(Tablero& tablero, Jugador& jugador);
void validarEntrada(int& numero);

//instancias a objetos
ListaJugadores lista;
Dado dado;
PilaGanadores pila;

int main()
{
    cout << "Cargando\n" << endl;
    cout << ".";
    //las funciones con thread y chrono hacen una breve pausa n segundos en la consola, esto para hacer el programa mas intuitivo
    cout << ".";
    this_thread::sleep_for(chrono::seconds(2));
    this_thread::sleep_for(chrono::seconds(1));
    cout << ".\n" << endl;
    cout << CYAN << "Carga completa\n\n" << RESET << endl;
    cout << "Presione ENTER para entrar" << endl;
    cin.get();
    bool salida = true;
    string mensajeDespedida = "\nMuchas gracias por haber jugado\n";
    do {
        lista.vaciarLista(); //Se vacia la lista para poder realizar varias partidas
        cout << "\n" << endl;
        bienvenida();
        //llamada al menu de opciones
        menuEscrito();
        cin >> opciones;
        validarEntrada(opciones);
        switch (opciones)
        {
        case 1:
            PlaySound(NULL, NULL, 0); //Apaga la musica que este sonando
            cout << "Cargando\n" << endl;
            cout << ".";
            this_thread::sleep_for(chrono::seconds(2));
            cout << ".";
            this_thread::sleep_for(chrono::seconds(1));
            cout << ".\n" << endl;
            cout << CYAN<< "Carga completa\n\n" <<RESET<< endl;
            //Llamada a un archivo de musica
            PlaySound(TEXT("C:\\Users\\javu2\\Downloads\\plants-vs-zombies-2.wav"), NULL, SND_ASYNC | SND_LOOP); 
            cout << CYAN << "-_-_-_-_-_-_-_-_-_-_- Configuracion inicial -_-_-_-_-_-_-_-_-_-_-" <<RESET<< endl;
            solicitudJugadores();
            cout << CYAN << "-_-_-_-_-_-_-_-_-_-_- Configuracion de tablero -_-_-_-_-_-_-_-_-_-_-" << RESET<<endl;
            solicitudTablero();
            break;
        case 2:
            mostrarInstrucciones();
            break;
        case 3:
            if (pila.isEmpty()) {
                cout << "\nNo hay ganadores registrados\nRegresando...\n" << endl; //si no han habido ganadores, se retorna este mensaje
            }
            else {
                bool mostrarJugador = true;
                while (mostrarJugador) {
                    cout << "Desea mostrar al ultimo ganador registrado?\n1. Si\n2. No\n" << endl;
                    int opcionesMostrar;
                    cin >> opcionesMostrar;
                    switch (opcionesMostrar) {
                    case 1:
                        if (pila.isEmpty()) {
                            cout << "No hay mas ganadores guardados. Presione 2 para regresar al menu inicial" << endl;
                        }
                        else {
                            pila.pop().mostrarGanador(); //por cada vez que se llame a esta funcion, retornara un ganador de la pila
                        };
                        break;
                    case 2:
                        cout << "Regresando . . .\n" << endl;
                        mostrarJugador = false;
                        break;
                    default:
                        cout << "Por favor, elija una opcion valida" << endl;
                        break;
                    }
                };
            };
            break;
        case 4:
            for (char c : mensajeDespedida) { //Da una despedida y finaliza el programa
                cout << CYAN << c << flush;
                tiempo();
            }; 
            tiempo();
            cout << RESET<<"\nVaciando memoria\n" << endl;
            pila.deleteStack();
            tiempoDos();
            cout << ".";
            tiempo();
            cout << ".";
            tiempo();
            cout << "." << endl;;
            salida = false;
            break;
        default:
            cout << "Opcion inexistente, recargando" << endl;
            break;
        }
    } while (salida);
    return 0;
};

void menuEscrito() { //Esta funcion muestra el menu inicial del juego, las definiciones son para colocarle color al texto
    cout << CYAN<< "\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-"<<RESET << endl;
    cout << "Bienvenidos a";
    cout << BRIGHT_CYAN << " serpientes y escaleras " << BRIGHT_RED<<"V2.2"<< RESET << endl;
    cout << "Elija la opcion que desee realizar" << endl;
    cout << "1. Jugar" << endl;
    cout << "2. Acerca de" << endl;
    cout << "3. Historial de ganadores" << endl;
    cout << "4. Salir" << endl;
    cout << CYAN<<"-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n" << RESET<<endl;
};


void solicitudJugadores() { //Esta funcion, solicita cuantos jugadores se quieren en la partida
    int numeroJugadores;
    do {
        cout << "Ingrese el numero de jugadores con los que quiera jugar"<<CYAN<<" deben jugar al menos dos jugadores"<<RESET<<"\n" << endl;
        cin >> numeroJugadores;
        validarEntrada(numeroJugadores);
    } while (numeroJugadores < 2); //validacion para siempre pedir mas de 1 jugador
    for (int i = 0; i < numeroJugadores; i++) {
        string nombreJugador;
        cout << "Ingrese el nombre del jugador No. " << i + 1 << endl;
        cin >> nombreJugador;
        int posicionJugador = 1;
        int numeroJugador = i + 1;
        //se crea el objeto jugador, y se inicializa la posicion, y el id del jugador
        Jugador jugador(nombreJugador, posicionJugador, numeroJugador); 
        lista.agregarJugador(jugador); //manda al jugador creado a la lista circular
        cout << "Jugador No. " << i + 1 << " anadido con exito"<< endl;
        cout << "\n";
    }
};

void solicitudTablero() {
    int filas;
    //Dado a las condiciones solicitadas, las columnas del tablero siempre seran 6, es por eso que se inicializan de esta manera
    int columnas = 6;
    Casilla** Matriz; //Creacion de un arreglo bidimencional tipo matriz
    int numeroCasillas;
    do {
        cout << "Ingrese el numero de casillas con las que quiera jugar" << CYAN " (mayor o igual a 30 y multiplo de 6)" << RESET <<endl;
        cin >> numeroCasillas;
        validarEntrada(numeroCasillas);
        //Validacion para que siempre se elija un numero de casillas de 30 a mas, y que este numero se multiplo de 6
    } while (numeroCasillas < 30 || numeroCasillas % 6 != 0);
    filas = numeroCasillas / columnas; // se calculan las filas

    Matriz = new Casilla * [filas]; //Se crea la matriz con las filas con casillas creadas

    for (int i = 0; i < filas; i++){
        Matriz[i] = new Casilla[columnas]; //Se crean las columnas con casillas
    }

    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            Matriz[i][j] = Casilla((i * columnas + j)+1, 0, 0); //Se crean objetos casilla recorriendo la matriz
        }
    }
    Tablero tablero(numeroCasillas,filas,columnas,Matriz); //Con la matriz creada, se crea el objeto tablero
    tablero.setCasillasEspeciales(); //Llamada a la funcion que aleatoriza todas las casillas que seran serpientes y escaleras
    cout << "Disenando su tablero . . ." << endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout << ".\n" << endl;
    cout << "Tablero creado con exito!" << endl;
    juego(tablero); //Llamada al juego, mandando como parametro el tablero creado
};

void juego(Tablero tablero) { //funcion con la logica del juego
    int turno = 1;
    int index = 0; //se inicia el indice en 0 para apuntar al primer jugador
    bool partida = true; //variable para mantener la partida hasta que alguien gane
    PlaySound(NULL, NULL, 0);
    cout << "Preparando a los jugadores\n" << endl;
    cout << ".";
    this_thread::sleep_for(chrono::seconds(2));
    cout << ".";
    this_thread::sleep_for(chrono::seconds(1));
    cout << ".\n" << endl;
    cout << CYAN<< "Carga completa\n\n" << RESET<<endl;
    tiempo();
    PlaySound(TEXT("C:\\Users\\javu2\\Downloads\\sugary-spire-ost-2nd-lap-theme.wav"), NULL, SND_ASYNC | SND_LOOP); //Más música
    cout << "Jugadores en el inicio" << endl;
    tiempo();
    cout << "." << endl;
    tiempoDos();
    cout << "En sus marcas" << endl;
    tiempo();
    cout << "." << endl;
    tiempoDos();
    cout << "listos?" << endl;
    tiempo();
    cout << "." << endl;
    tiempoDos();
    cout <<BRIGHT_RED<< "Jueguen!" <<RESET <<endl;
    tiempo();
    while (partida) { //entrando aqui, se inicia al juego
        tiempo();
        cout << "\n----------------------------------------------" << endl;
        cout << "Turno No. " << turno << endl; //Se mantiene un conteo de los turnos
        cout << "----------------------------------------------" << endl;
        Jugador& jugadorActual = lista.mostrarJugador(index); //Se crea una instancia del jugador actual guardado en la lista
        string Preparate = "Preparate " + jugadorActual.getNombre();
        for (char c : Preparate) {
            cout << c << flush;
            this_thread::sleep_for(chrono::milliseconds(50));
        }
        tiempo();
        tiempo();
        tiempo();
        cout <<RESET<< "\n----------------------------------------------\n" << endl;
        cout << SUPERWHITE << "Tablero de: " << jugadorActual.getNombre() << RESET <<"\n" << endl;
        mostrarPos(tablero, jugadorActual); //Muestra el tablero
        bool turnoActivo = true; //Mantiene el turno del jugador para que pueda navegar en el submenu de juego
        while (turnoActivo) {
            cout << "----------------------------------------------" << endl;
            cout << "Turno de: " << BRIGHT_CYAN << jugadorActual.getNombre() << RESET << endl;
            mostrarMenuJugador(); //funcion de submenu del juego
            int opcionesJugador;
            cin >> opcionesJugador;
            validarEntrada(opcionesJugador);
            switch (opcionesJugador) {
            case 1: {
                for (char c : jugadorActual.getNombre()) { //breve animacion al mostrar el nombre del jugador
                    cout << c << flush;
                    this_thread::sleep_for(chrono::milliseconds(50));
                };
                cout << " tira el dado..." << endl;
                int lanzarDado = dado.tirarDado();
                int nuevaPos = jugadorActual.getPos() + lanzarDado; //Calculo de a donde se movera el jugador
                tiempo();
                cout << "Sacaste un " << lanzarDado << endl;
                if (nuevaPos == tablero.getNumeroCasillas()) { //Condicion que obtiene al ganador si este cae en la ultima casilla
                    PlaySound(NULL, NULL, 0);
                    cout << BRIGHT_RED << ":O, algo ha pasado" << RESET << endl;
                    tiempoDos();
                    cout << "." << endl;
                    tiempo();
                    cout << "." << endl;
                    tiempo();
                    cout << "." << endl;
                    tiempoDos();
                    PlaySound(TEXT("C:\\Users\\javu2\\Downloads\\httpswwwyoutubecomwatchvfys93ke6zc.wav"), NULL, SND_ASYNC | SND_LOOP);
                    tiempo();
                    cout << BRIGHT_CYAN << "Felicidades! " << RESET;
                    for (char c : jugadorActual.getNombre()) {
                        cout << c << flush;
                        tiempo();
                    };
                    cout << endl;
                    tiempoDos();
                    cout << "Llegaste a la meta!" << endl;
                    tiempo();
                    cout << "La partida duro " << turno << " turnos" << endl;
                    tiempoDos();
                    cout << "\nTarjeta de ganador: \n" << endl;
                    jugadorActual.mostrarGanador(); //Muestra al ganador
                    cout << "Presiona ENTER para aceptar" << endl;
                    cin.ignore();
                    cin.get();
                    pila.push(jugadorActual);//Guarda al jugador que haya ganado en la pila de los ganadores
                    cout << "Registrando ganador" << endl;
                    cout << ".";
                    this_thread::sleep_for(chrono::seconds(1));
                    cout << ".";
                    this_thread::sleep_for(chrono::seconds(1));
                    cout << ".\n" << endl;
                    cout << CYAN << "Guardado completado\n\n" << RESET << endl;
                    PlaySound(NULL, NULL, 0);
                    tablero.vaciarTablero();
                    partida = false; //Finalizacion del turno y de la partida
                    turnoActivo = false;
                }
                else if (nuevaPos > tablero.getNumeroCasillas()) { //logica si el jugador sobrepasa el valor de la ultima casilla
                    int diferencia = nuevaPos - tablero.getNumeroCasillas();
                    cout << "Te pasaste por " << diferencia << ", vuelves a la posicion inicial del turno" << endl;
                    //Al nunca haber un set en la posicion, el jugador se queda donde esta
                    tiempo();
                    tiempo();
                    tiempo();
                    cout << SUPERWHITE << "\nTablero de: " << jugadorActual.getNombre() << RESET << "\n" << endl;
                    mostrarPos(tablero, jugadorActual);
                    tiempoDos();
                }
                else {
                    cout << "avanzas a la casilla " << nuevaPos << " del tablero" << endl; //mueve al jugador y le pone un nuevo valor a su posicion
                    jugadorActual.setPos(nuevaPos);
                    caerCasilla(tablero, jugadorActual); //Validacion si el jugador cae en una serpiente o en una escalera
                    tiempo();
                    tiempo();
                    tiempo();
                    cout << SUPERWHITE << "\nTablero de: " << jugadorActual.getNombre() << RESET << "\n" << endl;
                    mostrarPos(tablero, jugadorActual);
                    tiempoDos(); //Da un breve tiempo para que el jugador lea bien lo que ocurre
                    tiempo();
                }
                turnoActivo = false;
                break;
            }
            case 2:
                cout << CYAN << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << RESET << endl;
                cout << jugadorActual.getNombre() <<" estas en la posicion: " << jugadorActual.getPos() << " de " << tablero.getNumeroCasillas() << endl;
                cout << CYAN << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n" << RESET <<endl;
                mostrarPos(tablero, jugadorActual); //Muestra el tablero
                break;
            case 3:
                cout << BLUE << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << RESET << endl;
                lista.mostrarLista(); //Muestra a los jugadores y a sus posiciones
                cout << BLUE << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << RESET << endl;
                break;
            default:
                cout << "Opcion invalida. Intenta de nuevo." << endl; //Validacion para ingresar opciones validas
                break;
            }
        }
        turno++;
    }
};

void mostrarInstrucciones() { //Funcion que muestra las instrucciones
    cout << "\n";
    cout << BOLD_YELLOW <<"-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
    cout << "Serpientes y escaleras V2.2\n" << endl;
    cout << "Como jugar?\n" << endl;
    cout << "Bienvenido al juego!\n\nPara iniciar un juego elija la opcion '1' del menu\n\nSe le solicitara la cantidad de jugadores"
        << " que quiera en su partida\n\nIngrese la cantidad y el nombre de cada jugador\n\n"
        << "Una vez con los jugadores listos, ingrese la cantidad de casillas que quiera en su tablero\n\n" <<
        "OJO:" << "la cantidad de casillas debe ser un multiplo de 6 y mayor a 36 :D\n\n" <<
        "Para el tablero: \n\n" <<
        "La casilla de tu posicion se mostrara de color magenta!: ";
    cout << BRIGHT_MAGENTA << "[N]" << BOLD_YELLOW << endl;
    cout << "La casilla de serpientes se mostrara de color rojo!: ";
    cout << RED << "[N]" << BOLD_YELLOW << endl;
    cout << "La casilla de escaleras se mostrara de color azul!: ";
    cout << BLUE << "[N]" << BOLD_YELLOW << endl;
    cout << "\nLas casillas especiales tendran una flecha que indiquen a donde te llevaran!" << BLUE << "[N -> U]" << BOLD_YELLOW << endl;
        cout << BOLD_YELLOW << "Con todo listo, el juego iniciara y podra jugar!"<< endl;
    cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n" << endl;
    cout << BRIGHT_CYAN<< "Presione ENTER para regresar" << RESET<<endl;
    cin.ignore();
    cin.get();
}

void mostrarMenuJugador() { //Funcion que muestra el menu de opciones durante la partida
    cout << "----------------------------------------------" << endl;
    cout << "Elije la opcion que quieras hacer:" << endl;
    cout << "1. Tirar Dado\n2. Ver tu posicion\n3. Ver otros jugadores"<<endl;
    cout << "----------------------------------------------\n" << endl;
}

//Las funciones tiempo, utilizan thread y chrono para hacer pausas en el programa, estas son usadas para hacer el programa mas intuitivo
void tiempo() {
    this_thread::sleep_for(chrono::milliseconds(100));
}

void tiempoDos() {
    this_thread::sleep_for(chrono::seconds(2));
}


void mostrarPos(Tablero tablero, Jugador jugador) { //Logica que muestra la matriz del juego, se muestra de abajo hacia arriba
    for (int i = tablero.getfilas() - 1; i >= 0; i--) {
        for (int j = 0; j < tablero.getcolumnas(); j++) {
            switch (tablero.getTablero()[i][j].getTipo()) {
            case 0:
                if (tablero.getTablero()[i][j].getnumeroCasilla() == jugador.getPos()) { //Esta condicion muestra la posicion del jugador
                    cout << BRIGHT_MAGENTA<< "[ " << tablero.getTablero()[i][j].getnumeroCasilla() << " ]" << RESET;
                }
                else { //Esta condicion mostrara las casillas normales
                    cout << RESET << "[ " << tablero.getTablero()[i][j].getnumeroCasilla() << " ]" << RESET;
                };
                break;
            case 1: //Esta condicion muestra las escalerasn y a donde te llevan
                cout << BLUE "[E" << tablero.getTablero()[i][j].getnumeroCasilla() << "->"<<tablero.getTablero()[i][j].getFin()<<"]" << RESET;
                break;
            case 2: //Esta condicion muestra las serpientes y a donde te llevan
                cout << RED << "[S" << tablero.getTablero()[i][j].getnumeroCasilla() << "->" << tablero.getTablero()[i][j].getFin() << "]" << RESET;
                break;
            }
        }
        cout << "\n" << endl;
    }
};

void bienvenida() { //Funcion con una breve animacion al inicio y coloca la musica
    PlaySound(TEXT("C:\\Users\\javu2\\Downloads\\01-prologue.wav"), NULL, SND_ASYNC | SND_LOOP);
    tiempo();
    tiempo();
    tiempo();
    cout << "B";
    tiempo();
    cout << "i";
    tiempo();
    cout << "e";
    tiempo();
    cout << "n";
    tiempo();
    cout << "v";
    tiempo();
    cout << "e";
    tiempo();
    cout << "n";
    tiempo();
    cout << "i";
    tiempo();
    cout << "d";
    tiempo();
    cout << "o" << endl;
    tiempoDos();
}

void caerCasilla(Tablero& tablero, Jugador& jugador) { //Logica si se cae a una serpiente o a una escalera
    for (int i = 0; i < tablero.getfilas(); i++) { //Se itera la matriz para buscar coincidencias
        for (int j = 0; j < tablero.getcolumnas(); j++) {
            if (tablero.getTablero()[i][j].getTipo() == 2 && jugador.getPos()==tablero.getTablero()[i][j].getnumeroCasilla()) {
                jugador.setPos(tablero.getTablero()[i][j].getFin());
                cout << "\nParece que has caido en una serpiente!" << endl;
                cout << "Te mueves a: " << jugador.getPos() << endl;
                tiempo();
                tiempo();
                tiempo();
                caerCasilla(tablero, jugador); //Recursion para evaluar si la serpiente llevó a alguna otra casilla especial
            }
            if (tablero.getTablero()[i][j].getTipo() == 1 && jugador.getPos() == tablero.getTablero()[i][j].getnumeroCasilla()) {
                jugador.setPos(tablero.getTablero()[i][j].getFin());
                cout << "\nParece que has caido en una escalera!" << endl;
                cout << "Te mueves a: " << jugador.getPos() << endl;
                tiempo();
                tiempo();
                tiempo();
                caerCasilla(tablero, jugador);//Recursion para evaluar si la escalera llevó a alguna otra casilla especial
            }
            else {
                cout << "";//Mantiene al jugador en la posicion que esta si  se encuentra en una casilla normal
            };
        }
    }
};   

void validarEntrada(int& numero) {
    while (true) {
        numero;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << BOLD_YELLOW<<"\n\nEntrada invalida. Por favor, ingrese un numero entero.\n" << RESET<<endl;
        }
        else {
            break;
        }
    }
}