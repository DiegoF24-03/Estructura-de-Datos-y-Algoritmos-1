/*
Diego Frias CAstillo
1128342
Piramide de bolas
15/8/25
*/

#include <iostream>
using namespace std;

// Suma de cuadrados: 1^2 + 2^2 + ... + n^2
long long sumaCuadrados(long long n) {
    return n * (n + 1) * (2 * n + 1) / 6;
}

// Devuelve el máximo n tal que sumaCuadrados(n) <= bolas
long long maxCapas(long long bolas) {
    long long n = 0;
    while (sumaCuadrados(n + 1) <= bolas) {
        n++;
    }
    return n;
}

int main() {
    long long bolas = 10000; // cambia este valor si quieres probar otro
    long long n = maxCapas(bolas);
    long long usadas = sumaCuadrados(n);
    long long sobrantes = bolas - usadas;

    cout << "Bolas totales: " << bolas << "\n";
    cout << "Capas posibles: " << n << "\n";
    cout << "Bolas usadas: " << usadas << "\n";
    cout << "Bolas que sobran: " << sobrantes << "\n";

    return 0;
}
