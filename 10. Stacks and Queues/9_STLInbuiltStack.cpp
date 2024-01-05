// we will use c++ STL stack in this code.
#include <iostream>
// stl stack header file.
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
    cout << s.top() << endl;  // 50
    cout << s.size() << endl; // 5
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout << s.top() << endl;   // 10
    cout << s.size() << endl;  // 1
    cout << s.empty() << endl; // 0

    return 0;
}