#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int IngresarCantidad()
{
	int n;
	do
	{
		cout << "Ingrese la cantidad de ventas del dia: "; cin >> n;
	} while (n < 1 || n>100);
	return n;
}	

void GenerarDatos(int* vc, int* vca, float* vp, int n)
{
	for (int i = 0; i < n; i++)
	{
		vc[i] = 1000 + rand() % 100;
		vca[i] = 1 + rand() % 100;
		vp[i] = 1 + rand() % 5010 / 10.0;
	}
}

void MostrarDatos(int* vc, int* vca, float* vp, float* vv, int n)
{
	cout << endl;
	cout << "Codigo\tCantidad\tPrecio\t\tVentas" << endl;
 	for (int i = 0; i < n; i++)
	{
		cout << "[" << vc[i] << "]\t  [" << vca[i] << "]\t\t[" << vp[i] << "]\t\t[" << vv[i] << "]" << endl;
	}
}

void generarReporte(int* vc, int* vca, float* vp, float* vv, int n)
{
	int mayorV = vv[0];
	int mayorP = vp[0];
	int codigoMayorV = vc[0];
	int codigoMayorP = vp[0];
	float suma = 0;

	for (int i = 0; i < n; i++)
	{
		if (vv[i] > mayorV)
		{
			mayorV = vv[i];
			codigoMayorV = vc[i];
		}
		if (vp[i] > mayorP)
		{
			mayorP = vp[i];
			codigoMayorP = vc[i];
		}
		suma += vv[i];
	}
	cout << endl;
	cout << "Total en soles vendidos                        =" << suma << endl;
	cout << "Codigo del producto que produjo mayor ingreso  =" << codigoMayorV << endl;
	cout << "Venta mayor                                    =" << mayorV << endl;
	cout << "Codigo del producto mas caro                   =" << codigoMayorP << endl;
	cout << "Costo del producto mas caro                    =" << mayorP << endl;

}

void ObtenerVentas(int* vca, float* vp, float* vv, int n)
{
	for (int i = 0; i < n; i++)
	{
		vv[i] = vca[i] * vp[i];
	}
}

int main()
{
	srand(time(NULL));
	int n = IngresarCantidad();
	int* vcodigos = new int[n];
	int* vcantidades = new int[n];
	float* vprecios = new float[n];
	float* vventas = new float[n];
	GenerarDatos(vcodigos, vcantidades, vprecios, n);
	ObtenerVentas(vcantidades, vprecios, vventas, n);
	MostrarDatos(vcodigos, vcantidades, vprecios, vventas, n);
	generarReporte(vcodigos, vcantidades, vprecios, vventas, n);

	_getch();
	return 0;
}