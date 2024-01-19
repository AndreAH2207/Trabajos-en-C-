#include <iostream>
#include <conio.h>

using namespace std;

int IngresarNumero()
{
	int n;
	do
	{
		cout << "Ingrese un numero positivo menor a 10: "; cin >> n;
	} while (n < 2 || n > 10);
	return n;
}



void dibujar_triangulo_sin_relleno(int n)
{
	for (int fil = 0; fil < n; fil++)
	{
		for (int col = 0; col < n; col++)
		{
			if (col == 0 || fil == n - 1 || fil == col)
			{
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}
}

void dibujar_triangulo_de_numeros(int n)
{
	for (int fil = 0; fil < n; fil++)
	{
		for (int col = 0; col < n; col++)
		{
			if (fil >= col)
			{
				cout << col + 1  << " ";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}
}

void dibujar_triangulo_de_asteriscos(int n)
{
	for (int fil = 0; fil < n; fil++)
	{
		for (int col = 0; col < n - fil; col++)
		{
			cout << "* ";
		}
		cout << endl;
	}
}

void dibujar_triangulo_y_su_invertido(int n)
{
	for (int fil = 0; fil < n; fil++)
	{
		for (int col = 0; col < n; col++)
		{
			if (col == 0 || fil == n - 1 || fil == col)
			{
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}

	for (int fil = 1; fil < n; fil++)
	{
		for (int col = 0; col < n; col++)
		{
			if (fil == 0 || fil == col || col == n - 1)
			{ 
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}
}


int main()
{
	int n;
	n = IngresarNumero();
	cout << endl;
	dibujar_triangulo_sin_relleno(n);
	cout << endl;
	dibujar_triangulo_de_numeros(n);
	cout << endl;
	dibujar_triangulo_de_asteriscos(n);
	cout << endl;
	dibujar_triangulo_y_su_invertido(n);
	cout << endl;

	_getch();
	return 0;
}