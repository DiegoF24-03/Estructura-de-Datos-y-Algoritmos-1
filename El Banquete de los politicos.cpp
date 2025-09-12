/*
Diego Frias Castillo
ID: 1128342
Fecha: 9/11/25
Ejercicio: El Banquete de los políticos
*/



#include <iostream>
using namespace std;

int main() {
    const int TOTAL_PERSONAS = 100;
    const int TOTAL_MONEDAS = 7869;
    const int P_SEN = 75, P_CONG = 99, P_INV = 40;

    for (int s = 0; s <= TOTAL_PERSONAS; ++s) {          // senadores
        for (int c = 0; c <= TOTAL_PERSONAS - s; ++c) {  // congresistas
            int i = TOTAL_PERSONAS - s - c;              // invitados
            int dinero = P_SEN * s + P_CONG * c + P_INV * i;
            if (dinero == TOTAL_MONEDAS) {
                cout << "Senadores: " << s << "\n"
                    << "Congresistas: " << c << "\n"
                    << "Invitados: " << i << "\n";
                return 0; // listo
            }
        }
    }
    cout << "No hay solucion entera bajo esas condiciones.\n";
    return 0;
}
