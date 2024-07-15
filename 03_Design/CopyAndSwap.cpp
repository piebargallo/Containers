module copy_and_swap;

CopyAndSwap::~CopyAndSwap() { /* Implementation of destructor */ }

CopyAndSwap::CopyAndSwap(const CopyAndSwap& src)
{
	// This copy constructor can first delegate to a non-copy constructor
	// if any resource allocation have to be done. See the Spreadsheet
	// Implementation in chapter 9 for an example.

	// Make a copy of all data members...
}

void swap(CopyAndSwap& first, CopyAndSwap& second) noexcept
{
	first.swap(second);
}

void CopyAndSwap::swap(CopyAndSwap& other) noexcept
{
	using std::swap; // requires <utility>

	// Swap each data member, for a example:
	// swap(m_data, other.m_data);
}

CopyAndSwap& CopyAndSwap::operator=(const CopyAndSwap& rhs)
{
	// Copy-and-Swap idiom.
	auto copy{ rhs }; // Do all the work in a temporary instance.
	swap(copy);  // Commit the work with only non-throwing operations
	return *this;
}

