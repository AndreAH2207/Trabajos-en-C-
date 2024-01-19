#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;

int menu()
{
	int op;
	do
	{
		cout << endl;
		cout << " 1) Ingresar datos " << endl;
		cout << " 2) Imprimir datos " << endl;
		cout << " 3) Ordenar de forma ascendente " << endl;
		cout << " 4) Buscar dato " << endl;
		cout << " 5) Salir " << endl;
		cout << endl;
		cout << " Ingrese una opcion...";
		cin >> op;
		cout << endl;
	} while (op < 0 && op > 4);
	system("cls");
	return op;
}

int IngresarCantidad()
{
	int n;
	do
	{
		cout << "Ingrese una cantidad: "; cin >> n;
		cout << endl;
	} while (n < 1);
	return n;
}

void GenerarDatos(int* vn, int n)
{
	for (int i = 0; i < n; i++)
	{
		vn[i] = rand() % 101;
	}
	cout << "*************************************" << endl;
	cout << "    Datos generados correctamente" << endl;
	cout << "*************************************" << endl;
	cout << endl;
}

void MostrarDatos(int* vn, int n)
{
	if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "[" << vn[i] << "] ";
		}
		cout << endl;
		cout << endl;
		cout << "*************************************" << endl;
		cout << "          Mostrando datos " << endl;
		cout << "*************************************" << endl;
		cout << endl;
	}
	else
		{
		cout << endl;
		cout << "Error al ingresar los datos ..";
		}
}

void OrdenarAscendente(int* vn, int n)
{
	int aux;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (vn[i] > vn[j])
			{
				aux = vn[i];
				vn[i] = vn[j];
				vn[j] = aux;
			}
		}
	}
	cout << endl;
	cout << "*************************************" << endl;
	cout << "   Datos ordenados ascendentemente " << endl;
	cout << "*************************************" << endl;
	cout << endl;
}

void BuscarDato(int* vn, int n)
{
	int dato;
	bool encontrado;
	cout << " Ingrese el numero a buscar: "; cin >> dato;
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		if (vn[i] == dato)
		{
			cout << " Encontrado!! " << endl;
			encontrado = true;
			break;
		}
	}

	if (encontrado == true)
	{
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			if (vn[i] == dato)
			{
				cout << " Posicion " << i + 1 << endl;
			}

		}
	}
	else
	{
		cout << endl;
		cout << " No encontrado!!" << endl;
	}
}

int main()
{
	srand(time(NULL));

	int n;
	int* vnumeros;
	int op;
	do
	{
		op = menu();
		switch (op)
		{
		case 1:
			n = IngresarCantidad();
			vnumeros = new int[n];
			GenerarDatos(vnumeros, n);
			break;
		case 2:
			MostrarDatos(vnumeros, n);
			break;
		case 3:
			OrdenarAscendente(vnumeros, n);
			break;
		case 4:
			BuscarDato(vnumeros, n);
			break;
		default:
			break;
		}
	} while (op != 5);

	return 0;
}