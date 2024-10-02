// Uso del método swap()
#include <vector>
using std::vector;

int main()
{
	vector intVector{ 5, 6, 7, 8 };
	vector intVectorTwo{ 1, 2, 3, 4 };

	intVector.swap(intVectorTwo);
	return 0;
}
