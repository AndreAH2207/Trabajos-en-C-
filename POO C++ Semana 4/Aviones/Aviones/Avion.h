#pragma once
#include <iostream>

#define ANCHO_CONSOLA 120
#define ALTO_CONSOLA 30

class Avion
{
private:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int color;

public:
	Avion(int _alto, int _ancho);
	~Avion();

	void  mover();
	void borrar();
};

Avion::Avion(int _alto, int _ancho)
{
	ancho = _ancho;
	alto = _alto;

	x = rand() % (ANCHO_CONSOLA - ancho);
	y = rand() % (ALTO_CONSOLA - alto);
	dx = dy = 1;
	color = rand() % 13 + 1;
}

Avion
