#include <iostream>
#include <forward_list>

int main()
{
	// Declaring forward list
	std::forward_list<int> flist1;

	// Assigning values using assign()
	flist1.assign({ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 });

	// Displaying forward list
	for (auto a : flist1)
		std::cout << a << " ";
	std::cout << std::endl;
	
	return 0;
}
