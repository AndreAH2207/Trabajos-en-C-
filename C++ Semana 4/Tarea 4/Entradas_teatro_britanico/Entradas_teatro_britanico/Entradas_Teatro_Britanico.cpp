#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Variables para almacenar los datos recopilados
    int gamerCount = 0;
    int gamerAgeCount = 0;
    int academicWorkAgeSum = 0;
    int academicWorkCount = 0;
    vector<int> accessTimeCount(24, 0);
    int emotionalQueryMinAge = -1;

    // Bucle para recopilar los datos de acceso
    while (true) {
        char userType;
        cout << "Ingrese tipo de usuario (G: Gamer; E: Estudiante; P: Profesional): ";
        cin >> userType;
        userType = toupper(userType);
        if (userType != 'G' && userType != 'E' && userType != 'P') {
            cout << "Tipo de usuario inv�lido. Intente nuevamente." << endl;
            continue;
        }

        int age;
        cout << "Edad de usuario: ";
        cin >> age;
        if (age <= 10) {
            cout << "Edad inv�lida. Intente nuevamente." << endl;
            continue;
        }

        int accessHour;
        cout << "Hora de acceso (0-23): ";
        cin >> accessHour;
        if (accessHour < 0 || accessHour > 23) {
            cout << "Hora de acceso inv�lida. Intente nuevamente." << endl;
            continue;
        }

        char queryType;
        cout << "Tipo de consulta (E: Emocional; A: Acad�mico; D: Diversi�n; T: Trabajo): ";
        cin >> queryType;
        queryType = toupper(queryType);
        if (queryType != 'E' && queryType != 'A' && queryType != 'D' && queryType != 'T') {
            cout << "Tipo de consulta inv�lido. Intente nuevamente." << endl;
            continue;
        }

        // Estad�sticas por tipo de usuario
        if (userType == 'G') {
            gamerCount++;
            if (age >= 18 && age <= 25) {
                gamerAgeCount++;
            }
        }

        // Estad�sticas por tipo de consulta
        if (queryType == 'A' || queryType == 'T') {
            academicWorkAgeSum += age;
            academicWorkCount++;
        }

        // Estad�sticas por hora de acceso
        accessTimeCount[accessHour]++;

        // Usuario de menor edad con consulta emocional
        if (queryType == 'E' && (emotionalQueryMinAge == -1 || age < emotionalQueryMinAge)) {
            emotionalQueryMinAge = age;
        }

        // Finalizar el bucle si el usuario ingresa 'H'
        if (userType == 'H') {
            break;
        }
    }

    // C�lculo de las estad�sticas finales
    int totalUsers = gamerCount + academicWorkCount;
    float gamerAgePercentage = (static_cast<float>(gamerAgeCount) / gamerCount) * 100.0f;
    float academicWorkAgeAvg = (academicWorkCount > 0) ? static_cast<float>(academicWorkAgeSum) / academicWorkCount : 0.0f;

    int maxAccessTimeCount = 0;
    vector<string> mostCommonAccessTimes;
    vector<string> accessTimeLabels = { "MADRUGADA", "MA�ANA", "TARDE", "NOCHE" };

    // Encontrar el n�mero m�ximo de accesos por hora
    for (int count : accessTimeCount) {
        if (count > maxAccessTimeCount) {
            maxAccessTimeCount = count;
        }
    }

    // Encontrar los momentos m�s comunes de acceso
    for (int i = 0; i < accessTimeCount.size(); i++) {
        if (accessTimeCount[i] == maxAccessTimeCount) {
            mostCommonAccessTimes.push_back(accessTimeLabels[i]);
        }
    }

    // Impresi�n de resultados
    cout << "\nRESULTADOS\n" << endl;
    cout << "Porcentaje de Gamers cuya edad oscila entre los 18 y 25 a�os: " << gamerAgePercentage << endl;
    cout << "Edad promedio de usuarios que realizan una consulta del tipo acad�mico o de trabajo: " << academicWorkAgeAvg << endl;

    cout << "\nMomento o momentos del d�a en que se realizan m�s accesos:" << endl;
    for (string time : mostCommonAccessTimes) {
        cout << time << endl;
    }

    if (emotionalQueryMinAge != -1) {
        cout << "\nUsuario de menor edad que realiza una consulta del tipo emocional: NO HUBO" << endl;
    }

    return 0;
}