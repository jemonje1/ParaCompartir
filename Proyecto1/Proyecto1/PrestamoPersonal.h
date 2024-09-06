#pragma once
#include "Prestamo.h"

class PrestamoPersonal : public Prestamo {
private:
    const float tasaInteresAnual = 0.0585;
    int diasTranscurridos;

public:
    PrestamoPersonal(int ID, string cliente, string banco, string tipo, double cantidad, double intereses, int dias);
    void calcularPrestamo() override;
    void mostrarPrestamo() override;
    void mostrarInteres() override;
};