#include <iostream>
#include <conio.h>

using namespace std;
	
int Nivel()
{
	int n;
	do
	{
		cout << "Nivel de satisfaccion (Valor entre 1 y 5): "; cin >> n;
	} while (n > 5 || n < 1 && n != -1);
	return n;
}

char Sexo()
{
	char s;
	do
	{
		cout << "Sexo (M: Masculino; F: Femenino): "; cin >> s;
		s = toupper(s);

	} while (s != 'M' && s != 'F');
	return s;
}

int Edad()
{
	int e;
	do
	{
		cout << "Edad: "; cin >> e;

	} while (e > 150 || e < 0);
	return e;
}

char Como_Se_Entero()
{
	char f;
	do
	{
		cout << "Como se entero del seminario (C: Correo; L: Llamada; O: Otros): "; cin >> f;
		f = toupper(f);

	} while (f != 'C' && f != 'L' && f != 'O');
	return f;
}

int main()
{
	int nivel, edad;
	char sexo, como_se_entero;
	float ContN = 0;
	float Cont_tres = 0;
	do
	{
		nivel = Nivel();
		if (nivel == -1)break;
		sexo = Sexo();
		edad = Edad();
		como_se_entero = Como_Se_Entero();
		cout << endl;

		if (nivel >= 1)
		{
			ContN++;
			if (nivel > 3)
			{
				Cont_tres++;
			}
		}													
	} while (nivel != -1);

	cout << endl;
	cout << "Porcentaje de asistentes que calificaron el seminario con un nivel de satisfaccion superior a 3: " << (Cont_tres * 100 / ContN) << " % " << endl;

	_getch();
	return 0;
}