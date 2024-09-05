#include "PrestamoPersonal.h"
#include <iostream>

PrestamoPersonal::PrestamoPersonal(string cliente, string banco, string tipo, double cantidad, time_t fecha, double tasaAnual, int dias)
    : Prestamo(cliente, banco, tipo, cantidad, fecha), tasaInteresAnual(tasaAnual), diasTranscurridos(dias) {}

void PrestamoPersonal::calcularInteres() {
    interes = (cantidadInicial * tasaInteresAnual * diasTranscurridos) / 360;
}

void PrestamoPersonal::calcularPrestamo() {
    double prestamoCalculado = cantidadInicial + interes;
}

void PrestamoPersonal::mostrarPrestamo() const {
    cout << "Nombre: " << nombreCliente << endl;
    cout << "Banco: " << nombreBanco << endl;
    cout << "Tipo de Pr�stamo: " << tipoPrestamo << endl;
    cout << "Cantidad Inicial: " << cantidadInicial << endl;
    cout << "Fecha de Inicio: " << ctime(&fechaInicio);
    cout << "Tasa de Inter�s Anual: " << tasaInteresAnual << endl;
    cout << "D�as Transcurridos: " << diasTranscurridos << endl;
    cout << "Inter�s Calculado: " << interes << endl;
}
