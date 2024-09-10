#pragma once
#include "Prestamo.h"

class PrestamoHipotecario : public Prestamo {
private:
    float const diferencial = 0.0146;
    float const euribor = 0.004;

public:
    PrestamoHipotecario(int id, string cliente, string banco, string tipo, double cantidad, double intereses);
    void calcularPrestamo() override;
    void mostrarPrestamo() override;
    void mostrarInteres() override;
    void registrarInteres() override;
    void mostrarID() override;
};