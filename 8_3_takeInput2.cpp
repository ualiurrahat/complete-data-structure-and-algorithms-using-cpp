#include <bits/stdc++.h>
#include "8_0_LinkedListClass.cpp"

using namespace std;

// function to take user input linked list
// returns head of the list
// so return type would be Node*
// the function takes input untill -1 is given as input
// means function terminates with -1 input

// better function than the previous one
// complexity: T:O(n)
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

int main()
{
    Node *head = take_input();
    print_linked_list(head);

    return 0;
}