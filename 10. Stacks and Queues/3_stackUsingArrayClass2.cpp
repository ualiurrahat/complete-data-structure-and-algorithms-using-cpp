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
    // Constructor
    StackUsingArray()
    {
        // taking inital stack array size as 4.
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
            // coping  stack elements from old array to this new array
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }

            // updating capacity
            capacity *= 2;
            // deleting old array
            delete[] data;
            // assigning newData as Data array of the stack
            data = newData;
        }
        // pusing element into stack
        data[nextIndex] = element;
        // updating nextIndex
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

int main()
{
    // creating a stack named s. its inital size is 4
    StackUsingArray s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50); // for this 5th elemeent, stack creating double sized array here.
    s.push(100);

    cout << s.top() << endl; // 100
    cout << s.pop() << endl; // 100
    cout << s.pop() << endl; // 50
    cout << s.pop() << endl; // 40
    cout << s.pop() << endl; // 30
    cout << s.top() << endl; // 20

    cout << s.size() << endl;    // 2
    cout << s.isEmpty() << endl; // 0

    return 0;
}