#include <iostream>
#include <vector>
using std::cout;
using std::vector;
using std::endl;
using std::cerr;

int main() {
    setlocale(LC_ALL, "es-Es.utf8");
    // CTAD
    vector vec = { 1, 2, 3, 4, 5 };

    try {
        // Acceso seguro al tercer elemento
        cout << "El tercer elemento es: " << vec.at(2) << endl;

        // Intento de acceso fuera de los límites
        cout << "Elemento fuera de los límites: " << vec.at(10) << endl;
    }
    catch (const std::out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
