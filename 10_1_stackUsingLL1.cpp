#include <bits/stdc++.h>
#include "10_0_stackUsingLLClass4.cpp"

using namespace std;

int main()
{
    Stack<char> s;
    s.push('r');
    s.push('a');
    s.push('h');
    s.push('a');
    s.push('t');
    cout << s.getSize() << endl;

    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.getSize() << endl;

    cout << s.isEmpty() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.isEmpty() << endl;

    return 0;
}