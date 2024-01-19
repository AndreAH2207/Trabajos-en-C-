#include <iostream>
#include <conio.h>

using namespace std;


float sueldoBruto(float tH, int numH)
{
	return tH * numH;
}

float calcularDesEs(float sB)
{
	return sB * 0.09;
}

float descuentoAFP(float sB)
{
	return sB * 0.115;
}

float sueldoNeto(float sB, float dE, float dAFP)
{
	return sB - dE - dAFP;
}

int main()
{
	int numh;
	float tarifaH, sueldoB, descEs, descAFP, sueldoN;

	cout << " Ingrese las horas trabajadas: "; cin >> numh;
	cout << " Ingrese la tarifa horaria: "; cin >> tarifaH;
	cout << endl;

	sueldoB = sueldoBruto(tarifaH, numh);
	descEs = calcularDesEs(sueldoB);
	descAFP = descuentoAFP(sueldoB);
	sueldoN = sueldoNeto(sueldoB, descEs, descAFP);

	cout << "El sueldo bruto es: " << sueldoB << endl;
	cout << "El descuento ESSALUD es: " << descEs << endl;
	cout << "EL descuento por AFP es: " << descAFP << endl;
	cout << "El sueldo neto es: " << sueldoN << endl;

	_getch();
	return 0;
}