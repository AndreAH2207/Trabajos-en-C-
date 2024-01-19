#include <iostream>

using namespace std;

#define COL 10
#define FIL 10



void generarMatriz(char** matriz)
{
	for (int i = 0; i < FIL; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			matriz[i][j] = 65 + rand() % 25;
		}
	}
}

void mostrarMatriz(char** matriz)
{
	for (int i = 0; i < FIL; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
}



void cantidad_veces(char** matriz, char consonante)
{
	int cont1 = 0;
	int cont2 = 0;
	int cont3= 0;

	for (int i = 0; i < FIL; i++)
	{
		for (int j = 0; j < COL - 4; j++)
		{
			if (matriz[i][j] == consonante)
			{
				cout << matriz[i][j] << matriz[i][j + 1] << matriz[i][j + 2];
			}
		}
	}

	cout << "La cantidad de veces que aparece " << consonante << " es"
			<< cont1 << " veces" << endl;
}


int main()
{
	srand(time(NULL));

	char** matriz = new char*[FIL];


	for (int i = 0; i < COL; i++)
	{
		matriz[i] = new char[COL];
	}

	generarMatriz(matriz);
	mostrarMatriz(matriz);
	cout << endl;

	char consonante;
	
	do {
		cout << "Ingrese una consonante: "; cin >> consonante;
		consonante = toupper(consonante);
	} while(consonante == 'A' && consonante == 'E' &&
			consonante == 'I'&& consonante == 'O'
			&& consonante == 'U');

	cantidad_veces(matriz, consonante);
	system("pause");
	return 0;
}
