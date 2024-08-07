/* Take your solution from... and add a method template called assign(), accepting an argument of type E, 
   and assigning this argument to the data to wich the wrapped pointer is pointing to. Add a constraint to
   the method template to make sure type E is convertible to type T. */

#include <iostream>
#include <stdexcept>
#include <concepts>

using namespace std;

template <typename T>
class Pointer final
{
public:
	explicit Pointer(T* data);
	~Pointer();

	// Prevent copy construction and copy assignment.
	Pointer(const Pointer& src) = delete;
	Pointer& operator=(const Pointer& rhs) = delete;

	// Allow move construction and move assignment.
	Pointer(Pointer&& src) noexcept = default;
	Pointer& operator=(Pointer&& rhs) noexcept = default;

	T& operator*() noexcept;
	const T& operator*() const noexcept;

	[[nodiscard]] T* release() noexcept;
	void reset(T* data = nullptr) noexcept;

	template <convertible_to<T> E>
	void assign(const E& value);

private:
	T* m_data{ nullptr };
};

template <typename T>
Pointer<T>::Pointer(T* data) : m_data{ data }
{
	if (data == nullptr) {
		throw invalid_argument{ "Data cannot be null." };
	}
}

template <typename T>
Pointer<T>::~Pointer()
{
	reset();
}

template <typename T>
T& Pointer<T>::operator*() noexcept
{
	return *m_data;
}

template <typename T>
const T& Pointer<T>::operator*() const noexcept
{
	return *m_data;
}

template <typename T>
T* Pointer<T>::release() noexcept
{
	T* data{ m_data };
	m_data = nullptr;
	return data;
}

template <typename T>
void Pointer<T>::reset(T* data /*= nullptr*/) noexcept
{
	if (m_data) {
		delete m_data;
	}
	m_data = data;
}

template <typename T>
template <convertible_to<T> E>
void Pointer<T>::assign(const E& value)
{
	if (m_data) {
		*m_data = value;
	}
}

int main()
{
	Pointer pointer{ new int{ 42 } };
	cout << *pointer << endl;
	pointer.assign(11u);
	cout << *pointer << endl;
}
