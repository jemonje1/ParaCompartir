#pragma once
#include "Prestamo.h"

class PrestamoPersonal : public Prestamo {
private:
    double tasaInteresAnual;
    int diasTranscurridos;

public:
    PrestamoPersonal(string cliente, string banco, string tipo, double cantidad, time_t fecha, double tasaAnual, int dias);
    void calcularInteres() override;
    void calcularPrestamo() override;
    void mostrarPrestamo() const override;
};
