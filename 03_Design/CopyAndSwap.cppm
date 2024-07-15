/* Copy-and-Swap idiom. */

export module copy_and_swap;

import <utility>;

export class CopyAndSwap
{
public:
	CopyAndSwap() = default;
	virtual ~CopyAndSwap(); // Virtual destructor

	CopyAndSwap(const CopyAndSwap& src); // Copy constructor
	CopyAndSwap& operator=(const CopyAndSwap& rhs); // Copy assignment operator

	void swap(CopyAndSwap& other) noexcept;  // noexcept swap() method

private:
	// Private data members...
};

// Standalone no except swap() function
export void swap(CopyAndSwap& first, CopyAndSwap& second) noexcept;