#include <string>
#include <iostream>
#include <format>

using std::cout;
using std::format;
using std::endl;

int main()
{
	std::string myString{ "Hello, World" };
	cout << format("The value of myString is {}", myString) << endl;
	cout << format("The first letter is {}", myString[0]) << endl;
	return 0;
}
