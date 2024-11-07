#include "ListaJugadores.h"

//Constructor del nodo
ListaJugadores::Node::Node(Jugador jugadores, Node* next)
	: jugador(jugadores), next(next) {};

//Funcion que cuenta cuantos jugadores tiene guardada la lista
int ListaJugadores::contarJugadores() {
	int count = 0;
	Node* node = head;
	while (head != nullptr) {
		count++;
		head = head->next;
		return count;
	}
}

//Funcion que agrega los jugadores a la lista
void ListaJugadores::agregarJugador(Jugador jugadores)
{
	Node * nodo = new Node(jugadores, nullptr);
	nodo->jugador = jugadores;
	if (head == nullptr) {
		head = nodo;
		tail = nodo;
		nodo->next = head;
	}
	else {
		tail->next = nodo;
		tail = nodo;
		nodo->next = head;
	}
}

//Funcion que muestra todos los jugadores y sus posiciones actuales
void ListaJugadores::mostrarLista()
{
	if (head == nullptr) {
		cout << "No hay jugadores en la lista" << endl;
	}
	else {
		Node* nodoRecorrido = head;
		int i = 1;
		do {
			cout << "----------------------------------------" << endl;
			cout << "Jugador " << i <<": " << nodoRecorrido->jugador.getNombre() << endl;
			cout << "Esta en la casilla: " << nodoRecorrido->jugador.getPos() <<" del tablero" << endl;
			cout << "----------------------------------------" << endl;
			nodoRecorrido = nodoRecorrido->next;
			i++;
		} while (nodoRecorrido != head);
	}
}

//Funcion que muestra un jugador en especifico, esta funcion recorrera la lista circular para mantener los turnos del juego
Jugador &ListaJugadores::mostrarJugador(int index) {
	if (index < 0 || index >= contarJugadores()) {
		throw std::out_of_range("El indice no apunta a ningun lado");
	}
	Node* head = this->head;
	for (int i = 0; i < index; i++) {
		head = head->next;
	}
	return this->head->jugador;
}

//Funcion que vacia la lista para liberar memoria
void ListaJugadores::vaciarLista() {
	if (head == nullptr) {
		return;
	}
	Node* current = head;
	Node* nextNode = nullptr;
	tail->next = nullptr;
	while (current != nullptr) {
		nextNode = current->next;
		delete current;
		current = nextNode;
	}
	head = nullptr;
	tail = nullptr;
}