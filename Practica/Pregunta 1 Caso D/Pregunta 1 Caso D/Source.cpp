#include <iostream>
#include <string>

using namespace std;

struct Fecha
{
	int dia;
	int mes;
};

struct Asesor
{
	int DNI;
	string nombre;
	char condicion;
	Fecha fechaIngreso;
	char facultad;
};


struct Alumno
{
	long long codigo;
	string nombre;
	char carrera;
	float promedio;
};

int generarMenu(string Titulo, string Menu[], int tamano)
{
	int seleccion = 0;

	cout << "------" << Titulo << "-------" << endl;
	cout << endl;
	do
	{
		for (int i = 0; i < tamano; i++)
		{
			cout << " [" << i + 1 << "] " << Menu[i] << endl;
			
		}

		cout << endl;
		cout << "Seleccione una opcion: "; cin >> seleccion;
		system("cls");

	} while (seleccion < 1 || seleccion > tamano);
	return seleccion;
}

Asesor* listaAsesor = NULL;
int numAsesores = 0;

Alumno* listaAlumno = NULL;
int numAlumnos = 0;

void agregarAsesor(Asesor nuevo)
{
	Asesor* listaAux = new Asesor[numAsesores + 1];
	
	for (int i = 0; i < numAsesores; i++)
	{
		listaAux[i] = listaAsesor[i];
	}

	delete[] listaAsesor;

	numAsesores++;
	listaAsesor = listaAux;

	listaAsesor[numAsesores - 1] = nuevo;
}

void agregarAlumno(Alumno nuevo)
{
	Alumno* listaAux = new Alumno[numAlumnos + 1];

	for (int i = 0; i < numAlumnos; i++)
	{
		listaAux[i] = listaAlumno[i];
	}

	delete[] listaAlumno;

	numAlumnos++;
	listaAlumno = listaAux;

	listaAlumno[numAlumnos - 1] = nuevo;
}

void registrarAsesor()
{
	Asesor asesor;
	Fecha fecha;

	cout << ">> Registrando Asesor: " << endl;
	cout << endl;
	cout << endl;

	do
	{
		cout << "Ingrese numero de DNI: "; cin >> asesor.DNI;
	} while (asesor.DNI < 10000000 || asesor.DNI > 99999999);

	cout << endl;

	do
	{
		cout << "Ingrese nombre: "; cin >> asesor.nombre;
	} while (asesor.nombre.length() > 15);

	cout << endl;

	do
	{
		cout << "Ingrese la condicion (profesor tiempo completo (T), docente tiempo " << endl;
		cout <<	"completo(D), profesor tiempo parcial(P): "; cin >> asesor.condicion;

		asesor.condicion = toupper(asesor.condicion);

	} while (asesor.condicion != 'T' && asesor.condicion != 'D' && asesor.condicion != 'P');

	cout << endl;

	do
	{
		cout << "Ingrese la fecha de ingreso ->  Dia: "; cin >> asesor.fechaIngreso.dia;
	} while (asesor.fechaIngreso.dia < 1 || asesor.fechaIngreso.dia > 30);

	cout << endl;

	do
	{
		cout << "Ingrese la fecha de ingreso ->  Mes "; cin >> asesor.fechaIngreso.mes;
	} while (asesor.fechaIngreso.mes < 1 || asesor.fechaIngreso.mes > 12);

	cout << endl;

	do
	{
		cout << "Ingrese la facultad (Negocios (N), Ingenieria (I), " << endl;
		cout << "Comunicaciones(C), Economia(E), Arquitectura(A)) : "; cin >> asesor.facultad;

		asesor.facultad = toupper(asesor.facultad);

	} while (asesor.facultad != 'N' && asesor.facultad != 'I' && asesor.facultad != 'C'
		&& asesor.facultad != 'E' && asesor.facultad != 'A');

	agregarAsesor(asesor);
	cout << endl;

	cout << "**Asesor registrado**" << endl;

	system("pause");
}

void registrarAlumnos()
{
	Alumno alumno;

	cout << ">> Registrando Alumno: " << endl;
	cout << endl;
	cout << endl;

	do
	{
		cout << "Ingrese codigo de alumno: "; cin >> alumno.codigo;
	} while (alumno.codigo < 100000000 || alumno.codigo > 999999999);
	
	cout << endl;

	do
	{
		cout << "Ingrese el nombre: "; cin >> alumno.nombre;
	} while (alumno.nombre.length() > 15);

	cout << endl;

	do
	{
		cout << "Ingrese la carrera (Negocios Internacionales (N), IngenierIa Civil(C)," << endl;
		cout << "Comunicacion y Fotografia(F), Economia y Finanzas(E), Arquitectura(A): " ; cin >> alumno.carrera;

		alumno.carrera = toupper(alumno.carrera);

	} while (alumno.carrera != 'N' && alumno.carrera != 'C' && alumno.carrera != 'F' &&
			alumno.carrera != 'E' && alumno.carrera != 'A');

	cout << endl;

	do
	{
		cout << "Ingrese el promedio: "; cin >> alumno.promedio;
	} while (alumno.promedio < 0 || alumno.promedio > 20);

	cout << endl;
	agregarAlumno(alumno);

	cout << "**Alumno registrado**" << endl;

	system("pause");
}

void mostrarAsesor()
{
	Asesor asesor;
	
	cout << "  DNI\t\tNombre\t\tCondicion\tFecha de ingreso\tFacultad" << endl;
	cout << "---------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < numAsesores; i++)
	{
		asesor = listaAsesor[i];
		cout << asesor.DNI << "\t";
		cout << asesor.nombre << "\t\t  ";
		cout << asesor.condicion << "\t\t  ";
		cout << asesor.fechaIngreso.dia << asesor.fechaIngreso.mes << "\t\t\t";
		cout << asesor.facultad << endl;
	}
	cout << "---------------------------------------------------------------------------------" << endl;

	cout << endl;
	cout << endl;
}

void mostrarAlumno()
{
	Alumno alumno;

	cout << "Codigo\t\tNombre\t\tCarrera\t\tPromedio" << endl;
	cout << "---------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < numAlumnos; i++)
	{
		alumno = listaAlumno[i];
		cout << alumno.codigo << "\t\t";
		cout << alumno.nombre << "\t\t";
		cout << alumno.carrera << "\t\t";
		cout << alumno.promedio << "\t\t" << endl;
	}
	cout << "---------------------------------------------------------------------------------" << endl;

	cout << endl;
	cout << endl;
}

void mostrarNumeroAsesores()
{
	Asesor asesor;
	
	int contN = 0;
	int contI = 0;
	int contC = 0;
	int contE = 0;
	int contA = 0;

	for (int i = 0; i < numAsesores; i++)
	{
		asesor = listaAsesor[i];
;
		if (asesor.facultad == 'N')
		{
			contN++;
		}
		if (asesor.facultad == 'I')
		{
			contI++;
		}
		if (asesor.facultad == 'C')
		{
			contC++;
		}
		if (asesor.facultad == 'E')
		{
			contE++;
		}
		if (asesor.facultad == 'A')
		{
			contA++;
		}
	}
	cout << "El numero de asesores de la facultad de Negocios es         : " << contN << endl;
	cout << "El numero de asesores de la facultad de Ingenieria es       : " << contI << endl;
	cout << "El numero de asesores de la facultad de Comunicaciones es   : " << contC << endl;
	cout << "El numero de asesores de la facultad de Economia es         : " << contE << endl;
	cout << "El numero de asesores de la facultad de Arquitectura es     : " << contA << endl;
	cout << endl;
}

void asesoresIngresadosTrimestral()
{
	Asesor asesor;

	asesor = listaAsesor[0];

	int primerMesAsesor = asesor.fechaIngreso.mes;

	for (int i = 0; i < numAsesores; i++)
	{
		asesor = listaAsesor[i];

		if (asesor.condicion == 'P' && asesor.fechaIngreso.mes - primerMesAsesor <= 3)
		{
			cout << "  DNI\t\tNombre\t\tCondicion\tFecha de ingreso\tFacultad" << endl;
			cout << "---------------------------------------------------------------------------------" << endl;
				cout << asesor.DNI << "\t";
				cout << asesor.nombre << "\t\t  ";
				cout << asesor.condicion << "\t\t  ";
				cout << asesor.fechaIngreso.dia << asesor.fechaIngreso.mes << "\t\t\t";
				cout << asesor.facultad << endl;
			cout << "---------------------------------------------------------------------------------" << endl;
		}
	}
}

void ordenarDescendentemente()
{

	int auxDNI;
	string auxNombre;
	char auxCondicion;
	Fecha auxFecha;
	char auxFacultad;

	for (int i = 0; i < numAsesores; i++)
	{
		for (int j = i + 1; j < numAsesores; j++)
		{
			if (listaAsesor[i].condicion > listaAsesor[j].condicion)
			{
				auxDNI = listaAsesor[i].DNI;
				listaAsesor[i].DNI = listaAsesor[j].DNI;
				listaAsesor[j].DNI = auxDNI;

				auxNombre = listaAsesor[i].nombre;
				listaAsesor[i].nombre = listaAsesor[j].nombre;
				listaAsesor[j].nombre = auxNombre;

				auxCondicion = listaAsesor[i].condicion;
				listaAsesor[i].condicion = listaAsesor[j].condicion;
				listaAsesor[j].condicion = auxCondicion;

				auxFecha = listaAsesor[i].fechaIngreso;
				listaAsesor[i].fechaIngreso = listaAsesor[j].fechaIngreso;
				listaAsesor[j].fechaIngreso = auxFecha;

				auxFacultad = listaAsesor[i].facultad;
				listaAsesor[i].facultad = listaAsesor[j].facultad;
				listaAsesor[j].facultad = auxFacultad;
			
			}
		}

	}

}


string MenuPrincipal[] = {
	"Registrar",
	"Reportes",
	"Fin"
};

string MenuRegistrar[] = {
	"Registrar asesor",
	"Registrar alumno",
	"Mostrar registros",
	"Fin"
};

string MenuReportes[] = {
	"Mostrar el numero de asesores por cada facultad",
	"Mostrar los datos de los asesores que ingresaron en los ultimos tres meses",
	"Mostrar a los asesores ordenados descendentemente",
	"Fin",
};

void Menu()
{
	int principal = 0;
	int registrar = 0;
	int reportes = 0;

	while (true) 
	{

		system("cls");
		principal = generarMenu("Menu Principal", MenuPrincipal, 3);

		switch (principal)
		{
		case 1:
			do {
				{
					registrar = generarMenu("Menu Registrar", MenuRegistrar, 4);
					switch (registrar)
					{
					case 1:
					{
						registrarAsesor(); system("cls"); break;
					}
					case 2:
					{
						registrarAlumnos(); system("cls"); break;
					}
					case 3:
					{
						mostrarAlumno(); mostrarAsesor(); system("pause"); system("cls"); break;
					}
					case 4: break;
					default:
						break;
					}
				}
			} while (registrar != 4);
			break;

		case 2:
			do
			{
				reportes = generarMenu("Menu Reportes", MenuReportes, 4);
				switch (reportes)
				{
				case 1:
				{
					mostrarNumeroAsesores(); system("pause"); system("cls"); break;
				}

				case 2:
				{
					asesoresIngresadosTrimestral();  system("pause"); system("cls"); break;
				}
				
				case 3:
				{
					ordenarDescendentemente(); mostrarAsesor();  system("pause"); system("cls"); break;
				}

				case 4: break;
				default:
					break;
				}
			} while (reportes != 4);

		case 3:
			break;
		default:
			break;
		} 
	}
}



int main()
{
	Menu();

	return 0;
}
