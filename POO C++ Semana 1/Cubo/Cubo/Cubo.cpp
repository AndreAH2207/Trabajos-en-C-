#include "Header.h"
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	Cubo* cubito = new Cubo(10);
	cout << "Volumen del cubo es: "
		<< cubito->calcularVolumen() << endl;

	delete cubito;
	getch();
	return 0;
}