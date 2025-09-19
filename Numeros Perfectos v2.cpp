#include <iostream>
using namespace std;

// Funci�n para comprobar si un n�mero es perfecto
bool esPerfecto(int num) {
    int suma = 0;

    // Encontrar la suma de los divisores de num
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            suma += i;
        }
    }

    // Si la suma de los divisores es igual al n�mero, es perfecto
    return suma == num;
}

int main() {
    int limite;

    // Solicitar al usuario el l�mite de b�squeda
    cout << "Introduce el limite para buscar numeros perfectos: ";
    cin >> limite;

    // Mostrar los n�meros perfectos hasta el l�mite
    for (int i = 1; i <= limite; i++) {
        if (esPerfecto(i)) {
            cout << i << " es un numero perfecto." << endl;
        }
    }

    return 0;
}
