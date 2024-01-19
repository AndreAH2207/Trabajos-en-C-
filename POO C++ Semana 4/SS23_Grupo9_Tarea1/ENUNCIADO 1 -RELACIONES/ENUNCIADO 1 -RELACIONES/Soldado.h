#pragma once
#include <iostream>

using namespace std;

class Soldado
{
private:
	string nombre;
	int grado;
public:
	Soldado(string nombre, int grado)
	{
		this->grado = grado;
		this->nombre = nombre;
	}

	void setNombre(string nombre)
	{
		this->nombre = nombre;
	}

	string getNombre()
	{
		return this->nombre;
	}

	void setGrado(int grado)
	{
		this->grado = grado;
	}

	int getGrado()
	{
		return this->grado;
	}

	void mostrarInformacion() {
		cout << this->nombre << " | G" << this->grado << endl;
	}

};
