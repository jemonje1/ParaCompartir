#include "Prestamo.h"
#include <iostream>
using namespace std;
Prestamo::Prestamo(int id, string cliente, string banco, string tipo, double cantidad, double intereses)
    : ID(id), nombreCliente(cliente), nombreBanco(banco), tipoPrestamo(tipo), cantidadInicial(cantidad), interes(intereses) {}

Prestamo::~Prestamo() {
}

void Prestamo::mostrarPrestamo() {
    cout << "Cliente: " << nombreCliente << endl;
    cout << "Banco: " << nombreBanco << endl;
    cout << "Tipo de prestamo: " << tipoPrestamo << endl;
    cout << "Cantidad inicial: " << cantidadInicial << endl;
}

void Prestamo::mostrarInteres() {
    cout << "------------------------------------";
    cout << "Interes del prestamo: " << interes << endl;
    cout << "------------------------------------";
}
