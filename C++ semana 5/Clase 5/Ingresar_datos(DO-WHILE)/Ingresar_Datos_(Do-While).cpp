#include <iostream>
#include <conio.h>

using namespace std;

int IngresarNota()
{
	int n;
	do 
	{
		cout << "Ingresar nota: "; cin >> n;
		cout << endl;
	} while (n < 0 || n > 20);
	return n;
}

int IngresarDNI()
{
	int dni;
	do 
	{
		cout << "Ingrese DNI: "; cin >> dni;
		cout << endl;
	} while (dni > 0 || dni < 99999999);
	return dni;
}

int IngresarEdad()
{
	int e;
	do
	{
		cout << "Ingrese edad: "; cin >> e;
		cout << endl;
	} while (e < 0 || e > 100);
	return e;
}

char IngresarGenero()
{
	char g;
	do
	{
		cout << "Ingrese genero: "; cin >> g;
		cout << endl;
	} while (g != 'M' && g != 'F');
	return g;
}

void MostrarDatos(int n, int dni, int e, char g)
{
	cout << endl;
	cout << "La nota ingresada es: " << n << endl;
	cout << "El DNI ingresado es: " << dni << endl;
	cout << "La edad ingresada es: " << e << endl;
	cout << "El genero es: " << g << endl;
}


int main()
{
	int nota, DNI, edad;
	char genero;


	nota = IngresarNota();
	DNI = IngresarDNI();
	edad = IngresarEdad();
	genero = IngresarGenero();
	MostrarDatos(nota, DNI, edad, genero);

	_getch();
	return 0;
}