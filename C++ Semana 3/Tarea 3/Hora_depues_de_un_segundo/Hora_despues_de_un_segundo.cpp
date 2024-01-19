#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int h, m, s;
	
	cout << " Escribe las horas: "; cin >> h;
	cout << " Escribe los minutos: "; cin >> m;	
	cout << " Escribe los segundos: "; cin >> s;

	cout << endl;
	cout << "Hora ingresada: " << endl;

	cout << h << " : " << m << " : " << s << endl;



	_getch();
	return 0;
}