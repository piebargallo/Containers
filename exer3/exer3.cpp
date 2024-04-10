/* In exercise 15-1 you developed your own AssociativeArray. Modify the test cosde main() from that exercise to use
   one of the Standard Library constainers insteand. */

#include <unordered_map>
#include <string>
#include <iostream>
using std::unordered_map;
using std::string;
using std::cout;
using std::endl;

int main()
{
	unordered_map<string, int> myArray;
	myArray["Key 1"] = 11;
	myArray["Key 2"] = 22;
	myArray["Key 3"] = 33;

	cout << myArray["Key 1"] << endl;
	cout << myArray["Key 2"] << endl;

	//// std::unordered_map does not support operator[]
	//// on const instances.
	// Test const operator[]
	//const AssociativeArray<int>& c{ myArray };
	//cout << c["Key 3"] << endl;
	//cout << c["Key 4"] << endl;

	//// Instead, you can use find().
	const auto& c{ myArray };
	cout << c.find("Key 3")->second << endl;
	auto res{ c.find("Key 4") };
	if (res == end(c)) {
		cout << "Key 4 not found." << endl;
	}
}
