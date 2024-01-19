#include <iostream>
#include <conio.h>

using namespace std;

float area_sup_conica(int radio, int generatriz, int altura)
{
	float pi = 3.1416;
	float Area_S_C;

	Area_S_C = (pi * radio * radio) + (pi * radio * generatriz);
	return Area_S_C;
}

float volumen_cono(int radio, int altura)
{
	float pi = 3.1416;
	float Volumen;

	Volumen = (pi * radio * radio * altura) / 3;

	return Volumen;
}

int main()
{
	int r, g, h;
	float Area, Vol;

	float pi = 3.1416;

	cout << "Ingrese r: "; cin >> r;
	cout << "Ingrese g: "; cin >> g;
	cout << "Ingrese h: "; cin >> h;
	cout << endl;

	Area = area_sup_conica(r, g, h);
	Vol = volumen_cono(r, h);

	cout << "Area del cono es: " << trunc(Area*100)/100;
	cout << endl;
	cout << "Volumen del cono es: " << trunc(Vol*100)/100;


	_getch();
	return 0;
}