// ======================================================
// Stack Implementation Using Static Array (Fixed Size)
// ======================================================

// Arrays or linked lists are commonly used as internal storage
// structures when implementing data structures like stacks and queues.
// This example uses a static array to implement a basic stack.
// Note: Since the array size is fixed, the stack will have a maximum capacity.

#include <climits>
#include <iostream>
using namespace std;

class StackUsingArray
{
private:
    int *data;     // Pointer to dynamically allocated array for stack elements
    int nextIndex; // Points to the index where the next element will be inserted
    int capacity;  // Maximum size of the stack

public:
    // Constructor: initializes the stack with a fixed size
    StackUsingArray(int totalSize)
    {
        data = new int[totalSize]; // Allocate memory for the stack
        nextIndex = 0;             // Stack is initially empty
        capacity = totalSize;      // Set stack capacity
    }

    // Returns the current number of elements in the stack
    int size()
    {
        return nextIndex;
    }

    // Checks whether the stack is empty
    bool isEmpty()
    {
        return nextIndex == 0;
    }

    // Pushes an element onto the stack
    void push(int element)
    {
        if (nextIndex == capacity)
        {
            // If the stack is full, insertion is not allowed
            cout << "Stack is full! Push operation not possible!" << endl;
            return;
        }
        data[nextIndex] = element; // Insert element at the next available index
        nextIndex++;               // Move to next index
    }

    // Removes and returns the top element from the stack
    // Returns INT_MIN if the stack is empty
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty! Pop operation not possible" << endl;
            return INT_MIN; // Indicates stack underflow
        }
        nextIndex--; // Move index down before accessing top element
        return data[nextIndex];
    }

    // Returns the top element without removing it
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return INT_MIN; // Indicates stack underflow
        }
        return data[nextIndex - 1]; // Top element is at nextIndex - 1
    }
};

int main()
{
    // Create a stack with fixed size of 5
    StackUsingArray s(5);
    cout << s.pop() << endl;
    cout << s.isEmpty() << endl;
    cout << s.size() << endl;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(100); // This will fail as the stack is already full

    cout << s.top() << endl; // Should print 50
    cout << s.pop() << endl; // Removes 50
    cout << s.pop() << endl; // Removes 40
    cout << s.pop() << endl; // Removes 30
    cout << s.pop() << endl; // Removes 20
    cout << s.top() << endl; // Should print 10

    cout << s.size() << endl;    // Should print 1 (only one element left)
    cout << s.isEmpty() << endl; // Should print 0 (false)
    return 0;
}
