#include <iostream>
#include <vector>

using namespace std;

const int MAX_NODES = 100; // Tamaño máximo del grafo

class Grafo {
public:
    vector<vector<int>> matrizAdyacencia;

    // Constructor por defecto
    Grafo() {
        matrizAdyacencia.resize(MAX_NODES, vector<int>(MAX_NODES, 0));
    }

    // Constructor de copia
    Grafo(const Grafo& other) {
        matrizAdyacencia = other.matrizAdyacencia;
    }

    // Constructor de movimiento
    Grafo(Grafo&& other) noexcept {
        matrizAdyacencia = move(other.matrizAdyacencia);
    }

    void agregarArista(int nodo1, int nodo2) {
        matrizAdyacencia[nodo1][nodo2] = 1;
        matrizAdyacencia[nodo2][nodo1] = 1; // Si el grafo es no dirigido
    }
};

int main() {
    int numNodos = 5; // Número de nodos en el grafo
    Grafo grafo1; // Constructor por defecto
    Grafo grafo2(grafo1); // Constructor de copia
    Grafo grafo3 = move(grafo2); // Constructor de movimiento

    // Agregar aristas al grafo1
    grafo1.agregarArista(0, 1);
    grafo1.agregarArista(1, 2);
    grafo1.agregarArista(2, 3);
    grafo1.agregarArista(3, 4);

    // Imprimir matriz de adyacencia del grafo1
    for (int i = 0; i < numNodos; ++i) {
        for (int j = 0; j < numNodos; ++j) {
            cout << grafo1.matrizAdyacencia[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
