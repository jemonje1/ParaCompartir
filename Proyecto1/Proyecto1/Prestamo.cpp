#include "Prestamo.h"
#include <iostream>
using namespace std;

Prestamo::Prestamo(int id, string cliente, string banco, string tipo, double cantidad, double cantidadfija, double intereses)
    : ID(id), nombreCliente(cliente), nombreBanco(banco), tipoPrestamo(tipo), cantidadInicial(cantidad), cantidadFija(cantidadfija), interes(intereses), cantidadAbonos(0), capacidadAbonos(10) {
    historialAbonos = new double[capacidadAbonos];
}

Prestamo::~Prestamo() {
}

void Prestamo::mostrarPrestamo() {
    cout << "Cliente: " << nombreCliente << endl;
    cout << "Banco: " << nombreBanco << endl;
    cout << "Tipo de prestamo: " << tipoPrestamo << endl;
    cout << "Cantidad ingresada: Q. " << cantidadInicial << endl;
    cout << "Cantidad antes de abonos: Q."<<cantidadFija << endl;
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

void Prestamo::abonarPrestamo(double cantidadAbono) {
    if (cantidadAbonos == capacidadAbonos) {
        capacidadAbonos *= 2;
        double* nuevoHistorial = new double[capacidadAbonos];
        for (int i = 0; i < cantidadAbonos; ++i) {
            nuevoHistorial[i] = historialAbonos[i];
        }
        delete[] historialAbonos;
        historialAbonos = nuevoHistorial;
    }
    historialAbonos[cantidadAbonos++] = cantidadAbono;
    cantidadInicial -= cantidadAbono;
    calcularPrestamo(); 
}

void Prestamo::mostrarHistorialAbonos() {
    cout << "Historial de abonos del prestamo ID " << ID << ":" << endl;
    for (int i = 0; i < cantidadAbonos; ++i) {
        cout << "Abono " << (i + 1) << ": Q." << historialAbonos[i] << endl;
    }
}