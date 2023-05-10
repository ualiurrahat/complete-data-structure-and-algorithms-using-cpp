// set in c++ stl.
/*
1. set is an associative container that contains a sorted set of unique objects of type key.
2. it is actually implemented using Red Black Tree(RBT)
3. If we want to keep user defined data type in set, then we will have to
   provide compare function so that we can store them in sorted order.
set:
--> the result are sorted.
--> use Red Band Tree(RBT) in backdrop.
--> complexity: O(logn);

unordered set:
--> not sorted.
--> use Hashset.
--> O(1).

*/
#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    // set is just like a mathematical set.
    // syntax : set<T>objectName;
    set<int> s;
    // s = {10,5,30,2};
    // set convert this into,   s={2,5,10,30};
    s.insert(10);
    s.insert(5);
    s.insert(30);
    s.insert(2);
    s.insert(2);
    // though we tried to insert 2 twice, only one time will be inserted inside the set
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
    cout << count << endl;
    // see. 2 is only 1 time here even though mentioned 3 time.

    // set contains elements in linearly ascending orders
    // set only stores unique elements. does not contain duplicates of elements
    // dot operation on index(set.[0]) is not permitted
    // all the functions work in logarithmic time complexity
    // printing set:  we can not use this
    // for (int i = 0; i < s.size(); i++)
    // {
    //     cout << s[i] << " " << endl;
    // } cant use it as s[i] is not permitted
    // displaying the set.
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
        cout << "set s is empty." << endl;
    }
    else
    {
        cout << "s is not empty." << endl;
    }

    return 0;
}