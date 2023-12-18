// circular singly LL:the last node  points back to the first node instead of having a null reference.
// This creates a loop in the list,can be traversed the entire list starting from any node.
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
            cout << "Memory is free for data with " << value << endl;
        }
    }
};

// function to insert node in circular Singly LL
// function has a tail node, int element after which
// a node with value d has to be inserted
// NOTE: We don't need head,tail both pointer for circular LL
// only tail is enough
void insertNode(Node *&tail, int element, int d)
{
    // case for empty node
    if (tail == nullptr)
    {
        // create new node with data as d
        Node *newNode = new Node(d);
        // update tail
        tail = newNode;
        // make circular list by appointing next node of NewNode as the node itself
        newNode->next = newNode;
    }
    else
    // case for non-emptylist.
    // assuming that the element is present in the list
    {
        // create new node
        Node *newNode = new Node(d);
        // take a node curr to find node with element as data
        Node *curr = tail;
        // running loop to find the element data node
        while (curr->data != element)
        {
            curr = curr->next;
        }
        // now curr representds element data node
        // appoint curr as next to newNode
        newNode->next = curr->next;
        // update next of curr to make list circular
        curr->next = newNode;
    }
}

// function to print circular singly LL
void print(Node *tail)
{

    Node *temp = tail;

    // empty list
    if (tail == NULL)
    {
        cout << "List is Empty " << endl;
        return;
    }

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);

    cout << endl;
}
void deleteNode(Node *&tail, int value)
{

    // empty list
    if (tail == NULL)
    {
        cout << " List is empty, please check again" << endl;
        return;
    }
    else
    {
        // non-empty

        // assuming that "value" is present in the Linked List
        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        // 1 Node Linked List
        if (curr == prev)
        {
            tail = NULL;
        }

        //>=2 Node linked list
        else if (tail == curr)
        {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}

bool isCircularList(Node *head)
{
    // empty list
    if (head == NULL)
    {
        return true;
    }

    Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    if (temp == head)
    {
        return true;
    }

    return false;
}

int main()
{
    // take a tail node as null value
    Node *tail = NULL;

    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 5, 6);
    print(tail);

    insertNode(tail, 9, 10);
    print(tail);

    insertNode(tail, 3, 4);
    print(tail);

    deleteNode(tail, 5);
    print(tail);

    if (isCircularList(tail))
    {
        cout << " Linked List is Circular in nature" << endl;
    }
    else
    {
        cout << "Linked List is not Circular " << endl;
    }

    return 0;
}