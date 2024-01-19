#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	float v, t, d;

	cout << "Ingrese la velocidad en m/s^2: "; cin >> v;
	cout << "Ingrese el tiempo en s: "; cin >> t;

	d = v * t;

	cout << "La distancia sera de: " << trunc(d*100)/100 << " metros";

	_getch();
	return 0;
}