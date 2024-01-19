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

void dibujar_cuadrado_relleno(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
}

void dibujar_cuadrado_sin_relleno(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
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

void dibujar_cuadrado_con_diagonal(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 || j == 0 || i == n - 1 || j == n - 1 || i == j)
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
	dibujar_cuadrado_relleno(n);
	cout << endl;
	dibujar_cuadrado_sin_relleno(n);
	cout << endl;
	dibujar_cuadrado_con_diagonal(n);

	_getch();
	return 0;
}