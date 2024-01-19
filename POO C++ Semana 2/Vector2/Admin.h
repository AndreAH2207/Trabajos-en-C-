#pragma once
#include <string>
#include <vector>
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

class CAdmin
{
private:
	string nombre;
	vector<CAuto*>autos;

public:
	CAdmin(string nombre)
	{
		this->nombre = nombre;
	}

	string getNombre()
	{
		return nombre;
	}

	void registrar(CAuto* a)
	{
		autos.insert(autos.begin(), a);
	}
	vector<CAuto*>getAutos()
	{
		return this->autos;
	}

	CAuto* autoMasCaro()
	{
		double maxi = 0;
		CAuto* a;
		for (int i = 0; i < autos.size(); i++)
		{
			if (autos[i]->calcularPrecioFinal() > maxi)
			{
				maxi = autos[i]->calcularPrecioFinal();
				a = autos[i];
			}
		}
		return a;
	}
};