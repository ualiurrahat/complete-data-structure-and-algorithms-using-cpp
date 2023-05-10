#include <iostream>
#include <unordered_set>
#include <set>
using namespace std;

int main()
{
    
    // unordered set: no order in storing elements
    // does it arbitrarily
    // avg time complexity: O(1)
    // worst time complexity : O(set size)

    // note: if you don't need to store elements in sequential order
    // use unordered set
    // if get TLE -> switch to set
    unordered_set<int> un;

    un.insert(100);
    un.insert(200);
    un.insert(300);

    for (auto it : un)
    {
        cout << it << " ";
    }
    cout << endl;

    // multiset stores duplicate elements in sorted fashion
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    ms.insert(3);
    ms.insert(3);
    ms.insert(4);
    ms.insert(25);
    ms.insert(25);
    ms.insert(25);
    ms.insert(25);

    cout << "size of ms: " << ms.size() << endl;
    // ms-> 1 1 2 3 3 4

    // find how many times 1 occurs
    cout << "total 1 in ms: " << ms.count(1) << endl;

    for (auto it : ms)
    {
        cout << it << " ";
    }
    cout << endl;

    // deleting element from multiset
    // 1. if we pass only a value, multiset will delete all the elements containing the same value
    // 2. but if we delete using iterator, multiset will delete just the first appearance of that value.
    // setName.erase(element)
    ms.erase(25); 
    // deleted all the 25
    auto iter = ms.find(2); // pointing to the iterator pointing to 3
    // cout << *iter << endl;
    ms.erase(iter);
    for (auto it : ms)
    {
        cout << it << " ";
    }
    cout << endl;

    // delete whole ms
    ms.clear();
    // ms.erase(ms.begin(), ms.end());

    if (ms.empty() == 1)
    {
        cout << "ms is empty" << endl;
    }

    // notes on multiset:
    // no unoredered multiset
    // logn times
    // stores duplicates too.

    return 0;
}