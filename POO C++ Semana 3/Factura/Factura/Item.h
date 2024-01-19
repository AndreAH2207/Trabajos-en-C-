#pragma once
#include "Producto.h"

class CItem
{
private:
	int id;
	int cantidad;
	CProducto* producto;


public:
	CItem(int id, int cantidad, int codigo, string descripcion, float precio)
	{
		this->id = id;
		this->cantidad = cantidad;
		producto = new CProducto(codigo, descripcion, precio);
	}
	double calcularMontoParcial()
	{
		return cantidad* producto->getPrecio();
	}

	int getId()
	{
		return id;
	}

	int getCantidad()
	{
		return cantidad;
	}

	CProducto* getProducto()
	{
		return producto;
	}



};
