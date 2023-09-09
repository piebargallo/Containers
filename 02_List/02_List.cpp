#include <iostream>
#include <list>

int main()
{
    // Create a list containing integers
    std::list<int> l = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // Print out the list
    std::cout << "l = { ";
    for (int n : l)
        std::cout << n << ", ";
    std::cout << "};\n";

    return 0;
}