#pragma once
#include "Profesor.h"


class ProfesorTiempoCompleto : public Profesor
{
private:
	float sueldoBasico;
	float afp;

public:
	ProfesorTiempoCompleto(string nombre, string codigo, string dni, float sueldoBasico, float afp) :
	Profesor(nombre, codigo, dni), sueldoBasico(sueldoBasico), afp(afp) {}

	~ProfesorTiempoCompleto()
	{}

	virtual float calcularSueldo()
	{
		return sueldoBasico - (afp / 100) * sueldoBasico;
	}

};
