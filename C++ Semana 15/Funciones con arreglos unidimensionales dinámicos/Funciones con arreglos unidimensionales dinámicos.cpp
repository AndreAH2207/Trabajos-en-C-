#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;

int Ingresa_Cifras()
{
	int longitud_mensaje;
	do {
		cout << "Ingrese la cantidad de cifras del mensaje: "; cin >> longitud_mensaje;
	} while (longitud_mensaje < 20 || longitud_mensaje > 30);
	return longitud_mensaje;
}

void Generar_Mensaje(char* mensaje, int longitud_mensaje)
{
	for (int i = 0; i < longitud_mensaje; i++)
	{
		mensaje[i] =  65 + rand() % 25;
	}
}

void Imprimir_Mensaje(char* mensaje, int longitud_mensaje)
{
	for (int i = 0; i < longitud_mensaje; i++)
	{
		cout << "[" << mensaje[i] << "]";
	}
}

bool Existen_caracteres_inicio_final(char* mensaje, int longitud_mensaje)
{
	
	if (mensaje[0] == 'S' && mensaje[longitud_mensaje-1] == 'W')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Existe_mensaje_alterno(char* mensaje, int longitud_mensaje)
{
	for (int i = 0; i < longitud_mensaje - 4; i++) // evitar desborde
	{
		if (mensaje[i] == 'S' && mensaje[i + 2] == 'I' && mensaje[i + 4] == 'S')
		{
			return true;
			break;
		}
	}
	return false;
}

int main()
{
	srand(time(NULL));

	int longitud_mensaje = Ingresa_Cifras();
	char* mensaje = new char [longitud_mensaje];
	bool SW;
	bool SIS;
	char tecla;
	int cont = 0;

	do {
		Generar_Mensaje(mensaje, longitud_mensaje);
		cout << endl;
		Imprimir_Mensaje(mensaje, longitud_mensaje);
		cout << endl;
		cout << endl;

		SW = Existen_caracteres_inicio_final(mensaje, longitud_mensaje);
		SIS = Existe_mensaje_alterno(mensaje, longitud_mensaje);


		if (SW)
		{
			cout << "Es un alumno de software" << endl;
			cout << "Se encontro en el mensaje numero: " << cont << endl;
			cout << "Presione una tecla para continuar" << endl;
			tecla = getch();
		}

		if (SIS)
		{
			cout << "Es un alumno de sistemas" << endl;
			cout << "Se encontro en el mensaje numero: " << cont << endl;
			cout << "Presione una tecla para continuar" << endl;;
			tecla = getch();
		}

		cont++;

	} while (tecla != 27);


	_getch();
	return 0;
}