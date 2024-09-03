#include "PrestamoPersonal.h"
#include <iostream>
#include <ctime>

PrestamoPersonal::PrestamoPersonal(string, string, string, double, time_t, double tasaInteresAnual, int diasTranscurridos, double interesSimple, double prestamoCalculado): Prestamo(NombreUsuario, NombreBanco,
	Tipo, IngresoInicial, FechaActual), TasaInteresAnual(tasaInteresAnual), DiasTranscurridos(diasTranscurridos), InteresSimple(interesSimple), PrestamoCalculado(prestamoCalculado){
}

void PrestamoPersonal::mostrarPrestamo() {
	Prestamo::mostrarPrestamo();
	cout << "Interes: " << InteresSimple << endl;
	cout << "Prestamo Calculado: " << PrestamoCalculado << endl;
}

void PrestamoPersonal::calcularInteres() {
	InteresSimple = (IngresoInicial * TasaInteresAnual * DiasTranscurridos) / 360;
}

void PrestamoPersonal::calcularPrestamo() {
	PrestamoCalculado = InteresSimple - PorcentajePersonal;
}