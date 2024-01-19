#pragma once
#include "Naves.h"

class Alfa :public Naves {
public:
	Alfa() {//inicializando datos
		ID = 1;
		//parte de la linea x superior
		x = 0 + rand() % 100;// rand() % WIDTH - 1;
		y = 0;
		//desplazamiento en x = 0
		dx = 0;//movimiento es solo vertical
		//dy = rand() % 3 + 1; //pudo ser pero la ponemos fijo 1
		dy = 1;//velocidad es 1
		width = 19;
		height = 5;
		color = 1 + rand() % 15;
	}
	void draw() {
		Console::ForegroundColor = ConsoleColor(color);
		Console::SetCursorPosition(x, y + 0); cout << "      _.---._      ";//gotoxy(x,y)
		Console::SetCursorPosition(x, y + 1); cout << "    .'       '.    ";
		Console::SetCursorPosition(x, y + 2); cout << "_.-~===========~-._";
		Console::SetCursorPosition(x, y + 3); cout << "(_________________)";
		Console::SetCursorPosition(x, y + 4); cout << "     \\_______/    ";
	}
};


