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
    // we cant ask size as linked list is dynamic
    // so will take input as linked list node
    // untill -1 is given.

    // complexity: T:O(n^2)
    cout << "Enter your data: ";
    int data;
    // initialising head with null
    Node *head = nullptr;

    cin >> data;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        // check if head is null, then assign newNode as head
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "enter data: ";
        cin >> data;
    }
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