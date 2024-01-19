#include <iostream>

#define MAX_COLS 10
#define MAX_FILS 10

using namespace std;

bool esConsonante(char letra) {
    letra = toupper(letra);

    if (letra >= 'A' && letra <= 'Z' &&
        letra != 'A' && letra != 'E' && 
        letra != 'I' && letra != 'O' && 
        letra != 'U')
        return true;

    return false;
}

char generaLetraAleatoria() {
    int valor = rand() % 26;
    return 'A' + valor;
}

string generaSecuenciaConsonantes(char letra, int longitud) {
   int contador = 0;
   string secuencia = "";
  
   while (contador < longitud) {
      if (esConsonante(letra)) {
        secuencia += letra;
        contador++;
      }
      letra++;

      if (letra > 'Z')
        letra = 'A';
   }

   return secuencia;
}

bool insertSecuenciaVertical(char matriz[MAX_FILS][MAX_COLS], int fil, int col, string secuencia) {
 
    if (fil + secuencia.length() > MAX_FILS)
        return false;

    if (col > MAX_COLS)
        return false;

    for (int indice = 0; indice < secuencia.length(); indice++)
      matriz[fil + indice][col] = secuencia[indice];

    return true;
}

void genera_y_muestra_matriz(char matriz[MAX_FILS][MAX_COLS]) {
    srand(time(NULL));

    for (int fil = 0; fil < MAX_FILS; fil++) {
        for (int col = 0; col < MAX_COLS; col++) {
            matriz[fil][col] = generaLetraAleatoria();
        }
    }

    /// secuencias forzadas manualmente para la prueba
    insertSecuenciaVertical(matriz, 0, 8, "DFGH");
    insertSecuenciaVertical(matriz, 4, 4, "DFGH");
    insertSecuenciaVertical(matriz, 5, 1, "DFGH");
    insertSecuenciaVertical(matriz, 6, 9, "DFGH");

    cout << "  ";
    for (int col = 0; col < MAX_COLS; col++)
        cout << " " << col;
    cout << endl;

    for (int fil = 0; fil < MAX_FILS; fil++) {
         cout << " " << fil << " ";
        for (int col = 0; col < MAX_COLS; col++) {
            cout << matriz[fil][col]  << " ";
        }
        cout << endl;
    }

}

void cantidad_veces(char matriz[MAX_FILS][MAX_COLS], string secuencia) {
    int elemento1 = 0, elemento2 = 0, elemento3  = 0, elemento4  = 0;
    char letra;

    for (int fil = 0; fil < MAX_FILS; fil++) {
        for (int col = 0; col < MAX_COLS; col++) {
            letra = matriz[fil][col];

            if (letra == secuencia[0])
              elemento1++;

             if (letra == secuencia[1])
              elemento2++;

            if (letra == secuencia[2])
              elemento3++;

            if (letra == secuencia[3])
              elemento4++;
        }
    }

    cout << endl;
    cout << "Frecuencia Caracteres" << endl;
    cout << "---------------------" << endl;
    cout << "Carácter " << secuencia[0] << " aparece " << elemento1 << " veces" << endl;
    cout << "Carácter " << secuencia[1] << " aparece " << elemento2 << " veces" << endl;
    cout << "Carácter " << secuencia[2] << " aparece " << elemento3 << " veces" << endl;
    cout << "Carácter " << secuencia[3] << " aparece " << elemento4 << " veces" << endl;



}

void secuencia_en_matriz(char matriz[MAX_FILS][MAX_COLS], string secuencia) {
    int contador = 0;
    bool encontrada = false;

    cout << endl;
    cout << "Apariciones Secuencia" << endl;
    cout << "---------------------" << endl;
    for (int col = 0; col < MAX_COLS; col++) {
        for (int fil = 0; fil <= MAX_FILS - secuencia.length(); fil++) {
            encontrada = true;

            for (int sec = 0; sec < secuencia.length(); sec++) {
                if (matriz[fil + sec][col] != secuencia[sec]) {
                    encontrada = false;
                    break;
                }
            }

            if (encontrada) {
                contador++;
                cout << "Fila: " << fil << ", Columna: " << col << endl;
            }
        }
    }

    cout << endl;
    cout << "Total de apariciones : " << contador << endl;
}

int main() {
    char matriz[MAX_FILS][MAX_COLS];
    string secuencia = "";

    secuencia = generaSecuenciaConsonantes('A', 4);

    secuencia = "DFGH"; // <= forzar frecuencia manualmente para la prueba
    cout << "Secuencia = '" << secuencia << "'" << endl << endl;

    genera_y_muestra_matriz(matriz);
    cantidad_veces(matriz, secuencia);
    secuencia_en_matriz(matriz, secuencia);

    return 0;
}