#pragma once
#include <iostream>

using namespace std;
using namespace System;

#define WIDTH 120
#define HEIGHT 30 

class Naves {
protected:
	int ID, x, y, dx, dy, width, height, color;

public:
	Naves() {}
	~Naves() {}

	virtual void draw() {};

	bool  move() 
	{
		if (x + dx < 0 || x + dx + width>WIDTH)
			dx *= -1;
		if (y + dy < 0 || y + dy + height>HEIGHT) {
			//dy *= -1;
			dy = 0;
			return true;//llego al final inferior
		}		
		x += dx;
		y += dy;
		return false;//no llega al final
	}
	void clear() {
		for ( int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				Console::SetCursorPosition(x + j, y + i);//gotoxy(x,y)
				cout << " ";
			}
		}
	}
	
	int getWidth() { return width; }
	int getHight() { return height; }
	int getX() { return x;}
	int getY() { return y; }
	int getDx() { return dx;}
	int getDy() { return dy;}
	int getID() { return ID;}
};

