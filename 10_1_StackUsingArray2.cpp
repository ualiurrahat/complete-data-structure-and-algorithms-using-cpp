#include <bits/stdc++.h>
#include "10_0_stackUsingArrayClass2.cpp"

using namespace std;

int main()
{
    // checking stack with array
    StackUsingArray s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(100);

    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;

    cout << s.size() << endl;
    cout << s.isEmpty() << endl;

        return 0;
}