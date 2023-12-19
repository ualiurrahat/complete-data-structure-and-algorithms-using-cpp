#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

template <typename T>
class Queue
{
    // private members for queue DS
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    Queue()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(T element)
    {
        Node<T> *newNode = new Node<T>(element);
        // checking if queue is empty
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        size++;
    }

    T front()
    {
        if (isEmpty())
        {
            cout << "queue is empty! no front available" << endl;
            return 0; // returning 0 as a symbol of queue being empty.
        }
        return head->data;
    }
    T deque()
    {
        if (isEmpty())
        {
            cout << "queue is empty. deque not possible" << endl;
            return 0; // returning 0 as a symbol of queue being empty.
        }
        T ans = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }
};
