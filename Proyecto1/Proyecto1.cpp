/*Proyecto 01 Programación Avanzada
Grupo formado por:
Daniel Zepeda | 1265824
Javier Enrique Monje Pérez | 1260524*/


#include <iostream>
#include "Prestamo.h"
#include "PrestamoPersonal.h"

using namespace std;
bool Salida = true;
int numeroPrestamos;
Prestamo** prestamos;

int main()
{
	cout << "Bienvenido al sistema de gestión de préstamos" << endl;
	cout << "Ingrese el nombre de su banco: " << endl;
	string nombreBanco;
	cin >> nombreBanco;
	cout << "Bienvenido Banco: " << nombreBanco << endl;
	do {
		mostrarMenu();
	} while (Salida = true);
	return 0;
}

void mostrarMenu() {
	cout << "---------------------------------------------\nMenu de opciones\n---------------------------------------------" << endl;
	cout << "a) Agregar un nuevo prestamo\nb) Eliminar un prestamo existente\nc) Ver un prestamo\nd) Mostrar todos los prestamos\ne) Calcular y mostrar el interes de cada prestamo\nf) Salir" << endl;
	char opciones;
	cin >> opciones;
	switch (opciones) {
	case 'a':
		break;
	case 'b':
		break;
	case 'c':
		break;
	case 'd':
		break;
	case 'e':
		break;
	case 'f':
		cout << "Gracias por usar nuestros servicios" << endl;
		cout << "Cerrando sesión . . ." << endl;
		Salida = false;
		break;
	default:
		cout << "La opcion que eligio no es valida" << endl;
	}
}

void mostrarMenuVerPrestamos() {
	cout << "---------------------------------------------\nMenu de Ver Prestamos\n---------------------------------------------" << endl;
	cout << "a) Ver informacion del prestamo\nb) Calcular y mostrar intereses\nc) Registrar pago de intereses\nd) Abono al saldo del prestamo" << endl;
	char opciones2;
	cin >> opciones2;
	switch (opciones2) {
	case 'a':
		break;
	case 'b':
		break;
	case 'c':
		break;
	case 'd':
		break;
	default:
		break;
	}
}