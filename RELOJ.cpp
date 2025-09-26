/*
Diego Frias Castillo
ID: 1128342
Ejercicio: RELOJ o CLOCK
Fecha: 25/9/25
*/




#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Convierte minutos (double) desde 00:00 en HH:MM:SS y lo imprime
void printTime(double minutesFromMidnight) {
    long long totalSeconds = llround(minutesFromMidnight * 60.0); // redondeo seguro
    int hh = static_cast<int>((totalSeconds / 3600) % 24);
    int mm = static_cast<int>((totalSeconds / 60) % 60);
    int ss = static_cast<int>(totalSeconds % 60);

    cout << setfill('0') << setw(2) << hh << ":"
        << setw(2) << mm << ":"
        << setw(2) << ss;
}

int main() {
    const double intervalo = 720.0 / 11.0; // minutos entre superposiciones
    cout << fixed << setprecision(0);

    cout << "Superposiciones en 24 horas:\n";
    // En 24 h hay 22 superposiciones: k = 0..21 (k=22 sería 24:00 y no se cuenta)
    for (int k = 0; k < 22; ++k) {
        double t = k * intervalo; // minutos desde 00:00
        cout << "  #" << (k + 1) << "  ";
        printTime(t);
        cout << '\n';
    }

    cout << "\nTotal en 12 horas: " << 11 << " veces\n";
    cout << "Total en 24 horas: " << 22 << " veces\n";
    return 0;
}
