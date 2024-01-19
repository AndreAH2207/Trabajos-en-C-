#pragma once
#include <iostream>
using namespace std;
using namespace System;
class Chasis {
private:
	ConsoleColor color;
	int x, y;
	const char = 220;
public:
	Chasis(int x, int y, ConsoleColor color) {
		this->x = x;
		this->y = y;
		this->color = color;
	}
	Chasis(ConsoleColor color) {
		this->color = color;
	}
	void setXY(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void draw() {
		Console::ForegroundColor = color;
		Console::SetCursorPosition(x, y);
		cout << char(ASC) << char(ASC) << char(ASC) << char(ASC) << char(ASC);
	}
};
