#include <iostream>
#include <conio.h>

using namespace std;


int main()
{
	float gr, radian, m, s;
	float pi = 3.1416;

	cout << "Ingrese el valor del angulo en radianes: "; cin >> radian;	
	cout << endl;

	gr = radian * (180 / pi);
	m = ((trunc(gr * 100) / 100) - trunc(gr)) * 60;
	s = (m - trunc(m)) * 60;


	cout << "El valor a grados es: " << gr  << endl;
	cout << "El valor a minutos es: " << m  << endl;
	cout << "El valor a segundos es: " << s  << endl;

	_getch();
	return 0;
}