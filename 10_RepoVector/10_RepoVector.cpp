// Free store vectors smart pointer
#include <vector>
#include <memory>

using std::vector;
using std::make_unique;

class Element
{
public:
	Element() {}
	virtual ~Element() = default;
};

int main()
{
	auto elementVector{ make_unique<vector<Element>>(10) };
}