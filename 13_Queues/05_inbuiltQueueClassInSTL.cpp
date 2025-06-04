/*
queue - container adaptor.
FIFO : First In First Out (First element pushed is the first one to be popped)

STL queue provides efficient queue implementation with the following key operations:
 - push(element): insert element at the back of the queue (enqueue)
 - pop(): remove the front element of the queue (dequeue)
 - front(): access the front element
 - back(): access the last element
 - size(): returns the number of elements in the queue
 - empty(): checks whether the queue is empty

Note: queue does not provide iterators, because the internal order can only be accessed from front and back.

All operations have time complexity O(1).

*/

#include <iostream>
#include <string>
#include <queue> // STL queue header

using namespace std;

int main()
{
    // Create a queue of integers
    queue<int> q;

    // Inserting elements into queue using push()
    q.push(18); // queue: 18
    q.push(1);  // queue: 18, 1
    q.push(8);  // queue: 18, 1, 8
    q.push(25); // queue: 18, 1, 8, 25
    q.push(20); // queue: 18, 1, 8, 25, 20

    // Accessing front and back elements
    cout << "Front element: " << q.front() << " "; // should print 18 (FIFO)
    cout << "Back element: " << q.back() << endl;  // should print 20

    // Removing the front element (dequeue)
    q.pop(); // removes 18; queue now: 1, 8, 25, 20

    // Checking the new front element after pop
    cout << "New front element after one pop: " << q.front() << endl; // should print 1

    // Size of the queue
    cout << "Queue size: " << q.size() << endl; // should print 4

    // Additional useful queue operations:

    // Checking if queue is empty
    if (q.empty())
        cout << "Queue is empty." << endl;
    else
        cout << "Queue is NOT empty." << endl;

    // Let's clear the queue by popping all elements (to demonstrate empty)
    cout << "Clearing queue elements..." << endl;
    while (!q.empty())
    {
        cout << "Removing element: " << q.front() << endl;
        q.pop();
    }

    // After clearing, check if empty again
    if (q.empty())
    {
        cout << "Queue is empty now." << endl;
    }
    else
    {
        cout << "Queue is still NOT empty." << endl;
    }

    // Note:
    // There is no direct way to iterate through the queue elements.
    // To access all elements, you must pop them in FIFO order.

    return 0;
}
