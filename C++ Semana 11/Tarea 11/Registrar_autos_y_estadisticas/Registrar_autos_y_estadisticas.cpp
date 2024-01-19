#include <iostream>
#include <conio.h>

using namespace std;


struct Auto
{
	int serie;
	char modelo;
	char color;
};

int IngresarCant() {
	int n;
	do {
		cout << "Ingrese la cantidad de autos: ";
		cin >> n;
	} while (n < 1 || n>200);
	return n;
}

void GenerarDatos(Auto* va, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		do {
			cout << "Ingrese el numero de serie del motor del auto " << i + 1 << " (Entero de 6 digitos) : "; cin >> va[i].serie;
		} while (va[i].serie < 100000 || va[i].serie > 999999);

		do
		{
			cout << "Ingrese el caracter inicial del modelo de auto " << i + 1 << " (Rav4, Corolla, Yaris, Prius) : "; cin >> va[i].modelo;
			va[i].modelo = toupper(va[i].modelo);
		} while (va[i].modelo != 'R' && va[i].modelo != 'C' && va[i].modelo != 'Y' && va[i].modelo != 'P');

		do
		{
			cout << "Ingrese el caracter inicial del color del auto " << i + 1 << " (Plateado, Rojo, Negro) : "; cin >> va[i].color;
			va[i].color = toupper(va[i].color);
		} while (va[i].color != 'P' && va[i].color != 'R' && va[i].color != 'N');
	}
}

void MostrarDatos(Auto* va, int n)
{
	cout << " Serie      Modelo     Color" << endl;
 
	for (int i = 0; i < n; i++)
	{
		cout << "[" << va[i].serie << "]     [" << va[i].modelo << "]\t[" << va[i].color << "]" << endl;
	}
}


int main()
{
	int n = IngresarCant();
	Auto* vauto = new Auto[n];
	GenerarDatos(vauto, n);
	cout << endl;
	cout << endl;
	MostrarDatos(vauto, n);

	delete vauto;
	_getch();
	return 0;
}