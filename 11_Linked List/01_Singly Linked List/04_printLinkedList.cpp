/*
================================================================================
📌 Problem Statement:
Print all elements of a Singly Linked List starting from the head node.

This program demonstrates:
1️⃣ How to traverse a linked list safely
2️⃣ Why passing the head pointer by value does NOT modify the original head
3️⃣ How pointer movement works during traversal
4️⃣ Why using a temporary pointer is a good practice conceptually

================================================================================
*/

#include <iostream>
#include "02_linkedListClass.cpp"

using namespace std;

// -----------------------------------------------------------------------------
// Function: printLinkedList
// -----------------------------------------------------------------------------
// Purpose:
// Prints the elements of a linked list in sequence until nullptr is reached.
//
// Parameter:
// head -> Pointer to the first node of the linked list.
//
// IMPORTANT NOTES (Conceptual Understanding):
// - We receive a COPY of the head pointer, not the original head.
// - Even though we move the head pointer inside this function,
//   the head pointer in main() remains unchanged.
// - This is because pointers are passed by value unless explicitly
//   passed by reference or double pointer.
// -----------------------------------------------------------------------------
void printLinkedList(Node *head)
{
    // Using a temporary pointer (or moving head directly) is safe here
    // because:
    // - The head pointer received by this function is only a COPY.
    // - Any modification to it does NOT affect the original head in main().
    //
    // Example alternative (conceptual):
    // Node* temp = head;
    //
    // Both approaches are valid as long as ownership rules are respected.

    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next; // Move to the next node
    }

    cout << "NULL" << endl;

    // Time Complexity:
    // T: O(n), where n is the number of nodes in the linked list.
}

int main()
{
    // -------------------------------------------------------------------------
    // Creating nodes using STATIC (stack) memory allocation
    // -------------------------------------------------------------------------

    Node n1(18);
    Node n2(1);
    Node n3(8);
    Node n4(25);
    Node n5(20);

    // Linking nodes to form the linked list
    Node *head = &n1; // Head points to the first node
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = nullptr; // Explicitly marking end of the list

    // Printing the address stored in head
    cout << "Head address: " << head << endl;

    // -------------------------------------------------------------------------
    // Printing the linked list
    // -------------------------------------------------------------------------
    // We pass a COPY of the head pointer to the function.
    // Inside printLinkedList(), the pointer moves forward,
    // but the original head in main() remains unchanged.
    // -------------------------------------------------------------------------

    printLinkedList(head);
    printLinkedList(head); // List can be printed again safely

    // Verifying that head is unchanged
    cout << "Head data after printing: " << head->data << endl;
    cout << "Head address after printing: " << head << endl;

    return 0;
}
