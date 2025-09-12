/*
Diego Frias Castillo
1128342
ej: Descomponer
28/8/25
*/

#include <iostream>
#include <cmath>
using namespace std;

// Imprime la descomposición en factores primos de n
void descomponer(long long n) {
    long long original = n;

    // Casos especiales
    if (n == 0) { cout << "0 no tiene descomposicion en factores primos.\n"; return; }
    if (n == 1) { cout << "1 no tiene factores primos.\n"; return; }
    if (n == -1) { cout << "-1 no tiene factores primos.\n"; return; }

    cout << original << " = ";

    // Manejar signo
    if (n < 0) {
        cout << "-1";
        n = -n;
        if (n > 1) cout << " * ";
    }

    // Factor 2
    bool primero = true;
    while (n % 2 == 0) {
        cout << (primero ? "" : " * ") << 2;
        primero = false;
        n /= 2;
    }

    // Factores impares
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            cout << (primero ? "" : " * ") << i;
            primero = false;
            n /= i;
        }
    }

    // Si queda un primo grande
    if (n > 1) {
        cout << (primero ? "" : " * ") << n;
    }

    cout << '\n';
}

int main() {
    long long n;
    cout << "Ingrese un entero: ";
    while (cin >> n) {
        descomponer(n);
        cout << "Ingrese otro entero (Ctrl+C para salir): ";
    }
    return 0;
}
