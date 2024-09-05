#pragma once
#include "Prestamo.h"

class PrestamosAutomoviles : public Prestamo {
private:
    double tasaInteresMensual;
    int plazoMeses;

public:
    PrestamosAutomoviles(string cliente, string banco, string tipo, double cantidad, time_t fecha, double tasaMensual, int plazo);
    void calcularInteres() override;
    void calcularPrestamo() override;
    void mostrarPrestamo() const override;
};
