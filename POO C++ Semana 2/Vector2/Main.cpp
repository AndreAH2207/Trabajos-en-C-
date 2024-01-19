#include <conio.h>
#include <vector>
#include <algorithm>
#include "Admin.h"
#include "Auto.h"

using namespace std;
using namespace System;

/*
* Desarrollar un programa en C++ tal que permita a la Empresa "Multiautos" gestionar
  la venta de autos, los datos de los autos que debe registrar son: codigo, marca,
  modelo, precio de costo y stock.
  El precio final es igual al precio de costo más el IGV menos el descuento.
* El descuento consiste en que si el stock es mayor que 100 entonces se aplica un
  descuento del 20% sobre el precio de costo.
* Imprimir un reporte donde muestre los datos del auto y su precio final.
*/

bool comparaPrecios(CAuto* auto1, CAuto* auto2)
{
	return auto1->calcularPrecioFinal() > auto2->calcularPrecioFinal();
}

int main()
{
	CAuto* auto1 = new CAuto(12345, "Nissan", "Qashqai", 100000, 12);
	CAuto* auto2 = new CAuto(47655, "Toyota", "Corolla", 50000, 17);
	CAuto* auto3 = new CAuto(63419, "Hyundai", "Elantra", 60000, 16);
	CAuto* auto4 = new CAuto(90232, "Mazda", "CX-3", 10000, 25);

	CAdmin admin("MrPieg");

	admin.registrar(auto1);
	admin.registrar(auto2);
	admin.registrar(auto3);
	admin.registrar(auto4);

	vector<CAuto*> lista = admin.getAutos();
	
	cout << "[Nombre de administrador: " << admin.getNombre() << "]" << endl;
	cout << endl;

	for (int i = 0; i < lista.size(); i++)
	{
		cout << "Registro de autos " << i + 1 << endl;
		cout << "Codigo : " << lista[i]->getCodigo() << endl;
		cout << "Marca  : " << lista[i]->getMarca() << endl;
		cout << "Modelo : " << lista[i]->getModelo() << endl;
		cout << "Stock  : " << lista[i]->getStock() << endl;
		cout << "Precio : " << lista[i]->getPrecio() << endl;
		cout << "  " << endl;
	}

	for (int i = 0; i < lista.size(); i++) {

		cout << "Codigo:" << lista[i]->getMarca() << " Modelo:" << lista[i]->getModelo() <<
			" Precio:" << lista[i]->getPrecio() <<
			" Precio Final:" << lista[i]->calcularPrecioFinal() << endl;
	}
	CAuto* caro = admin.autoMasCaro();
	cout << "El auto mas caro es: " << caro->getModelo() <<
		"Precio Costo:" << caro->getPrecio() << endl;

	getch();
	return 0;
}