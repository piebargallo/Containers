#include <iostream>
#include <format>
#include <utility>

using std::pair;
using std::cout;
using std::format;
using std::endl;

int main()
{
	pair pai{ 1.23, 4 };
	cout << format("Pair = {}, {}", pai.first, pai.second) << endl;
	return 0;
}