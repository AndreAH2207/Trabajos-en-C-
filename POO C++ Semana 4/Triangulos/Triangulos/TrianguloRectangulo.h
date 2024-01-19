#pragma once
#include "Triangulo.h"

class TrianguloRectangulo
{
public:
	TrianguloRectangulo(int _l1, int _l2);
	~TrianguloRectangulo();

private:
	int l1, l2;

};

TrianguloRectangulo::TrianguloRectangulo(int _l1, int _l2, char dx, char dy)
{
	l1 = _l1;
	l2 = _l2;
	dx = 1;
	dy = 1;
}

TrianguloRectangulo::~TrianguloRectangulo(){}

void TrianguloRectangulo::dibujar()
{
	while (true)
	{
		Console::SetCursorPosition(x, y);
		cout << caracter;

		if(contador>=)

		x += dx;
		y += dy;
		contador++;
		_sleep(100);
	}
}

