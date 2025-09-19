/*
Diego Frias Castillo
ID: 1128342
Fecha: 18/09/25
EJ: Super Piramide
*/


#include <iostream>
using namespace std;

int main() {
    int filas;
    cout << "Ingrese el numero de filas: ";
    cin >> filas;

    for (int i = 1; i <= filas; i++) {
        // Espacios en blanco
        for (int j = 1; j <= filas - i; j++) {
            cout << " ";
        }
        // Asteriscos
        for (int k = 1; k <= (2 * i - 1); k++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}