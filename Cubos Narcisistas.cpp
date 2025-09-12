/*
Diego Frias Castillo
ID: 1128342
Fecha: 21/8/2025
Ej: Cubos narcisistas
*/

#include <iostream>
using namespace std;

int main()
{
    for (int i = 100; i <= 999; i++) {
        int a = i / 100;         // centena
        int b = (i / 10) % 10;   // decena
        int c = i % 10;          // unidad

        if (i == a * a * a + b * b * b + c * c * c) {
            cout << i << endl;
        }
    }

    return 0;
}
