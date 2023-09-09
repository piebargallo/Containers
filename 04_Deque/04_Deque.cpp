#include <deque>
#include <iostream>

int main()
{
    // Create a deque containing integers
    std::deque<int> d = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // Iterate and print values of deque
    for (int n : d)
        std::cout << n << ' ';
    std::cout << std::endl;;

    return 0;
}