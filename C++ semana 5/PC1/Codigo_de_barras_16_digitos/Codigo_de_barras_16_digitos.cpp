#include <iostream>
#include <conio.h>

using namespace std;

long long Ingresar_codigo()
{
	long long cod;
	cout << "Ingrese codigo: "; cin >> cod;
	return cod;
}

int Tipo_Celular(long long cod)
{
	return cod = cod / 1000000000000;	
}

int Horas_Celular(long long cod)
{
	return cod = (cod % 1000000000000) / 10000000000;
}

int Minutos_Celular(long long cod)
{
	return cod = ((cod % 1000000000000) % 10000000000)/100000000;
}

int Tipo_Fijo(long long cod)
{
	return cod = (((cod % 1000000000000) % 10000000000) % 100000000) / 10000;
}

int Horas_Fijo(long long cod)
{
	return cod = ((((cod % 1000000000000) % 10000000000) % 100000000)% 10000) / 100;
}

int Minutos_Fijo(long long cod)
{
	return cod = ((((cod % 1000000000000) % 10000000000) % 100000000) % 10000) % 100;
}

int main()
{
	char PPPP_F, PPPP_C;
	int min_f, min_cel;
	int hor_f, hor_cel;
	long long codigo;
	float montoF, montoC, montoT;

	codigo = Ingresar_codigo();

	PPPP_C = Tipo_Celular(codigo);
	hor_cel = Horas_Celular(codigo);
	min_cel = Minutos_Celular(codigo);
	PPPP_F = Tipo_Fijo(codigo);
	hor_f = Horas_Fijo(codigo);
	min_f = Minutos_Fijo(codigo);

	montoF = (0.15 * min_f) + ((hor_f * 60) * 0.15);
	montoC = (0.35 * min_cel) + ((hor_cel * 60) * 0.35);
	montoT = montoF + montoC;

	cout << endl;
	cout << "Cantidad de horas a fijo: " << hor_f << endl;
	cout << "Cantidad de minutos a fijo: " << min_f << endl;
	cout << "Cantidad de horas a celular: " << hor_cel << endl;
	cout << "Cantidad de minutos a celular: " << min_cel << endl;
	cout << endl;
	cout << "Monto a pagar por el consumo: " << montoT << endl;

	if (montoC > montoF)
	{
		cout << "El mayor gasto lo tuvo al realizar llamadas a (F: fijo; C: celular): C";
	}
	else
		cout << "El mayor gasto lo tuvo al realizar llamadas a(F: fijo; C: celular) : F";
	
	_getch();
	return 0;
}