#include <iostream>
#include <vector>

int main()
{

    // Begin y end en un contenedor de tipo vector
    std::vector<int> vic{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "Vector container: ";
    for (auto it = vic.begin(); it != vic.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;

}