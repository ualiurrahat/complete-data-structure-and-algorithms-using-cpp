// this time we are implementing queue
// using dynamic array.So size issue is solved.
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

    // function to perform enqueue operation in queue.
    void enqueue(T element)
    {
        // in case of queue is full
        if (size == capacity)
        {
            // creating double sized new array to store elements in queue.
            T *newData = new T[2 * capacity];
            int j = 0;
            // filling up newData with data's existing element
            // from firstIndex to lastIndex(capacity)
            for (int i = firstIndex; i < capacity; i++)
            {
                newData[j] = data[i];
                j++; // updating index of newData
            }
            // filling rest of the element from index 0 to firstIndex
            for (int i = 0; i < firstIndex; i++)
            {
                newData[j] = data[i];
                j++; // updating index of newData
            }
            // deleting old array
            delete[] data;
            // assigning newData as data
            data = newData;
            // resetting firstIndex and newtIndex
            firstIndex = 0;
            nextIndex = capacity;
            // updating capacity.
            capacity *= 2;
        }
        // inserting element in queue
        data[nextIndex] = element;
        // updating size
        size++;
        // next elements index
        nextIndex = (nextIndex + 1) % capacity;
        // resetting firstIndex if queue is empty before inserting current element.
        if (firstIndex == -1)
        {
            firstIndex = 0;
        }
    }

    // front element of queue
    T front()
    {
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

int main()
{
    QueueUsingArray<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // no queue is full message. as we have solved the size issue in enqueue function.
    q.enqueue(70);
    q.enqueue(80);

    cout << q.front() << endl;   // 10
    cout << q.deque() << endl;   // 10
    cout << q.deque() << endl;   // 20
    cout << q.deque() << endl;   // 30
    cout << q.deque() << endl;   // 40
    cout << q.getSize() << endl; // 4
    cout << q.isEmpty() << endl; // 0

    return 0;
}