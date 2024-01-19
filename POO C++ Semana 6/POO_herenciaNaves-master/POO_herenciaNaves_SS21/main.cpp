#include <iostream>
#include <conio.h>
#include <time.h>
using namespace System;
using namespace std;
#include "Alfa.h"
#include "Beta.h"
#include "Controller.h"

void main() {
	srand(time(NULL));
	Console::CursorVisible = false;
	Console::SetWindowSize(WIDTH, HEIGHT);
	Controller* c = new Controller();// lo crea a batman

	Naves* a = new Alfa();
	Naves* b = new Beta();
	c->agregarNave(a);
	c->agregarNave(b);
	while (true) {	
		if (kbhit()) {
			int tecla = getch();
			if (tecla == 224) {
				tecla = getch();
				c->moverBatman(tecla);//movimiento de la barra
			}
			if (tecla == 'g') { //nueva nave aleatoria
				int n = 1 + rand() % 2;
				if (n == 1)
					b = new Alfa();
				else
				    b = new Beta();
				c->agregarNave(b);
			}
			if (tecla == 'h') {//h sale termina
				break;
			}			
		}
		if (c->getBatman()->getVidas() == 0) {
			break;
		}
		c->dibujarTodos();
		_sleep(150);//va luego de dibujar
		c->borrarTodos();
		c->moverNaves();
		c->colision();		
	}
	//Console::SetCursorPosition(20, 20);
	cout << "Puntos: " << c->getBatman()->getVidas() << endl;
	c->eliminarTodos();//de memoria
	_getch();
}