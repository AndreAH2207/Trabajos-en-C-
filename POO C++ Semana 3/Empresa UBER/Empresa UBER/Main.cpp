#include <iostream>
#include <conio.h>
#include "UBER.h"

using namespace std;
using namespace System;

void main()
{
	CUber* empresa = new CUber("UBER SAC");
	CChofer* chofer1 = new CChofer("8888888", "Pepe", 9956789, "A35345", 111, "Toyota", "Yari", 2023);
	CChofer* chofer2 = new CChofer("9999999", "Beto", 8839213, "A44445", 2222, "Vovlo", "Jeta", 2010);

	empresa->registrar(chofer1);
	empresa->registrar(chofer2);

	vector<CChofer*> lista = empresa->getLista();
	cout << "Listado completo ************" << endl;
	for (int i = 0; i < lista.size(); i++) {
		cout << lista[i]->getNombre() << endl;
	}
	cout << "** Listado de choferes con autos mayores a 2020 **";
	vector<CChofer*> datos = empresa->getListaConAutosMas2020();
	for (int i = 0; i < lista.size(); i++) {
		cout << lista[i]->getNombre() << endl;
	}


	getch();
}