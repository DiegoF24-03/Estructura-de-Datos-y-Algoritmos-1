/*
Diego Frias Castillo
ID: 1128342
Fecha: 21/8/2025
Ejercicio: Serie de Fibonacci
*/

#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Ingrese la cantidad de terminos de la serie de Fibonacci: ";
    cin >> n;

    int a = 0, b = 1;   // primeros dos términos
    cout << "Serie de Fibonacci: ";

    for (int i = 1; i <= n; i++) {
        cout << a << " ";  // mostramos el término actual
        int siguiente = a + b;  // calculamos el siguiente
        a = b;   // el segundo pasa a ser el primero
        b = siguiente;  // el siguiente pasa a ser el segundo
    }

    cout << endl;
    return 0;
}
