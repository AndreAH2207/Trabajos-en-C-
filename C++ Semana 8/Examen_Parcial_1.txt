#include <iostream>
#include <conio.h>

using namespace std;

char Destino()
{
	char dest;
	do {
		cout << "Ciudad elegida (N: Nagoya; K: Kioto; O: Osaka): "; cin >> dest;
		dest = toupper(dest);
	} while (dest != 'N' && dest != 'K' && dest != 'O');
	return dest;
}

char Transporte()
{
	char tr;
	do {
		cout << "Medio de Transporte (T: Tren; B: Bus): "; cin >> tr;
		tr = toupper(tr);
	} while (tr != 'T' && tr != 'B');
	return tr;
}

char Tipo()
{
	char t;

	do {
		cout << "Tipo de Tren (N: Nozomi; H: Hikari; O: otros): "; cin >> t;
		t = toupper(t);
	} while (t != 'N' && t != 'H' && t != 'O');
	return t;

}

int Dia()
{
	int dia;

	do {
		cout << "Dia en que realizo la compra : "; cin >> dia;

	} while (dia < 1 || dia > 31);
	return dia;
}

int Mes()
{
	int mes;

	do {
		cout << "Mes en que realizo la compra:  "; cin >> mes;

	} while (mes < 1 || mes > 12);
	return mes;
}

float Precio_Tren(int destino, char tipo, int precio)
{

	if (tipo == 'N' && destino == 'N')
	{
		precio = 9750;
	}
	else if (tipo == 'H' && destino == 'N')
	{
		precio = 6750;
	}
	else if (tipo == 'O' && destino == 'N')
	{
		precio = 6000;
	}
	else if (tipo == 'N' && destino == 'K')
	{
		precio = 13000;
	}
	else if (tipo == 'H' && destino == 'K')
	{
		precio = 9000;
	}
	else if (tipo == 'O' && destino == 'K')
	{
		precio = 8000;
	}
	else if (tipo == 'N' && destino == 'O')
	{
		precio = 14300;
	}
	else if (tipo == 'H' && destino == 'O')
	{
		precio = 9900;
	}
	else if (tipo == 'O' && destino == 'O')
	{
		precio = 8800;
	}
	return precio;
}

int ValidarFecha (int dia, int mes, int precio)
{
	if (mes == 3 && dia >= 21)
	{
		precio = precio + (precio * 0.10);
	}

	if (mes == 4 && dia <= 5)
	{
		precio = precio + (precio * 0.10);
	}

	return precio;
}


float ValidarPrecio(char destino, char transporte, char tipo, int dia, int mes)
{
	float precio;

	destino = Destino();
	transporte = Transporte();
	if (transporte == 'T')
	{
		tipo = Tipo();
	}
	dia = Dia();
	mes = Mes();


	switch (destino)
	{
	case 'N':

		if (transporte == 'B')
		{
			precio = 4875;
			precio = ValidarFecha(dia, mes, precio);
		}
		else
		{
			precio = Precio_Tren(destino, tipo, precio);
			precio = ValidarFecha(dia, mes, precio);
		}

		break;

	case 'K':

		if (transporte == 'B')
		{
			precio = 6500;
			precio = ValidarFecha(dia, mes, precio);

		}
		else
		{
			precio = Precio_Tren(destino, tipo, precio);
			precio = ValidarFecha(dia, mes, precio);
		}
		break;

	case 'O':

		if (transporte == 'B')
		{
			precio = 7150;
			precio = ValidarFecha(dia, mes, precio);
		}
		else
		{
			precio = Precio_Tren(destino, tipo, precio);
			precio = ValidarFecha(dia, mes, precio);
		}
		break;
	default:
		break;
	}
	return precio;
}

int main()
{
	char destino, transporte, tipo; 
	int dia, mes, precio;

	precio = ValidarPrecio(destino, transporte, tipo, dia, mes);

	cout << endl;
	cout << "Precio de entrada ($Y): " << precio << endl;
	cout << endl;

	_getch();
	return 0;
}