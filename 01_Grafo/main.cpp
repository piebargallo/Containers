#include <iostream>
#include <vector>

using namespace std;

const int MAX_NODES = 100; // Tamaño máximo del grafo

class Grafo {
public:
    vector<vector<int>> matrizAdyacencia;

    Grafo(int n) {
        matrizAdyacencia.resize(n, vector<int>(n, 0));
    }

    void agregarArista(int nodo1, int nodo2) {
        matrizAdyacencia[nodo1][nodo2] = 1;
        matrizAdyacencia[nodo2][nodo1] = 1; // Si el grafo es no dirigido
    }
};

int main() {
    int numNodos = 5; // Número de nodos en el grafo
    Grafo grafo(numNodos);

    // Agregar aristas
    grafo.agregarArista(0, 1);
    grafo.agregarArista(1, 2);
    grafo.agregarArista(2, 3);
    grafo.agregarArista(3, 4);

    // Imprimir matriz de adyacencia
    for (int i = 0; i < numNodos; ++i) {
        for (int j = 0; j < numNodos; ++j) {
            cout << grafo.matrizAdyacencia[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
