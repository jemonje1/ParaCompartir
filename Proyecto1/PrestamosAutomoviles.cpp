#include "PrestamosAutomoviles.h"
#include <iostream>
#include <ctime>
#include <math.h>

using namespace std;

PrestamosAutomoviles::PrestamosAutomoviles(string, string, string, double, time_t, double tasaInteresMensual, int plazoMeses, double cuotaMensual, double prestamoCalculado) :Prestamo(NombreUsuario, NombreBanco, Tipo, IngresoInicial, FechaActual),
TasaInteresMensual(tasaInteresMensual), PlazoMeses(plazoMeses), CuotaMensual(cuotaMensual), PrestamoCalculado(prestamoCalculado){
}

void PrestamosAutomoviles::mostrarPrestamo() {
	Prestamo::mostrarPrestamo();
	cout << "Interes: " << CuotaMensual << endl;
	cout << "Prestamo Calculado: " << PrestamoCalculado<< endl;
}

void PrestamosAutomoviles::calcularCuotaMensual() {
	double base = (1-(1+TasaInteresMensual));
	double calculoPotencia = pow(base, PlazoMeses);
	CuotaMensual = (IngresoInicial * TasaInteresMensual) / calculoPotencia;
}

void PrestamosAutomoviles::calcularPrestamoAutomoviles() {
	PrestamoCalculado = (CuotaMensual * (1 / 12)) * Porcentaje;
}
