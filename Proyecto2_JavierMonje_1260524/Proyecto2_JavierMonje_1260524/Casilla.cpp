#include "Casilla.h"

//Constructor vacio de una casilla, para poder crearlas y posteriormente definirlas correctamente
Casilla::Casilla() : numeroCasilla(0), Tipo(0) {};

//Constructor de casillas con sus atributos
Casilla::Casilla(int numerocasilla, int tipo, int fin):numeroCasilla(numerocasilla), Tipo(tipo), Fin(fin){};

//Getters
int Casilla::getnumeroCasilla() {
	return numeroCasilla;
}

int Casilla::getTipo() {
	return Tipo;
}

int Casilla::getFin() {
	return Fin;
}

//Setters
void Casilla::setTipo(int nuevoTipo) {
	Tipo = nuevoTipo;
}

void Casilla::setFin(int nuevoFin) {
	Fin = nuevoFin;
}