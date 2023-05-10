// #include <bits/stdc++.h>
#include <set>
#include <iostream>

using namespace std;

int main()
{
    // given n elements find total unique numbers.
    // ex: a[] = {18,1,8,1,20}....ans = 4

    int a[] = {20, 1, 13, 1, 14, 14, 1, 18, 1, 8, 1, 20};
    int size = sizeof(a) / sizeof(a[0]);
    set<int> s;
    // inserting elements in set
    for (int i = 0; i < size; i++)
    {
        s.insert(a[i]);
    }
    // printing elements
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

    // we can not use + or - operator in set
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
    // ways of coping set
    // way 1
    set<int> s3 = s2;
    // way 2
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

    return 0;
}