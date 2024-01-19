#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Auto.h"
#include "Administrador.h"
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL));
	Administrador* adm = new Administrador();
	for (int i = 0; i < 3; i++) {
		adm->agregarAuto();
	}

	while (true) {
		adm->eliminarAutos();
		Auto* gana = adm->moverAutos();
		if (gana != nullptr) {
			Console::ForegroundColor = gana->getColor();
			cout << "GANO";
			break; // sale del while
		}
		adm->dibujarAutos();
		Sleep(300);
	}
	_getch();
}
