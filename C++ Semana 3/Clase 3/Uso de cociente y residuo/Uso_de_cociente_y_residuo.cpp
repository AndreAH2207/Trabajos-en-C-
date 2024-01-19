#include <iostream>
#include <conio.h>

using namespace std;

int IngresarCantidad()
{
	int s;
	cout << " Ingrese la cantidad de sobres "; cin >> s;
	return s;
}

int obtenerP50(int s)
{
	return s / 50;
}

int obtenerP30(int s)
{
	return (s % 50) / 30;
}

int obtenerP12(int s)
{
	int sobrante;

	if ((((s % 50) % 30) / 12) != 0)
	{
		sobrante = 1;
	}
	else
		sobrante = 0;
	
	return sobrante + ((s % 50)%30)/12;
}

void MostrarDatos(int e50, int e30, int e12)
{
	cout << " Paquetes de 50 " << e50 << endl;
	cout << " Paquetes de 30 " << e30 << endl;
	cout << " Paquetes de 12 " << e12 << endl;

}


int main()
{

	int p30, p12, p50, sobres;
	
	sobres = IngresarCantidad();
	p50 = obtenerP50(sobres);
	p30 = obtenerP30(sobres);
	p12 = obtenerP12(sobres);

	cout << endl;
	cout << endl;
	MostrarDatos(p50, p30, p12);

	_getch();
	return 0;
}