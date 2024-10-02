#include <cstddef>
#include <vector>
#include <iostream>
#include <limits>
#include <format>

using namespace std;

int main()
{
	vector<double> doubleVector;
	// Initialize max to smallest number
	double max{ -numeric_limits<double>::infinity() };

	for (size_t i{ 1 }; true; i++) {
		double temp;
		cout << format("Enter score {} (-1 to stop): ", i);
		cin >> temp;
		if (temp == -1) {
			break;
		}
		doubleVector.push_back(temp);
		if (temp > max) {
			max = temp;
		}
	}

	max /= 100.0;

	// Using auto keyword
	for (auto iter{ begin(doubleVector) };
		iter != end(doubleVector); ++iter) {
		*iter /= max;
		cout << *iter << " ";
	}
	cout << endl;
}
