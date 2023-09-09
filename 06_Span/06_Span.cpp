// C++ program to illustrate the use of std::span
#include <iostream>
#include <span>

int main()
{
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// Create a span of int of array
	std::span<int> span_arr(arr);

	for (const auto& num : span_arr) 
		std::cout << num << " ";
	std::cout << std::endl;
	
	return 0;
}
