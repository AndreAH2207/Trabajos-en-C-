#include "pch.h"
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    float A, B, C, AreaTotal, AreaDeTriangulo, AreaDeRectangulo;

    cout << "Ingrese valor de la altura mayor: "; cin >> A;
    cout << "Ingrese valor de la base: "; cin >> B;
    cout << "Ingrese valor de la altura menor: "; cin >> C;

    AreaDeTriangulo = ((A - C) * B) / 2;
    AreaDeRectangulo = B * C;
    AreaTotal = AreaDeRectangulo + AreaDeTriangulo;

    cout << "El area total es: " << AreaTotal;
    cout << endl;

    _getch();
    return 0;
}
