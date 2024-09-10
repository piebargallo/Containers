#include <cstdint>
#include <cstddef>
#include <array>
#include <iostream>
#include <format>
using namespace std;

template<typename Contained, std::size_t Size>
struct array {
	Contained _values[Size];

	constexpr Contained& operator[](std::size_t idx) {
		return _values[idx];
	}

	constexpr Contained *begin() {
		return _values;
	}

	constexpr Contained *end() {
		return _values + Size;
	}

	constexpr Contained *begin() const {
		return _values;
	}

	constexpr Contained *end() const {
		return _values + Size;
	}

	constexpr Contained *cbegin() const {
		return _values;
	}

	constexpr Contained *cend() const {
		return _values + Size;
	}

	constexpr Contained &front() { return *_values; }
	constexpr const Contained &front() { return *_values; }
};

int main()
{
	std::array<int, 5> data{ 2,3,4,5,6 };

	for (auto value : data) {
		cout << format("{} ", value);
	}

	return data[0];
}