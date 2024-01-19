#include <iostream>
#include <conio.h>

using namespace std;

int IngresarCant()
{
	int n;
	do
	{
		cout << " Ingrese la cantidad de letras: "; cin >> n;
	} while (n < 1);
	return n;
}

void IngresarMensaje(char* vl, int n)
{
	for (int i = 0; i < n; i++)
	{
		cin.get(vl[i]);
	}
}

void CalcularPago(char* vl, int n)
{
	int cl = 0, cn = 0, cce = 0;
	for (int i = 0; i < n; i++)
	{
		if((vl[i] >= 65 && vl[i] <= 90) || (vl[i] <=))
	}

}

int main()
{
	int n = IngresarCant();
	char* vletras = new char[n];
	IngresarMensaje(vletras, n);



	_getch();
	return 0;
}