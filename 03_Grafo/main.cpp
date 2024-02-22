#include <iostream>
#include <vector>
#include <algorithm> // Para std::swap

using namespace std;

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

    // Método para intercambiar los contenidos de dos grafos
    void swap(Grafo& otro) {
        matrizAdyacencia.swap(otro.matrizAdyacencia);
    }
};

int main() {
    int numNodos = 5; // Número de nodos en el grafo
    Grafo grafo1(numNodos);
    Grafo grafo2(numNodos);

    // Agregar aristas al grafo1
    grafo1.agregarArista(0, 1);
    grafo1.agregarArista(1, 2);
    grafo1.agregarArista(2, 3);
    grafo1.agregarArista(3, 4);

    // Intercambiar los contenidos de grafo1 y grafo2
    grafo1.swap(grafo2);

    // Imprimir matriz de adyacencia del grafo2 (que ahora contiene las aristas)
    for (int i = 0; i < numNodos; ++i) {
        for (int j = 0; j < numNodos; ++j) {
            cout << grafo2.matrizAdyacencia[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
