#include "Jugador.h"

//Constructor del jugador con sus atributos
Jugador::Jugador(string nombre, int posicion, int numero) : nombreJugador(nombre), posicionJugador(posicion), numeroJugador(numero) {
};

//Getters
string Jugador::getNombre() {
	return nombreJugador;
}

int Jugador::getNumero() {
	return numeroJugador;
}

int Jugador::getPos() {
	return posicionJugador;
}

//Setters
void Jugador::setPos(int nuevaPos) {
	posicionJugador = nuevaPos;
}

//Muestra la informacion del jugador como ganador
void Jugador::mostrarGanador() {
	cout << "\n----------------------------------" << endl;
	cout << "Ganador de la partida:" << endl;
	cout << getNombre() << endl;
	cout << "-----------------------------------\n" << endl;
}