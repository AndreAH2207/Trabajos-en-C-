#include <iostream>
#include <conio.h>

using namespace std;

void Ingresar_Datos(int& P_Cusco2020, int& P_Puno2020, int& P_Cusco2021, int& P_Puno2021, int& P_Cusco2022, int& P_Puno2022)
{
    cout << "Ingrese % Mujeres violentadas en Cusco en el 2020: ";
    cin >> P_Cusco2020;

    cout << "Ingrese % Mujeres violentadas en Puno en el 2020: ";
    cin >> P_Puno2020;

    cout << endl;

    cout << "Ingrese % Mujeres violentadas en Cusco en el 2021: ";
    cin >> P_Cusco2021;

    cout << "Ingrese % Mujeres violentadas en Puno en el 2021: ";
    cin >> P_Puno2021;

    cout << endl;

    cout << "Ingrese % Mujeres violentadas en Cusco en el 2022: ";
    cin >> P_Cusco2022;

    cout << "Ingrese % Mujeres violentadas en Puno en el 2022: ";
    cin >> P_Puno2022;
}

void Dibujar_Caracteres(char c, int p)
{
    for (int i = 0; i < p; i += 10)
    {
        cout << c;
    }
    cout << " " << p << "%" << endl;
}

int main()
{
    int P_Cusco2020, P_Puno2020, P_Cusco2021, P_Puno2021, P_Cusco2022, P_Puno2022;
    char C_Cusco, C_Puno;

    Ingresar_Datos(P_Cusco2020, P_Puno2020, P_Cusco2021, P_Puno2021, P_Cusco2022, P_Puno2022);

    cout << "Ingrese caracter para Cusco: ";
    cin >> C_Cusco;
    cout << "Ingrese caracter para Puno: ";
    cin >> C_Puno;

    cout << endl;

    cout << "2020 Cusco: ";
    Dibujar_Caracteres(C_Cusco, P_Cusco2020);

    cout << "2020 Puno: ";
    Dibujar_Caracteres(C_Puno, P_Puno2020);

    cout << endl;

    cout << "2021 Cusco: ";
    Dibujar_Caracteres(C_Cusco, P_Cusco2021);

    cout << "2021 Puno: ";
    Dibujar_Caracteres(C_Puno, P_Puno2021);

    cout << endl;

    cout << "2022 Cusco: ";
    Dibujar_Caracteres(C_Cusco, P_Cusco2022);

    cout << "2022 Puno: ";
    Dibujar_Caracteres(C_Puno, P_Puno2022);

    _getch();
    return 0;
}