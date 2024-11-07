#include "Dado.h"
#include <iostream>
#include <random>
#include <time.h>
#include <stdlib.h>

using namespace std;

//La funcion dado devuelve un valor aleatorio entre 1-6
int Dado::tirarDado() {
	srand(time(NULL));
	int numeroDado;
	int valorMenor = 1;
	int valorMayor = 6;
	numeroDado = valorMenor + rand() % (valorMayor + 1 - valorMenor);
	return numeroDado;
}