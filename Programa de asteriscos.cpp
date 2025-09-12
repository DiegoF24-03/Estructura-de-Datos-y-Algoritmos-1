/*
* Diego Antonio Frias Castillo
* ID:1128342
* Ej: ASTERISCOS
* Fecha: 14/8/2025
*/



#include <iostream>
using namespace std;

int main() {
    for (int fila = 1; fila <= 7; fila++) {
        cin.get(); // espera que el usuario presione Enter
        for (int col = 1; col <= fila; col++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
