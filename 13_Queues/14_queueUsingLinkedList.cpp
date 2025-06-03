// implementing queue using Linked List.
#include <iostream>
using namespace std;

template <typename T>
// Node class.
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
// class for Queue
class Queue
{
    // private members for queue DS
private:
    Node<T> *head; // to store front element
    Node<T> *tail; // to check last element in queue
    int size;      // no. of elements present in queue.

public:
    // constructor.
    Queue()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    // function to return size of queue
    int getSize()
    {
        return size;
    }
    // function to check if queue is empty or not.
    bool isEmpty()
    {
        return size == 0;
    }
    // function to perform enqueue operation in queue.
    void enqueue(T element)
    {
        // creating new node with element as data
        Node<T> *newNode = new Node<T>(element);
        // in case of queue is empty
        if (head == nullptr)
        {
            // queue is empty. updating head and tail.
            head = newNode;
            tail = newNode;
        }
        // queue is not empty. updating tail.
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        // update size of queue.
        size++;
    }
    // function to get front element in queue
    T front()
    {
        // checking if queue is empty.
        if (isEmpty())
        {
            cout << "queue is empty! no front available" << endl;
            // since queue is generic data type.
            // returning 0 as standard value.
            return 0;
        }
        // returning front element.
        return head->data;
    }
    // function to perform deque operation in queue.
    // returns the front elemeent.
    T deque()
    {
        // in case queue is empty.
        if (isEmpty())
        {
            cout << "queue is empty. deque not possible" << endl;
            // since queue is generic data type.
            // returning 0 as standard value.
            return 0;
        }
        // store front element.
        T ans = head->data;
        Node<T> *temp = head;
        // update head.
        head = head->next;
        // deleting previous front element
        // as deque operation.
        delete temp;
        // update size.
        size--;
        // return front.
        return ans;
    }
};
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

    cout << q.front() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl;

    return 0;
}
