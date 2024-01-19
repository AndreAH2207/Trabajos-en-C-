#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;

char s[2] = { 'M','F' };
char sv[3] = { 'E','P','F' };
char niv[3] = { 'B','R','M' };

struct Clientes
{
	int edad;
	char sexo;
	char servicio;
	char nivel;
};


int IngresarCant()
{
	int n;
	do
	{
		cout << "Ingresa la cantidad de clientes: "; cin >> n;
	} while (n < 1 || n > 70);
	return n;
}

void GenerarDatos(Clientes* vclientes, int n)
{
	Random r;

	for (int i = 0; i < n; i++)
	{
		vclientes[i].edad = r.Next(18, 75);
		vclientes[i].sexo = s[rand() % 2];
		vclientes[i].servicio = sv[rand() % 3];
		vclientes[i].nivel = niv[rand() % 3];
	}
}

void ImprimirDatos(Clientes* vclientes, int n)
{
	cout << "Edad\tSexo\tServicio\tNivel" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "[" << vclientes[i].edad << "]\t [" << vclientes[i].sexo << "]\t  [" << vclientes[i].servicio << "]\t\t [" << vclientes[i].nivel << "]" << endl;
	}
}

void hallar_mayor_y_cuantos(Clientes* vclientes, int n)
{
	int cont = 0;
	int mayor = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (vclientes[i].edad > vclientes[j].edad)
			{
				vclientes[i].edad = mayor;
			}
		}
	}
	cout << "El cliente con mayor edad es: " << mayor;
}

void porcentaje_servicios(Clientes* vclientes, int n)
{
	int cont = 0;
	int porc = 0;

	for (int i = 0; i < n; i++)
	{
		if (vclientes[i].edad > 30 && vclientes[i].sexo == 'M')
		{
			cont++;   
		}
	}

	porc = (cont / n) * 100;

	cout << "El porcentaje de personas mayores de 30 es: " << porc << endl;
}

void promedio_edad_por_nivel(Clientes* vclientes, int n)
{
	int c1 = 0;
	int c2 = 0;
	int c3 = 0;
	int suma1 = 0;
	int suma2 = 0;
	int suma3 = 0;
	int prom1 = 0;
	int prom2 = 0;
	int prom3 = 0;

	for (int i = 0; i < n; i++)
	{
		if (vclientes[i].nivel == 'B')
		{
			c1++;
			suma1 += vclientes[i].edad;
		}
		if (vclientes[i].nivel == 'M')
		{
			c2++;
			suma2 += vclientes[i].edad;
		}
		if (vclientes[i].nivel == 'R')
		{
			c3++;
			suma3 += vclientes[i].edad;
		}
	}
	prom1 = suma1 / c1;
	prom2 = suma2 / c2;
	prom3 = suma3 / c3;

	cout << "El promedio de edad para los clientes con satisfaccion buena es  : " << prom1 << endl;
	cout << "El promedio de edad para los clientes con satisfaccion regular es: " << prom2 << endl;
	cout << "El promedio de edad para los clientes con satisfaccion mala es   : " << prom3 << endl;
}

void OrdenarDescendente(Clientes* vclientes, int n)
{
	int aux1;
	char aux2;
	char aux3;
	char aux4;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (vclientes[i].servicio < vclientes[j].servicio)
			{
				aux1 = vclientes[i].edad;
				vclientes[i].edad = vclientes[j].edad;
				vclientes[j].edad = aux1;

				aux2 = vclientes[i].nivel;
				vclientes[i].nivel = vclientes[j].nivel;
				vclientes[j].nivel = aux2;

				aux3 = vclientes[i].servicio;
				vclientes[i].servicio = vclientes[j].servicio;
				vclientes[j].servicio = aux3;

				aux4 = vclientes[i].sexo;
				vclientes[i].sexo = vclientes[j].sexo;
				vclientes[j].sexo = aux4;

			}
		}
	}
}

int main()
{
	srand(time(NULL));
	int n = IngresarCant();
	cout << endl;
	Clientes* vclientes = new Clientes[n];
	GenerarDatos(vclientes, n);
	ImprimirDatos(vclientes, n);
	cout << endl;
	cout << "===================HALLAR EDAD MAYOR Y CUANTOS SON=========================";
	cout << endl;
	hallar_mayor_y_cuantos(vclientes, n);
	cout << endl;
	cout << "===================HALLAR EDAD MAYOR Y CUANTOS SON=========================";
	cout << endl;
	porcentaje_servicios(vclientes, n);
	cout << endl;
	cout << "===================HALLAR EDAD MAYOR Y CUANTOS SON=========================";
	cout << endl;
	promedio_edad_por_nivel(vclientes, n);
	cout << endl;
	cout << "===================ORDENAR DE MANERA DESCENDENTE=========================";
	cout << endl;
	OrdenarDescendente(vclientes, n);
	ImprimirDatos(vclientes, n);

	_getch();
	return 0;
}
