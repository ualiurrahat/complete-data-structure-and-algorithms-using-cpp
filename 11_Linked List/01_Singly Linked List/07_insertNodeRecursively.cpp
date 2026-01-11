/*
Problem Statement:
------------------
Insert a node at any given position (index-based) in a singly linked list
using a recursive approach.

This file is a continuation of the linked list series where:
- The iterative insertion logic has already been implemented earlier.
- Here, the same insertion logic is implemented using recursion to
  strengthen conceptual understanding and decision-making skills.
*/

#include <iostream>
#include "02_linkedListClass.cpp"

using namespace std;

/*
Function: takeInputBetter
-------------------------
An optimized approach to take user input for creating a linked list.

Key learning points (especially for brute-force learners):
- We do not ask for the size of the linked list because it is dynamic.
- Input continues until the sentinel value `-1` is entered.
- Maintaining both `head` and `tail` allows insertion at the end in O(1) time.
- This approach avoids repeated traversal of the list.

Returns:
- Pointer to the head of the constructed linked list.

Time Complexity:
- O(n), where n is the number of nodes in the linked list.

Space Complexity:
- O(n), for storing n nodes.
*/
Node *takeInputBetter()
{
    cout << "Enter your data (enter -1 to exit): ";

    int data;

    // Initializing head and tail pointers with nullptr
    // head -> points to the first node of the linked list
    // tail -> points to the last node of the linked list
    Node *head = nullptr;
    Node *tail = nullptr;

    cin >> data;

    // Continue taking input until sentinel value -1 is encountered
    while (data != -1)
    {
        // Creating a new node with user-provided data
        Node *newNode = new Node(data);

        // If this is the first node, head and tail both point to it
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            // Attach new node after the current tail
            tail->next = newNode;

            // Update tail to point to the newly added node
            tail = newNode; // or: tail = tail->next;
        }

        cout << "Enter your data (enter -1 to exit): ";
        cin >> data;
    }

    // Returning the head of the linked list
    return head;
}

/*
Function: printLinkedList
-------------------------
Prints the linked list in a readable format.

Important explanation:
- The head pointer received here is a copy of the pointer from main().
- Any movement of this pointer does NOT affect the original head in main().
- This makes the function safe and side-effect free.

Output format:
- data1->data2->data3->null

Time Complexity:
- O(n), where n is the size of the linked list.

Space Complexity:
- O(1), as no extra space proportional to input size is used.
*/
void printLinkedList(Node *head)
{
    // Traversing the linked list until the end is reached
    while (head != nullptr)
    {
        cout << head->data << "->";
        head = head->next;
    }

    cout << "null" << endl;
}

/*
Function: insertNode
--------------------
Inserts a node at a given index using an iterative approach.

Parameters:
- head : Pointer to the head of the linked list
- i    : Index at which the new node should be inserted (0-based)
- data : Data value of the new node

Conceptual explanation:
- If i == 0, insertion happens at the beginning and head is updated.
- Otherwise, we traverse the list to reach the (i-1)th node.
- The new node is linked between existing nodes without breaking the list.

Returns:
- Updated head pointer of the linked list.

Time Complexity:
- O(1) for insertion at index 0
- O(n) for insertion at any other index
*/
Node *insertNode(Node *head, int i, int data)
{
    // Creating a new node with the given data
    Node *newNode = new Node(data);

    // Case: inserting at the beginning of the linked list
    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    // Counter to track the current index
    int count = 0;

    // Temporary pointer to traverse the list
    Node *temp = head;

    // Traversing to reach the (i-1)th position
    // Conditions ensure:
    // - We do not access invalid memory
    // - The index is within valid range
    while (temp != nullptr && count < i - 1)
    {
        temp = temp->next;
        count++;
    }

    // If temp is valid, perform insertion
    if (temp != nullptr)
    {
        Node *nextNode = temp->next;
        temp->next = newNode;
        newNode->next = nextNode;

        // Alternative (commented for conceptual clarity):
        // newNode->next = temp->next;
        // temp->next = newNode;
    }

    // Returning head (unchanged for i > 0)
    return head;
}

/*
Function: insertNodeRecursively
-------------------------------
Inserts a node at a given index using recursion.

Parameters:
- head : Pointer to the current node of the linked list
- i    : Index at which the new node should be inserted
- data : Data value of the new node

Step-by-step recursive reasoning:
1. Edge Case:
   - If head is nullptr, insertion is not possible.
2. Base Case:
   - If i == 0, create a new node and attach it before the current head.
3. Recursive Case:
   - Move to the next node while decreasing index by 1.
   - Reconnect the returned smaller list back to the current node.

Returns:
- Updated head pointer after insertion.

Time Complexity:
- O(n), where n is the position at which insertion occurs.

Space Complexity:
- O(n), due to recursive call stack.
*/
Node *insertNodeRecursively(Node *head, int i, int data)
{
    // Edge case:
    // If the list is empty, no insertion can be performed
    if (head == nullptr)
    {
        return head;
    }

    // Base case:
    // When index becomes 0, insert the new node at this position
    if (i == 0)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }

    // Recursive call:
    // Insert in the remaining smaller linked list
    Node *smallHead = insertNodeRecursively(head->next, i - 1, data);

    // Small calculation:
    // Reconnecting the current node with the updated smaller list
    head->next = smallHead;

    return head;
}

int main()
{
    // Taking user input to create the initial linked list
    Node *head = takeInputBetter();

    // Printing the initial linked list
    printLinkedList(head);

    // Inserting three new nodes using recursive insertion
    for (int j = 0; j < 3; j++)
    {
        int index;
        int data;

        cout << "Insert the index for new Node: ";
        cin >> index;

        cout << "Insert data for new Node: ";
        cin >> data;

        // Calling recursive insertion function
        head = insertNodeRecursively(head, index, data);

        // Printing the linked list after insertion
        printLinkedList(head);
    }

    return 0;
}
