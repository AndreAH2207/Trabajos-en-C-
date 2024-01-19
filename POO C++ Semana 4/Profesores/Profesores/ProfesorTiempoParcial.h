#pragma once
#include "Profesor.h"

class ProfesorTiempoParcial:public Profesor
{
private:
	int horas;
	float tarifaHora;
public:
	ProfesorTiempoParcial(string nombre, string codigo, string dni, float tarifaHora, int horas)
	:Profesor(nombre, codigo, dni), tarifaHora(tarifaHora), horas(horas) {}

	~ProfesorTiempoParcial()
	{}

	virtual float calcularSueldo()
	{
		return horas * tarifaHora;
	}

};
