#include <iostream>
#include <optional>

using std::optional;
using std::cout;
using std::endl;


optional<int> getData(bool giveIt)
{
	if (giveIt) {
		return 42;
	}

	return std::nullopt;  // or simply return {};
}

int main()
{
	optional<int> data1{ getData(true) };
	optional<int> data2{ getData(false) };

	cout << "data1.has_value = " << data1.has_value() << endl;
	if (data2) {
		cout << "data2 has a value." << endl;
	}

	cout << "data1.value = " << data1.value() << endl;
	cout << "data1.value = " << *data1 << endl;

	try {
		cout << "data2.value = " << data2.value() << endl;
	}
	catch (const std::bad_optional_access& ex) {
		cout << "Exception: " << ex.what() << endl;
	}

	cout << "data2.value = " << data2.value_or(0) << endl;

	return 0;
}