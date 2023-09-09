#include <iostream>
#include <array>

int main()
{
    // Construction uses aggregate initialization
    std::array<int, 10> a1{{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }}; 

    // Ranged for loop is supported
    for (const auto& s : a1)
        std::cout << s << ' ';
    std::cout << std::endl;

    return 0;
}
