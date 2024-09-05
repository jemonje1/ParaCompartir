#include "PrestamoHipotecario.h"
#include <iostream>

PrestamoHipotecario::PrestamoHipotecario(string cliente, string banco, string tipo, double cantidad, time_t fecha, double dif)
    : Prestamo(cliente, banco, tipo, cantidad, fecha), diferencial(dif) {}

void PrestamoHipotecario::calcularInteres() {
    interes = cantidadInicial * (0.03 + diferencial);
}

void PrestamoHipotecario::calcularPrestamo() {
    double prestamoCalculado = cantidadInicial + interes;
}

void PrestamoHipotecario::mostrarPrestamo() const {
    cout << "Nombre: " << nombreCliente << endl;
    cout << "Banco: " << nombreBanco << endl;
    cout << "Tipo de Préstamo: " << tipoPrestamo << endl;
    cout << "Cantidad Inicial: " << cantidadInicial << endl;
    cout << "Fecha de Inicio: " << ctime(&fechaInicio);
    cout << "Diferencial: " << diferencial << endl;
    cout << "Interés Calculado: " << interes << endl;
}
