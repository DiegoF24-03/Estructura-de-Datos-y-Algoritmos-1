/*
* Diego Antonio Frias Castillo
* ID:1128342
* Ej: COCACOLA
* Fecha: 15/8/2025
*/

#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 100; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            cout << "coca cola\n";
        }
        else if (i % 3 == 0) {
            cout << "coca\n";
        }
        else if (i % 5 == 0) {  
            cout << "cola\n";
        }
        else {
            cout << i << "\n";
        }
    }
    return 0;
}
