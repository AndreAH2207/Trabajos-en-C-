#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;

char of[3] = { 'C','S','L'};

struct Empleado
{
	int horas;
	int minutos;
	char oficina;
};


void genera_arreglos(Empleado* vempleado)
{
	Random r;
	for (int i = 0; i < 15; i++)
	{
		vempleado[i].horas = r.Next(20, 51);
		vempleado[i].minutos = r.Next(0, 181);
		vempleado[i].oficina = of[rand() % 3];
	}
}

void imprime_arreglos(Empleado* vempleado)
{
	cout << "Horas trabajadas\tOficina\t\tMinutos de tardanza" << endl;

	for (int i = 0; i < 15; i++)
	{
		cout << "     [" << vempleado[i].horas << "]\t\t  [" << vempleado[i].oficina << "]\t\t\t[" << vempleado[i].minutos << "]" << endl;
	}
}

void empleados_mas_trabajadores(Empleado* vempleado)
{
	int cont = 0;

	for (int i = 0; i < 15; i++)
	{
		if (vempleado[i].horas > 30)
		{
			cout << "Codigo de empleado " << i+1 << ":\t" << vempleado[i].horas << vempleado[i].oficina << vempleado[i].minutos << endl;
		}
	}
}

void promedio_de_tardanzas_por_oficina(Empleado* vempleado)
{
	int sumaC = 0;
	int sumaS = 0;
	int sumaL = 0;

	int contC = 0;
	int contS = 0;
	int contL = 0;

	int promedioC = 0;
	int promedioS = 0;
	int promedioL = 0;

	for (int i = 0; i < 15; i++)
	{
		if (vempleado[i].oficina == 'C')
		{
			contC++;
			sumaC += vempleado[i].minutos;
		}
		if (vempleado[i].oficina == 'S')
		{
			contS++;
			sumaS += vempleado[i].minutos;
		}
		if (vempleado[i].oficina == 'L')
		{
			contL++;
			sumaL += vempleado[i].minutos;
		}
	}
	if (contC == 0) 
	{
		contC = 1; 
	}
	if (contS == 0)
	{
		contS = 1;
	}
	if (contL == 0)
	{
		contL = 1;
	}

	promedioC = sumaC / contC;
	promedioS = sumaS / contS;
	promedioL = sumaL / contL;

	cout << "El promedio de tardanzas para la oficina de Contabilidad es: " << promedioC << endl;
	cout << "El promedio de tardanzas para la oficina de Sistemas es: " << promedioS << endl;
	cout << "El promedio de tardanzas para la oficina de Logistica es: " << promedioL << endl;
}

void empleados_puntuales(Empleado* vempleado)
{
	int cont = 0;

	for (int i = 0; i < 15; i++)
	{
		if (vempleado[i].minutos == 0)
		{
			cout << "*EMPLEADO PUNTUAL " << endl;
			cout << "Codigo de empleado numero " << i + 1 << ":\t" << vempleado[i].horas << vempleado[i].oficina << vempleado[i].minutos << endl;
			cout << "Horas trabajadas: " << vempleado[i].horas << " horas" << endl;
			cout << "Oficina: " << vempleado[i].oficina << endl;
			cout << endl;
			cont++;
		}
	}
		if (cont == 0)
		{
			cout << "No hay empleados puntales :( " << endl;
		}
}

void ordena_arreglos(Empleado* vempleado)
{
	int auxH = 0;
	int auxO = 0;
	int auxM = 0;

	for (int i = 0; i < 15; i++)
	{
		for (int j = i + 1; j < 15; j++)
		{
			if (vempleado[i].oficina > vempleado[j].oficina)
			{
				auxH = vempleado[i].horas;
				vempleado[i].horas = vempleado[j].horas;
				vempleado[j].horas = auxH;

				auxO = vempleado[i].oficina;
				vempleado[i].oficina = vempleado[j].oficina;
				vempleado[j].oficina = auxO;

				auxM = vempleado[i].minutos;
				vempleado[i].minutos = vempleado[j].minutos;
				vempleado[j].minutos = auxM;
			}
			else if (vempleado[i].oficina == vempleado[j].oficina && vempleado[i].horas < vempleado[j].horas)
			{
				auxH = vempleado[i].horas;
				vempleado[i].horas = vempleado[j].horas;
				vempleado[j].horas = auxH;

				auxO = vempleado[i].oficina;
				vempleado[i].oficina = vempleado[j].oficina;
				vempleado[j].oficina = auxO;

				auxM = vempleado[i].minutos;
				vempleado[i].minutos = vempleado[j].minutos;
				vempleado[j].minutos = auxM;
			}
		}
	}
}

int main()
{
	srand(time(NULL));
	cout << endl;
	Empleado* vempleado = new Empleado[15];
	genera_arreglos(vempleado);
	imprime_arreglos(vempleado);
	cout << endl;
	cout << "===================EMPLEADOS MAS TRABAJADORES======================" << endl;
	cout << endl;
	empleados_mas_trabajadores(vempleado);
	cout << endl;
	cout << "=============PROMEDIO DE TARDANZAS PARA CADA OFICINA===============" << endl;
	cout << endl;
	promedio_de_tardanzas_por_oficina(vempleado);
	cout << endl;
	cout << "==================CODIGOS DE EMPLEADOS PUNTUALES===================" << endl;
	cout << endl;
	empleados_puntuales(vempleado);
	cout << endl;
	cout << "======================ORDENANDO EMPLEADOS==========================" << endl;
	cout << endl;
	ordena_arreglos(vempleado);
	imprime_arreglos(vempleado);
	
	_getch();
	return 0;
}