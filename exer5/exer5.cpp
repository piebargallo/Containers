/* Bonus: Can you convert your average() function into a function template? The function template should only be 
   instantiable with integral or floating-point types. What effect does it have on your test code in main()? */

#include <vector>
#include <array>
#include <span>
#include <iostream>
#include <concepts>

using namespace std;

template <typename T> requires integral<T> || floating_point<T> // Type constraints: see Chapter 12
double average(span<const T> values)
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
	//// The parameter of the function template is span<const T>.
	//// This cannot be automatically deduced from the function arguments.
	//// So, we need to specify the template type argument explicitly.
	cout << average<double>(values1) << endl;

	array<int, 4> values2{ 1, 2, 3, 4 };
	cout << average<int>(values2) << endl;
	cout << average<int>({ values2.data() + 2, 2 }) << endl;
}
