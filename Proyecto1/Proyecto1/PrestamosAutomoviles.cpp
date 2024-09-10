#include "PrestamosAutomoviles.h"
#include <iostream>
#include <cmath>

PrestamosAutomoviles::PrestamosAutomoviles(int id, string cliente, string banco, string tipo, double cantidad, double intereses, double tasaMensual, int plazo)
    : Prestamo(id, cliente, banco, tipo, cantidad, interes), tasaInteresMensual(tasaMensual), plazoMeses(plazo) {}

float PrestamosAutomoviles::conversionAMeses() {
    tasaInteresMensual = interesAnual / 12;
    return tasaInteresMensual;
}

void PrestamosAutomoviles::calcularPrestamo() {
    float conversionAMeses();
    interes = (cantidadInicial * tasaInteresMensual) / (pow(1 - (1 - tasaInteresMensual), -plazoMeses));
};

void PrestamosAutomoviles::mostrarPrestamo() {
    cout << "---------------------------------------------" << endl;
    cout << "ID de prestamo: " << ID << endl;
    cout << "Prestamo: Q. " << cantidadInicial + interes << endl;
    cout << "Interes calculado: " << interes << endl;
    Prestamo::mostrarPrestamo();
    cout << "Considerando un plazo de: " << plazoMeses << endl;
    cout << "Con una tasa de interes mensual de: " << tasaInteresMensual << endl;
    cout << "---------------------------------------------" << endl;
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
