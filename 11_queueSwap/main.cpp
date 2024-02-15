// CPP program to illustrate
// Implementation of swap() function
#include <iostream>
#include <queue>

int main()
{
	// Take any two queues
	std::queue<char> queue1, queue2;
	int v = 96;
	for (int i = 0; i < 5; i++) {
		queue1.push(v + 1);
		v++;
	}

	for (int i = 0; i < 4; i++) {
		queue2.push(v + 1);
		v++;
	}

	// Swap elements of queues
	queue1.swap(queue2);

	std::cout << "queue1 = ";
	while (!queue1.empty()) {
		std::cout << queue1.front() << " ";
		queue1.pop();
	}

	std::cout << std::endl << "queue2 = ";
	while (!queue2.empty()) {
		std::cout << queue2.front() << " ";
		queue2.pop();
	}

	return 0;
}
