// ============================================================
// Stack Implementation Using Dynamic Array (Auto-Resizing)
// ============================================================

// This implementation removes the limitation of a fixed-size array
// by dynamically resizing the internal array when the stack is full.
// This ensures the stack can grow as needed without size constraints.

#include <climits>
#include <iostream>
using namespace std;

class StackUsingArray
{
private:
    int *data;     // Pointer to dynamically allocated array for stack elements
    int nextIndex; // Points to the next insertion index
    int capacity;  // Current capacity of the stack

public:
    // Constructor initializes with default capacity (4)
    StackUsingArray()
    {
        data = new int[4]; // Allocate initial memory
        nextIndex = 0;     // Stack starts empty
        capacity = 4;      // Initial capacity
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
            // Stack is full — double the array size to allow more elements
            int *newData = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i]; // Copy existing elements
            }

            capacity *= 2;  // Update capacity
            delete[] data;  // Free old memory
            data = newData; // Reassign data to the new array
        }
        data[nextIndex] = element; // Insert element
        nextIndex++;               // Move to next index
    }

    // Removes and returns the top element from the stack
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return INT_MIN; // Indicates stack underflow
        }
        nextIndex--; // Move index down before returning element
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
        return data[nextIndex - 1];
    }
};

int main()
{
    // Create a stack with default initial size (capacity = 4)
    StackUsingArray s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);  // Triggers resizing (capacity becomes 8)
    s.push(100); // Successfully pushed after resizing

    cout << s.top() << endl; // Should print 100
    cout << s.pop() << endl; // Removes 100
    cout << s.pop() << endl; // Removes 50
    cout << s.pop() << endl; // Removes 40
    cout << s.pop() << endl; // Removes 30
    cout << s.top() << endl; // Should print 20

    cout << s.size() << endl;    // Should print 2
    cout << s.isEmpty() << endl; // Should print 0 (false)

    return 0;
}
