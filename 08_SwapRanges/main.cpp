#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v1 = { 1, 2, 3, 4 };
    std::vector<int> v2 = { -1, -2, -3, -4 };

    std::swap_ranges(v1.begin(), v1.begin() + 2, v2.begin());

    for (int n : v1)
        std::cout << n << ' ';
    std::cout << '\n';
    
    for (int n : v2)
        std::cout << n << ' ';
    std::cout << '\n';

    return 0;
}