#include <iostream>
#include <conio.h>
#include "Factura.h"

using namespace std;
using namespace System;

void main()
{
	CFactura* factura = new CFactura(123, 888888888, "El Encuentro", "30/08/2023");
	factura->registrar(1, 2, 111, "Coca Cola", 3.5);
	factura->registrar(2, 2, 324, "Pepsi", 2.5);
	factura->registrar(3, 1, 222, "Seven Up", 3.0);

	vector<CItem*>items = factura->getItems();

	for (int i = 0; i < items.size(); i++) 
	{
		 cout << items[i]->getId() << "  " << 
			    items[i]->getProducto()->getDescripcion() <<
		"   " << items[i]->calcularMontoParcial() << endl;
	}
	cout << "Total:" << factura->calcularMontoTotal();
	getch();
}