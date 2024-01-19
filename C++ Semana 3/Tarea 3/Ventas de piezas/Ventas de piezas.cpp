#include "pch.h"
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    float precioDeCompra, porcentajeDeGanancia, precioDeVenta, ganancia;

    cout << "Escribe el precio de compra: "; cin >> precioDeCompra;
    cout << "Escribe el porcentaje de ganancia: "; cin >> porcentajeDeGanancia;
    cout << endl;

    ganancia = precioDeCompra * (porcentajeDeGanancia / 100);
    precioDeVenta = precioDeCompra + ganancia;

    cout << "El precio al que se debe vender sera de: " << precioDeVenta << " soles";
    cout << endl;


    getch();
    return 0;
}