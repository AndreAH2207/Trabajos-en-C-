#pragma once
#include "Chasis.h"
#include "Llanta.h"

#define ANCHO 50
#define ALTO 30
#include <vector>
class Auto {
private:
	int x, y;
	int dx;
	Chasis* chasis;
	Llanta* llantas[4];
	ConsoleColor color;
public:
	Auto(int x, int y, int dx) {
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->color = ConsoleColor(1 + rand() % 15);
		chasis = new Chasis(color); // composicion
		llantas[0] = new Llanta(color); // composicion
		llantas[1] = new Llanta(color);
		llantas[2] = new Llanta(color);
		llantas[3] = new Llanta(color);
	}

	void draw() {
		llantas[0]->setXY(x + 1, y - 1);
		llantas[0]->draw();
		llantas[1]->setXY(x +1 , y + 1);
		llantas[1]->draw();
		chasis->setXY(x, y);
		chasis->draw();
		llantas[2]->setXY(x + 3, y - 1);
		llantas[2]->draw();
		llantas[3]->setXY(x + 3, y + 1);
		llantas[3]->draw();
	}
	void mover() {
		x += dx;
	}
	void borrar() {
		Console::SetCursorPosition(x, y - 1); cout << "      ";
		Console::SetCursorPosition(x, y );    cout << "      ";
		Console::SetCursorPosition(x, y +1);  cout << "      ";
		Console::SetCursorPosition(x, y +2);  cout << "      ";
	}
	int getX() {
		return x;
	}
	ConsoleColor getColor() {
		return color;
	}
};