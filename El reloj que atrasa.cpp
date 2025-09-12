#include <iostream>
#include <cmath>    // Para pow()

using namespace std;

// Función para calcular el término n de Fibonacci
long long fibonacci(int n) {
    if (n == 1 || n == 2) return 1;
    long long f1 = 1, f2 = 1, fn;
    for (int i = 3; i <= n; i++) {
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }
    return f2;
}

int main() {
    double atraso = 0.0;

    for (int n = 1; n <= 24; n++) {
        long long Fn = fibonacci(n);
        double termino = (double)Fn / pow(2, n);
        atraso += termino;

        cout << "Hora " << n << ": F(" << n << ")=" << Fn
            << " -> Termino = " << termino << " minutos" << endl;
    }

    cout << "\nAtraso total en 24 horas = " << atraso << " minutos" << endl;

    return 0;
}
