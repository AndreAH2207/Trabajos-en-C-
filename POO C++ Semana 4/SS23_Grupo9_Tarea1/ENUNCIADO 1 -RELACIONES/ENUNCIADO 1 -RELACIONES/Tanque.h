#pragma once
#include <iostream>
#include "Torreta.h"

using namespace std;

class Tanque
{
private:
	string modelo;
	Torreta* torreta;

public:
	Tanque(string modelo, Torreta* torreta)
	{
		this->modelo = modelo;
		this->torreta = torreta;
	}

	string getModelo()
	{
		return this->modelo;
	}

	void setModelo(string modelo)
	{
		this->modelo = modelo;
	}

	Torreta* getTorreta()
	{
		return this->torreta;
	}

	void setTorreta(Torreta* torreta)
	{
	      this->torreta= torreta;
	}

	int getAnioTorreta() {
		return torreta->getAniosAntiguedad();
	}

	void mostrarInformacion() {
		cout << "Tanque " << this->modelo << " | ";
		torreta->mostrarInformacion();
	}


};
