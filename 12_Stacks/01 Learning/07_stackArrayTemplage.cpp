// stack_array_template.cpp
// Implementation of a stack using dynamic array with templates (generic data type support)

#include <iostream> // Required for input/output operations

using namespace std;

// Template class for stack implementation
// T is a generic data type
template <typename T>
class StackUsingArray
{
private:
    T *data;       // Dynamic array to store stack elements
    int nextIndex; // Index where next element will be inserted
    int capacity;  // Current capacity of the stack

public:
    // Constructor to initialize stack with default capacity
    StackUsingArray()
    {
        data = new T[4]; // Allocate memory for 4 elements
        nextIndex = 0;   // Stack is initially empty
        capacity = 4;    // Initial capacity
    }

    // Returns the number of elements currently in the stack
    int size()
    {
        return nextIndex;
    }

    // Returns true if the stack is empty, false otherwise
    bool isEmpty()
    {
        return nextIndex == 0;
    }

    // Push an element into the stack
    void push(T element)
    {
        // If the stack is full, double the capacity
        if (nextIndex == capacity)
        {
            T *newData = new T[2 * capacity]; // Allocate new memory

            // Copy existing elements to new array
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }

            capacity *= 2;  // Update the capacity
            delete[] data;  // Free old memory
            data = newData; // Point data to new memory
        }

        data[nextIndex] = element; // Add element to stack
        nextIndex++;               // Move to next index
    }

    // Pop (remove and return) the top element of the stack
    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;

            // Return a default value (0) in case of underflow
            // Note: this assumes T can safely be assigned zero
            return 0;
        }

        nextIndex--;            // Decrease size
        return data[nextIndex]; // Return the last inserted element
    }

    // Return (without removing) the top element of the stack
    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;

            // Return a default value (0) if stack is empty
            return 0;
        }

        return data[nextIndex - 1]; // Return top element
    }
};

// Driver code to demonstrate stack usage with char type
int main()
{
    StackUsingArray<char> s;
    s.push('a');
    s.push('h');
    s.push('n');
    s.push('a');
    s.push('f');

    cout << s.size() << endl; // Output current size of stack

    cout << s.top() << endl; // Output top element
    cout << s.pop() << endl; // Pop and output element
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.size() << endl; // Output new size

    cout << s.isEmpty() << endl; // Check if stack is empty

    // using int data type to showcase our stack class usage and operations
    StackUsingArray<int> sInt;
    sInt.push(10);
    sInt.push(20);
    sInt.push(30);

    cout << sInt.top() << endl;  // Output: 30
    cout << sInt.pop() << endl;  // Output: 30
    cout << sInt.size() << endl; // Output: 2

    return 0;
}
