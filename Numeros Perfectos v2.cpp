/*Diego Frias Castillo - 1128342 - 18/9/25 - Numeros Perfectos */


#include <iostream>
using namespace std;

// Función para comprobar si un número es perfecto
bool esPerfecto(int num) {
    int suma = 0;

    // Encontrar la suma de los divisores de num
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            suma += i;
        }
    }

    // Si la suma de los divisores es igual al número, es perfecto
    return suma == num;
}

int main() {
    int limite;
    int opcion;

    do {
        // Mostrar el menú
        cout << "\n----- Menu -----\n";
        cout << "1. Introducir un numero y buscar si es perfecto\n";
        cout << "2. Salir\n";
        cout << "Elige una opción: ";
        cin >> opcion;

        // Opción 1: Buscar números perfectos hasta el límite
        if (opcion == 1) {
            cout << "Introduce el límite para buscar números perfectos: ";
            cin >> limite;

            // Mostrar los números perfectos hasta el límite
            bool encontrado = false;
            for (int i = 1; i <= limite; i++) {
                if (esPerfecto(i)) {
                    cout << i << " es un número perfecto." << endl;
                    encontrado = true;
                }
            }

            if (!encontrado) {
                cout << "No se encontraron números perfectos hasta " << limite << ".\n";
            }
        }
        // Opción 2: Salir
        else if (opcion == 2) {
            cout << "¡Hasta luego!\n";
        }
        else {
            cout << "Opción no válida. Por favor, elige una opción válida.\n";
        }

    } while (opcion != 2);  // El programa continuará hasta que el usuario elija salir

    return 0;
}

