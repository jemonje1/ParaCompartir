#include "PrestamosAutomoviles.h"
#include <iostream>
#include <cmath>

PrestamosAutomoviles::PrestamosAutomoviles(string cliente, string banco, string tipo, double cantidad, time_t fecha, double tasaMensual, int plazo)
    : Prestamo(cliente, banco, tipo, cantidad, fecha), tasaInteresMensual(tasaMensual), plazoMeses(plazo) {}

void PrestamosAutomoviles::calcularInteres() {
    double base = 1 + tasaInteresMensual;
    double potencia = pow(base, plazoMeses);
    interes = (cantidadInicial * tasaInteresMensual * potencia) / (potencia - 1);
}

void PrestamosAutomoviles::calcularPrestamo() {
    double prestamoCalculado = cantidadInicial + interes;
}

void PrestamosAutomoviles::mostrarPrestamo() const {
    cout << "Nombre: " << nombreCliente << endl;
    cout << "Banco: " << nombreBanco << endl;
    cout << "Tipo de Préstamo: " << tipoPrestamo << endl;
    cout << "Cantidad Inicial: " << cantidadInicial << endl;
    cout << "Fecha de Inicio: " << ctime(&fechaInicio);
    cout << "Tasa de Interés Mensual: " << tasaInteresMensual << endl;
    cout << "Plazo en Meses: " << plazoMeses << endl;
    cout << "Interés Calculado: " << interes << endl;
}
