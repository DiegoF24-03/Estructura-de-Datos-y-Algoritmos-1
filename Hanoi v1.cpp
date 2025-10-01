/*
IDS343-02-ESTRUCTURAS DE DATOS Y ALGORITMOS I
EJ: Hanoi
Grupo 3:
Diego Frias - 1128342
Dominic De La Rosa - 1128190
Francis Quezada - 1118703
Yarihel Tavarez - 1121618
Fernando Santana - 1127371
Fecha de entrega: 2/10/25
*/

*/

#include <iostream>
#include <cctype>
#include <limits>
#include <string>
using namespace std;

// ---------- Funciones auxiliares ----------
char otherPeg(char a, char b) {
    for (char t : {'A', 'B', 'C'})
        if (t != a && t != b)
            return t;
    return 'A';
}

// limpiar pantalla
void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Validacion de enteros positivos
bool esEnteroValido(const string& s) {
    if (s.empty()) return false;
    for (char c : s) if (!isdigit((unsigned char)c)) return false;
    try { stoll(s); }
    catch (...) { return false; }
    return true;
}

int obtenerEnteroValido(const string& mensaje) {
    string entrada;
    while (true) {
        cout << mensaje;
        getline(cin, entrada);

        // trim
        size_t i = entrada.find_first_not_of(" \t");
        size_t j = entrada.find_last_not_of(" \t");
        if (i == string::npos) {
            cout << "Error: entrada vacia.\n";
            continue;
        }
        entrada = entrada.substr(i, j - i + 1);

        if (!esEnteroValido(entrada)) {
            cout << "Error: solo numeros enteros positivos.\n";
            continue;
        }
        try {
            int v = stoi(entrada);
            return v;
        }
        catch (...) {
            cout << "Error: numero invalido.\n";
        }
    }
}

int obtenerOpcionValida(int min, int max) {
    while (true) {
        int op = obtenerEnteroValido("Seleccione una opcion (" + to_string(min) + "-" + to_string(max) + "): ");
        if (op < min || op > max) {
            cout << "Error: opcion fuera de rango.\n";
        }
        else return op;
    }
}

// ---------- Algoritmo de Hanoi ----------
void hanoi(int n, char from, char aux, char to, unsigned long long& pasos) {
    if (n == 0) return;
    hanoi(n - 1, from, to, aux, pasos);
    cout << "Mover disco " << n << " de " << from << " -> " << to << '\n';
    ++pasos;
    hanoi(n - 1, aux, from, to, pasos);
}

// ---------- Consola ----------
void mostrarMenu() {
    cout << "\n========================================\n";
    cout << "            TORRES DE HANOI             \n";
    cout << "========================================\n";
    cout << "1. Resolver Torres de Hanoi\n";
    cout << "2. Ayuda rapida\n";
    cout << "3. Salir\n";
    cout << "========================================\n";
}

void ayuda() {
    cout << "\nREGLAS DEL JUEGO:\n";
    cout << "- 3 torres: A, B y C.\n";
    cout << "- Los discos estan ordenados de mayor a menor en la torre de origen.\n";
    cout << "- No se puede poner un disco grande sobre uno pequeno.\n";
    cout << "- Objetivo: trasladar todos los discos de una torre a otra.\n";
    cout << "- Movimientos minimos: 2^n - 1.\n";
}

// ---------- Programa principal ----------
int main() {
    int opcion;
    do {
        limpiarPantalla();
        mostrarMenu();
        opcion = obtenerOpcionValida(1, 3);

        if (opcion == 1) {
            int n;
            while (true) {
                n = obtenerEnteroValido("Cantidad de anillos (>=1): ");
                if (n < 1) { cout << "Debe ser >= 1.\n"; continue; }
                break;
            }

            char origen, destino;
            while (true) {
                cout << "Torre de origen [A/B/C]: ";
                if (!(cin >> origen)) {
                    cout << "Entrada invalida.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                origen = toupper(origen);
                if (origen == 'A' || origen == 'B' || origen == 'C') break;
                cout << "Invalido. Use A, B o C.\n";
            }

            while (true) {
                cout << "Torre de destino [A/B/C]: ";
                if (!(cin >> destino)) {
                    cout << "Entrada invalida.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                destino = toupper(destino);
                if (destino != origen && (destino == 'A' || destino == 'B' || destino == 'C')) break;
                cout << "Invalido o igual al origen.\n";
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            char auxiliar = otherPeg(origen, destino);

            cout << "\nMoviendo " << n << " discos de " << origen
                << " a " << destino << " usando " << auxiliar << " como auxiliar.\n\n";

            unsigned long long pasos = 0ULL;
            hanoi(n, origen, auxiliar, destino, pasos);

            // Calculo seguro del valor teorico si n < 64
            cout << "\nTotal de movimientos: " << pasos;
            if (n >= 0 && n < 64) {
                unsigned long long esperado = (1ULL << n) - 1ULL;
                cout << " (esperado: " << esperado << ")";
            }
            else {
                cout << " (esperado: 2^n - 1; n demasiado grande para 64 bits)";
            }
            cout << "\n";
        }
        else if (opcion == 2) {
            ayuda();
        }
        else if (opcion == 3) {
            cout << "Gracias por usar el programa. Adios!\n";
        }

        if (opcion != 3) {
            cout << "\nPresione Enter para continuar...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (opcion != 3);

    return 0;
}
