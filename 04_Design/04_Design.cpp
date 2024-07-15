/* Throw and Catch exceptions. */

#include <stdexcept>
#include <iostream>
using namespace std;

void throwIf(bool throwIt)
{
	if (throwIt) {
		throw runtime_error { "Here is my exception" };
	}
}

int main()
{
	try {
		throwIf(false); // Doesn´t throw.
		throwIf(true); // Throw.
	}
	catch (const runtime_error& e) {
		cerr << "Caught exception: " << e.what() << endl;
		return 1;
	}
}