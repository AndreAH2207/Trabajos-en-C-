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
            cout << "Tipo de usuario inválido. Intente nuevamente." << endl;
            continue;
        }

        int age;
        cout << "Edad de usuario: ";
        cin >> age;
        if (age <= 10) {
            cout << "Edad inválida. Intente nuevamente." << endl;
            continue;
        }

        int accessHour;
        cout << "Hora de acceso (0-23): ";
        cin >> accessHour;
        if (accessHour < 0 || accessHour > 23) {
            cout << "Hora de acceso inválida. Intente nuevamente." << endl;
            continue;
        }

        char queryType;
        cout << "Tipo de consulta (E: Emocional; A: Académico; D: Diversión; T: Trabajo): ";
        cin >> queryType;
        queryType = toupper(queryType);
        if (queryType != 'E' && queryType != 'A' && queryType != 'D' && queryType != 'T') {
            cout << "Tipo de consulta inválido. Intente nuevamente." << endl;
            continue;
        }

        // Estadísticas por tipo de usuario
        if (userType == 'G') {
            gamerCount++;
            if (age >= 18 && age <= 25) {
                gamerAgeCount++;
            }
        }

        // Estadísticas por tipo de consulta
        if (queryType == 'A' || queryType == 'T') {
            academicWorkAgeSum += age;
            academicWorkCount++;
        }

        // Estadísticas por hora de acceso
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

    // Cálculo de las estadísticas finales
    int totalUsers = gamerCount + academicWorkCount;
    float gamerAgePercentage = (static_cast<float>(gamerAgeCount) / gamerCount) * 100.0f;
    float academicWorkAgeAvg = (academicWorkCount > 0) ? static_cast<float>(academicWorkAgeSum) / academicWorkCount : 0.0f;

    int maxAccessTimeCount = 0;
    vector<string> mostCommonAccessTimes;
    vector<string> accessTimeLabels = { "MADRUGADA", "MAÑANA", "TARDE", "NOCHE" };

    // Encontrar el número máximo de accesos por hora
    for (int count : accessTimeCount) {
        if (count > maxAccessTimeCount) {
            maxAccessTimeCount = count;
        }
    }

    // Encontrar los momentos más comunes de acceso
    for (int i = 0; i < accessTimeCount.size(); i++) {
        if (accessTimeCount[i] == maxAccessTimeCount) {
            mostCommonAccessTimes.push_back(accessTimeLabels[i]);
        }
    }

    // Impresión de resultados
    cout << "\nRESULTADOS\n" << endl;
    cout << "Porcentaje de Gamers cuya edad oscila entre los 18 y 25 años: " << gamerAgePercentage << endl;
    cout << "Edad promedio de usuarios que realizan una consulta del tipo académico o de trabajo: " << academicWorkAgeAvg << endl;

    cout << "\nMomento o momentos del día en que se realizan más accesos:" << endl;
    for (string time : mostCommonAccessTimes) {
        cout << time << endl;
    }

    if (emotionalQueryMinAge != -1) {
        cout << "\nUsuario de menor edad que realiza una consulta del tipo emocional: NO HUBO" << endl;
    }

    return 0;
}