#include <iostream>
#include <conio.h>

using namespace std;

char Usuario()
{
    char user;
    do
    {
        cout << "Ingrese tipo de usuario: ";
        cin >> user;
        user = toupper(user);
    } while (user != 'G' && user != 'E' && user != 'P');
    return user;
}

int Edad()
{
    int e;
    do
    {
        cout << "Edad de usuario: ";
        cin >> e;
    } while (e > 120 || e < 10);
    return e;
}

int Hora()
{
    int hora;
    do
    {
        cout << "Hora de acceso: ";
        cin >> hora;
    } while (hora > 23 || hora < 0);
    return hora;
}

char Tipo()
{
    char tipo;
    do
    {
        cout << "Tipo de consulta: ";
        cin >> tipo;
        tipo = toupper(tipo);
    } while (tipo != 'E' && tipo != 'A' && tipo != 'D' && tipo != 'T');
    return tipo;
}

int main()
{
    int edad, hora;
    char usuario, tipo;
    int ContG = 0;
    int ContE = 0;
    int ContT = 0;
    int ContEdad = 0;

    do
    {
        usuario = Usuario();
        if (usuario == 'H')
            break;
        edad = Edad();
        hora = Hora();
        tipo = Tipo();
        cout << endl;

        if (usuario == 'G')
        {
            ContG++;
            if (edad >= 18 && edad <= 25)
            {
                ContE++;
            }
        }

        if (tipo == 'A' || tipo == 'T')
        {
            ContT++;
            ContEdad += edad;
        }


    } while (usuario != 'H');

    cout << endl;
    cout << "Porcentaje de Gamers cuya edad oscila entre los 18 y 25 años: " << (ContE * 100 / ContG) << " % " << endl;
    _getch();
    return 0;
}