// bitset in STL C++
// takes 1 bit space for each bit.
#include <bits/stdc++.h>

using namespace std;

int main()
{

    bitset<5> bt; // 10110
    // 5 spaces for a bitset variable called bit;
    // bitset only stores 1 or 0

    cout << "enter your bit: ";
    cin >> bt;

    // all
    cout << "all(): " << bt.all() << endl;
    // all() : if all bits are set, returns true, either false.

    // any
    cout << "any(): " << bt.any() << endl;
    // any():if even a bit is set, ther returns true, either false.

    // count
    cout << "count: " << bt.count() << endl;
    // returns total number of setbit or 1.

    // flip
    cout << "flip at index 2: " << bt.flip(2) << endl;
    // converts the bit 1 to 0 and 0 to 1.

    // none
    cout << "none(): " << bt.none() << endl;
    // returns true if no bit is set, either false

    // set
    cout << "set at (1):" << bt.set(1) << endl;
    // sets the index 1 only(index starts from 0).

    cout << "set all bit: " << bt.set() << endl;
    // sets the whole bit.

    cout << "set 0 at (0): " << bt.set(0, 0) << endl;
    // set 0 at index 0

    // reset
    cout << "reset all: " << bt.reset() << endl;
    // turns all indexes to 0
    cout << "reset at (4): " << bt.reset(4) << endl;
    // size
    cout << "size: " << bt.size() << endl;

    // test
    cout << "test at (3): " << bt.test(3) << endl;
    // checks if bit is set or not at index 3

    return 0;
}