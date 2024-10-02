// User-definer classes

#include <vector>
using std::vector;

class Element
{
public:
	Element() {}
	virtual ~Element() = default;
};

int main()
{
	vector<Element> elementVector;
}
