/*
================================================================================
📌 Problem Statement:
Create a Singly Linked List by taking user input dynamically.

This file demonstrates TWO approaches:
1️⃣ Brute-force approach (O(n²)) – for understanding the problem
2️⃣ Better approach using tail pointer (O(n)) – for optimized solution

Keeping both approaches together helps in:
- Comparing performance
- Understanding trade-offs
- Making better design decisions as a software engineer

================================================================================
*/

#include <iostream>
#include "02_linkedListClass.cpp"

using namespace std;

// -----------------------------------------------------------------------------
// Function: takeInputBrute
// -----------------------------------------------------------------------------
// Purpose:
// Takes input from the user and creates a linked list using a brute-force method.
//
// Key Characteristics:
// - Does NOT use a tail pointer.
// - For every new node, traversal starts again from the head.
// - This approach is simple but inefficient.
//
// Input Rule:
// - Input continues until user enters -1.
// - Size cannot be asked beforehand because Linked List is dynamic.
//
// Returns:
// - Pointer to the head of the created linked list.
//
// Time Complexity:
// - O(n²), because for each insertion we traverse the list.
//
// Space Complexity:
// - O(n), for storing n nodes.
// -----------------------------------------------------------------------------
Node *takeInputBrute()
{
    cout << "Enter your data (enter -1 to exit): ";

    int data;
    cin >> data;

    // Initializing head pointer as nullptr
    Node *head = nullptr;

    while (data != -1)
    {
        // Creating a new node dynamically
        Node *newNode = new Node(data);

        // If list is empty, new node becomes the head
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            // Traversing the list to reach the last node
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }

            // Attaching new node at the end
            temp->next = newNode;
        }

        cout << "Enter your data (enter -1 to exit): ";
        cin >> data;
    }

    return head;
}

// -----------------------------------------------------------------------------
// Function: takeInputBetter
// -----------------------------------------------------------------------------
// Purpose:
// Takes input from the user and creates a linked list using an optimized approach.
//
// Key Characteristics:
// - Uses both head and tail pointers.
// - Avoids repeated traversal.
// - Each insertion happens in constant time.
//
// Input Rule:
// - Input continues until user enters -1.
//
// Returns:
// - Pointer to the head of the created linked list.
//
// Time Complexity:
// - O(n), where n is the number of nodes.
//
// Space Complexity:
// - O(n), for storing n nodes.
// -----------------------------------------------------------------------------
Node *takeInputBetter()
{
    cout << "Enter your data (enter -1 to exit): ";

    int data;
    cin >> data;

    // Initializing both head and tail pointers as nullptr
    Node *head = nullptr;
    Node *tail = nullptr;

    while (data != -1)
    {
        // Creating a new node dynamically
        Node *newNode = new Node(data);

        // If list is empty, head and tail both point to the new node
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            // Attach new node directly after tail
            tail->next = newNode;

            // Move tail to the newly added node
            tail = newNode;
        }

        cout << "Enter your data (enter -1 to exit): ";
        cin >> data;
    }

    return head;
}

// -----------------------------------------------------------------------------
// Function: printLinkedList
// -----------------------------------------------------------------------------
// Purpose:
// Prints the linked list starting from the head node.
//
// Important Concept:
// - A COPY of the head pointer is passed.
// - Moving the pointer inside this function does NOT affect main().
//
// Time Complexity:
// - O(n)
//
// Space Complexity:
// - O(1)
// -----------------------------------------------------------------------------
void printLinkedList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    // -------------------------------------------------------------------------
    // Creating linked list using BRUTE-FORCE approach
    // -------------------------------------------------------------------------
    cout << "\n--- Creating Linked List (Brute Force Approach) ---\n";
    Node *headBrute = takeInputBrute();
    printLinkedList(headBrute);

    // -------------------------------------------------------------------------
    // Creating linked list using BETTER (Optimized) approach
    // -------------------------------------------------------------------------
    cout << "\n--- Creating Linked List (Better Approach) ---\n";
    Node *headBetter = takeInputBetter();
    printLinkedList(headBetter);

    return 0;
}
