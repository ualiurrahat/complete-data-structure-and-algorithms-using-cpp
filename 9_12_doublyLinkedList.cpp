#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
    // destructor
    ~Node()
    {
        int val = data;
        if (next != nullptr)
        {
            delete next;
            next = nullptr;
        }
        if(prev != nullptr)
        {
            delete prev;
            prev = nullptr;
        }
        cout << "memory free for node with data " << val << endl;
    }
};

void print(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int length(Node *head)
{
    if (head == nullptr)
    {
        return 0;
    }
    int len = 0;
    while (head != nullptr)
    {

        head = head->next;
        len++;
    }
    return len;
}

void insertAtHead(Node *&head, Node *&tail, int data)
// taking head reference to make changes in the head node of main() function
{
    if (head == nullptr)
    {
        Node *temp = new Node(data);
        head = temp;
        // head null means tail is also null. updating tail
        tail = temp;
        return;
    }
    Node *temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void insertAtTail(Node *&head, Node *&tail, int data)
{
    // if tail is null, means head is null too
    if (tail == nullptr)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    Node *temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    // inserting at position 1 == insert at head
    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }
    Node *temp = head;
    int i = 1;
    while (i < position - 1 && temp != nullptr)
    {
        temp = temp->next;
        i++;
    }
    // inseting at last == insert at tail
    if (temp != nullptr && temp->next == nullptr)
    {
        insertAtTail(head, tail, data);
        return;
    }
    // inseting at other positon except head and tail
    if (temp != nullptr)
    {
        Node *nodeToInsert = new Node(data);
        nodeToInsert->next = temp->next;
        temp->next->prev = nodeToInsert;
        temp->next = nodeToInsert;
        nodeToInsert->prev = temp;
    }
}

// function to take input
Node *take_input()
{
    // we cant ask size as linked list is dynamic
    // so will take input as linked list node
    // untill -1 is given.
    cout << "enter your linked list: " << endl;
    int data;
    cin >> data;
    Node *head = nullptr;
    Node *tail = nullptr;

    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = tail->next;
        }
        // further input for nodes
        cin >> data;
    }
    // returning head of the linked list
    return head;
}

// delete node index wise
Node *deleteNode(Node *head, int index)
{
    // deleting first index
    if (index == 0)
    {
        Node *temp = head;
        head = temp->next;
        temp->next = nullptr;
        delete temp;
        return head;
    }
    // deleting mid indexed nodes
    int len = length(head);
    if (index >= len)
    {
        return head;
    }
    int count = 1;
    Node *temp = head;
    while (count < index)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next != nullptr && index < len - 1)
    {
        Node *a = temp->next;
        temp->next = a->next;
        a->next->prev = temp;
        a->next = nullptr;
        a->prev = nullptr;
        delete a;
        return head;
    }
    // deleting last index
    if (index == len - 1)
    {
        Node *a = temp->next;
        a->prev = nullptr;
        temp->next = nullptr; // temp->next = null
        return head;
    }
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    insertAtHead(head, tail, 20);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    insertAtHead(head, tail, 30);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    cout << "length : " << length(head) << endl;

    insertAtHead(head, tail, 40);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    // cout << head << endl;
    // head got changed here. as we updated head node

    // cout << sizeof(head) << endl;
    insertAtTail(head, tail, 100);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    insertAtPosition(head, tail, 3, 400);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    insertAtPosition(head, tail, 1, 2022);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    insertAtPosition(head, tail, 25, 2022);
    // position 25 makes head = nullptr before it reaches to 25th position
    // so no change in the linked list
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    head = take_input();
    print(head);

    // delete node with index 0
    head = deleteNode(head, 0);
    print(head);

    // delete node with index more than length of the LL
    // will bring no change
    head = deleteNode(head, 5);
    print(head);

    head = deleteNode(head, 2);
    print(head);

    head = deleteNode(head, 4);
    print(head);

    head = deleteNode(head, 30);
    print(head);
    head = deleteNode(head,5);
    print(head);

    return 0;
}