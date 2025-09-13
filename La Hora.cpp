/*
Diego Frias Castillo
1128342
12/9/24
Ejercicio: La Hora
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    for (int h = 0; h < 24; ++h) {
        for (int m = 0; m < 60; ++m) {
            int left = h * h + m * m;       // (HH)^2 + (MM)^2
            int right = 100 * h + m;      // número HHMM
            if (left == right) {
                cout << setfill('0') << setw(2) << h << ":"
                    << setw(2) << m << '\n';
            }
        }
    }
    return 0;
}