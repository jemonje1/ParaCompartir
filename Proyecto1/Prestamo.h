#pragma once
#include <string>
#include <ctime>

using namespace std;

class Prestamo {
protected:
    string nombreCliente;
    string nombreBanco;
    string tipoPrestamo;
    double cantidadInicial;
    time_t fechaInicio;
    double interes;

public:
    Prestamo(string cliente, string banco, string tipo, double cantidad, time_t fecha);
    virtual ~Prestamo();
    virtual void calcularInteres() = 0; 
    virtual void calcularPrestamo() = 0; 
    virtual void mostrarPrestamo() const = 0; 
};

