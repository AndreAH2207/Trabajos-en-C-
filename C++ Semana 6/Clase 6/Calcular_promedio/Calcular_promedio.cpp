#include <iostream>
#include <conio.h>

using namespace std;

int IngreseCantidadAlumnos()
{
	int n;
	do 
	{
		cout << "Ingrese cantidad de alumnos: "; cin >> n;
	} while (n < 1);
	return n;
}

float IngresaNota(string msje)
{
	float nota;
	do
	{
		cout << msje; cin >> nota;
	} while (nota < 0 || nota > 20);
	return nota;
}

void ObtenerPromedio(int n)
{
	float EF, EP, TF, prom = 0;
	int cont = 0;

	while (cont < n)
	{
		EF = IngresaNota("Ingrese la nota del examen final: ") ;
		EP = IngresaNota("Ingrese la nota del examen parcial: ");
		TF = IngresaNota("Ingrese la nota del trabajo final: ");

		cout << "Promedio del alumno " << cont + 1 << " = "
			 << (EF * 0.55 + EP * 0.30 + TF * 0.15) << endl;
		cout << "====================================================" << endl;
		cont++;
	}
}

int main()
{
	int n, cont = 0;
	float EF, EP, TF, prom = 0;

	n = IngreseCantidadAlumnos();
	cout << "====================================================" << endl;
	ObtenerPromedio(n);

	_getch();
	return 0;
}