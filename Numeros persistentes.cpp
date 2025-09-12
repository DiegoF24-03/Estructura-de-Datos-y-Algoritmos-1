/*
Diego Frias Castillo
ID: 1128342
Ejercicio: N�meros persistentes
Fecha: 9/11/25
*/


#include <iostream>
using namespace std;

// Funci�n que devuelve la persistencia multiplicativa de un n�mero
int persistencia(int n) {
    int pasos = 0;
    while (n >= 10) { // mientras no sea un d�gito
        int producto = 1;
        int temp = n;
        while (temp > 0) {
            producto *= temp % 10; // multiplicar d�gitos
            temp /= 10;
        }
        n = producto;
        pasos++;
    }
    return pasos;
}

int main() {
    int resultado = -1;
    for (int n = 10; n < 100; n++) { // solo dos d�gitos
        int p = persistencia(n);
        if (p > 3) {
            cout << "Numero: " << n << " tiene persistencia: " << p << endl;
            resultado = n;
        }
    }
    if (resultado != -1)
        cout << "El unico numero de dos digitos con persistencia mayor que 3 es: " << resultado << endl;
    else
        cout << "No se encontro ningun n�mero de dos digitos con persistencia > 3." << endl;

    return 0;
}
