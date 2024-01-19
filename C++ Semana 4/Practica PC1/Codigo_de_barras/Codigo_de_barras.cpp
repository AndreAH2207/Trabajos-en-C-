#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

long long codigo_de_barras()
{
	long long cod;

	cout << " Ingrese el codigo de barras: "; cin >> cod;
	return cod;
}

int cod_Pais(long long cod)
{
	return cod / 10000000000;
}


int cod_Empresa(long long cod)
{
	return (cod % 10000000000) / 1000000;
}

int cod_Producto(long long cod)
{
	return ((cod % 10000000000) % 1000000) / 100;
}


int duracion_en_meses(long long cod)
{
	return ((cod % 10000000000) % 1000000) % 100;
}

int main()
{
	long long codigo;
	int pais;
	int empresa;
	int producto;
	int duracion;
	char continente;
	int meses;


	codigo = codigo_de_barras();
	cout << endl;

	pais = cod_Pais(codigo);
	empresa = cod_Empresa(codigo);
	producto = cod_Producto(codigo);
	duracion = duracion_en_meses(codigo);

	if (pais >= 65 && pais <= 74)
	{
		continente = 'A';
	} 
	else if (pais >= 75 && pais <= 79)
	{
		continente = 'E';
	} 
	else if (pais >= 80 && pais <= 90)
	{
		continente = 'O';
	}



	if (duracion >= 0 && duracion < 10)
	{
		meses = 0;
	}
	else if (pais >= 10 && pais <= 20)
	{
		meses = 1;
	}
	else if (pais > 20)
	{
		meses = 2;
	}

	cout << "Codigo de pais: " << pais;
	cout << endl;
	cout << "Continente: " << continente;
	cout << endl;
	cout << "Codigo de la empresa: " << empresa;
	cout << endl;
	cout << "Codigo de producto: " << producto;
	cout << endl;
	cout << "Duracion (meses): " << duracion;
	cout << endl;
	cout << "Probabilidad de venta : (2 = optimo, 1 = promedio, 0 = bajo) : " << meses;


	_getch();
	return 0;
}
