/*
Problem: Design Linked List (LeetCode 707)

Description:
------------
Design and implement a singly linked list using a class-based approach.
The linked list supports the following operations:

1. get(index)           -> Get the value of the index-th node.
2. addAtHead(val)       -> Insert a node at the beginning.
3. addAtTail(val)       -> Insert a node at the end.
4. addAtIndex(index,val)-> Insert a node before the index-th node.
5. deleteAtIndex(index) -> Delete the index-th node.

Important Constraints:
----------------------
- All indices are 0-based.
- If an index is invalid, the operation should fail gracefully.
- The linked list is implemented manually (no STL containers).

Learning Objective:
-------------------
- Apply OOP principles to data structures.
- Manage dynamic memory safely.
- Handle edge cases systematically.
- Maintain class invariants (head, tail, length).
*/

class MyLinkedList
{
public:
    // ---------------------- Node Data Members ----------------------
    int data;           // Stores the value of the current node
    MyLinkedList *next; // Pointer to the next node in the list

    // ---------------------- Linked List Metadata -------------------
    MyLinkedList *head; // Pointer to the first node of the linked list
    MyLinkedList *tail; // Pointer to the last node of the linked list
    int length;         // Tracks the current size of the linked list

    // ---------------------- Constructor ----------------------------
    MyLinkedList()
    {
        // Initializing an empty linked list
        this->head = nullptr;
        this->tail = nullptr;

        // Initializing node-related members (used only when this object acts as a node)
        this->data = 0;
        this->next = nullptr;

        // Initial length of the linked list is zero
        this->length = 0;
    }

    // ---------------------- get(index) -----------------------------
    int get(int index)
    {
        // Edge case: if index is invalid, return -1
        if (index >= this->length)
        {
            return -1;
        }

        int count = 0;
        MyLinkedList *temp = head;

        // Traverse the list until the desired index is reached
        while (temp != nullptr && count < index)
        {
            temp = temp->next;
            count++;
        }

        // temp now points to the index-th node
        return temp->data;
    }

    // ---------------------- addAtHead(val) -------------------------
    void addAtHead(int val)
    {
        // Case 1: Linked list is empty
        // The newly created node becomes both head and tail
        if (head == nullptr)
        {
            MyLinkedList *newNode = new MyLinkedList();
            newNode->data = val;

            this->head = newNode;
            this->tail = newNode;
            this->length++;

            return;
        }

        // Case 2: Linked list already exists
        // Insert the new node before the current head
        MyLinkedList *newNode = new MyLinkedList();
        newNode->data = val;
        newNode->next = this->head;

        this->head = newNode;
        this->length++;

        return;
    }

    // ---------------------- addAtTail(val) -------------------------
    void addAtTail(int val)
    {
        // Case 1: Linked list is empty
        if (head == nullptr)
        {
            MyLinkedList *newNode = new MyLinkedList();
            newNode->data = val;

            this->head = newNode;
            this->tail = newNode;
            this->length++;

            return;
        }

        // Case 2: Linked list is not empty
        // Attach the new node after the current tail
        MyLinkedList *newNode = new MyLinkedList();
        newNode->data = val;

        this->tail->next = newNode;
        this->tail = newNode;
        this->length++;

        return;
    }

    // ---------------------- addAtIndex(index, val) -----------------
    void addAtIndex(int index, int val)
    {
        // Edge case: index greater than length
        // Insertion is not allowed
        if (index > this->length)
        {
            return;
        }

        // Case 1: index equals length
        // Insert node at the end of the list
        if (index == this->length)
        {
            addAtTail(val);
            return;
        }

        // Case 2: index is zero
        // Insert node at the head
        if (index == 0)
        {
            addAtHead(val);
            return;
        }

        // Case 3: index lies somewhere in the middle
        MyLinkedList *temp = head;
        int count = 0;

        // Create the new node with the given value
        MyLinkedList *newNode = new MyLinkedList();
        newNode->data = val;

        // Traverse to the (index - 1)-th node
        while (temp != nullptr && count < index - 1)
        {
            temp = temp->next;
            count++;
        }

        // Perform insertion if the position is valid
        if (temp != nullptr)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            this->length++;
            return;
        }
    }

    // ---------------------- deleteAtIndex(index) -------------------
    void deleteAtIndex(int index)
    {
        // Edge case: invalid index
        if (index >= this->length)
        {
            return;
        }

        // Case 1: deleting the head node
        if (index == 0)
        {
            MyLinkedList *nodeToDelete = head;
            head = head->next;

            delete nodeToDelete;
            this->length--;

            return;
        }

        // Traverse the list to reach the (index - 1)-th node
        MyLinkedList *temp = head;
        int count = 0;

        while (temp != nullptr && count < index - 1)
        {
            temp = temp->next;
            count++;
        }

        // Case 2: deleting a node other than the head
        if (temp != nullptr)
        {
            MyLinkedList *nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;

            // If the last node is deleted, update the tail pointer
            if (index == this->length - 1)
            {
                tail = temp;
            }

            delete nodeToDelete;
            this->length--;

            return;
        }
    }
};
