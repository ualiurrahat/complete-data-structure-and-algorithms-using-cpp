// creating stack class using static array
// this stack can be full
// so size is an issue here.
#include<climits>
#include<iostream>

using namespace std;


class StackUsingArray
{
private:
    int *data;          // integer pointer to store elements in stacks
    int nextIndex;      // and nextIndex var to check element's index
    int capacity;       // capacity var to check stack length

public:
    //Constructor
    StackUsingArray(int totalSize)
    {
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
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
    void push(int element)
    {
        if (nextIndex == capacity)
        {
            cout << "Stack is full!" << endl;
            return;
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

