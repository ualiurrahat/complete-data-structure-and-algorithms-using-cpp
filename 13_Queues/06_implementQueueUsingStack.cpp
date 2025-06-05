/* Leetcode: 232
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
*/
#include <iostream>
#include <stack>
using namespace std;

/*
Approach 1: Costly Push, Efficient Pop
--------------------------------------
In this approach, we maintain the queue order in `s1` by making the `push()` operation expensive.

Steps:
- During push: Move all elements from `s1` to `s2`, insert the new element into `s1`, then move everything back from `s2` to `s1`. This ensures the newest element is always at the bottom.
- During pop/peek: Just operate on top of `s1`, which always has the front of the queue.

Time Complexity:
- push(): O(N)
- pop(): O(1)
- peek(): O(1)
- empty(): O(1)
*/
class MyQueue
{
    stack<int> s1, s2; // s1 holds the queue with front on top, s2 is used as a temporary buffer

public:
    MyQueue() {}

    // Insert element x to the back of the queue
    void push(int x)
    {
        // Step 1: Move all elements from s1 to s2
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        // Step 2: Push the new element into s1
        s1.push(x);

        // Step 3: Move all elements back from s2 to s1
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }

        // T: O(N), S: O(1)
    }

    // Remove and return the element from the front of the queue
    int pop()
    {
        int front = s1.top();
        s1.pop();
        return front;

        // T: O(1), S: O(1)
    }

    // Return the element at the front of the queue without removing it
    int peek()
    {
        return s1.top();

        // T: O(1), S: O(1)
    }

    // Check whether the queue is empty
    bool empty()
    {
        return s1.empty();

        // T: O(1), S: O(1)
    }
};

/*
Approach 2: Efficient Push, Lazy Pop
------------------------------------
In this optimized approach, we make `push()` efficient by simply adding to `s1`.
We delay rearranging until `pop()` or `peek()` is called and `s2` is empty.

Steps:
- push(x): Push to `s1` directly.
- pop()/peek():
  - If `s2` is not empty, use its top element (it holds the front of the queue).
  - If `s2` is empty, move all elements from `s1` to `s2` to reverse the order and expose the front.

This approach achieves amortized O(1) time for each operation.

Time Complexity:
- push(): O(1)
- pop(): Amortized O(1), Worst O(N)
- peek(): Amortized O(1), Worst O(N)
- empty(): O(1)
*/
class MyQueue
{
    stack<int> s1, s2; // s1 is for incoming elements, s2 is for outgoing elements

public:
    MyQueue() {}

    // Insert element x to the back of the queue
    void push(int x)
    {
        // Just push onto s1
        s1.push(x);

        // T: O(1), S: O(1)
    }

    // Remove and return the element from the front of the queue
    int pop()
    {
        // If s2 is empty, transfer all elements from s1 to s2
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int front = s2.top();
        s2.pop();
        return front;

        // T: Amortized O(1), Worst-case O(N); S: O(1)
    }

    // Return the element at the front of the queue without removing it
    int peek()
    {
        // If s2 is empty, transfer all elements from s1 to s2
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();

        // T: Amortized O(1), Worst-case O(N); S: O(1)
    }

    // Check whether the queue is empty
    bool empty()
    {
        return s1.empty() && s2.empty();

        // T: O(1), S: O(1)
    }
};
