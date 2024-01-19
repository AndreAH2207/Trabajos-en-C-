#include <iostream>
#include <conio.h>
#include <time.h>

#define N 10

using namespace std;
using namespace System;

void GenerarDatos(char** m)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			m[i][j] = 65 + rand() % 26;
		}
	}
}

void mostrarDatos(char** m)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << "[" << m[i][j] << "]";
		}
		cout << endl;
	}
}

char ingresarLetra()
{
	char letra;
	do
	{
		cout << "Ingrese una consonante: "; cin >> letra;
		letra = toupper(letra);
	} while ((letra <= 65 || letra >= 88) || (letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U'));
	
	return letra;
}

char obtenerConsonante(char cons)
{
	if (char(cons + 1) == 'A' || char(cons + 1) == 'E' || char(cons + 1) == 'I' || char(cons + 1) == 'O' || char(cons + 1) == 'U')
		return cons + 2;
	else
		return cons + 1;
}	

void buscarPatron(char** m, char l1, char l2, char l3)
{
	int cont = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			cout << "se encontro en la fila: " << i + 1 << ", columna " << j + 1 << endl;
			cont++;
		}
	}

	cout << "Cantidad de patrones encontrados: " << cont++;
}



int main()
{
	//crear filas de la matriz
	char** matriz = new char* [N];

	for (int i = 0; i < N; i++)
	{
		matriz[i] = new char[N];
	}

	GenerarDatos(matriz);
	mostrarDatos(matriz);
	
	char letra1, letra2, letra3;

	letra1 = ingresarLetra();
	cout << "Letra ingresada: " << letra1 << endl;
	letra2 = obtenerConsonante(letra1);
	letra3 = obtenerConsonante(letra2);
	cout << "Obtener consonantes: " << letra1 << letra2 << letra3;
	
	_getch();
	return 0;
}