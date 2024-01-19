#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include "Auto.h"
#include "Administrador.h"
#include "Menu.h"
using namespace std;

bool compararPorPrecio(Auto* auto1, Auto* auto2) {
	return auto1->calcularPrecioFinal() < auto2->calcularPrecioFinal();
}

void main() {
	int op, ele, pos, codigo, e;
	string marca, modelo;
	float precio;
	int stock;
	Menu* menu = new Menu();
	Administrador* adm = new Administrador("Pepe");
	Auto* a = nullptr;
	vector<Auto*> autos;

	do {
		op = menu->menu();
		switch (op)
		{
		case 1:			
			cout << "Ingrese Codigo:";
			cin >> codigo;
			cout << "Ingrese marca:";
			cin >> marca;
			cout << "Ingrese modelo:";
			cin >> modelo;
			cout << "Ingrese precio:";
			cin >> precio;
			cout << "Ingrese Stock:";
			cin >> stock;
			a = new Auto(codigo, marca, modelo, precio, stock);
			adm->registrar(a);
			break;
		case 2:

			autos = adm->getAutos();
			cout << "Codigo\t\tMarca\t\tModelo\t\tPrecio\t\tPrecio Final" << std::endl;
			for (int i = 0; i < autos.size(); i++) {
				cout << autos[i]->getCodigo() << "\t\t"
					<< autos[i]->getMarca() << "\t\t"
					<< autos[i]->getModelo() << "\t\t"
					<< autos[i]->getPrecio() << "\t\t"
					<< autos[i]->calcularPrecioFinal() << "\t\t" <<endl;
			}
			break;
		case 3:
			cout << "Ingrese codigo de auto a eliminar:";
			cin >> codigo;			
			adm->eliminar(codigo);
			cout << "Eliminado!" << endl;
			break;
		case 4:
			break;
		case 5:
			
			autos = adm->getAutos();
			sort(autos.begin(), autos.end(), compararPorPrecio);
			cout << "Codigo\t\tMarca\t\tModelo\t\tPrecio\t\tPrecio Final" << std::endl;
			for (int i = 0; i < autos.size(); i++) {
				cout << autos[i]->getCodigo() << "\t\t"
					<< autos[i]->getMarca() << "\t\t"
					<< autos[i]->getModelo() << "\t\t"
					<< autos[i]->getPrecio() << "\t\t"
					<< autos[i]->calcularPrecioFinal() << "\t\t" << endl;
			}
			break;
		}
		if (op == 6)
			break;
		cout << "Presione cualquier tecla para continuar .....";
		_getch();
		system("cls");
	} while (true);
	cout << "FIN" << endl;
}