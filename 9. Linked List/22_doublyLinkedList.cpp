#include <iostream>
using namespace std;

// Doubly LL class.
// each node has a data
// a next pointer to hold next node address
// a prev pointer to hold previous node address
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    // constructor
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
        if (prev != nullptr)
        {
            delete prev;
            prev = nullptr;
        }
        cout << "memory free for node with data " << val << endl;
    }
};
// function to print Doubly LL
void print(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "<->";
        temp = temp->next;
    }
    cout << "null" << endl;
}
// function to get length of a doubley LL
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
// function to insert a node as head of the doubly LL
// takes head,tail nodes and data of the node that has to be added in the LL as parameters
// taking  references of head and tail to make changes in the head node of main() function
void insertAtHead(Node *&head, Node *&tail, int data)
{
    // in case if head is null
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
// function to insert a node as tail of the doubly LL
// takes head,tail nodes and data of the node that has to be added in the LL as parameters
// taking  references of head and tail to make changes in the head node of main() function
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
// function to insert a node at any given position of the doubly LL
// takes head,tail nodes and data of the node that has to be added in the LL
// and the postion where new node has to be placed as parameters
// taking  references of head and tail to make changes in the head node of main() function
void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    // in case of inserting at position 1 i.e. insert at head
    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }
    // in case of position at any other place
    Node *temp = head;
    int i = 1;
    while (i < position - 1 && temp != nullptr)
    {
        temp = temp->next;
        i++;
    }
    // in case of inseting at last i.e. insert at tail
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
    // we can not ask size as linked list is dynamic
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

// delete node 0-based index wise
Node *deleteNode(Node *head, int index)
{
    // deleting first index
    if (index == 0)
    {
        Node *temp = head;
        temp->next->prev = nullptr;
        head = temp->next;
        temp->next = nullptr;
        delete temp;
        return head;
    }
    // deleting mid indexed nodes
    int len = length(head);
    // in case invalid index is enquired
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
// function to delete head node of DLL
Node *deleteHead(Node *head)
{
    // Write your code here.
    // edge case: when LL has one node only
    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    Node *temp = head;
    head = temp->next;
    head->prev = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}
// to delete the last node of the LL
Node *deleteLastNode(Node *head)
{
    // Write your code here
    Node *temp = head;
    // case for only one node in the list
    if (temp->next == NULL)
    {
        delete temp;
        return NULL;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    temp->prev = NULL;
    delete temp;
    return head;
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
    head = deleteNode(head, 5);
    print(head);

    return 0;
}