/* Write an average() function (not a function template) to calculate the average of a sequence of double values.
   Make sure it works with a sequence or subsequence from a vector or an array. Test your code with both a vector
   and an array in you main() function. */

#include <vector>
#include <array>
#include <span>
#include <iostream>
using std::vector;
using std::array;
using std::span;
using std::cout;
using std::endl;

double average(span<const double> values)
{
	double sum{ 0.0 };
	for (auto& value : values) {
		sum += value;
	}
	return sum / values.size();
}

int main()
{
	vector values1{ 1.1, 2.2, 3.3, 4.4 };
	cout << average(values1) << endl;

	array<double, 4> values2{ 1.1, 2.2, 3.3, 4.4 };
	cout << average(values2) << endl;
	cout << average({ values2.data() + 2, 2 }) << endl;
}

   
   