#include <iostream>
#include <conio.h>

using namespace std;

int IngreseNumero()
{
	int n;
	do
	{
		cout << " Ingrese numero: "; cin >> n;
	} while (n < 1);

	return n;
}

float Suma(int n)
{
	float suma = 0;
	int cont = 0;

	while (cont < n)
	{
		suma += 1 / pow(2,cont);
		cout << " 1/" << pow(2, cont) << " +";
		cont++;
	}
	cout << endl;
	cout << " La suma es: " << suma;

	return (suma);
}

int main()
{
	int n;
	float suma;

	n = IngreseNumero();
	suma = Suma(n);

	_getch();
	return 0;
}