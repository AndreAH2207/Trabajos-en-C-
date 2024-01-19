#include <iostream>
#include <conio.h>


using namespace std;

char Ingresar_zona(string msj)
{
	char zona;
	cout << msj; cin >> zona;
	zona = toupper(zona);

	return zona;
}

int Ingresar_numero_de_entradas(string msj)
{
	int entradas;
	cout << msj; cin >> entradas;
	return entradas;
}

char Ingresar_Descuento_por_socio(string msj)
{
	char socio;
	cout << msj; cin >> socio;
	socio = toupper(socio);
	return socio;
}

float calcular_precio(char zona, int entradas, char socio)
{
	float precio;

	switch (socio)
	{
	case 'S':
		switch (zona)
		{
		case 'V':
			precio = 350;
			if (entradas >= 1 && entradas <= 2)
			{
				precio = (precio * entradas) - (precio* entradas) * 0.08;
			}
			if (entradas >= 3 && entradas <= 6)
			{
				precio = (precio * entradas) - (precio * entradas * 0.13);
			}
			else if (entradas >= 7 && entradas <= 9)
			{
				precio = (precio * entradas) - (precio * entradas * 0.155);
			}
			else if (entradas >= 9)
			{
				precio = (precio * entradas) - (precio * entradas * 0.18);
			}
			break;

		case 'E':
			precio = 50;
			if (entradas >= 1 && entradas <= 2)
			{
				precio = (precio * entradas) - (precio * entradas) * 0.08;
			}
			if (entradas >= 3 && entradas <= 6)
			{
				precio = (precio * entradas) - (precio * entradas * 0.13);
			}
			else if (entradas >= 7 && entradas <= 9)
			{
				precio = (precio * entradas) - (precio * entradas * 0.155);
			}
			else if (entradas >= 9)
			{
				precio = (precio * entradas) - (precio * entradas * 0.18);
			}
			break;
		case 'P':
			precio = 130;
			if (entradas >= 1 && entradas <= 2)
			{
				precio = (precio * entradas) - (precio * entradas) * 0.08;
			}
			else if (entradas >= 3 && entradas <= 6)
			{
				precio = (precio * entradas) - (precio * entradas * 0.13);
			}
			else if (entradas >= 7 && entradas <= 9)
			{
				precio = (precio * entradas) - (precio * entradas * 0.155);
			}
			else if (entradas >= 9)
			{
				precio = (precio * entradas) - (precio * entradas * 0.18);
			}
			break;


		default: precio = 0; 
			break;
		}
		break;
	case 'N':

		switch (zona)
		{
		case 'V':
			precio = 350;
			if (entradas >= 3 && entradas <= 6)
			{
				precio = (precio * entradas) - precio * entradas * 0.05;
			}
			else if (entradas >= 7 && entradas <= 9)
			{
				precio = (precio*entradas) - precio * entradas * 0.075;
			}
			else if (entradas >= 9)
			{
				precio = (precio * entradas) - precio * entradas * 0.10;

			}
			break;

		case 'E':
			precio = 50;
			if (entradas >= 3 && entradas <= 6)
			{
				precio = (precio * entradas) - precio * entradas * 0.05;
				;
			}
			else if (entradas >= 7 && entradas <= 9)
			{
				precio = (precio * entradas) - precio * entradas * 0.075;

			}
			else if (entradas >= 9)
			{
				precio = (precio * entradas) - precio * entradas * 0.10;
			}
			break;
		case 'P':
			precio = 130;
			if (entradas >= 3 && entradas <= 6)
			{
				precio = (precio * entradas) - precio * entradas * 0.05;

			}
			else if (entradas >= 7 && entradas <= 9)
			{
				precio = (precio * entradas) - precio * entradas * 0.075;

			}
			else if (entradas >= 9)
			{
				precio = (precio * entradas) - precio * entradas * 0.10;

			}
			break;
		default: precio = 0; 
			break;
		}
		break;
	default: precio = 0;
		break;
	}
	return precio;
}

int main()
{
	float precio;
	char zona;
	int entradas;
	char socio;
	
	zona = Ingresar_zona("Ingrese la zona elegida (Vip, Platea, Popular): ");
	entradas = Ingresar_numero_de_entradas("Ingrese el numero de entradas: ");
	socio = Ingresar_Descuento_por_socio("Es socio de la U (S: si; N: no): ");
	cout << endl;
	cout << "El monto a pagar es: " << calcular_precio(zona, entradas, socio);

	_getch();
	return 0;
}