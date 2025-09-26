/*
IDS343-02-ESTRUCTURAS DE DATOS Y ALGORITMOS I
EJ: Tabla Hash
Grupo 3:
Diego Frias - 1128342
Dominic De La Rosa - 1128190
Francis Quezada - 1118703
Yarihel Tavarez - 1121618
Fernando Santana - 1127371
Fecha de entrega: 25/9/25
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <sstream>
#include <cctype>

using namespace std;

// Función para limpiar la pantalla (multi-plataforma)
void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

class StudentHashTable {
private:
    static const int TABLE_SIZE = 37;  // Tamaño de la tabla hash cambiado a 37 (número primo para mejor distribución)
    vector<int> table;                 // Vector que representa la tabla hash
    int count;                         // Contador de elementos insertados

    // Función hash: calcula el índice usando módulo del tamaño de la tabla
    int hashFunction(int studentId) {
        return studentId % TABLE_SIZE;
    }

public:
    // Constructor: inicializa la tabla con -1 (indicando posiciones vacías)
    StudentHashTable() : count(0) {
        table.resize(TABLE_SIZE, -1);
    }

    // Método para insertar un estudiante en la tabla hash
    void insertarEstudiante(int studentId) {
        if (count >= TABLE_SIZE) {
            cout << "Error: La tabla hash esta llena. No se puede insertar el estudiante " << studentId << endl;
            return;
        }

        int indice = hashFunction(studentId);  // Calcular índice inicial
        int indiceOriginal = indice;           // Guardar índice original
        int sondeos = 0;                       // Contador de sondeos

        // Buscar posición vacía usando sondeo lineal
        while (table[indice] != -1) {
            // Si el estudiante ya existe, no insertar duplicados
            if (table[indice] == studentId) {
                cout << "El estudiante " << studentId << " ya existe en la tabla (indice " << indice << ")" << endl;
                return;
            }
            // Avanzar al siguiente índice (sondeo lineal)
            indice = (indice + 1) % TABLE_SIZE;
            sondeos++;

            // Detener si se completó un ciclo completo
            if (indice == indiceOriginal) {
                cout << "Error: No se encontro espacio para insertar el estudiante " << studentId << endl;
                return;
            }
        }

        // Insertar el estudiante en la posición encontrada
        table[indice] = studentId;
        count++;
        cout << "Estudiante " << studentId << " insertado en indice " << indice;
        cout << " (" << sondeos << " sondeo(s))" << endl;
    }

    // Método para buscar un estudiante en la tabla hash
    bool buscarEstudiante(int studentId) {
        int indice = hashFunction(studentId);  // Calcular índice inicial
        int indiceOriginal = indice;           // Guardar índice original
        int sondeos = 0;                       // Contador de sondeos

        // Buscar mientras no se encuentre una posición vacía
        while (table[indice] != -1) {
            if (table[indice] == studentId) {
                cout << "Estudiante " << studentId << " encontrado en indice " << indice;
                cout << " (" << sondeos << " sondeo(s))" << endl;
                return true;
            }
            // Avanzar al siguiente índice (sondeo lineal)
            indice = (indice + 1) % TABLE_SIZE;
            sondeos++;

            // Detener si se completó un ciclo completo
            if (indice == indiceOriginal) {
                break;
            }
        }
        cout << "Estudiante " << studentId << " no encontrado" << endl;
        return false;
    }

    // Método para mostrar el estado completo de la tabla hash
    void mostrarTabla() {
        cout << "\n========================================" << endl;
        cout << "          TABLA HASH COMPLETA           " << endl;
        cout << "========================================" << endl;

        // Encabezado de la tabla
        cout << "+---------+--------------+------------+" << endl;
        cout << "| Indice  | ID Estudiante | Estado    |" << endl;
        cout << "+---------+--------------+------------+" << endl;

        int espaciosVacios = 0;
        // Recorrer toda la tabla e imprimir cada posición
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "| " << setw(7) << i << " | ";
            if (table[i] != -1) {
                cout << setw(12) << table[i] << " | Ocupado   |" << endl;
            }
            else {
                cout << setw(12) << "---" << " | Vacio |" << endl;
                espaciosVacios++;
            }
        }
        cout << "+---------+--------------+------------+" << endl;

        // Mostrar estadísticas de la tabla
        cout << "\nESTADISTICAS DE LA TABLA:" << endl;
        cout << "----------------------------" << endl;
        cout << "Elementos insertados: " << count << endl;
        cout << "Espacios vacios: " << espaciosVacios << endl;
        cout << "Tamano total: " << TABLE_SIZE << endl;
        cout << "Factor de carga: " << fixed << setprecision(1)
            << (static_cast<double>(count) / TABLE_SIZE) * 100 << "%" << endl;
    }

    // Método para analizar la distribución de las claves en la tabla hash
    void mostrarDistribucion() {
        vector<int> conteo(TABLE_SIZE, 0);  // Vector para contar elementos por índice

        // Contar cuántos elementos caen en cada índice de hash
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != -1) {
                int indice = hashFunction(table[i]);
                conteo[indice]++;
            }
        }

        cout << "\n========================================" << endl;
        cout << "         DISTRIBUCION DE HASH          " << endl;
        cout << "========================================" << endl;

        // Encabezado de la tabla de distribución
        cout << "+--------+------------+------------+" << endl;
        cout << "| Indice | Elementos  | Colisiones |" << endl;
        cout << "+--------+------------+------------+" << endl;

        int colisionesTotales = 0;
        int maxColisiones = 0;
        int totalElementos = 0;

        // Calcular colisiones y mostrar distribución
        for (int i = 0; i < TABLE_SIZE; i++) {
            int colisiones = (conteo[i] > 1) ? (conteo[i] - 1) : 0;
            cout << "| " << setw(6) << i << " | " << setw(10) << conteo[i]
                << " | " << setw(10) << colisiones << " |" << endl;

            totalElementos += conteo[i];
            if (colisiones > 0) {
                colisionesTotales += colisiones;
                if (colisiones > maxColisiones) {
                    maxColisiones = colisiones;
                }
            }
        }

        cout << "+--------+------------+------------+" << endl;

        // Mostrar resumen de la distribución
        cout << "\nRESUMEN DE DISTRIBUCION:" << endl;
        cout << "----------------------------" << endl;
        cout << "Total de elementos: " << totalElementos << endl;
        cout << "Total de colisiones: " << colisionesTotales << endl;
        cout << "Maximo de colisiones: " << maxColisiones << endl;
        if (totalElementos > 0) {
            cout << "Eficiencia de hash: " << fixed << setprecision(1)
                << (1.0 - static_cast<double>(colisionesTotales) / totalElementos) * 100 << "%" << endl;
        }
        else {
            cout << "Eficiencia de hash: 0.0%" << endl;
        }
    }

    // Método para limpiar/resetear la tabla hash
    void limpiarTabla() {
        fill(table.begin(), table.end(), -1);  // Llenar con -1 (vacío)
        count = 0;  // Reiniciar contador
        cout << "Tabla hash limpiada correctamente" << endl;
    }

    // Método para verificar si la tabla está vacía
    bool estaVacia() {
        return count == 0;
    }
};

// Función para validar si una cadena representa un número entero válido
bool esEnteroValido(const string& str) {
    if (str.empty()) return false;

    // Verificar que todos los caracteres sean dígitos
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }

    // Verificar que el número no sea demasiado grande
    try {
        stoll(str);  // Usar long long para evitar desbordamiento
        return true;
    }
    catch (const out_of_range&) {
        return false;
    }
}

// Función para obtener un número entero válido del usuario
int obtenerEnteroValido(const string& mensaje) {
    string entrada;
    while (true) {
        cout << mensaje;
        getline(cin, entrada);

        // Eliminar espacios en blanco al inicio y final
        size_t inicio = entrada.find_first_not_of(" \t");
        size_t fin = entrada.find_last_not_of(" \t");

        if (inicio == string::npos) {
            cout << "Error: Entrada vacia. Por favor, ingrese un numero entero." << endl;
            continue;
        }

        entrada = entrada.substr(inicio, fin - inicio + 1);

        if (esEnteroValido(entrada)) {
            try {
                return stoi(entrada);
            }
            catch (const out_of_range&) {
                cout << "Error: El numero es demasiado grande. Por favor, ingrese un numero mas pequeño." << endl;
            }
        }
        else {
            cout << "Error: Entrada invalida. Por favor, ingrese solo numeros enteros positivos." << endl;
            cout << "       No se permiten letras, simbolos, decimales o numeros negativos." << endl;
        }
    }
}

// Función para obtener una opción válida del menú
int obtenerOpcionValida(int min, int max) {
    string entrada;
    while (true) {
        cout << "Seleccione una opcion (" << min << "-" << max << "): ";
        getline(cin, entrada);

        // Eliminar espacios en blanco
        size_t inicio = entrada.find_first_not_of(" \t");
        size_t fin = entrada.find_last_not_of(" \t");

        if (inicio == string::npos) {
            cout << "Error: Entrada vacia. Por favor, ingrese una opcion valida." << endl;
            continue;
        }

        entrada = entrada.substr(inicio, fin - inicio + 1);

        if (esEnteroValido(entrada)) {
            int opcion = stoi(entrada);
            if (opcion < min || opcion > max) {
                cout << "Error: Opcion fuera de rango. Por favor, ingrese un numero entre "
                    << min << " y " << max << "." << endl;
            }
            else {
                return opcion;
            }
        }
        else {
            cout << "Error: Opcion invalida. Por favor, ingrese solo numeros." << endl;
        }
    }
}

// Función para mostrar el menú principal
void mostrarMenu() {
    limpiarPantalla();
    cout << "\n========================================" << endl;
    cout << "        TABLA HASH DE ESTUDIANTES       " << endl;
    cout << "========================================" << endl;
    cout << "1. Buscar estudiante" << endl;
    cout << "2. Mostrar tabla hash completa" << endl;
    cout << "3. Mostrar distribucion de hash" << endl;
    cout << "4. Insertar todos los estudiantes" << endl;
    cout << "5. Limpiar tabla hash" << endl;
    cout << "6. Salir" << endl;
    cout << "========================================" << endl;
}

int main() {
    // Lista predefinida de IDs de estudiantes para inserción masiva
    vector<int> idsEstudiantes = {
        1128342, 1128190, 1118703, 1121618, 1127371,
        1126872, 1128212, 1128405, 1126970, 1128834,
        1128068, 1128306, 1126686, 1127646, 1128642,
        1127827, 1128787, 1128719, 1127276, 1127855,
        1126796, 1127597, 1127943, 1128559, 1123238,
        1095100, 1119634, 1126017, 1128060, 1127443,
        1127779, 1127384, 1127024, 1127851, 1127396,
        1128342, 1128190, 1118703, 1121618, 1127371
    };

    StudentHashTable tablaHash;  // Crear instancia de la tabla hash
    int opcion, valor;

    // Mostrar encabezado inicial
    limpiarPantalla();
    cout << "========================================" << endl;
    cout << "     SISTEMA DE TABLA HASH - GRUPO 3    " << endl;
    cout << "========================================" << endl;
    cout << "  ESTRUCTURAS DE DATOS Y ALGORITMOS I   " << endl;
    cout << "              IDS343-02                 " << endl;
    cout << "========================================" << endl;
    cout << "\nPresione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Bucle principal del programa
    do {
        mostrarMenu();
        opcion = obtenerOpcionValida(1, 6);

        switch (opcion) {
        case 1:  // Buscar estudiante
            if (tablaHash.estaVacia()) {
                cout << "La tabla hash esta vacia." << endl;
            }
            else {
                valor = obtenerEnteroValido("Ingrese el ID del estudiante a buscar: ");
                tablaHash.buscarEstudiante(valor);
            }
            break;

        case 2:  // Mostrar tabla completa
            if (tablaHash.estaVacia()) {
                cout << "La tabla hash esta vacia." << endl;
            }
            else {
                tablaHash.mostrarTabla();
            }
            break;

        case 3:  // Mostrar distribución de hash
            if (tablaHash.estaVacia()) {
                cout << "La tabla hash esta vacia. No hay distribucion que mostrar." << endl;
            }
            else {
                tablaHash.mostrarDistribucion();
            }
            break;

        case 4:  // Inserción masiva de estudiantes
            cout << "Insertando " << idsEstudiantes.size() << " estudiantes..." << endl;
            for (int id : idsEstudiantes) {
                tablaHash.insertarEstudiante(id);
            }
            cout << "Insercion masiva completada." << endl;
            break;

        case 5:  // Limpiar tabla
            if (tablaHash.estaVacia()) {
                cout << "La tabla hash ya esta vacia." << endl;
            }
            else {
                tablaHash.limpiarTabla();
            }
            break;

        case 6:  // Salir del programa
            cout << "Gracias por usar el sistema! Hasta luego." << endl;
            break;
        }

        // Pausa antes de continuar (excepto al salir)
        if (opcion != 6) {
            cout << "\nPresione Enter para continuar...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (opcion != 6);

    return 0;
}