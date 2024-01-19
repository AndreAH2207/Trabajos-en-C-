#pragma once
#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>

using namespace std;
using namespace System;

/*
* Desarrollar un programa en C++ tal que permita a la Empresa "Multiautos" gestionar
  la venta de autos, los datos de los autos que debe registrar son: codigo, marca,
  modelo, precio de costo y stock.
  El precio final es igual al precio de costo más el IGV menos el descuento.
* El descuento consiste en que si el stock es mayor que 100 entonces se aplica un
  descuento del 20a% sobre el precio de costo.
* Imprimir un reporte donde muestre los datos del auto y su precio final.
*/

class CAuto
{
private:
	int codigo;
	string marca;
	string modelo;
	double precio;
	int stock;

public:
	CAuto(int codigo, string marca, string modelo, double precio, int stock)
	{
		this->codigo = codigo;
		this->marca = marca;
		this->modelo = modelo;
		this->precio = precio;
		this->stock = stock;
	}

	double calcularDescuento()
	{
		double descuento = 0;

		if (stock > 100)
		{
			descuento = 0.20 * precio;
		}
		return descuento;
	}

	double calcularIGV()
	{
		double IGV = 0.18;
		return precio * IGV;
	}

	double calcularPrecioFinal()
	{
		return precio = calcularIGV() - calcularDescuento();
	}

	int getCodigo()
	{
		return codigo;
	}

	string getMarca()
	{
		return marca;
	}

	string getModelo()
	{
		return modelo;
	}

	int getStock()
	{
		return stock;
	}

	double getPrecio()
	{
		return precio;
	}
};