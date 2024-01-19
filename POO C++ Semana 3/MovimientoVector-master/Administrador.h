#pragma once
#include "Letra.h"
#include <vector>
#include <cmath>
class Administrador {
private:
	vector<Letra*> letras;
public:
	void agregarLetra() {			
			int x = rand() % ANCHO + 1;
			int y = rand() % ALTO + 1;
			int dy = rand() % 2 + 1;
			int dx = rand() % 2 + 1;
			Letra* le = new Letra(x, y, dx, dy, 1, 1);
			letras.push_back(le);
	}
	void dibujarLetras() {
		for (int i = 0; i < letras.size(); i++) {
			letras[i]->draw();
		}
	}
	void moverLetras() {
		for (int i = 0; i < letras.size(); i++) {
			letras[i]->mover();
		}
	}
	void eliminarLetras() {
		for (int i = 0; i < letras.size(); i++) {
			letras[i]->clear();
		}
	}
};