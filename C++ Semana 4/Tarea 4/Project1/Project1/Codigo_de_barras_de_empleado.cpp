#include <iostream>
#include <conio.h>

using namespace std;

long long Ingrese_codigo()
{
	long long cod;
	cout << "Ingrese codigo del empleado: "; cin >> cod;
	return cod;
}

int Primera_letra_nombre(long long cod)
{
	return cod = cod / 10000000000;
}

int Primera_letra_apellido_paterno(long long cod)
{
	return cod = (cod % 10000000000) / 100000000;
}

int Primera_letra_apellido_materno(long long cod)
{
	return cod = ((cod % 10000000000) % 100000000) / 1000000;
}

int Hora_entrada(long long cod)
{
	return cod = (((cod % 10000000000) % 100000000) % 1000000)/10000;
}

int Minuto_entrada(long long cod)
{
	return cod = ((((cod % 10000000000) % 100000000) % 1000000) % 10000) / 100;
}


int Segundo_entrada(long long cod)
{
	return cod = ((((cod % 10000000000) % 100000000) % 1000000) % 10000) % 100;
}

int Llego_tarde(int h)
{
	if (h < 9)
	{
		return false;
	}
	else if (h >= 9)
	{
		return true;
	}
}

int main ()
{
	long long codigo;
	int HH, MM, SS, Llegada;
	char NN, PP, AA;

	codigo = Ingrese_codigo();

	NN = Primera_letra_nombre(codigo);
	PP = Primera_letra_apellido_paterno(codigo);
	AA = Primera_letra_apellido_materno(codigo);
	HH = Hora_entrada(codigo);
	MM = Minuto_entrada(codigo);
	SS = Segundo_entrada(codigo);
	Llegada = Llego_tarde(HH);

	cout << endl;
	cout << " Hora de entrada: " << HH << endl;
	cout << " Minutos de entrada: " << MM << endl;
	cout << " Segundos de entrada: " << SS << endl;
	cout << " Su nombre empieza con la letra: " << NN << endl;
	cout << " Su apellido paterno empieza con la letra: " << PP << endl;
	cout << " Su apellido materno empieza con la letra: " << AA << endl;
	cout << endl;
	cout << " Llego tarde(1:si, 0:no): " << Llegada << endl;

	_getch();
	return 0;
}