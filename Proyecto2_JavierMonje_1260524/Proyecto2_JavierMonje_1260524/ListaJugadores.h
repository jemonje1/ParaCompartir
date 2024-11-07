#pragma once
#include <iostream>
#include "Jugador.h"
//Metodos y atributos de lista
class ListaJugadores{
public:
	struct Node {
		Jugador jugador;
		Node* next;
		Node(Jugador jugadores, Node* next);
	};
	Node* head = nullptr;
	Node* tail = nullptr;
	int contarJugadores();
	void agregarJugador(Jugador jugadores);
	void mostrarLista();
	Jugador &mostrarJugador(int index);
	void vaciarLista();
};