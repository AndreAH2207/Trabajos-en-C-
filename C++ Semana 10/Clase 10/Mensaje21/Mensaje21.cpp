#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;
int obtenerCant() {
	return 20 + rand() % 11;
}

void generarMensaje(char* vm, int n) {
	for (int i = 0; i < n; i++)
	{
		vm[i] = 65 + rand() % 26;      //65-90
	}
}
void imprimirMensaje(char* vm, int n) {
	for (int i = 0; i < n; i++)
	{
		cout << "[" << vm[i] << "]";
	}
	cout << endl;
}
bool obtenerMensajeConsecutivo(char* vm, int n) {
	bool encontrado = false; // false no se encontro mensaje consecutivo 
	for (int i = 0; i < n - 2; i++)
	{
		if (vm[i] == 'U' && vm[i + 1] == 'P' && vm[i + 2] == 'C') {
			encontrado = true;
			break;
		}
	}
	return encontrado;
}
bool obtenerMensajeAlterno(char* vm, int n) {
	bool encontrado = false;
	for (int i = 0; i < n - 4; i++)
	{
		if (vm[i] == 'I' && vm[i + 2] == 'S' && vm[i + 4] == 'I') {
			encontrado = true;
			break;
		}
	}
	return encontrado;
}

int main() {
	srand(time(NULL));
	int n;
	int cont = 1;
	bool consecutivo, alterno;
	//Solo debo declara el vector y se creará cuando N tome valor
	char* vmensaje;
	while (true) {
		n = obtenerCant();
		vmensaje = new char[n];
		generarMensaje(vmensaje, n);
		cout << "Mensaje " << cont << endl;
		imprimirMensaje(vmensaje, n);
		consecutivo = obtenerMensajeConsecutivo(vmensaje, n);
		if (consecutivo) {
			cout << "ES ALUMNOS UPC" << endl;
			cout << "Presione una tecla para continuar" << endl;
			getch();
		}
		alterno = obtenerMensajeAlterno(vmensaje, n);
		if (alterno) {
			cout << "ES ALUMNOS INGENIERIA DE SISTEMAS DE INFORMACION" << endl;
			cout << "Presione una tecla para continuar" << endl;
			getch();
		}
		cont++;
		//_sleep(100);
	}
	getch();
}