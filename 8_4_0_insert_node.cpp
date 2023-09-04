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
    Node *newNode = new Node(data);

    // if newNode is added in the 0th index
    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    // var count for finding right index
    // and temp pointer to find the previous node.
    int count = 0;
    Node *temp = head;

    // loop to get the right positon to place newNode
    while (temp != nullptr && count < i - 1)
    {
        temp = temp->next;
        count++;
    }

    // adding newNode in the list
    // checking if the position of the newNode is valid or not
    if (temp != nullptr)
    {
        Node *a = temp->next;
        temp->next = newNode;
        newNode->next = a;
    }
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