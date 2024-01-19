#include <iostream>
#include <conio.h>

using namespace std;

long long IngresarCodigo()
{
	long long c;
	
	cout << " Ingrese el codigo de barras: "; cin >> c;
	return c;
}
int dia_de_vencimiento(long long c)
{
	return c/10000000000;
}

int mes_de_vencimiento(long long c)
{
	return (c%10000000000)/100000000;
}

int anio_de_vencimiento(long long c)
{
	return (c%10000000000)%100000000/10000;
}

int tipo_de_producto(long long c)
{
	return ((c%10000000000)%100000000)%10000/100;
}

int Indicar_perecible(long long c)
{
	int perecible = (((c % 10000000000) % 100000000) % 10000) % 100 / 100;
	int res;

	if (perecible == 0)
		res = 1;
	else
		res = 0;

	return res;
}

int main()
{
	long long codigo;
	int dia, mes, anio, pp;
	char tp;

	codigo = IngresarCodigo();
	cout << endl;
	
	dia = dia_de_vencimiento(codigo);
	mes = mes_de_vencimiento(codigo);
	anio = anio_de_vencimiento(codigo);
	tp = tipo_de_producto(codigo);
	pp = Indicar_perecible(codigo);

	cout << " Dia: " << dia << endl;
	cout << " Mes: " << mes << endl;
	cout << " Anio: " << anio << endl;
	cout << " Tipo de producto: " << tp << endl;
	cout << " Perecible: " << pp << endl;
	cout << endl;

	_getch();
	return 0;
}