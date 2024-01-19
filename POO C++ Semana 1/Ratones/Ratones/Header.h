#pragma once
#include <iostream>
#include <stdio.h>  
#include <windows.h> 

#define ANCHO 120
#define ALTO 60

using namespace std;
using namespace System;

void gotoxy(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

class CRaton
{
private:
    int x;
    int y;
    int dx;
    int dy;
    int ancho;
    int alto;

public:
    CRaton(int x, int y, int dx, int dy, int ancho, int alto)
    {
        this->x = x;
        this->y = y;
        this->dx = dx;
        this->dy = dy;
        this->ancho = ancho;
        this->alto = alto;
    }

    void draw()
    {
        gotoxy(x, y);     cout << "        _____()()";
        gotoxy(x, y + 1); cout << "       /       @@";
        gotoxy(x, y + 2); cout << "`----- \_;m__m._>O";
    }

    void mover()
    {
        if (!(x + dx > 0 && (x + ancho + dx) < ANCHO))
        {
            dx *= -1;
        }
        if (!(y + dy > 0 && (y + alto + dy) < ALTO))
        {
            dy *= -1;
        }
        x += dx;
        y += dy;
    }

    void setX(int x)
    {
        this->x = x;
    }

    int getx()
    {
        return x;
    }
};