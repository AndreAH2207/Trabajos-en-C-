#pragma once
#include <string>

using namespace std;

class CAuto
{
private:
	int codigo;
	string marca;
	string modelo;
	int anioFabricacion;

public:
	CAuto(int codigo, string marca, string modelo, int anioFabricacion)
	{
		this->codigo = codigo;
		this->marca = marca;
		this->modelo = modelo;
		this->anioFabricacion = anioFabricacion;
	}

	int getAnioFabricacion()
	{
		return anioFabricacion;
	}

	~CAuto()
	{}
};
