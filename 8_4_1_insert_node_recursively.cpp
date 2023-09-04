#include <bits/stdc++.h>
#include "8_0_LinkedListClass.cpp"

using namespace std;

// function to take user input linked list
// returns head of the list
// so return type would be Node*
// the function takes input untill -1 is given as input
// means function terminates with -1 input

Node *take_input()
{
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
            // link newNode with previos node
            tail->next = newNode;
            // update tail now
            tail = newNode;
            // or, tail = tail->next;
        }
        // further input for nodes
        cin >> data;
    }
    // returning head of the linked list
    return head;
}

void print_linked_list(Node *head)
{
    // always use a temp pointer as head
    // otherwise maintaining head would be difficult

    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// function to insert a node at the ith index with data as value

Node *insert_node(Node *head, int i, int data)
{
    // 1.base case
    if (head == nullptr)
    {
        return head;
    }
    //  condition case, when index = i = 0, 
    // will create new node, attach it with head
    // update the head and return
    if (i == 0)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }

    // 2. recursive call
    Node *smallHead = insert_node(head->next, i - 1, data);
    // 3. small calculation
    head->next = smallHead;
    return head;
}

int main()
{
    Node *head = take_input();
    print_linked_list(head);

    for (int j = 0; j < 3; j++)
    {
        // inserting a new node in the list
        int i, data;
        cout << "Insert the index for new Node: ";
        cin >> i;
        cout << "Insert data for new Node: ";
        cin >> data;

        // calling insert_node() function to add the new Node in the list
        head = insert_node(head, i, data);
        print_linked_list(head);
    }

    return 0;
}