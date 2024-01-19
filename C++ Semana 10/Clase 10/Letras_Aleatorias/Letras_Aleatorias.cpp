#include <iostream>
#include <conio.h>

using namespace std;

char vcolor[3] = { 'N', 'P', 'R' };

int IngresarCantidad()
{
	int n;
	do
	{
		cout << "Ingrese la cantidad de letras: "; cin >> n;
	} while (n < 1);
	return n;
}

void GenerarLetras(char* vl, int n)
{
	int cont = 1;
	for (int i = 0; i < n; i++)
	{
		do
		{
			vl[i] = 78 + rand() % 5;
			cont++;
		} while (vl[i] != 'N' && vl[i] != 'P' && vl[i] != 'R');
	}
	cout << endl;
	cout << "Cantidad de veces dentro del while: " << cont << endl;
	cout << endl;
}
void MostrarLetras(char* vl, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "[" << vl[i] << "]";
	}
	cout << endl;
}

void GenerarLetras2(char* vl, int n)
{
	for (int i = 0; i < n; i++)
	{
		vl[i] = vcolor[rand() % 3];
		cout << "[" << vl[i] << "]";
	}
}



int main()
{
	int n = IngresarCantidad();
	char* vletras = new char[n];
	GenerarLetras(vletras, n);
	MostrarLetras(vletras, n);
	GenerarLetras2(vletras, n);
	_getch();
	return 0;
}