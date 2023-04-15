#include <bits/stdc++.h>

using namespace std;

int main()
{

    stack<int> s;
    // LIFO DS
    //push,pop,size,emtpy,top

    s.push(18);
    s.push(1);
    s.push(8);
    s.push(5);
    s.push(20);

    cout << "size of stack: " << s.size() << endl;
    cout << s.top() << endl; // 20
    s.pop();
    cout << s.top() << endl; // 5

    // delete entire stack

    while (!s.empty())
    {
        s.pop();
    }
    if (s.empty())
    {
        cout << "stack is empty" << endl;
    }

    // now stack is emtpy. so s.top will show error
    // cout << s.top() << endl;
    // always check before implementing s.top().

    return 0;
}