/*
Diego Frias Castillo
1128342
ej: calcular las raices de una ecuacion cuadratica ax^2 + bx + c = 0
14/8/25
*/
#include <iostream>
#include <cmath> 
using namespace std;

int main() {
    double a, b, c;
    cout << "Ingrese a: ";
    cin >> a;
    cout << "Ingrese b: ";
    cin >> b;
    cout << "Ingrese c: ";
    cin >> c;

    if (a == 0) {
        cout << "No es una ecuacion cuadratica (a = 0)." << endl;
        return 0;
    }

    double discriminante = b * b - 4 * a * c;

    if (discriminante < 0) {
        cout << "No hay soluciones reales." << endl;
    }
    else if (discriminante == 0) {
        double x = -b / (2 * a);
        cout << "Raiz unica: x = " << x << endl;
    }
    else {
        double x1 = (-b + sqrt(discriminante)) / (2 * a);
        double x2 = (-b - sqrt(discriminante)) / (2 * a);
        cout << "Raices: x1 = " << x1 << ", x2 = " << x2 << endl;
    }

    return 0;
}


