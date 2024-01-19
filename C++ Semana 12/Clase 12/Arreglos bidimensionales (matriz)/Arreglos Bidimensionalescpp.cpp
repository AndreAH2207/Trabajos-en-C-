#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;

void dibujatablero(char tablero[][8])
{
	for (int esp = 0; esp < 36; esp++)
		cout << ' ';
	cout << "01234567\n";
	for (int fila = 0; fila < 8; fila++)
	{
		for (int esp = 0; esp < 36; esp++)
			cout << ' ';

		for (int col = 0; col < 8; col++)
			cout << tablero[fila][col];
		cout << endl;
	}
}

void main()
{
	char tablero[8][8] =
	{
		{' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
		{'b', ' ', 'b', ' ', 'b', ' ', 'b', ' '},
		{' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{'r', ' ', 'r', ' ', 'r', ' ', 'r', ' '},
		{' ', 'r', ' ', 'r', ' ', 'r', ' ', 'r'},
		{'r', ' ', 'r', ' ', 'r', ' ', 'r', ' '},
	};

	int inix, iniy, finx, finy;
	while (1)
	{
		Console::Clear();
		dibujatablero(tablero);
		_sleep(50);
		cout << "Ingrese posicion inicial (col,fil) : ";
		cin >> iniy >> inix;
		cout << "Ingrese posicion final(col,fil) : ";
		cin >> finy >> finx;
		if (abs(iniy - finy) <= 1 && abs(inix - finx <= 1))
			tablero[finx][finy] = tablero[inix][iniy];
		tablero[inix][iniy] = ' ';
		_getch();
	}
}
