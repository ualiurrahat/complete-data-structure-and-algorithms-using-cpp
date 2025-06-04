/*
  Filename : 03_dynamicQueueUsingArray.cpp
  Purpose  : Implementation of Queue using Dynamic Array in C++
*/

#include <iostream>
using namespace std;

// Generic Queue implementation using a dynamically resizable array
template <typename T>
class QueueUsingArray
{
private:
    T *data;        // Array to store queue elements
    int firstIndex; // Index of the front element
    int nextIndex;  // Index where the next element will be inserted
    int size;       // Current number of elements in the queue
    int capacity;   // Current maximum capacity of the queue

public:
    // Constructor
    // Initializes queue with a user-defined initial capacity
    QueueUsingArray(int totalSize)
    {
        data = new T[totalSize]; // Allocate initial array
        nextIndex = 0;           // Start inserting from index 0
        firstIndex = -1;         // Queue is initially empty
        size = 0;                // No elements yet
        capacity = totalSize;    // Set initial capacity
    }

    // Returns the number of elements currently in the queue
    int getSize()
    {
        return size;
    }

    // Checks whether the queue is empty
    bool isEmpty()
    {
        return size == 0;
    }

    // Inserts an element at the end of the queue
    void enqueue(T element)
    {
        // If the queue is full, we need to resize it
        if (size == capacity)
        {
            // Create a new array with double the capacity
            T *newData = new T[2 * capacity];
            int j = 0;

            // Copy elements from firstIndex to end of current array
            for (int i = firstIndex; i < capacity; i++)
            {
                newData[j++] = data[i];
            }

            // Copy elements from beginning up to firstIndex
            for (int i = 0; i < firstIndex; i++)
            {
                newData[j++] = data[i];
            }

            // Deallocate old array and update data pointer
            delete[] data;
            data = newData;

            // Reset indices
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2; // Double the capacity
        }

        // Insert the new element
        data[nextIndex] = element;

        // Update nextIndex in a circular fashion
        nextIndex = (nextIndex + 1) % capacity;

        // If the queue was previously empty, update firstIndex
        if (firstIndex == -1)
        {
            firstIndex = 0;
        }

        // Increment the size
        size++;
    }

    // Returns the front element without removing it
    T front()
    {
        if (firstIndex == -1)
        {
            cout << "Queue is empty!" << endl;
            return 0; // Return default value for generic type
        }
        return data[firstIndex];
    }

    // Removes and returns the front element from the queue
    T dequeue()
    {
        // Check if queue is empty
        if (isEmpty())
        {
            cout << "Queue is empty! dequeue is not possible" << endl;
            return 0; // Return default value
        }

        // Store and remove the front element
        T ans = data[firstIndex];

        // Update firstIndex in a circular fashion
        firstIndex = (firstIndex + 1) % capacity;

        // Decrease size
        size--;

        // If queue becomes empty after removal, reset indices
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
    QueueUsingArray<int> q(5); // Create a queue with initial capacity of 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // No "Queue is full" message due to dynamic resizing
    q.enqueue(70);
    q.enqueue(80);

    cout << q.front() << endl;   // Output: 10
    cout << q.dequeue() << endl; // Output: 10
    cout << q.dequeue() << endl; // Output: 20
    cout << q.dequeue() << endl; // Output: 30
    cout << q.dequeue() << endl; // Output: 40
    cout << q.getSize() << endl; // Output: 4
    cout << q.isEmpty() << endl; // Output: 0 (false)

    return 0;
}
