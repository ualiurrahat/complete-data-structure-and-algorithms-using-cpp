/*
  Filename : 04_queueUsingLinkedList.cpp
  Purpose  : Implementation of a generic Queue using Linked List in C++
*/

#include <iostream>
using namespace std;

// Node class for Linked List
template <typename T>
class Node
{
public:
    T data;        // Data stored in the node
    Node<T> *next; // Pointer to the next node

    // Constructor
    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

// Queue class implemented using a singly linked list
template <typename T>
class Queue
{
private:
    Node<T> *head; // Pointer to the front of the queue
    Node<T> *tail; // Pointer to the rear of the queue
    int size;      // Number of elements in the queue

public:
    // Constructor
    Queue()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Returns the current size of the queue
    int getSize()
    {
        return size;
    }

    // Returns true if the queue is empty
    bool isEmpty()
    {
        return size == 0;
    }

    // Inserts an element at the rear of the queue
    void enqueue(T element)
    {
        Node<T> *newNode = new Node<T>(element);

        // If the queue is empty, both head and tail point to the new node
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            // Link the new node at the end and update tail
            tail->next = newNode;
            tail = newNode;
        }

        // Increment size
        size++;
    }

    // Returns the front element without removing it
    T front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty! No front available." << endl;
            return 0; // Return a default value for generic type
        }
        return head->data;
    }

    // Removes and returns the front element of the queue
    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. dequeue not possible." << endl;
            return 0; // Return a default value for generic type
        }

        T ans = head->data;
        Node<T> *temp = head;
        head = head->next;

        // Free the memory of the old front node
        delete temp;

        // Decrement size
        size--;

        return ans;
    }
    // Destructor
    ~Queue()
    {
        // Start from the head of the linked list.
        while (head != nullptr)
        {
            // Temporarily store the current head node.
            Node<T> *temp = head;

            // Move head to the next node in the queue.
            head = head->next;

            // Delete the previous front node to free memory.
            delete temp;
        }

        // At the end, all nodes are deleted.
        // 'tail' will also become dangling, but we don't need to delete it separately,
        // since every node was already deleted in the loop.
    }
};

// Main function to demonstrate queue operations
int main()
{
    Queue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);

    cout << q.front() << endl;   // Output: 10
    cout << q.dequeue() << endl; // Output: 10
    cout << q.dequeue() << endl; // Output: 20
    cout << q.dequeue() << endl; // Output: 30
    cout << q.dequeue() << endl; // Output: 40
    cout << q.getSize() << endl; // Output: 4
    cout << q.isEmpty() << endl; // Output: 0 (false)

    return 0;
}
