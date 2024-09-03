#pragma once
#include <iostream>
#include <ctime>
#include "Prestamo.h"
using namespace std;

class PrestamosAutomoviles:public Prestamo
{
protected:
	const float Porcentaje = 0.1175;
	double TasaInteresMensual;
	int PlazoMeses;
	double CuotaMensual;
	double PrestamoCalculado;

public:
	PrestamosAutomoviles(string, string, string, double, time_t, double, int, double, double);
	void mostrarPrestamo() override;
	void calcularCuotaMensual();
	void calcularPrestamoAutomoviles();
};

