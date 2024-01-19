#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

struct Empresa
{
	long long RUC;
	char distrito;
	char tipo;
	int Fechaevaluacion;
};

struct Rubro
{
	int codigo;
	string descripcion;
	string categoria;
};

int menu()
{
	int op;
	do
	{
		cout << "[1] Registrar" << endl;
		cout << "[2] Reportes" << endl;
		cout << "[3] Fin" << endl;
		cout << endl;
		cout << "Seleccione una opcion: "; cin >> op;
	} while (op < 1 || op > 3);
	return op;
}

int menuRegistro()
{
	int op;
	do
	{
		cout << "[1] Registrar empresa	" << endl;
		cout << "[2] Registrar rubro" << endl;
		cout << "[3] Fin" << endl;
		cout << endl;
		cout << "Seleccione una opcion: "; cin >> op;
	} while (op < 1 || op > 3);
	return op;
}

int menuReportes()
{
	int op;
	do
	{
		cout << "[1] Mostrar el número de empresas por cada distrito" << endl;
		cout << "[2] Mostrar los datos de las pequeñas empresas que han sido evaluadas en los últimos dos meses" << endl;
		cout << "[3] Mostrar un reporte de las empresas ordenadas ascendentemente por el distrito" << endl;
		cout << "[4] Fin" << endl;
		cout << endl;
		cout << "Seleccione una opcion: "; cin >> op;
	} while (op < 1 || op > 4);
	return op;
}

Empresa* RegistrarEmpresa(Empresa* vempresa, int* n)
{
	Empresa* vaux = new Empresa[*n + 1];

	if (*n != 0)	
	{
		for (int i = 0; i < *n; i++)
		{
			vaux[i] = vempresa[i];
		}
	}

	long long RUC;
	char d;
	char t;
	int f;

	bool Validar;
	do {
		do
		{
			Validar = false;
			cout << "Ingrese un RUC: ";
			cin >> vaux[*n].RUC;
		} while (vaux[*n].RUC < 100000000000 || vaux[*n].RUC > 99999999999);

		for (int i = 0; i < *n; i++)
		{
			if (vempresa[i].RUC = vaux[*n].RUC)
			{
				Validar = true;
				break;
			}
		}
	} while (Validar == true);

	do
	{
		cout << "Ingrese el distrito [San Isidro (I), San Borja (S), Jesús Maria (J), Breña(B), Cercado de Lima (L)]: ";
		cin >> vaux[*n].distrito;
		vaux[*n].distrito != toupper(vaux[*n].distrito);

	} while (vaux[*n].distrito != 'I' && vaux[*n].distrito != 'S' && vaux[*n].distrito != 'J' && vaux[*n].distrito != 'B' && vaux[*n].distrito != 'L');

	do
	{
		cout << "Ingrese el tipo [Pequena (P), Mediana (M), Grande (G): ";
		cin >> vaux[*n].tipo;
		vaux[*n].tipo != toupper(vaux[*n].tipo);

	} while (vaux[*n].tipo != 'P' && vaux[*n].tipo != 'M' && vaux[*n].tipo != 'G');

	do
	{
		cout << "Fecha de evaluacion: ";
		cin >> vaux[*n].Fechaevaluacion;

	} while (vaux[*n].Fechaevaluacion < 101 || vaux[*n].Fechaevaluacion > 3112);

	*n = *n + 1;
	return vaux;
}



void mostrarEmpresasDistrito(Empresa* vempresa, int* n)
{
	for (int i = 0; i < *n; i++)
	{
		cout << "[" << vempresa[i].RUC << "]\t[" << vempresa[i].distrito << "]\t[" << vempresa[i].tipo << "]\t[" << vempresa[i].Fechaevaluacion << "]";
	}
}

void ordenarEmpresasDistintas(Empresa* ve, int* n)
{
	long long auxR;
	char auxD;
	char auxT;
	int auxF;

	for (int i = 0; i < *n, i++)
	{

	}
}

int main()
{
	srand(time(NULL));
	int* n = new int;
	*n = 0;

	Empresa* vempresa = new Empresa[*n];
	Rubro* vrubro = new Rubro[*n];

	int op, opRg, opRp;

	do
	{
		op = menu();
		switch (op)
		{
		case 1: opRg = menuRegistro();
			{
			switch (opRg)
				{
				case 1: RegistrarEmpresa(vempresa, n); break;
				case 2: RegistrarRubro(vrubro, n); break;
				case 3: break;
				}
			break;
		case 2:opRp = menuReportes();
			switch (opRp)
				{
				case 1: mostrarEmpresasDistrito(vempresas, n); break;
				case 2: mostrarEmpresasEvaluadas(vempresas, n); break;
				case 3: ordenarEmpresasDistrito(vempresas, n); break;
				}
			}
		}
	}

}