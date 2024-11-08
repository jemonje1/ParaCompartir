#pragma once
//Librerias usadas para el tablero
#include <iostream>
#include <sstream>
#include <random>
#include <time.h>
#include <stdlib.h>
#include <thread>
#include <chrono>
//Clase casilla, ya que el tablero guarda estas
#include "Casilla.h"
class Tablero
{
private:
	Casilla** Matriz;
	int NumeroCasillas;
	int Filas;
	int Columnas;
public:
	Tablero(int numeroCasillas, int filas, int columnas, Casilla** punterito);
	int getNumeroCasillas();
	int getfilas();
	int getcolumnas();
	Casilla** getTablero();
	int buscarCasillaObtenerFila(int ID);
	int contarCasillasEspeciales(int FilaActual);
	int obtencionCasilla();
	void setCasillasEspeciales();
	int randomizarTipo(int fila);
	void determinarFinales(int pos, int tipoCasilla);
	int limiteEscalera(int pos);
	int limiteSerpiente(int pos);
	void tiempo();
	void vaciarTablero();
};