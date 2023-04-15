//#include <bits/stdc++.h>
#include <set>
#include <iostream>
#include <unordered_set>

using namespace std;

// set contains elements in linearly ascending orders
// set only stores unique elements. does not contain duplicates of elements
// dot operation on index(set.[0]) is not permitted
// all the functions work in logarithmic time complexity

int main()
{
    // given n elements find total unique numbers.
    // ex: a[] = {18,1,8,1,20}....ans = 4

    int a[] = {20, 1, 13, 1, 14, 14, 1, 18, 1, 8, 1, 20};
    int size = sizeof(a) / sizeof(a[0]);
    set<int> s;

    for (int i = 0; i < size; i++)
    {
        s.insert(a[i]);
    }

    // printing set
    // for (int i = 0; i < s.size(); i++)
    // {
    //     cout << s[i] << " " << endl;
    // } cant use it as s[i] is not permitted

    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "unique numbers: " << s.size() << endl;

    // erase in set: set_name.erase(iterator)
    s.erase(s.begin()); // first element deleted

    cout << "Set after deleting first element: ";
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // we cant use + or - operator in set
    // s.erase(s.begin() + 2) is not allowed

    // erasing a particular element
    s.erase(13);
    cout << "set after deleting 13: ";
    cout << endl;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }

    set<int> s2 = {10, 20, 30, 40, 50};
    set<int> s3 = s2;
    set<int> s4(s.begin(), s.end());
    cout << endl;
    for (auto it = s2.begin(); it != s2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    for (auto it = s3.begin(); it != s3.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    for (auto it = s4.begin(); it != s4.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // find
    auto it = s2.find(30); // iterator point to 30

    auto it2 = s2.find(100); // iterator will point to s2.end()

    // insert = emplace    s2.emplace(25)

    // delete entire set
    s2.erase(s2.begin(), s2.end());
    cout << s2.empty() << endl;

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

    cout << "size of ms: " << ms.size() << endl;
    // ms-> 1 1 2 3 3 4

    // find how many times 1 occurs
    cout << "total 1 in ms: " << ms.count(1) << endl;

    for (auto it : ms)
    {
        cout << it << " ";
    }
    cout << endl;

    ms.erase(2);
    auto iter = ms.find(3); // pointing to the iterator pointing to 3
    // cout << *iter << endl;

    ms.erase(1);
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