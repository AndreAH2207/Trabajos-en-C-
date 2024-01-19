#include <iostream>
using namespace std;

class Menu {
public:
	int menu() {
		int op;
		do {
			cout << "[1] Registrar Auto" << endl;
			cout << "[2] Listar Autos" << endl;
			cout << "[3] Eliminar Auto" << endl;
			cout << "[4] Actualizar" << endl;
			cout << "[5] Listar Sort Autos con Precio Final" << endl;
			cout << "[6] Salir" << endl;
			cout << "Ingrese una opcion: ";
			cin >> op;
		} while (op < 0 || op>6);
		return op;
	}
};