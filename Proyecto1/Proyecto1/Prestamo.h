#pragma once
#include <iostream>

using namespace std;

#pragma once
#include <iostream>

using namespace std;

class Prestamo {
protected:
    int ID;
    string nombreCliente;
    string nombreBanco;
    string tipoPrestamo;
    double cantidadInicial;
    double interes;

public:
    Prestamo(int id, string cliente, string banco, string tipo, double cantidad, double intereses);
    virtual ~Prestamo();
    virtual void calcularPrestamo() = 0;
    virtual void mostrarPrestamo();
    virtual void mostrarInteres();
    virtual void mostrarID();
    virtual void registrarInteres();
    void obtenernuevoID(int nuevoID);
};