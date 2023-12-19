#include <bits/stdc++.h>
#include "10_0_stackUsingArrayClass3.cpp"

using namespace std;

int main()
{
    StackUsingArray<char> s;
    s.push('a');
    s.push('h');
    s.push('n');
    s.push('a');
    s.push('f');
    cout << s.size() << endl;

    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.size() << endl;

    cout << s.isEmpty() << endl;

    return 0;
}