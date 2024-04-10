/* This exercise is to practice working with vectors. Create a program containing a vector og ints, called values,
   initialized with the numbers 2 and 5. Next, implement the following operations:
   1. Use insert() to insert the numbers 3 and 4 at the correct place in values.
   2. Create a second vector of ints initialized with 0 and 1, and then insert the contents of this new vector
   at the beginning of values.
   3. Create a third vector of ints. Loop over the elements of values in reverse, and insert them in this third vector.
   4. Print the contents of the third vector using a range-based for loop. */

#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;

int main()
{
	vector<int> values{ 2, 5 };

	// 1
	values.insert(begin(values) + 1, 3);
	values.insert(begin(values) + 2, 4);

	// 2
	vector<int> v2{ 0, 1 };
	values.insert(begin(values), cbegin(v2), cend(v2));

	// 3
	vector<int> v3;
	for (auto riter{ crbegin(values) }; riter != crend(values); ++riter) {
		v3.push_back(*riter);
	}

	// 4
	for (const auto& element : v3) {
		cout << element << " ";
	}
	cout << endl;
}
