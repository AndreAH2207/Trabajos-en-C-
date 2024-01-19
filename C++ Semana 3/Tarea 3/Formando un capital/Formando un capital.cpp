#include "pch.h"
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    float C, J, E, capitalTotal;
    float pC, pJ, pE;

    cout << "Ingrese aporte de Carmela: "; cin >> C;
    cout << "Ingrese aporte de Javier:  " ; cin >> J;
    cout << "Ingrese aporte de Eulogio: "; cin >> E;

    capitalTotal = C + J + E;

    pC = (C/capitalTotal) * 100;
    pJ = (J / capitalTotal) * 100;
    pE = (E / capitalTotal) * 100;

    cout << endl;
    cout << "El capital formado es de: " << capitalTotal << " soles" << endl;
    cout << endl;
    cout << "El porcentaje de capital de Carmela es de : " << trunc(pC*100)/100 << "%" << endl;
    cout << "El porcentaje de capital de Javier es de : " << trunc(pJ*100)/100 << "%" << endl;
    cout << "El porcentaje de capital de Eulogio es de : " << trunc(pE*100)/100 << "%" << endl;

    _getch();
    return 0;
}
