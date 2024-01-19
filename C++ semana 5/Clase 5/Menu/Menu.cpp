#include <iostream>
#include <conio.h>

using namespace std;

int menu()
{
	int op;
	do
	{
		cout << endl;
		cout << "     [MENU]";
		cout << endl;
		cout << "[1] Suma " << endl;
		cout << "[2] Resta " << endl;
		cout << "[3] Multiplicacion " << endl;
		cout << "[4] Division " << endl;
		cout << "[5] Salir " << endl;
		cout << endl;
		cout << "Ingrese una opcion: "; cin >> op;
		system("cls");
	} while (op < 1 || op > 5);
	return op;
}

float IngresarNum(string mensaje)
{
	float n;
	cout << mensaje; cin >> n;
	return n;
}


int main()
{
	int opcion;
	float num1, num2, respuesta;

	do
	{
		opcion = menu();
		if (opcion != 5)
		{
			num1 = IngresarNum("Ingrese un numero: ");
			num2 = IngresarNum("Ingrese otro numero: ");
			
			switch (opcion)
			{
			case 1:
				cout << "La suma es: " << num1 + num2 << endl; 
				break;
			case 2:
				cout << "La resta es: " << num1 - num2 << endl;
				break;
			case 3:
				cout << "La multiplicacion es: " << num1 * num2 << endl;
				break;
			case 4:
				if (num2 != 0)
				{
					cout << "La division es: " << num1 / num2 << endl;
				}
				else
					cout << "Error" << endl;
				break;
			case 5:
				break;
			default:
				break;
			}
		}
	} while (opcion != 5);

	cout << "Fin del programa";


	_getch();
	return 0;
}