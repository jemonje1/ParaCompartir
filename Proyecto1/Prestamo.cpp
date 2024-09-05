#include "Prestamo.h"

Prestamo::Prestamo(string cliente, string banco, string tipo, double cantidad, time_t fecha)
    : nombreCliente(cliente), nombreBanco(banco), tipoPrestamo(tipo), cantidadInicial(cantidad), fechaInicio(fecha), interes(0.0) {}

Prestamo::~Prestamo() {
}
