/*Implement a last-in-first-out (LIFO) stack using queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
*/
#include <iostream>
#include <queue>

using namespace std;

class MyStack
{
    queue<int> q; // Single queue used to simulate stack behavior

public:
    // Constructor: Initializes an empty stack
    MyStack() {}

    // Pushes element x onto the stack
    void push(int x)
    {
        int n = q.size(); // Store current size of the queue
        q.push(x);        // Enqueue the new element at the back

        // Rotate the previous elements behind the newly added one
        // This ensures the new element appears at the front (top of stack)
        for (int i = 0; i < n; i++)
        {
            q.push(q.front()); // Move front element to the back
            q.pop();           // Remove it from the front
        }
        // T:O(N), S:O(N = no. of elements in the queue)
    }

    // Removes and returns the top element of the stack
    int pop()
    {
        int top = q.front(); // Get the front element (top of the stack)
        q.pop();             // Remove it from the queue
        return top;          // Return the popped value
        // T:O(1), S:O(1)
    }

    // Returns the top element without removing it
    int top()
    {
        return q.front(); // Front of the queue is the top of the stack
        // T:O(1), S:O(1)
    }

    // Returns true if the stack is empty, false otherwise
    bool empty()
    {
        return q.empty(); // Check if the queue is empty
        // T:O(1), S:O(1)
    }
};
