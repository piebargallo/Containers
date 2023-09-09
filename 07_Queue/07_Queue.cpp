// CPP code to illustrate Queue in
// Standard Template Library (STL)
#include <iostream>
#include <queue>

// Print the queue
void showq(std::queue<int> gq)
{
	std::queue<int> g = gq;
	while (!g.empty()) {
		std::cout << " " << g.front();
		g.pop();
	}
	std::cout << std::endl;
}

int main()
{
	std::queue<int> gquiz;
	gquiz.push(0);
	gquiz.push(1);
	gquiz.push(2);
	gquiz.push(3);
	gquiz.push(4);
	gquiz.push(5);
	gquiz.push(6);
	gquiz.push(7);
	gquiz.push(8);
	gquiz.push(9);

	showq(gquiz);

	return 0;
}
