#include "PilaGanadores.h"

//Constructor del nodo de la pila
PilaGanadores::Node::Node(Jugador jugador, Node* next) :jugador(jugador), next(next) {
};

//Funcion para saber si la pila esta vacia o no
bool PilaGanadores::isEmpty() {
	return this->head == nullptr;
};

//Funcion que oushea un ganador a la pila
void PilaGanadores::push(Jugador jugador) {
	Node* node = new Node{jugador, head};
	this->head = node;
};

//Funcion que retorna al ultimo ganador puesto en la pila (pop)
Jugador PilaGanadores::pop() {
	Node* node = head;
	Jugador jugador = node->jugador;
	this->head = this->head->next;
	delete node;
	return jugador;
};

//Funcion que vacia la pila para la liberacion de memoria
void PilaGanadores::deleteStack() {
	while (!isEmpty()) {
		Node* node = head;
		this->head = this->head->next;
		delete node;
	}
}