#include <iostream>
#include <conio.h>
#include <vector>
#include "Administrador.h"
#include "Profesor.h"
#include "ProfesorTiempoCompleto.h"
#include "ProfesorTiempoParcial.h"

using namespace std;

void main()
{
	Administrador* adm = new Administrador();

	ProfesorTiempoCompleto* ptc1 = new ProfesorTiempoCompleto ("12345", "Coco", "88888888", 3500, 18);
	ProfesorTiempoCompleto* ptc2 = new ProfesorTiempoCompleto ("43144", "Thanos", "77777777", 3400, 18);

	ProfesorTiempoParcial* ptp1 = new ProfesorTiempoParcial ("54321", "Mario", "99999999", 100, 60);

	adm->registrar(ptc1);
	adm->registrar(ptp1);
	adm->registrar(ptc2);

	vector<Profesor*>lista = adm->getProfesores();

	cout << "Nombre\t\tSueldo Final\n";
	for (int i = 0; i < lista.size(); i++)
	{
		cout << lista[i]->getNombre() << "\t\t" << lista[i]->calcularSueldo() << endl;
	}

}
