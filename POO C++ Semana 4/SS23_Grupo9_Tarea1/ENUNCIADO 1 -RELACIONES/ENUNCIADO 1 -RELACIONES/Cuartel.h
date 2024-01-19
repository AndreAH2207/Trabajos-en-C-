#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Soldado.h"
#include "Tanque.h"

using namespace std;

class Cuartel
{
private:
	int codigo;
	string nombre;
	vector<Tanque*>tanques;
	vector<Soldado*>soldados;

public:
	Cuartel(int codigo, string nombre)
	{
		this->codigo = codigo;
		this->nombre = nombre;
	}

	void setCodigo(int codigo)
	{
		this->codigo = codigo;
	}

	int getCodigo()
	{
		return this->codigo;
	}

	void setNombre(string nombre)
	{
		this->nombre = nombre;
	}

	string getnombre()
	{
		return this->nombre;
	}

	void asignarTanque(Tanque* tanque)
	{
		tanques.push_back(tanque);
	}

	void asignarSoldado(Soldado* soldado)
	{
		soldados.push_back(soldado);
	}

	int capacidadAtaque() {
		int promGradSol, sumGradSol;
		int promAnyosTorr, sumAnysTorr;

		sumGradSol = 0;
		sumAnysTorr = 0;

		for (int indice = 0; indice < soldados.size(); indice++)
			sumGradSol = sumGradSol + soldados[indice]->getGrado();

		promGradSol = sumGradSol / soldados.size();

		for (int indice = 0; indice < tanques.size(); indice++)
			sumAnysTorr = sumAnysTorr + tanques[indice]->getAnioTorreta();

		promAnyosTorr = sumAnysTorr / tanques.size();

		return promGradSol - promAnyosTorr;
	}

	void mostrarInformacion() {
		cout << "CUARTEL " << this->nombre
			<< " | C" << this->codigo << endl;
		cout << "----------------------------" << endl;
		cout << "TANQUES " << tanques.size() << endl;
		for (int indice = 0; indice < tanques.size(); indice++)
			tanques[indice]->mostrarInformacion();
		cout << "----------------------------" << endl;
		cout << "SOLDADOS " << soldados.size() << endl;
		for (int indice = 0; indice < soldados.size(); indice++)
			soldados[indice]->mostrarInformacion();
		cout << "----------------------------" << endl;
		cout << "Capacidad de ataque " << capacidadAtaque() << endl;
	}
};

