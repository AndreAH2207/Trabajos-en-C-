#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
int ingresarCant() {
	int k;
	do {
		cout << "Ingrese K terminos: ";
		cin >> k;
	} while (k < 1 || k>20);
	return k;
}
float ingresarValor() {
	float a;
	do {
		cout << "Ingrese el valor para a: ";
		cin >> a;
	} while (a < 0);
	return a;
}
float factorial(int cont) {
	float fac = 1;
	for (int i = 1; i <= cont; i++)
	{
		fac *= i;
	}
	return fac;
}

float calcularSerie(int k, float a) {
	int cont = 0;
	float s = 0.0;
	while (cont < k) {
		s += pow(a, cont) / factorial(cont);
		cout << pow(a, cont) << "/" << factorial(cont) << "   ";
		cont++;
	}
	return s;
}

int main() {
	int k;
	float a, suma;
	k = ingresarCant();
	a = ingresarValor();
	suma = calcularSerie(k, a);
	cout << "\nLa suma es: " << suma << endl;
	
	_getch();
	return 0;
}