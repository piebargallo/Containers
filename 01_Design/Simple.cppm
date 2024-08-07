/* Building sample class. */

export module simple;

// A simple class that illustrates class definition syntax.
export class Simple
{
public:
	Simple();  // Constructor
	virtual ~Simple() = default;  // Defaulted virtual destructor

	// Disallow assignment and pass-by-value
	Simple(const Simple& src) = delete;
	Simple& operator=(const Simple& rhs) = delete;

	// Explicitly default move constructor and move assignment operator
	Simple(Simple&& src) noexcept = default;
	Simple& operator=(Simple&& rhs) noexcept = default;

	virtual void publicMethod(); // Public method
	int m_publicInteger;  // Public data member

protected:
	virtual void protectedMethod();  // Protected method
	int m_protectedInteger{ 41 };  // Prptected data method

private:
	virtual void privateMethod();  // Private method
	int m_privateInteger{ 42 };  // Private data member
	static const int Constant{ 2 };  // Private constant
	static inline int ms_staticInt{ 3 };  // Private static data member
};