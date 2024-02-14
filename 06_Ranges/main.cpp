#include <ranges>
#include <iostream>

int main()
{
    auto const enteros = { 0, 1, 2, 3, 4, 5 };
    auto par = [](int i) { return 0 == i % 2; };
    auto cuadrado = [](int i) { return i * i; };

    // sintaxis de "tubería" para componer las vistas:
    for (int i : enteros | std::views::filter(par) | std::views::transform(cuadrado)) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}