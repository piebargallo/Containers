#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

template<typename T>
void printVector(const vector<T>& v)
{
	for (auto& element : v)
	{
		cout << element << " ";
	}
	cout << endl;
}

int main()
{
	vector vectorOne{ 1, 2, 3, 5 };
	
	// Add elements 6 through 10 to vectorOne
	for (int i{ 6 }; i <= 10; i++) {
		vectorOne.push_back(i);
	}

	printVector(vectorOne);
	
	return 0;
}
