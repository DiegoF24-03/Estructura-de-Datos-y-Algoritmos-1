/*
* Diego Antonio Frias Castillo
* ID:1128342
* Ej: Mayor de 5 Numeros
* Fecha: 15/8/2025
*/

#include <iostream>
using namespace std;

int main() {
    int numeros[5]; 
    int mayor;

    cout << "Ingrese 5 numeros enteros:\n";

    for (int i = 0; i < 5; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> numeros[i];
    }

    mayor = numeros[0];

    for (int i = 1; i < 5; i++) {
        if (numeros[i] > mayor) {
            mayor = numeros[i];
        }
    }

    cout << "El numero mayor es: " << mayor << endl;

    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
