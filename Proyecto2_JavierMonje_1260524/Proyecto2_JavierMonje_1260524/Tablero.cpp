#include "Tablero.h"
#include <iostream>
#include <random>
#include <time.h>
#include <stdlib.h>
#include <thread>
#include <chrono>

using namespace std;

//Constructor del tablero
Tablero::Tablero(int numeroCasillas, int filas, int columnas, Casilla** punterito) :NumeroCasillas(numeroCasillas), Filas(filas), Columnas(columnas), Matriz(punterito) {
    srand(time(NULL)); //Establecimiento de la aleatoridad para las funciones que lo requieran
};

//Getters
int Tablero::getfilas() {
	return Filas;
}

int Tablero::getcolumnas() {
	return Columnas;
}

int Tablero::getNumeroCasillas() {
	return NumeroCasillas;
}

Casilla** Tablero::getTablero() {
	return Matriz;
}

//Funcion que obtiene la casilla especial y define tanto el tipo de la casilla como el final
void Tablero::setCasillasEspeciales() {
    int cantidadCasillasEspeciales = getNumeroCasillas() * 0.25; //Asegurar que las especiales no sobrepases el 25% de las casillas del mapa y obtener cuantas se especiales se haran
    for (int i = 0; i < cantidadCasillasEspeciales; i++) { 
        int IDCasillaSeleccionada = obtencionCasilla(); //Se obtiene la casilla
        int fila = buscarCasillaObtenerFila(IDCasillaSeleccionada); //Se busca la fila
        int tipoCasilla = randomizarTipo(fila);//Se define el tipo de la casilla
        for (int j = 0; j < Filas; j++) {
            for (int k = 0; k < Columnas; k++) {
                if (Matriz[j][k].getnumeroCasilla() == IDCasillaSeleccionada) { //Se busca la casilla seleccionada en la matriz
                    Matriz[j][k].setTipo(tipoCasilla); //Se hace un set al tipo de la casilla
                    determinarFinales(Matriz[j][k].getnumeroCasilla(), tipoCasilla); //Se determina a donde te llevara la serpiente o la escalera
                }
            }
        }
    }
    cout << "Creando casillas especiales. . ." << endl;
}

//Esta funcion retornará un número aleatorio entre la segunda casilla hasta la penultima
int Tablero::obtencionCasilla() {
    tiempo(); //Se llama a la funcion tiempo para asegurar mayor aleatoridad
	int aleatoridad;
	int valorMenor = 2;
	int valorMayor = NumeroCasillas-1;
	aleatoridad = valorMenor + rand() % (valorMayor - valorMenor);
	int BuscarEnFila = buscarCasillaObtenerFila(aleatoridad);
    //Condicion para asegurar que en la fila no hayan 3 casillas especiales
	if (contarCasillasEspeciales(BuscarEnFila) >= 3) {
		return obtencionCasilla();
	}
	else {
		return aleatoridad;
	};
}

//Cuenta si hay alguna casilla especial en la fila de la casilla seleccionada
int Tablero::contarCasillasEspeciales(int numeroFila) {
	int count = 0;
	for (int i = 0; i < numeroFila; i++) {
		if (Matriz[numeroFila][i].getTipo() != 0) {
			count++;
		};
	}
	return count;
};

//Funcion que busca la casilla y retorna la fila
int Tablero::buscarCasillaObtenerFila(int ID) {
	for (int i = 0; i < Filas; i++) {
		for (int j = 0; j < Columnas; j++) {
			if (Matriz[i][j].getnumeroCasilla() == ID) {
				return i;
			};
		};
	};
};

//Funcion que aleatoriza el tipo de casilla
int Tablero::randomizarTipo(int fila) {
    int Tipo;
    int valorMenor = 1;
    int valorMayor = 2;
    do {
        Tipo = valorMenor + rand() % (valorMayor + 1 - valorMenor);
        //Ciclo que evita que las escaleras queden en la ultima fila o que las serpientes esten en la primera
    } while ((Tipo == 1 && fila == Filas - 1) || (Tipo == 2 && fila == 0));
    return Tipo;
}

//Funcion que, segun el tipo, aleatorizará a donde llevará la casilla especial
void Tablero::determinarFinales(int pos, int tipoCasilla) {
    int nuevoFin;
    if (tipoCasilla == 1) {
        nuevoFin = limiteEscalera(pos);
    }
    if (tipoCasilla == 2) {
        nuevoFin = limiteSerpiente(pos);
    }
    for (int i = 0; i < getfilas(); i++) {
        for (int j = 0; j < getcolumnas(); j++) {
            if (Matriz[i][j].getnumeroCasilla() == pos) {
                //Al obtener a donde llevará, se seteará el fin en la casilla
                Matriz[i][j].setFin(nuevoFin);
            };
        }
    }
}

//Funcion que estima a donde lleva una escalera
int Tablero::limiteEscalera(int pos) {
    int aleatoridad;
    int valorMenor = pos + 1; 
    int valorMayor = NumeroCasillas - 1;
    do {
        aleatoridad = valorMenor + rand() % (valorMayor + 1 - valorMenor);
        //Ciclo que evita que lleve a la misma fila
    } while (buscarCasillaObtenerFila(aleatoridad) == buscarCasillaObtenerFila(pos) || aleatoridad == 0);
    return aleatoridad;
}

//Funcion que estima a donde lleva una serpiente
int Tablero::limiteSerpiente(int pos) {
    int aleatoridad;
    int valorMenor = 1;
    int valorMayor = pos - 1;
    do {
        aleatoridad = valorMenor + rand() % (valorMayor + 1 - valorMenor);
        //Ciclo que evita que lleve a la misma fila
    } while (buscarCasillaObtenerFila(aleatoridad) == buscarCasillaObtenerFila(pos) || aleatoridad==0);
    return aleatoridad;
}

//Funcion que detiene el sistema breve milisegundos
void Tablero::tiempo() {
    this_thread::sleep_for(chrono::milliseconds(100));
}

//Funcion que vacía el tablero para liberar memoria
void Tablero::vaciarTablero() {
    for (int i = 0; i < getfilas(); i++) {
        delete[] Matriz[i];  // Elimina cada fila, liberando las columnas y casillas dentro de esa fila
    }
    delete[] Matriz;
}