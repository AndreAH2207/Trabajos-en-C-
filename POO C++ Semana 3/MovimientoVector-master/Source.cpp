#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Letra.h"
#include "Administrador.h"
using namespace std;

int main() {

	srand(time(NULL));
	Administrador* adm = new Administrador();
	for (int i = 0; i < 5; i++) {
		adm->agregarLetra();	
	}
	
	while (true) {
		adm->eliminarLetras();
		adm->moverLetras();		
		adm->dibujarLetras();		
		Sleep(300);
	}
		getch();
}