#include <iostream>
#include <valarray>
#include <cmath>
using std::valarray;
using std::cout;
using std::endl;

int main() {
    setlocale(LC_ALL, "es-Es.utf8");
    valarray<double> v = { 1.0, 4.0, 9.0, 16.0, 25.0 };

    // Raíz cuadrada de cada elemento
    valarray<double> raiz = sqrt(v);

    // Logaritmo natural de cada elemento
    valarray<double> logaritmo = log(v);

    cout << "Raíz cuadrada: ";
    for (double i : raiz) {
        cout << i << " ";
    }
    
    cout << "\nLogaritmo: ";
    for (double j : logaritmo) {
        cout << j << " ";
    }
    cout << endl;

    return 0;
}

