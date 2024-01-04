// either array or linked list is used
// as internal storage for implementation of other data structures.
// here, we are creating stack class using static array
// NOTE: we need to consider the size issue here.Since we are using static array here.
#include <climits>
#include <iostream>

using namespace std;

class StackUsingArray
{
private:
    int *data;     // array pointer to store elements in stacks
    int nextIndex; // to maintain element's index
    int capacity;  // size of stack

public:
    // Constructor: user will declare stack with size also.
    StackUsingArray(int totalSize)
    {
        // initializg array with user given totalSize
        data = new int[totalSize];
        // index of first element is 0.
        nextIndex = 0;
        // total size of the stack
        capacity = totalSize;
    }

    // size of stack
    int size()
    {
        return nextIndex;
    }

    // function to tell if stack is empty.
    bool isEmpty()
    {
        // if(nextIndex == 0)
        //     return true;
        // else
        //     return false;

        // short form of the above code
        return nextIndex == 0;
    }
    // push function for stack. to insert element in the stack.
    void push(int element)
    {
        // when stack is full. we can not insert anymore.
        if (nextIndex == capacity)
        {
            cout << "Stack is full!" << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    // pop function to delete element from the stack.
    // removes the top element from the stack
    // returns new top element
    // returns INT_MIN in case of empty stack.
    int pop()
    {
        // when stack is empty, we can not pop up element from stack.
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

    // function to find top element from stack.
    int top()
    {
        // if stack is empty, returns INT_MIN.
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            // returning INT_MIN as a sign
            // that stack is empty
            return INT_MIN;
        }
        // returning the top element.
        return data[nextIndex - 1];
    }
};
int main()
{
    // creating a stack with size 5
    StackUsingArray s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(100); // stack is full. so this will not add to the stack s

    cout << s.top() << endl; // 50
    cout << s.pop() << endl; // 50
    cout << s.pop() << endl; // 40
    cout << s.pop() << endl; // 30
    cout << s.pop() << endl; // 20
    cout << s.top() << endl; // 10

    cout << s.size() << endl;    // 1
    cout << s.isEmpty() << endl; // 0
    return 0;
}