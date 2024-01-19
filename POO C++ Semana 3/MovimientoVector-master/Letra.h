#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#define ANCHO  40
#define ALTO  20

using namespace std;
using namespace System;



void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class Letra {
private:
	int x, y;
	int dx, dy;
	int ancho, alto;
public:
	Letra(int x, int y, int dx, int dy, int ancho, int alto) {
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		this->ancho = ancho;
		this->alto = alto;
	}
	void draw() {
			gotoxy(x, y);
			cout << "X";		
	}
	void clear() {		
				gotoxy(x, y);
				cout << " ";
				gotoxy(x, y +1);
				cout << " ";
     }

	void mover() {
		if (!(x + dx > 0 && (x + ancho + dx) < ANCHO))
			dx *= -1;
		if (!(y + dy > 0 && (y + alto + dy) < ALTO))
			dy *= -1;
		x += dx;
		y += dy;
	}
};

