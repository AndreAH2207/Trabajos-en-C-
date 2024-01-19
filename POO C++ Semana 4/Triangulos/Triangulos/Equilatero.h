#pragma once
#include "Triangulo.h"

class Equilatero
{
public:
	Equilatero(char car);
	~Equilatero();

private:

};

Equilatero::Equilatero(char car) :Triangulo(car)
{
	dx = 1;
	dy = -1;
}

Equilatero::~Equilatero(){}
void Equilatero::mostrar()
{
	while (true)
	{
		Console::SetCursorPosition(x, y); cout << caracter;

		if (cont >= lado)dy = 1;
		if (cont >= lado * 2)
		{
			dy = 0;
			dx = -2;
		}
		if (cont >= lado * 3)break;
		x+=

	}
}