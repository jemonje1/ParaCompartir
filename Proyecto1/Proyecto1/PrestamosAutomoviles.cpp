#include "PrestamosAutomoviles.h"
#include <iostream>
#include <cmath>

PrestamosAutomoviles::PrestamosAutomoviles(int id, string cliente, string banco, string tipo, double cantidad, double cantidadfija, double intereses, int plazo)
    : Prestamo(id, cliente, banco, tipo, cantidad, cantidadfija, interes), plazoMeses(plazo) {

}

void PrestamosAutomoviles::calcularPrestamo() {
    float conversionAMeses();
    double base = 1 + tasaInteresMensual;
    double exponente = -1*plazoMeses;
    double potencia = pow(base, exponente);
    double cuotaMensual = (cantidadInicial * tasaInteresMensual) / (1 - potencia);
    cout << "Cuota Mensual: Q." << cuotaMensual << endl;
};

void PrestamosAutomoviles::mostrarPrestamo() {
    cout << "---------------------------------------------" << endl;
    cout << "ID de prestamo: " << ID << endl;
    cout << "Cantidad inicial: Q." << cantidadInicial << endl;
    calcularPrestamo();
    cout << "Considerando un plazo de: " << plazoMeses << " meses" << endl;
    Prestamo::mostrarPrestamo();
    cout << "Con una tasa de interes anual de: " << tasaInteresMensual*12 << endl;
    cout << "----------------------------------------------" << endl;
}

void PrestamosAutomoviles::mostrarInteres() {
    void calcularPrestamo();
    Prestamo::mostrarInteres();
}

void PrestamosAutomoviles::registrarInteres() {
        void calcularPrestamo();
        Prestamo::registrarInteres();
        cout << "------------------------------------" << endl;
}

void PrestamosAutomoviles::mostrarID() {
    Prestamo::mostrarID();
}
