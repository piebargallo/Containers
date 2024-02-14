#include <iostream>
#include <ranges>
#include <vector>

template <std::ranges::input_range R>
void print(R&& r)
{
    if (std::ranges::empty(r)) {
        std::cout << "Vacio" << std::endl;;
        return;
    }

    for (const auto& element : r) {
        std::cout << element << ' ';
    }

    std::cout << '\n';
}

int main()
{
    {
        auto v = std::vector<int>{ 0, 2, 4 };
        std::cout << "Vector v: ";
        print(v);
    }

    {
        auto w = std::vector<int>{};
        std::cout << "Vector w: ";
        print(w);
    }
    std::cout << std::endl;

    return 0;
}