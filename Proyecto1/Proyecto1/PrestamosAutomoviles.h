#pragma once
#include "Prestamo.h"
#include <cmath>

class PrestamosAutomoviles : public Prestamo {
private:
    float const tasaInteresMensual = 0.01175 / 12;
    int plazoMeses;

public:
    PrestamosAutomoviles(int id, string cliente, string banco, string tipo, double cantidad, double intereses, double cantidadfija, int plazo);
    void calcularPrestamo() override;
    void mostrarPrestamo() override;
    void mostrarInteres() override;
    void registrarInteres() override;
    void mostrarID() override;
};