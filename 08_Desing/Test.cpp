import simple_wrapper;
#include <iostream>
#include <string>

using namespace std;

int main()
{
	// Try wrapping an integer
	int i{ 7 };
	SimpleWrapper intWrapper{ i };  // Using CTAD.
	// Or without class template argument deduction (CTAD).
	//SimpleWrapper<int> intWrapper{ i };
	i = 2;
	cout << "wrapped value is " << intWrapper.get() << endl;
}
