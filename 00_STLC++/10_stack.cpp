/*
Stack Data structure:
-- also known as container adopter.
-- cause we need array or vector or linked list to implement stack.
-- follows LIFO: last in fast out.
*/
#include <iostream>
#include <string>
#include <stack> // header file for stack.

using namespace std;

int main()
{
    // syntax to declare a stack:
    // stack<dataType>stackName;
    stack<int> s;
    s.push(4);
    s.push(8);
    s.push(11);
    s.push(3);

    cout << "size of stack: " << s.size() << endl;
    cout << s.top() << endl; // 20
    // remove element from top
    s.pop();
    cout << s.top() << endl; // 5

    // it is not supporting here but supported in set
    // s.clear().
    // checking if stack is empty.
    if (s.empty())
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        cout << "stack is not empty" << endl;
    }
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