#pragma once
#include "Prestamo.h"

class PrestamosAutomoviles : public Prestamo {
private:
    float const interesAnual = 0.01175;
    float tasaInteresMensual;
    int plazoMeses;

public:
    PrestamosAutomoviles(int id, string cliente, string banco, string tipo, double cantidad,double intereses, double tasaMensual, int plazo);
    float conversionAMeses();
    void calcularPrestamo() override;
    void mostrarPrestamo() override;
    void mostrarInteres() override;
    void registrarInteres() override;
    void mostrarID() override;
};