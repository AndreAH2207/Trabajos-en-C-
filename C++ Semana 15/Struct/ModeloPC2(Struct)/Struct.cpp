#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;

struct Persona
{
	int ficha;
	int peso;
	float talla;
	int pulso;
	int temperatura;
};

int IngresarCant()
{
	int n;
	do
	{
		cout << "Ingrese la cantidad de personas: "; cin >> n;
	} while (n < 5 && n > 10);
	return n;
}

void GenerarDatos(Persona* vpersona, int n)
{
	Random r;
	for (int i = 0; i < n; i++)
	{
		vpersona[i].ficha =r.Next(100000000,1000000000);
		vpersona[i].peso = 50 + rand() % 51;
		vpersona[i].talla = 170 + rand() % 22;
		vpersona[i].pulso = 0 + rand() % 2;
		vpersona[i].temperatura = 20 + rand() % 15;
	}
}

void ImprimirDatos(Persona* vpersona, int n)
{
	cout << "Numero de fichas\tPeso\tTalla\tPulso Cardiaco\tTemperatura" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "  [" << vpersona[i].ficha << "]\t\t[" << vpersona[i].peso << "]\t[" << vpersona[i].talla << "]\t    [" << vpersona[i].pulso << "]\t\t   [" << vpersona[i].temperatura << "]" << endl;
	}
}

void OrdenarDescendentemente(Persona* vpersona, int n)
{
	int auxF;
	int auxP;
	int auxT;
	int auxPl;
	int auxTp;


	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (vpersona[i].ficha < vpersona[j].ficha)
			{
				auxF = vpersona[i].ficha;
				vpersona[i].ficha = vpersona[j].ficha;
				vpersona[j].ficha = auxF;

				auxP = vpersona[i].peso;
				vpersona[i].peso = vpersona[j].peso;
				vpersona[j].peso = auxP;

				auxT = vpersona[i].talla;
				vpersona[i].talla = vpersona[j].talla;
				vpersona[j].talla = auxT;


				auxPl = vpersona[i].pulso;
				vpersona[i].pulso = vpersona[j].pulso;
				vpersona[j].pulso = auxPl;

				auxTp = vpersona[i].temperatura;
				vpersona[i].temperatura = vpersona[j].temperatura;
				vpersona[j].temperatura = auxTp;
			}
		}
	}
	cout << endl;

}

void OrdenarAscendentemente(Persona* vpersona, int n)
{
	int auxF;
	int auxP;
	int auxT;
	int auxPl;
	int auxTp;


	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (vpersona[i].talla > vpersona[j].talla)
			{
				auxF = vpersona[i].ficha;
				vpersona[i].ficha= vpersona[j].ficha;
				vpersona[j].ficha = auxF;

				auxP = vpersona[i].peso;
				vpersona[i].peso= vpersona[j].peso;
				vpersona[j].peso = auxP;

				auxT = vpersona[i].talla;
				vpersona[i].talla= vpersona[j].talla;
				vpersona[j].talla = auxT;


				auxPl = vpersona[i].pulso;
				vpersona[i].pulso = vpersona[j].pulso;
				vpersona[j].pulso = auxPl;

				auxTp = vpersona[i].temperatura;
				vpersona[i].temperatura = vpersona[j].temperatura;
				vpersona[j].temperatura = auxTp;
			}
		}
	}
	cout << endl;
}

void CantPulso(Persona* vpersona, int n)
{
	int contP = 0;
	for (int i = 0; i < n; i++)
	{
		if (vpersona[i].pulso == 1)
		{
			contP++;
		}
	}
	cout << "La cantidad de personas con pulso cardiaco igual a 1 son: " << contP;
}

void PromedioTallas(Persona* vpersona, int n)
{
	int promedio = 0;
	int suma = 0;
	int aux = 0;

	for (int i = 0; i < n; i++)
	{
		if (vpersona[i].talla > 180)
		{
			suma += vpersona[i].talla;
			aux++;
		}
	}

	if (aux > 0)
	{
		promedio = suma / aux;
		cout << "El promedio de tallas mayores a 180 centimetros es: " << promedio;
	}
	else
	{
		cout << "No hay personas con talla mayor a 180 centimetros " << endl;
	}
}

void BuscarFicha(Persona* vpersona, int n)
{
	int ficha;
	char tecla;


	do {
		cout << "Ingrese la ficha que desea buscar: ";
		cin >> ficha;
		bool encontrado = false;

		for (int i = 0; i < n; i++)
		{
			
			if (vpersona[i].ficha == ficha)
			{
				encontrado = true;
				cout << "Datos de la persona con ficha " << ficha << ":" << endl;
				cout << "Peso: " << vpersona[i].peso << endl;
				cout << "Talla: " << vpersona[i].talla << endl;
				cout << "Pulso Cardiaco: " << vpersona[i].pulso << endl;
				cout << "Temperatura: " << vpersona[i].temperatura << endl;
				cout << endl;
			}
		} 

		if (encontrado == false)
		{
			cout << "No se encontro ninguna persona con la ficha: " << ficha << endl;
			cout << endl;
		}
		
		tecla = getch();

	} while (tecla != 27);
}

int main()
{
	srand(time(NULL));
	int n = IngresarCant();
	cout << endl;
	Persona* vpersona = new Persona[n];
	GenerarDatos(vpersona, n);
	ImprimirDatos(vpersona, n);
	cout << endl;
	cout << "===========ORDENADO DESCENDENTEMENTE POR NUMERO DE FICHA=============";
	cout << endl;
	OrdenarDescendentemente(vpersona, n);
	ImprimirDatos(vpersona, n);
	cout << endl;
	cout << "===========ORDENADO ASCENDENTEMENTE POR TALLA=============";
	cout << endl;
	OrdenarAscendentemente(vpersona, n);
	ImprimirDatos(vpersona, n);
	cout << endl;
	cout << "===========DATOS ADICIONALES=============";
	cout << endl;
	CantPulso(vpersona, n);
	cout << endl;
	PromedioTallas(vpersona, n);
	cout << endl;
	cout << endl;
	cout << "===========BUSCAR FICHA=============";
	cout << endl;
	BuscarFicha(vpersona, n);
	
	_getch();
	return 0;
}