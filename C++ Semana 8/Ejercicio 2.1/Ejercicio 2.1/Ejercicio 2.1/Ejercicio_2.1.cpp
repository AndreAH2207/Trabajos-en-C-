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
    } while (user != 'G' && user != 'E' && user != 'P' && user != 'H');
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
    float ContG = 0.0;
    float ContE = 0.0;
    int ContT = 0;
    int ContEdad = 0;
    int ContDia = 0;
    int ContTarde = 0;
    int ContNoche = 0;

    do
    {
        usuario = Usuario();
        if (usuario == 'H')
            break;
        edad = Edad();
        hora = Hora();
        tipo = Tipo();
        cout << endl;

        if (usuario == 'G' || usuario == 'E' || usuario == 'P')
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

        if (hora > 6 && hora < 12)
        {
            ContDia++;
        } 
        else if (hora >= 12 && hora <= 18)
        {
            ContTarde++;
        }
        else if (hora > 18 || hora <= 6)
        {
            ContNoche++;
        }

    } while (usuario != 'H');             

    cout << endl;
    cout << "Porcentaje de Gamers cuya edad oscila entre los 18 y 25 anios: " << (ContE / ContG) * 100 << " % " << endl;
    cout << "Edad promedio de usuarios que realizan una consulta del tipo academico o de trabajo: " << ContEdad / ContT << " anios" << endl;
    cout << "Momento o momentos del dia en que se realizan mas accesos:" << endl;
    if (ContDia >= ContTarde && ContDia >= ContNoche)
    {
        cout << "MANIANA" << endl;
    }
    if (ContTarde >= ContDia && ContTarde >= ContNoche)
    {
        cout << "TARDE" << endl;
    }
    if (ContNoche >= ContDia && ContNoche >= ContTarde)
    {
        cout << "NOCHE" << endl;
    }

    _getch();
    return 0;
}