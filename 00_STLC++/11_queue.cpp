/*
queue - container adaptor.
FIFO : First In First Out

*/
#include <iostream>
#include <string>
#include <queue> // header file for queue.

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
    q.push(25);
    q.push(20);

    cout << q.front() << " ";
    cout << q.back() << endl;
    q.pop();
    cout << q.front();
    cout << endl;
    cout << "size: " << q.size() << endl;

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