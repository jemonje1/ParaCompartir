#include "PrestamoHipotecario.h"
#include <iostream>
#include <ctime>

using namespace std;

PrestamoHipotecario::PrestamoHipotecario(string, string, string, double, time_t, double diferencial, double interesCompuesto, double calculoPrestamoHipotecario):Prestamo(NombreUsuario, NombreBanco,Tipo, IngresoInicial, FechaActual), Diferencial(diferencial), 
InteresCompuesto(interesCompuesto), CalculoPrestamoHipotecario(calculoPrestamoHipotecario) {
}

void PrestamoHipotecario::mostrarPrestamo() {
	Prestamo::mostrarPrestamo();
	cout << "Interes Compuesto: " << InteresCompuesto << endl;
	cout << "Prestamo Calculado: " << CalculoPrestamoHipotecario << endl;
}

void PrestamoHipotecario::calcularInteresCompuesto(){
	Diferencial = 0.04 - 0.0146;
	InteresCompuesto = IngresoInicial * (Euribor + Diferencial) / 12;
}

void PrestamoHipotecario::calcularPrestamoHipotecario() {
	CalculoPrestamoHipotecario = InteresCompuesto - Diferencial;
}
