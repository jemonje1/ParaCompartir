/*Proyecto 01 Programación Avanzada
Grupo formado por:
Daniel Zepeda | 1265824
Javier Enrique Monje Pérez | 1260524*/

#include <iostream>
#include "Prestamo.h"
#include "PrestamoPersonal.h"
#include "PrestamoHipotecario.h"
#include "PrestamosAutomoviles.h"

using namespace std;

bool Salida = true;
int numeroPrestamos;
Prestamo** prestamos;
int posicion = 0;
string nombreBanco;

//Prototipos de funcion
void mostrarMenu();
void mostrarMenuVerPrestamos();
void pedirPrestamos();
void mostrarPrestamo();
void mostrarInteres();
void agregarPrestamoPersonal(Prestamo** prestamos, int& localizacion);
void agregarPrestamoHipotecario(Prestamo** prestamos, int& localizacion);
void agregarPrestamoAutomovil(Prestamo** prestamos, int& localizacion);
void mostrarUnPrestamo();
void mostrarUnInteres();
void registroInteres();
void mostrarID();
void eliminarPrestamo();
void abonarPrestamo();
void historialAbonos();


//MAIN CON LAS SOLICITUDES DE LA CLASE BANCO
int main() {
    cout << "Bienvenido al sistema de gestion de prestamos" << endl;
    cout << "Ingrese el nombre de su banco: " << endl;
    cin >> nombreBanco;
    cout << "Bienvenido Banco: " << nombreBanco << endl;
    pedirPrestamos();

    do {
        mostrarMenu();
    } while (Salida);

    for (int i = 0; i < posicion; ++i) {
        delete prestamos[i];
    }
    delete[] prestamos;

    return 0;
}

void mostrarMenu() {
    cout << "---------------------------------------------\nMenu de opciones\n---------------------------------------------" << endl;
    cout << "a) Agregar un nuevo prestamo\nb) Eliminar un prestamo existente\nc) Ver un prestamo\nd) Mostrar todos los prestamos\ne) Calcular y mostrar el interes de cada prestamo\nf) Ver ID de cada prestamo\ng) Salir" << endl;
    char opciones;
    cin >> opciones;
    switch (opciones) {
    case 'a':
        cout << "Ingrese el tipo de prestamo a agregar:\n1) Personal\n2) Hipotecario\n3) Automovil" << endl;
        char tipo;
        cin >> tipo;
        switch (tipo) {
        case '1':
            if (posicion < numeroPrestamos) {
                agregarPrestamoPersonal(prestamos, posicion);
            }
            else {
                cout << "No hay espacio para agregar más prestamos personales." << endl;
            }
            break;
        case '2':
            if (posicion < numeroPrestamos) {
                agregarPrestamoHipotecario(prestamos, posicion);
            }
            else {
                cout << "No hay espacio para agregar más prestamos hipotecarios." << endl;
            }
            break;
        case '3':
            if (posicion < numeroPrestamos) {
                agregarPrestamoAutomovil(prestamos, posicion);
            }
            else {
                cout << "No hay espacio para agregar más prestamos de automóviles." << endl;
            }
            break;
        default:
            cout << "Opción no válida." << endl;
        }
        break;
    case 'b':
        cout << "------------------------------ Eliminacion de prestamos ------------------------------" << endl;
        cout << "ADVERTENCIA: seguro que quiere eliminar un prestamo (no se podra recuperar la informacion y se eliminara el abono tambien)" << endl;
        cout << "a) Si, quiero borrar un prestamo\nb)No, quiero regresar al menu" << endl;
        char opciones3;
        cin >> opciones3;
        switch (opciones3) {
        case 'a':
            eliminarPrestamo();
            break;
        case 'b':
            cout << "Regresando al menu . . ." << endl;
            break;
        default: 
            cout << "Opcion invalida" << endl;
        }
    case 'c':
        mostrarMenuVerPrestamos();
        break;
    case 'd':
        mostrarPrestamo();
        break;
    case 'e':
        mostrarInteres();
        break;
    case 'f':
        mostrarID();
        break;
    case 'g':
        cout << "Gracias por usar nuestros servicios" << endl;
        cout << "Cerrando sesion . . ." << endl;
        Salida = false;
        break;
    default:
        cout << "La opcion que eligio no es valida" << endl;
        break;
    }
}

void mostrarMenuVerPrestamos() {
    cout << "---------------------------------------------\nMenu de Ver Prestamos\n---------------------------------------------" << endl;
    cout << "a) Ver informacion del prestamo\nb) Calcular y mostrar intereses\nc) Registrar pago de intereses\nd) Abono al saldo del prestamo\ne) Ver abonos"<< endl;
    char opciones2;
    cin >> opciones2;
    switch (opciones2) {
    case 'a':
        mostrarUnPrestamo();
        break;
    case 'b':
        mostrarUnInteres();
        break;
    case 'c':
        registroInteres();
        break;
    case 'd':
        abonarPrestamo();
        break;
    case 'e':
        historialAbonos();
        break;
    default:
        cout << "Opción no válida." << endl;
        break;
    }
}

void pedirPrestamos() {
    cout << "---------------------------------------------" << endl;
    cout << "Ingrese el numero de prestamos que quiera ingresar: " << endl;
    cin >> numeroPrestamos;

    prestamos = new Prestamo * [numeroPrestamos];
}

void mostrarPrestamo() {
    cout << "------------------------\nLista de prestamos:\n------------------------" << endl;
    for (int i = 0; i < posicion; ++i) {
        prestamos[i]->mostrarPrestamo();
    }
}



void agregarPrestamoPersonal(Prestamo** prestamos, int& localizacion) {
    int Identificador = localizacion+1;
    cout << "Ha ingresado un prestamo personal" << endl;
    cout << "Ingrese un nombre: " << endl;
    string Nombre;
    cin >> Nombre;
    string Tipo = "Prestamo Personal";
    cout << "Ingrese la cantidad inicial" << endl;
    double cantidadInicial;
    cin >> cantidadInicial;
    cout << "Ingrese los dias transcurridos desde que se solicito el prestamo: " << endl;
    int diasTranscurridos;
    cin >> diasTranscurridos;

    PrestamoPersonal* nuevoPrestamo = new PrestamoPersonal(Identificador, Nombre, nombreBanco, Tipo, cantidadInicial, cantidadInicial,0, diasTranscurridos);
    nuevoPrestamo->calcularPrestamo();

    prestamos[localizacion] = nuevoPrestamo;
    ++localizacion;

    cout << "Prestamo Personal Agregado!" << endl;
}

void agregarPrestamoHipotecario(Prestamo** prestamos, int& localizacion) {
    int Identificador = localizacion + 1;
    cout << "Ha ingresado un prestamo hipotecario" << endl;
    cout << "Ingrese un nombre: " << endl;
    string Nombre;
    cin >> Nombre;
    string Tipo = "Prestamo Hipotecario";
    cout << "Ingrese la cantidad inicial" << endl;
    double cantidadInicial;
    cin >> cantidadInicial;

    PrestamoHipotecario* nuevoPrestamo = new PrestamoHipotecario(Identificador, Nombre, nombreBanco, Tipo, cantidadInicial, cantidadInicial, 0);
    nuevoPrestamo->calcularPrestamo();

    prestamos[localizacion] = nuevoPrestamo;
    ++localizacion;

    cout << "Prestamo Hipotecario Agregado!" << endl;
}

void agregarPrestamoAutomovil(Prestamo** prestamos, int& localizacion) {
    int Identificador = localizacion + 1;
    cout << "Ha ingresado un préstamo de automoviles" << endl;
    cout << "Ingrese un nombre: " << endl;
    string Nombre;
    cin >> Nombre;
    string Tipo = "Prestamo Automovil";
    cout << "Ingrese la cantidad inicial" << endl;
    double cantidadInicial;
    cin >> cantidadInicial;
    cout << "Ingrese el plazo en meses: " << endl;
    int plazoMeses;
    cin >> plazoMeses;

    PrestamosAutomoviles* nuevoPrestamo = new PrestamosAutomoviles(Identificador, Nombre, nombreBanco, Tipo, cantidadInicial, cantidadInicial, 0.01175 / 12, plazoMeses);
    nuevoPrestamo->calcularPrestamo();

    prestamos[localizacion] = nuevoPrestamo;
    ++localizacion;

    cout << "Prestamo de Automoviles Agregado!" << endl;
}

void mostrarInteres() {
    cout << "------------------------\nLista de intereses:\n------------------------" << endl;
    for (int i = 0; i < posicion; ++i) {
        cout << "Prestamo: " << i + 1 << " ";
        prestamos[i]->mostrarInteres();
    }
}

void mostrarUnPrestamo() {
    cout << "Ingrese el ID del prestamo que quiere ver" << endl;
    int Identificador;
    cin >> Identificador;
    Identificador = Identificador - 1;
    prestamos[Identificador]->mostrarPrestamo();
}

void mostrarUnInteres() {
    cout << "Ingrese el ID del prestamo que quiera ver su interes" << endl;
    int Identificador;
    cin >> Identificador;
    Identificador = Identificador - 1;
    prestamos[Identificador]->mostrarInteres();
}
void registroInteres() {
    cout << "Ingrese el ID del prestamo que quiera ver su interes" << endl;
    int Identificador;
    cin >> Identificador;
    Identificador = Identificador - 1;
    prestamos[Identificador]->registrarInteres();
}

void mostrarID() {
    cout << "------------------------\nLista de prestamos:\n------------------------" << endl;
    for (int i = 0; i < posicion; ++i) {
        cout << "Prestamo: " << i + 1 << " ";
        prestamos[i]->mostrarID();
    }
}

void eliminarPrestamo() {
    cout << "Ingrese el ID del prestamo que desea eliminar: " << endl;
    int Identificador;
    cin >> Identificador;
    Identificador = Identificador - 1;
    if (Identificador < 0 || Identificador >= posicion) {
        cout << "ID de prestamo no valido." << endl;
        return;
    }
    delete prestamos[Identificador];
    for (int i = Identificador; i < posicion - 1; ++i) {
        prestamos[i] = prestamos[i + 1];
        prestamos[i]->obtenernuevoID(i + 1);
    }
    --posicion;
    cout << "Prestamo eliminado con exito!" << endl;
    cout << "Se han actualizado los ID de los prestamos" << endl;
}

void abonarPrestamo() {
    cout << "Ingrese el ID del prestamo al que desea abonar: " << endl;
    int idPrestamo;
    cin >> idPrestamo;
    idPrestamo--;
    cout << "Ingrese la cantidad a abonar: " << endl;
    double cantidadAbono;
    cin >> cantidadAbono;
    prestamos[idPrestamo]->abonarPrestamo(cantidadAbono);
    cout << "Abono realizado con éxito." << endl;
}

void historialAbonos() {
    cout << "Ingrese el ID del prestamo para ver su historial de abonos: " << endl;
    int idPrestamoHistorial;
    cin >> idPrestamoHistorial;
    idPrestamoHistorial--;
    prestamos[idPrestamoHistorial]->mostrarHistorialAbonos();
}