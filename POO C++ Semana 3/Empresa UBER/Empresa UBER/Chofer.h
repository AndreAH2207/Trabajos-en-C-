#pragma once
#include <string>
#include "Auto.h"

using namespace std;

class CChofer
{
private:
	string DNI;
	string nombre;
	int telefono;
	string email;
	int numeroLicencia;
	CAuto* autito;

public:
	CChofer(string DNI, string nombre, int telefono,
		string email, int numeroLicencia,
		int codigo, string marca, string modelo,
		int anioFabricacion)
	{
		autito = new CAuto(codigo, marca, modelo, anioFabricacion);
		this->DNI = DNI;
		this->nombre = nombre;
		this->telefono = telefono;
		this->email = email;
		this->numeroLicencia = numeroLicencia;
	}

	string getNombre()
	{
		return nombre;
	}

	string getDNI()
	{
		return DNI;
	}

	CAuto* getAuto()
	{
		return autito;
	}

	~CChofer()
	{}


};
