/*
Diego Frias Castillo
1128342
ej: La cadena mas larga
5/9/25
*/

#include <iostream>
using namespace std;

// Función para contar la longitud de la cadena para un número dado
int contarCadena(int numero) {
    int contador = 1; // Empezamos con el número actual en la cadena
    while (numero != 4) { // Repetimos hasta llegar a 4
        if (numero % 2 == 0) {
            numero /= 2; // Si es par, dividimos por 2
        }
        else {
            numero = numero * 3 + 1; // Si es impar, multiplicamos por 3 y sumamos 1
        }
        contador++; // Aumentamos el contador por cada paso
    }
    return contador; // Devolvemos la longitud de la cadena
}

int main() {
    int maxCadena = 0; // Para almacenar la longitud máxima de la cadena
    int numeroMaxCadena = 0; // Para almacenar el número que genera la cadena más larga

    // Probamos todos los números entre 1 y 99
    for (int i = 1; i <= 99; i++) {
        int longitud = contarCadena(i); // Calculamos la longitud de la cadena para cada número
        if (longitud > maxCadena) {
            maxCadena = longitud; // Si encontramos una cadena más larga, actualizamos
            numeroMaxCadena = i; // Guardamos el número que generó esa cadena
        }
    }

    // Imprimimos el resultado
    cout << "El número que genera la cadena más larga es: " << numeroMaxCadena << endl;
    cout << "La longitud de la cadena es: " << maxCadena << endl;

    return 0;
}
