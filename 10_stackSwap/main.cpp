
// CPP program to illustrate 
// Implementation of swap() function 
#include <stack> 
#include <iostream> 

int main()
{
	std::stack<int> mystack1;
	std::stack<int> mystack2;

	mystack1.push(1);
	mystack1.push(2);
	mystack1.push(3);
	mystack1.push(4);

	mystack2.push(3);
	mystack2.push(5);
	mystack2.push(7);
	mystack2.push(9);

	// using swap() function to swap elements of stacks 
	mystack1.swap(mystack2);

	std::cout << "mystack1 = ";
	while (!mystack1.empty()) {
		std::cout << mystack1.top() << " ";
		mystack1.pop();
	}

	std::cout << std::endl << "mystack2 = ";
	while (!mystack2.empty()) {
		std::cout << mystack2.top() << " ";
		mystack2.pop();
	}
	return 0;
}

/* Output:
	9753
	4321 */
