#pragma once
#include "Prestamo.h"
#include <iostream>
#include <ctime>

using namespace std;
class PrestamoPersonal:public Prestamo
{
protected:
	const float PorcentajePersonal = 0.0585;
	double TasaInteresAnual;
	int DiasTranscurridos;
	double InteresSimple;
	double PrestamoCalculado;

public:
	PrestamoPersonal(string, string, string, double, time_t, double, int, double, double);
	void mostrarPrestamo() override;
	void calcularInteres();
	void calcularPrestamo();
};

