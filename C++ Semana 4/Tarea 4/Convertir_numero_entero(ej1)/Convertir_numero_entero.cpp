#include <iostream>
#include <conio.h>

using namespace std;

int main()
{

	float e;

	cout << "ingrese numero entero: "; cin >> e;

	if (e >= 0 && e < 10)
	{
		e = (e / 4);

	}
	else if (e >= 10)
	{
		e = e / 3;
	}

	cout << "el numero que devuelve es: " << e;

	_getch();
	return 0;
}