#include <iostream>
#include <conio.h>

using namespace std;

int IngresarCantidad()
{
	int personas;
	do
	{
		cout << " Ingrese la cantidad de personas: "; cin >> personas;
	} while (personas < 1);
	return personas;
}

void GenerarDatos(int personas, float* vpesos)
{
	for (int i = 0; i < personas; i++)
	{
		vpesos[i] = 40 + (rand() % 701) / 10.0;
	}
}

void MostrarDatos(int personas, float* vpesos)
{
	cout << endl;
	cout << " =========== Pesos ===========" << endl;
	cout << endl;

	for (int i = 0; i < personas; i++)
	{
		cout << " [" << vpesos[i] << "]";
	}
	cout << endl;
}

void Promedio(int personas, float* vpesos)
{
	float suma = 0;
	float promedio = 0;
	for (int i = 0; i < personas; i++)
	{
		suma += vpesos[i];
	}
	promedio = suma / personas;

	cout << endl;
	cout << " * El promedio de pesos es: " << promedio << " kilos" << endl;
}

void PesoMaximo(int personas, float* vpesos)
{
	float maximo = vpesos[0];
	for (int i = 0; i < personas; i++)
	{
		if (vpesos[i] > maximo)
		{
			maximo = vpesos[i];
		}
	}
	cout << " * El peso maximo es: " << maximo << endl;
}

void PesoMinimo(int personas, float* vpesos)
{
	float minimo = vpesos[0];
	for (int i = 0; i < personas; i++)
	{
		if (vpesos[i] < minimo)
		{
			minimo = vpesos[i];
		}
	}
	cout << " * El peso minimo es: " << minimo << endl;
}

void Reporte_Contextura_Personas(int personas, float* vpesos)
{
	int cpd = 0;
	int cpm = 0;
	int cpg = 0;

	for (int i = 0; i < personas; i++)
	{
		if (vpesos[i] < 53)
		{
			cpd++;
		}
		else if (vpesos[i] >= 53 && vpesos[i] <= 60)
		{
			cpm++;
		}
		else if (vpesos[i] > 60)
		{
			cpg++;
		}
	}
	cout << endl;
	cout << " * El numero de personas cuya contextura es delgada es: " << cpd << endl;
	cout << " * El numero de personas cuya contextura es mediana es: " << cpm << endl;
	cout << " * El numero de personas cuya contextura es gruesa es: " << cpg << endl;
}

int main()
{
	srand(time(NULL));

	int personas = IngresarCantidad();
	float* vpesos = new float[personas];

	GenerarDatos(personas, vpesos);
	MostrarDatos(personas, vpesos);
	Promedio(personas, vpesos);
	PesoMaximo(personas, vpesos);
	PesoMinimo(personas, vpesos);
	Reporte_Contextura_Personas(personas, vpesos);

	delete vpesos;
	_getch();
	return 0;
}
