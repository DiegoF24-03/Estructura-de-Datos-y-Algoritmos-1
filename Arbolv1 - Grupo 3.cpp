/*
IDS343-02-ESTRUCTURAS DE DATOS Y ALGORITMOS I
Pj: Gestión de un Árbol Binario de Búsqueda. 
Grupo 3:
Diego Frias - 1128342
Dominic De La Rosa - 1128190
Francis Quezada - 1118703
Yarihel Tavarez - 1121618
Fernando Santana - 1127371
Kevin 
Fecha de entrega: 17/9/25
*/

#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

// Estructura del nodo del arbol
struct Nodo {
    int dato;
    Nodo* izquierdo;
    Nodo* derecho;

    // Constructor
    Nodo(int valor) {
        dato = valor;
        izquierdo = nullptr;
        derecho = nullptr;
    }
};

// Clase para el Arbol Binario de Busqueda
class ArbolBinarioBusqueda {
private:
    Nodo* raiz;

    // Funcion auxiliar para insertar un nodo
    Nodo* insertarNodo(Nodo* nodo, int valor) {
        // Si el arbol esta vacio, crear nuevo nodo
        if (nodo == nullptr) {
            return new Nodo(valor);
        }

        // Si el valor es menor, insertar en subarbol izquierdo
        if (valor < nodo->dato) {
            nodo->izquierdo = insertarNodo(nodo->izquierdo, valor);
        }
        // Si el valor es mayor, insertar en subarbol derecho
        else if (valor > nodo->dato) {
            nodo->derecho = insertarNodo(nodo->derecho, valor);
        }

        return nodo;
    }

    // Funcion para encontrar el nodo con valor minimo
    Nodo* encontrarMinimo(Nodo* nodo) {
        Nodo* actual = nodo;
        while (actual && actual->izquierdo != nullptr) {
            actual = actual->izquierdo;
        }
        return actual;
    }

    // Funcion auxiliar para eliminar un nodo
    Nodo* eliminarNodo(Nodo* nodo, int valor) {
        if (nodo == nullptr) {
            return nodo;
        }

        // Buscar el nodo a eliminar
        if (valor < nodo->dato) {
            nodo->izquierdo = eliminarNodo(nodo->izquierdo, valor);
        }
        else if (valor > nodo->dato) {
            nodo->derecho = eliminarNodo(nodo->derecho, valor);
        }
        else {
            // Nodo con un solo hijo o sin hijos
            if (nodo->izquierdo == nullptr) {
                Nodo* temp = nodo->derecho;
                delete nodo;
                return temp;
            }
            else if (nodo->derecho == nullptr) {
                Nodo* temp = nodo->izquierdo;
                delete nodo;
                return temp;
            }

            // Nodo con dos hijos: obtener el sucesor inorden (minimo en subarbol derecho)
            Nodo* temp = encontrarMinimo(nodo->derecho);

            // Copiar el dato del sucesor
            nodo->dato = temp->dato;
              
            // Eliminar el sucesor
            nodo->derecho = eliminarNodo(nodo->derecho, temp->dato);
        }
        return nodo;
    }

    // Funcion auxiliar para buscar un valor
    bool buscarNodo(Nodo* nodo, int valor) {
        if (nodo == nullptr) {
            return false;
        }

        if (valor == nodo->dato) {
            return true;
        }
        else if (valor < nodo->dato) {
            return buscarNodo(nodo->izquierdo, valor);
        }
        else {
            return buscarNodo(nodo->derecho, valor);
        }
    }

    // Funciones de recorrido
    void inOrden(Nodo* nodo) {
        if (nodo != nullptr) {
            inOrden(nodo->izquierdo);
            cout << nodo->dato << " ";
            inOrden(nodo->derecho);
        }
    }

    void preOrden(Nodo* nodo) {
        if (nodo != nullptr) {
            cout << nodo->dato << " ";
            preOrden(nodo->izquierdo);
            preOrden(nodo->derecho);
        }
    }

    void postOrden(Nodo* nodo) {
        if (nodo != nullptr) {
            postOrden(nodo->izquierdo);
            postOrden(nodo->derecho);
            cout << nodo->dato << " ";
        }
    }

    // Funcion para mostrar el arbol de forma grafica
    void mostrarArbolGrafico(Nodo* nodo, int espacio = 0, int incremento = 4) {
        if (nodo == nullptr) {
            return;
        }

        espacio += incremento;

        // Mostrar subarbol derecho primero
        mostrarArbolGrafico(nodo->derecho, espacio);

        // Imprimir el nodo actual
        cout << endl;
        cout << setw(espacio - incremento) << "" << nodo->dato << endl;

        // Mostrar subarbol izquierdo
        mostrarArbolGrafico(nodo->izquierdo, espacio);
    }

public:
    // Constructor
    ArbolBinarioBusqueda() {
        raiz = nullptr;
    }

    // Metodos publicos
    void insertar(int valor) {
        raiz = insertarNodo(raiz, valor);
        cout << "Nodo " << valor << " insertado correctamente." << endl;
    }

    void eliminar(int valor) {
        if (buscar(valor)) {
            raiz = eliminarNodo(raiz, valor);
            cout << "Nodo " << valor << " eliminado correctamente." << endl;
        }
        else {
            cout << "El valor " << valor << " no existe en el arbol." << endl;
        }
    }

    bool buscar(int valor) {
        return buscarNodo(raiz, valor);
    }

    // Metodos para mostrar recorridos
    void mostrarInOrden() {
        cout << "Recorrido InOrden: ";
        inOrden(raiz);
        cout << endl;
    }

    void mostrarPreOrden() {
        cout << "Recorrido PreOrden: ";
        preOrden(raiz);
        cout << endl;
    }

    void mostrarPostOrden() {
        cout << "Recorrido PostOrden: ";
        postOrden(raiz);
        cout << endl;
    }

    // Mostrar arbol de forma grafica
    void mostrarArbol() {
        if (raiz == nullptr) {
            cout << "El arbol esta vacio." << endl;
            return;
        }

        cout << "\nEstructura del Arbol Binario de Busqueda:" << endl;
        cout << "========================================" << endl;
        mostrarArbolGrafico(raiz);
        cout << endl;
    }

    // Verificar si el arbol esta vacio
    bool estaVacio() {
        return raiz == nullptr;
    }
};

// Funcion para validar entrada numerica
int obtenerEnteroValido(const string& mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        cin >> valor;

        if (cin.fail()) {
            // Limpiar el estado de error
            cin.clear();
            // Descartar la entrada incorrecta
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Por favor, ingrese solo numeros enteros." << endl;
        }
        else {
            // Limpiar el buffer despues de una entrada exitosa
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }
    }
}

// Funcion para validar la opcion del menu
int obtenerOpcionValida() {
    int opcion;
    while (true) {
        cout << "Seleccione una opcion (1-8): ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion invalida. Por favor, ingrese solo numeros." << endl;
        }
        else if (opcion < 1 || opcion > 8) {
            cout << "Opcion fuera de rango. Por favor, ingrese un numero entre 1 y 8." << endl;
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return opcion;
        }
    }
}

// Funcion para mostrar el menu
void mostrarMenu() {
    cout << "\n========================================" << endl;
    cout << "      GESTION DE ARBOL BINARIO DE BUSQUEDA" << endl;
    cout << "========================================" << endl;
    cout << "1. Insertar nodo" << endl;
    cout << "2. Buscar nodo" << endl;
    cout << "3. Eliminar nodo" << endl;
    cout << "4. Mostrar recorrido InOrden" << endl;
    cout << "5. Mostrar recorrido PreOrden" << endl;
    cout << "6. Mostrar recorrido PostOrden" << endl;
    cout << "7. Mostrar arbol (vista grafica)" << endl;
    cout << "8. Salir" << endl;
    cout << "========================================" << endl;
}

int main() {
    ArbolBinarioBusqueda arbol;
    int opcion, valor;

    do {
        mostrarMenu();
        opcion = obtenerOpcionValida();

        switch (opcion) {
        case 1:
            valor = obtenerEnteroValido("Ingrese el valor a insertar: ");
            arbol.insertar(valor);
            break;

        case 2:
            valor = obtenerEnteroValido("Ingrese el valor a buscar: ");
            if (arbol.buscar(valor)) {
                cout << "El valor " << valor << " SI existe en el arbol." << endl;
            }
            else {
                cout << "El valor " << valor << " NO existe en el arbol." << endl;
            }
            break;

        case 3:
            valor = obtenerEnteroValido("Ingrese el valor a eliminar: ");
            arbol.eliminar(valor);
            break;

        case 4:
            if (!arbol.estaVacio()) {
                arbol.mostrarInOrden();
            }
            else {
                cout << "El arbol esta vacio." << endl;
            }
            break;

        case 5:
            if (!arbol.estaVacio()) {
                arbol.mostrarPreOrden();
            }
            else {
                cout << "El arbol esta vacio." << endl;
            }
            break;

        case 6:
            if (!arbol.estaVacio()) {
                arbol.mostrarPostOrden();
            }
            else {
                cout << "El arbol esta vacio." << endl;
            }
            break;

        case 7:
            arbol.mostrarArbol();
            break;

        case 8:
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
        }

    } while (opcion != 8);

    return 0;
}