#include <iostream>
#include <vector>

// Función para imprimir un vector por referencia
template <typename T>
void print_vec(const std::vector<T>& vec) {
    for (size_t i{}; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec_int = { 1,2,3,4 };
    print_vec(vec_int);

    std::vector<std::string> vec_str {"The", "sky", "is", "blue", "my", "friend"};
    print_vec(vec_str);
    return 0;
}