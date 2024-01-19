#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

int ingresarCant() {
	int n;
	do {
		cout << "Ingrese la cantidad de numeros: ";
		cin >> n;
	} while (n < 1);
	return n;
}
void generarDatos(int* vn, int n) {
	for (int i = 0; i < n; i++)
	{
		vn[i] = 10 + rand() % 191; //10 -200
	}
}
void mostrarDatos(int* vn, int n) {
	for (int i = 0; i < n; i++)
	{
		cout << "[" << vn[i] << "] ";
	}
	cout << endl;
}

void comprobar(int inv, int n) {
	if (inv == n)
		cout << "SI" << endl;
	else
		cout << "NO" << endl;
}
void calcularCapicua(int* vn, int n) {
	int num, dig, inverso;
	for (int i = 0; i < n; i++)
	{
		num = vn[i];
		while (num > 0) {
			dig = num % 10;
			num = num / 10;
			inverso = inverso * 10 + dig;
		}
		comprobar(inverso, vn[i]);
		inverso = 0;
	}
}

int main() {
	srand(time(NULL));
	int n = ingresarCant();
	int* vnumeros = new int[n];
	generarDatos(vnumeros, n);
	mostrarDatos(vnumeros, n);
	calcularCapicua(vnumeros, n);
	getch();
}