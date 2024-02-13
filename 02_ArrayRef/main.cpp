#include <iostream>
#include <array>

// Función para imprimir un arreglo por ref
template <typename T, size_t Size>
void print_array(const std::array<T, Size>& arr) {
    for (size_t i{}; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::array<int, 4> arr_int{1, 2, 3, 4};
    print_array(arr_int);

    std::array<std::string, 6> arr_str {"The", "sky", "is", "blue", "my", "friend"};
    print_array(arr_str);
    return 0;
}