/* Writing a Class Template. */

export module simple_wraper;

export template <typename T>
class SimpleWrapper
{
public:
	SimpleWrapper(T& object) : m_object { object } {}
	T& get() { return m_object; }
private:
	T& m_object;
};