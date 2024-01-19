#pragma once
#include <iostream>
#include <conio.h>
#include <time.h>
#include "Raton.h"
#include <Windows.h>

using namespace System;
using namespace std;

#define ALTO 30
#define ANCHO  110

class Queso {
private:
	int x, y;
	int alto, ancho;
public:
	Queso() {
		x = 20; y = 20;
		alto = 9;
		ancho = 18;
	}
	void draw() {
		gotoxy(x, y);
		gotoxy(x, y + 1); cout << "   ___ _____";
		gotoxy(x, y + 2); cout << "   /\\ (_)  \\";
		gotoxy(x, y + 3); cout << "_) _\\ _ \\";
		gotoxy(x, y + 4); cout << "/ (_)\_( )____\\";
		gotoxy(x, y + 5); cout << "\_ /    _    _/";
		gotoxy(x, y + 6); cout << "  ) /\/ (o) (";
		gotoxy(x, y + 7); cout << "  \ \_)(o)   /";
		gotoxy(x, y + 8); cout << "   \/_______/";

	}

	void clear() {
		for (int i = 0; i < alto; i++) {
			for (int j = 0; j < ancho; j++) {
				gotoxy(x + j, y + i);
				cout << " ";
			}
		}
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}
	int getAncho() {
		return ancho;
	}
	int getAlto() {
		return alto;
	}
};

