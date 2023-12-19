// inbuilt stack.
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << s.top() << endl;
    cout << s.size() << endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout << s.top()<< endl;
    cout << s.size()<< endl;
    cout << s.empty() << endl;

    return 0;
}