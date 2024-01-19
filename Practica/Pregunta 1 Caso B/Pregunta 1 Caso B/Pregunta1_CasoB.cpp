#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

struct Fecha
{
	int dia;
	int mes;
};

struct Proyecto
{
	int codigoProyecto;
	string nombre;
	char tipo;
	Fecha fechaIniProyecto;
	char distrito;
};

struct Tarea
{
	int codigoTarea;
	string descripcion;
	float costo;
};

Proyecto* listaProyectos = NULL;
int numProyectos = 0;

Tarea* listaTareas = NULL;
int numTareas = 0;

int generarMenu(string titulo, string contenido[], int tamano)
{
	int seleccion = 0;

	do
	{
		for (int i = 0; i < tamano; i++)
		{
			cout << " [" << i + 1 << "] " << contenido[i] << endl;
		}

		cout << endl;
		cout << " Seleccione una opcion: "; cin >> seleccion;

		system("cls");

	} while (seleccion < 1 || seleccion > tamano);

	return seleccion;
}

void agregarProyecto(Proyecto nuevo)
{
	Proyecto* listaAuxiliar = new Proyecto[numProyectos + 1];
	for (int i = 0; i < numProyectos; i++)
	{
		listaAuxiliar[i] = listaProyectos[i];
	}

	delete[]listaProyectos;

	numProyectos++;
	listaProyectos = listaAuxiliar;

	listaProyectos[numProyectos - 1] = nuevo;
}


void registrarProyectos()
{
	Proyecto registro;
	Fecha fecha;

	cout << "**REGISTRA PROYECTOS**" << endl;
	cout << endl;
	cout << endl;
	do
	{
		cout << "Ingrese el codigo del proyecto (5 digitos): "; cin >> registro.codigoProyecto;
	} while (registro.codigoProyecto < 10000 || registro.codigoProyecto > 99999);

	cout << endl;

	do
	{
		cout << "Ingrese el nombre del proyecto: "; cin >> registro.nombre;
	} while (registro.nombre.length() > 30 || registro.nombre.length() < 1);

	cout << endl;

	do
	{
		cout << "Ingrese el tipo de proyecto (Software (S), Comunicaciones y redes (R))" << endl;
		cout << "Seguridad(G), Auditoria(A), Consultoria(C)): "; cin >> registro.tipo;

		registro.tipo = toupper(registro.tipo);

	} while (registro.tipo != 'S' && registro.tipo != 'R' && registro.tipo != 'G' &&
		registro.tipo != 'A' && registro.tipo != 'C');

	cout << endl;

	do
	{
		cout << "Ingrese la fecha de inicio del proyecto: " << endl;
		cout << "Dia: "; cin >> registro.fechaIniProyecto.dia;
		cout << "Mes: "; cin >> registro.fechaIniProyecto.mes;

	} while (registro.fechaIniProyecto.dia < 1 || registro.fechaIniProyecto.dia > 30
		|| registro.fechaIniProyecto.mes < 1 || registro.fechaIniProyecto.mes > 12);

	cout << endl;

	do
	{
		cout << "Ingrese el distrito del proyecto (Surco (S), Miraflores (M)," << endl;
		cout << " San Miguel (G), Magdalena(D), Cercado de Lima(L)) : "; cin >> registro.distrito;

		registro.distrito = toupper(registro.distrito);

	} while (registro.distrito != 'S' && registro.distrito != 'M' && registro.distrito != 'G'
		&& registro.distrito != 'D' && registro.distrito != 'L');

	cout << endl;

	agregarProyecto(registro);

	cout << endl;
	cout << "**REGISTRO EXITOSO**" << endl;
	cout << endl;

	system("pause");
}



void mostrarProyectos()
{
	Proyecto proyecto;

	cout << "-----------------------MOSTRANDO PROYECTOS----------------------------" << endl;
	cout << endl;
	cout << "  CODIGO\tNOMBRE\t\tTIPO\t\tFECHA\t\tDISTRITO " << endl;
	cout << "----------------------------------------------------------------------" << endl;

	for (int i = 0; i < numProyectos; i++)
	{
		proyecto = listaProyectos[i];
		cout << "  " << proyecto.codigoProyecto << "\t\t";
		cout << proyecto.nombre << "\t\t";
		cout << proyecto.tipo << "\t\t";
		cout << proyecto.fechaIniProyecto.dia << proyecto.fechaIniProyecto.mes << "\t\t";
		cout << proyecto.distrito << endl;;
	}
	cout << "----------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "    " << numProyectos << " registro(s)" << endl;
	cout << endl;

}


void agregarTarea(Tarea nuevo)
{
	Tarea* listaAuxiliar = new Tarea[numTareas + 1];
	for (int i = 0; i < numTareas; i++)
	{
		listaAuxiliar[i] = listaTareas[i];
	}

	delete[] listaTareas;

	numTareas++;
	listaTareas = listaAuxiliar;
	listaTareas[numTareas - 1] = nuevo;
}


void registrarTareas()
{
	Tarea registro;

	cout << "**REGISTRA TAREAS**" << endl;
	cout << endl;
	cout << endl;
	do
	{
		cout << "Ingrese el codigo de la tarea (100-800): "; cin >> registro.codigoTarea;
	} while (registro.codigoTarea < 100 || registro.codigoTarea > 800);

	cout << endl;

	do
	{
		cout << "Ingrese la descripcion (espacio = _ ): "; cin >> registro.descripcion;
	} while (registro.descripcion.length() > 30 || registro.descripcion.length() < 1);

	cout << endl;

	do
	{
		cout << "Ingrese el costo de la tarea: "; cin >> registro.costo;
	} while (registro.costo < 0);

	cout << endl;

	agregarTarea(registro);

	cout << endl;
	cout << "**REGISTRO EXITOSO**" << endl;
	cout << endl;

	system("pause");
}


void mostrarTareas()
{
	Tarea tarea;

	cout << "--------------------------MOSTRANDO TAREAS----------------------------" << endl;
	cout << endl;
	cout << "  CODIGO\tDESCRIPCION\t\tCOSTO" << endl;
	cout << "----------------------------------------------------------------------" << endl;

	for (int i = 0; i < numTareas; i++)
	{
		tarea = listaTareas[i];

		cout << "   " << tarea.codigoTarea << "\t\t";
		cout << tarea.descripcion << "\t\t     ";
		cout << tarea.costo << " soles" << endl;
	}
	cout << "----------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "    " << numTareas << " registro(s)" << endl;
	cout << endl;

}

void proyectosXDistrito()
{
	Proyecto proyecto;

	int contS = 0;
	int contM = 0;
	int contG = 0;
	int contD = 0;
	int contL = 0;

	for (int i = 0; i < numProyectos; i++)
	{
		proyecto = listaProyectos[i];

		if (proyecto.distrito == 'S')
		{
			contS++;
		}

		if (proyecto.distrito == 'M')
		{
			contM++;
		}

		if (proyecto.distrito == 'G')
		{
			contG++;
		}

		if (proyecto.distrito == 'D')
		{
			contD++;
		}

		if (proyecto.distrito == 'L')
		{
			contL++;
		}
	}

	cout << "Cantidad de proyectos en Surco            : " << contS << endl;
	cout << "Cantidad de proyectos en Miraflores       : " << contM << endl;
	cout << "Cantidad de proyectos en San Miguel       : " << contG << endl;
	cout << "Cantidad de proyectos en Magdalena        : " << contD << endl;
	cout << "Cantidad de proyectos en Cercado de Lima  : " << contL << endl;

}

void datosSoftwareBimestral()
{
	Proyecto proyecto;

	proyecto = listaProyectos[0];
	
	int primerMesProyecto = proyecto.fechaIniProyecto.mes;
	
	for (int i = 0; i < numProyectos; i++)
	{
		proyecto = listaProyectos[i];

		if (proyecto.tipo == 'S' && proyecto.fechaIniProyecto.mes - primerMesProyecto <= 2)
		{
			cout << "-----------------------------------" << endl;
			cout << "Codigo: " << proyecto.codigoProyecto << endl;	
			cout << "Nombre: " << proyecto.nombre << endl;
			cout << "Tipo: " << proyecto.tipo << endl;
			cout << "Fecha de inicio: " << proyecto.fechaIniProyecto.dia << proyecto.fechaIniProyecto.mes << endl;
			cout << "Distrito: " << proyecto.distrito << endl;
			cout << "-----------------------------------" << endl;
		}
	}
}

void ordenarDescendentemente()
{
	Proyecto proyecto;

	int auxC;
	string auxN;
	char auxT;
	Fecha auxF;
	char auxD;

	for (int i = 0; i < numProyectos; i++)
	{
		for (int j = i + 1; j < numProyectos; j++)
		{
			if (listaProyectos[i].distrito > listaProyectos[j].distrito)
			{
				auxC = listaProyectos[i].codigoProyecto;
				listaProyectos[i].codigoProyecto = listaProyectos[j].codigoProyecto;
				listaProyectos[j].codigoProyecto = auxC;

				auxN = listaProyectos[i].nombre;
				listaProyectos[i].nombre = listaProyectos[j].nombre;
				listaProyectos[j].nombre = auxN;

				auxT = listaProyectos[i].tipo;
				listaProyectos[i].tipo = listaProyectos[j].tipo;
				listaProyectos[j].tipo = auxT;

				auxF = listaProyectos[i].fechaIniProyecto;
				listaProyectos[i].fechaIniProyecto = listaProyectos[j].fechaIniProyecto;
				listaProyectos[j].fechaIniProyecto = auxF;

				auxD = listaProyectos[i].distrito;
				listaProyectos[i].distrito = listaProyectos[j].distrito;
				listaProyectos[j].distrito = auxD;
			}
		}
	}
}


string menuPrincipal[] = {
	"Registrar",
	"Reportes" ,
	"Fin"
};

string menuRegistrar[] = {
	"Registrar proyecto",
	"Registrar tarea" ,
	"Ver registros",
	"Fin"
};


string menuReportes[] = {
	"Mostrar numero de proyectos por distrito",
	"Mostrar los datos de los proyectos de software que se han iniciado en los ultimos dos meses",
	"Mostrar un reporte de los proyectos ordenados descendentemente por el distrito",
	"Fin"
};


void Menu()
{
	int principal = 0;
	int registrar = 0;
	int reportes = 0;

	while (true)
	{
		system("cls");
		principal = generarMenu("MENU PRINCIPAL", menuPrincipal, 3);
		switch (principal)
		{
		case 1:
			do
			{
				registrar = generarMenu("MENU REGISTRAR", menuRegistrar, 4);
				switch (registrar)
				{
				case 1:
					registrarProyectos();
					system("cls");
					break;
				case 2:
					registrarTareas();
					system("cls");
					break;
				case 3:
					mostrarProyectos();
					mostrarTareas();

					system("pause");
					system("cls");
					break;
				case 4:
					break;
				default:
					break;
				}
			} while (registrar != 4);
			break;

		case 2:
			do 
			{
				reportes = generarMenu("MENU REPORTES", menuReportes, 4);
				switch (reportes)
				{
				case 1:
					proyectosXDistrito();
					cout << endl;
					system("pause");
					system("cls");
					break;
				case 2:
					datosSoftwareBimestral();
					system("pause");
					system("cls");
					break;
				case 3:
					ordenarDescendentemente();
					mostrarProyectos();
					cout << endl;
					system("pause");
					system("cls");
					break;
				case 4:
					break;
				default:
					break;
				}
			} while (reportes != 4);

		case 3:
			break;		
		}
	}
}

int main()
{
	Menu();

	getch();
	return 0;
}