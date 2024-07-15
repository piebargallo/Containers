import simple_wraper;

#include <iostream>
#include <string>

using namespace std;

int main()
{
	// Try wraping an integer.
	int i{ 7 };
	SimpleWrapper intWrapper{ i }; // Using CTAD.
	// Or without class template argument deduction (CTAD)
	// SimpleWrapper<int> intWrapper { i };
	i = 2;
	cout << "wrapper value is " << intWrapper.get() << endl;

	// Try wrapping a string.
	string str{ "test" };
	SimpleWrapper stringWrapper{ str };
	str += "!";
	cout << "wraped value is " << stringWrapper.get() << endl;
}
