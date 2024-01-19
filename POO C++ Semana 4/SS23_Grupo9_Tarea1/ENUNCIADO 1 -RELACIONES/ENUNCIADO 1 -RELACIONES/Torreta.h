#pragma once
#include <iostream>
#include <string>

using namespace std;

class Torreta
{
private:
	string modelo;
	string tipoMunicion;
	int aniosAntiguedad;

public:

	Torreta(string modelo, string tipoMunicion, int aniosAntiguedad)
	{
		this->modelo = modelo;
		this->tipoMunicion = tipoMunicion;
		this->aniosAntiguedad = aniosAntiguedad;
	}

	void setModelo(string modelo)
	{
		this->modelo = modelo;
	}

	string getModelo()
	{
		return this->modelo;
	}


	void setTipoMunicion(string tipoMunicion)
	{
		this->tipoMunicion = tipoMunicion;
	}

	string getTipoMunicion()
	{
		return this->tipoMunicion;
	}

	void setAniosAntiguedad(int aniosAntiguedad)
	{
		this->aniosAntiguedad = aniosAntiguedad;
	}

	int getAniosAntiguedad()
	{
		return this->aniosAntiguedad;
	}

	void mostrarInformacion() {
		cout << "Torreta " << this->modelo
			<< " | municion " << this->tipoMunicion
			<< " | antiguedad " << this->aniosAntiguedad
			<< endl;
	}
};
