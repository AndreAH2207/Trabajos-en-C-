#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int sT, h, m, s;

	cout << "Ingrese la hora expresada en segundos: "; cin >> sT;

	h = sT / 3600;
	sT = sT % 3600;
	m = sT / 60;
	s = sT % 60;

	cout << "[Espresado a horas, minutos, segundos:] " << h <<" horas " << m << " minutos "
		                                             << s << " segundos ";

	_getch();
	return 0;
}