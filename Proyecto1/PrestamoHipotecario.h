#pragma once
#include <iostream>
#include <ctime>
#include "Prestamo.h"

using namespace std;

class PrestamoHipotecario:public Prestamo
{
protected:
	const double Euribor = 3.088;
	double Diferencial;
	double InteresCompuesto;
	double CalculoPrestamoHipotecario;

public:
	PrestamoHipotecario(string, string, string, double, time_t, double, double, double);
	void mostrarPrestamo() override;
	void calcularInteresCompuesto();
	void calcularPrestamoHipotecario();
};

