#pragma once
#include <vector>
#include "Profesor.h"

using namespace std;

class Administrador
{
private:
	vector<Profesor*>profesores;

public:
	Administrador(){}
	~Administrador() {}

	void registrar(Profesor* profesor)
	{
		profesores.push_back(profesor);
	}
	vector<Profesor*>getProfesores() 
	{
		return profesores;
	}

};
