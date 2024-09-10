#include "PrestamoHipotecario.h"
#include <iostream>

PrestamoHipotecario::PrestamoHipotecario(int id, string cliente, string banco, string tipo, double cantidad, double intereses)
    : Prestamo(id, cliente, banco, tipo, cantidad, interes){};


void PrestamoHipotecario::calcularPrestamo() {
    interes = cantidadInicial*(euribor+diferencial)/12;
}

void PrestamoHipotecario::mostrarPrestamo() {
    cout << "---------------------------------------------" << endl;
    cout << "ID de prestamo: " << ID << endl;
    cout << "Prestamo: Q. " << cantidadInicial + interes << endl;
    cout << "Interes calculado: " << interes << endl;
    Prestamo::mostrarPrestamo();
    cout << "Valor euribor: " << euribor << endl;
    cout << "Valor diferencial: " << diferencial << endl;
    cout << "---------------------------------------------" << endl;
}

void PrestamoHipotecario::mostrarInteres() {
    void calcularPrestamo();
    Prestamo::mostrarInteres();
}

void PrestamoHipotecario::registrarInteres() {
    void calcularPrestamo();
    Prestamo::registrarInteres();
    cout << "------------------------------------" << endl;
}

void PrestamoHipotecario::mostrarID() {
    Prestamo::mostrarID();
}