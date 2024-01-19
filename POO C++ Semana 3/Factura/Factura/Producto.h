#pragma once
#include <string>

using namespace std;

class CProducto
{
private:
	int codigo;
	string descripcion;
	float precio;

public:
	CProducto(int codigo, string descripcion, float precio)
	{
		this->codigo = codigo;
		this->descripcion = descripcion;
		this->precio = precio;
	}

	float getPrecio()
	{
		return precio;
	}

	string getDescripcion()
	{
		return descripcion;
	}
};