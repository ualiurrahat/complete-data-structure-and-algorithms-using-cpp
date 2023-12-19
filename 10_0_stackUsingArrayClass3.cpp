// stack using array with templates.
// can be use for generic data type
#include <climits>
#include <iostream>

using namespace std;

template <typename T>
class StackUsingArray
{
    // dynamic array to store elements in stacks
    // and index var for elements
    // capacity var to check stack length
private:
    T *data;
    int nextIndex;
    int capacity;

public:
    //Constructor
    StackUsingArray()
    {
        data = new T[4];
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
        //     return true;
        // else
        //     return false;
        // short form of the above code
        return nextIndex == 0;
    }
    // insert element
    void push(T element)
    {
        if (nextIndex == capacity)
        {
            // stack is full. so creating double sized stack here to resolve the issue.
            T *newData = new T[2 * capacity];
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
    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;

            // T can be any data type.we don't know
            // what kind of data user will use. So 0 is a standard value.
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    // top element
    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            // returning INT_MIN as a sign
            // that stack is empty
            return 0;
        }
        return data[nextIndex - 1];
    }
};
