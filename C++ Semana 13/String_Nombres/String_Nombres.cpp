#include <iostream>
#include <conio.h>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;
string nombres[5] = { "Alan","Jose","Bruno","Maria","Ale" };
string apellidos[5] = { "Zambrano","Quispe","Barcos","Delgado","Sanchez" };
int ingresarCant() {
	int n;
	do {
		cout << "Ingrese la cantidad: ";
		cin >> n;
	} while (n < 1);
	return n;
}

void generarDatos(string* vn, int* n) {
	for (int i = 0; i < *n; i++)
	{
		vn[i] = nombres[rand() % 5] + " " + apellidos[rand() % 5];
	}
}
void mostrarDatos(string* vn, int* n) {
	for (int i = 0; i < *n; i++)
	{
		cout << vn[i] << endl;
	}
}

void buscarNombre(string* vn, int* n) {
	string name, nombre;
	int cont = 0;
	bool encontrado = false;
	cin.get();//captura el enter antes de un string usando getline
	cout << "Ingrese un nombre a buscar: ";
	getline(cin, name);
	for (int i = 0; i < *n; i++)
	{
		nombre = vn[i];
		if (name.length() == nombre.length()) {

			for (int j = 0; j < name.length(); j++)
			{
				if (toupper(name[j]) == toupper(nombre[j]))
					cont++;
			}
			if (cont == name.length()) {
				cout << "Encontrado en posicion " << i + 1 << endl;
				encontrado = true;
			}
			cont = 0;
		}

	}
	if (encontrado == false)
		cout << "No encontrado" << endl;


}

string* insertarAlFinal(string* vn, int* n) {
	//crear un vector auxiliar de tamaño n+1

	string* vaux = new string[*n + 1];
	string name;
	cout << "Ingrese un nombre a insertar al final del registro: ";
	getline(cin, name);
	for (int i = 0; i < *n; i++)
	{
		vaux[i] = vn[i];
	}

	//Guardamos el nombre en la ultima posicion del vector aux
	vaux[*n] = name;
	//Hacer crecer el valor de N en 1
	*n = *n + 1;
	return vaux;


}

int main() {
	srand(time(NULL));
	int* n = new int;
	*n = ingresarCant();
	string* vnombres;
	vnombres = new string[*n];
	generarDatos(vnombres, n);
	mostrarDatos(vnombres, n);
	buscarNombre(vnombres, n);
	vnombres = insertarAlFinal(vnombres, n);
	cout << "Datos actualizados" << endl;
	mostrarDatos(vnombres, n);
	vnombres = insertarAlFinal(vnombres, n);
	cout << "Datos actualizados" << endl;
	mostrarDatos(vnombres, n);

	getch();
}