#pragma once
//Atributos y metodos de una casilla
class Casilla
{
private:
	int numeroCasilla;
	int Tipo;
	int Fin;
public:
	Casilla();
	Casilla(int numerocasilla, int tipo, int fin);
	int getnumeroCasilla();
	int getTipo();
	int getFin();
	void setTipo(int nuevoTipo);
	void setFin(int nuevoFin);
};