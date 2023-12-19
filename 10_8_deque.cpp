#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> d;
    d.push_front(18);
    d.push_back(1);
    d.push_front(20);
    // deque: 20 18 1
    cout << d.front() << endl;
    cout << d.back() << endl;

    d.pop_back(); // 1 is removed
    cout << d.back() << endl;
    d.pop_front(); // 20 is removed
    cout << d.front() << endl;
    cout << d.size() << endl;

    return 0;
}