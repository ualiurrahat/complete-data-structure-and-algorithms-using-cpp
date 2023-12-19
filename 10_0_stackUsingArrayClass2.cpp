// creating stack using dynamic array
// when stack gets full, size issue will be solved this time
// we don't need to initialize stack with size
// creating stack class using array
#include <climits>
#include <iostream>

using namespace std;

class StackUsingArray
{
    // dynamic array to store elements in stacks
    // and index var for elements
    // capacity var to check stack length
private:
    int *data;
    int nextIndex;
    int capacity;

public:
    //Constructor
    StackUsingArray()
    {
        data = new int[4];
        nextIndex = 0;
        capacity = 4; // initial capacity
    }

    // size of stack
    int size()
    {
        return nextIndex;
    }

    // check if stack is empty
    bool isEmpty()
    {
        // if(nextIndex == 0)
        // {
        //     return true;
        // }
        // else
        // {
        //     return false;
        // }

        // short form of the above code
        return nextIndex == 0;
    }
    // insert element
    void push(int element)
    {
        if (nextIndex == capacity)
        {
            // stack is full. so creating double sized stack here to resolve the issue.
            int *newData = new int[2 * capacity];
            // coping prevoious stack elements into this array
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }

            // updating capacity
            capacity *= 2;
            // deleting old data
            delete[] data;
            // assigning newData as Data array of the stack
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    // delete element
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            // returning INT_MIN as a sign
            // that stack is empty
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    // top element
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            // returning INT_MIN as a sign
            // that stack is empty
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};
