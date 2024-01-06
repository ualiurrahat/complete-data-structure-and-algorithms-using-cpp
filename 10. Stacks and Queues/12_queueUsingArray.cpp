// we can implement queue data structure
// by linked list and array.
// here, implementing queue using static array.
// Since we are using static array, size will be an issue here.
// As we can not increse queue size.

#include <iostream>
using namespace std;

template <typename T>
class QueueUsingArray
{
private:
    T *data;        // array to store queue elements. generic data type
    int firstIndex; // index of front element
    int nextIndex;  //  index of next element
    int size;       // no. of elements present in queue.
    int capacity;   // capacity of queue

public:
    // constructor
    // takes size of queue from user
    QueueUsingArray(int totalSize)
    {
        // queue is being created.
        // creating array with size of totalSize to contain elements
        data = new T[totalSize];
        nextIndex = 0;        // since queue is empty. nextIndex of element is 0.
        firstIndex = -1;      // no front element in the queue. So -1 is initial value.
        size = 0;             // queue is empty. so size is 0.
        capacity = totalSize; // initial capacity
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    // insert elements
    void enqueue(T element)
    {
        // checking if queuse is full
        if (size == capacity)
        {
            // queue is full. enque not possible
            cout << "Queue is full!" << endl;
            return;
        }
        // inserting element in the queue
        data[nextIndex] = element;
        // updating nextIndex
        nextIndex = (nextIndex + 1) % capacity;
        // resetting firstIndex in case queue gets emptied.
        if (firstIndex == -1)
        {
            firstIndex = 0;
        }
        // updating size
        size++;
    }

    // get front element of queue
    T front()
    {
        // checking if queue is empty
        if (firstIndex == -1)
        {
            cout << "Queue is empty! No front element is there." << endl;
            // data type is generic. So returning 0 as standard value in case of front element.
            return 0;
        }
        return data[firstIndex];
    }

    // remove an element from queue
    T deque()
    {
        // if queue is empty
        if (isEmpty())
        {
            cout << "Queue is empty! Deque is not possible" << endl;
            return 0;
        }
        // storing data of firstIndex
        T ans = data[firstIndex];
        // updating firstIndex
        firstIndex = (firstIndex + 1) % capacity;
        // updating size
        size--;
        // if queue becomes empty, then reset firstIndex and nextIndex
        if (size == 0)
        {
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }
};
int main()
{
    QueueUsingArray<int> q(5);

    cout << q.isEmpty() << endl; // 1
    q.enqueue(18);
    cout << q.front() << endl; // 18
    q.enqueue(1);
    q.enqueue(8);
    cout << q.getSize() << endl; // 3
    q.enqueue(5);
    q.enqueue(20);
    q.enqueue(100);              // queue is full
    cout << q.getSize() << endl; // 5
    cout << q.deque() << endl;   // 18
    cout << q.deque() << endl;   // 1
    cout << q.front() << endl;   // 8
    cout << q.deque() << endl;   // 8
    cout << q.deque() << endl;   // 5
    cout << q.deque() << endl;   // 20
    cout << q.deque() << endl;   // queue is empty! 0
    cout << q.deque() << endl;   // queue is empty! 0

    return 0;
}