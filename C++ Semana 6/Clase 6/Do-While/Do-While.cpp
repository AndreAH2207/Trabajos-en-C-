#include <iostream>
#include <conio.h>
using namespace std;
int ingresarNum() {
	int n;
	cout << "Ingrese un numero: ";
	cin >> n;
	return n;
}

void obtenerImparesW(int n) {
	int cont = 0, impar = 1;
	cout << "====== IMPARES CON WHILE ======" << endl;
	while (impar <= n) {
		cout << impar << " \t ";
		impar += 2;
		cont++;
	}
	cout << "\nCantidad de impares con While: " << cont << endl;

}
void obtenerImparesDW(int n) {
	int impar = 1, cont = 0;
	cout << "====== IMPARES CON DO-WHILE ======" << endl;
	do {
		cout << impar << "\t";
		impar += 2;
		cont++;
	} while (impar <= n);
	cout << "\nCantidad de impares con While: " << cont << endl;
}
void obtenerImparesFor(int n) {
	int cont = 0;
	cout << "====== IMPARES CON FOR ======" << endl;
	for (int i = 1; i <= 20; i += 2)
	{
		cout << i << "\t";
		cont++;
	}
	cout << "\nCantidad de impares con FOR: " << cont << endl;
}
int main() {
	int numero = ingresarNum();
	obtenerImparesW(numero);
	obtenerImparesDW(numero);
	obtenerImparesFor(numero);
	getch();
}