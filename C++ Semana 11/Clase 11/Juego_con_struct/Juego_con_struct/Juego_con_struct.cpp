#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;
using namespace System;
struct Fantasma {
	char simbolo;
	int x;
	int y;
	int color;
	int dx;
	int dy;
};
Fantasma boo; //declaramos a la variable de tipo Fastams como global

Fantasma generarDatos() { // La funcion es de tipo Struct
	Fantasma E; // enemigo que se mueve 
	E.simbolo = char(1 + rand() % 6); // 
	E.x = rand() % 80;
	E.y = rand() % 40;
	E.color = 1 + rand() % 15; // 3 es azul 
	E.dx = 1 + rand() % 5;
	E.dy = 1 + rand() % 5;
	return E;
}
void dibujar() {
	//dibujar
	Console::ForegroundColor = ConsoleColor(boo.color);
	Console::SetCursorPosition(boo.x, boo.y);
	cout << boo.simbolo;
}

void mover() {
	if (boo.x + boo.dx < 0 || boo.x + boo.dx>79)
		boo.dx *= -1;
	boo.x += boo.dx;
	if (boo.y + boo.dy < 0 || boo.y + boo.dy>39)
		boo.dy *= -1;
	boo.y += boo.dy;
}
void borrar() {
	Console::SetCursorPosition(boo.x, boo.y);
	cout << " ";
}
int main() {
	srand(time(NULL));
	Console::SetWindowSize(80, 40);
	Console::CursorVisible = false;
	boo = generarDatos();  //debemos retornar los datos de la variable de tipo struct
	dibujar();
	while (1) {
		//borrar
		borrar();
		//mover
		mover();
		//dibujar
		dibujar();
		_sleep(100);
	}
	getch();
}