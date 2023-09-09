#include <iostream>
#include <vector>

int main()
{
    // Create a vector containing integers
    std::vector<int> v = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    //Print out the vector
    for (int n : v)
        std::cout << n << ' ';
    std::cout << '\n';

    return 0;
}