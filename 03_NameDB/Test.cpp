import NameDB;
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	NameDB boys{ "boys_long.txt" };

	cout << boys.getNameRank("Daniel") << endl;
	cout << boys.getNameRank("Jacob") << endl;
	cout << boys.getNameRank("William") << endl;
}
