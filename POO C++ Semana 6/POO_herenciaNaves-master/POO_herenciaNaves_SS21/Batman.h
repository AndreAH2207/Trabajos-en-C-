#pragma once
#pragma once
#include <iostream>
#include "Naves.h"
using namespace std;
using namespace System;

#define arriba 72
#define abajo 80
#define izquierda 75
#define derecha 77

class Batman {
protected:
	int x, y, dx, dy;
	int ancho, alto, vidas;
public:
	Batman(int vidas): vidas(vidas) {
		x = WIDTH/2; y = HEIGHT-3;//al medio en la parte inferior
		dx = 2; dy = 2;
		ancho = 3; alto = 3;		
	}
	void dibujar() {
		Console::ForegroundColor = ConsoleColor::DarkCyan;
		Console::SetCursorPosition(x, y + 0); cout << " 0 ";
		Console::SetCursorPosition(x, y + 1); cout << "-|-";
		Console::SetCursorPosition(x, y + 2); cout << "_|_";

	}
	void borrar() {
		Console::SetCursorPosition(x, y + 0); cout << "   ";
		Console::SetCursorPosition(x, y + 1); cout << "   ";
		Console::SetCursorPosition(x, y + 2); cout << "   ";
	}
	void mover(int tecla) {
		switch (tecla)
		{
		case arriba:dy = -2; dx = 0; break;
		case abajo:dy = 2; dx = 0; break;
		case izquierda:dy =	 0; dx = -2; break;
		case derecha:dy = 0; dx = 2; break;
		}
		if (x + dx<0 || x + dx + ancho>WIDTH) dx *= -1;
		if (y + dy<0 || y + dy + alto>HEIGHT)dy *= -1;
		x += dx;
		y += dy;
	}
	int getX() { return x; }
	int getY() { return y; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	int getVidas() { return vidas; }
	void addVidas() { vidas++; }
	void delVidas() { vidas--; }
	void setVidas(int pvidas) { vidas = pvidas; }
};
