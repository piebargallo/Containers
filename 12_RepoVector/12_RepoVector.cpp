// Comparing vectors
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector vectorOne{ 1, 2, 3, 4 };
	vector vectorTwo{ 5, 6, 7, 8 };

	if (vectorOne == vectorTwo) {
		cout << "equal!" << endl;
	}
	else {
		cout << "not equal!" << endl;
	}

	return 0;
}