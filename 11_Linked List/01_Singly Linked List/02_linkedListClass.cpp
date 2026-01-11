/*
================================================================================
📌 Topic: Node Class for Singly Linked List
📁 Folder: 11_Linked List / 01_Singly Linked List
📄 File  : 02_linkedListClass.cpp
📘 Type  : Core Building Block (Node Definition)
================================================================================

This file defines the fundamental building block of a Singly Linked List: the
Node class.

A Linked List is made up of multiple nodes connected together using pointers.
Each node stores:
1️⃣ Data (actual value)
2️⃣ A pointer to the next node in the list

⚠ IMPORTANT DESIGN NOTE:
- A Node should NOT manage (delete) the rest of the list.
- Memory management of the entire list must be handled by a LinkedList class.

This design avoids:
- Accidental recursive deletion
- Double-free errors
- Undefined behavior
- Stack overflow for large lists

================================================================================
*/

class Node
{
public:
    // -------------------------------------------------------------------------
    // Data Members
    // -------------------------------------------------------------------------

    int data;   // Stores the actual value of the node
    Node *next; // Pointer to the next node in the linked list

    // -------------------------------------------------------------------------
    // Constructor
    // -------------------------------------------------------------------------

    /*
     * Constructor: Initializes a node with given data.
     *
     * @param data The value to be stored inside the node.
     *
     * Behavior:
     * - Assigns the provided value to the data field.
     * - Initializes the next pointer to nullptr, indicating that the node
     *   is not yet connected to any other node.
     */
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

    // -------------------------------------------------------------------------
    // Destructor
    // -------------------------------------------------------------------------

    /*
     * Destructor: Cleans up the node itself.
     *
     * ⚠ VERY IMPORTANT DESIGN DECISION:
     * - This destructor DOES NOT delete the `next` node.
     *
     * WHY?
     * - A single node does NOT own the rest of the linked list.
     * - Deleting `next` here would cause recursive deletion, leading to:
     *     ❌ Double-free bugs
     *     ❌ Dangling pointers
     *     ❌ Undefined behavior
     *
     * CORRECT RESPONSIBILITY:
     * - The LinkedList class (or controlling logic) must explicitly traverse
     *   the list and delete nodes one by one.
     *
     * This keeps:
     * - Ownership clear
     * - Behavior predictable
     * - Code safe and professional
     */
    ~Node()
    {
        // No deletion of `next` here by design.
        // Destructor only destroys the current node.
        next = nullptr;
    }
};
