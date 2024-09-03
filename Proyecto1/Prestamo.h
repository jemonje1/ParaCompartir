#pragma once
#include <iostream>
#include <ctime>

using namespace std;
class Prestamo
{
protected:
	string NombreUsuario;
	string NombreBanco;
	string Tipo;
	double IngresoInicial;
	time_t FechaActual;

public:
	Prestamo();
	Prestamo(string nombreUsuario, string nombreBanco, string tipo, double ingresoInicial, time_t fechaActual);
	virtual void mostrarPrestamo();
};
