#include <iostream>
#include <vector>
#include <array>

// Función para imprimir una colección mediante iteradores
template <typename T>
void print_collection(const T& collection) {
    auto it = collection.begin();

    std::cout << " [";
    while (it != collection.end()) {
        std::cout << " " << *it;
        ++it;
    }
    std::cout << "]" << std::endl;
}

int main()
{
    std::vector<int> vec_int{ 11, 22, 33, 44 };
    std::array<int, 4> arr_int {100, 200, 300, 400};

    std::vector<int>::iterator it_begin = vec_int.begin();
    std::vector<int>::iterator it_end = vec_int.end();

    std::cout << "vec_int: ";
    print_collection(vec_int);

    std::cout << "arr_int: ";
    print_collection(arr_int);

    return 0;
}