/*Proyecto 01 Programación Avanzada
Grupo formado por:
Daniel Zepeda | 1265824
Javier Enrique Monje Pérez | 1260524*/

#include <iostream>
#include "Prestamo.h"
#include "PrestamoPersonal.h"
#include "PrestamoHipotecario.h"
#include "PrestamosAutomoviles.h"
#include <ctime>

using namespace std;

bool Salida = true;
int numeroPrestamos;
Prestamo** prestamos;
int posicion = 0;
string nombreBanco;

void mostrarMenu();
void mostrarMenuVerPrestamos();
void pedirPrestamos();
void mostrarPrestamo();
void agregarPrestamoPersonal(Prestamo** prestamos, int& localizacion);
void agregarPrestamoHipotecario(Prestamo** prestamos, int& localizacion);
void agregarPrestamoAutomovil(Prestamo** prestamos, int& localizacion);
void calcularInteresYMostrar();

int main() {
    cout << "Bienvenido al sistema de gestión de préstamos" << endl;
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
    cout << "a) Agregar un nuevo préstamo\nb) Eliminar un préstamo existente\nc) Ver un préstamo\nd) Mostrar todos los préstamos\ne) Calcular y mostrar el interés de cada préstamo\nf) Salir" << endl;
    char opciones;
    cin >> opciones;
    switch (opciones) {
    case 'a':
        cout << "Ingrese el tipo de préstamo a agregar:\n1) Personal\n2) Hipotecario\n3) Automóvil" << endl;
        char tipo;
        cin >> tipo;
        switch (tipo) {
        case '1':
            if (posicion < numeroPrestamos) {
                agregarPrestamoPersonal(prestamos, posicion);
            }
            else {
                cout << "No hay espacio para agregar más préstamos personales." << endl;
            }
            break;
        case '2':
            if (posicion < numeroPrestamos) {
                agregarPrestamoHipotecario(prestamos, posicion);
            }
            else {
                cout << "No hay espacio para agregar más préstamos hipotecarios." << endl;
            }
            break;
        case '3':
            if (posicion < numeroPrestamos) {
                agregarPrestamoAutomovil(prestamos, posicion);
            }
            else {
                cout << "No hay espacio para agregar más préstamos de automóviles." << endl;
            }
            break;
        default:
            cout << "Opción no válida." << endl;
        }
        break;
    case 'b':
        // Implementar eliminación
        break;
    case 'c':
        mostrarMenuVerPrestamos();
        break;
    case 'd':
        mostrarPrestamo();
        break;
    case 'e':
        calcularInteresYMostrar();
        break;
    case 'f':
        cout << "Gracias por usar nuestros servicios" << endl;
        cout << "Cerrando sesión . . ." << endl;
        Salida = false;
        break;
    default:
        cout << "La opción que eligió no es válida" << endl;
    }
}

void mostrarMenuVerPrestamos() {
    cout << "---------------------------------------------\nMenu de Ver Préstamos\n---------------------------------------------" << endl;
    cout << "a) Ver información del préstamo\nb) Calcular y mostrar intereses\nc) Registrar pago de intereses\nd) Abono al saldo del préstamo" << endl;
    char opciones2;
    cin >> opciones2;
    switch (opciones2) {
    case 'a':
        mostrarPrestamo();
        break;
    case 'b':
        calcularInteresYMostrar();
        break;
    case 'c':
        // Implementar registro de pago de intereses
        break;
    case 'd':
        // Implementar abono al saldo del préstamo 
        break;
    default:
        cout << "Opción no válida." << endl;
    }
}

void pedirPrestamos() {
    cout << "---------------------------------------------" << endl;
    cout << "Ingrese el número de préstamos que quiera ingresar: " << endl;
    cin >> numeroPrestamos;

    prestamos = new Prestamo * [numeroPrestamos];
}

void mostrarPrestamo() {
    cout << "------------------------\nLista de préstamos:\n------------------------" << endl;
    for (int i = 0; i < posicion; ++i) {
        prestamos[i]->mostrarPrestamo();
    }
}

void agregarPrestamoPersonal(Prestamo** prestamos, int& localizacion) {
    cout << "Ha ingresado un préstamo personal" << endl;
    cout << "Ingrese un nombre: " << endl;
    string Nombre;
    cin >> Nombre;
    string Tipo = "Préstamo Personal";
    cout << "Ingrese la cantidad inicial" << endl;
    double cantidadInicial;
    cin >> cantidadInicial;
    cout << "Fecha Actual (en segundos desde el Epoch): " << endl;
    time_t fechaActual;
    cin >> fechaActual;
    double tasaInteresAnual;
    int diasTranscurridos;
    cout << "Ingrese la tasa de interés anual: " << endl;
    cin >> tasaInteresAnual;
    cout << "Ingrese los días transcurridos: " << endl;
    cin >> diasTranscurridos;

    PrestamoPersonal* nuevoPrestamo = new PrestamoPersonal(Nombre, nombreBanco, Tipo, cantidadInicial, fechaActual, tasaInteresAnual, diasTranscurridos);
    nuevoPrestamo->calcularInteres();
    nuevoPrestamo->calcularPrestamo();

    prestamos[localizacion] = nuevoPrestamo;
    ++localizacion;

    cout << "Préstamo Personal Agregado!" << endl;
}

void agregarPrestamoHipotecario(Prestamo** prestamos, int& localizacion) {
    cout << "Ha ingresado un préstamo hipotecario" << endl;
    cout << "Ingrese un nombre: " << endl;
    string Nombre;
    cin >> Nombre;
    string Tipo = "Préstamo Hipotecario";
    cout << "Ingrese la cantidad inicial" << endl;
    double cantidadInicial;
    cin >> cantidadInicial;
    cout << "Fecha Actual (en segundos desde el Epoch): " << endl;
    time_t fechaActual;
    cin >> fechaActual;
    double diferencial;
    cout << "Ingrese el diferencial: " << endl;
    cin >> diferencial;

    PrestamoHipotecario* nuevoPrestamo = new PrestamoHipotecario(Nombre, nombreBanco, Tipo, cantidadInicial, fechaActual, diferencial);
    nuevoPrestamo->calcularInteres();
    nuevoPrestamo->calcularPrestamo();

    prestamos[localizacion] = nuevoPrestamo;
    ++localizacion;

    cout << "Préstamo Hipotecario Agregado!" << endl;
}

void agregarPrestamoAutomovil(Prestamo** prestamos, int& localizacion) {
    cout << "Ha ingresado un préstamo de automóviles" << endl;
    cout << "Ingrese un nombre: " << endl;
    string Nombre;
    cin >> Nombre;
    string Tipo = "Préstamo Automóvil";
    cout << "Ingrese la cantidad inicial" << endl;
    double cantidadInicial;
    cin >> cantidadInicial;
    cout << "Fecha Actual (en segundos desde el Epoch): " << endl;
    time_t fechaActual;
    cin >> fechaActual;
    double tasaInteresMensual;
    int plazoMeses;
    cout << "Ingrese la tasa de interés mensual: " << endl;
    cin >> tasaInteresMensual;
    cout << "Ingrese el plazo en meses: " << endl;
    cin >> plazoMeses;

    PrestamosAutomoviles* nuevoPrestamo = new PrestamosAutomoviles(Nombre, nombreBanco, Tipo, cantidadInicial, fechaActual, tasaInteresMensual, plazoMeses);
    nuevoPrestamo->calcularInteres();
    nuevoPrestamo->calcularPrestamo();

    prestamos[localizacion] = nuevoPrestamo;
    ++localizacion;

    cout << "Préstamo de Automóviles Agregado!" << endl;
}

void calcularInteresYMostrar() {
    cout << "Calculando y mostrando el interés de cada préstamo..." << endl;
    for (int i = 0; i < posicion; ++i) {
        prestamos[i]->calcularInteres();
        prestamos[i]->calcularPrestamo(); 
        prestamos[i]->mostrarPrestamo();
    }
}
