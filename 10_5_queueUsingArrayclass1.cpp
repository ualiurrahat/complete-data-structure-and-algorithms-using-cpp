// creating a queue using static array
// size is a issue here

#include <iostream>
using namespace std;

template <typename T>
class QueueUsingArray
{
private:
    T *data;
    int firstIndex; // to get front element
    int nextIndex;  // to get index of next element
    int size;       // total queue size
    int capacity;   // capacity of queue

public:
    QueueUsingArray(int totalSize)
    {
        // queue is being created.
        // creating array of totalSize to contain elements
        // queue is empty. indicating this with firstIndex as 0 and nextIndex as 0;
        data = new T[totalSize];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
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
        // inserting element and increasing size
        data[nextIndex] = element;
        // updating nextIndex
        nextIndex = (nextIndex + 1) % capacity;
        // checking if queue was empty,then front element needs to be set
        if (firstIndex == -1)
        {
            firstIndex = 0;
        }
        // updating size
        size++;
    }

    // front element of queue
    T front()
    {
        // checking if queue is empty
        if (firstIndex == -1)
        {
            cout << "Queue is empty!" << endl;
            return 0;
        }
        return data[firstIndex];
    }

    // remove an element
    T deque()
    {
        // if queue is empty, deque is not possible
        if (isEmpty())
        {
            cout << "Queue is empty! Deque is not possible" << endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
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