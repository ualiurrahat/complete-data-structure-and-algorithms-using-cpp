
#include <iostream>
// header file to use array from STL
#include <array>
#include <string>

using namespace std;

// max size of global array
// 10^7 -> int,double,char
// 10^8 -> bool

int main()
{
    // max size of array inside int main()
    // 10^6 -> int,double,char etc
    // 10^7 -> bool
    int ara[5] = {1}; // {1,0,0,0,0}
    // only zeroth index gets one, all other gets 0.
    cout << "ara = ";
    for (int i = 0; i < 5; i++)
    {
        cout << ara[i] << " ";
    }
    cout << endl;
    // creating array using STL array class
    array<int, 5> a;
    // creates an array 'a' of int number of 5 lengths
    a.fill(8); // all elements will have 8
    cout << "a = ";
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    // iterators
    // begin(), end(), rbegin(), rend()
    // begin(): first element
    // end(): points empty address right after the last element.
    // rend() : position before the start element
    // rbegin() : last element

    array<int, 5> b;
    b = {18, 1, 8, 1, 20};
    cout << "b = ";
    for (auto it = b.begin(); it != b.end(); it++)
    {
        cout << *it << " ";
        // 18 1 8 1 20
    }
    cout << endl;

    // reverse traversal with reverse iterator
    cout << "b in reverse order: ";
    for (auto it = b.rbegin(); it != b.rend(); it++)
    {
        cout << *it << " ";
        // 20 1 8 1 18
    }
    cout << endl;

    // reverse traversal with non-reverse iterator
    // for (auto it = b.end() - 1; it >= b.begin(); it--)
    // {
    //     cout << *it << " ";
    //     // 20 1 8 1 18
    // }
    cout << endl;

    // for each loop
    // auto element iterator
    // always work on forward path...goes first to last element
    // for (auto it : b)
    // {
    //     cout << it << " ";
    //     // 18 1 8 1 20
    // }
    cout << endl;

    string name = "ahnaf";
    for (auto c : name)
    {
        cout << c << " ";
        // c is each character from name
        // prints: a h n a f
    }
    cout << endl;

    // size and max size
    cout << "size of b: " << b.size() << endl;
    cout << "max size of b: " << b.max_size() << endl;

    // front and back element
    cout << "front element of b: " << b.front() << endl; // 18 since b = 18 1 8 1 20
    cout << "back element of b: " << b.back() << endl;   // 20
    cout << b.at(b.size() - 1) << endl;                  // 20

    return 0;
}