/*
IDS343-02-ESTRUCTURAS DE DATOS Y ALGORITMOS I
Pj: Lista enlazada
Grupo 3:
Diego Frias - 1128342
Dominic De La Rosa - 1128190
Francis Quezada - 1118703
Yarihel Tavarez - 1121618
Fernando Santana�-�1127371
Kevin
Fecha: 5/9/25
*/

#include <iostream>
#include <limits>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Funci�n para validar entrada de n�meros enteros
int validarEntero() {
    int valor;
    while (true) {
        cin >> valor;
        if (cin.fail()) {    // Si la entrada falla (no es un n�mero)
            cin.clear();    // Limpiar el estado de error de cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada incorrecta
            cout << "Entrada no v�lida. Ingrese un n�mero entero: ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }
    }
}

// Insertar nodo de forma ordenada
void insertarOrdenado(Nodo*& cabeza) {
    cout << "Ingrese el dato a insertar: ";
    int nuevoDato = validarEntero();

    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = nuevoDato;
    nuevoNodo->siguiente = nullptr;

    // Caso 1: Lista vac�a
    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
        cout << "Dato " << nuevoDato << " insertado correctamente." << endl;
        return;
    }

    // Caso 2: Insertar al inicio
    if (nuevoDato < cabeza->dato) {
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
        cout << "Dato " << nuevoDato << " insertado correctamente." << endl;
        return;
    }

    // Caso 3: Buscar posici�n para insertar
    Nodo* actual = cabeza;
    Nodo* anterior = nullptr;

    while (actual != nullptr && actual->dato < nuevoDato) {
        anterior = actual;
        actual = actual->siguiente;
    }

    // Verificar si el dato ya existe
    if (actual != nullptr && actual->dato == nuevoDato) {
        cout << "El dato " << nuevoDato << " ya existe en la lista." << endl;
        delete nuevoNodo;
        return;
    }

    // Insertar en la posici�n encontrada
    anterior->siguiente = nuevoNodo;
    nuevoNodo->siguiente = actual;
    cout << "Dato " << nuevoDato << " insertado correctamente." << endl;
}

// Buscar un dato en la lista
void buscarElemento(Nodo* cabeza) {
    if (cabeza == nullptr) {
        cout << "La lista est� vac�a." << endl;
        return;
    }

    cout << "Ingrese el dato a buscar: ";
    int datoBuscar = validarEntero();

    Nodo* actual = cabeza;
    int posicion = 1;
    bool encontrado = false;

    while (actual != nullptr) {
        if (actual->dato == datoBuscar) {
            cout << "Dato " << datoBuscar << " encontrado en posici�n " << posicion << "." << endl;
            encontrado = true;
            break;
        }
        if (actual->dato > datoBuscar) {
            break; // La lista est� ordenada, no es necesario seguir
        }
        actual = actual->siguiente;
        posicion++;
    }

    if (!encontrado) {
        cout << "Dato " << datoBuscar << " no encontrado." << endl;
    }
}

// Eliminar un dato de la lista
void eliminarElemento(Nodo*& cabeza) {
    if (cabeza == nullptr) {
        cout << "La lista est� vac�a." << endl;
        return;
    }

    cout << "Ingrese el dato a eliminar: ";
    int datoEliminar = validarEntero();

    Nodo* actual = cabeza;
    Nodo* anterior = nullptr;
    bool encontrado = false;

    // Buscar el nodo a eliminar
    while (actual != nullptr && actual->dato <= datoEliminar) {
        if (actual->dato == datoEliminar) {
            encontrado = true;
            break;
        }
        anterior = actual;
        actual = actual->siguiente;
    }

    if (!encontrado) {
        cout << "Dato " << datoEliminar << " no encontrado." << endl;
        return;
    }

    // Eliminar el nodo
    if (anterior == nullptr) {
        cabeza = cabeza->siguiente; // Eliminar el primer nodo
    }
    else {
        anterior->siguiente = actual->siguiente;
    }

    delete actual;
    cout << "Dato " << datoEliminar << " eliminado correctamente." << endl;
}

// Mostrar todos los elementos de la lista
void mostrarLista(Nodo* cabeza) {
    if (cabeza == nullptr) {
        cout << "La lista est� vac�a." << endl;
        return;
    }

    cout << "Elementos de la lista (orden ascendente):" << endl;
    Nodo* actual = cabeza;
    int posicion = 1;

    while (actual != nullptr) {
        cout << "Posici�n " << posicion << ": " << actual->dato << endl;
        actual = actual->siguiente;
        posicion++;
    }
}

    // Liberar toda la memoria
    void liberarMemoria(Nodo*& cabeza) {
        while (cabeza != nullptr) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }   

// Men� principal
int main() {
    Nodo* cabeza = nullptr;
    int opcion;

    do {
        cout << "\n=== MEN� LISTA ENLAZADA ORDENADA ===" << endl;
        cout << "1. Insertar elemento" << endl;
        cout << "2. Buscar elemento" << endl;
        cout << "3. Eliminar elemento" << endl;
        cout << "4. Mostrar lista" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opci�n: ";

        cin >> opcion;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opci�n no v�lida. Ingrese un n�mero del 1 al 5." << endl;
            continue;
        }

        switch (opcion) {
        case 1:
            insertarOrdenado(cabeza);
            break;
        case 2:
            buscarElemento(cabeza);
            break;
        case 3:
            eliminarElemento(cabeza);
            break;
        case 4:
            mostrarLista(cabeza);
            break;
        case 5:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opci�n no v�lida. Ingrese un n�mero del 1 al 5." << endl;
        }

    } while (opcion != 5);

    liberarMemoria(cabeza);
    
    return 0;
}