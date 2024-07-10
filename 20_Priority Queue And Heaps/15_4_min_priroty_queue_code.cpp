#include <bits/stdc++.h>
#include "15_3_min_priority_queue_class.cpp"

using namespace std;

int main()
{
    PriorityQueue p;
    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);

    cout << p.size() << endl;
    cout << p.getMin() << endl;

    while (p.size() != 0)
    {
        cout << p.removeMin() << " ";
    }
    cout << endl;

    return 0;
}