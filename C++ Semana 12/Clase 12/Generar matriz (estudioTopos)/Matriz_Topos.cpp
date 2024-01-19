#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;
using namespace System;
#define FILA 10
#define COL 15

void generarDatos(int** mt) {
	for (int i = 0; i < FILA; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			mt[i][j] = 1 + rand() % 3;
		}
	}
}

void mostrarDatos(int** mt) {
	for (int i = 0; i < FILA; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << "[" << mt[i][j] << "]";
		}
		cout << endl;
	}
}

void buscarGuarida(int** mt) {
	int encontrado = 0;
	cout << "Los puntos donde puede existir una guarida de topo son: " << endl;
	for (int i = 1; i < FILA - 1; i++)
	{
		for (int j = 1; j < COL - 1; j++)
		{
			if (mt[i + 1][j] == 1 && mt[i - 1][j] == 3 && mt[i][j - 1] == 2 && mt[i][j + 1] == 2) {
				cout << "Fila: " << i + 1 << ", Columna: " << j + 1 << endl;
				encontrado = 1;
			}

		}
	}
	if (encontrado == 0)
		cout << "No se contrados guaridas de topos: " << endl;

	//Color
	int x, y;
	for (int i = 1; i < FILA - 1; i++)
	{
		for (int j = 1; j < COL - 1; j++)
		{
			if (mt[i + 1][j] == 1 && mt[i - 1][j] == 3 && mt[i][j - 1] == 2 && mt[i][j + 1] == 2) {
				x = j * 3 + 1;
				y = i;
				Console::BackgroundColor = ConsoleColor::Green;
				Console::ForegroundColor = ConsoleColor::Black;
				Console::SetCursorPosition(x, y);
				cout << mt[i][j];
				Console::BackgroundColor = ConsoleColor::Black;
				Console::ForegroundColor = ConsoleColor::Gray;

				x = 0; y = 0;
			}

		}
	}
}

void obtenerFrecuencia(int** mt) {

	int f1 = 0, f2 = 0, f3 = 0;
	for (int i = 0; i < FILA; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			switch (mt[i][j])
			{
			case 1: f1++; break;
			case 2: f2++; break;
			case 3: f3++; break;
			}
		}
	}
	Console::SetCursorPosition(0, 16);
	cout << "Cantidad de zanahorias: " << f1 << endl;
	cout << "Cantidad de Berenjenas: " << f2 << endl;
	cout << "Cantidad de Nabos: " << f3 << endl;
	if (f1 > f2 && f1 > f3 && f2 > f3)
		cout << "El cultivo con mayor frecuencia es 1, y con menor frecuencia es el 3" << endl;
	if (f1 > f2 && f1 > f3 && f3 > f2)
		cout << "El cultivo con mayor frecuencia es 1, y con menor frecuencia es el 2" << endl;
	if (f2 > f1 && f2 > f3 && f1 > f3)
		cout << "El cultivo con mayor frecuencia es 2, y con menor frecuencia es el 3" << endl;
	if (f2 > f1 && f2 > f3 && f3 > f1)
		cout << "El cultivo con mayor frecuencia es 2, y con menor frecuencia es el 1" << endl;
	if (f3 > f1 && f3 > f2 && f1 > f2)
		cout << "El cultivo con mayor frecuencia es 3, y con menor frecuencia es el 2" << endl;
	if (f3 > f1 && f3 > f2 && f2 > f1)
		cout << "El cultivo con mayor frecuencia es 3, y con menor frecuencia es el 1" << endl;
	//frencuencia con un vector estatico
	cout << "=========================================" << endl;
	int vf[3] = { 0,0,0 }; // se guarda la frecuencia de 1 2 3 en las posiciones 0 1 2
	for (int i = 0; i < FILA; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			switch (mt[i][j])
			{
			case 1: vf[0]++; break;
			case 2: vf[1]++; break;
			case 3: vf[2]++; break;
			}
		}
	}
	int mayor = vf[0];
	int menor = vf[0];
	for (int i = 1; i < 3; i++) {
		if (vf[i] > mayor) mayor = vf[i];
		if (vf[i] < menor)menor = vf[i];
	}
	cout << "Cantidad de zanahorias: " << vf[0] << endl;
	cout << "Cantidad de Berenjenas: " << vf[1] << endl;
	cout << "Cantidad de Nabos: " << vf[2] << endl;
	cout << "El cultivo con mayor frecuencia es " << mayor << " y con menor frecuencia es el " << menor << endl;

}
int main() {
	srand(time(NULL));
	Console::CursorVisible = false;
	int** mtopos = new int* [FILA];
	for (int i = 0; i < FILA; i++)
	{
		mtopos[i] = new int[COL];
	}
	generarDatos(mtopos);
	mostrarDatos(mtopos);
	buscarGuarida(mtopos);
	obtenerFrecuencia(mtopos);
	getch();
}