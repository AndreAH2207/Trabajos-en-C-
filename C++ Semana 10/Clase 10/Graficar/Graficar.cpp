#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;
void generarDatos(int* v1, int* v2) {
	for (int i = 0; i < 12; i++)
	{
		v1[i] = rand() % 31;
		v2[i] = rand() % 31;
	}
}
void mostrarDatos(int* v1, int* v2) {
	cout << "Datos del Anio 2014" << endl;
	for (int i = 0; i < 12; i++)
	{
		cout << "[" << v1[i] << "] ";
	}
	cout << "\nDatos del Anio 2015" << endl;
	for (int i = 0; i < 12; i++)
	{
		cout << "[" << v2[i] << "] ";
	}
	cout << endl;
}
void graficar(int* v, int anio) {
	cout << "Grafico del Anio " << anio << endl;
	//Recorremos el vector para extraer la cantidad de cada posicion i
	for (int i = 0; i < 12; i++)
	{
		//Generamos # segun la cantidad en la posicion i del vector
		for (int j = 0; j < v[i]; j++)
		{
			cout << "#";
		}
		cout << "(" << v[i] << ")" << endl;
	}
}
int main() {
	srand(time(NULL));
	int* v1 = new int[12];
	int* v2 = new int[12];
	generarDatos(v1, v2);
	mostrarDatos(v1, v2);
	cout << "===============================" << endl;
	graficar(v1, 2014);
	cout << "===============================" << endl;
	graficar(v2, 2015);
	getch();
}