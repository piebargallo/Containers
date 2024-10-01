#include <iostream>
#include <valarray>
using std::valarray;
using std::cout;
using std::endl;

int main() {
    valarray<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Crear una máscara para seleccionar elementos mayores que 5
    valarray<bool> mask = v > 5;

    // Usar la máscara para modificar los elementos seleccionados
    v[mask] = 0;

    cout << "Array modificado: ";
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
