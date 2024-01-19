#pragma once
#include <iostream>
using namespace std;
using namespace System;
class Llanta {
private:
	ConsoleColor color;
	int x, y;
	const char ASC = 219;
public:
	Llanta(int x, int y, ConsoleColor color) {
		this->x = x;
		this->y = y;
		this->color = color;
	}
	Llanta(ConsoleColor color) {
		this->color = color;
	}
	void setXY(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void draw() {
		Console::ForegroundColor = color;
		Console::SetCursorPosition(x, y);
		cout << char(ASC);
	}
};