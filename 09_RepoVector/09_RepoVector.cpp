#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

int main() {
    setlocale(LC_ALL, "es-Es.utf8");
    vector vec { 10, 20, 30, 40, 50 };

    // Acceder al primer elemento usando front()
    cout << "El primer elemento es: " << vec.front() << endl;

    // Acceder al último elemento usando back()
    cout << "El último elemento es: " << vec.back() << endl;

    // Modificar el primer y último elemento
    vec.front() = 100;
    vec.back() = 500;

    cout << "Después de modificar, el primer elemento es: " << vec.front() << endl;
    cout << "Después de modificar, el último elemento es: " << vec.back() << endl;

    return 0;
}
