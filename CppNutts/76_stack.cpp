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
    stack<int> s;
    s.push(4);
    s.push(8);
    s.push(11);
    s.push(3);

    cout << s.top() << endl;

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

    // check how to print full stack .....GFG article on C++ docs.

    return 0;
}