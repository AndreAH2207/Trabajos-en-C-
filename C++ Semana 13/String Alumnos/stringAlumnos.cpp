#include <iostream>
#include <conio.h>
#include <string>
#include <time.h>
using namespace std;
using namespace System;
string nombresA[5] = { "Alan","Jose","Bruno","Maria","Ale" };
string apellidos[5] = { "Zambrano","Quispe","Barcos","Delgado","Sanchez" };
string nombresC[5] = { "Progra","Mate","Lengua","Recreo","Dibujo" };
struct Cursos {
	int  id_C;
	string nombre;
	int creditos;
	int disponible;
};
struct Alumnos {
	int id_A;
	string nombre;
	string Apellidos;
	Cursos registro;

};

int ingresarCant() {
	int n;
	do {
		cout << "Ingrese la cantidad: ";
		cin >> n;
	} while (n < 1);
	return n;
}

void generarDatos(Alumnos* va, Cursos* vc, int* n) {
	for (int i = 0; i < *n; i++)
	{
		va[i].nombre = nombresA[rand() % 5];
		va[i].Apellidos = apellidos[rand() % 5];
		va[i].id_A = i; // id no deben ser repetidos
	}
	for (int i = 0; i < 5; i++)
	{
		vc[i].nombre = nombresC[rand() % 5];
		vc[i].id_C = 2023 + i;
		vc[i].creditos = 1 + rand() % 5;
		vc[i].disponible = 1; // 1 esta disponible y 0 no disponible
	}
}
void mostrarDatos(Alumnos* va, Cursos* vc, int* n) {
	for (int i = 0; i < *n; i++)
	{
		cout << "[" << va[i].id_A << "]\t[" << va[i].Apellidos << "]\t[" << va[i].nombre << "]" << endl;
	}
	cout << "cursos Disponible" << endl;
	for (int i = 0; i < 5; i++)
	{
		//Console::SetCursorPosition(20, *n + 2+i);
		cout << "[" << vc[i].id_C << "]\t[" << vc[i].nombre << "]\t\t[" << vc[i].disponible << "]" << endl;
	}
}

void registrarCursos(Alumnos* va, Cursos* vc, int* n) {
	int idA, idC, posA = -1, posC = -1;
	cout << "Ingrese su codigo (ID): ";
	cin >> idA;
	for (int i = 0; i < *n; i++)
	{
		if (va[i].id_A == idA) {
			posA = i;
			break;
		}
	}
	if (posA != -1) {
		cout << "Bienvenido " << va[posA].nombre << endl;
		cout << "Ingrese el codigo del curso a registrar: " << endl;
		cin >> idC;
		for (int i = 0; i < 5; i++)
		{
			if (vc[i].id_C == idC && vc[i].disponible == 1) {
				posC = i;
				vc[i].disponible = 0;
				break;
			}
		}
		if (posC != -1) {
			cout << va[posA].nombre << " Ud se registro en el curso " << vc[posC].nombre << endl;
			//pasamos los datos para el regisro de curso dentro de cada Alumnos 
			va[posA].registro.nombre = vc[posC].nombre;
			va[posA].registro.creditos = vc[posC].creditos;
			va[posA].registro.disponible = vc[posC].disponible;
		}
		else
			cout << "Curso no disponible o error al ingresar el codigo" << endl;

	}
	else
		cout << "!!!!Error al ingresar el codigo del alumno" << endl;

}


void obtenerReporte(Alumnos* va, int* n) {
	for (int i = 0; i < *n; i++)
	{
		if (va[i].registro.disponible == 0) {
			cout << "[" << va[i].id_A << "]\t[" << va[i].Apellidos << "]\t[" << va[i].nombre << "]" << endl;
			cout << "         Curso Registrado -> [" << va[i].registro.nombre << "]" << endl;
		}
	}
}

int main() {
	srand(time(NULL));
	int* n = new int;
	*n = ingresarCant();
	char tecla;
	Alumnos* va = new Alumnos[*n];
	Cursos* vc = new Cursos[5];
	generarDatos(va, vc, n);
	mostrarDatos(va, vc, n);
	do {
		registrarCursos(va, vc, n);
		cout << "Desea registrar otro curso [S o N]: " << endl;
		tecla = toupper(getch());
		mostrarDatos(va, vc, n);
	} while (tecla != 'N');
	obtenerReporte(va, n);


	getch();
}