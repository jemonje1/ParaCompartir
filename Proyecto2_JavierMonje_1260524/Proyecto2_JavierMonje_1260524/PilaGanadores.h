#pragma once
#include "Jugador.h"
//Metodos y atributos de la pila de los ganadores
class PilaGanadores
{
private:
	struct Node {
		Jugador jugador;
		Node* next;
		Node(Jugador jugador, Node* next);
	};
	Node* head = nullptr;
public:
	bool isEmpty();
	void push(Jugador jugador);
	Jugador pop();
	void deleteStack();
};