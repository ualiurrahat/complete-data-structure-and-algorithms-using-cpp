/*
in set, duplicate elements will be removed.
in multiset, it wont be.

*/
#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    // set is just like a mathematical set.

    multiset<int> s; // s = {10,5,30,2} => s={2,2,2,5,10,30};
    s.insert(10);
    s.insert(5);
    s.insert(30);
    s.insert(2);
    s.insert(2);
    s.insert(2);
    cout << s.size() << endl;

    // now lets check if 8 and 2 is in the set or not.
    auto it = s.find(8);
    if (it != s.end())
    {
        cout << " 8 is present" << endl;
    }
    else
    {
        cout << "8 not present" << endl;
    }

    it = s.find(2);
    if (it != s.end())
    {
        cout << "2 is present" << endl;
    }
    else
    {
        cout << "2 not present" << endl;
    }

    // lets see how many 2's are there in the set.
    int count = s.count(2);
    cout << count << endl; // see. 2 is only 1 time here even though mentioned 3 time.

    // displayint the set.
    cout << "s = { ";
    for (it = s.begin(); it != s.end(); it++)
    {
        cout << (*it) << ", ";
    }
    cout << " }" << endl;

    // let's try to empty the set s.

    s.clear();
    if (s.empty())
    {
        cout << "multiset s is empty." << endl;
    }
    else
    {
        cout << "multiset  is not empty." << endl;
    }

    return 0;
}