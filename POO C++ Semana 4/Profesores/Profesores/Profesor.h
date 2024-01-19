#pragma once
#include <string>

using namespace std;

class Profesor
{
private:
	string codigo;
	string nombre;
	string dni;

public:
	Profesor(string nombre, string codigo, string dni)
	:nombre(nombre), codigo(codigo), dni(dni){}

	float calcularSueldo()
	{
		return 0;
	}

	string getNombre()
	{
		return nombre;
	}

	string getCodigo()
	{
		return codigo;
	}

	void setCodigo(string codigo)
	{
		this->codigo = codigo;
	}

	~Profesor()
	{}
};
