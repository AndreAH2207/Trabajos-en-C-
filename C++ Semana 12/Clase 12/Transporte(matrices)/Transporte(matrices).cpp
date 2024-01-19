#include <iostream>
#include <conio.h>
#include <time.h>
#include <iomanip>
using namespace std;

void generarDatos(int** mt) {
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			mt[i][j] = 1 + rand() % 25;
		}
	}
}

void mostrarDatos(int** mt) {
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << " [" << setfill('0') << setw(2) << mt[i][j] << "] ";
		}

		cout << endl;
	}
}

void calcularPasajerosXSemana(int** mt) {
	int suma = 0;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			suma += mt[i][j];
		}
		cout << "El conductor " << i + 1 << " logro trasportar " << suma << " pasajeros" << endl;
		suma = 0;
	}
}

void calcularPasajerosXDia(int** mt) {
	int suma = 0;
	for (int j = 0; j < 6; j++)
	{
		for (int i = 0; i < 20; i++)
		{
			suma += mt[i][j];
		}
		cout << "El promedio de pasajeros en el dia " << j + 1 << " es = " << suma / 20.0 << endl;
		suma = 0;
	}
}
int main() {
	srand(time(NULL));
	//Creamos filas para la matrix
	int** mTransporte = new int* [20];
	//Creamos columnas para cada fila de la matriz
	for (int i = 0; i < 20; i++)
	{
		mTransporte[i] = new int[6];
	}
	generarDatos(mTransporte);
	mostrarDatos(mTransporte);
	cout << endl;
	calcularPasajerosXSemana(mTransporte);
	cout << "==========================================" << endl;
	calcularPasajerosXDia(mTransporte);
	getch();
}