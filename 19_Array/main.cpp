#include <iostream>
#include <format>
#include <array>

using std::array;
using std::cout;
using std::format;
using std::endl;

int main()
{
	array arr{ 9, 8, 7 };
	// Comprova si està buït, output bool
	cout << format("bacuo = {}", arr.empty()) << endl;
	cout << format("Array size = {}", arr.size()) << endl;
	cout << format("First element = {}", arr.front()) << endl;
	cout << format("Last element = {}", arr.back()) << endl;

	return 0;
}