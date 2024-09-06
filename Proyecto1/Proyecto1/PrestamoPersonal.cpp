#include "PrestamoPersonal.h"
#include <iostream>
#include "Prestamo.h"

using namespace std;
PrestamoPersonal::PrestamoPersonal(int id, string cliente, string banco, string tipo, double cantidad, double intereses, int dias)
    : Prestamo(id, cliente, banco, tipo, cantidad, intereses), diasTranscurridos(dias) {}


void PrestamoPersonal::calcularPrestamo() {
    interes = (cantidadInicial * tasaInteresAnual * diasTranscurridos) / 360;
};

void PrestamoPersonal::mostrarPrestamo() {
    cout << "---------------------------------------------" << endl;
    cout << "ID de prestamo: " << ID << endl;
    cout << "Prestamo: Q. " << cantidadInicial + interes << endl;
    cout << "Interes calculado: " << interes << endl;
    Prestamo::mostrarPrestamo();
    cout << "Desde: " << diasTranscurridos << " dias" << endl;
    cout << "Con una tasa de interes de: " << tasaInteresAnual << endl;
    cout << "---------------------------------------------" << endl;
};

void PrestamoPersonal::mostrarInteres() {
    void calcularPrestamo();
    Prestamo::mostrarInteres();
}