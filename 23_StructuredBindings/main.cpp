#include <array>
#include <utility>
#include <iostream>
#include <format>

using std::cout;
using std::format;
using std::endl;

int main()
{
	{
		// Structured bindings with std::array.
		std::array values{ 11, 22, 33 };
		auto [x, y, z] { values };
		cout << format("Value x, y, z: {}, {}, {}", x, y, z) << endl;
	}

	{
		// Structured bindings with struct.
		struct Point { double m_x, m_y, m_z; };
		Point point;
		point.m_x = 1.0; point.m_y = 2.0; point.m_z = 3.0;
		auto [x, y, z] { point };
		cout << format("Value m_x, m_y, m_z: {}, {}, {}", x, y, z) << endl;
	}

	{
		// Structured bindings with std::pair.
		std::pair myPair{ "hello", 5 };
		auto [theString, theInt] { myPair };  // Decompose using structured bindings
		cout << format("theString: {}", theString) << endl;
		cout << format("theInt: {}", theInt) << endl;
	}
	
	return 0;
}
