#include <iostream>
#include <list>

template<class Os, class Co> Os& operator<<(Os& os, const Co& co) {
    os << "{";
    for (auto const& i : co) { os << ' ' << i; }
    return os << " } ";
}

int main()
{
    std::list<int> l1{1, 2, 3};
    std::list<int> l2{ 4, 5 };

    std::cout << l1 << l2 << std::endl;
    l1.swap(l2);
    std::cout << l1 << l2 << std::endl;
    
    return 0;
}