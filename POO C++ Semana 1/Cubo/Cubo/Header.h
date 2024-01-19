#pragma once
#include <iostream>

using namespace std;

class Cubo
{
private:
	int lado;

public:
	Cubo(double lado)
	{
		this->lado = lado;
	}
	Cubo()
	{
		this->lado = 0;
	}

	void setLado(double lado)
	{
		this->lado = lado;
	}
	double getLado()
	{
		return this->lado;
	}

	double calcularVolumen()
	{
		return pow(lado, 3);
	}

};