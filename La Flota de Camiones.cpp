/*Diego Frias Castillo
ID: 1128342
fecha: 18/9/25
Ejercicio: La Flota de Camiones
*/

#include <iostream>  

using namespace std;  

// Función que verifica si el cuadrado del número termina en el mismo número
bool terminaEnNumero(int numero) {
    int cuadrado = numero * numero;  
    int ultimoDigito = cuadrado % 100; 
    return ultimoDigito == numero;  
}

int main() {
    cout << "Camiones con numeros cuyo cuadrado termina en el mismo numero:\n"; 

    // Iteramos a través de todos los números menores que 500
    for (int i = 1; i < 500; i++) {
        // Llamamos a la función terminaEnNumero para verificar si el cuadrado de i termina en i mismo
        if (terminaEnNumero(i)) {
            cout << "Camion con numero: " << i << endl;  
        }
    }

    return 0;  
}
