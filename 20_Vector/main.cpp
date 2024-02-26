#include <iostream>
#include <format>
#include <vector>

using std::vector;
using std::cout;
using std::format;
using std::endl;

int main()
{
	// Create a vector of integers.
	vector vec{ 11, 22 };

	// Add some more integers to the vector using push_back().
	vec.push_back(33);
	vec.push_back(44);

	cout << format("Bacuo = {}", vec.empty()) << endl;
	cout << format("Second element = {}", vec[1]) << endl;
	cout << format("First element = {}", vec.front()) << endl;
	cout << format("Last element = {}", vec.back()) << endl;

	return 0;
}