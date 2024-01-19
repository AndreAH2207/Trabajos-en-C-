#include <iostream>
#include <conio.h>

using namespace std;

long long IngresarCodigo()
{
	long long c;
	cout << "Ingrese numero de 16 digitos: "; cin >> c;
	return c;
}

int DiaNacimiento(long long c)
{
	return c = c / 100000000000000;
}

int MesNacimiento(long long c)
{
	return c = (c % 100000000000000)/1000000000000;
}

int AnioNacimiento(long long c)
{
	return c = ((c % 100000000000000) % 1000000000000)/100000000;
}

int Edad(long long c)
{
     return c = (((c % 100000000000000) % 1000000000000) % 100000000)/1000000;
}

int TipodeContrato(long long c)
{
	return c = ((((c % 100000000000000) % 1000000000000) % 100000000) % 1000000)/100000;
}

int Sexo(long long c)
{
	return c = (((((c % 100000000000000) % 1000000000000) % 100000000) % 1000000) % 100000)/10000;
}

int Inicio(long long c)
{
	return c = (((((c % 100000000000000) % 1000000000000) % 100000000) % 1000000) % 100000) % 10000;
}


int main()
{
	int DD, MM, AAAA, EE, ZZZZ, T, S;
	char Tipo, Gen;
	long long codigo;

	codigo = IngresarCodigo();
	
	DD = DiaNacimiento(codigo);
	MM = MesNacimiento(codigo);
	AAAA = AnioNacimiento(codigo);
	EE = Edad(codigo);
	T = TipodeContrato(codigo);
	S = Sexo(codigo);
	ZZZZ = Inicio(codigo);



	cout << endl;
	cout << "Dia de nacimiento: " << DD << endl;
	cout << "MesNacimiento: " << MM << endl;
	cout << "Anio de nacimiento: " << AAAA << endl;
	cout << "Edad: " << EE << endl;	


	if (EE < 18 && EE >= 0)
	{
		cout << "Tipo de contrato: 0" << endl;
		cout << "Sexo: X" << endl;
		cout << "Anio de inicio de contrato: 0" << endl;
		cout << "Tipo de tarjeta: X" << endl;
		cout << "Tasa creditica: 0" << endl;

		_getch();
		return 0;
	}

	if (T == 1)
	{
		Tipo = 'C';
	}
	else if (T == 0)
	{
		Tipo = 'P';
	}
	else
		Tipo = '?';

	cout << "Tipo de contrato: " << Tipo << endl;

	if (S == 0)
	{
		Gen = 'M';
	}
	else if (S == 1)
	{
		Gen = 'H';
	}
	else
		Gen = '?';

	cout << "Sexo: " << Gen << endl;
	cout << "Anio de inicio de contrato: " << ZZZZ << endl;

	if (ZZZZ <= 2011)
	{
		cout << "Tipo de tarjeta: O" << endl;
	}
	else if (ZZZZ <= 2017 && ZZZZ >= 2012)
	{
		cout << "Tipo de tarjeta: P" << endl;
	}
	else if (ZZZZ <= 2021 && ZZZZ > 2017)
	{
		cout << "Tipo de tarjeta: B" << endl;
	}


	if (EE > 60)
	{
		cout << "Tasa crediticia: 15%" << endl;
	}
	else if (EE >= 40 && EE <= 60)
	{
		cout << "Tasa crediticia: 12%" << endl;
	}
	else if (EE >= 18 && EE <= 39)
	{
		cout << "Tasa creditica: 10%" << endl;
	}
	else
		cout << "No hay tasa crediticia " << endl;


	_getch();
	return 0;
}