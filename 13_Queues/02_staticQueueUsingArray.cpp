/*
  Filename : 02_queueUsingArray.cpp
  Purpose  : Implementation of Queue using Static Array in C++
*/

#include <iostream>
using namespace std;

// Generic Queue implementation using static array
template <typename T>
class QueueUsingArray
{
private:
    T *data;        // Array to store queue elements
    int firstIndex; // Index of the front element
    int nextIndex;  // Index where the next element will be inserted
    int size;       // Current number of elements in the queue
    int capacity;   // Maximum capacity of the queue

public:
    // Constructor
    // Initializes a queue of user-defined total size
    QueueUsingArray(int totalSize)
    {
        data = new T[totalSize]; // Allocate memory for the array
        nextIndex = 0;           // Start inserting from index 0
        firstIndex = -1;         // Queue is initially empty
        size = 0;                // No elements in queue initially
        capacity = totalSize;    // Set maximum capacity
    }

    // Returns the current size of the queue
    int getSize()
    {
        return size;
    }

    // Checks whether the queue is empty
    bool isEmpty()
    {
        return size == 0;
    }

    // Inserts an element into the queue
    void enqueue(T element)
    {
        // Check if queue is full
        if (size == capacity)
        {
            cout << "Queue is full! Enqueue not possible!" << endl;
            return;
        }

        // Insert element at nextIndex
        data[nextIndex] = element;

        // Update nextIndex in a circular manner
        nextIndex = (nextIndex + 1) % capacity;

        // If inserting first element, update firstIndex
        if (firstIndex == -1)
        {
            firstIndex = 0;
        }

        // Increment size
        size++;
    }

    // Returns the front element without removing it
    T front()
    {
        // Check if queue is empty
        if (firstIndex == -1)
        {
            cout << "Queue is empty! No front element is there." << endl;
            // Return default value for generic type
            return 0;
        }
        return data[firstIndex];
    }

    // Removes and returns the front element from the queue
    T dequeue()
    {
        // Check if queue is empty
        if (isEmpty())
        {
            cout << "Queue is empty! Dequeue is not possible" << endl;
            return 0;
        }

        // Store the front element to return
        T ans = data[firstIndex];

        // Update firstIndex in a circular manner
        firstIndex = (firstIndex + 1) % capacity;

        // Decrement the size
        size--;

        // If queue becomes empty after dequeue, reset indices
        if (size == 0)
        {
            firstIndex = -1;
            nextIndex = 0;
        }

        return ans;
    }
    // destructor
    ~QueueUsingArray()
    {
        // 'data' was allocated using 'new[]' in the constructor:
        //     data = new T[totalSize];
        // So we must release it with 'delete[]' to prevent memory leak.
        delete[] data;
    }
};

int main()
{
    QueueUsingArray<int> q(5); // Create a queue of capacity 5

    cout << q.isEmpty() << endl; // Output: 1 (true)

    q.enqueue(18);
    cout << q.front() << endl; // Output: 18

    q.enqueue(1);
    q.enqueue(8);
    cout << q.getSize() << endl; // Output: 3

    q.enqueue(5);
    q.enqueue(20);
    q.enqueue(100); // Queue is full, enqueue not possible

    cout << q.getSize() << endl; // Output: 5

    cout << q.dequeue() << endl; // Output: 18
    cout << q.dequeue() << endl; // Output: 1
    cout << q.front() << endl;   // Output: 8
    cout << q.dequeue() << endl; // Output: 8
    cout << q.dequeue() << endl; // Output: 5
    cout << q.dequeue() << endl; // Output: 20
    cout << q.dequeue() << endl; // Queue is empty! Output: 0
    cout << q.dequeue() << endl; // Queue is empty! Output: 0

    return 0;
}
