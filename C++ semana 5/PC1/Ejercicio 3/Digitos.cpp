#include <iostream>
#include <conio.h>

using namespace std;

int IngresarDigitos()
{
	int dig;

	do {
		cout << "Ingrese numero de 3 digitos: "; cin >> dig;
	} while (dig > 1000 && dig < 99);
	return dig;
}

int Invertido(int dig)
{
	int u, d, c, inv;

	c = dig / 100;
	d = (dig % 100) / 10;
	u = (dig % 100) % 10;

	inv = dig;

	if (c > u)
	{
		inv = (u * 100) + (d * 10) + c;
	}
	else
		inv = 0;

	return inv;
}


int op1(int dig)
{
	int u, d, c, mayor;

	c = dig / 100;
	d = (dig % 100) / 10;
	u = (dig % 100) % 10;

	mayor = dig;

	if (d > c)
	{
		mayor = c + d + u;
	}
	else
	{
		mayor = 0;
	}
	return mayor;
}

int op2(int dig)
{
	int u, d, c, op;

	c = dig / 100;
	d = (dig % 100) / 10;
	u = (dig % 100) % 10;

	op = dig;

	if (u > c)
	{
		op = c * d * u;
	}
	else
	{
		op = 0;
	}
	return op;
}



int main()
{
	int digito, invertido, suma, multiplicacion;

	digito = IngresarDigitos();

	invertido = Invertido(digito);
	suma = op1(digito);
	multiplicacion = op2(digito);


	cout << "Si la centena es mayor que las unidades (Si es 0 no cumple):  " << invertido << endl;
	cout << "Si la decenas es mayor que la centenas  (Si es 0 no cumple): " << suma << endl;
	cout << "Si el las unidades son mayores que las centenas  (Si es 0 no cumple): " << multiplicacion << endl;
	

	_getch();
	return 0;
}