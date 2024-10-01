#include <iostream>
#include <valarray>
using std::valarray;
using std::cout;
using std::endl;

int main() {
    valarray<int> val1 = { 1, 2, 3, 4, 5 };
    valarray<int> val2 = { 6, 7, 8, 9, 10 };

    // Element-wise addition
    valarray<int> val3 = val1 + val2;

    // Print the result
    for (int i : val3) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
