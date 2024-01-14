// implementing stack using Linked List.
// here, we are pushing elements into the stack
// with the help of linked list and inserting elements in 0th position
// for example: if first 3 elemenst of stack are 10,20,30
// then 30 is top element.
// but linked list will look like this: 30->20->10->null.
// So we are adding new element at 0th node position
// to achieve O(1) time complexity in push function.
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
    int size; // no. of elements present in the stack.

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
        // store top element.
        T ans = head->data;
        Node<T> *temp = head;
        // update head.
        head = head->next;
        // delete the top node.
        delete temp;
        // update size.
        size--;
        // return top element.
        return ans;
    }

    // push elements
    void push(T element)
    {
        Node<T> *newNode = new Node<T>(element);
        // instead of adding node at last , we are adding new Node at 0th postion
        // this is helpful for pop() function
        // means if Stack first two elements are 10,20
        // then they will look like: 20->10->null
        // we are adding node at 0th postion to achieve O(1) time complexity.
        newNode->next = head;
        // update head.
        head = newNode;
        // update size of stack.
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
int main()
{
    Stack<char> s;
    s.push('r');
    s.push('a');
    s.push('h');
    s.push('a');
    s.push('t');
    cout << s.getSize() << endl; // 5

    cout << s.top() << endl;     // t
    cout << s.pop() << endl;     // t
    cout << s.pop() << endl;     // a
    cout << s.pop() << endl;     // h
    cout << s.getSize() << endl; // 2

    cout << s.isEmpty() << endl; // 0
    cout << s.pop() << endl;     // a
    cout << s.pop() << endl;     // r
    cout << s.top() << endl;     // stack is empty!
    cout << s.pop() << endl;     // stack is empty!
    cout << s.isEmpty() << endl; // true->1

    return 0;
}
