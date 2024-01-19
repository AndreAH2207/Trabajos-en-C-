#pragma once
#include "Auto.h"
#include <vector>
class Administrador {
private:
	vector<Auto*> autos;
	int y = 0;
public:
	void agregarAuto() {
		int  x = 1;
		y += 7;
		int dx = rand() % 4 + 1;
		Auto* a = new Auto(x, y, dx);
		autos.push_back(a);
	}
	void dibujarAutos() {
		for (int i = 0; i < autos.size(); i++) {
			autos[i]->draw();
		}
	}
	Auto* moverAutos() {
		for (int i = 0; i < autos.size(); i++) {
			if (autos[i]->getX() > ANCHO)
				return autos[i];
			autos[i]->mover();
		}
		return nullptr;
	}
	void eliminarAutos() {
		for (int i = 0; i < autos.size(); i++) {
			autos[i]->borrar();
		}
	}

};
