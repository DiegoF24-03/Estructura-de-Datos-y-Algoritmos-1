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

    // Solicitar al usuario el límite de búsqueda
    cout << "Introduce el limite para buscar numeros perfectos: ";
    cin >> limite;

    // Mostrar los números perfectos hasta el límite
    for (int i = 1; i <= limite; i++) {
        if (esPerfecto(i)) {
            cout << i << " es un numero perfecto." << endl;
        }
    }

    return 0;
}
