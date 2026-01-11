/*
================================================================================
📌 Problem Statement:
Demonstrate how to create a Singly Linked List using:
1️⃣ Static (stack) memory allocation
2️⃣ Dynamic (heap) memory allocation

This program helps beginners clearly understand:
- How nodes are connected in memory
- The difference between '.' and '->'
- Why address-of (&) is used in static allocation
- How pointers behave differently in dynamic allocation

================================================================================
*/

#include <iostream>
#include "02_linkedListClass.cpp"

using namespace std;
int main()
{
    // -------------------------------------------------------------------------
    // 1️⃣ Creating a Linked List using STATIC memory allocation
    // -------------------------------------------------------------------------
    // Nodes are created on the stack.
    // Their memory is managed automatically.
    // We must explicitly take their addresses when linking nodes.
    // -------------------------------------------------------------------------

    Node n1(1);             // First node created statically
    Node *headStatic = &n1; // Head stores the ADDRESS of n1

    Node n2(2);    // Second node created statically
    n1.next = &n2; // Linking n1 to n2 using address-of operator (&)

    // Printing values to verify static linking
    cout << "Static LL Data: ";
    cout << n1.data << " " << n2.data << endl;

    cout << "Static LL via Head: ";
    cout << headStatic->data << " " << headStatic->next->data << endl;

    // Expected Output:
    // Static LL Data: 1 2
    // Static LL via Head: 1 2

    // -------------------------------------------------------------------------
    // 2️⃣ Creating a Linked List using DYNAMIC memory allocation
    // -------------------------------------------------------------------------
    // Nodes are created on the heap using 'new'.
    // 'new' already returns an address, so '&' is NOT required.
    // Manual deletion is necessary to avoid memory leaks.
    // -------------------------------------------------------------------------

    Node *n3 = new Node(10); // Node created dynamically (heap)
    Node *headDynamic = n3;  // Head directly stores pointer returned by new

    Node *n4 = new Node(20); // Second dynamic node
    n3->next = n4;           // Linking using pointer access (->)

    // Printing values to verify dynamic linking
    cout << "Dynamic LL Data: ";
    cout << n3->data << " " << n4->data << endl;

    cout << "Dynamic LL via Head: ";
    cout << headDynamic->data << " " << headDynamic->next->data << endl;

    // Expected Output:
    // Dynamic LL Data: 10 20
    // Dynamic LL via Head: 10 20

    // -------------------------------------------------------------------------
    // 3️⃣ Cleaning up dynamically allocated memory
    // -------------------------------------------------------------------------
    // IMPORTANT:
    // - Stack-allocated nodes (n1, n2) are destroyed automatically.
    // - Heap-allocated nodes (n3, n4) MUST be deleted manually.
    // -------------------------------------------------------------------------

    delete n4;
    delete n3;

    return 0;
}
