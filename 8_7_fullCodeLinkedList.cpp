#include <bits/stdc++.h>

using namespace std;

// class for creating nodes for linked list
class Node
{
public:
    int data;
    Node *next;

    Node(int n)
    {
        data = n;
        next = nullptr;
    }
};

// to print the linked list
void print(Node *head)
{
    cout << "linked list: ";
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// take user given linked list as input
Node *takeInput()
{
    cout << "enter your linked list: ";
    int data;
    cin >> data;
    // pointer for head
    Node *head = nullptr;
    // pointer for tail
    // used to link new nodes with its previous nodes
    Node *tail = nullptr;

    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            tail = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

// functon to insert node in linked list
// i = index in the list
// data = value of the node

Node *insertNode(Node *head, int i, int data)
{
    // if node is inserted at 0th index
    // then the newNode becomes the head
    Node *newNode = new Node(data);
    if (i == 0)
    {
        // linking newNode with previous head
        newNode->next = head;
        // newNode is head now. updating head node
        head = newNode;
        return head;
    }

    // if node is inserted any other postion except 0th index
    // we need to check if the position is valid
    // means index i does not exceed the length of linked list

    // var to travese through linked list
    int count = 0;
    Node *temp = head;

    // traversing linkedList to find the appropriate position
    // for newNode
    while (temp != nullptr && count < i - 1)
    {
        temp = temp->next;
        count++;
    }
    // checking if the position is valid
    if (temp != nullptr)
    {
        Node *a = temp->next;
        temp->next = newNode;
        newNode->next = a;
    }

    return head;
}

// delete any node from the linked list
// deleting ith index here

Node *deleteNode(Node *head, int i)
{
    Node *a;

    // deleting 0th index
    if (i == 0)
    {
        a = head;          // a needs to be deleted
        head = head->next; // updating head
        delete a;          // deleting old head
        return head;
    }

    // deleting any other indexed node
    int count = 0;
    Node *temp = head;

    // loop to traverse linked list
    // to find the ith nodes that needs to be deleted.
    while (temp != nullptr && count < i - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp != nullptr)
    {
        a = temp->next;    // a needs to be deleted
        Node *b = a->next; // b is the next node of the temp node
        temp->next = b;    // updating temp's next node as b
        delete a;          // deleting ith index node
    }
    return head;
}

// find lenght of linked list
// length = total num of nodes
int length(Node *head)
{
    int count = 1;
    while (head->next != nullptr)
    {
        head = head->next;
        count++;
    }
    return count;
}

int main()
{

    // static linked list
    Node n1(1);
    Node *head = &n1;

    Node n2(2);
    n1.next = &n2;

    cout << n1.data << " " << n2.data << endl;
    cout << head->data << endl;

    // dynamic linked list
    Node *n3 = new Node(10);
    Node *head2 = n3;
    Node *n4 = new Node(20);
    n3->next = n4;

    cout << n3->data << " " << n4->data << endl;
    cout << head2->data << endl;

    // checking print() and takeInput() function
    head = takeInput();
    print(head);

    // checking insertNode function
    head = insertNode(head, 0, 25);
    print(head);
    head = insertNode(head, 4, 100);
    print(head);
    head = insertNode(head, 10, 250);
    print(head);

    // checking deleteNode() function
    head = deleteNode(head, 0);
    print(head);
    head = deleteNode(head, 3);
    print(head);
    head = deleteNode(head, 8);
    print(head);

    int len = length(head);
    cout << "length of linked list: " << len << endl;

    return 0;
}