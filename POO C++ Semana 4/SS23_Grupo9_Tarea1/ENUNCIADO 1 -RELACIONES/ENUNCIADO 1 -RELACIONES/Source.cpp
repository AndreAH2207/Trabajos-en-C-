#include <iostream>
#include <conio.h>
#include <vector>
#include "Cuartel.h"

using namespace std;

void main()
{
    Soldado* sol1 = new Soldado("Juan Dominguez", 8);
    Soldado* sol2 = new Soldado("Pedro Flores", 5);
    Soldado* sol3 = new Soldado("Alan Garcia", 9);

    Torreta* torr1 = new Torreta("T100", "M700", 4);
    Tanque* tan1 = new Tanque("Leopard", torr1);

    Torreta* torr2 = new Torreta("T200", "M800", 2);
    Tanque* tan2 = new Tanque("Tiger", torr2);

    Torreta* torr3 = new Torreta("T900", "M100", 1);
    Tanque* tan3 = new Tanque("Lion", torr3);

    Cuartel* cuar1 = new Cuartel(7, "ALFA");

    cuar1->asignarSoldado(sol1);
    cuar1->asignarSoldado(sol2);
    cuar1->asignarSoldado(sol3);

    cuar1->asignarTanque(tan1);
    cuar1->asignarTanque(tan2);
    cuar1->asignarTanque(tan3);

    cuar1->mostrarInformacion();

    delete cuar1;

    delete torr1;
    delete torr2;
    delete torr3;

    delete tan1;
    delete tan2;
    delete tan3;

    delete sol1;
    delete sol2;
    delete sol3;

    _getch();
}