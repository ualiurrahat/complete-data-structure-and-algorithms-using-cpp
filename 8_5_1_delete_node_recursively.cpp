#include <bits/stdc++.h>
#include "8_0_LinkedListClass.cpp"

using namespace std;

// function to take user input linked list
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
    int count = 0;
    Node *temp = head;

    // if newNode is added in the 0th index
    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    // loop to get the right positon to place newNode
    while (temp != nullptr && count < i - 1)
    {
        temp = temp->next;
        count++;
    }

    // adding newNode in the list
    if (temp != nullptr)
    {
        Node *a = temp->next;
        temp->next = newNode;
        newNode->next = a;
    }
    return head;
}

// function to delete a node from the list
// at ith index, with data as value
// returns head node
Node *delete_node(Node *head, int i)
{
    if (head == nullptr)
    {
        return head;
    }
    if (i == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *smallHead = delete_node(head->next, i - 1);
    head->next = smallHead;
    return head;
}
int main()
{
    Node *head = take_input();
    print_linked_list(head);

    int i;
    for (int j = 0; j < 3; j++)
    {
        cout << "Enter index of node you wanna delete:";
        cin >> i;

        head = delete_node(head, i);
        print_linked_list(head);
    }

    return 0;
}