#include "Prestamo.h"
#include <iostream>
using namespace std;

Prestamo::Prestamo(int id, string cliente, string banco, string tipo, double cantidad, double intereses)
    : ID(id), nombreCliente(cliente), nombreBanco(banco), tipoPrestamo(tipo), cantidadInicial(cantidad), interes(intereses){
}

Prestamo::~Prestamo() {
}

void Prestamo::mostrarPrestamo() {
    cout << "Cliente: " << nombreCliente << endl;
    cout << "Banco: " << nombreBanco << endl;
    cout << "Tipo de prestamo: " << tipoPrestamo << endl;
    cout << "Cantidad inicial: " << cantidadInicial << endl;
}

void Prestamo::mostrarInteres() {
    cout << "------------------------------------" << endl;
    cout << "Prestamo de ID: " << ID << endl;
    cout << "Interes del prestamo: " << interes << endl;
    cout << "------------------------------------" << endl;
}

void Prestamo::registrarInteres() {
    cout << "------------------------------------" << endl;
    cout << "Prestamo de ID: " << ID << endl;
    cout << "Interes del prestamo: " << interes << endl;
}

void Prestamo::mostrarID() {
    cout << "------------------------------------" << endl;
    cout << "ID de prestamo: " << ID << endl;
    cout << "Nombre del cliente: " << nombreCliente << endl;
    cout << "------------------------------------" << endl;
}

void Prestamo::obtenernuevoID(int nuevoID) {
    ID = nuevoID;
}
