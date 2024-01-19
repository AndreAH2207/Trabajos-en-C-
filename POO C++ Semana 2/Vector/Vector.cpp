#include <iostream>
#include <vector>
#include <conio.h>
#include <algorithm>

using namespace std;
using namespace System;

bool funcion_comparar(int a, int b)
{
	return (a > b);
}

int main()
{
	vector<int> notas;
	notas.insert(notas.begin(), 15);
	notas.insert(notas.begin(), 14);
	notas.insert(notas.begin(), 13);
	notas.insert(notas.begin(), 19);
	notas.insert(notas.begin(), 18);
	notas.insert(notas.begin(), 17);
	notas.insert(notas.begin(), 14);
	notas.insert(notas.begin(), 15);

	cout << "===NOTAS DE ALUMNOS X===" << endl;
	for (int i = 0; i < notas.size(); i++)
	{
		cout << notas[i] << " ";
	}
	cout << endl;

	sort(notas.begin(), notas.end(), funcion_comparar);
	cout << endl;
	cout << "===ORDENADO DE MAYOR A MENOR===" << endl;
	for (int i = 0; i < notas.size(); i++)
	{
		cout << notas[i] << " ";
	}
	cout << endl;

	notas.erase(notas.begin());
	cout << endl;
	cout << "===BORRAR PRIMER ELEMENTO===" << endl;
	for (int i = 0; i < notas.size(); i++)
	{
		cout << notas[i] << " ";
	}

	getch();
	return 0;
}