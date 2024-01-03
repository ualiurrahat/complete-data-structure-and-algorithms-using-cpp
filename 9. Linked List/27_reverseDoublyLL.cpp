#include <bits/stdc++.h>
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

// delete node index wise
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
// function to convert an array into a doubly linked list
Node *convertArrayIntoDLL(int arr[], int n)
{
    // Write your code here
    Node *head = new Node(arr[0]);
    Node *tail = new Node(arr[n - 1]);

    Node *temp = head;
    for (int i = 1; i < n - 1; i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        newNode->prev = temp;
        temp = temp->next;
    }
    // to add last element of array into DLL
    if (n > 1)
    {
        temp->next = tail;
        tail->prev = temp;
    }

    return head;
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
// function to reverse a doubly LL
// approach: take a stack. insert all the LL data into it.
// starting from head. and then fill all the stack data from top to bottom
// in the LL starting from head.
Node *reverseDoublyLLBruteForce(Node *head)
{
    // edge case: if head is null
    if (head == nullptr)
    {
        return head;
    }
    // take a stack to store data of LL nodes
    stack<int> st;
    // to traverse the LL
    Node *temp = head;
    // traverse and store LL data into stack
    while (temp != nullptr)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    // now fill up the temp data into LL starting from head.
    temp = head;
    while (temp != nullptr)
    {
        temp->data = st.top();
        // update temp to go to next node
        temp = temp->next;
        // remove top element from stack
        st.pop();
    }
    // reversing is done. return the head
    return head;
}
// T:O(n)+(n) = O(2n)
// S:O(n)

// optimal approach to reverse DLL.
// method: a DLL node has 3 elements: data,nextP,prevP
// we reversed data in previous method.
// here we will reversed the prev,next linked.
// reverse means, next pointer becomes previous and vice versa.
Node *reverseDLLOptimal(Node *head)
{
    // for single node list
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    // to track the previous node of each node in LL.
    Node *last = nullptr;
    // to traverse the list.
    Node *current = head;
    while (current != nullptr)
    {
        last = current->prev;
        current->prev = current->next;
        current->next = last;
        current = current->prev;
    }
    // LL is reversed.update head of the reversed LL
    head = last->prev;
    return head;
}
// T:O(n)
// S:O(1)
int main()
{
    // take user defined doubly LL
    Node *head = take_input();
    cout << "User given Doubly LL is: ";
    print(head);
    // head = reverseDoublyLLBruteForce(head);
    // cout << "Reversed Doubly LL is: ";
    head = reverseDLLOptimal(head);
    cout << "Reversed Doubly LL is: ";
    print(head);
    return 0;
}