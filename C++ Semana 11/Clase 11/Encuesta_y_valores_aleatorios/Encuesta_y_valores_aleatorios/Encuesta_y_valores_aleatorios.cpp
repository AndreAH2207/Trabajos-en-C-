#include <iostream>
#include <conio.h>

using namespace std;

char letras[4		] = { 'A','C','L','P' };

struct Encuesta
{
	int nivel;
	int edad;
	char dpto;
};

int Ingresar_Cantidad()
{
	int n;
	do
	{
		cout << "Ingrese la cantidad de encuestados: "; cin >> n;
	} while (n < 1 || n>100);
	return n;
}

void Generar_Datos(Encuesta* ve, int n)
{
	for (int i = 0; i < n; i++)
	{
		ve[i].nivel = 1 + rand() % 5;
		ve[i].edad = 17 + rand() % 94; //17-110
		ve[i].dpto = letras[rand() % 4];
	}
}

void Mostrar_Datos(Encuesta* ve, int n)
{
	cout << " Nivel\tEdad\tDpto" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << " [" << ve[i].nivel << "]\t[" << ve[i].edad << "]\t[" << ve[i].dpto << "]" << endl;
	}
}

void Calcular_Votación_Obtenida(Encuesta* ve, int n)
{
	int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0;

	for (int i = 0; i < n; i++)
	{
		switch (ve[i].nivel)
		{
		case 1: c1++; break;
		case 2: c2++; break;
		case 3: c3++; break;
		case 4: c4++; break;
		case 5: c5++; break;
		}
	}
	cout << endl;
	cout << "Puntaje de nivel 1: " << c1 << endl;
	cout << "Puntaje de nivel 2: " << c2 << endl;
	cout << "Puntaje de nivel 3: " << c3 << endl;
	cout << "Puntaje de nivel 4: " << c4 << endl;
	cout << "Puntaje de nivel 5: " << c5 << endl;
}

void Calcular_Participación(Encuesta* ve, int n)
{
	int cont = 0;
	for (int i = 0; i < n; i++)
	{
		if (ve[i].dpto == 'C' || ve[i].dpto == 'P')
		{
			cont++;
		}
	}
	cout << endl;
	cout << "La cantidad de personas encuestadas en Cajamarca y Puno: " << cont << endl;
}

void Ordenar_Descendente(Encuesta* ve, int n)
{
	int aux1;
	int aux2;
	char aux3;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (ve[i].edad < ve[j].edad)
			{
				aux1 = ve[i].edad;
				ve[i].edad = ve[j].edad;
				ve[j].edad = aux1;

				aux2 = ve[i].nivel;
				ve[i].nivel = ve[j].nivel;
				ve[j].nivel = aux2;

				aux3 = ve[i].dpto;
				ve[i].dpto = ve[j].dpto;
				ve[j].dpto = aux3;
			}
		}
	}
}

void Calcular_Mayor_Menor(Encuesta* ve, int n)
{
	int mayor = ve[0].edad;
	int menor = ve[0].edad;
	char mayorD = ve[0].dpto;
	char menorD = ve[0].dpto;

	for (int i = 0; i < n; i++)
	{
		if (ve[i].edad > mayor)
		{
			mayor = ve[i].edad;
			mayorD = ve[i].dpto;
		}
		if (ve[i].edad < menor)
		{
			menor = ve[i].edad;
			mayorD = ve[i].dpto;
		}
	}

	cout << "El departamento " << mayorD << " obtuvo la mayor edad que es de: " << mayor << endl;
	cout << "El departamento " << menorD << " obtuvo la menor edad que es de: " << menor << endl;
}		

int main()
{
	srand(time(NULL));

	int n = Ingresar_Cantidad();

	Encuesta* vencuesta = new Encuesta[n];
	Generar_Datos(vencuesta, n);
	Mostrar_Datos(vencuesta, n);
	Calcular_Votación_Obtenida(vencuesta, n);
	Calcular_Participación(vencuesta, n);
	Ordenar_Descendente(vencuesta, n);
	cout << endl;
	cout << "Mostramos los datos ascendentemente: " << endl;
	cout << endl;
	Mostrar_Datos(vencuesta, n);
	Calcular_Mayor_Menor(vencuesta, n);

	_getch();
	return 0;
}