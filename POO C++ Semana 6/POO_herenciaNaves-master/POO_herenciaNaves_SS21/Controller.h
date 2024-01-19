#pragma once
#include <iostream>
#include <vector>

using namespace System;
using namespace std;


#include "Naves.h"
#include "Alfa.h"
#include "Batman.h"

class Controller {
private:
	vector<Naves*> naves;
	Batman* batman;
	int contador=0;
public:
	Controller() {
		batman = new Batman(2);// vidas
	}
	void agregarNave(Naves* nave) {       
		naves.push_back(nave);
	}
	void dibujarNaves() {
		for (int i = 0; i < naves.size(); i++) {
			naves[i]->draw();//polimorfismo
		}
	}
	void dibujarTodos() {
		for (int i = 0; i < naves.size(); i++) {
			naves[i]->draw();
		}
		batman->dibujar();
	}
	void moverNaves() {
		for (int i = 0; i < naves.size(); i++) {
			if (naves[i]->move()) {
				naves.erase(naves.begin() + i);
			}
		}
	}

	void borrarTodos() {
		for (int i = 0; i < naves.size(); i++) {
			naves[i]->clear();
		}
		batman->borrar();
	}	
	void moverBatman(int tecla) {
		batman->mover(tecla);
	}

	void colision() {
		for (int i = 0; i < naves.size(); i++)
		{
			int x1 = naves[i]->getX();
			int y1 = naves[i]->getY();
			int w1 = naves[i]->getWidth();
			int h1 = naves[i]->getHight();
			int x2 = batman->getX();
			int y2 = batman->getY();
			int w2 = batman->getAncho();
			int h2 = batman->getAlto();
			if (x1 + w1 > x2 && x1 < x2 + w2 && y1 + h1 > y2 && y1 <y2 + h2) {//colision
				if(naves[i]->getID()==1) // Alfa
					batman->addVidas();
				if (naves[i]->getID() == 2) //Beta
					batman->delVidas();
				naves.erase(naves.begin() + i);
			}
		}
	}
	void eliminarTodos() { //elinarlos de memoria
		int n = naves.size();
		for (int i = 0; i < n ; i++) {
			delete(naves[i]);
		}
		delete(batman);
	}
	Batman* getBatman(){
		return batman;
	}
};