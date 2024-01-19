#include <iostream>
#include <conio.h>

using namespace std;

char letras[2] = { 'S','N' };

struct Alumno {
	char gripe;
	char tos;
	float peso;
};


int ingresarCant() {
	int n;
	do {
		cout << "Ingrese la cantidad de Alumnos: ";
		cin >> n;
	} while (n < 1 || n>20);
	return n;
}
void generarDatos(Alumno* va, int n) {
	int num;
	for (int i = 0; i < n; i++)
	{	
		//uso de vector statico llamado letras para de forma aleatorio por posicion guarda S o N
		va[i].gripe = letras[rand() % 2];
		//uso de switch para generar dos letras
		num = rand() % 2;
		switch (num)
		{
		case 0: va[i].tos = 'S'; break;
		case 1: va[i].tos = 'N'; break;
		}
		va[i].peso = 30 + rand() % 301 / 10.0;
	}
}
void mostrarDatos(Alumno* va, int n) {

	for (int i = 0; i < n; i++)
	{
		cout << "[" << va[i].gripe << "]\t[" << va[i].tos << "]\t[" << va[i].peso << "]" << endl;
	}
}

int main() {
	srand(time(NULL));
	int n = ingresarCant();
	Alumno* vAlumnos = new Alumno[n];
	generarDatos(vAlumnos, n);
	mostrarDatos(vAlumnos, n);
	getch();
}