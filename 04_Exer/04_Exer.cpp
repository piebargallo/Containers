/* Write a lambda expression returning the sum of two paramters. The lambda expression should work with
   with all kind of data types, such as integral types and floating-point types. Try out your lambda
   expression by calculating the sum of 11 and 22, and 1.1 and 1.2. */

#include <iostream>
using std::cout;
using std::endl;

int main()
{
	auto sum{ [](auto a, auto b) { return a + b; } };
	cout << sum(11, 22) << endl;
	cout << sum(1.1, 2.2) << endl;
}