#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <string>
#include <algorithm>
#include "Auto.h"
using namespace std;

class Administrador {
private:
	string nombre;
	vector<Auto*> autos;

public:
	Administrador(string nombre) {
		this->nombre = nombre;
	}
	void registrar(Auto* a) { //Agregacion
		autos.push_back(a);
	}

	vector<Auto*> getAutos() {
		return this->autos;
	}

	Auto* buscar(int codigo) {
		for (int i = 0; i < autos.size(); i++) {
			if (autos[i]->getCodigo() == codigo) {
				return autos[i];
			}
		}
		return nullptr;
	}
	int buscarIndice(int codigo) {
		for (int i = 0; i < autos.size(); i++) {
			if (autos[i]->getCodigo() == codigo) {
				return i;
			}
		}
		return -1;
	}
	void eliminar(int codigo) {
		int i = buscarIndice(codigo);
		vector < Auto* > ::iterator pos = autos.begin() + i;//pointers
		autos.erase(pos);
	}

	
};


