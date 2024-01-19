		#pragma once
#include "Naves.h"
class Beta :public Naves {
public:
	Beta() {
		ID = 2;
		x = 0 + rand() % 100;
		y = 0;
		dx = 0;
		//dy = rand() % 3 + 1;
		dy = 1;
		width = 13;
		height = 3;
		color = 1 + rand() % 15;
	}
	void draw() {
		Console::ForegroundColor = ConsoleColor(color);
		Console::SetCursorPosition(x, y + 0); cout << "    .---.    ";
		Console::SetCursorPosition(x, y + 1); cout << "  _/__~0_\\_ ";
		Console::SetCursorPosition(x, y + 2); cout << " (_________) ";
	}

};


