#include <iostream>
#include <valarray>
using std::valarray;
using std::slice_array;
using std::cout;
using std::endl;

int main() {
    valarray<int> v = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // Crear un slice que tome cada segundo elemento
    slice_array<int> slice = v[std::slice(0, 5, 2)];

    // Modificar los elementos del slice
    slice = v + 10;

    cout << "Array modificado: ";
    for (int i : v) {
        std::cout << i << " ";
    }
    cout << endl;

    return 0;
}

