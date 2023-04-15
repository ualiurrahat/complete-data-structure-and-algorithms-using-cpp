#include <bits/stdc++.h>

using namespace std;

int main()
{

    queue<int> q;
    // there is no iterator in stack and queue.

    // operation:
    // front
    // push
    // pop
    // size
    // empty
    // T:O(1)

    q.push(18);
    q.push(1);
    q.push(8);
    q.push(5);
    q.push(20);

    cout << "size: " << q.size() << endl;
    cout << "front: " << q.front() << endl;
    q.pop();
    cout << "size after 1 pop: " << q.size() << endl;
    cout << "front after 1 pop: " << q.front() << endl;

    // delete the entire queue
    // T: O(size)
    while (!q.empty())
    {
        q.pop();
    }

    if (q.empty())
    {
        cout << "queue is empty" << endl;
    }
    return 0;
}