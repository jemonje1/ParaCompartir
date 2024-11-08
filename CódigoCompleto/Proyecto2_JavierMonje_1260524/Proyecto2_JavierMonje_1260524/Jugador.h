#pragma once
#include <iostream>
using namespace std;
//Propiedades y atributos de los jugadores
class Jugador
{
private:
	string nombreJugador;
	int numeroJugador;
	int posicionJugador;
public:
	Jugador(string nombre, int posicion, int numero);
	string getNombre();
	int getNumero();
	int getPos();
	void setPos(int nuevaPos);
	void mostrarGanador();
};