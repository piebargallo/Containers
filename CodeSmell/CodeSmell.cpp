// Code smell: In computer programming, a code smell is any
// characteristic in the source code of a program that possibly
// indicates a deeper problem

// Code smell:
// * might indicate a deeper problem
// * should be avoided

// code smell does *not* mean:
// * never do this thing

#include <vector>

struct Widget {
	std::vector<int> thingies;
};

static constexpr int thingy_offset_for_fizzling = 4;

// this function Fizzles the Widget
void fizzle_widget(Widget& w)
{
	/* loop over each thingy
	// make sure the thingy is fizzled
	// to match the rest of the widget thingies
	for (auto& thingy : w.thingies) {
		// perfom complex operations
		thingy += 4;
	}*/
	auto update_thingy_fizzling = [](auto& thingy) {
		thingy += thingy_offset_for_fizzling;
		};

	for (auto& thingy : w.thingies) {
		update_thingy_fizzling(thingy);
	}
}

int main()
{}