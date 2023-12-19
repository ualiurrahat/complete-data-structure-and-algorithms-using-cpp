#include <iostream>

using namespace std;

template <typename T>
// class for nodes of linked list
class Node
{
public:
    T data;
    Node<T> *next;
    // constructor
    Node(T data)
    {
        this->data = data;
        next = nullptr;
    }
};

// class for stack
template <typename T>
class Stack
{
private:
    // these datas should be private
    // according to charactersitics of stack DS
    Node<T> *head;
    int size; // represents total no. of elements in the stack

public:
    // constructor
    Stack()
    {
        head = nullptr;
        size = 0;
    }
    // get size of stack
    int getSize()
    {
        return size;
    }
    // check if stack is empty
    bool isEmpty()
    {
        return size == 0;
    }
    // pop elements.
    T pop()
    {
        // check if stack is empty
        // then pop is not possible
        if (isEmpty())
        {
            cout << "Stack is empty! so pop is not possible" << endl;
            return 0;
        }
        T ans = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }

    // push elements
    void push(T element)
    {
        Node<T> *newNode = new Node<T>(element);
        // instead of adding node at last , we are adding new Node at 0th postion
        // this is helpful for pop() function
        newNode->next = head;
        head = newNode;
        size++;
    }
    // find top elements
    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty! so no top is there" << endl;
            return 0;
        }
        return head->data;
    }
};