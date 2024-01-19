#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#define ANCHO  110
#define ALTO  25

using namespace std;
using namespace System;


// Función para colocar el cursor en una posición específica en la consola
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class Raton {
private:
    int x;
    int y;
    int dx;
    int dy;
    int ancho, alto;

public:
    Raton(int x, int y, int dx, int dy, int ancho, int alto)
        : x(x), y(y), dx(dx), dy(dy), ancho(ancho), alto(alto) {}
    Raton() {
        alto = 3;
        ancho = 19;
        dx = 2;
        dy = 2;
        x = 1;
        y = 1;
    }

    void draw() {
        if (dx > 0) {
            gotoxy(x, y);
            cout << "        ____()()";
            gotoxy(x, y + 1);
            cout << "      /      @@";
            gotoxy(x, y + 2);
            cout << "`~~~~~\\_;m__m._>o";
        }
        else {
            gotoxy(x, y);
            cout << "  ()()____";
            gotoxy(x, y + 1);
            cout << "  @@      \\";
            gotoxy(x, y + 2);
            cout << "o<_.m__m;_/~~~~~`";
        }
    }

    void mover(int xq, int yq, bool queso) {
        if (queso == false) {
            if (!(x + dx > 0 && (x + ancho + dx) < ANCHO))
                dx *= -1;
            if (!(y + dy > 0 && y + alto + dy < ALTO))
                dy *= -1;
            x += dx;
            y += dy;
        }
        else {
            if (x < xq && y > yq) {
                dx = 1; dy = -1;
            }
            else {
                if (x < xq && y < yq) {
                    dx = 1; dy = 1;
                }
                else {
                    if (x < xq && y < yq) {
                        dx = 1; dy = 1;
                    }
                    else {
                        if (x > xq && y > yq) {
                            dx = -1; dy = -1;
                        }
                        else {
                            if (x > xq && y < yq) {
                                dx = -1; dy = 1;
                            }
                            else {
                                if (x == xq && y > yq) {
                                    dy = -1; dx = 0;
                                }
                                else {
                                    if (x == xq && y < yq) {
                                        dy = 1; dx = 0;
                                    }
                                    else {
                                        if (x > xq && y == yq) {
                                            dx = -1; dy = 0;
                                        }
                                        else {
                                            if (x < xq && y == yq) {
                                                dx = 1; dy = 0;
                                            }
                                            else {
                                                if (x == xq && y == yq) {
                                                    dx = dy = 0;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        x += dx;
        y += dy;
    }

    void clear() {
        for (int i = 0; i < alto; i++) {
            for (int j = 0; j < ancho; j++) {
                gotoxy(x + j, y + i);
                cout << " ";
            }
        }
    }

    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
};





