// Implementation of Stack using Linked List with Templates (Generic Data Types)
//
// This stack implementation uses a singly linked list where new elements are always
// inserted at the beginning (head). This approach ensures O(1) time complexity for
// both push and pop operations, adhering to the LIFO (Last In First Out) principle.
//
// Example: If the stack contains 10, 20, 30 (30 being the top),
// the linked list will appear as: 30 -> 20 -> 10 -> nullptr

#include <iostream>
using namespace std;

// Node class for singly linked list supporting generic data type T
template <typename T>
class Node
{
public:
    T data;        // Data field of the node
    Node<T> *next; // Pointer to the next node

    // Constructor to initialize the node with data
    Node(T data)
    {
        this->data = data;
        next = nullptr;
    }
};

// Stack class implemented using linked list
template <typename T>
class Stack
{
private:
    Node<T> *head; // Pointer to the top of the stack (head of the list)
    int size;      // Tracks the number of elements in the stack

public:
    // Constructor initializes an empty stack
    Stack()
    {
        head = nullptr;
        size = 0;
    }

    // Returns the number of elements in the stack
    int getSize()
    {
        return size;
    }

    // Returns true if the stack is empty, false otherwise
    bool isEmpty()
    {
        return size == 0;
    }

    // Removes and returns the top element of the stack
    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty! so pop is not possible" << endl;
            return 0; // Returning 0 as a generic placeholder
        }

        // Store the current top element to return it later
        T ans = head->data;

        // Move head to the next element
        Node<T> *temp = head;
        head = head->next;

        // Deallocate memory of the removed node
        delete temp;

        // Decrement stack size
        size--;

        return ans;
    }

    // Adds an element to the top of the stack
    void push(T element)
    {
        // Create a new node with the element
        Node<T> *newNode = new Node<T>(element);

        // Insert at the beginning to maintain LIFO order
        newNode->next = head;
        head = newNode;

        // Increment stack size
        size++;
    }

    // Returns the top element without removing it
    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty! so no top is there" << endl;
            return 0; // Returning 0 as a generic placeholder
        }
        return head->data;
    }
};

int main()
{
    Stack<char> s;

    s.push('r');
    s.push('a');
    s.push('h');
    s.push('a');
    s.push('t');

    cout << s.getSize() << endl; // 5

    cout << s.top() << endl; // t
    cout << s.pop() << endl; // t
    cout << s.pop() << endl; // a
    cout << s.pop() << endl; // h

    cout << s.getSize() << endl; // 2

    cout << s.isEmpty() << endl; // 0
    cout << s.pop() << endl;     // a
    cout << s.pop() << endl;     // r
    cout << s.top() << endl;     // stack is empty!
    cout << s.pop() << endl;     // stack is empty!
    cout << s.isEmpty() << endl; // 1 (true)

    return 0;
}
