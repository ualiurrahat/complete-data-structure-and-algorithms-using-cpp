// Iterators are like pointers like structure
// it locates the position of elements in STL containers
// v.begin() -> location just before of the first element
// v.end() -> points out the location next to last element
// it++ -> next iterator
// it+1 -> next location
// since vector is given continuous memory allocation,
// so it++ and it + 1 is same here,
// but for other containers like Map,
// it++ means location of next element
// it+1 means next location
// NOTE: use it++ to find iterator of the next element in container
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    vector<int> v = {10, 20, 30, 40, 50};
    // printing vector elements
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    // vector iterator
    vector<int>::iterator it;
    cout << "printing using iterator: ";
    // printing vector elements using iterator
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // taking vector of pairs
    vector<pair<int, int>> p = {{1, 10}, {2, 20}, {3, 30}};
    // iterator for vector of pairs
    vector<pair<int, int>>::iterator it2;
    // accessing pairs using iterator
    cout << "pair using iterator: " << endl;
    for (it2 = p.begin(); it2 != p.end(); it2++)
    {
        cout << it2->first << " " << it2->second << endl;
        // cout << (*it2).first << " " << (*it2).second << endl;
        // it2->first == (*it2).first .....they are like same
    }

    return 0;
}