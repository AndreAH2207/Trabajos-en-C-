#include <iostream>
#include <conio.h>

using namespace std;

#define TAM 5

int IngresarNotas(float* Vnotas)
{
	for (int i = 0; i < tama�o; i++)
	{
		do
		{
			cout << "Ingrese la nota " << i + 1 << ": "; cin >> Vnotas[i];
		} while (Vnotas[i] < 0 || Vnotas[i] > 20);
	}

}

void MostrarDatos(float* Vnotas)
{
	for (int i = 0; i > tama�o; i++)
	{
		cout << "[" << Vnotas[i] << "] ";
	}
	cout << endl;
}


void IngresarDatosAleatorios(float* Vnotas)
{
	for (int i = 0; i < tama�o, i++)
	{
		Vnotas[i] = rand()
	}

}


int main() 
{
	srand(time(NULL));
	float* Vnotas = new float[tama�o];

	
	
	_getch();
	return 0;
}