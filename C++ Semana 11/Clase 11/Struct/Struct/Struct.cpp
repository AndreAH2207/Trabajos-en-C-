#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;

#define TAM 10

struct Alumno {
	int tema;
	float puntaje;
};

void generarDatos(Alumno* vA) {
	for (int i = 0; i < TAM; i++)
	{
		vA[i].tema = 1 + rand() % 3;
		vA[i].puntaje = (rand() % 501) / 10.0;
	}
}
void mostrarDatos(Alumno* vA) {
	cout << "Tema\tPuntaje" << endl;
	for (int i = 0; i < TAM; i++)
	{
		cout << "[" << vA[i].tema << "]\t[" << vA[i].puntaje << "]" << endl;
	}
}

int main() {
	srand(time(NULL));
	Alumno* vAlumnos = new Alumno[TAM];
	generarDatos(vAlumnos);
	mostrarDatos(vAlumnos);
	getch();
}