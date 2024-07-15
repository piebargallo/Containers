export module derived_simple;

export import simple;

// A class derived from the simple class.
export class DerivedSimple : public Simple
{
public:
	DerivedSimple() : Simple{} // Constructor
	{ /* Implementation of constructor */ }

	void publicMethod() override // Overridden method
	{
		// Implementation of overriden method
		Simple::publicMethod();  // You can access base class implentations.
	}

	virtual void anotherMethod() // New method
	{ /* Implementation of new method */ }
};