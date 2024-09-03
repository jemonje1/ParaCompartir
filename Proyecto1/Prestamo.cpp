#include "Prestamo.h"
#include <iostream>
#include <ctime>

using namespace std;

Prestamo::Prestamo() :NombreUsuario(""), NombreBanco(""), Tipo(""), IngresoInicial(0), FechaActual(0) {
}

Prestamo::Prestamo(string nombreUsuario, string nombreBanco, string tipo, double ingresoInicial, time_t fechaActual) :NombreUsuario(nombreUsuario), NombreBanco(nombreBanco),
Tipo(tipo), FechaActual(fechaActual) {

};

void Prestamo:: mostrarPrestamo() {
	cout << "----------- Prestamo ----------" << endl;
	cout << "Nombre del prestatario: " << NombreUsuario << endl;
	cout << "Nombre del banco prestamista: " << NombreBanco << endl;
	cout << "Tipo de prestamo: " << Tipo << endl;
	cout << "Fecha: " << FechaActual << endl;
}