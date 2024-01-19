#include <iostream>
#include <string>

using namespace std;

// --- estructuras
struct Mascota {
    string codigo;   
    string nombre;
    string tipo;
    string raza;
    bool sexo;       // true: macho | false: hembra
};

struct Veterinario {
    string dni;
    string nombres;
    string apellidos;
    char   area;    // 'c': "cirugía" | 'f':"Fisioterapia" | 'o': "Oftalmólogo"
    int    sueldo;
};

struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Hora {
    int hora;
    int minutos;
};

struct Cita {
    string dniVeterinario;
    string codigoMascota;
    Fecha  fechaAtencion;
    Hora   horaAtencion;
};

struct Atencion {
    string dniVeterinario;
    string codigoMascota;
    Fecha  fechaCita;
    Hora   horaCita;
    string diagnostico;
    string medicamento;
};

        
// --- funciones auxiliares
int muestraMenu(string titulo, string items[], int tamano) {
    int seleccion = 0;

    do {
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "                                                === " << titulo << " ===" << endl;
        cout << endl;

        for (int indice = 0; indice < tamano; indice++) {
            cout << "                                             [" << indice + 1 << "] " << items[indice] << endl;
        }
        cout << endl;
        cout << "                                                 Seleccione una opcion: ";
        cin >> seleccion;

        system("cls");
    } while (seleccion < 1 || seleccion > tamano);

    return seleccion;
}

int diasMes(int mes) {
    int diasMeses[] = { 30, 28, 31, 30, 31, 30, 30, 31, 30, 31, 30, 31 };
    return diasMeses[mes];
}

string formatoFecha(Fecha valor) {
    return to_string(valor.dia) + "/" + 
            to_string(valor.mes) + "/" +
             to_string(valor.anio);
}

string formatoHora(Hora valor) {
    return to_string(valor.hora) + ":" +
        to_string(valor.minutos);
}

string espacios(string valor, int longitud) {
    if (longitud <= valor.size())
        return valor;

    int diferencia = longitud - valor.length();

    for (int indice = 0; indice < diferencia; indice++)
        valor += " ";

    return valor;
}

bool comparaFecha(Fecha fecha1, Fecha fecha2) {
    if (fecha1.dia != fecha2.dia)
        return false;

    if (fecha1.mes != fecha2.mes)
        return false;

    if (fecha1.anio != fecha2.anio)
        return false;

    return true;
}

bool comparaHora(Hora hora1, Hora hora2) {
    if (hora1.hora != hora2.hora)
        return false;

    if (hora1.minutos != hora2.minutos)
        return false;

    return true;
}

// --- menus
string menuPrincipal[] = {
    "Registrar mascota",
    "Registar veterinario",
    "Registrar cita",
    "Registrar atencion",
    "Reportes",
    "Salir"
};

// --- listas
Veterinario* listaVeterinarios = NULL;
int numVeterinarios = 0;

Mascota* listaMascotas = NULL;
int numMascotas = 0;

Cita* listaCitas = NULL;
int numCitas = 0;

Atencion* listaAtenciones = NULL;
int numAtenciones = 0;


// -- veterinario
void agregarVeterinario(Veterinario nuevo) {
    Veterinario* listaAuxilar = new Veterinario[numVeterinarios + 1];

    for (int indice = 0; indice < numVeterinarios; indice++) {
        listaAuxilar[indice] = listaVeterinarios[indice];
    }

    delete[] listaVeterinarios;

    numVeterinarios++;
    listaVeterinarios = listaAuxilar;

    listaVeterinarios[numVeterinarios - 1] = nuevo;
}

string areaVeterinario(char valor) {
    string resultado = "n/a";

    switch (tolower(valor)) {
    case 'o':
        resultado = "Oftalmologia";
        break;

    case 'f':
        resultado = "Fisioterapia";
        break;

    case 'c':
        resultado = "Cirugia";
        break;
    }

    return resultado;
}

void listarVeterinarios() {
    Veterinario veterinario;

    cout << "                *** LISTADO DE VETERINARIOS ***" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << "  DNI     NOMBRES       APELLIDOS        AREA        HONORARIOS" << endl;
    for (int indice = 0; indice < numVeterinarios; indice++) {
        veterinario = listaVeterinarios[indice];
        cout << veterinario.dni << "  ";
        cout << espacios(veterinario.nombres, 12) << " ";
        cout << espacios(veterinario.apellidos, 15) << "  ";
        cout << espacios(areaVeterinario(veterinario.area), 12) << "   ";
        cout << veterinario.sueldo << endl;
    }
    cout << "-------------------------------------------------------------------" << endl;
    cout << numVeterinarios << " registro(s)" << endl;
    cout << endl;
}

void listarVeterinariosxArea(char area) {
    Veterinario veterinario;

    for (int indice = 0; indice < numVeterinarios; indice++) {
        veterinario = listaVeterinarios[indice];
        if (veterinario.area == area) {
            cout << "Doctor Recomendado: " << endl;
            cout << veterinario.dni << " - " << "Dr. " << veterinario.nombres << " " << veterinario.apellidos << endl;
            cout << endl;
        }
    }
}

// -- mascotas
void agregarMascota(Mascota nuevo) {
    Mascota* listaAuxilar = new Mascota[numMascotas + 1];

    for (int indice = 0; indice < numMascotas; indice++) {
        listaAuxilar[indice] = listaMascotas[indice];
    }

    delete[] listaMascotas;

    numMascotas++;
    listaMascotas = listaAuxilar;

    listaMascotas[numMascotas - 1] = nuevo;
}

string sexoMascota(bool valor) {
    if (valor)
        return "Macho";
    else
        return "Hembra";
}


// -- citas
void agregarCita(Cita nueva) {
    Cita* listaAuxilar = new Cita[numCitas + 1];

    for (int indice = 0; indice < numCitas; indice++) {
        listaAuxilar[indice] = listaCitas[indice];
    }

    delete[] listaCitas;

    numCitas++;
    listaCitas = listaAuxilar;

    listaCitas[numCitas - 1] = nueva;
}

// -- atencion
void agregarAtencion(Atencion nueva) {
    Atencion* listaAuxiliar = new Atencion[numAtenciones + 1];

    for (int indice = 0; indice < numAtenciones; indice++) {
        listaAuxiliar[indice] = listaAtenciones[indice];
    }

    delete[] listaAtenciones;

    numAtenciones++;
    listaAtenciones = listaAuxiliar;

    listaAtenciones[numAtenciones - 1] = nueva;
}

void listarAtenciones() {
    Atencion atencion;

    cout << "                         *** LISTADO DE ATENCIONES ***" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << "   DNI      CODIGO      FECHA        HORA   DIGNOSTICO       MEDICAMENTO" << endl;

    for (int indice = 0; indice < numAtenciones; indice++) {
        atencion = listaAtenciones[indice];
        cout << atencion.dniVeterinario << "   ";
        cout << atencion.codigoMascota << "    ";
        cout << formatoFecha(atencion.fechaCita) << "    ";
        cout << formatoHora(atencion.horaCita) << "    ";
        cout << atencion.diagnostico << "          ";
        cout << atencion.medicamento << "  " << endl;
    }
    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << numAtenciones << " registro(s)" << endl;
    cout << endl;
}

// -- llenado de listas

void llenaListaMascotas() {
    Mascota registro;

    registro.codigo = "10000000";
    registro.nombre = "Chispitas";
    registro.tipo = "Perro";
    registro.raza = "Bulldog";
    registro.sexo = false;
    agregarMascota(registro);

    registro.codigo = "20000000";
    registro.nombre = "Cua Cua";
    registro.tipo = "Pato";
    registro.raza = "Silvestre";
    registro.sexo = true;
    agregarMascota(registro);

    registro.codigo = "30000000";
    registro.nombre = "Kali";
    registro.tipo = "Gato";
    registro.raza = "Siames";
    registro.sexo = true;
    agregarMascota(registro);

    /// muestraMascotas();
}


void llenaListaVeterinarios() {
    Veterinario registro;


    registro.dni = "00000001";
    registro.nombres = "Miguel";
    registro.apellidos = "Olivares";
    registro.sueldo = 2000;
    registro.area = 'c';
    agregarVeterinario(registro);

    registro.dni = "00000002";
    registro.nombres = "Piero";
    registro.apellidos = "Sanchez";
    registro.sueldo = 3000;
    registro.area = 'o';
    agregarVeterinario(registro);

    registro.dni = "00000003";
    registro.nombres = "Alexia";
    registro.apellidos = "Zarate";
    registro.sueldo = 2300;
    registro.area = 'f';
    agregarVeterinario(registro);

    registro.dni = "00000004";
    registro.nombres = "Camila";
    registro.apellidos = "Gonzalez";
    registro.sueldo = 2500;
    registro.area = 'f';
    agregarVeterinario(registro);

    /// muestraVeterinarios();
}

void listarMascotas() {
    Mascota mascota;

    cout << "               *** LISTADO DE MASCOTAS ***" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "  CODIGO       NOMBRE           TIPO          RAZA         SEXO" << endl;

    for (int indice = 0; indice < numMascotas; indice++) {
        mascota = listaMascotas[indice];
        cout << espacios(mascota.codigo, 6) << "     ";
        cout << espacios(mascota.nombre, 15) << "   ";
        cout << espacios(mascota.tipo, 10) << "    ";
        cout << espacios(mascota.raza, 10) << "   ";
        cout << sexoMascota(mascota.sexo) << endl;
    }
    cout << "------------------------------------------------------------------" << endl;
    cout << numMascotas << " registro(s)" << endl;
    cout << endl;
}


bool libreParaCita(Cita cita) {
    Cita aux;

    for (int indice = 0; indice < numCitas; indice++) {
        aux = listaCitas[indice];

        if (aux.dniVeterinario == cita.dniVeterinario) {
            if (comparaFecha(aux.fechaAtencion, cita.fechaAtencion)) {
                if (comparaHora(aux.horaAtencion, cita.horaAtencion)) {
                    return false;
                }
            }
        }
    }
    return true;
}

Veterinario* buscarVeterinario(string dni) {
    Veterinario* auxVeterinario = NULL;

    for (int indice = 0; indice < numVeterinarios; indice++) {
        auxVeterinario = &listaVeterinarios[indice];

        if (auxVeterinario->dni == dni) {
            return auxVeterinario;
        }
    }
    return NULL;
}

// --- menu-principal Opc (1)
void reservarCita() 
{
    char auxArea;
    string auxDNI;
    int auxDia, auxMes, auxAnio, auxHora, auxMinuto;
    string auxCodMascota;

    cout << ">> RESERVAR CITA " << endl;
    cout << endl;
    cout << endl;
    listarVeterinarios();
    cout << endl;
    do {
        cout << "Ingrese el area de especializacion (C: Cirugia, C: O: Oftalmologo,  F: Fisioterapia): "; cin >> auxArea;
    } while (auxArea != 'c' && auxArea != 'o' && auxArea != 'f');
    cout << endl;
    cout << "----------------------------------------" << endl;
    listarVeterinariosxArea(auxArea);
    cout << "----------------------------------------" << endl;
    do {
        cout << "Ingrese DNI del veterinario: "; cin >> auxDNI;
    } while (auxDNI.length() != 8);
    // --- fecha
    do {
        cout << "Ingrese mes                : "; cin >> auxMes;
    } while (auxMes < 1 || auxMes > 12);
    do {
        cout << "Ingrese dia                : "; cin >> auxDia;
    } while (auxDia < 1 || auxDia > 30);
    do {
        cout << "Ingrese anio               : "; cin >> auxAnio;
    } while (auxAnio < 2023 || auxAnio > 2025);
    // hora
    do {
        cout << "Ingrese hora               : "; cin >> auxHora;
    } while (auxHora < 0 || auxHora > 23);
    do {
        cout << "Ingrese minuto             : "; cin >> auxMinuto;
    } while (auxMinuto < 1 || auxMinuto > 59);

        cout << "Ingrese codigo de mascota  : "; cin >> auxCodMascota;

    Cita nuevaCita;

    nuevaCita.dniVeterinario = auxDNI;
    nuevaCita.fechaAtencion.dia = auxDia;
    nuevaCita.fechaAtencion.mes = auxMes;
    nuevaCita.fechaAtencion.anio = auxAnio;
    nuevaCita.horaAtencion.hora = auxHora;
    nuevaCita.horaAtencion.minutos = auxMinuto;
    nuevaCita.codigoMascota = auxCodMascota;

    if (libreParaCita(nuevaCita)) {
        agregarCita(nuevaCita);

        Veterinario* veterinario;

        veterinario = buscarVeterinario(auxDNI);

        cout << endl;
        cout << "*** Cita Reservada ***" << endl;
        cout << "DNI         : " << veterinario->dni << endl;
        cout << "Nombres     : " << veterinario->nombres << endl;
        cout << "Apellidos   : " << veterinario->apellidos << endl;
        cout << "Area        : " << areaVeterinario(veterinario->area) << endl;
        cout << "Cod Mascota : " << auxCodMascota << endl;
        cout << "Fecha       : " << formatoFecha(nuevaCita.fechaAtencion) << endl;
        cout << "Hora        : " << formatoHora(nuevaCita.horaAtencion) << endl;
        cout << "Honorario   : S/" << veterinario->sueldo << endl;
        cout << endl;

    }
    else {
        cout << endl;
        cout << "*** Horario no disponible ***" << endl;
    }

    system("pause");
}

void listarCitas() {
    Cita cita;

    cout << "         *** LISTADO DE CITAS ***" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "   DNI         CODIGO      FECHA         HORA" << endl;

    for (int indice = 0; indice < numCitas; indice++) {
        cita = listaCitas[indice];
        cout << cita.dniVeterinario << "      ";
        cout << cita.codigoMascota << "    ";
        cout << formatoFecha(cita.fechaAtencion) << "     ";
        cout << formatoHora(cita.horaAtencion) << endl;
    }
    cout << "-----------------------------------------------" << endl;
    cout << numCitas << " registro(s)" << endl;
    cout << endl;
}


// --- menu-principal 
void registrarAtencion() {
    Fecha fecha;
    Hora hora;
    string auxDniVeterinario;
    string auxCodigoMascota;
    string auxDiagnostico;
    string auxMedicamento;
    int auxDia, auxMes, auxAnio, auxHora, auxMinuto;

    cout << ">> REGISTRAR ATENCION" << endl;
    cout << endl;

    listarCitas();
    cout << endl;

    do {
        cout << "Ingrese DNI del veterinario : "; cin >> auxDniVeterinario;
    } while (auxDniVeterinario.length() != 8);
    // --- fecha
    do {
        cout << "Ingrese mes                 : "; cin >> auxMes;
    } while (auxMes < 0 || auxMes > 12);
    do {
        cout << "Ingrese dia                 : "; cin >> auxDia;
    } while (auxDia < 0 || auxDia > 30);
    do {
        cout << "Ingrese anio                : "; cin >> auxAnio;
    } while (auxAnio < 2023 || auxAnio > 2025);
    // hora
    do {
        cout << "Ingrese hora                : "; cin >> auxHora;
    } while (auxHora < 0 || auxHora > 23);
    do {
        cout << "Ingrese minuto              : "; cin >> auxMinuto;
    } while (auxMinuto < 0 || auxMinuto > 60);

    fecha.dia = auxDia;
    fecha.mes = auxMes;
    fecha.anio = auxAnio;

    hora.hora = auxHora;
    hora.minutos = auxMinuto;

    Cita auxCita;
    
    auxCita.dniVeterinario = auxDniVeterinario;
    auxCita.fechaAtencion = fecha;
    auxCita.horaAtencion = hora;

    if (libreParaCita(auxCita)) {
        cout << "*** No tuvo atencion en el horario indicado ***" << endl;
        cout << endl;
        system("pause");
        return;
    }

    cout << "Codigo Mascota              : "; cin >> auxCodigoMascota;
    cout << endl;
    auxCita.codigoMascota = auxCodigoMascota;
    cout << "----------------------------------------------------------";
    cout << endl;
    cout << "Diagnostico                 : "; cin >> auxDiagnostico; 
    cout << "Medicamento                 : "; cin >> auxMedicamento;

    Atencion atencion;

    atencion.dniVeterinario = auxDniVeterinario;
    atencion.codigoMascota = auxCodigoMascota;
    atencion.fechaCita.dia = auxDia;
    atencion.fechaCita.mes = auxMes;
    atencion.fechaCita.anio = auxAnio;
    atencion.horaCita.hora = auxHora;
    atencion.horaCita.minutos = auxMinuto;
    atencion.diagnostico = auxDiagnostico;
    atencion.medicamento = auxMedicamento;

    agregarAtencion(atencion);

    cout << endl;
    cout << ">> Atencion registrada " << endl;
    cout << endl,
    listarAtenciones();

    system("pause");

}

// --- menu-principal Opc (3)
void registrarMascota() {
    Mascota registro;

    cout << ">> REGISTRAR MASCOTA" << endl;
    cout << endl;

    listarMascotas();
    cout << endl;

    do {
        cout << "Codigo de la mascota      : "; cin >> registro.codigo;
    } while (registro.codigo.length() != 8);
    do {
        cout << "Nombre de la mascota      : "; cin >> registro.nombre;
    } while (registro.nombre.length() < 0 || registro.nombre.length() > 10);
    do {
        cout << "Tipo de animal            : "; cin >> registro.tipo;
    } while (registro.tipo.length() < 0 || registro.tipo.length() > 10);
    do {
        cout << "Raza                      : "; cin >> registro.raza;
    } while (registro.raza.length() < 0 || registro.raza.length() > 10);
    do {
        cout << "Sexo (1:Macho, 0:Hembra)  : "; cin >> registro.sexo;
    } while (registro.sexo != 1 && registro.sexo != 0);
    cout << endl;

    agregarMascota(registro);


    cout << "*** Mascota Registrada ***" << endl;
    cout << endl;
    system("pause");
}

// --- menu-principal Opc (4)
void registrarVeterinario() {
    Veterinario registro;

    cout << ">> REGISTRAR VETERINARIO" << endl;
    cout << endl;

    listarVeterinarios();
    cout << endl;

    do {
        cout << "DNI              : "; cin >> registro.dni;
    } while (registro.dni.length() != 8);
    do {
        cout << "Primer Nombre    : "; cin >> registro.nombres;
    } while (registro.nombres.length() < 0 || registro.nombres.length() > 10);
    do {
        cout << "Primer Apellido  : "; cin >> registro.apellidos;
    } while (registro.apellidos.length() < 0 || registro.apellidos.length() > 10);
    do {
        cout << "Area de especializacion (c: Cirugia,  o: Oftalmologo,  f: Fisioterapia): "; cin >> registro.area;
    } while (registro.area != 'c' && registro.area != 'o' && registro.area != 'f');
    do {
        cout << "Honorarios       : "; cin >> registro.sueldo;
    } while (registro.sueldo < 1000 || registro.sueldo > 10000);
    cout << endl;

    agregarVeterinario(registro);

    cout << ">> Registro exitoso (" << numVeterinarios << ") " << endl;
    system("pause");
}

// --- menu-principal Opc (5)
void reportes() {
    cout << endl;
    listarMascotas();
    cout << endl;
    cout << endl;
    listarVeterinarios();
    cout << endl;
    cout << endl;
    listarCitas();
    cout << endl;
    cout << endl;
    listarAtenciones();
    cout << endl;
    system("pause");
}

void pantallaPrincipal() {
    int seleccion = 0;

    while (true) {
        system("cls");
        seleccion = muestraMenu("MENU PRINCIPAL", menuPrincipal, 6);

        switch (seleccion) {
        case 1:
            registrarMascota();
            break;
        case 2:
            registrarVeterinario();
            break;
        case 3:
            reservarCita();
            break;
        case 4:
            registrarAtencion();
            break;
        case 5:
            reportes();
            break;
        case 6: // salir
            return;
        }
    }
}


int main() 
{
    llenaListaVeterinarios();
    llenaListaMascotas();

    pantallaPrincipal();

    return 0;
}

