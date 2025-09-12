/*
* Diego Antonio Frias Castillo
* ID:1128342
* Ej: Floreros de Salvador
* Fecha: 14/8/2025
*/

#include <iostream>
using namespace std;

int main() {
    int total_inicial = 100;


    for (int x = total_inicial; x >= 0; x--) {
        if (x % 6 == 0 && (x - 8) % 11 == 0) {
            cout << "Antes: " << x << " -> Ahora: " << (x - 8) << '\n';

        }
    }


}
