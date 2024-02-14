#include <iostream>
#include <vector>

int main()
{
    
    // Begin y end en un arreglo de C
    int vi[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << "Array de C: ";
    for (auto it = std::begin(vi); it != std::end(vi); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;

}