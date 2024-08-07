/* Write an RAII class template, pointer, that can store a pointer to any type of object and automatically
   deletes the memory when such an RAII instance goes out of scope.
   Provide a reset() and release() method, and a overloader operator. */

#include <iostream>

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

private:
	T* m_data{ nullptr };
};

template <typename T>
Pointer<T>::Pointer(T* data) : m_data{ data }
{
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

int main()
{
	Pointer pointer{ new int{ 42 } };
	cout << *pointer << endl;
}
