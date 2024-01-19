#include <iostream>
#include <conio.h>

using namespace std;

char m[4] = { 'R','C','Y','P' };
char c[3] = { 'P','R','N' };


struct Auto
{
	int serie;
	char modelo;
	char color;
};

int IngresarCant() {
	int n;
	do {
		cout << "Ingrese la cantidad de autos: ";
		cin >> n;
	} while (n < 1 || n>200);
	return n;
}

void GenerarDatos(Auto* va, int n)
{
	for (int i = 0; i < n; i++)
	{
		va[i].serie = 100000 + rand() % 899999;
		va[i].modelo = m[rand() % 4];
		va[i].color = c[rand() % 3];
	}
}

void MostrarDatos(Auto* va, int n)
{

	cout << "* Impriendo los numeros de serie de los motores (Entero de 6 digitos)" << endl;
	cout << "* Imprimiento el caracter inicial de los modelo (Rav4, Corolla, Yaris, Prius)" << endl;
	cout << "* Imprimiendo el caracter inicial del color (Plateado, Rojo, Negro)" << endl;
	cout << endl;
	cout << endl;

	cout << " Serie      Modelo     Color" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "[" << va[i].serie << "]     [" << va[i].modelo << "]\t[" << va[i].color << "]" << endl;
	}
}

void RegistarCantModelos(Auto* va, int n)
{
	int contMR = 0;
	int contMC = 0;
	int contMY = 0;
	int contMP = 0;

	for (int i = 0; i < n; i++)
	{
		if (va[i].modelo == 'R')
		{
			contMR++;
		}
		if (va[i].modelo == 'C')
		{
			contMC++;
		}
		if (va[i].modelo == 'Y')
		{
			contMY++;
		}
		if (va[i].modelo == 'P')
		{
			contMP++;
		}
	}

	cout << endl;
	cout << "La cantidad de autos de modelo Rav4 son: " << contMR << endl;
	cout << "La cantidad de autos de modelo Corolla son: " << contMC << endl;
	cout << "La cantidad de autos de modelo Yaris son: " << contMY << endl;
	cout << "La cantidad de autos de modelo Prius son: " << contMP << endl;
	cout << endl;
}


void RegistarCantColor(Auto* va, int n)
{
	int contCP = 0;
	int contCR = 0;
	int contCN = 0;

	for (int i = 0; i < n; i++)
	{
		if (va[i].color == 'P')
		{
			contCP++;
		}
		if (va[i].color == 'R')
		{
			contCR++;
		}
		if (va[i].color == 'N')
		{
			contCN++;
		}
	}

	cout << endl;
	cout << "La cantidad de autos de color plateado son: " << contCP << endl;
	cout << "La cantidad de autos de color rojo son: " << contCR << endl;
	cout << "La cantidad de autos de color negro son: " << contCN << endl;
	cout << endl;
}

char IngresarModelo()
{
	char m;
	do
	{
		cout << "Ingrese un modelo (Rav4, Corolla, Yaris, Prius):  "; cin >> m;
		m = toupper(m);
	} while (m != 'R' && m != 'C' && m != 'Y' && m != 'P');
}

void ColoresDisponibles(Auto* va, int n)
{
	int contCR = 0;
	int contCP = 0;
	int contCN = 0;

	char modelo = IngresarModelo();

	for (int i = 0; i < n; i++)
	{
		if (va[i].modelo == modelo)
		{
			switch (va[i].color)
			{
			case 'P': contCP++; break;
			case 'R': contCR++; break;
			case 'N': contCN++; break;
			}
		}
	}

	cout << 

}

int main()
{
	srand(time(NULL));
	int n = IngresarCant();

	Auto* vauto = new Auto[n];
	GenerarDatos(vauto, n);
	cout << endl;
	cout << endl;
	MostrarDatos(vauto, n);
	RegistarCantModelos(vauto, n);
	RegistarCantColor(vauto, n);

	delete vauto;
	_getch();
	return 0;
}