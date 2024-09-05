#pragma once
#include "Prestamo.h"

class PrestamoHipotecario : public Prestamo {
private:
    double diferencial;

public:
    PrestamoHipotecario(string cliente, string banco, string tipo, double cantidad, time_t fecha, double dif);
    void calcularInteres() override;
    void calcularPrestamo() override;
    void mostrarPrestamo() const override;
};
